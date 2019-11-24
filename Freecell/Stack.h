/*************************************************************
* Author: Dillon Wall
* Filename: Stack.h
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#pragma once

#include "Array.h"
#include "Exception.h"

/************************************************************************
* Class: Stack
*
* Purpose: This class is an Array-based Stack
*
* Manager functions:
* Stack();
* Stack(int size);
* Stack(const Stack<T>& copy);
* ~Stack();
* Stack<T>& operator=(const Stack<T>& rhs);
*
* Methods:
* void Push(const T& item);
*		Push an item onto the stack
* T Pop();
*		Return and pop an item from the stack
* T& Peek() const;
*		Return the item at the top of the stack
* int Size() const;
*		Return the number of elements in the stack
* bool isEmpty() const;
*		Returns if the stack is empty
* bool isFull() const;
*		Returns if the stack is full
* void setSize(int size);
*		Sets a new size
*
*
*************************************************************************/

template <typename T>
class Stack
{
public:
	Stack();
	Stack(int size);
	Stack(const Stack<T>& copy);
	~Stack();
	Stack<T>& operator=(const Stack<T>& rhs);

	void Push(const T& item);
	T Pop();
	T& Peek() const;
	int Size() const;
	bool isEmpty() const;
	bool isFull() const;
	void setSize(int size);

private:
	Array<T>* m_arr;
	int m_numElements;
};


template <typename T>
inline Stack<T>::Stack() : m_arr(nullptr), m_numElements(0)
{
	m_arr = new Array<T>();
}

template<typename T>
inline Stack<T>::Stack(int size) : m_arr(nullptr), m_numElements(0)
{
	if (size < 0) 
		throw Exception("Size less than 0");
	m_arr = new Array<T>(size);
}

template<typename T>
inline Stack<T>::Stack(const Stack<T> & copy) : m_arr(nullptr), m_numElements(copy.m_numElements)
{
	m_arr = new Array<T>(*(copy.m_arr));
}


template <typename T>
inline Stack<T>::~Stack()
{
	delete m_arr;
	m_numElements = 0;
}

template<typename T>
inline Stack<T> & Stack<T>::operator=(const Stack<T> & rhs)
{
	if (this != &rhs)
	{
		delete m_arr;
		m_numElements = 0;

		m_arr = new Array<T>(*(rhs.m_arr));
		m_numElements = rhs.m_numElements;
	}

	return *this;
}

template<typename T>
inline void Stack<T>::Push(const T& item)
{
	if (isFull()) 
		throw Exception("Stack Overflow");

	(*m_arr)[m_numElements] = item;
	++m_numElements;
}

template<typename T>
inline T Stack<T>::Pop()
{
	if (isEmpty()) 
		throw Exception("Stack Underflow");

	--m_numElements;
	return (*m_arr)[m_numElements];
}

template<typename T>
inline T& Stack<T>::Peek() const
{
	if (isEmpty()) 
		throw Exception("Peeking empty stack");

	return (*m_arr)[m_numElements - 1];
}

template<typename T>
inline int Stack<T>::Size() const
{
	return m_numElements;
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return (m_numElements == 0) ? true : false;
}

template<typename T>
inline bool Stack<T>::isFull() const
{
	return (m_numElements == m_arr->GetLength()) ? true : false;
}

template<typename T>
inline void Stack<T>::setSize(int size)
{
	if (size < 0) 
		throw Exception("Size less than 0");
	if (size < m_numElements) 
		throw Exception("Attempted to set a size smaller than number of elements");

	Array<T>* newArr = new Array<T>(size);
	for (int i = 0; i < m_numElements; ++i)
	{
		(*newArr)[i] = (*m_arr)[i];
	}

	delete m_arr;
	m_arr = newArr;

}
