#pragma once
#include <vector>
#include <iostream>

class Food
{
public:
	Food(double weight = 0, size_t partsCount = 0, double partWeight = 0, double price = 0)
		: m_weight(weight)
		, m_partsCount(partsCount)
		, m_partWeight(partWeight)
		, m_price(price)
	{}

	inline const double getWeight() const { return m_weight; };
	inline const size_t getPartsCount() const { return m_partsCount; };
	inline const double getPartWeight() const { return m_partWeight; };
	inline const double getPrice() const { return m_price; };

	void consume()
	{
		m_partsCount--;
		m_weight -= m_partWeight;
	}

	void print() const
	{
		std::cout << "Food with weight " << m_weight << ", " << m_partsCount << " parts, "
			<< "weight per part " << m_partWeight << " and price " << m_price << "$.";
	}

private:
	double m_weight;
	size_t m_partsCount;
	double m_partWeight;
	double m_price;
};

