/*************************************************************
* Author: Dillon Wall
* Filename: Array.h
* Date Created: 1/19/2019
* Modifications:
**************************************************************/


#pragma once

#include "Exception.h"


/************************************************************************
* Class: Array
*
* Purpose: This class is a dynamic array
*
* Manager functions:
* Array()
*		Creates default Array where m_array is nullptr, m_length is 0 and m_start_length is 0
* Array(int length, int start_index = 0)
*		Creates a Array with a specific length and start_index
* Array(const Array& other)
* Array& operator=(const Array& other)
* ~Array()
* T& operator[](int index)
*		Get an element from the array
* const T& operator[](int index) const
*		Get an element from a const array
*
* Methods:
* int GetStartIndex() const
* void SetStartIndex(int start_index)
* int GetLength() const
* void SetLength(int length)
*
*
*************************************************************************/

template <typename T>
class Array
{
public:
	Array();
	Array(int length, int start_index = 0);
	Array(const Array<T>& copy);
	~Array();
	Array& operator=(const Array<T>& rhs);
	T& operator[](int index);
	const T& operator[](int index) const;

	int GetStartIndex() const;
	void SetStartIndex(int start_index);
	int GetLength() const;
	void SetLength(int length);

private:
	T * m_array;
	int m_length;
	int m_start_index;

};



///Source Code///

template<typename T>
Array<T>::Array() : m_array(nullptr), m_length(0), m_start_index(0)
{
}

template<typename T>
Array<T>::Array(int length, int start_index) : m_array(nullptr), m_length(length), m_start_index(start_index)
{
	if (m_length >= 0) m_array = new T[m_length];
	else throw Exception("Invalid length (less than 0)");
}

template<typename T>
Array<T>::Array(const Array<T> & copy) : m_array(nullptr), m_length(copy.m_length), m_start_index(copy.m_start_index)
{
	m_array = new T[copy.m_length];

	for (int i = 0; i < copy.m_length; ++i)
	{
		m_array[i] = copy.m_array[i];
	}
}

template<typename T>
Array<T>::~Array()
{
	delete[] m_array;
	m_array = nullptr;
	m_length = 0;
	m_start_index = 0;
}

template<typename T>
Array<T> & Array<T>::operator=(const Array<T> & rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;

		m_length = rhs.m_length;
		m_start_index = rhs.m_start_index;
		m_array = new T[rhs.m_length];
		for (int i = 0; i < rhs.m_length; ++i)
		{
			m_array[i] = rhs.m_array[i];
		}
	}

	return *this;
}

template<typename T>
inline T & Array<T>::operator[](int index)
{
	if (index - m_start_index >= m_length) throw Exception("Array index out of bounds (larger than max range)");
	if (index - m_start_index < 0) throw Exception("Array index out of bounds (smaller than start index)");
	return m_array[index - m_start_index];
}

template<typename T>
const T & Array<T>::operator[](int index) const
{
	if (index - m_start_index >= m_length) throw Exception("Array index out of bounds (larger than max range)");
	if (index - m_start_index < 0) throw Exception("Array index out of bounds (smaller than start index)");
	return m_array[index - m_start_index];
}

template<typename T>
int Array<T>::GetStartIndex() const
{
	return m_start_index;
}

template<typename T>
void Array<T>::SetStartIndex(int start_index)
{
	m_start_index = start_index;
}

template<typename T>
int Array<T>::GetLength() const
{
	return m_length;
}

template<typename T>
void Array<T>::SetLength(int length)
{
	if (length < 0) throw Exception("Invalid length (less than 0)");
	if (m_length < length)
	{
		T * newArr = new T[length];
		for (int i = 0; i < m_length; ++i)
		{
			newArr[i] = m_array[i];
		}

		delete[] m_array;
		m_array = newArr;
	}

	m_length = length;
}


