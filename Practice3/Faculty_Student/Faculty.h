#pragma once
#include "Student.h"
#include <vector>

class Faculty
{
public:
	Faculty(const char* name = "", const char* dean = "");
	~Faculty();

	inline const char* getName() const { return m_name; }
	void setName(const char* name);
	void setDean(const char* dean);

	void addStudent(const Student& student);
	void printStudents() const;
	void expelStudent(size_t index);

private:
	void clear();

	char* m_name;
	char* m_dean;
	std::vector<Student> m_students;
};

