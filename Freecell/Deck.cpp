/*************************************************************
* Author: Dillon Wall
* Filename: Deck.cpp
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#include "Deck.h"



Deck::Deck() : m_cards(NUM_CARDS), m_numCards(NUM_CARDS)
{
	char suits[4] = { Card::SPADES, Card::CLUBS, Card::HEARTS, Card::DIAMONDS };
	int pos = 0;

	for (char suit : suits)
	{
		for (int val = 1; val <= 13; ++val)
		{
			m_cards[pos] = Card(suit, val);
			++pos;
		}
	}
}


Deck::~Deck()
{
	m_cards = Array<Card>();
	m_numCards = 0;
}

bool Deck::IsEmpty() const
{
	return m_numCards <= 0;
}

void Deck::Shuffle()
{
	for (int times = 0; times < 3; ++times)
	{
		for (int i = 0; i < m_numCards; ++i)
		{
			int r = Random::GetRand(51);
			Card temp = m_cards[i];
			m_cards[i] = m_cards[r];
			m_cards[r] = temp;
		}
	}
}

Card & Deck::Draw()
{
	if (m_numCards <= 0) 
		throw Exception("No more cards left to draw (Deck) (Draw)");
	
	return m_cards[--m_numCards];
}
