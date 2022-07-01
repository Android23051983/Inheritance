#pragma once
#include "Stdafx.h"

#define HUMAN_PARAMETERS const string& last_name, const string& first_name, unsigned int age
#define HUMAN_ARGUMENTS last_name, first_name, age

class Human
{
	string last_name;
	string first_name;
	unsigned int  age;
public:
	const string& get_last_name()const;
	const string& get_first_name()const;
	unsigned int get_age()const;
	void set_last_name(const string& last_name);
	void set_first_name(const string& first_name);
	void set_age(unsigned int age);

	Human(HUMAN_PARAMETERS);
	~Human();
	void info()const;
};