
#include "Human.h"
#include "Student.h"

const string& Student::get_specialty()const
{
	return specialty;
}
const string& Student::get_group()const
{
	return group;
}
unsigned int Student::get_year()const
{
	return year;
}
float Student::get_rating()const
{
	return rating;
}
float Student::get_attendance()const
{
	return attendance;
}

void Student::set_specialty(const string& specialty)
{
	this->specialty = specialty;
}
void Student::set_group(const string& group)
{
	this->group = group;
}
void Student::set_year(unsigned int year)
{
	this->year = year;
}
void Student::set_rating(float rating)
{
	this->rating = rating;
}
void Student::set_attendance(float attendance)
{
	this->attendance = attendance;
}

Student::Student(HUMAN_PARAMETERS, STUDENT_PARAMETERS) :Human(HUMAN_ARGUMENTS)
{
	set_specialty(specialty);
	set_group(group);
	set_year(year);
	set_rating(rating);
	set_attendance(attendance);
	cout << "SConstructor:\t" << this << endl;
}
Student::~Student()
{
	cout << "SDestrucror:\t" << this << endl;
}
void Student::info()const
{
	Human::info();
	cout << specialty << " " << group << " " << year << " " << rating << " " << attendance << endl;
}