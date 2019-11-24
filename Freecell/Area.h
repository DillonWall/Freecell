/*************************************************************
* Author: Dillon Wall
* Filename: Area.h
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#pragma once

#include "Card.h"

/************************************************************************
* Class: Area
*
* Purpose: This class is a pure abstract class representing an area on the gameboard
*
* Manager functions:
* Area()
*
* Methods:
* virtual bool AddCard(Card card, int pos) = 0;
*		Adds a card to the specified position
* virtual Card RemoveCard(int pos) = 0;
*		Removes a card to the specified position
* virtual Card GetCard(int pos) = 0;
*		Gets a card at the specified position
* virtual void Print() const = 0;
*		Prints all the cards in the area
*
*
*************************************************************************/

class Area
{
public:
	Area() {};

	virtual bool AddCard(Card card, int pos) = 0;
	virtual Card RemoveCard(int pos) = 0;
	virtual Card GetCard(int pos) = 0;
	virtual void Print() const = 0;
};

