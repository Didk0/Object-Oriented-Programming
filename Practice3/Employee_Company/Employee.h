#pragma once
#include <cstring>
#include <iostream>

class Employee
{
public:
	Employee(const char* name = "", const char* department = "", size_t years = 0, double salary = 0);
	~Employee();

	void setName(const char* name);
	void setDepartment(const char* department);
	void setYears(size_t years);
	void setSalary(double salary);

	inline const char* getName() const { return m_name; }
	inline const char* getDepartment() const { return m_department; }
	inline size_t getYears() const { return m_years; }
	inline double getSalary() const { return m_salary; }

	bool operator==(const Employee& other) const;

	void print() const;

private:
	void clear();

	char* m_name;
	char* m_department;
	size_t m_years;
	double m_salary;
};

