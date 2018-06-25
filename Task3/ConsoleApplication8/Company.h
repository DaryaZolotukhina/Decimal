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
#include "MyDate.h"
//using namespace std;

class Worker {
public:
	// табельный номер
	__int32 pers_number;
	// номер отдела
	__int32 depart_number;
	// фамилия
	string surname;
	// оклад
	__int32 salary;
	// дата поступления
	string date;
	// процент надбавки
	__int32 percent;
	// подоходный налог
	__int32 tax;
	// количество отработанных дней
	__int32 days_worked;
	// количество дней в месяце
	__int32 days_month;
	// начислено
	__int32 accured;
	// удержано
	__int32 withheld;


	// конструктор по умолчанию
	Worker();


	// изменение структуры "компания"
	Worker ChangeWorker(Worker &result);

	// перегруженный оператор равенства для структуры "компания"
	Worker& operator = (Worker c);
};



