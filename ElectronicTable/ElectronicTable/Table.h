#pragma once
#include <vector>
#include <iostream>
#include "Type.h"

using table = std::vector<std::vector<Type*>>;

class Table
{
public:
	/// @brief Constructor
	Table();

	/// @brief Copy Constructor, deleted
	/// @param other - Table to assign
	Table(const Table& other) = delete;

	/// @brief Copy Assignment operator, deleted
	/// @param other - Table to assign
	/// @return *this
	Table& operator=(const Table& other) = delete;

	/// @brief gives the rows of the table
	/// @return rows
	inline size_t rowsCount() const { return m_table.size(); };

	/// @brief gives the columns of the table
	/// @return columns
	inline size_t colsCount() const { return m_table.size() == 0 ? 0 : m_table[0].size(); };

	/// @brief gives pointer to the object at given position
	/// @param row - row in the table
	/// @param col - column in the table
	/// @return pointer to the object
	Type* at(size_t row, size_t col) const;

	/// @brief clears the allocated memory
	void clear();

	/// @brief sets a new object to the table at given position
	/// @param t - pointer to the object
	/// @param row - row to set in the table
	/// @param col - column to set in the table
	void edit(Type* t, size_t row, size_t col);

	/// @brief aligns the table and prints it
	void print();

private:
	/// @brief expands the rows of the table
	/// @param row - the new count of the rows
	void resizeRows(size_t row);

	/// @brief expands the columns of the table
	/// @param col - the new count of the columns
	void resizeCols(size_t col);

	/// @brief finds the lognest value of an object in every column and sets it to m_colsLongestLengths
	void fillLengths();

	table m_table;
	std::vector<size_t> m_colsLongestLengths;
};

