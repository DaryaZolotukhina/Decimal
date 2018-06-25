/* 6 Информация о сотруднике представлена записью с полями: табельный номер, номер отдела, фамилия,
оклад, дата поступлния на работу, процент надбавки, подоходный налог, количество отработанных дней в месяце,
количество рабочих дней в мсяце, начислено, удержано. Поиск по номеру отдела, фамилии, дате поступления и окладу.*/
#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
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

class Worker {
public:
	// табельный номер
	int pers_number;
	// номер отдела
	int depart_number;
	// фамилия
	string surname;
	// оклад
	int salary;
	// дата поступления
	MyDate date;
	// процент надбавки
	int percent;
	// подоходный налог
	int tax;
	// количество отработанных дней
	int days_worked;
	// количество дней в месяце
	int days_month;
	// начислено
	int accured;
	// удержано
	int withheld;


	// конструктор по умолчанию
	Worker();


	// изменение структуры "компания"
	Worker ChangeWorker(Worker &result);

	// перегруженный оператор равенства для структуры "компания"
	Worker& operator = (Worker c);
};



