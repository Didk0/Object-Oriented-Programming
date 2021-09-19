#include<cassert>
#include "catch.hpp"
#include "Vehicle.h"

TEST_CASE("Vehicle class method", "[Vehicle]")
{
	SECTION("Vehicle_GivenVehicle_HaveEqualRegNums")
	{
		//Arrange
		Vehicle vehicle("4444", "car", 3);

		//Act
		bool areDifferentRegNums = strcmp(vehicle.registration(), "4444");

		//Assert
		REQUIRE(areDifferentRegNums == false);
	}
	SECTION("Vehicle_GivenVehicle_HaveEqualDescriptions")
	{
		//Arrange
		Vehicle vehicle("4444", "car", 3);

		//Act
		bool areDifferentDescr = strcmp(vehicle.description(), "car");
		bool areDifferentSpaces = vehicle.space() == 3;

		//Assert
		REQUIRE(areDifferentDescr == false);
	}
	SECTION("Vehicle_GivenVehicle_HaveEqualSpaces")
	{
		//Arrange
		Vehicle vehicle("4444", "car", 3);

		//Act
		bool areSameSpaces = vehicle.space() == 3;

		//Assert
		REQUIRE(areSameSpaces == true);
	}
}