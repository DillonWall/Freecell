/*************************************************************
* Author: Dillon Wall
* Filename: Deck.h
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#pragma once

#include "Card.h"
#include "Array.h"
#include "Random.h"

/************************************************************************
* Class: Deck
*
* Purpose: This class represents a deck of playing cards
*
* Manager functions:
* Deck();
* ~Deck();
*
* Methods:
* bool IsEmpty() const;
*		Returns true if the deck is empty
* void Shuffle();
*		Shuffles the deck
* Card& Draw();
*		Returns a card from the top of the deck and removes it
*
*
*************************************************************************/

class Deck
{
public:
	Deck();
	~Deck();

	static const int NUM_CARDS = 52;

	bool IsEmpty() const;
	void Shuffle();
	Card& Draw();

private:
	Array<Card> m_cards;
	int m_numCards;
};

