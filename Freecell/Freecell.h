/*************************************************************
* Author: Dillon Wall
* Filename: Freecell.h
* Date Created: 1/19/2019
* Modifications:
**************************************************************/

#pragma once

#include "Area.h"
#include "Card.h"
#include "PlayArea.h"
#include "HomeArea.h"
#include "FreeArea.h"
#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;

/************************************************************************
* Class: Freecell
*
* Purpose: This class is the main game controller and handles the Input and Printing of the game
*
* Manager functions:
* Freecell();
* ~Freecell();
* Freecell(const Freecell& copy);
* Freecell& operator=(const Freecell& rhs);
*
* Methods:
* bool Won() const
*		Checks the HomeArea to see if the game is won
* bool Update(char * input)
*		Takes in a line of input and parses it to do the correct actions
* void Print()
*		Prints the game to the console
*
* bool Move(Area * fromArea, int fromPos, Area * toArea, int toPos);
*		Removes a card from one area and adds it to another
* bool MoveCard(Card card, Area* toArea, int toPos, bool testingCanMove);
*		Returns if a card can move to the specified area, if 'testingCanMove' is true, it also adds the card to that area
* bool MoveStack(Area * fromArea, int fromPos, Area * toArea, int toPos, int amount, int vacantFreeCells);
*		Moves a stack of cards recursively based on the amount to move
* bool CheckBounds(Area * area, int pos);
*		Checks if a card selection is within its Area boundaries
* Area* ParseAreaInput(char * p);
*		Gets the next strtok and returns a corresponding Area
* bool CheckAlternatingColors(Card& card1, Card& card2);
*		Returns if the two cards have alternating colors
* bool CheckInSequence(Card& lower, Card& higher);
*		Returns if the two cards are in sequence
* bool CheckSuitPos(Card& card, int pos);
*		Checks if the card's suit is going to the correct position for its suit in the HomeArea
* int GetNumFreeCells();
*		Returns how many freecells are unused
*
*
*************************************************************************/

class Freecell
{
public:
	Freecell();
	~Freecell();
	Freecell(const Freecell& copy);
	Freecell& operator=(const Freecell& rhs);

	bool Won() const;
	bool Update(char * input);
	void Print();

private:
	bool Move(Area * fromArea, int fromPos, Area * toArea, int toPos);
	bool MoveCard(Card card, Area* toArea, int toPos, bool testingCanMove);
	bool MoveStack(Area * fromArea, int fromPos, Area * toArea, int toPos, int amount, int vacantFreeCells);
	bool CheckBounds(Area * area, int pos);
	Area* ParseAreaInput(char * p);
	bool CheckAlternatingColors(Card& card1, Card& card2);
	bool CheckInSequence(Card& lower, Card& higher);
	bool CheckSuitPos(Card& card, int pos);
	int GetNumFreeCells();

	PlayArea * m_pArea;
	FreeArea * m_fArea;
	HomeArea * m_hArea;
};

