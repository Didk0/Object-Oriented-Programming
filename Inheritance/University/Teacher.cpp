#include <iostream>
#include "Teacher.h"

using std::cout;
using std::endl;

const float  TEACH_SKILL_FACTOR_INCR = 0.5;
const size_t MAX_START_SKILL_LEVEL = 30;
const size_t MIN_START_SKILL_LEVEL = 10;

Teacher::Teacher(const string& name, unsigned int age, const string& subject)
	: Person(name, age)
	, m_subject({ subject, MIN_START_SKILL_LEVEL + rand() % (MAX_START_SKILL_LEVEL + 1) })
{
}

Teacher::Teacher(const Person& person, const string& subject)
	: Teacher(person.getName(), person.getAge(), subject)
{}

void Teacher::print() const
{
	Person::print();
	cout << " and is teaching " << m_subject.name << " with a skill level of " << m_subject.skill;
}

void Teacher::teach(Student& student)
{
	m_subject.skill += student.learn(m_subject) * TEACH_SKILL_FACTOR_INCR;
}
