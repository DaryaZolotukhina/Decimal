#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template <class Type>
Type InputNumber(Type min, Type max, string message)
{
	Type n;
	do
	{
		cout << message ;
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "Неправильный ввод !!  Повторите ввод!\n";
			cin.clear();  // восстанавливает поток если он в ошибочном сосотянии
			cin.sync();   // очищает поток от имеющихся символов
			cout << message  ;
			getchar();
			getchar();
		}
	} while ((n < min) || (n > max));
	return n;
}

// ввод информации
string InputInformation(string messge)
{
	string a;
	cout << messge ;
	cin >> a;
	return a;
}

// проверка символа на корректность в имени файла
bool CorrectSymbol(char c)
{
	switch (c)
	{
	case '.':
	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
	case '/':
		return false;
	default:
		return true;
	}
}


// проверка имени файла на коректность
bool CorrectName(string name)
{
	int i = 0;
	bool goodsm = true;
	for (int i = 0; (i < name.length() && goodsm);i++)
		goodsm = CorrectSymbol(name[i]);
	return goodsm;
}

// ввод имени файла
string InputFileName()
{

	string filename;
	do
	{
		cout << "Введите имя файла:  ";
		cin >> filename;
		if (filename.length() > 35)
			filename.erase(filename.begin(), filename.begin() + 35);
		if (CorrectName(filename))
		{
			filename = filename + ".txt";
			break;
		}
		else
			cout << "Неверное имя файла\n";
	} while (true);

	return filename;
}

// чтение строки из бинарного файла
string StringFromBinFile(ifstream& in)
{
	string result;
	size_t len_name;
	in.read((char*)&len_name, sizeof(len_name)); // чтение длины записанной строки
	char * buf = new char[len_name];         // Выделение буфера для чтения
	in.read(buf, len_name);// Чтение 
	result = buf;                       // Присвоение считанной строки 
	delete[]buf;               // Освобождение памяти

	return result;
}

// запись строки в бинарный файл
void StringInBinFile(ofstream& os, string str)
{
	size_t len_name = str.length() + 1;  // длина 
	os.write((char*)&len_name, sizeof(int)); // запись длины
	os.write(str.c_str(), len_name);  // запись информации
}




