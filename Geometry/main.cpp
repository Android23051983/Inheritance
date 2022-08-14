#include<iostream>
#include<Windows.h>
#include<math.h>

using namespace std;

namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,

		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yelow = 0xEE,
		console_default = 0x07

	};
	enum Defaults
	{
		start_x_min = 100,
		start_y_min = 100,

		start_x_max = 800,
		start_y_max = 500,

		line_width_min = 1,
		line_width_man = 30,

		primary_size_min = 5,
		primary_size_max = 500,
		radius = 200

	};
#define SHAPE_TAKE_PARAMETERS Color color, unsigned int start_x, unsigned int start_y, unsigned int line_width
#define Triangle_TAKE_PARAMETERS double side_a, double side_b, double side_c
#define SHAPE_GIVE_PARAMETERS color, start_x, start_y, line_width
#define Triangle_GIVE_PARAMETERS side_a, side_b, side_c

	class Shape
	{
	protected:
		Color color;
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
	public:
		Color get_color()const
		{
			return color;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x < Defaults::start_x_min) start_x = Defaults::start_x_min;
			if (start_x > Defaults::start_x_max) start_x = Defaults::start_x_max;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y < Defaults::start_y_min)start_y = Defaults::start_y_min;
			if (start_y > Defaults::start_y_max)start_y = Defaults::start_y_max;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width > Defaults::line_width_man)line_width = Defaults::line_width_man;
			if (line_width < Defaults::line_width_min)line_width = Defaults::line_width_min;
			this->line_width = line_width;
		}

		Shape(SHAPE_TAKE_PARAMETERS) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;

		virtual void info()const
		{
			cout << "Площадь фигуры " << get_area() << endl;
			cout << "Периметр фигуры " << get_perimeter() << endl;
			draw();
		}
	};

	/*class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}

		void set_side(double side)
		{
			if (side < Defaults::primary_size_min)side = Defaults::primary_size_min;
			if (side > Defaults::primary_size_max)side = Defaults::primary_size_max;
			this->side = side;
		}

		Square(double side, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		~Square() {}

		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны:" << get_side() << endl;
			Shape::info();
		}
	};*/

	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		void set_width(double width)
		{
			if (width < Defaults::primary_size_min)width = Defaults::primary_size_min;
			if (width > Defaults::primary_size_max)width = Defaults::primary_size_max;
			this->width = width;

		}
		void set_height(double height)
		{
			if (height < Defaults::primary_size_min)height = Defaults::primary_size_min;
			if (height > Defaults::primary_size_max)height = Defaults::primary_size_max;
			this->height = height;
		}

		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_height(height);

		}

		~Rectangle() {}

		double get_area()const
		{
			return width * height;
		}
		double get_perimeter()const
		{
			return (width + height) * 2;
		}

		void draw()const
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					SetConsoleTextAttribute(hConsole, color);
					cout << "* ";
					SetConsoleTextAttribute(hConsole, Color::console_default);
				}
				cout << endl;
			}*/
			//Получчаем окно консоли
			HWND hwnd = GetConsoleWindow();
			//Получчаем контекст устройства для нашего окна консоли
			HDC hdc = GetDC(hwnd);
			//Создаём карандаш
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			//Создаём кисть:
			HBRUSH hBrush = CreateSolidBrush(color);
			//hPen и hBrush - это то, чем мы будем рисовать

			//Выбираем, чем и на чём будем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Когда мы выбрали чем, и на чем рисовать, рисуем фигуру

			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}

		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длинна" << get_width() << endl;
			cout << "Высота" << get_height() << endl;
			Shape::info();
		}

	};

	class Square :public Rectangle
	{

	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) : Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длинна стороны" << get_width() << endl;
			Shape::info();
		}
	};

	class Triangle :public Shape
	{
	protected:
		double side_a;
		double side_b;
		double side_c;
	public:
		double get_side_a()const
		{
			return side_a;
		}
		double get_side_b()const
		{
			return side_b;
		}
		double get_side_c()const
		{
			return side_c;
		}
		void set_side_a(double side_a)
		{
			this->side_a = side_a;
		}
		void set_side_b(double side_b)
		{
			this->side_b = side_b;
		}
		void set_side_c(float side_c)
		{
			this->side_c = side_c;
		}

		Triangle(Triangle_TAKE_PARAMETERS, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_side_a(side_a);
			set_side_b(side_b);
			set_side_c(side_c);

		}
		virtual ~Triangle() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;

		virtual void info()const
		{
			cout << typeid(*this).name() << endl;
			Shape::info();
		}
	};

	class Triangle_1 : public Triangle
	{

	protected:
		

	public:
		
		
		Triangle_1( Triangle_TAKE_PARAMETERS, SHAPE_TAKE_PARAMETERS) : Triangle(Triangle_GIVE_PARAMETERS, SHAPE_GIVE_PARAMETERS)
		{
		
		}


		~Triangle_1() {}

		double get_area()const
		{
			unsigned int p = (side_a + side_b + side_c) / 2;
			unsigned int area = sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
			return area;
		}
		double get_perimeter()const
		{
			return side_a + side_b + side_c;
		}


		double get_height()const
		{
			return 2 * get_area() / side_c;
		}

		void info()const
		{
			//cout << typeid(*this).name() << endl;
			//cout << "" << get_width() << endl;
			//cout << "" << get_height() << endl;
			cout << "Высота " << Triangle_1::get_height() << endl;
			Triangle::info();
			
		}

		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			//Получчаем контекст устройства для нашего окна консоли
			HDC hdc = GetDC(hwnd);
			//Создаём карандаш
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			//Создаём кисть:
			HBRUSH hBrush = CreateSolidBrush(color);
			//hPen и hBrush - это то, чем мы будем рисовать

			//Выбираем, чем и на чём будем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT poly[3] = { {start_x, start_y}, {start_x - side_c / 2, start_y + get_height()}, {start_x + side_c / 2, start_y + get_height()} };
			Polygon(hdc, poly, 3);
			
		}
	};

	class Triangle_2 : public Triangle
	{
	protected:

	public:


		Triangle_2(Triangle_TAKE_PARAMETERS, SHAPE_TAKE_PARAMETERS) : Triangle(Triangle_GIVE_PARAMETERS, SHAPE_GIVE_PARAMETERS)
		{

		}


	~Triangle_2() {}

		double get_area()const
		{
			unsigned int p = (side_a + side_b + side_c) / 2;
			unsigned int area = sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
			return area;
		}
		double get_perimeter()const
		{
			return side_a + side_b + side_c;
		}

		double Triangle_g()const
		{
			double g = sqrt((side_a * side_a) + (side_b * side_b));
			return g;
		}

	};

	class Ellipse : public Triangle_2
	{
		
	protected:
		unsigned int radius;

	public:

		unsigned int get_radius()const
		{
			return radius;
		}
		void set_radius(unsigned int radius)
		{
			this->radius = radius;
		}
	
		Ellipse(Triangle_TAKE_PARAMETERS, SHAPE_TAKE_PARAMETERS) : Triangle_2(Triangle_GIVE_PARAMETERS, SHAPE_GIVE_PARAMETERS)
		{

		}

		~Ellipse() {}
		double get_area()const
		{
			return Triangle_g() * 3.14;
		}
		double get_perimeter()const
		{
			return 2*3.14*(Triangle_g()/2);
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();//Получчаем окно консоли
			HDC hdc = GetDC(hwnd);//Получчаем контекст устройства для нашего окна консоли
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);//Создаём карандаш
			HBRUSH hBrush = CreateSolidBrush(color);//Создаём кисть:
			//hPen и hBrush - это то, чем мы будем рисовать

			//Выбираем, чем и на чём будем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			::Ellipse(hdc, start_x, start_y, start_x + side_c + Triangle_g(), start_y + side_a + Triangle_g());
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}

	};

	
}

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::console_blue, 0, 0, 1);
	Geometry::Square square(55, Geometry::Color::console_red, 600, 200, 5);
	/*cout << "Длинна стороны: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Площадь квадрата: " << square.get_perimeter() << endl;
	square.draw();*/
	square.info();
	square.draw();
	Geometry::Rectangle rect(100, 70, Geometry::Color::green, 1000, 100, 5);
	rect.info();
	rect.draw();
	Geometry::Triangle_1 tr(150, 150, 150, Geometry::Color::green, 900, 200, 5);
	tr.info();
	tr.draw();
	Geometry::Ellipse el(100, 141,100, Geometry::Color::green, 900, 400, 5);
	//cout << el.get_area() << endl;
	//cout << el.get_perimeter() << endl;
	el.draw();
	el.info();
	cin.get();
}