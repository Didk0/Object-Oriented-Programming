#pragma once
#include "Food.h"

class Salad : public Food
{
public:
	Salad(double weight = 0, size_t partsCount = 0, double partWeight = 0, double price = 0, size_t productsCount = 0, bool hasIngrediants = false)
		: Food(weight, partsCount, partWeight, price)
		, m_productsCount(productsCount)
		, m_hasIngrediants(hasIngrediants)
	{}

	Salad(const Food& food, size_t productsCount = 0, bool hasIngrediants = false)
		: Food(food.getWeight(), food.getPartsCount(), food.getPartWeight(), food.getPrice())
		, m_productsCount(productsCount)
		, m_hasIngrediants(hasIngrediants)
	{}

	void print() const
	{
		Food::print();
		std::cout << " The food is salad with " << m_productsCount << " products and " << (m_hasIngrediants? "has" : "hasn't") << " ingrediants";
	}

private:
	size_t m_productsCount;
	bool m_hasIngrediants;
};

