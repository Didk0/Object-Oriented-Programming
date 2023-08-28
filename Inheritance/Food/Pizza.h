#pragma once
#include <string>
#include "Food.h"

using std::string;

class Pizza : public Food
{
public:
	Pizza(double weight = 0, size_t partsCount = 0, double partWeight = 0, double price = 0, const string& type = "")
		: Food(weight, partsCount, partWeight, price)
		, m_type(type)
	{}

	Pizza(const Food& food, const string& type = "")
		: Food(food.getWeight(), food.getPartsCount(), food.getPartWeight(), food.getPrice())
	{}

	void print() const
	{
		Food::print();
		std::cout << " The food is " << m_type << " pizza";
	}

private:
	string m_type;
};

