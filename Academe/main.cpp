#include "Stdafx.h"
#include "Human.h"
//#include "Human.cpp"
#include "Student.h"
//#include "Student.cpp"
#include "Teacher.h"
//#include "Teacher.cpp"
#include "Graduate.h"


//#define TEACHER_PARAMETERS const std::string& specialty, unsigned int eperience
//#define TEACHER_ARGUMENTS specialty, eperience
//
//
//class Teacher :public Human
//{
//
//	string specialty;
//	unsigned int experience;
//public:
//	const string& get_specialty()const
//	{
//		return specialty;
//	}
//	unsigned int get_experience()const
//	{
//		return experience;
//	}
//
//	void set_specialty(const string& specialty)
//	{
//		this->specialty = specialty;
//	}
//	void set_experience(unsigned int experience)
//	{
//		this->experience = experience;
//	}
//	Teacher(HUMAN_PARAMETERS, TEACHER_PARAMETERS) :Human(HUMAN_ARGUMENTS)
//	{
//		set_specialty(specialty);
//	}
//	~Teacher()
//	{
//		cout << "TDestructor:\t" << this << endl;
//	}
//
//	void info()const
//	{
//		cout << specialty << " " << experience << endl;
//	}
//};

//class Graduate :public Student
//{
//	std::string subject;
//public:
//	const std::string& get_subgect()const
//	{
//		return subject;
//	}
//	void set_subject(const std::string& subject)
//	{
//		this->subject = subject;
//	}
//
//	Graduate(HUMAN_PARAMETERS, STUDENT_PARAMETERS, const std::string& subject)
//		:Student(HUMAN_ARGUMENTS, STUDENT_ARGUMENTS)
//	{
//		set_subject(subject);
//		cout << "GConstructor:\t" << this << endl;
//	}
//	~Graduate()
//	{
//		cout << "GDestructor:\t" << this << endl;
//	}
//	void info()const
//	{
//		Student::info();
//		cout << " " << subject << endl;
//	}
//};

#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human h("Montana", "Antonio", 25);
	h.info();
	cout << "\n-------------------- - \n" << endl;
	Student jessie("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 1, 70, 90);
	jessie.info();

	cout << "\n---------------------- \n" << endl;
	Teacher walter("White", "Whalter", 50, "Chemistry", 25);
	walter.info();

	cout << "\n-------------------- - \n" << endl;
	Graduate hank("Schrader", "Hank", 40, "Criminalistic", "WW_220", 5, 89, 80, "How to catch Hejsenderg");
	hank.info();
	cout << "\n-------------------- - \n" << endl;
#endif // INHERITANCE_CHECK

	//Generalisation:


}