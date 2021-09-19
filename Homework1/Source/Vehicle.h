#pragma once
#include "MyString.h"

class Vehicle
{
public:
	Vehicle(const char* regNum, const char* description, std::size_t space);
	const char* registration() const;
	const char* description() const;
	size_t space() const;

private:
	MyString m_regNum;
	MyString m_description;
	size_t m_space;
};

