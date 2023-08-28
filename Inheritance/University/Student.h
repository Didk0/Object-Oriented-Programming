#pragma once
#include <vector>
#include "Person.h"
#include "Subject.h"

using std::vector;
using subjects = vector<Subject>;

class Student : public Person
{
public:
	Student(const string& name = "", unsigned int age = 0, size_t fn = 0, const string& specialty = "");
	Student(const Person& person, size_t fn = 0, const string& specialty = "");

	void print() const;
	size_t learn(const Subject& subj);

	inline void setSpecialty(const string& spec) { m_specialty = spec; }
	inline size_t getFacultyNum() { return m_fN; }

private:
	int getSubjectIndex(const string& subjName) const;

	size_t m_fN;
	size_t m_learnLvl;
	string m_specialty;
	subjects m_subjects;
};

