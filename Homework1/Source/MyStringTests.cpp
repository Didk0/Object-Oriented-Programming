#define CATCH_CONFIG_MAIN 
#include<cassert>
#include "catch.hpp"
#include"MyString.h"

TEST_CASE("MyString Constructor", "[MyString]")
{
	SECTION("MyString_GivenMyStringObject_Created")
	{
		//Arrange
		MyString str("String");
		size_t strLen = str.size();
		bool areDifferent = false;

		//Act
		areDifferent = strcmp(str.getName(), "String");

		//Assert
		REQUIRE(areDifferent == false);
	}
}

TEST_CASE("MyString Copy constructor", "[MyString]")
{
	SECTION("MyString_GivenMyStringObject_ProperlyCopied)") {
		//Arrange
		MyString str1("String");
		MyString str2(str1);
		bool areDifferent = false;

		//Act
		areDifferent = strcmp(str1.getName(), str2.getName());

		//Assert
		REQUIRE(areDifferent == false);
	}
	SECTION("MyString_GivenMyStringObject_HaveEqualLengths") {
		//Arrange
		MyString str1("Hello");
		MyString str2(str1);

		//Act
		bool areEqual = str1.size() == str2.size();

		//Assert
		REQUIRE(areEqual == true);
	}
}

TEST_CASE("MyString operator=", "[operator=]")
{
	SECTION("operator=_GivenMyStringObject_AreTheSame)") {
		//Arrange
		MyString str1("String");
		MyString str2 = str1;
		bool areDifferent = false;

		//Act
		areDifferent = strcmp(str1.getName(), str2.getName());

		//Assert
		REQUIRE(areDifferent == false);
	}
	SECTION("operator=_GivenMyStringObject_HaveEqualLengths") {
		//Arrange
		MyString str1("String");
		MyString str2 = str1;

		//Act
		bool areEqual = str1.size() == str2.size();

		//Assert
		REQUIRE(areEqual == true);
	}
}

TEST_CASE("Move constructor", "[MyString]")
{
	// TODO
}

TEST_CASE("MyString class function", "[MyString]")
{
	SECTION("MyString_GivenMyStringObject_ProperlyCopiedConstChar*)") {
		//Arrange
		const char* str2 = "String";
		MyString str1(str2);
		bool areDifferent = false;

		//Act
		areDifferent = strcmp(str1.getName(), str2);

		//Assert
		REQUIRE(areDifferent == false);
	}
	SECTION("MyString_GivenMyStringObject_HaveEqualLengths") {
		//Arrange
		const char* str2 = "String";
		MyString str1(str2);
		size_t str2Len = strlen(str2);

		//Act
		bool areEqual = str1.size() == str2Len;

		//Assert
		REQUIRE(areEqual == true);
	}
}

TEST_CASE("MyString at class method", "[at]")
{
	SECTION("at_GivenINVALIDIndex_ShouldThrow")
	{
		//Arrange
		MyString str("String");

		//Assert
		REQUIRE_THROWS_AS(str.at(6), std::out_of_range);
	}
	SECTION("at_GivenVALIDIndex")
	{
		//Arrange
		MyString str("String");

		//Assert
		REQUIRE(str.at(1) == 't');
	}
}

TEST_CASE("MyString const at class method", "[at]")
{
	SECTION("at_GivenINVALIDIndex_ShouldThrow")
	{
		//Arrange
		const MyString str("String");

		//Assert
		REQUIRE_THROWS_AS(str.at(6), std::out_of_range);
	}
	SECTION("at_GivenVALIDIndex")
	{
		//Arrange
		const MyString str("String");

		//Assert
		REQUIRE(str.at(1) == 't');
	}
}

TEST_CASE("MyString operator[]", "[operator[]]")
{
	SECTION("operator[]_GivenVALIDIndex")
	{
		//Arrange
		MyString str("String");

		//Assert
		REQUIRE(str[1] == 't');
	}
}

TEST_CASE("MyString const operator[]", "[operator[]]")
{
	SECTION("operator[]_GivenVALIDIndex")
	{
		//Arrange
		MyString str("String");

		//Assert
		REQUIRE(str[1] == 't');
	}
}

TEST_CASE("front class method", "[front]")
{
	SECTION("front_ReturnsCorrectSymbol")
	{
		//Arrange
		MyString str("String");

		//Assert
		REQUIRE(str.front() == 'S');
	}
}

TEST_CASE("const front class method", "[front]")
{
	SECTION("front_ReturnsCorrectSymbol")
	{
		//Arrange
		const MyString str("String");

		//Assert
		REQUIRE(str.front() == 'S');
	}
}

TEST_CASE("back class method", "[back]")
{
	SECTION("back_ReturnsCorrectSymbol")
	{
		//Arrange
		MyString str("String");

		//Assert
		REQUIRE(str.back() == 'g');
	}
}

TEST_CASE("const back class method", "[back]")
{
	SECTION("back_ReturnsCorrectSymbol")
	{
		//Arrange
		MyString str("String");

		//Assert
		REQUIRE(str.back() == 'g');
	}
}

TEST_CASE("MyString empty class method", "[empty]")
{
	SECTION("empty_GivenEmptyString")
	{
		//Arrange
		MyString str("");

		//Assert
		REQUIRE(str.empty() == true);
	}
	SECTION("empty_GivenEmptyString_HasZeroLength")
	{
		//Arrange
		MyString str("");

		//Assert
		REQUIRE(str.size() == 0);
	}
}

TEST_CASE("MyString size class method", "[size]")
{
	SECTION("size_GivenString")
	{
		//Arrange
		MyString str("String");

		//Assert
		REQUIRE(str.size() == 6);
	}
}

TEST_CASE("MyString clear class method", "[clear]")
{
	SECTION("clear_GivenString_IsEmpty")
	{
		//Arrange
		MyString str("String");

		//Act
		str.clear();

		//Assert
		REQUIRE(str.empty() == true);
	}
	SECTION("clear_GivenString_HasZeroLength")
	{
		//Arrange
		MyString str("String");

		//Act
		str.clear();

		//Assert
		REQUIRE(str.size() == 0);
	}
	SECTION("clear_GivenString_IsFirstSymbolZero")
	{
		//Arrange
		MyString str("String");

		//Act
		str.clear();

		//Assert
		REQUIRE(str.front() == '\0');
	}
}

TEST_CASE("push_back class method", "[push_back]")
{
	SECTION("push_back_GivenMyString_AddsElementProperly")
	{
		//Arrange
		MyString str("String");

		//Act
		str.push_back('s');

		//Assert
		REQUIRE(str.back() == 's');
	}
}

TEST_CASE("pop_back class method", "[pop_back]")
{
	SECTION("pop_back_GivenMyString_RemovesElementProperly")
	{
		//Arrange
		MyString str("String");

		//Act
		str.pop_back();

		//Assert
		REQUIRE(str.back() == 'n');
	}
}

TEST_CASE("operator+=(char)", "[operator+=]")
{
	SECTION("operator+=_GivenMyString_AddsElementProperly")
	{
		//Arrange
		MyString str("String");

		//Act
		str += 's';

		//Assert
		REQUIRE(str.back() == 's');
	}
}

TEST_CASE("operator+=(MyString)", "[operator+=]")
{
	SECTION("operator+=_GivenMyString_AddsMyStringProperly")
	{
		//Arrange
		MyString str1("The");
		const MyString str2("String");

		//Act
		str1 += str2;

		//Assert
		REQUIRE(str1.back() == 'g');
	}
	SECTION("operator+=_GivenMyString_HasCombinedLength")
	{
		//Arrange
		MyString str1("The");
		const MyString str2("String");

		//Act
		str1 += str2;

		//Assert
		REQUIRE(str1.size() == 9);
	}
}

TEST_CASE("operator+(char)", "[operator+]")
{
	SECTION("operator+_GivenMyString_AddsSymbolProperly")
	{
		//Arrange
		MyString str1("String");
		MyString str2;

		//Act
		str2 = str1 + 's';

		//Assert
		REQUIRE(str2.back() == 's');
	}
	SECTION("operator+_GivenMyString_Doesn'tChangeOldObject")
	{
		//Arrange
		MyString str1("String");
		MyString str2;

		//Act
		str2 = str1 + 's';

		//Assert
		REQUIRE(str1.back() == 'g');
	}
}

TEST_CASE("operator+(MyString)", "[operator+]")
{
	SECTION("operator+_GivenMyString_AddsMyStringProperly")
	{
		//Arrange
		MyString str1("String");
		MyString str2;

		//Act
		str2 = str1 + 's';

		//Assert
		REQUIRE(str2.back() == 's');
	}
	SECTION("operator+_GivenMyString_Doesn'tChangeOldObject")
	{
		//Arrange
		MyString str1("String");
		MyString str2;

		//Act
		str2 = str1 + 's';

		//Assert
		REQUIRE(str1.back() == 'g');
	}
}

TEST_CASE("c_str class method", "[c_str]")
{
	SECTION("c_str_GivenMyString_ReturnsNullTerminatedCharArray")
	{
		//Arrange
		MyString str1("String");

		//Act
		const char* str2 = str1.c_str();
		bool areDifferent = strcmp(str1.getName(), str2);

		//Assert
		REQUIRE(areDifferent == false);
	}
	SECTION("c_str_GivenMyString_ReturnsEmptyMyString")
	{
		//Arrange
		MyString str1;
		str1.clear();

		//Act
		const char* str2 = str1.c_str();

		//Assert
		REQUIRE(*str2 == '\0');
	}
	SECTION("c_str_GivenMyString_ReturnsNullptr")
	{
		//Arrange
		MyString str1;
		str1.~MyString();

		//Act
		const char* str2 = str1.c_str();

		//Assert
		REQUIRE(str2 == nullptr);
	}
}

TEST_CASE("operator==", "[operator==]")
{
	SECTION("operator==_GivenMyStringObject_AreTheSame)") {
		//Arrange
		MyString str1("String");
		MyString str2(str1);

		//Act
		bool areTheSame = str1 == str2;

		//Assert
		REQUIRE(areTheSame == true);
	}
}

TEST_CASE("operator<", "[operator<]")
{
	SECTION("operator<_GivenMyStringObject_IsSmaller)") {
		//Arrange
		MyString str1("String");
		MyString str2("Word");

		//Act
		bool areDifferent = str1 < str2;

		//Assert
		REQUIRE(areDifferent == true);
	}
}

TEST_CASE("getName class method", "[getName]")
{
	SECTION("getName_GivenMyStringObject_ReturnsMyString")
	{
		//Arrange
		MyString str("String");

		//Act
		bool areDifferent = strcmp(str.getName(), "String");

		//Assert
		REQUIRE(areDifferent == false);
	}
}