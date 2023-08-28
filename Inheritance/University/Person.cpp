#include <iostream>
#include "Person.h"

Person::Person(const string& name, unsigned int age)
	: m_name(name)
	, m_age(age)
{}

void Person::print() const
{
	std::cout << m_name << " is " << m_age << " years old";
}
