#include "Table.h"

using std::cout;
using std::endl;

Table::Table()
{}

Type* Table::at(size_t row, size_t col) const
{
	if (row >= rowsCount() || col >= colsCount())
	{
		return nullptr;
	}

	return m_table[row][col];
}

void Table::clear()
{
	for (size_t i = 0; i < m_table.size(); i++)
	{
		for (size_t j = 0; j < m_table[i].size(); j++)
		{
			delete m_table[i][j];
			m_table[i][j] = nullptr;
		}
	}
	m_table.clear();
}

void Table::edit(Type* t, size_t row, size_t col)
{
	if (col > 26)
		throw std::invalid_argument("Invalid column!");

	if (row > m_table.size())
		resizeRows(row);

	if (col > m_table[0].size())
		resizeCols(col);

	delete m_table[row - 1][col - 1];
	m_table[row - 1][col - 1] = t;
}

void Table::print()
{
	if (m_table.size() > 0)
	{
		fillLengths();
		cout << "  ";
		for (size_t i = 0; i < m_table[0].size(); i++)
		{
			cout << "| " << (char)(i + 65);
			for (size_t j = 0; j < m_colsLongestLengths[i]; j++)
				cout << ' ';
		}
		cout << "|" << endl;

		for (size_t i = 0; i < m_table.size(); i++)
		{
			cout << i + 1 << " |";
			for (size_t j = 0; j < m_table[i].size(); j++)
			{
				size_t currSize;
				if (!m_table[i][j])
					currSize = 0;
				else
					currSize = m_table[i][j]->getSize();

				for (size_t k = 0; k < m_colsLongestLengths[j] - currSize; k++)
					cout << ' ';
				if (m_table[i][j])
				{
					cout << " ";
					m_table[i][j]->print();
				}
				else
					cout << " ";
				cout << " |";
			}
			cout << endl;
		}
	}
}

void Table::resizeRows(size_t row)
{
	if (row > m_table.size())
	{
		m_table.reserve(row);

		for (size_t i = m_table.size(); i < row; i++)
		{
			m_table.push_back(std::vector<Type*>());
			for (size_t j = 0; j < m_table[0].size(); j++)
				m_table[i].push_back(nullptr);
		}
	}
}

void Table::resizeCols(size_t col)
{
	if (col > m_table[0].size())
	{
		for (size_t i = 0; i < m_table.size(); i++)
		{
			m_table[i].reserve(col);
			for (size_t j = m_table[i].size(); j < col; j++)
				m_table[i].push_back(nullptr);
		}
	}
}

void Table::fillLengths()
{
	m_colsLongestLengths.clear();
	size_t numOfCols = m_table[0].size();
	for (size_t i = 0; i < numOfCols; i++)
	{
		int colMaxLen = 0;
		int currLen = 0;
		for (size_t j = 0; j < m_table.size(); j++)
		{
			currLen = 0;
			if (!m_table[j][i])
			{
				continue;
			}
			else
			{
				currLen = m_table[j][i]->getSize();
			}

			if (currLen >= colMaxLen)
			{
				colMaxLen = currLen;
			}
		}
		m_colsLongestLengths.push_back(colMaxLen);
	}
}
