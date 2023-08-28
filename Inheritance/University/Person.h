#pragma once
#include <string>

using std::string;

class Person
{
public:
	Person(const string& name = "", unsigned int age = 0);

	void print() const;

	inline const string& getName() const { return m_name; };
	inline const unsigned int getAge() const { return m_age; };

protected:
	string m_name;
	unsigned int m_age;
};

