#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Table.h"
#include "Formula.h"

using std::string;
using tokens = std::vector<string>;

class Proccessor
{
public:
	Proccessor(const Proccessor& other) = delete;
	Proccessor& operator=(const Proccessor& other) = delete;
	~Proccessor() = delete;

	/// @brief checks if a given string can be an Integer
	/// @param str - value to check
	/// @return true if the string is correct Integer
	static bool isInteger(const string& str);

	/// @brief checks if a given string can be a Double
	/// @param str - value to check
	/// @return true if the string is correct Double
	static bool isDouble(const string& str);

	/// @brief checks if a given string can be a String
	/// @param str - value to check
	/// @return true if the string is correct String
	static bool isString(const string& str);

	/// @brief checks if a given string can be a Formula
	/// @param str - value to check
	/// @return true if the string is correct Formula (only checks if the formula starts with '=' here!)
	static bool isFormula(const string& str);

	/// @brief splits a given command to separate tokens
	/// @param cmd - the command to be split
	/// @param tokens - the tokens of the command
	static void process(const string& cmd, tokens& tokens);

	/// @brief removes the quotes of a string
	/// @param str - the string to be proccessed
	static void processString(string& str);

	/// @brief gets an adress of a cell in a table and transforms the letter to a column and the number to a row
	/// @param cell - given address
	/// @param row - the transformed row
	/// @param col - the transformed column
	static void getPosition(const string& cell, size_t& row, size_t& col);

	/// @brief removes the '=' from a Formula
	/// @param str - value of the Formula
	static void processFormula(string& str);

	/// @brief recalculates all formulas
	/// @param table - the table that contains the formulas
	static void updateFormulas(Table& table);

	/// @brief checks if a string is a valid address
	/// @param str - the given string
	/// @return if the string is an address returns true and false - otherwise
	static bool isAddress(const string& str);

	/// @brief sets all lower case letters to upper case ones
	/// @param str - string to be processed
	static void toUpper(string& str);

	/// @brief splits a string by commas
	/// @param str - the string to be splitted
	/// @param tokens - the splitted parts of the string
	static void splitByComma(const string& str, tokens& tokens);

	/// @brief puts white spaces between a character in string if the character is an aritmetic sign
	/// @param str - the string to be processed
	static void putWhiteSpaces(string& str);

	/// @brief checks if a character is a digit
	/// @param c - the given character
	/// @return if the character is a digit returns true, otherwise - false
	static inline bool isNumber(const char c) { return c >= '0' && c <= '9'; };

	/// @brief checks if a character is an upper case
	/// @param ch - the given character
	/// @return if the character is an upper case returns true, otherwise - false
	static inline bool isUpperCase(char ch) { return ch >= 'A' && ch <= 'Z'; };

	/// @brief checks if a character is a lower case
	/// @param ch - the given character
	/// @return if the character is a lower case returns true, otherwise - false
	static inline bool isLowerCase(char ch) { return ch >= 'a' && ch <= 'z'; };

	/// @brief checks if a string is an aritmetic sign
	/// @param str - the given string
	/// @return if the string is aritmetic sign returns true, otherwise - false
	static inline bool isAritmeticSign(const string& str) { return str == "+" || str == "-" || str == "*" || str == "/" || str == "^"; };

private:
	Proccessor();
};

