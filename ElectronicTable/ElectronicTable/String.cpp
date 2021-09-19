#include "String.h"

String::String(const string& value)
	: m_value(value)
{}

String& String::operator=(const string & str)
{
	m_value = str;
	return *this;
}

const double String::operator+(const Type& other) const
{
	return getValue() + other.getValue();
}

const double String::operator-(const Type& other) const
{
	return getValue() - other.getValue();
}

const double String::operator*(const Type& other) const
{
	return getValue() * other.getValue();
}

const double String::operator/(const Type& other) const
{
	if (other.getValue() == 0)
	{
		throw std::invalid_argument("Cannot divide by 0!");
	}
	return getValue() / other.getValue();
}

const double String::operator^(const Type& other) const
{
	return pow(getValue(),other.getValue());
}

void String::print() const
{
	std::cout << m_value;
}

size_t String::getSize() const
{
	return m_value.size();
}

double String::getValue() const
{
	if (!Proccessor::isInteger(m_value) && !Proccessor::isDouble(m_value))
	{
		return 0;
	}

	return std::stod(m_value);
}

string String::toString() const
{
	return m_value;
}
