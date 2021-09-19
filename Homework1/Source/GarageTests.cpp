#include<cassert>
#include "catch.hpp"
#include "Garage.h"

TEST_CASE("Garage Constructor", "[Garage]")
{
	SECTION("Constructor_GivenGarageObject_CreatesWithValue")
	{
		Garage garage(10);

		REQUIRE(garage.size() == 0);
		REQUIRE(garage.empty() == true);
	}
	SECTION("Constructor_GivenGarageObject_CreatesWithZeroSize")
	{
		REQUIRE_THROWS_AS(Garage(0), std::invalid_argument);
	}
}

TEST_CASE("Garage Copy constructor", "[Garage]")
{
	SECTION("CopyConstructor_GivenGarageObject_HaveSameSizes")
	{
		Garage garage1(5);
		Garage garage2(garage1);

		REQUIRE(garage2.size() == garage1.size());
	}
}

TEST_CASE("Garage operator=", "[Garage]")
{
	SECTION("operator=_GivenGarageObject_HaveSameSizes")
	{
		Garage garage1(5);
		Garage garage2 = garage1;

		REQUIRE(garage2.size() == garage1.size());
	}
}

TEST_CASE("insert class method", "[insert]")
{
	SECTION("insert_GivenGarageObject_InsertsCorrectly")
	{
		Garage garage1(5);
		Vehicle vehicle("1234", "audi", 3);
		garage1.insert(vehicle);

		REQUIRE(garage1.size() == 1);
	}
	SECTION("insert_GivenGarageObject_NotEnoughSpace")
	{
		Garage garage1(5);
		Vehicle vehicle("1234", "audi", 6);

		REQUIRE_THROWS_AS(garage1.insert(vehicle), std::invalid_argument);
	}
	SECTION("insert_GivenGarageObject_SameRegNumbers")
	{
		Garage garage1(5);
		Vehicle vehicle1("1234", "audi", 2);
		Vehicle vehicle2("1234", "opel", 2);
		garage1.insert(vehicle1);

		REQUIRE_THROWS_AS(garage1.insert(vehicle2), std::invalid_argument);
	}
}

TEST_CASE("erase class method", "[erase]")
{
	SECTION("erase_GivenGarageObject_ErasesProperly")
	{
		Garage garage1(5);
		Vehicle vehicle("1234", "audi", 3);
		garage1.insert(vehicle);
		garage1.erase(vehicle.registration());

		REQUIRE(garage1.size() == 0);
	}
}

TEST_CASE("Garage at class method", "[at]")
{
	SECTION("Constructor_GivenGarageObject_ReturnsCorrectIndex")
	{
		Garage garage1(5);
		Vehicle vehicle1("1234", "audi", 3);
		Vehicle vehicle2("4567", "opel", 2);
		garage1.insert(vehicle1);
		garage1.insert(vehicle2);

		bool areDifferent = strcmp(garage1.at(1).registration(), vehicle2.registration());

		REQUIRE(areDifferent == false);
	}
	SECTION("Constructor_GivenInvalidIndex_ShouldThrow")
	{
		Garage garage1(5);
		Vehicle vehicle1("1234", "audi", 3);
		garage1.insert(vehicle1);

		REQUIRE_THROWS_AS(garage1.at(1), std::out_of_range);
	}
}

TEST_CASE("Garage operator[]", "[operator[]]")
{
	SECTION("operator[]_GivenGarageObject_ReturnsCorrectIndex")
	{
		Garage garage1(5);
		Vehicle vehicle1("1234", "audi", 3);
		garage1.insert(vehicle1);

		bool areDifferent = strcmp(garage1[0].registration(), vehicle1.registration());

		REQUIRE(areDifferent == false);
	}
}

TEST_CASE("Garage empty class method", "[empty]")
{
	SECTION("empty_GivenGarageObject_ReturnsZeroSize")
	{
		Garage garage1(5);
		Vehicle vehicle1("1234", "audi", 3);
		garage1.insert(vehicle1);
		garage1.erase(vehicle1.registration());

		REQUIRE(garage1.empty() == true);
	}
	SECTION("empty_GivenGarageObject_ReturnsZeroSizeFromBegining")
	{
		Garage garage1(5);

		REQUIRE(garage1.empty() == true);
	}
}

TEST_CASE("Garage size class method", "[size]")
{
	SECTION("size_GivenGarageObject_ZeroSize")
	{
		Garage garage1(5);
		Vehicle vehicle1("1234", "audi", 3);
		garage1.insert(vehicle1);
		garage1.erase(vehicle1.registration());

		REQUIRE(garage1.empty() == true);
	}
	SECTION("size_GivenGarageObject_ZeroSizeFromBegining")
	{
		Garage garage1(5);

		REQUIRE(garage1.empty() == true);
	}
}

TEST_CASE("Garage clear class method", "[clear]")
{
	SECTION("clear_GivenGarageObject_HasZeroValues")
	{
		Garage garage1(5);
		Vehicle vehicle1("1234", "audi", 3);
		garage1.insert(vehicle1);
		garage1.clear();

		REQUIRE(garage1.empty() == true);
		REQUIRE(garage1.size() == 0);
	}
	SECTION("clear_GivenGarageObject_HasZeroValuesFromBegining")
	{
		Garage garage1(5);

		REQUIRE(garage1.empty() == true);
		REQUIRE(garage1.size() == 0);
	}
}

TEST_CASE("find class method", "[find]")
{
	SECTION("find_GivenGarageObject_FindsVehicleWithRegNum")
	{
		Garage garage1(5);
		Vehicle vehicle1("1234", "audi", 3);
		garage1.insert(vehicle1);

		bool areDifferent = strcmp(garage1.find(vehicle1.registration())->registration(), vehicle1.registration());

		REQUIRE(areDifferent == false);
	}
	SECTION("find_GivenGarageObject_ReturnsNullptr")
	{
		Garage garage1(5);

		bool isNullptr = garage1.find("1234") == nullptr;

		REQUIRE(isNullptr == true);
	}
}