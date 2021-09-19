#include "Vehicle.h"

Vehicle::Vehicle(const string& regnum, const string& description)
	: m_regnum(regnum)
	, m_description(description)
	, m_personID(0)
{}

void Vehicle::setOwner(unsigned int ID)
{
	m_personID = ID;
}

istream& operator>>(istream& in, Vehicle& obj)
{
	in >> obj.m_regnum >> obj.m_description;

	return in;
}

ostream& operator<<(ostream& out, const Vehicle& obj)
{
	out << obj.m_description << " with registration: " << obj.m_regnum.toString();

	return out;
}
