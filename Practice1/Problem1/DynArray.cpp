#include "DynArray.h"

void DynArray::create(size_t capacity)
{
	m_capacity = capacity;

	m_arr = new int[capacity];
}

void DynArray::push_back(int elem)
{
	if (m_size >= m_capacity)
	{
		resize();
	}

	m_arr[m_size] = elem;
	++m_size;
}

void DynArray::resize()
{
	if (m_capacity == 0)
	{
		m_capacity = 1;
	}
	int* newArr = new int[m_capacity * 2];
	m_capacity *= 2;

	for (size_t i = 0; i < m_size; i++)
	{
		newArr[i] = m_arr[i];
	}

	delete[] m_arr;
	m_arr = newArr;
}

void DynArray::pop_back()
{
	--m_size;
}

int DynArray::get(size_t index)
{
	if (index >= 0 && index < m_size)
	{
		return m_arr[index];
	}
	return -1;
}

void DynArray::remove(size_t index)
{
	for (size_t i = index; i < m_size - 1; i++)
	{
		m_arr[i] = m_arr[i + 1];
	}
	--m_size;
}

void DynArray::map(void(func)(int&))
{
	for (size_t i = 0; i < m_size; i++)
	{
		func(m_arr[i]);
	}
}

void DynArray::filter(bool(func)(int))
{
	for (size_t i = 0; i < m_size; i++)
	{
		if (func(m_arr[i]))
		{
			remove(i);
			--i;
		}
	}
}
