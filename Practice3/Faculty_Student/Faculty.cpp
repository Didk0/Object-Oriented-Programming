#include "Faculty.h"

Faculty::Faculty(const char* name, const char* dean)
	: m_name(new char[strlen(name) + 1])
	, m_dean(new char[strlen(dean) + 1])
{}

Faculty::~Faculty()
{
	clear();
}

void Faculty::setName(const char* name)
{
	if (name != nullptr)
	{
		m_name = new char[strlen(name) + 1];
		delete[] m_name;
		strcpy(m_name, name);
	}
}

void Faculty::setDean(const char* dean)
{
	if (dean != nullptr)
	{
		m_dean = new char[strlen(dean) + 1];
		delete[] m_dean;
		strcpy(m_dean, dean);
	}
}

void Faculty::addStudent(const Student& student)
{
	m_students.push_back(student);
}

void Faculty::printStudents() const
{
	size_t size = m_students.size();
	for (size_t i = 0; i < size; i++)
	{
		std::cout << m_students[i].getName() << " " << m_students[i].getFamily() << ", FN: " << m_students[i].FN()
			<< ", " << m_students[i].getGradeOOP() << ", " 
			<< m_students[i].getGradeOOPpract() << std::endl;
	}
}

void Faculty::expelStudent(size_t index)
{
	m_students.erase(m_students.begin() + index);
}

void Faculty::clear()
{
	delete[] m_name;
	m_name = nullptr;
	delete[] m_dean;
	m_dean = nullptr;
}
