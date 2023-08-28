#pragma once
#include <cstring>
#include <iostream>
class Student
{
public:
	Student(const char* name = "", const char* family = "", double gradeOOP = 0, double gradeOOPpract = 0);
	Student(const Student& other);
	Student& operator=(const Student& other);
	Student(Student&& other) noexcept;
	Student& operator=(Student&& other) noexcept;
	~Student();

	void setGradeOOP(double grade);
	void setGradeOOPpract(double grade);
	inline size_t FN() const { return m_FN; }
	inline const char* getName() const { return m_name; }
	inline const char* getFamily() const { return m_family; }
	inline double getGradeOOP() const { return m_gradeOOP; }
	inline double getGradeOOPpract() const { return m_gradeOOPpract; }

private:
	void clear();
	void copy(const Student& other);
	void move(Student& other);

	static size_t getFN();
	static size_t currFN;

	size_t m_FN;
	char* m_name;
	char* m_family;
	double m_gradeOOP;
	double m_gradeOOPpract;
};

