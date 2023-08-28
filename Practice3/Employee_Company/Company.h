#pragma once
#include "Employee.h"

class Company
{
public:
	Company();
	~Company();

	void addEmployee(const Employee& emp);
	bool removeEmployee(const Employee& emp);
	inline bool isEmpty() const { return m_size == 0; }
	void sort();
	double avgSalary() const;
	void increaseSalary(double percent);

private:
	void clear();

	Employee* m_employees;
	size_t m_size;
};

