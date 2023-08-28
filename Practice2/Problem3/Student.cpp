#include "Student.h"

bool isLetter(char l)
{
	return (l >= 97 && l <= 122) || (l >= 65 && l <= 90);
}

bool isCapital(char l)
{
	return (l >= 65 && l <= 90);
}

void makeCapital(char* name)
{
	while (*name) {
		while (!isLetter(*name)) {
			name++;
		}

		if (!isCapital(*name)) {
			*name -= 32;
		}

		while (isLetter(*name)) {
			name++;
		}
	}
}

size_t setName(char* name, Student*& student)
{
	std::cin.getline(name, 50);

	size_t len = strlen(name);
	student->name = new char[len + 1];
	if (!name)
	{
		return 0;
	}

	makeCapital(name);
	strcpy(student->name, name);

	return 1;
}

size_t setID(char* id, Student*& student)
{
	std::cin.getline(id, 10);

	student->ID = new char[strlen(id) + 1];
	if (!student->ID)
	{
		return 0;
	}

	strcpy(student->ID, id);

	return 1;
}

size_t setFN(size_t fn, Student*& student)
{
	std::cin >> fn;

	if (fn < 100000 || fn > 999999)
	{
		return 0;
	}
	student->FN = fn;

	return 1;
}

size_t setGrades(char* subject, Student*& student)
{
	for (size_t i = 0; i < 5; i++)
	{
		std::cin.getline(subject, 50);

		student->grades[i].subject = new char[strlen(subject) + 1];
		if (!student->grades[i].subject) {
			return 0;
		}

		strcpy(student->grades[i].subject, subject);
		std::cin >> student->grades[i].grade;
	}

	return 1;
}

Student* createStudent()
{
	Student* student;
	size_t fn;
	char buffer[100];

	if (!setName(buffer, student))
	{
		return nullptr;
	}
	if (!setID(buffer, student))
	{
		return nullptr;
	}
	if (!setFN(fn, student))
	{
		return nullptr;
	}
	if (!setGrades(buffer, student))
	{
		return nullptr;
	}

	return student;
}

bool addStudent(Student* students, size_t count)
{
	Student* student = createStudent();

	if (!student)
	{
		return false;
	}

	students[count] = *student;

	return true;
}

double averageGrade(Student* student)
{
	double res = 0;
	for (size_t i = 0; i < 5; i++) {
		res += student->grades[i].grade;
	}

	return res / 5;

}

void printStudentsInMarch(Student*& students, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		if (students[i].ID[3] == '3')
		{
			std::cout << "Full name: " << students[i].name << "| Average performance: " << averageGrade(&students[i]) << std::endl;
		}
	}
}

void printHighestGrade(Student*& students, size_t count)
{
	Student* student = nullptr;
	double max = 0;
	for (size_t i = 0; i < count; i++)
	{
		double average = averageGrade(&students[i]);
		if (average > max)
		{
			max = average;
			student = &students[i];
		}
	}

	std::cout << "Full name: " << student->name << "| Average performance: " << averageGrade(student) << std::endl;
}

void deleteStudent(Student& student)
{
	delete[] student.name;
	delete[] student.ID;
	for (size_t i = 0; i < 5; i++)
	{
		delete[] student.grades->subject;
	}
}
