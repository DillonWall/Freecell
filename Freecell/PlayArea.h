/*************************************************************
* Author: Dillon Wall
* Filename: PlayArea.h
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#pragma once
#include "Area.h"
#include "Card.h"
#include "Deck.h"
#include "StackList.h"
#include <iostream>

using std::cout;
using std::endl;

/************************************************************************
* Class: PlayArea
*
* Purpose: This class represents the Play area on the gameboard
*
* Manager functions:
* PlayArea();
* ~PlayArea();
* PlayArea(const PlayArea& copy);
* PlayArea& operator=(const PlayArea& rhs);
*
* Methods:
* bool IsEmpty(int pos) const;
*		Returns if the stack at the position given is empty
* virtual bool AddCard(Card card, int pos) override;
*		Adds a card to the specified position
* virtual Card RemoveCard(int pos) override;
*		Removes a card to the specified position
* virtual Card GetCard(int pos) override;
*		Gets a card at the specified position
* virtual void Print() const override;
*		Prints all the cards in the area
*
*
*************************************************************************/

class PlayArea :
	public Area
{
public:
	PlayArea();
	~PlayArea();
	PlayArea(const PlayArea& copy);
	PlayArea& operator=(const PlayArea& rhs);

	static const int NUM_STACKS = 8;

	bool IsEmpty(int pos) const;
	virtual bool AddCard(Card card, int pos) override;
	virtual Card RemoveCard(int pos) override;
	virtual Card GetCard(int pos) override;
	virtual void Print() const override;

private:
	StackList<Card>* m_stacks;

};

