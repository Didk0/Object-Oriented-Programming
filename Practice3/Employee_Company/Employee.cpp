#include "Employee.h"

Employee::Employee(const char* name, const char* department, size_t years, double salary)
	: m_name(new char[50])
	, m_department(new char[50])
	, m_years(years)
	, m_salary(salary)
{
	setName(name);
	setDepartment(department);
	setYears(years);
	setSalary(salary);
}

Employee::~Employee()
{
	clear();
}

void Employee::setName(const char* name)
{
	if (name != nullptr)
	{
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}
}

void Employee::setDepartment(const char* department)
{
	if (department != nullptr)
	{
		delete[] m_department;
		m_department = new char[strlen(department) + 1];
		strcpy(m_department, department);
	}
}

void Employee::setYears(size_t years)
{
	if (years >= 18 && years <= 64)
	{
		m_years = years;
	}
	else
	{
		std::cout << "Invalid years!" << std::endl;
		return;
	}
}

void Employee::setSalary(double salary)
{
	if (salary >= 610 && salary <= 1000)
	{
		m_salary = salary;
	}
	else
	{
		std::cout << "Invalid salary!" << std::endl;
		return;
	}
}

bool Employee::operator==(const Employee& other) const
{
	if (strcmp(m_name, other.m_name) == 0 && strcmp(m_department, other.m_department) == 0
		&& m_years == other.m_years && m_salary == other.m_salary)
	{
		return true;
	}

	return false;
}

void Employee::print() const
{
	std::cout << "name: " << m_name << ", department: " << m_department <<
		", years: " << m_years << ", salary: " << m_salary << std::endl;
}

void Employee::clear()
{
	delete[] m_name;
	m_name = nullptr;
	delete[] m_department;
	m_department = nullptr;
}
