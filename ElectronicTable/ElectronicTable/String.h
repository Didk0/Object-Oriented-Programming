#pragma once
#include <string>
#include <iostream>
#include "Type.h"
#include "Proccessor.h"

class String : public Type
{
public:
	/// @brief Constructor
	/// @param value - the value of the object
	String(const string& value);

	/// @brief Copy assignment operator
	/// @param str - the new value 
	/// @return *this
	String& operator=(const string& str);

	/// @brief adds String to Type object
	/// @param other - the other add
	/// @return result of the addition
	virtual const double operator+(const Type& other) const override;

	/// @brief subtracts Type from String object
	/// @param other - the other to subtract
	/// @return result of the subtraction
	virtual const double operator-(const Type& other) const override;

	/// @brief multiplies String to Type object
	/// @param other - the other to multiply
	/// @return result of the multiplication
	virtual const double operator*(const Type& other) const override;

	/// @brief divides String by Type object
	/// @param other - the other to divide
	/// @return result of the division
	virtual const double operator/(const Type& other) const override;

	/// @brief powers up a String object by the value of the Type object
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

	/// @brief gives the value as string
	/// @return value to string
	virtual string toString() const override;

private:
	string m_value;
};

