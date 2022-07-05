#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>


using namespace std;


//#define WRITE_TO_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	cout << "Hello files";
	std::ofstream fout; // создаем поток
	fout.open("File.txt", std::ios_base::app); //Открыть путь
	fout << "Hello files" << endl; // Используем поток
	fout.close();		   // после использования потока его обязательно нужно закрыть

	system("notepad File.txt");
#endif //WRITE_TO_FILE
	const int FILENAME_SIZE = 256;
	char sz_filename[FILENAME_MAX] = {};
	cout << "Введите имя файла:"; cin.getline(sz_filename, FILENAME_MAX);

	if (strstr(sz_filename, ".txt") == NULL)
	{
		strcat(sz_filename, ".txt");
		//ф-ция strcat(str1, str2) выполняет конкатенацию строк,
		//а именно, к содержимому str1 добавляет содержимое str2,
		//выводит ошибку
		//Runtime check failure #2 или Heap corruption detected
	
	}

	ifstream fin(sz_filename);
	if (fin.is_open())
	{
		// TODO: читаем файл
		const int SIZE = 256; //Размер буфера чтения
		char buffer[SIZE] = {};//Буфер чтения
		while (!fin.eof()) // eof() - End of file
		{
		
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
	
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();
	char sz_command[FILENAME_MAX] = "start notepad ";
	strcat(sz_command, sz_filename);
	system(sz_command); //запуск чего либо в новом 
}