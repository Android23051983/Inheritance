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
		cout << "Периметр: " << side * 4 << endl;
	}
	void Square1()
	{
		cout << "Площадь: " << side * side << endl;
	}
	void print()
	{
		cout << "Сторона квадрата: " << this->side << endl;
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
		cout << "Периметр: " << (height + width) * 2 << endl;
	}
	void Square()
	{
		cout << "Площадь: " << height * width << endl;
	}

	
	void print()
	{
		cout << "Высота: " << this->height << "\nШирина: " << this->width << std::endl;
	}



};

class Triangle
{
public:
};
class Circle
{
	float radius;
	float Pi;
public:
	float get_radius()const
	{
		return radius;
	}

	float get_Pi()const
	{
		return Pi;
	}

	void set(float radius)
	{
		this->radius = radius;
		this->Pi = 3.14;
	}

	Circle()
	{
		this->radius = 0;
		this->Pi =3.14;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Circle(float radius)
	{
		this->radius = radius;
		this->Pi = 3.14;
		cout << "Constructor:\t\t" << this << endl;
	}
	~Circle()
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	void print()
	{
		cout << "Радиус: " << this->radius << "\nПИ: " << this->Pi << endl;
	}
};

//#define RECTANGLE
//#define SQUARE
#define CIRCLE

void main()

{
	setlocale(LC_ALL, "");
#ifdef RECTANGLE
	Rectangle A;
	A.print();
	float a, b;
	cout << "Введите ширину и высоту через пробел: ";
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
	cout << "Введите размер стороны квадрата: ";
	cin >> a;
	A.set(a);
	A.print();
	A.Perimeter();
	A.Square1();
#endif // SQUARE

#ifdef CIRCLE
	Circle A;
	A.print();
	double a;
	cout << "Введите радиус круга: ";
	cin >> a;
	A.set(a);
	A.print();
	
#endif // CIRCLE


	system("pause");

}
