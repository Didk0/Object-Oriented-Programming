#pragma once
#include "Person.h"
#include "Vehicle.h"
#include <cstring>
#include <iostream>
#include <fstream>

using std::getline;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::invalid_argument;
using std::ifstream;
using std::ofstream;
using tokens = vector<string>;

class Database
{
public:
	Database(const Database& other) = delete;
	Database& operator=(const Database& other) = delete;

	static Database& instance();

	Person* findPerson(unsigned int ID);
	Vehicle* findVehicle(const string& regNum);
	void addPerson(const string& name, unsigned int ID);
	void removePerson(unsigned int ID);
	void addVehicle(const string& regNum, const string& description);
	void removeVehicle(const string& regNum);
	void acquire(unsigned int ownerID, const string& regNum);
	void release(unsigned int ownerID, const string& regNum);
	void displayHelp() const;
	void run();
	void readFromFile(const string& file);
	void writeToFile(const string& file);

private:
	Database();

	void validateInput(const string& command, tokens& tokens);
	inline bool isDigit(char ch) const { return ch >= '0' && ch <= '9'; };
	bool isID(const string& str) const;
	void toUpper(string& str);
	void printPeople() const;
	void printVehicles() const;
	string& at(size_t index, tokens& tokens);
	unsigned int atoi(string& str);

	vector<Person> m_people;
	vector<Vehicle> m_vehicles;
};

