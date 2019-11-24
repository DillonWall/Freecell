/*************************************************************
* Author: Dillon Wall
* Filename: Freecell.cpp
* Date Created: 2/12/2019
* Modifications:
**************************************************************/


#include "Freecell.h"



Freecell::Freecell() : m_pArea(nullptr), m_fArea(nullptr), m_hArea(nullptr)
{
	m_pArea = new PlayArea();
	m_fArea = new FreeArea();
	m_hArea = new HomeArea();
}


Freecell::~Freecell()
{
	delete m_pArea;
	delete m_fArea;
	delete m_hArea;

	m_pArea = nullptr;
	m_fArea = nullptr;
	m_hArea = nullptr;
}

Freecell::Freecell(const Freecell & copy) : m_pArea(nullptr), m_fArea(nullptr), m_hArea(nullptr)
{
	m_pArea = new PlayArea(*(copy.m_pArea));
	m_fArea = new FreeArea(*(copy.m_fArea));
	m_hArea = new HomeArea(*(copy.m_hArea));
}

Freecell & Freecell::operator=(const Freecell & rhs)
{
	if (this != &rhs)
	{
		delete m_pArea;
		delete m_fArea;
		delete m_hArea;

		m_pArea = new PlayArea(*(rhs.m_pArea));
		m_fArea = new FreeArea(*(rhs.m_fArea));
		m_hArea = new HomeArea(*(rhs.m_hArea));
	}

	return *this;
}

bool Freecell::Won() const
{
	return m_hArea->Won();
}

bool Freecell::Update(char * input) 
{
	char * p;
	p = strtok(input, " "); // get a pointer to point to the input delimiting by spaces
	if (!p) return true; // if bad input exit the function but keep game going

	bool moving = strcmp(p, "m") == 0 || strcmp(p, "move") == 0;
	bool movingStack = strcmp(p, "ms") == 0 || strcmp(p, "movestack") == 0;

	if (strcmp(p,"exit") == 0)
	{
		return false; //false stops the game
	}
	else if (moving || movingStack)
	{
		int fromCell = 0;
		int toCell = 0;
		int amount = 1;

		Area * fromArea = m_pArea;
		if (moving) 
			fromArea = ParseAreaInput(p);

		p = strtok(NULL, " ");
		fromCell = atoi(p) - 1;

		if (movingStack)
		{
			p = strtok(NULL, " ");
			amount = atoi(p);
		}

		Area * toArea = m_pArea;
		if (moving) 
			toArea = ParseAreaInput(p);

		p = strtok(NULL, " ");
		toCell = atoi(p) - 1;

		if (movingStack && (!dynamic_cast<PlayArea*>(fromArea) || !dynamic_cast<PlayArea*>(toArea)))
			return true;
		MoveStack(fromArea, fromCell, toArea, toCell, amount, GetNumFreeCells());
	}

	return true;

}

void Freecell::Print()
{
	//clear window
	for (int i = 0; i < 24; ++i)
	{
		cout << endl;
	}

	SetConsoleTextAttribute(Card::hConsole, 32); //green bg
	cout << "      FREE CELLS                     HOME           " << endl;
	cout << " 01    02    03    04       01 ";
	cout << "S  ";
	cout << "02 ";
	cout << "C  ";
	cout << "03 ";
	SetConsoleTextAttribute(Card::hConsole, 36);
	cout << "H  ";
	SetConsoleTextAttribute(Card::hConsole, 32);
	cout << "04 ";
	SetConsoleTextAttribute(Card::hConsole, 36);
	cout << "D  " << endl;
	SetConsoleTextAttribute(Card::hConsole, 32);
	m_fArea->Print();
	SetConsoleTextAttribute(Card::hConsole, 32); //green bg
	cout << "||  ";
	m_hArea->Print();
	SetConsoleTextAttribute(Card::hConsole, 32); //green bg
	cout << endl << "                                                    " << endl;
	cout << "                     PLAY                           " << endl;
	cout << " 01    02    03    04    05    06    07    08       " << endl;
	m_pArea->Print();
	SetConsoleTextAttribute(Card::hConsole, 32); //green bg
	cout << "                                                    " << endl;
	SetConsoleTextAttribute(Card::hConsole, 15); //default
}

bool Freecell::Move(Area * fromArea, int fromPos, Area * toArea, int toPos)
{
	Card fromCard = fromArea->GetCard(fromPos);
	Card toCard = toArea->GetCard(toPos);

	//check bounds
	if (!CheckBounds(fromArea, fromPos))
		return false;
	if (!CheckBounds(toArea, toPos))
		return false;		

	if (!(toCard.GetSuit() != Card::NONE && dynamic_cast<FreeArea*>(toArea))) //Checks if trying to move to occupied free cell
	{
		if (dynamic_cast<HomeArea*>(toArea) ? 
			CheckSuitPos(fromCard, toPos) && CheckInSequence(toCard, fromCard) : //can move to home area
			(CheckAlternatingColors(fromCard, toCard) && CheckInSequence(fromCard, toCard))) //can move to play area/freecell
		{
			if (toArea->AddCard(fromCard, toPos))
			{
				fromArea->RemoveCard(fromPos);
				return true;
			}
			else
				throw Exception("Unable to add single card (Freecell) (Move)");
		}
	}

	return false;
}

bool Freecell::MoveCard(Card card, Area* toArea, int toPos, bool testingCanMove)
{
	Card toCard = toArea->GetCard(toPos);

	if (!(toCard.GetSuit() != Card::NONE && dynamic_cast<FreeArea*>(toArea))) //Checks if trying to move to occupied free cell
	{

		if (dynamic_cast<HomeArea*>(toArea) ?
			CheckSuitPos(card, toPos) && CheckInSequence(toCard, card) : //can move to area
			(CheckAlternatingColors(card, toCard) && CheckInSequence(card, toCard))) //can move to play area/freecell
		{
			{
				if (testingCanMove || m_pArea->AddCard(card, toPos))
				{
					return true;
				}
				else
					throw Exception("Unable to add single card (Freecell) (MovePlay)");
			}
		}
	}

	return false;
}

bool Freecell::MoveStack(Area * fromArea, int fromPos, Area * toArea, int toPos, int amount, int vacantFreeCells)
{
	//continue while amount > 0
	//check selection is ordered (return false if not)
	//if play area open, move it there
	//else if free cell open, move it there
	//else return false
	//do next card, if false, move this back to original
	//	if true, move this card to the desired stack

	//continue while amount > 0
	if (amount > 1 && dynamic_cast<PlayArea*>(fromArea) && dynamic_cast<PlayArea*>(toArea))
	{
		Card current = m_pArea->RemoveCard(fromPos);
		Card next = m_pArea->GetCard(fromPos);

		//check selection is ordered (return false if not)
		if (current.GetSuit() == Card::NONE || next.GetSuit() == Card::NONE)
			return false;

		//if play area open, move it there
		bool wasOpen = false;
		for (int i = 0; i < PlayArea::NUM_STACKS && !wasOpen; ++i)
		{
			if(i != fromPos && i != toPos && MoveCard(current, m_pArea, i, true))
				wasOpen = true;
		}

		//else if free cell open, move it there
		if (!wasOpen)
		{
			if (vacantFreeCells > 0)
			{
				wasOpen = true;
				--vacantFreeCells;
			}
		}

		//else replace back and return false
		if (!wasOpen)
		{
			MoveCard(current, toArea, fromPos, false);
			return false;
		}

		//do next card, if true, move this card to the desired stack
		if (MoveStack(fromArea, fromPos, toArea, toPos, amount - 1, vacantFreeCells))
			return MoveCard(current, toArea, toPos, false);
		else //if false, move this back to original and keep returning false
		{
			MoveCard(current, toArea, fromPos, false);
			return false;
		}

	}
	else if (amount == 1)
	{
		return Move(fromArea, fromPos, toArea, toPos);
	}
	return true;
}

bool Freecell::CheckBounds(Area * area, int pos)
{
	if (dynamic_cast<PlayArea*>(area) &&
		pos < 0 && pos >= PlayArea::NUM_STACKS)
		return false;
	else if (dynamic_cast<FreeArea*>(area) &&
		pos < 0 && pos >= FreeArea::NUM_FREE_CELLS)
		return false;
	else if (dynamic_cast<HomeArea*>(area) &&
		pos < 0 && pos >= HomeArea::NUM_HOME_AREAS)
		return false;
	return true;
}

Area * Freecell::ParseAreaInput(char * p)
{
	Area * retVal = m_pArea;

	p = strtok(NULL, " ");
	if (strcmp(p, "p") == 0 || strcmp(p, "play") == 0)
		retVal = m_pArea;
	else if (strcmp(p, "f") == 0 || strcmp(p, "free") == 0)
		retVal = m_fArea;
	else if (strcmp(p, "h") == 0 || strcmp(p, "home") == 0)
		retVal = m_hArea;

	return retVal;
}

bool Freecell::CheckAlternatingColors(Card & card1, Card & card2)
{
	char suit1 = card1.GetSuit();
	char suit2 = card2.GetSuit();

	if (suit2 == Card::NONE)
		return true;

	if (suit1 == Card::SPADES || suit1 == Card::CLUBS)
	{
		if (suit2 == Card::HEARTS || suit2 == Card::DIAMONDS)
			return true;
		return false;
	}
	if (suit2 == Card::SPADES || suit2 == Card::CLUBS)
		return true;
	return false;
}

bool Freecell::CheckInSequence(Card & lower, Card & higher)
{
	if (higher.GetSuit() == Card::NONE)
		return true;

	return (lower.GetValue() == higher.GetValue() - 1);
}

bool Freecell::CheckSuitPos(Card & card, int pos)
{
	char suit = card.GetSuit();
	if (suit == Card::SPADES && pos == 0 ||
		suit == Card::CLUBS && pos == 1 ||
		suit == Card::HEARTS && pos == 2 ||
		suit == Card::DIAMONDS && pos == 3)
		return true;
	return false;
}

int Freecell::GetNumFreeCells()
{
	int retVal = 0;
	for (int i = 0; i < FreeArea::NUM_FREE_CELLS; ++i)
	{
		if (m_fArea->GetCard(i).GetSuit() == Card::NONE)
			++retVal;
	}
	return retVal;
}
