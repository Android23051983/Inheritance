#include "Stdafx.h"
#include "Teacher.h"

const string& Teacher::get_specialty()const
{
	return specialty;
}
unsigned int Teacher::get_experience()const
{
	return experience;
}

void Teacher::set_specialty(const string& specialty)
{
	this->specialty = specialty;
}
void Teacher::set_experience(unsigned int experience)
{
	this->experience = experience;
}
Teacher::Teacher(HUMAN_PARAMETERS, TEACHER_PARAMETERS) :Human(HUMAN_ARGUMENTS)
{
	set_specialty(specialty);
}
Teacher::~Teacher()
{
	cout << "TDestructor:\t" << this << endl;
}

void Teacher::info()const
{
	cout << specialty << " " << experience << endl;
}