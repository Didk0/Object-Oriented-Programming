#pragma once
#include "Teacher.h"
#include "Student.h"

using teachers = std::vector<Teacher>;
using students = std::vector<Student>;

class University
{
public:
	University();
	void run();

private:
	size_t getNextFN();
	int    getTeacherIndex(const string& name) const;
	int    getStudentIndex(const string& name) const;

private:
	static const size_t STARTING_FAC_NUM;

	size_t   currFacNum;
	teachers m_teachers;
	students m_students;
};

