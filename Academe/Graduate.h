#pragma once
#include "Stdafx.h"
#include "Human.h"
#include "Student.h"
class Graduate :public Student
{
	string subject;
public:
	const string& get_subgect()const;
	void set_subject(const string& subject);

	Graduate(HUMAN_PARAMETERS, STUDENT_PARAMETERS, const string& subject);
	~Graduate();
	void info()const;
};