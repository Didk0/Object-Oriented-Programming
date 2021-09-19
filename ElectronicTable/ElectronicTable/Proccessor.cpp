#include "Proccessor.h"

Proccessor::Proccessor()
{}

bool Proccessor::isInteger(const string& str)
{
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		i = 1;
		if (str.size() - 1 == 0)
			return false;
	}

	for (i; i < str.size(); i++)
	{
		if (!isNumber(str[i]))
		{
			return false;
		}
	}
	return true;
}

bool Proccessor::isDouble(const string& str)
{
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		i = 1;
		if (str.size() - 1 == 0)
			return false;
	}

	size_t dotsCnt = 0;
	for (i; i < str.size(); i++)
	{
		if (str[i] == '.')
			dotsCnt++;
		else
			if (!isNumber(str[i]))
				return false;
	}
	if (dotsCnt != 1)
		return false;

	return true;
}

bool Proccessor::isString(const string& str)
{
	if (str[0] == '\"' && str[str.size() - 1] == '\"')
	{
		return true;
	}
	return false;
}

bool Proccessor::isFormula(const string& str)
{
	return str[0] == '=';
}

void Proccessor::process(const string& cmd, tokens& tokens)
{
	tokens.clear();
	int currInd = 0;

	for (size_t i = 0; i < cmd.size(); i++)
	{
		while (cmd[i] == ' ')
		{
			i++;
			currInd++;
		}

		if (cmd[i] != '"')
		{
			while (cmd[i] != ' ' && i < cmd.size())
			{
				i++;
			}
			tokens.push_back(cmd.substr(currInd, i - currInd));
			currInd = i + 1;
		}
		else
		{
			while (i < cmd.size())
			{
				i++;
			}
			tokens.push_back(cmd.substr(currInd, i - currInd + 1));
		}
	}

	if (tokens.size() > 3)
	{
		throw std::invalid_argument("Invalid command!");
	}
}

void Proccessor::processString(string& str)
{
	if (str[0] == '\"' && str.back() == '\"')
		str = str.substr(1, str.size() - 2);
}

void Proccessor::getPosition(const string& cell, size_t& row, size_t& col)
{
	string res = std::to_string((int)cell[0] - 64);
	col = std::atol(res.c_str());
	row = std::atol(cell.substr(1, cell.size() - 1).c_str());
}

void Proccessor::processFormula(string& str)
{
	str = str.substr(1, str.size() - 1);
}

void Proccessor::updateFormulas(Table& table)
{
	for (size_t i = 0; i < table.rowsCount(); i++)
	{
		for (size_t j = 0; j < table.colsCount(); j++)
		{
			if (table.at(i,j) && Proccessor::isFormula(table.at(i,j)->toString()))
			{
				Formula* f = static_cast<Formula*>(table.at(i, j));
				f->calculate();
			}
		}
	}
}

bool Proccessor::isAddress(const string& str)
{
	if (!isUpperCase(str[0]))
		return false;

	if (!isInteger(str.substr(1, str.size())))
		return false;

	return true;
}

void Proccessor::toUpper(string& str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (isLowerCase(str[i]))
			str[i] -= 'a' - 'A';
}

void Proccessor::splitByComma(const string& str, tokens& tokens)
{
	tokens.clear();

	size_t currInd = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		while (str[i] == ' ' && i < str.size())
		{
			i++;
		}
		currInd = i;

		while (str[i] != ',' && i < str.size())
		{
			i++;
		}
		tokens.push_back(str.substr(currInd, i - currInd));
	}
}

void Proccessor::putWhiteSpaces(string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		char c = str[i];
		string curr = "";
		curr.push_back(c);
		if (isAritmeticSign(curr))
		{
			if (str[i - 1] != ' ')
			{
				str.insert(i, " ");
				i++;
			}
			if (str[i + 1] != ' ')
			{
				str.insert(i + 1, " ");
				i++;
			}
		}
	}
}
