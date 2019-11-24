/*************************************************************
* Author: Dillon Wall
* Filename: Card.cpp
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#include "Card.h"


HANDLE Card::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Card::Card() : m_suit(Card::NONE), m_value(0)
{
}

Card::Card(char suit, int value) : m_suit(suit), m_value(value)
{
}

Card::~Card()
{
}

Card::Card(const Card & copy) : m_suit(copy.m_suit), m_value(copy.m_value)
{
}

Card & Card::operator=(const Card & rhs)
{
	if (this != &rhs)
	{
		m_suit = rhs.m_suit;
		m_value = rhs.m_value;
	}

	return *this;
}

bool Card::operator!=(const Card & rhs) const
{
	return (m_suit != rhs.m_suit || m_value != rhs.m_value);
}

bool Card::operator==(const Card & rhs) const
{
	return (m_suit == rhs.m_suit && m_value == rhs.m_value);
}

char Card::GetSuit() const
{
	return m_suit;
}

int Card::GetValue() const
{
	return m_value;
}

void Card::Print() const
{
	SetConsoleTextAttribute(hConsole, 241); //Blue. white bg
	cout << "[";

	if (m_suit == SPADES || m_suit == CLUBS)
		SetConsoleTextAttribute(hConsole, 240); //Black. white bg
	else
		SetConsoleTextAttribute(hConsole, 244); //Red. white bg

	if (m_suit == 'N')
		cout << "  ";
	else
	{
		if (m_value == 1)
		{
			SetConsoleTextAttribute(hConsole, 246); //Gold. white bg
			cout << 'A';
			if (m_suit == SPADES || m_suit == CLUBS)
				SetConsoleTextAttribute(hConsole, 240); //Black. white bg
			else
				SetConsoleTextAttribute(hConsole, 244); //Red. white bg
		}
		else if (m_value == 11)
			cout << 'J';
		else if (m_value == 12)
			cout << 'Q';
		else if (m_value == 13)
			cout << 'K';
		else
			cout << m_value;

		cout << m_suit;
	}

	SetConsoleTextAttribute(hConsole, 241); //Blue. white bg
	cout << "]";
	SetConsoleTextAttribute(hConsole, 32); //green bg
	cout << " " << (m_value != 10 ? " " : "");
}
