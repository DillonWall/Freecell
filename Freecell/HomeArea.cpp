/*************************************************************
* Author: Dillon Wall
* Filename: HomeArea.cpp
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#include "HomeArea.h"



HomeArea::HomeArea() : m_cardStacks(nullptr)
{
	m_cardStacks = new Stack<Card>[NUM_HOME_AREAS];
	for (int i = 0; i < NUM_HOME_AREAS; ++i)
	{
		m_cardStacks[i] = Stack<Card>(MAX_CARD_STACK);
	}
}


HomeArea::~HomeArea()
{
	delete[] m_cardStacks;
}

HomeArea::HomeArea(const HomeArea & copy) : m_cardStacks(nullptr)
{
	m_cardStacks = new Stack<Card>[NUM_HOME_AREAS];
	for (int i = 0; i < NUM_HOME_AREAS; ++i)
	{
		m_cardStacks[i] = Stack<Card>(copy.m_cardStacks[i]);
	}
}

HomeArea & HomeArea::operator=(const HomeArea & rhs)
{
	if (this != &rhs)
	{
		delete[] m_cardStacks;

		m_cardStacks = new Stack<Card>[NUM_HOME_AREAS];
		for (int i = 0; i < NUM_HOME_AREAS; ++i)
		{
			m_cardStacks[i] = Stack<Card>(rhs.m_cardStacks[i]);
		}
	}

	return *this;
}

bool HomeArea::AddCard(Card card, int pos)
{
	if (pos < 0 || pos >= NUM_HOME_AREAS)
		throw Exception("Stack number out of bounds (HomeArea) (AddCard)");

	//char suit = card.GetSuit();
	//int stackNum = -1;
	//if (suit == Card::SPADES)
	//	stackNum = 0;
	//else if (suit == Card::CLUBS)
	//	stackNum = 1;
	//else if (suit == Card::HEARTS)
	//	stackNum = 2;
	//else if (suit == Card::DIAMONDS)
	//	stackNum = 3;

	if (!m_cardStacks[pos].isEmpty() && m_cardStacks[pos].Peek().GetValue() != card.GetValue() - 1)
		return false;

	m_cardStacks[pos].Push(card);
	return true;
}

Card HomeArea::RemoveCard(int pos)
{
	throw Exception("Tried to remove card from HomeArea (HomeArea) (RemoveCard)");
	return Card();
}

Card HomeArea::GetCard(int pos)
{
	if (pos < 0 || pos >= NUM_HOME_AREAS)
		throw Exception("Stack number out of bounds (HomeArea) (GetCard)");

	//int stackNum = -1;
	//if (suit == Card::SPADES)
	//	stackNum = 0;
	//else if (suit == Card::CLUBS)
	//	stackNum = 1;
	//else if (suit == Card::HEARTS)
	//	stackNum = 2;
	//else if (suit == Card::DIAMONDS)
	//	stackNum = 3;
	if (m_cardStacks[pos].isEmpty())
		return Card();

	return m_cardStacks[pos].Peek();
}

bool HomeArea::Won() const
{
	bool retVal = true;
	for (int i = 0; i < NUM_HOME_AREAS && retVal; ++i)
	{
		if (m_cardStacks[i].Size() != MAX_CARD_STACK)
			retVal = false;
	}
	return retVal;
}

void HomeArea::Print() const
{
	for (int i = 0; i < NUM_HOME_AREAS; ++i)
	{
		if (!m_cardStacks[i].isEmpty())
			m_cardStacks[i].Peek().Print();
		else
			Card().Print();
	}
}
