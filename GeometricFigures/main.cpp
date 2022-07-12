#include "Stdafx.h"

//enum Defaults
//{
//	size = NULL,
//	diagonal = NULL,
//	width = NULL,
//	height = NULL
//};

class Square
{
	float side;
public:
	float get_side()const
	{
		return side;
	}

	void set(float side)
	{
		this->side = side;
	}

	Square()
	{
		this->side = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Square(float side)
	{
		this->side = side;
		cout << "Constructor:\t\t" << this << endl;

	}
	~Square()
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	void Perimeter()
	{
		cout << "��������: " << side * 4 << endl;
	}
	void Square1()
	{
		cout << "�������: " << side * side << endl;
	}
	void print()
	{
		cout << "������� ��������: " << this->side << endl;
	}
};




class Rectangle
{
	float width;
	float height;

public:
	float get_width()const
	{
		return width;
	}
	float get_height()const
	{
		return height;
	}
	

	void set(float width, float height)
	{
		this->width = width;
		this->height = height;
	}

	Rectangle()
	{
		this->width = 0;
		this->height = 0;
		cout << "DefaultConstructorRectangle:\t" << this << endl;
	}
	Rectangle(float width, float height)
	{
		this->width = width;
		this->height = height;
		cout << "ConstructorRectangle:\t\t" << this << endl;
	}
	~Rectangle()
	{
		cout << "DestructorRectangle: \t\t" << this << endl;
	}


	void Perimeter()
	{
		cout << "��������: " << (height + width) * 2 << endl;
	}
	void Square()
	{
		cout << "�������: " << height * width << endl;
	}

	
	void print()
	{
		cout << "������: " << this->height << "\n������: " << this->width << std::endl;
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

//#define RECTANGLE
//#define SQUARE

void main()

{
	setlocale(LC_ALL, "");
#ifdef RECTANGLE
	Rectangle A;
	A.print();
	float a, b;
	cout << "������� ������ � ������ ����� ������: ";
	cin >> a >> b;
	A.set(a, b);
	A.print();
	A.Perimeter();
	A.Square();
#endif // RECTANGLE

#ifdef SQUARE
	Square A;
	A.print();
	float a;
	cout << "������� ������ ������� ��������: ";
	cin >> a;
	A.set(a);
	A.print();
	A.Perimeter();
	A.Square1();
#endif // SQUARE


	system("pause");

}
