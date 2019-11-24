/*************************************************************
* Author: Dillon Wall
* Filename: FreeArea.h
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#pragma once

#include "Array.h"
#include "Card.h"
#include "Area.h"

/************************************************************************
* Class: FreeArea
*
* Purpose: This class represents the area with Free Cells on the gameboard
*
* Manager functions:
* FreeArea();
* ~FreeArea();
* FreeArea(const FreeArea& copy);
* FreeArea& operator=(const FreeArea& rhs);
*
* Methods:
* bool IsOccupied(int pos) const;
*		Returns true if the position already has a card
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

class FreeArea :
	public Area
{
public:
	FreeArea();
	~FreeArea();
	FreeArea(const FreeArea& copy);
	FreeArea& operator=(const FreeArea& rhs);

	static const int NUM_FREE_CELLS = 4;

	bool IsOccupied(int pos) const;
	virtual bool AddCard(Card card, int pos) override;
	virtual Card RemoveCard(int pos) override;
	virtual Card GetCard(int pos) override;
	virtual void Print() const override;

private:
	Array<Card> m_cells;

	// Inherited via Area

};

