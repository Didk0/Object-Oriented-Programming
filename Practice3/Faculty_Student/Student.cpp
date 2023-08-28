#include "Student.h"

size_t Student::currFN = 0;

Student::Student(const char* name, const char* family, double gradeOOP, double gradeOOPpract)
	: m_FN(getFN())
	, m_name(new char[strlen(name) + 1])
	, m_family(new char[strlen(family) + 1])
	, m_gradeOOP(gradeOOP)
	, m_gradeOOPpract(gradeOOPpract)
{
	strcpy(m_name, name);
	strcpy(m_family, family);
}

Student::Student(const Student& other)
{
	copy(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

Student::Student(Student&& other) noexcept
{
	move(other);
}

Student& Student::operator=(Student&& other) noexcept
{
	if (this != &other)
	{
		move(other);
	}
	return *this;
}

Student::~Student()
{
	clear();
}

void Student::setGradeOOP(double grade)
{
	if (grade < 2 || grade > 6)
	{
		throw std::out_of_range("Grade must be between 2 and 6!");
	}
	m_gradeOOP = grade;
}

void Student::setGradeOOPpract(double grade)
{
	if (grade < 2 || grade > 6)
	{
		throw std::out_of_range("Grade must be between 2 and 6!");
	}
	m_gradeOOPpract = grade;
}

void Student::clear()
{
	delete[] m_name;
	m_name = nullptr;
	delete[] m_family;
	m_family = nullptr;
}

void Student::copy(const Student& other)
{
	m_FN = getFN();
	m_name = new char[strlen(other.m_name) + 1];
	strcpy(m_name, other.m_name);
	m_family = new char[strlen(other.m_family) + 1];
	strcpy(m_family, other.m_family);
	m_gradeOOP = other.m_gradeOOP;
	m_gradeOOPpract = other.m_gradeOOPpract;
}

void Student::move(Student& other)
{
	m_FN = other.m_FN;
	other.m_FN = 0;
	m_name = other.m_name;
	other.m_name = nullptr;
	m_family = other.m_family;
	other.m_family = nullptr;
	m_gradeOOP = other.m_gradeOOP;
	other.m_gradeOOP = 0;
	m_gradeOOPpract = other.m_gradeOOPpract;
	other.m_gradeOOPpract = 0;
}

size_t Student::getFN()
{
	return currFN++;
}
