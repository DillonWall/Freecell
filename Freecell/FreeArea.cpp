/*************************************************************
* Author: Dillon Wall
* Filename: FreeArea.cpp
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#include "FreeArea.h"



FreeArea::FreeArea() : m_cells(NUM_FREE_CELLS)
{
}


FreeArea::~FreeArea()
{
	m_cells = Array<Card>(NUM_FREE_CELLS);
}

FreeArea::FreeArea(const FreeArea & copy) : m_cells(copy.m_cells)
{
}

FreeArea & FreeArea::operator=(const FreeArea & rhs)
{
	if (this != &rhs)
	{
		m_cells = Array<Card>(rhs.m_cells);
	}

	return *this;
}

bool FreeArea::IsOccupied(int pos) const
{
	if (pos >= NUM_FREE_CELLS || pos < 0) 
		throw Exception("Selected Cell out of bounds (FreeArea) (IsOccupied)");

	if (m_cells[pos].GetSuit() == Card::NONE)
		return false;
	return true;
}

bool FreeArea::AddCard(Card card, int pos)
{
	if (pos >= NUM_FREE_CELLS || pos < 0) 
		throw Exception("Selected Cell out of bounds (FreeArea) (AddCard)");

	if (IsOccupied(pos))
		return false;
	m_cells[pos] = card;
	return true;
}

Card FreeArea::RemoveCard(int pos)
{
	if (pos >= NUM_FREE_CELLS || pos < 0) 
		throw Exception("Selected Cell out of bounds (FreeArea) (RemoveCard)");
	
	if (!IsOccupied(pos))
	{
		throw Exception("Tried to remove card from empty free area. Check IsOccupied first (FreeArea) (RemoveCard)");
		return m_cells[0];
	}

	Card retVal = m_cells[pos];
	m_cells[pos] = Card();
	return retVal;
}

Card FreeArea::GetCard(int pos)
{
	if (pos >= NUM_FREE_CELLS || pos < 0) 
		throw Exception("Selected Cell out of bounds (FreeArea) (GetCard)");
	
	return m_cells[pos];
}

void FreeArea::Print() const
{
	for (int i = 0; i < NUM_FREE_CELLS; ++i)
	{
		m_cells[i].Print();
	}
}
