#pragma once
#include "Registration.h"
#include <ostream>

using std::istream;
using std::ostream;

class Vehicle
{
public:
	Vehicle(const string& regnum = "", const string& description = "");

	inline const string& getRegNum() const { return m_regnum.toString(); };
	inline const string& getDescription() const { return m_description; };
	inline unsigned int getOwnerID() const { return m_personID; };
	void setOwner(unsigned int ID);

	friend istream& operator>>(istream& in, Vehicle& obj);
	friend ostream& operator<<(ostream& out, const Vehicle& obj);

private:
	Registration m_regnum;
	string m_description;
	unsigned int m_personID;
};

