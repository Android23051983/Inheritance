#pragma once
#include "Stdafx.h"
#include "Student_define.h"

class Student :public Human
{

	std::string specialty;
	std::string group;
	unsigned int year;
	float rating;
	float attendance;
public:
	const std::string& get_specialty()const;
	const std::string& get_group()const;
	unsigned int get_year()const;
	float get_rating()const;
	float get_attendance()const;

	void set_specialty(const std::string& specialty);
	void set_group(const std::string& group);
	void set_year(unsigned int year);
	void set_rating(float rating);
	void set_attendance(float attendance);

	Student(HUMAN_PARAMETERS, STUDENT_PARAMETERS) :Human(HUMAN_ARGUMENTS);
	~Student();
	void info()const;
};