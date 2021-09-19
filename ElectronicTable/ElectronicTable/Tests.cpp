#define CATCH_CONFIG_MAIN 
#include <cassert>
#include "catch2.hpp"
#include "Integer.h"
#include "Double.h"
#include "String.h"
#include "Formula.h"
#include "Table.h"
#include "Proccessor.h"
#include "Document.h"

TEST_CASE("Integer Constructor", "[Integer]")
{
	SECTION("Integer_GivenValue_Creates")
	{
		Integer i("123");

		REQUIRE(i.getValue() == 123);
		REQUIRE(i.toString() == "123");
		REQUIRE(i.getSize() == 3);
	}
}

TEST_CASE("Integer operator+", "[operator+]")
{
	SECTION("operator+_GivenInteger_Adds")
	{
		Integer i1("123");
		Integer i2("2");

		double res = i1 + i2;

		REQUIRE(res == 125);
	}
	SECTION("operator+_GivenDouble_Adds")
	{
		Integer i("123");
		Double d("2.5");

		double res = i + d;

		REQUIRE(res == 125.5);
	}
	SECTION("operator+_GivenString_Adds")
	{
		Integer i("123");
		String s("2");

		double res = i + s;

		REQUIRE(res == 125);
	}
	SECTION("operator+_GivenFormula_Adds")
	{
		Integer i("123");
		Formula f("=5 + 5", nullptr);

		double res = i + f;

		REQUIRE(res == 133);
	}
}

TEST_CASE("Integer operator-", "[operator-]")
{
	SECTION("operator-_GivenInteger_Subtracts")
	{
		Integer i1("3");
		Integer i2("2");

		double res = i1 - i2;

		REQUIRE(res == 1);
	}
	SECTION("operator-_GivenDouble_Subtracts")
	{
		Integer i("3");
		Double d("2.5");

		double res = i - d;

		REQUIRE(res == 0.5);
	}
	SECTION("operator-_GivenString_Subtracts")
	{
		Integer i("3");
		String s("2");

		double res = i - s;

		REQUIRE(res == 1);
	}
	SECTION("operator-_GivenFormula_Subtracts")
	{
		Integer i("13");
		Formula f("=5 + 5", nullptr);

		double res = i - f;

		REQUIRE(res == 3);
	}
}

TEST_CASE("Integer operator*", "[operator*]")
{
	SECTION("operator*_GivenInteger_Multiplies")
	{
		Integer i1("3");
		Integer i2("2");

		double res = i1 * i2;

		REQUIRE(res == 6);
	}
	SECTION("operator*_GivenDouble_Multiplies")
	{
		Integer i("3");
		Double d("2.5");

		double res = i * d;

		REQUIRE(res == 7.5);
	}
	SECTION("operator*_GivenString_Multiplies")
	{
		Integer i("3");
		String s("2");

		double res = i * s;

		REQUIRE(res == 6);
	}
	SECTION("operator*_GivenFormula_Multiplies")
	{
		Integer i("3");
		Formula f("=5 + 5", nullptr);

		double res = i * f;

		REQUIRE(res == 30);
	}
}

TEST_CASE("Integer operator/", "[operator/]")
{
	SECTION("operator/_GivenInteger_Divides")
	{
		Integer i1("4");
		Integer i2("2");

		double res = i1 / i2;

		REQUIRE(res == 2);
	}
	SECTION("operator/_GivenDouble_Divides")
	{
		Integer i("4");
		Double d("2.5");

		double res = i / d;

		REQUIRE(res == 1.6);
	}
	SECTION("operator/_GivenString_Divides")
	{
		Integer i("4");
		String s("2");

		double res = i / s;

		REQUIRE(res == 2);
	}
	SECTION("operator/_GivenFormula_Divides")
	{
		Integer i("4");
		Formula f("=1 + 1", nullptr);

		double res = i / f;

		REQUIRE(res == 2);
	}
}

TEST_CASE("Integer getSize", "[getSize]")
{
	SECTION("getSize_ReturnsSize")
	{
		Integer i("1234");

		REQUIRE(i.getSize() == 4);
	}
}

TEST_CASE("Integer getValue", "[getValue]")
{
	SECTION("getValue_ReturnsValue")
	{
		Integer i("1234");

		REQUIRE(i.getValue() == 1234);
	}
}

TEST_CASE("Integer toString", "[toString]")
{
	SECTION("toString_ReturnsToString")
	{
		Integer i("1234");

		REQUIRE(i.toString() == "1234");
	}
}

TEST_CASE("Double Constructor", "[Double]")
{
	SECTION("Double_GivenValue_Creates")
	{
		Double d("5.6");

		REQUIRE(d.getValue() == 5.6);
		REQUIRE(d.toString() == "5.600000");
		REQUIRE(d.getSize() == 8);
	}
}

TEST_CASE("Double operator+", "[operator+]")
{
	SECTION("operator+_GivenDouble_Adds")
	{
		Double d1("2.5");
		Double d2("2.5");

		double res = d1 + d2;

		REQUIRE(res == 5);
	}
	SECTION("operator+_GivenInteger_Adds")
	{
		Double d("2.5");
		Integer i("2");

		double res = i + d;

		REQUIRE(res == 4.5);
	}
	SECTION("operator+_GivenString_Adds")
	{
		Double d("2.5");
		String s("2");

		double res = d + s;

		REQUIRE(res == 4.5);
	}
	SECTION("operator+_GivenFormula_Adds")
	{
		Double d("2.5");
		Formula f("=5 + 5", nullptr);

		double res = d + f;

		REQUIRE(res == 12.5);
	}
}

TEST_CASE("Double operator-", "[operator-]")
{
	SECTION("operator-_GivenDouble_Subtracts")
	{
		Double d1("3.5");
		Double d2("2.5");

		double res = d1 - d2;

		REQUIRE(res == 1);
	}
	SECTION("operator-_GivenInteger_Subtracts")
	{
		Integer i("3");
		Double d("2.5");

		double res = i - d;

		REQUIRE(res == 0.5);
	}
	SECTION("operator-_GivenString_Subtracts")
	{
		Double d("3.5");
		Integer s("2");

		double res = d - s;

		REQUIRE(res == 1.5);
	}
	SECTION("operator-_GivenFormula_Subtracts")
	{
		Double d("13.5");
		Formula f("=5 + 5", nullptr);

		double res = d - f;

		REQUIRE(res == 3.5);
	}
}

TEST_CASE("Double operator*", "[operator*]")
{
	SECTION("operator*_GivenDouble_Multiplies")
	{
		Double d1("1.5");
		Double d2("2.5");

		double res = d1 * d2;

		REQUIRE(res == 3.75);
	}
	SECTION("operator*_GivenInteger_Multiplies")
	{
		Integer i("3");
		Double d("2.5");

		double res = i * d;

		REQUIRE(res == 7.5);
	}
	SECTION("operator*_GivenString_Multiplies")
	{
		Double d("3.5");
		Integer s("2");

		double res = d * s;

		REQUIRE(res == 7);
	}
	SECTION("operator*_GivenFormula_Multiplies")
	{
		Double d("3.5");
		Formula f("=5 + 5", nullptr);

		double res = d * f;

		REQUIRE(res == 35);
	}
}

TEST_CASE("Double operator/", "[operator/]")
{
	SECTION("operator/_GivenDouble_Divides")
	{
		Double d1("0.12");
		Double d2("0.4");

		double res = d1 / d2;

		REQUIRE(res == 0.3);
	}
	SECTION("operator/_GivenInteger_Divides")
	{
		Double d("2.5");
		Integer i("2");

		double res = d / i;

		REQUIRE(res == 1.25);
	}
	SECTION("operator/_GivenString_Divides")
	{
		Double d("2.5");
		String s("2");

		double res = d / s;

		REQUIRE(res == 1.25);
	}
	SECTION("operator/_GivenFormula_Divides")
	{
		Double d("2.5");
		Formula f("=1 + 1", nullptr);

		double res = d / f;

		REQUIRE(res == 1.25);
	}
}

TEST_CASE("Double getSize", "[getSize]")
{
	SECTION("getSize_ReturnsSize")
	{
		Double d("2.5");

		REQUIRE(d.getSize() == 8);
	}
}

TEST_CASE("Double getValue", "[getValue]")
{
	SECTION("getValue_ReturnsValue")
	{
		Double d("2.5");

		REQUIRE(d.getValue() == 2.5);
	}
}

TEST_CASE("Double toString", "[toString]")
{
	SECTION("toString_ReturnsToString")
	{
		Double d("2.5");

		REQUIRE(d.toString() == "2.500000");
	}
}

TEST_CASE("String Constructor", "[String]")
{
	SECTION("String_GivenValue_Creates")
	{
		String s("ivan");

		REQUIRE(s.getValue() == 0);
		REQUIRE(s.toString() == "ivan");
		REQUIRE(s.getSize() == 4);
	}
}

TEST_CASE("String operator+", "[operator+]")
{
	SECTION("operator+_GivenString_Adds")
	{
		String s1("2");
		String s2("ivan");

		double res = s1 + s2;

		REQUIRE(res == 2);
	}
	SECTION("operator+_GivenInteger_Adds")
	{
		String s("2");
		Integer i("2");

		double res = i + s;

		REQUIRE(res == 4);
	}
	SECTION("operator+_GivenDouble_Adds")
	{
		String s("2");
		Double d("2.5");

		double res = d + s;

		REQUIRE(res == 4.5);
	}
	SECTION("operator+_GivenFormula_Adds")
	{
		String s("2");
		Formula f("=5 + 5", nullptr);

		double res = s + f;

		REQUIRE(res == 12);
	}
}

TEST_CASE("String operator-", "[operator-]")
{
	SECTION("operator-_GivenString_Subtracts")
	{
		String s1("3");
		String s2("2.5");

		double res = s1 - s2;

		REQUIRE(res == 0.5);
	}
	SECTION("operator-_GivenInteger_Subtracts")
	{
		String s("4");
		Integer i("3");

		double res = s - i;

		REQUIRE(res == 1);
	}
	SECTION("operator-_GivenDouble_Subtracts")
	{
		String s("4.5");
		Double d("3.5");

		double res = s - d;

		REQUIRE(res == 1);
	}
	SECTION("operator-_GivenFormula_Subtracts")
	{
		String s("13.5");
		Formula f("=5 + 5", nullptr);

		double res = s - f;

		REQUIRE(res == 3.5);
	}
}

TEST_CASE("String operator*", "[operator*]")
{
	SECTION("operator*_GivenString_Multiplies")
	{
		String s1("1");
		String s2("2");

		double res = s1 * s2;

		REQUIRE(res == 2);
	}
	SECTION("operator*_GivenInteger_Multiplies")
	{
		String s("3");
		Integer i("2");

		double res = s * i;

		REQUIRE(res == 6);
	}
	SECTION("operator*_GivenDouble_Multiplies")
	{
		Double d("3.5");
		String s("2");

		double res = s * d;

		REQUIRE(res == 7);
	}
	SECTION("operator*_GivenFormula_Multiplies")
	{
		String s("3");
		Formula f("=5 + 5", nullptr);

		double res = s * f;

		REQUIRE(res == 30);
	}
}

TEST_CASE("String operator/", "[operator/]")
{
	SECTION("operator/_GivenString_Divides")
	{
		String s1("6");
		String s2("3");

		double res = s1 / s2;

		REQUIRE(res == 2);
	}
	SECTION("operator/_GivenInteger_Divides")
	{
		String s("4");
		Integer i("2");

		double res = s / i;

		REQUIRE(res == 2);
	}
	SECTION("operator/_GivenDouble_Divides")
	{
		Double d("2.5");
		String s("5");

		double res = s / d;

		REQUIRE(res == 2);
	}
	SECTION("operator/_GivenFormula_Divides")
	{
		String s("2");
		Formula f("=1 + 1", nullptr);

		double res = s / f;

		REQUIRE(res == 1);
	}
}

TEST_CASE("String getSize", "[getSize]")
{
	SECTION("getSize_GivenNotNumber")
	{
		String s("ivan");

		REQUIRE(s.getSize() == 4);
	}
	SECTION("getSize_GivenInteger")
	{
		String s("123");

		REQUIRE(s.getSize() == 3);
	}
	SECTION("getSize_GivenDouble")
	{
		String s("2.5");

		REQUIRE(s.getSize() == 3);
	}
}

TEST_CASE("String getValue", "[getValue]")
{
	SECTION("getValue_GivenNotNumber")
	{
		String s("ivan");

		REQUIRE(s.getValue() == 0);
	}
	SECTION("getValue_GivenInteger")
	{
		String s("123");

		REQUIRE(s.getValue() == 123);
	}
	SECTION("getSize_GivenDouble")
	{
		String s("2.5");

		REQUIRE(s.getValue() == 2.5);
	}
}

TEST_CASE("String toString", "[toString]")
{
	SECTION("toString_ReturnsToString")
	{
		String s("ivan");

		REQUIRE(s.toString() == "ivan");
	}
}

TEST_CASE("Formula Constructor", "[Formula]")
{
	SECTION("Formula_GivenNumbers_Creates")
	{
		Formula f("=4 + 5", nullptr);

		REQUIRE(f.getValue() == 9);
		REQUIRE(f.toString() == "=4 + 5");
		REQUIRE(f.getSize() == 8);
	}
	SECTION("Formula_GivenAddesses_Creates")
	{
		Table t;
		Formula* f = new Formula("=a1 + 5", &t);
		t.edit(f, 1, 1);

		REQUIRE(f->getValue() == 5);
		REQUIRE(f->toString() == "=A1 + 5");
		REQUIRE(f->getSize() == 8);
		t.clear();
	}
}

TEST_CASE("Formula operator+", "[operator+]")
{
	SECTION("operator+_GivenFormula_Adds")
	{
		Formula f1("=5", nullptr);
		Formula f2("=ivan", nullptr);

		double res = f1 + f2;

		REQUIRE(res == 5);
	}
	SECTION("operator+_GivenInteger_Adds")
	{
		Formula f("=5", nullptr);
		Integer i("2");

		double res = f + i;

		REQUIRE(res == 7);
	}
	SECTION("operator+_GivenDouble_Adds")
	{
		Formula f("=5", nullptr);
		Double d("2.5");

		double res = d + f;

		REQUIRE(res == 7.5);
	}
	SECTION("operator+_GivenString_Adds")
	{
		Formula f("=5 + 5", nullptr);
		String s("2");

		double res = s + f;

		REQUIRE(res == 12);
	}
}

TEST_CASE("Formula operator-", "[operator-]")
{
	SECTION("operator-_GivenFormula_Subtracts")
	{
		Formula f1("=5", nullptr);
		Formula f2("=ivan", nullptr);

		double res = f1 - f2;

		REQUIRE(res == 5);
	}
	SECTION("operator-_GivenInteger_Subtracts")
	{
		Formula f("=5", nullptr);
		Integer i("2");

		double res = f - i;

		REQUIRE(res == 3);
	}
	SECTION("operator-_GivenDouble_Subtracts")
	{
		Formula f("=5", nullptr);
		Double d("2.5");

		double res = f - d;

		REQUIRE(res == 2.5);
	}
	SECTION("operator-_GivenString_Subtracts")
	{
		Formula f("=5 + 5", nullptr);
		String s("2");

		double res = f - s;

		REQUIRE(res == 8);
	}
}

TEST_CASE("Formula operator*", "[operator*]")
{
	SECTION("operator*_GivenFormula_Multiplies")
	{
		Formula f1("=5", nullptr);
		Formula f2("=ivan", nullptr);

		double res = f1 * f2;

		REQUIRE(res == 0);
	}
	SECTION("operator*_GivenInteger_Multiplies")
	{
		Formula f("=5", nullptr);
		Integer i("2");

		double res = f * i;

		REQUIRE(res == 10);
	}
	SECTION("operator*_GivenDouble_Multiplies")
	{
		Formula f("=5", nullptr);
		Double d("2.5");

		double res = f * d;

		REQUIRE(res == 12.5);
	}
	SECTION("operator*_GivenString_Multiplies")
	{
		Formula f("=5 + 5", nullptr);
		String s("2");

		double res = s * f;

		REQUIRE(res == 20);
	}
}

TEST_CASE("Formula operator/", "[operator/]")
{
	SECTION("operator/_GivenFormula_Divides")
	{
		Formula f1("=5", nullptr);
		Formula f2("=ivan", nullptr);

		double res = f2 / f1;

		REQUIRE(res == 0);
	}
	SECTION("operator/_GivenInteger_Divides")
	{
		Formula f("=5", nullptr);
		Integer i("2");

		double res = f / i;

		REQUIRE(res == 2.5);
	}
	SECTION("operator/_GivenDouble_Divides")
	{
		Formula f("=5", nullptr);
		Double d("2");

		double res = f / d;

		REQUIRE(res == 2.5);
	}
	SECTION("operator/_GivenString_Divides")
	{
		Formula f("=5 + 5", nullptr);
		String s("2");

		double res = f / s;

		REQUIRE(res == 5);
	}
}

TEST_CASE("Formula getSize", "[getSize]")
{
	SECTION("getSize_GivenInteger")
	{
		Formula f("=5 + 5", nullptr);

		REQUIRE(f.getSize() == 9);
	}
	SECTION("getSize_GivenNotNumber")
	{
		Formula f("=ivan", nullptr);

		REQUIRE(f.getSize() == 8);
	}
	SECTION("getSize_GivenDouble")
	{
		Formula f("=2.5", nullptr);

		REQUIRE(f.getSize() == 8);
	}
}

TEST_CASE("Formula getValue", "[getValue]")
{
	SECTION("getValue_GivenInteger")
	{
		Formula f("=5 + 5", nullptr);

		REQUIRE(f.getValue() == 10);
	}
	SECTION("getValue_GivenNotNumber")
	{
		Formula f("=ivan", nullptr);

		REQUIRE(f.getValue() == 0);
	}
	SECTION("getValue_GivenDouble")
	{
		Formula f("=2.5", nullptr);

		REQUIRE(f.getValue() == 2.5);
	}
}

TEST_CASE("Formula toString", "[toString]")
{
	SECTION("toString_GivenInteger")
	{
		Formula f("=5 + 5", nullptr);

		REQUIRE(f.toString() == "=5 + 5");
	}
	SECTION("toString_GivenNotNumber")
	{
		Formula f("=5 + 5", nullptr);

		REQUIRE(f.toString() == "=5 + 5");
	}
	SECTION("toString_GivenDouble")
	{
		Formula f("=2.5", nullptr);

		REQUIRE(f.toString() == "=2.5");
	}
}

TEST_CASE("Formula calculate", "[calculate]")
{
	SECTION("calculate_AllOperators")
	{
		Formula f("=5 + 5 ^ 2 / 25 - 4 * 5", nullptr);
		f.calculate();
		REQUIRE(f.getValue() == -14);
	}
	SECTION("calculate_TooManyOperators_Throws")
	{
		REQUIRE_THROWS_AS(Formula("=5 + 5 ^ 2 / 25 - 4 * 5 +", nullptr), std::invalid_argument);
	}
	SECTION("calculate_AllOperatorsGivenString")
	{
		Formula f("=5 + 5 ^ 2 / 25 - 4 * \"ivan\"", nullptr);
		f.calculate();
		REQUIRE(f.getValue() == 6);
	}
	SECTION("calculate_Addresses")
	{
		Table t;
		t.edit(new Integer("5"), 1, 1);
		t.edit(new Integer("5"), 1, 2);
		t.edit(new Integer("2"), 1, 3);
		t.edit(new Integer("25"), 1, 4);
		t.edit(new Integer("4"), 1, 5);
		t.edit(new Integer("5"), 1, 6);
		Formula* f = new Formula("=A1 + B1 ^ C1 / D1 - E1 * F1", &t);
		f->calculate();
		REQUIRE(f->getValue() == -14);
		t.clear();
	}
	SECTION("calculate_InvalidAddresses")
	{
		Table t;
		t.edit(new Integer("5"), 1, 1);
		t.edit(new Integer("5"), 1, 2);
		t.edit(new Integer("2"), 1, 3);
		t.edit(new Integer("25"), 1, 4);
		t.edit(new Integer("4"), 1, 5);
		Formula* f = new Formula("=A1 + B1 ^ C1 / D1 - E1 * F1", &t);
		f->calculate();
		REQUIRE(f->getValue() == 6);
		t.clear();
	}
	SECTION("calculate_StringAddress")
	{
		Table t;
		t.edit(new Integer("5"), 1, 1);
		t.edit(new Integer("5"), 1, 2);
		t.edit(new Integer("2"), 1, 3);
		t.edit(new Integer("25"), 1, 4);
		t.edit(new Integer("4"), 1, 5);
		t.edit(new String("ivan"), 1, 6);
		Formula* f = new Formula("=A1 + B1 ^ C1 / D1 - E1 * F1", &t);
		f->calculate();
		REQUIRE(f->getValue() == 6);
		t.clear();
	}
}

TEST_CASE("Table rowsCount", "[rowsCount]")
{
	SECTION("rowsCount_GivenEmptyTable_ReturnsZero")
	{
		Table t;

		REQUIRE(t.rowsCount() == 0);
	}
	SECTION("rowsCount_GivenNonEmptyTable_ReturnsCount")
	{
		Table t;
		t.edit(new Integer("123"), 10, 10);

		REQUIRE(t.rowsCount() == 10);
		t.clear();
	}
}

TEST_CASE("Table colsCount", "[colsCount]")
{
	SECTION("colsCount_GivenEmptyTable_ReturnsZero")
	{
		Table t;

		REQUIRE(t.colsCount() == 0);
	}
	SECTION("colsCount_GivenNonEmptyTable_ReturnsCount")
	{
		Table t;
		t.edit(new Integer("123"), 10, 10);

		REQUIRE(t.colsCount() == 10);
		t.clear();
	}
}

TEST_CASE("Table at", "[at]")
{
	SECTION("at_GivenEmptyTable_ReturnsNullptr")
	{
		Table t;

		REQUIRE(t.at(0, 0) == nullptr);
	}
	SECTION("at_GivenValidIndex_ReturnsObject")
	{
		Table t;
		t.edit(new Integer("123"), 2, 2);

		REQUIRE(t.at(1, 1)->getValue() == 123);
		t.clear();
	}
}

TEST_CASE("Table clear", "[clear]")
{
	SECTION("clear_GivenTable_Clears")
	{
		Table t;
		t.edit(new Integer("123"), 2, 2);
		t.clear();
		REQUIRE(t.at(1, 1) == nullptr);
	}
}

TEST_CASE("Table edit", "[edit]")
{
	SECTION("edit_GivenTable_Edits")
	{
		Table t;
		t.edit(new Integer("123"), 2, 2);
		REQUIRE(t.at(1, 1)->getValue() == 123);
		t.clear();
	}
}

TEST_CASE("Proccessor isInteger", "[isInteger]")
{
	SECTION("isInteger_GivenValidInteger_ReturnsTrue")
	{
		REQUIRE(Proccessor::isInteger("123"));
		REQUIRE(Proccessor::isInteger("+123"));
		REQUIRE(Proccessor::isInteger("-123"));
	}
	SECTION("isInteger_GivenInValidInteger_ReturnsFalse")
	{
		REQUIRE(!Proccessor::isInteger("-123.5"));
		REQUIRE(!Proccessor::isInteger("asdsa"));
	}
}

TEST_CASE("Proccessor isDouble", "[isDouble]")
{
	SECTION("isDouble_GivenValidDouble_ReturnsTrue")
	{
		REQUIRE(Proccessor::isDouble("2.5"));
		REQUIRE(Proccessor::isDouble("+2.5"));
		REQUIRE(Proccessor::isDouble("-2.5"));
	}
	SECTION("isDouble_GivenInValidDouble_ReturnsFalse")
	{
		REQUIRE(!Proccessor::isDouble("-123"));
		REQUIRE(!Proccessor::isDouble("asdsa"));
	}
}

TEST_CASE("Proccessor isString", "[isString]")
{
	SECTION("isString_GivenValidString_ReturnsTrue")
	{
		REQUIRE(Proccessor::isString("\"asd\""));
	}
	SECTION("isString_GivenInValidString_ReturnsFalse")
	{
		REQUIRE(!Proccessor::isString("-123"));
		REQUIRE(!Proccessor::isString("+2.5"));
	}
}

TEST_CASE("Proccessor isFormula", "[isFormula]")
{
	SECTION("isFormula_GivenValidFormula_ReturnsTrue")
	{
		REQUIRE(Proccessor::isFormula("=5 + 5"));
	}
	SECTION("isFormula_GivenInValidFormula_ReturnsFalse")
	{
		REQUIRE(!Proccessor::isFormula("5 + 5"));
	}
}

TEST_CASE("Proccessor process", "[process]")
{
	SECTION("process_GivenValidInput_Splits")
	{
		std::vector<string> tokens;
		Proccessor::process("edit a1 5", tokens);

		REQUIRE(tokens[0] == "edit");
		REQUIRE(tokens[1] == "a1");
		REQUIRE(tokens[2] == "5");
	}
	SECTION("isFormula_GivenInvalidInput_Throws")
	{
		std::vector<string> tokens;

		REQUIRE_THROWS_AS(Proccessor::process("edit a1 5 adc", tokens), std::invalid_argument);
	}
}

TEST_CASE("Proccessor processString", "[processString]")
{
	SECTION("processString_GivenValidString_RemovesQuotes")
	{
		string s = "\"adsa dsa\"";

		Proccessor::processString(s);
		char c1 = s[0];
		char c2 = s[7];

		REQUIRE(c1 == 'a');
		REQUIRE(c2 == 'a');
	}
}

TEST_CASE("Proccessor getPosition", "[getPosition]")
{
	SECTION("getPosition_GivenValidAddress_SetsRowAndCol")
	{
		string s = "A4";
		size_t row = 0, col = 0;

		Proccessor::getPosition(s, row, col);

		REQUIRE(row == 4);
		REQUIRE(col == 1);
	}
}

TEST_CASE("Proccessor processFormula", "[processFormula]")
{
	SECTION("processFormula_GivenValidFormula_Removes=")
	{
		string s = "=4 + 5";
		Proccessor::processFormula(s);

		char c = s[0];

		REQUIRE(c == '4');
	}
}

TEST_CASE("Proccessor updateFormulas", "[updateFormulas]")
{
	SECTION("updateFormulas_GivenValidTable_Recalculates")
	{
		Table t;
		t.edit(new Integer("5"), 1, 1);
		Formula* f = new Formula("=A1 + 5", &t);
		t.edit(f, 1, 2);
		t.edit(new Integer("6"), 1, 1);

		Proccessor::updateFormulas(t);

		REQUIRE(f->getValue() == 11);
		t.clear();
	}
}

TEST_CASE("Proccessor isAddress", "[isAddress]")
{
	SECTION("isAddress_GivenValidAddress_ReturnsTrue")
	{
		string s = "A1";

		REQUIRE(Proccessor::isAddress(s) == true);
	}
	SECTION("isAddress_GivenInValidAddress_ReturnsFalse")
	{
		string s1 = "a1";
		string s2 = "5";

		REQUIRE(Proccessor::isAddress(s1) == false);
		REQUIRE(Proccessor::isAddress(s2) == false);
	}
}

TEST_CASE("Proccessor toUpper", "[toUpper]")
{
	SECTION("toUpper_GivenLowerCaseString_ToUpper")
	{
		string s = "abcd";
		Proccessor::toUpper(s);

		REQUIRE(s == "ABCD");
	}
	SECTION("isAddress_GivenUpperCaseString_NoDiff")
	{
		string s = "ABCD";
		Proccessor::toUpper(s);

		REQUIRE(s == "ABCD");
	}
}

TEST_CASE("Proccessor splitByComma", "[splitByComma]")
{
	SECTION("splitByComma_GivenString_Splits")
	{
		std::vector<string> tokens;
		string s = "abd, ads";
		Proccessor::splitByComma(s, tokens);

		REQUIRE(tokens[0] == "abd");
		REQUIRE(tokens[1] == "ads");
	}
}

TEST_CASE("Proccessor putWhiteSpaces", "[putWhiteSpaces]")
{
	SECTION("putWhiteSpaces_GivenString")
	{
		string s = "abd+ads";
		Proccessor::putWhiteSpaces(s);

		char c1 = s[3];
		char c2 = s[5];

		REQUIRE(c1 == ' ');
		REQUIRE(c2 == ' ');
	}
}

TEST_CASE("Proccessor isNumber", "[isNumber]")
{
	SECTION("isNumber_GivenValidNumber")
	{
		char ch = '6';

		REQUIRE(Proccessor::isNumber(ch));
	}
	SECTION("isNumber_GivenInvalidNumber")
	{
		char ch = 'a';

		REQUIRE(!Proccessor::isNumber(ch));
	}
}

TEST_CASE("Proccessor isUpperCase", "[isUpperCase]")
{
	SECTION("isUpperCase_GivenUpperCase")
	{
		char ch = 'A';

		REQUIRE(Proccessor::isUpperCase(ch));
	}
	SECTION("isUpperCase_GivenLowerCase")
	{
		char ch = 'a';

		REQUIRE(!Proccessor::isUpperCase(ch));
	}
}

TEST_CASE("Proccessor isLowerCase", "[isLowerCase]")
{
	SECTION("isLowerCase_GivenLowerCase")
	{
		char ch = 'a';

		REQUIRE(Proccessor::isLowerCase(ch));
	}
	SECTION("isLowerCase_GivenUpperCase")
	{
		char ch = 'A';

		REQUIRE(!Proccessor::isLowerCase(ch));
	}
}

TEST_CASE("Proccessor isAritmeticSign", "[isAritmeticSign]")
{
	SECTION("isAritmeticSign_GivenAritmeticSign_ReturnsTrue")
	{
		string str = "+";

		REQUIRE(Proccessor::isAritmeticSign(str));
	}
	SECTION("isAritmeticSign_GivenNotAritmeticSign_ReturnsFalse")
	{
		string str = "a";

		REQUIRE(!Proccessor::isAritmeticSign(str));
	}
}

TEST_CASE("Document Constructor", "[Document]")
{
	SECTION("Document_GivenDocument_Creates")
	{
		Document doc;

		REQUIRE(doc.getFileName().empty());
		REQUIRE(!doc.isNew());
		REQUIRE(!doc.isOpen());
	}
}

TEST_CASE("Document open", "[open]")
{
	SECTION("open_GivenValidFile_LoadsData")
	{
		Document doc;
		Table t;

		doc.open("input.txt", t);

		REQUIRE(doc.getFileName() == "input.txt");
		REQUIRE(!doc.isNew());
		REQUIRE(doc.isOpen());
	}
	SECTION("open_GivenValidFile_LoadsData")
	{
		Document doc;
		Table t;

		doc.open("input.txt", t);

		REQUIRE(doc.getFileName() == "input.txt");
		REQUIRE(!doc.isNew());
		REQUIRE(doc.isOpen());
		REQUIRE(t.at(0, 0)->getValue() == 123);
		REQUIRE(t.at(1, 3)->toString() == "abc");
		REQUIRE(t.at(3, 1)->getValue() == 123);

		t.clear();
	}
	SECTION("open_GivenInValidFile_Throws")
	{
		Document doc;
		Table t;

		REQUIRE_THROWS_AS(doc.open("abc.txt", t), std::invalid_argument);

		t.clear();
	}
	SECTION("open_GivenInValidFile_Throws")
	{
		Document doc;
		Table t;

		REQUIRE_THROWS_AS(doc.open("wrongInput.txt", t), std::invalid_argument);

		t.clear();
	}
}

TEST_CASE("Document close", "[close]")
{
	SECTION("close_ClosesFile")
	{
		Document doc;
		Table t;

		doc.open("input.txt", t);
		doc.close();

		REQUIRE(doc.getFileName().empty());
		REQUIRE(!doc.isNew());
		REQUIRE(!doc.isOpen());
		t.clear();
	}
}

TEST_CASE("Document new", "[new]")
{
	SECTION("new_SetsToTrue")
	{
		Document doc;

		doc.newDoc();

		REQUIRE(doc.getFileName().empty());
		REQUIRE(doc.isNew());
		REQUIRE(!doc.isOpen());
	}
}

TEST_CASE("Document save", "[save]")
{
	SECTION("save_GivenNoPath_Throws")
	{
		Document doc;
		Table t;

		doc.newDoc();

		REQUIRE_THROWS_AS(doc.save(t), std::invalid_argument);
	}
	SECTION("save_NotLoadedDoc_Throws")
	{
		Document doc;
		Table t;

		REQUIRE_THROWS_AS(doc.save(t), std::invalid_argument);
	}
}

TEST_CASE("Document saveas", "[saveas]")
{
	SECTION("saveas_GivenNoLoadedFile_Throws")
	{
		Document doc;

		REQUIRE_THROWS_AS(doc.close(), std::invalid_argument);
	}
}