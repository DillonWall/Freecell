/*************************************************************
* Author: Dillon Wall
* Filename: Card.h
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#pragma once

#include <Windows.h>
#include <iostream>
using std::cout;

/************************************************************************
* Class: Card
*
* Purpose: This class represents a playing card
*
* Manager functions:
* Card();
* Card(char suit, int value);
* ~Card();
* Card(const Card& copy);
* Card& operator=(const Card& rhs);
* bool operator!=(const Card& rhs) const;
* bool operator==(const Card& rhs) const;
*
* Methods:
* char GetSuit() const;
*		Returns m_suit
* int GetValue() const;
*		Returns m_value
* void Print() const;
*		Prints the card such as: [QS] for queen of spades
*
*
*************************************************************************/

class Card
{
public:
	enum SUIT : char {SPADES = 'S', CLUBS = 'C', HEARTS = 'H', DIAMONDS = 'D', NONE = 'N'};

	Card();
	Card(char suit, int value);
	~Card();
	Card(const Card& copy);
	Card& operator=(const Card& rhs);
	bool operator!=(const Card& rhs) const;
	bool operator==(const Card& rhs) const;

	char GetSuit() const;
	int GetValue() const;
	void Print() const;

	static HANDLE hConsole;

private:
	char m_suit;
	int m_value;
};

