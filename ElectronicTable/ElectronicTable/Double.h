#pragma once
#include<iostream>
#include "Type.h"

class Double : public Type
{
public:
	/// @brief Constructor
	/// @param value - the value of the object
	Double(const string& value);

	/// @brief adds Double to Type object
	/// @param other - the other add
	/// @return result of the addition
	virtual const double operator+(const Type& other) const override;

	/// @brief subtracts Type from Double object
	/// @param other - the other to subtract
	/// @return result of the subtraction
	virtual const double operator-(const Type& other) const override;

	/// @brief multiplies Double to Type object
	/// @param other - the other to multiply
	/// @return result of the multiplication
	virtual const double operator*(const Type& other) const override;

	/// @brief divides Double by Type object
	/// @param other - the other to divide
	/// @return result of the division
	virtual const double operator/(const Type& other) const override;

	/// @brief powers up a Double object by the value of the Type object
	/// @param other - object for the power up
	/// @return powered Double
	virtual const double operator^(const Type& other) const override;

	/// @brief prints the value
	virtual void print() const override;

	/// @brief gives the size of the value as string
	/// @return size
	virtual size_t getSize() const override;

	/// @brief gives the value
	/// @return value
	virtual double getValue() const override;

	/// @brief gives the value as string
	/// @return value to string
	virtual string toString() const override;

private:	
	double m_value;
};

