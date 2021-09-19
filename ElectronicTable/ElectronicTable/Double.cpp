#include "Double.h"

Double::Double(const string& value)
	: m_value(std::stod(value))
{}

const double Double::operator+(const Type& other) const
{
	double result = m_value + other.getValue();

	return result;
}

const double Double::operator-(const Type& other) const
{
	double result = m_value - other.getValue();

	return result;
}

const double Double::operator*(const Type& other) const
{
	double result = m_value * other.getValue();

	return result;
}

const double Double::operator/(const Type& other) const
{
	if (other.getValue() == 0)
	{
		throw std::invalid_argument("Cannot divide by 0!");
	}
	double result = m_value / other.getValue();

	return result;
}

const double Double::operator^(const Type& other) const
{
	double result = pow(m_value, other.getValue());
	return result;
}

void Double::print() const
{
	std::cout << toString();
}

size_t Double::getSize() const
{
	return std::to_string(m_value).size();
}

double Double::getValue() const
{
	if (!this)
	{
		return 0;
	}

	return m_value;
}

string Double::toString() const
{
	return std::to_string(m_value);
}
