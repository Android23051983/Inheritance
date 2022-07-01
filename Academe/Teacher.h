#pragma once
#include "Stdafx.h"
#include "Human.h"

#define TEACHER_PARAMETERS const std::string& specialty, unsigned int eperience
#define TEACHER_ARGUMENTS specialty, eperience


class Teacher :public Human
{
	string specialty;
	unsigned int experience;
public:
	const string& get_specialty()const;
	unsigned int get_experience()const;

	void set_specialty(const string& specialty);
	void set_experience(unsigned int experience);
	Teacher(HUMAN_PARAMETERS, TEACHER_PARAMETERS);
	~Teacher();

	void info()const;
};
