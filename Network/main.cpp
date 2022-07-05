#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");
	
	const int FILENAME_SIZE = 256;
	char sz_filename[FILENAME_MAX] = {};
	cout << "Введите имя файла:"; cin.getline(sz_filename, FILENAME_MAX);

	if (strstr(sz_filename, ".txt") == NULL)
	{
		strcat(sz_filename, ".txt");
	}


	ifstream fin(sz_filename);
	if (fin.is_open())
	{
		// TODO: читаем файл
		const int SIZE = 256; //Размер буфера чтения
		char buffer[SIZE] = {};
		while (!fin.eof()) // eof() - End of file
		{
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
			//cout << buffer1;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();
	
}