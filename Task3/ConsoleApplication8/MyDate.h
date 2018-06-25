#pragma once
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
//using namespace std;

//подтип дата
class MyDate {

	// проверка является ли год високосным
	bool IsLeap(int year);

	// проверка даты на корректность
	bool CorrectDate(int day, int month, int year, string &message);
public:
	// день
	int day;
	// месяц
	int month;
	// год
	int year;

	// конструктор по умолчанию
	MyDate();

	// ввод даты с консоли
	void InputDate();

	// перевод даты в строку (для последующей записи в файл)
	string ToString();

	//извлечение структуры "дата" из строки 
	// Формат:
	// день месяц год
	MyDate FromString(string str);

	// перегруженный оператор равенства
	bool operator == (const MyDate &c);

	// конструктор копирования
	MyDate& operator = (MyDate c);

	// перегруженный оператор больше
	bool operator > (const MyDate &c);

	// перегруженные оператор меньше
	bool operator < (const MyDate &c);

};