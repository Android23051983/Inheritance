#include <iostream>
#include <fstream>
#include <string>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

enum Defaults
{
	type_width = 15,
	last_name_width = 15,
	first_name_width = 10,
	age_width = 5,
	speciality_width = 25,
	group_width = 8,
	year_width = 3,
	reating_width = 8,
	attendance_width = 8
};

class Square
{
	double side;
	double diagonal;
public:
	double get_side()const
	{
		return side;
	}
	
	double get_diagonal()const
	{
		return diagonal;
	}

	void set_side(double side)
	{
		this->side = side;
	}

	void set_diagonal(double diagonal)
	{
		this->diagonal = diagonal;
	}
};

class Rectangle
{
	double width;
	double height;
	double diagonal;

public:
	double get_width()const
	{
		return width;
	}
	double get_height()const
	{
		return height;
	}
	double get_diagonal()const
	{
		return diagonal;
	}

	void set_width(double width)
	{
		this->width = width;
	}
	
	void set_height(double height)
	{
		this->height = height;
	}

	void set_diagonal(double diagonal)
	{
		this->diagonal = diagonal;
	}

};

class Triangle
{
public:
};
class Cicle
{
public:
};

void main()

{
	setlocale(LC_ALL, "");

}
