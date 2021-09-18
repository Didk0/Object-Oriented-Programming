#include "Vehicle.h"

Vehicle::Vehicle(const char* regNum, const char* description, std::size_t space)
	: m_regNum(regNum)
	, m_description(description)
	, m_space(space)
{
	if (m_space == 0)
	{
		throw std::invalid_argument("Invalid space!");
	}
}

const char* Vehicle::registration() const
{
	return m_regNum.c_str();
}

const char* Vehicle::description() const
{
	return m_description.c_str();
}

size_t Vehicle::space() const
{
	return m_space;
}
