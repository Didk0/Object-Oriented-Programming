#pragma once
#include "Person.h"
#include "Student.h"
#include "Subject.h"

class Teacher : public Person
{
public:
	Teacher(const string& name = "", unsigned int age = 0, const string& subject = "");
	Teacher(const Person& person, const string& subject = "");

	void print() const;
	void teach(Student& student);

	inline string getSubject() const { return m_subject.name; };

private:
	Subject m_subject;
};

