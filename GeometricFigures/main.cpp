#include "Stdafx.h"

class Figure // �������, ����������� �����
{ 

public:

	//����� ����������� ������� �������� (������������) ������

	virtual void calc_Square() {};
	virtual void calc_Perimeter() {};
	//virtual void print() const = 0;
};

class Square: public Figure
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

	void calc_Perimeter()
	{
		cout << "��������: " << side * 4 << endl;
	}
	void calc_Square()
	{
		cout << "�������: " << side * side << endl;
	}

	void print()
	{
		cout << "������� ��������: " << this->side << endl;
	}
};


class Rectangle: public Figure
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
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Rectangle(float width, float height)
	{
		this->width = width;
		this->height = height;
		cout << "Constructor:\t\t" << this << endl;
	}
	~Rectangle()
	{
		cout << "Destructor: \t\t" << this << endl;
	}


	void calc_Perimeter()
	{
		cout << "��������: " << (height + width) * 2 << endl;
	}
	void calc_Square()
	{
		cout << "�������: " << height * width << endl;
	}

	
	void print()
	{
		cout << "������: " << this->height << "\n������: " << this->width << std::endl;
	}

};

class Triangle: public Figure
{
	float a, b, c;
public:
	float get_a()const
	{
		return a;
	}
	float get_b()const
	{
		return b;
	}
	float get_c()const
	{
		return c;
	}

	void set(float a, float b, float c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	Triangle()
	{
		this->a = 0;
		this->b = 0;
		this->c = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}

	Triangle(float a, float b, float c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		cout << "Constructor:\t\t" << this << endl;
	}

	~Triangle()
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	void calc_Perimeter()
	{
		cout << "��������: " << a + b + c << endl;
	}
	void calc_Square()
	{
		float p = (a + b + c)/2;
		cout << "�������: " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
	}

	void print() const
	{
		cout << "������� a: " << a << "\n������� b: " << b << "\n������� c: " << c << endl;
	}
};
class Circle: public Figure
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
		this->Pi = (float)3.14;
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
		cout << "������: " << this->radius << "\n��: " << this->Pi << endl;
	}

	void calc_Square()
	{
		cout << "������� �����: " << Pi * (radius * radius) << endl;
	}

	void calc_Perimeter()
	{
		cout << "����� ����������: " << 2 * radius * Pi << endl;
	}
};

//#define RECTANGLE
//#define SQUARE
#define TRIANGLE
//#define CIRCLE
//#define DELETE

void main()

{
	setlocale(LC_ALL, "");

	/*Figure** figure = new Figure* [4];
	cout << "Output of the program:\n";*/
#ifdef RECTANGLE
	cout << "\nFigure #1 (rectangle):" << endl;
	//cout << "�������..." << endl;
	//figure[0] = new Rectangle(5, 10); //������� ����������� �� ��������� 3, 4, 5
	//figure[0]->calc_Square();
	//figure[0]->calc_Perimeter();
	Rectangle A;
	A.print();
	A.set(5, 10);
	A.print();
	A.calc_Perimeter();
	A.calc_Square();
#endif // RECTANGLE

#ifdef SQUARE
	cout << "\nFigure #2 (square):" << endl;
	//cout << "�������..." << endl;
	//figure[1] = new Square(5); //������� ����������� �� ��������� 3, 4, 5
	//figure[1]->calc_Square();
	//figure[1]->calc_Perimeter();
	Square A;
	A.print();
	A.set(5);
	A.print();
	A.calc_Perimeter();
	A.calc_Square();
#endif // SQUARE

#ifdef CIRCLE
	cout << "\nFigure #3 (circle):" << endl;
	//cout << "�������..." << endl;
	//figure[2] = new Circle(3); //������� ����������� �� ��������� 3, 4, 5
	//figure[2]->calc_Square();
	//figure[2]->calc_Perimeter();
	Circle A;
	A.print();
	A.set(3);
	A.print();
	A.calc_Perimeter();
	A.calc_Square();
#endif // CIRCLE
#ifdef TRIANGLE
	cout << "\nFigure #4 (triangle):" << endl;
	//cout << "�������..." << endl;
	//figure[3] = new Triangle(3, 4, 5); //������� ����������� �� ��������� 3, 4, 5
	//figure[3]->calc_Square();
	//figure[3]->calc_Perimeter();
	Triangle A;
	A.print();
	A.set(3,4,5);
	A.print();
	A.calc_Perimeter();
	A.calc_Square();
#endif // TRIANGLE

#ifdef DELETE
	delete figure[0];
	delete figure[1];
	delete figure[2];
	delete figure[3];
	delete[] figure;
#endif // DELETE
	
	system("pause");

}
