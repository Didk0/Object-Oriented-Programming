#include "Point.h"

void Point::read()
{
	std::cin >> m_coord1 >> m_coord2;
}

void Point::print()
{
	std::cout << '(' << m_coord1 << ',' << m_coord2 << ')' << std::endl;
}

double Point::distanceToCenter()
{
	return std::sqrt(m_coord1 * m_coord1 + m_coord2 * m_coord2);
}

double Point::distanceBetweenTwoDots(const Point& other)
{
	return sqrt((m_coord1 - other.m_coord1)* (m_coord1 - other.m_coord1) +
		(m_coord2 - other.m_coord2)* (m_coord2 - other.m_coord2));
}
