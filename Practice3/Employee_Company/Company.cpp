#include "Company.h"

Company::Company()
	: m_employees(new Employee[1000])
	, m_size(0)
{}

Company::~Company()
{
	clear();
}

void Company::addEmployee(const Employee& emp)
{
	if (m_size + 1 <= 1000)
	{
		m_employees[m_size++] = emp;
	}
}

bool Company::removeEmployee(const Employee& emp)
{
	for (size_t i = 0; i < m_size; i++)
	{
		if (emp == m_employees[i])
		{
			m_employees[i] = m_employees[m_size - 1];
			m_employees[m_size - 1].~Employee();
			m_size--;
			return true;
		}
	}

	return false;
}

void Company::sort()
{
	for (size_t i = 0; i < m_size; i++)
	{
		size_t maxInd = i;
		for (size_t j = i; j < m_size - 1; j++)
		{
			if (strcmp(m_employees[maxInd].getName(), m_employees[j].getName()) < 0)
				maxInd = j;
		}
		if (maxInd != i)
		{
			std::swap(m_employees[maxInd], m_employees[i]);
		}
	}
}

double Company::avgSalary() const
{
	double avg = 0;
	for (size_t i = 0; i < m_size; i++)
	{
		avg += m_employees[i].getSalary();
	}
	return avg / m_size;
}

void Company::increaseSalary(double percent)
{
	for (size_t i = 0; i < m_size; i++)
	{
		double newSalary = m_employees[i].getSalary() + m_employees[i].getSalary() * percent / 100;
		m_employees[i].setSalary(newSalary);
	}
}

void Company::clear()
{
	delete[] m_employees;
	m_employees = nullptr;
}
