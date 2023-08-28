#pragma once
#include <vector>
#include "Food.h"
#include"Pizza.h"

using foods = std::vector<Food*>;

class Menu
{
public:
	Menu()
	{}

	void addProduct(Food& product)
	{
		m_foods.push_back(&product);
	}

	void removeProduct(Food& product)
	{
		m_foods.erase(m_foods.begin() + findProductInd(product));
	}

	const int findProductInd(Food& product) const
	{
		for (size_t i = 0; i < m_foods.size(); i++)
		{
			if (m_foods[i] == &product)
			{
				return i;
			}
		}
		return -1;
	}

	void printProducts() const
	{
		for (size_t i = 0; i < m_foods.size(); i++)
		{
			m_foods[i]->print();
			std::cout << std::endl;
		}
	}

	void printCheapesProduct() const
	{
		double minPrice = 0;
		int ind = 0;
		for (size_t i = 0; i < m_foods.size(); i++)
			if (m_foods[i]->getPrice() < minPrice)
			{
				minPrice = m_foods[i]->getPrice();
				ind = i;
			}

		std::cout << "The cheapest product: " << std::endl;
		m_foods[ind]->print();
	}

private:
	foods m_foods;
};

