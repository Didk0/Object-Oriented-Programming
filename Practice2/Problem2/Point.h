#pragma once
#include <iostream>

struct Point
{
	void read();
	void print();
	double distanceToCenter();
	double distanceBetweenTwoDots(const Point& other);

	double m_coord1, m_coord2;
};