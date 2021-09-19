#include "Type.h"

const double Type::operator+(const Type& other) const
{
	double result = (double)m_value + other.getValue();

	return result;
}
