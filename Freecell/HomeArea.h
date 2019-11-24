/*************************************************************
* Author: Dillon Wall
* Filename: HomeArea.h
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#pragma once
#include "Area.h"
#include "Stack.h"
#include "Card.h"

/************************************************************************
* Class: HomeArea
*
* Purpose: This class represents the Home area on the gameboard
*
* Manager functions:
* HomeArea();
* ~HomeArea();
* HomeArea(const HomeArea& copy);
* HomeArea& operator=(const HomeArea& rhs);
*
* Methods:
* virtual bool AddCard(Card card, int pos) override;
*		Adds a card to the specified position
* virtual Card RemoveCard(int pos) override;
*		Removes a card to the specified position
* virtual Card GetCard(int pos) override;
*		Gets a card at the specified position
* virtual void Print() const override;
*		Prints all the cards in the area
* bool Won() const;
*		Returns whether the game is won or not
*
*
*************************************************************************/

class HomeArea :
	public Area
{
public:
	HomeArea();
	~HomeArea();
	HomeArea(const HomeArea& copy);
	HomeArea& operator=(const HomeArea& rhs);

	static const int MAX_CARD_STACK = 13;
	static const int NUM_HOME_AREAS = 4;

	virtual bool AddCard(Card card, int pos) override;
	virtual Card RemoveCard(int pos) override;
	virtual Card GetCard(int pos) override;
	bool Won() const;
	virtual void Print() const override;

private:
	Stack<Card>* m_cardStacks;
};

