#include "Person.h"

Person::Person(const string& name, unsigned int id)
	: m_name(name)
	, m_Id(id)
{}

int Person::findRegNum(const string& regNum)
{
	size_t len = m_vehicles.size();
	for (size_t i = 0; i < len; i++)
	{
		if (m_vehicles[i] == regNum)
		{
			return i;
		}
	}

	return -1;
}

void Person::addRegNum(const string & regNum)
{
	if (findRegNum(regNum) != -1)
	{
		throw std::invalid_argument("This person already has this vehicle!");
	}

	m_vehicles.push_back(regNum);
}

void Person::removeRegNum(const string& regNum)
{
	int ind = findRegNum(regNum);
	if (ind == -1)
	{
		throw std::invalid_argument("There is no person with this vehicle!");
	}

	m_vehicles.erase(m_vehicles.begin() + ind);
}

std::istream& operator>>(std::istream& in, Person& obj)
{
	in >> obj.m_name >> obj.m_Id;
	size_t size = obj.m_vehicles.size();
	for (size_t i = 0; i < size; i++)
	{
		in >> obj.m_vehicles[i];
	}

	return in;
}

ostream& operator<<(ostream& out, const Person& obj)
{
	out << obj.m_name << " with ID: " << obj.m_Id << " has cars with registrations: ";
	size_t size = obj.m_vehicles.size();
	for (size_t i = 0; i < size; i++)
	{
		out << obj.m_vehicles[i].toString() << ' ';
	}

	return out;
}
