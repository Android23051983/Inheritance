#pragma once
#include "Stdafx.h"
#include "Human.h"
#include "Student.h"

#define STUDENT_PARAMETERS const string& specialty, const string& group, unsigned int year, float rating, float attendance
#define STUDENT_ARGUMENTS specialty, group,  year, rating, attendance

class Student :public Human
{

	string specialty;
	string group;
	unsigned int year;
	float rating;
	float attendance;
public:
	const string& get_specialty()const;
	const string& get_group()const;
	unsigned int get_year()const;
	float get_rating()const;
	float get_attendance()const;

	void set_specialty(const string& specialty);
	void set_group(const string& group);
	void set_year(unsigned int year);
	void set_rating(float rating);
	void set_attendance(float attendance);

	Student(HUMAN_PARAMETERS, STUDENT_PARAMETERS) :Human(HUMAN_ARGUMENTS);
	~Student();
	void info()const;
};