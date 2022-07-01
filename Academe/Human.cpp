#define "Stdafx.h"
#include "Human.h"
#include "Human_define.h"

const Human::string& get_last_name()const
{
	return last_name;
}
const Human::string& get_first_name()const
{
	return first_name;
}
unsigned int get_age()const
{
	return age;
}
void Human::set_last_name(const std::string& last_name)
{
	this->last_name = last_name;
}
void Human::set_first_name(const std::string& first_name)
{
	this->first_name = first_name;
}
void Human::set_age(unsigned int age)
{
	this->age = age;
}

Human::Human(HUMAN_PARAMETERS)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	cout << "HConstructor:\t" << this << endl;

}
Human::~Human()
{
	cout << "HDestructor:\t" << this << endl;
}
void Human::info()const
{
	cout << last_name << " " << first_name << " " << age << " " << "yars\n";
}