#include "Formula.h"

Formula::Formula(const string& expression, const Table* table)
	: m_value(0)
	, m_expression(expression)
	, m_table(table)
{
	Proccessor::putWhiteSpaces(m_expression);
	Proccessor::toUpper(m_expression);
	calculate();
}

const double Formula::operator+(const Type& other) const
{
	return m_value + other.getValue();
}

const double Formula::operator-(const Type& other) const
{
	return m_value - other.getValue();
}

const double Formula::operator*(const Type& other) const
{
	return m_value * other.getValue();
}

const double Formula::operator/(const Type& other) const
{
	if (other.getValue() == 0)
	{
		throw std::invalid_argument("Cannot divide by 0!");
	}
	return m_value / other.getValue();
}

const double Formula::operator^(const Type& other) const
{
	return pow(m_value, other.getValue());
}

void Formula::calculate()
{
	string expression = m_expression;
	double result = 0;

	Proccessor::processFormula(expression);

	splitFormula(expression);

	if (adjacentNumbers())
	{
		throw std::invalid_argument("Invalid formula!");
	}

	if (!countAritmeticSigns())
	{
		throw std::invalid_argument("Invalid formula!");
	}

	processAll();

	if (m_arguments.size() == 1)
	{
		String s(m_arguments[0]);
		Type* oper = &s;

		if (Proccessor::isAddress(m_arguments[0]))
		{
			size_t row1 = 0, col1 = 0;
			Proccessor::getPosition(m_arguments[0], row1, col1);
			oper = m_table->at(row1 - 1, col1 - 1);
		}

		if (!oper)
			m_value = 0;
		else
			m_value = oper->getValue();

		m_arguments.pop_back();
		return;
	}

	calculatePowers(result);

	calculateProductsAndDivisions(result);

	calculateSumsAndSubtractions(result);

	m_value = result;
	m_arguments.clear();
}

void Formula::splitFormula(const string& expression)
{
	int currInd = 0;
	for (size_t i = 0; i < expression.size(); i++)
	{
		while (expression[i] == ' ')
		{
			i++;
		}
		currInd = i;
		while (expression[i] != ' ' && i < expression.size())
		{
			i++;
		}
		m_arguments.push_back(expression.substr(currInd, i - currInd));
		currInd = i + 1;
	}
}

bool Formula::countAritmeticSigns()
{
	size_t signs = 0, nums = 0, equals = 0;
	for (size_t i = 0; i < m_arguments.size(); i++)
	{
		if (Proccessor::isAritmeticSign(m_arguments[i]))
			signs++;
		else if (m_arguments[i] == "=")
			equals++;
		else
			nums++;
	}
	return nums > signs && equals == 0;
}

void Formula::processAll()
{
	for (size_t i = 0; i < m_arguments.size(); i++)
	{
		Proccessor::processString(m_arguments[i]);
	}
}

bool Formula::adjacentNumbers()
{
	for (size_t i = 0; i < m_arguments.size(); i++)
	{
		if (i + 1 < m_arguments.size())
		{
			if ((Proccessor::isInteger(m_arguments[i]) || Proccessor::isDouble(m_arguments[i]) || Proccessor::isAddress(m_arguments[i]))
				&& (Proccessor::isInteger(m_arguments[i + 1]) || Proccessor::isDouble(m_arguments[i + 1])
					|| Proccessor::isAddress(m_arguments[i + 1])))
			{
				return true;
			}
		}
	}

	return false;
}

void Formula::calculatePowers(double& result)
{
	for (size_t i = 0; i < m_arguments.size(); i++)
	{
		if (m_arguments[i] == "^")
		{
			String s1(m_arguments[i - 1]);
			Type* lhs = &s1;
			String s2(m_arguments[i + 1]);
			Type* rhs = &s2;

			if (Proccessor::isAddress(m_arguments[i - 1]))
			{
				size_t row1 = 0, col1 = 0;
				Proccessor::getPosition(m_arguments[i - 1], row1, col1);
				lhs = m_table->at(row1 - 1, col1 - 1);
			}

			if (Proccessor::isAddress(m_arguments[i + 1]))
			{
				size_t row2 = 0, col2 = 0;
				Proccessor::getPosition(m_arguments[i + 1], row2, col2);
				rhs = m_table->at(row2 - 1, col2 - 1);
			}

			if (!lhs)
			{
				s1 = "0";
				lhs = &s1;
			}
			if (!rhs)
			{
				s2 = "0";
				rhs = &s2;
			}

			result = lhs->operator^(*rhs);

			m_arguments.erase(m_arguments.begin() + i + 1);
			m_arguments.erase(m_arguments.begin() + i);
			i--;

			m_arguments[i] = std::to_string(result);
		}
	}
}

void Formula::calculateProductsAndDivisions(double& result)
{
	for (size_t i = 0; i < m_arguments.size(); i++)
	{
		if (m_arguments[i] == "*")
		{
			String s1(m_arguments[i - 1]);
			Type* lhs = &s1;
			String s2(m_arguments[i + 1]);
			Type* rhs = &s2;

			if (Proccessor::isAddress(m_arguments[i - 1]))
			{
				size_t row1 = 0, col1 = 0;
				Proccessor::getPosition(m_arguments[i - 1], row1, col1);
				lhs = m_table->at(row1 - 1, col1 - 1);
			}

			if (Proccessor::isAddress(m_arguments[i + 1]))
			{
				size_t row2 = 0, col2 = 0;
				Proccessor::getPosition(m_arguments[i + 1], row2, col2);
				rhs = m_table->at(row2 - 1, col2 - 1);
			}

			if (!lhs)
			{
				s1 = "0";
				lhs = &s1;
			}
			if (!rhs)
			{
				s2 = "0";
				rhs = &s2;
			}

			result = lhs->operator*(*rhs);

			m_arguments.erase(m_arguments.begin() + i + 1);
			m_arguments.erase(m_arguments.begin() + i);
			i--;

			m_arguments[i] = std::to_string(result);
		}
		else if (m_arguments[i] == "/")
		{
			String s1(m_arguments[i - 1]);
			Type* lhs = &s1;
			String s2(m_arguments[i + 1]);
			Type* rhs = &s2;

			if (Proccessor::isAddress(m_arguments[i - 1]))
			{
				size_t row1 = 0, col1 = 0;
				Proccessor::getPosition(m_arguments[i - 1], row1, col1);
				lhs = m_table->at(row1 - 1, col1 - 1);
			}

			if (Proccessor::isAddress(m_arguments[i + 1]))
			{
				size_t row2 = 0, col2 = 0;
				Proccessor::getPosition(m_arguments[i + 1], row2, col2);
				rhs = m_table->at(row2 - 1, col2 - 1);
			}

			if (!lhs)
			{
				s1 = "0";
				lhs = &s1;
			}
			if (!rhs)
			{
				s2 = "0";
				rhs = &s2;
			}

			result = lhs->operator/(*rhs);

			m_arguments.erase(m_arguments.begin() + i + 1);
			m_arguments.erase(m_arguments.begin() + i);
			i--;

			m_arguments[i] = std::to_string(result);
		}
	}
}

void Formula::calculateSumsAndSubtractions(double& result)
{
	for (size_t i = 0; i < m_arguments.size(); i++)
	{
		if (m_arguments[i] == "+")
		{
			String s1(m_arguments[i - 1]);
			Type* lhs = &s1;
			String s2(m_arguments[i + 1]);
			Type* rhs = &s2;

			if (Proccessor::isAddress(m_arguments[i - 1]))
			{
				size_t row1 = 0, col1 = 0;
				Proccessor::getPosition(m_arguments[i - 1], row1, col1);
				lhs = m_table->at(row1 - 1, col1 - 1);
			}

			if (Proccessor::isAddress(m_arguments[i + 1]))
			{
				size_t row2 = 0, col2 = 0;
				Proccessor::getPosition(m_arguments[i + 1], row2, col2);
				rhs = m_table->at(row2 - 1, col2 - 1);
			}

			if (!lhs)
			{
				s1 = "0";
				lhs = &s1;
			}
			if (!rhs)
			{
				s2 = "0";
				rhs = &s2;
			}

			result = lhs->operator+(*rhs);

			m_arguments.erase(m_arguments.begin() + i + 1);
			m_arguments.erase(m_arguments.begin() + i);
			i--;

			m_arguments[i] = std::to_string(result);
		}
		else if (m_arguments[i] == "-")
		{
			String s1(m_arguments[i - 1]);
			Type* lhs = &s1;
			String s2(m_arguments[i + 1]);
			Type* rhs = &s2;

			if (Proccessor::isAddress(m_arguments[i - 1]))
			{
				size_t row1 = 0, col1 = 0;
				Proccessor::getPosition(m_arguments[i - 1], row1, col1);
				lhs = m_table->at(row1 - 1, col1 - 1);
			}

			if (Proccessor::isAddress(m_arguments[i + 1]))
			{
				size_t row2 = 0, col2 = 0;
				Proccessor::getPosition(m_arguments[i + 1], row2, col2);
				rhs = m_table->at(row2 - 1, col2 - 1);
			}

			if (!lhs)
			{
				s1 = "0";
				lhs = &s1;
			}
			if (!rhs)
			{
				s2 = "0";
				rhs = &s2;
			}

			result = lhs->operator-(*rhs);

			m_arguments.erase(m_arguments.begin() + i + 1);
			m_arguments.erase(m_arguments.begin() + i);
			i--;

			m_arguments[i] = std::to_string(result);
		}
	}
}

void Formula::print() const
{
	std::cout << std::to_string(m_value);
}

size_t Formula::getSize() const
{
	return std::to_string(m_value).size();
}

double Formula::getValue() const
{
	return m_value;
}

string Formula::toString() const
{
	return m_expression;
}