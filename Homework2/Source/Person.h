#pragma once
#include "Registration.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>

using std::string;
using std::vector;
using std::istream;
using std::ostream;

class Person
{
public:
	Person(const string& name = "", unsigned int id = 0);

	inline const string& getName() const { return m_name; }
	inline unsigned int getId() const { return m_Id; };
	inline size_t getVehiclesNum() const { return m_vehicles.size(); };
	inline const string& getCurrVehicle(size_t index) const { return m_vehicles[index].toString(); };
	void addRegNum(const string& regNum);
	void removeRegNum(const string& regNum);
	int findRegNum(const string& regNum);

	friend istream& operator>>(istream& in, Person& obj);
	friend ostream& operator<<(ostream& out, const Person& obj);

private:
	string m_name;
	unsigned int m_Id;
	vector<Registration> m_vehicles;
};

