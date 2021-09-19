#include "Integer.h"

Integer::Integer(const string& value)
	: m_value(std::stoi(value))
{}

const double Integer::operator+(const Type & other) const
{
	double result = (double)m_value + other.getValue();

	return result;
}
 
const double Integer::operator-(const Type& other) const
{
	double result = (double)m_value - other.getValue();

	return result;
}

const double Integer::operator*(const Type& other) const
{
	double result = (double)m_value * other.getValue();

	return result;
}

const double Integer::operator/(const Type& other) const
{
	if (other.getValue() == 0)
	{
		throw std::invalid_argument("Cannot divide by 0!");
	}
	double result = (double)m_value / other.getValue();

	return result;
}

const double Integer::operator^(const Type& other) const
{
	double result = pow((double)m_value, other.getValue());
	return result;
}

void Integer::print() const
{
	std::cout << toString();
}

size_t Integer::getSize() const
{
	return std::to_string(m_value).size();
}

double Integer::getValue() const
{
	return m_value;
}

string Integer::toString() const
{
	return std::to_string(m_value);
}
