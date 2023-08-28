#include "DynArray.h"
#include <iostream>

void print(DynArray& arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr.get(i) << ' ';
	}
	std::cout << std::endl;
}

bool isEven(int elem) 
{
	return elem % 2 == 0; 
}


void square(int& elem) 
{ 
	elem *= 2; 
}

int main()
{
	DynArray arr;
	arr.create(3);
	arr.resize();

	arr.push_back(5);

	print(arr, arr.m_size);

	arr.push_back(3);
	arr.push_back(8);
	arr.push_back(10);
	arr.push_back(24);

	arr.pop_back();

	print(arr, arr.m_size);
	
	arr.remove(0);

	print(arr, arr.m_size);

	arr.filter(isEven);

	print(arr, arr.m_size);

	arr.map(square);

	print(arr, arr.m_size);

	return 0;
}