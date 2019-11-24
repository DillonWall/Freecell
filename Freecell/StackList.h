/*************************************************************
* Author: Dillon Wall
* Filename: StackList.h
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#pragma once

#include "List.h"
#include "Exception.h"

/************************************************************************
* Class: StackList
*
* Purpose: This class is a LinkedList-based Stack
*
* Manager functions:
* StackList();
* StackList(const StackList<T>& copy);
* ~StackList();
* StackList<T>& operator=(const StackList<T>& rhs);
*
* Methods:
* void Push(const T& item);
*		Push an item onto the stack
* T Pop();
*		Return and pop an item from the stack
* const T& Peek() const;
*		Return the item at the top of the stack
* int Size() const;
*		Return the number of elements in the stack
* bool isEmpty() const;
*		Returns if the stack is empty
*
*
*************************************************************************/

template <typename T>
class StackList
{
public:
	StackList();
	StackList(const StackList<T>& copy);
	~StackList();
	StackList<T>& operator=(const StackList<T>& rhs);

	void Push(const T& item);
	T Pop();
	const T& Peek() const;
	int Size() const;
	bool isEmpty() const;

private:
	List<T>* m_list;
	int m_numElements;
};


template <typename T>
inline StackList<T>::StackList() : m_list(nullptr), m_numElements(0)
{
	m_list = new List<T>();
}

template<typename T>
inline StackList<T>::StackList(const StackList<T> & copy) : m_list(nullptr), m_numElements(copy.m_numElements)
{
	m_list = new List<T>(*(copy.m_list));
}


template <typename T>
inline StackList<T>::~StackList()
{
	delete m_list;
	m_numElements = 0;
}

template<typename T>
inline StackList<T> & StackList<T>::operator=(const StackList<T> & rhs)
{
	if (this != &rhs)
	{
		delete m_list;
		m_numElements = 0;

		m_list = new List<T>(*(rhs.m_list));
		m_numElements = rhs.m_numElements;
	}

	return *this;
}

template<typename T>
inline void StackList<T>::Push(const T& item)
{
	m_list->Append(item);
	++m_numElements;
}

template<typename T>
inline T StackList<T>::Pop()
{
	if (isEmpty()) 
		throw Exception("StackList Underflow");

	--m_numElements;
	T last = m_list->Last();
	m_list->Extract(last);
	return last;
}

template<typename T>
inline const T& StackList<T>::Peek() const
{
	if (isEmpty()) 
		throw Exception("Peeking empty stack");

	return m_list->Last();
}

template<typename T>
inline int StackList<T>::Size() const
{
	return m_numElements;
}

template<typename T>
inline bool StackList<T>::isEmpty() const
{
	return (m_numElements == 0) ? true : false;
}