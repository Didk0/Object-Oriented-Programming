#pragma once
#include "Grade.h"
#include <iostream>

const int MAX_NAME_SIZE = 50;
const int MAX_EGN_SIZE = 10;

struct Student
{
	char* name;
	char* ID;
	size_t FN;
	Grade grades[5];
};

Student* createStudent();

bool addStudent(Student* students, size_t count);

void printStudentsInMarch(Student*& students, size_t count);

void printHighestGrade(Student*& students, size_t count);

void deleteStudent(Student& student);