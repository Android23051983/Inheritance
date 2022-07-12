#include <iostream>
#include <fstream>
#include <string>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

enum Defaults
{
	size = NULL,
	diagonal = NULL,
	width = NULL,
	height = NULL
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

	Square()
	{
		this->side = 0;
		this->diagonal = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	~Square()
	{
		cout << "Destructor: \t\t" << this << endl;
	}
};

class Rectangle
{
	float width;
	float height;
	//float diagonal;

public:
	double get_width()const
	{
		return width;
	}
	double get_height()const
	{
		return height;
	}
	/*double get_diagonal()const
	{
		return diagonal;
	}*/

	void set_width(float width)
	{
		this->width = width;
	}
	
	void set_height(float height)
	{
		this->height = height;
	}

	/*void set_diagonal(double diagonal)
	{
		this->diagonal = diagonal;
	}*/

	void get()
	{
		cout << "Высота: " << height << "\nШирина: " << width << endl;
	}

	Rectangle()
	{
		this->width = 0;
		this->height = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	~Rectangle()
	{
		cout << "Destructor: \t\t" << this << endl;
	}
	void Perimeter()
	{}
	void Square()
	{}

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
