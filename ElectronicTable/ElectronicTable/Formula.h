#pragma once
#include <vector>
#include <iostream>
#include "Proccessor.h"
#include "String.h"
#include "Table.h"

class Formula : public Type
{
public:
	/// @brief Constructor
	/// @param expression - the raw look of the formula as expression
	/// @param table - pointer to a Table
	Formula(const string& expression, const Table* table);
	
	/// @brief adds Formula to Type object
	/// @param other - the other add
	/// @return result of the addition
	virtual const double operator+(const Type& other) const override;

	/// @brief subtracts Type from Formula object
	/// @param other - the other to subtract
	/// @return result of the subtraction
	virtual const double operator-(const Type& other) const override;

	/// @brief multiplies Formula to Type object
	/// @param other - the other to multiply
	/// @return result of the multiplication
	virtual const double operator*(const Type& other) const override;

	/// @brief divides Formula by Type object
	/// @param other - the other to divide
	/// @return result of the division
	virtual const double operator/(const Type& other) const override;

	/// @brief powers up a Formula object by the value of the Type object
	/// @param other - object for the power up
	/// @return powered Integer
	virtual const double operator^(const Type& other) const override;

	/// @brief prints the value
	virtual void print() const override;

	/// @brief gives the size of the value as string
	/// @return size
	virtual size_t getSize() const override;

	/// @brief gives the value
	/// @return value
	virtual double getValue() const override;

	/// @brief gives the raw look of the expression
	/// @return value to string
	virtual string toString() const override;

	/// @brief calculates the expression and sets the result to m_value
	void calculate();

private:
	/// @brief splits the expression to tokens and sets them to m_arguments
	/// @param expression - the raw expression 
	void splitFormula(const string& expression);

	/// @brief counts the aritmetic operators
	/// @return if they are less than the operands returns true, otherwise - false 
	bool countAritmeticSigns();

	/// @brief removes the quotes of every argument
	void processAll();

	/// @brief checks if there are adjacent numbers
	/// @return if there are adjacent numbers returns true, otherwise - false
	bool adjacentNumbers();

	/// @brief executes the powers
	/// @param result - the result after the powers
	void calculatePowers(double& result);

	/// @brief executes the multiplications and the divisions
	/// @param result - the result after the multiplications and the divisions
	void calculateProductsAndDivisions(double& result);

	/// @brief executes the sums and the subtractions
	/// @param result - the result after the sums and the subtractions 
	void calculateSumsAndSubtractions(double& result);

	double m_value;
	string m_expression;
	std::vector<std::string> m_arguments;
	const Table* m_table = nullptr;
};

