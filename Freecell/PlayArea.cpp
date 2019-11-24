/*************************************************************
* Author: Dillon Wall
* Filename: PlayArea.cpp
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#include "PlayArea.h"



PlayArea::PlayArea() : m_stacks(nullptr)
{
	m_stacks = new StackList<Card>[NUM_STACKS];

	Deck d;
	d.Shuffle();

	int stack = 0;
	while (!d.IsEmpty())
	{
		m_stacks[stack].Push(d.Draw());

		++stack;
		if (stack >= NUM_STACKS)
			stack = 0;
	}
}


PlayArea::~PlayArea()
{
	delete[] m_stacks;
}

PlayArea::PlayArea(const PlayArea & copy) : m_stacks(nullptr)
{
	m_stacks = new StackList<Card>[NUM_STACKS];
	for (int i = 0; i < NUM_STACKS; ++i)
	{
		m_stacks[i] = StackList<Card>(copy.m_stacks[i]);
	}
}

PlayArea & PlayArea::operator=(const PlayArea & rhs)
{
	if (this != &rhs)
	{
		delete[] m_stacks;

		m_stacks = new StackList<Card>[NUM_STACKS];
		for (int i = 0; i < NUM_STACKS; ++i)
		{
			m_stacks[i] = StackList<Card>(rhs.m_stacks[i]);
		}
	}

	return *this;
}

bool PlayArea::IsEmpty(int pos) const
{
	if (pos < 0 || pos >= NUM_STACKS)
		throw Exception("Stack number out of bounds (PlayArea) (IsEmpty)");

	return m_stacks[pos].isEmpty();
}

bool PlayArea::AddCard(Card card, int pos)
{
	if (pos < 0 || pos >= NUM_STACKS)
		throw Exception("Stack number out of bounds (PlayArea) (AddCard)");
	
	m_stacks[pos].Push(card);

	return true;
}

Card PlayArea::RemoveCard(int pos)
{
	if (pos < 0 || pos >= NUM_STACKS)
		throw Exception("Stack number out of bounds (PlayArea) (RemoveCard)");
	
	if (m_stacks[pos].isEmpty())
		return Card();
	return m_stacks[pos].Pop();
}

Card PlayArea::GetCard(int pos)
{
	if (pos < 0 || pos >= NUM_STACKS)
		throw Exception("Stack number out of bounds (PlayArea) (GetCard)");
	
	if (m_stacks[pos].isEmpty())
		return Card();

	return m_stacks[pos].Peek();
}

void PlayArea::Print() const
{
	StackList<Card>* stackCopy = new StackList<Card>[NUM_STACKS];
	StackList<Card>* stackCopyReverse = new StackList<Card>[NUM_STACKS];

	for (int i = 0; i < NUM_STACKS; ++i)
	{
		stackCopy[i] = m_stacks[i];
		stackCopyReverse[i] = StackList<Card>();

		while (!stackCopy[i].isEmpty())
			stackCopyReverse[i].Push(stackCopy[i].Pop());
	}

	bool done = false;
	while (!done)
	{
		done = true;
		for (int stack = 0; stack < NUM_STACKS; ++stack)
		{
			if (!stackCopyReverse[stack].isEmpty())
			{
				stackCopyReverse[stack].Pop().Print();
				done = false;
			}
			else
			{
				cout << "      ";
			}
		}
		cout << "    " << endl;
	}

	delete[] stackCopy;
	delete[] stackCopyReverse;
}
