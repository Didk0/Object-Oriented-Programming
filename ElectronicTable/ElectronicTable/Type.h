#pragma once
#include <string>

using std::string;

class Type
{
public:

	/// @brief prints the value
	virtual void print() const = 0;

	/// @brief gives the size of the value as string
	/// @return size
	virtual size_t getSize() const = 0;

	/// @brief gives the value
	/// @return value
	virtual double getValue() const = 0;

	/// @brief gives the value as string
	/// @return value to string
	virtual string toString() const = 0;

	/// @brief adds two Type objects
	/// @param other - the other add
	/// @return result of the addition
	virtual const double operator+(const Type& other) const;

	/// @brief subtracts two Type objects
	/// @param other - the other to subtract
	/// @return result of the subtraction
	virtual const double operator-(const Type& other) const;

	/// @brief multiplies two Type objects
	/// @param other - the other to multiply
	/// @return result of the multiplication
	virtual const double operator*(const Type& other) const;

	/// @brief divides two Type objects
	/// @param other - the other to divide
	/// @return result of the division
	virtual const double operator/(const Type& other) const;

	/// @brief powers up an Type object by the value of the other
	/// @param other - object for the power up
	/// @return powered Type object
	virtual const double operator^(const Type& other) const = 0;
};

