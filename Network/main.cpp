#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define REVERS_FILE
#define FORMATING_FILE
#define h "host 201-"
#define ha "hardvware ethernet"
#define fi "fixed-address"

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


#ifdef REVERS_FILE
	ofstream fout;
	fout.open("Copy_201 RAW.txt");
	ifstream fin(sz_filename);
	if (fin.is_open())
	{
		// TODO: читаем файл
		const int SIZE = 256; //Размер буфера чтения
		char buffer[SIZE] = {}; //Запись первого слова
		char buffer1[SIZE] = {};//Запись второго слова
		while (!fin.eof()) // eof() - End of file
		{
			fin >> buffer >> buffer1;
			fout << buffer1 << "\t\t" << buffer << endl;
			//cout << buffer1;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();
	fout.close();
#endif // REVERS_FILE
#ifdef FORMATING_FILE
	ofstream fout;
	fout.open("201.dhcpd");
	ifstream fin(sz_filename);
	int i = 1;
	if (fin.is_open())
	{
		// TODO: читаем файл
		const int SIZE = 256; //Размер буфера чтения
		char buffer[SIZE] = {}; //Запись первого слова
		char buffer1[SIZE] = {};//Запись второго слова
		while (!fin.eof()) // eof() - End of file
		{
			fin >> buffer >> buffer1;
			fout << h << i << endl;
			fout << "{" << endl;
			fout << "\t" << ha << "\t" << buffer1 << ";" << endl;
			fout << "\t" << fi << "\t\t" << buffer << ";" << endl;
			fout << "}" << endl;
			//fout << buffer1 << "\t\t" << buffer << endl;
			//cout << buffer1;
			int j = i;
			if (i == j)
			{
				i++;
			}
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();
	fout.close();
#endif // FORMATING_FILE

	
}