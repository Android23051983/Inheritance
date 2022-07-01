#include "Stdafx.h"
#include "Graduate.h"
#include "Human.h"
#include "Student.h"



const std::string& Graduate::get_subgect()const
{
	return subject;
}
void Graduate::set_subject(const std::string& subject)
{
	this->subject = subject;
}

Graduate::Graduate(HUMAN_PARAMETERS, STUDENT_PARAMETERS, const std::string& subject)
	:Student(HUMAN_ARGUMENTS, STUDENT_ARGUMENTS)
{
	set_subject(subject);
	cout << "GConstructor:\t" << this << endl;
}
Graduate::~Graduate()
{
	cout << "GDestructor:\t" << this << endl;
}
void Graduate::info()const
{
	Student::info();
	cout << " " << subject << endl;
}