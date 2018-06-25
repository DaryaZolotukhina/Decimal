#pragma once
#include <stdio.h>
#include <conio.h>
#include <sstream>
#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "Company.h"

//подсчет начисленной суммы
int CalcSalary(Worker n)
{
	return (n.salary * n.days_worked / n.days_month + (n.percent/100 * n.salary) - (n.tax/100 * n.salary) - n.withheld);
}

//подсчет зарплаты
int CalcSumSalary(Worker n)
{
	return (n.salary + ((n.percent * n.salary) / 100) - ((n.tax * n.salary) / 100));
}
	// конструктор по умолчанию
Worker::Worker()
	{
		__int32 pers_number = 0;
		__int32 depart_number = 0;
		string surname = "";
		__int32 salary = 0;
		string date;
		__int32 percent = 0;
		__int32 tax = 0;
		__int32 days_worked = 0;
		__int32 days_month = 0;
		__int32 withheld = 0;
		__int32 accured = 0;
	}


	// изменение структуры "компания"
Worker Worker::ChangeWorker(Worker &result)
{
	MyDate d;
	if (InputNumber(0, 1, "Вы хотите изменить табельный номер " + to_string(result.pers_number) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.pers_number = InputNumber(0, 1000000, "Введите новый табельный номер (0 - 1000000): ");
	if (InputNumber(0, 1, "Вы хотите изменить номер отдела " + to_string(result.depart_number) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.depart_number = InputNumber(0, 1000000, "Введите новый номер отдела (0 - 1000000): ");
	if (InputNumber(0, 1, "Вы хотите изменить фамилию " + result.surname + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.surname = InputInformation("Введите новую фамилию: ");
	if (InputNumber(0, 1, "Вы хотите изменить оклад" + to_string(result.salary) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
		result.salary = InputNumber(0, 1000000, "Введите новый оклад (0 - 1000000): ");
	if (InputNumber(0, 1, "Вы хотите изменить дату поступления на работу (0 - нет, 1 - да) \nВыш выбор: ") == 1)
	{
		d.InputDate();
		result.date = d.ToString();
	}
		if (InputNumber(0, 1, "Вы хотите изменить процент надбавки" + to_string(result.percent) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.percent = InputNumber(0, 25, "Введите новый процент надбавки (0 - 25): ");
		if (InputNumber(0, 1, "Вы хотите изменить подоходный налог" + to_string(result.tax) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.tax = InputNumber(0, 25, "Введите новый подоходный налог (0 - 25): ");
		if (InputNumber(0, 1, "Вы хотите изменить количество отработанных дней в месяце" + to_string(result.days_worked) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.days_worked = InputNumber(0, 31, "Введите новое количество отработанных дней в месяце (0 - 1000000): ");
		if (InputNumber(0, 1, "Вы хотите изменить количество рабочих дней в месяце" + to_string(result.days_month) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.days_month = InputNumber(0, 31, "Введите новое количество рабочих дней в месяце (0 - 1000000): ");
		if (InputNumber(0, 1, "Вы хотите изменить удержанную сумму" + to_string(result.withheld) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.withheld = InputNumber(0, (result.salary/2), "Введите новую удержанную сумму (не более половины оклада): ");
		result.accured = CalcSalary(result);
		return result;
	}

	// перегруженный оператор равенства для структуры "компания"
Worker& Worker::operator = (Worker c)
	{
		pers_number = c.pers_number;
		depart_number = c.depart_number;
		surname = c.surname;
		salary = c.salary;
		date = c.date;
		percent = c.percent;
		tax = c.tax;
		days_worked = c.days_worked;
		days_month = c.days_month;
		accured = c.accured;
		withheld = c.withheld;

		return (*this);
	}


// функция ввода структуры "компания" с консоли
Worker InputScreenWorker()
{
	MyDate k;
	Worker c;
	c.pers_number = InputNumber(0, 1000000, "Введите табельный номер (0 - 1000000): ");
	c.depart_number = InputNumber(0, 1000000, "Введите номер отдела (0 - 1000000): ");
	c.surname = InputInformation("Введите фамилию: ");
	c.salary = InputNumber(0, 1000000, "Введите оклад (0 - 1000000): ");
	k.InputDate();
	c.date = k.ToString();
	c.percent = InputNumber(0, 25, "Введите процент надбавки (0 - 25): ");
	c.tax = InputNumber(0, 25, "Введите подоходный налог (0 - 25): ");
	c.days_worked = InputNumber(0, 31, "Введите количество отработанных дней в месяце (0 - 31): ");
	c.days_month = InputNumber(0, 31, "Введите количество рабочих дней в месяце (0 - 31): ");
	c.withheld = InputNumber(0, (c.salary / 2), "Введите удержанную сумму (не более половины оклада): ");
	c.accured= CalcSalary(c);
	return c;
}

// функция вывода структуры "компания" на консоль
void OutputScreenWorker(Worker c)
{
	cout << setw(11) << setiosflags(ios::left) << c.pers_number << "|";
	cout << setw(12) << setiosflags(ios::left) << c.depart_number << "|";
	cout << setw(10) << setiosflags(ios::left) << c.surname << "|";
	cout << setw(5) << setiosflags(ios::left) << c.salary << "|";
	cout << setw(10) << setiosflags(ios::left) << c.date << "|";
	cout << setw(10) << setiosflags(ios::left) << c.percent << "|";
	cout << setw(7) << setiosflags(ios::left) << c.tax << "|";
	cout << setw(10) << setiosflags(ios::left) << c.days_worked << "|";
	cout << setw(8) << setiosflags(ios::left) << c.days_month << "|";
	cout << setw(8) << setiosflags(ios::left) << c.withheld << "|";
	cout << setw(9) << setiosflags(ios::left) << c.accured << endl;
	cout << endl;
}

// запись в бинарный файл
void WriteWorkerToFile(Worker a, ofstream& os)
{
	os.write((char*)&a.pers_number, sizeof(__int32));
	os.write((char*)&a.depart_number, sizeof(__int32));
	StringInBinFile(os, a.surname);
	os.write((char*)&a.salary, sizeof(__int32));
	StringInBinFile(os, a.date);
	os.write((char*)&a.percent, sizeof(__int32));
	os.write((char*)&a.tax, sizeof(__int32));
	os.write((char*)&a.days_worked, sizeof(__int32));
	os.write((char*)&a.days_month, sizeof(__int32));
	os.write((char*)&a.withheld, sizeof(__int32));
	os.write((char*)&a.accured, sizeof(__int32));
}

// считывание из бинарного файла
Worker ReadWorkerFile(ifstream& in)
{
	Worker a;

	in.read((char*)&a.pers_number, sizeof(__int32));
	in.read((char*)&a.depart_number, sizeof(__int32));
	a.surname = StringFromBinFile(in);
	in.read((char*)&a.salary, sizeof(__int32));
	a.date = StringFromBinFile(in);
	in.read((char*)&a.percent, sizeof(__int32));
	in.read((char*)&a.tax, sizeof(int));
	in.read((char*)&a.days_worked, sizeof(__int32));
	in.read((char*)&a.days_month, sizeof(__int32));
	in.read((char*)&a.withheld, sizeof(__int32));
	in.read((char*)&a.accured, sizeof(__int32));

	return a;
}
// вывод на консоль заголовка
void OutputScreenHeaderWorker()
{
	cout << setw(4) << setiosflags(ios::left) << "№" << "|";
	cout << setw(11) << setiosflags(ios::left) << "Табельный №" << "|";
	cout << setw(12) << setiosflags(ios::left) << "Номер отдела" << "|";
	cout << setw(10) << setiosflags(ios::left) << "Фамилия" << "|";
	cout << setw(5) << setiosflags(ios::left) << "Оклад" << "|";
	cout << setw(10) << setiosflags(ios::left) << "Дата" << "|";
	cout << setw(10) << setiosflags(ios::left) << "Надбавка %" << "|";
	cout << setw(7) << setiosflags(ios::left) << "Налог %" << "|";
	cout << setw(10) << setiosflags(ios::left) << "Отраб. дни" << "|";
	cout << setw(8) << setiosflags(ios::left) << "Раб. дни" << "|";
	cout << setw(8) << setiosflags(ios::left) << "Удержано" << "|";
	cout << setw(9) << setiosflags(ios::left) << "Начислено" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}

// поиск равного элемента по выбранному критерию
bool SearchElementPersNumber(Worker n, Worker m)
{
	return n.pers_number == m.pers_number;
}
bool SearchElementDepart(Worker n, Worker m)
{
	return (n.depart_number == m.depart_number);
}

bool SearchElementSurname(Worker n, Worker m)
{
	return (n.surname == m.surname);
}

bool SearchElementDate(Worker n, Worker m)
{
	return (n.date == m.date);
}
bool SearchElementSalary(Worker n, Worker m)
{
	return (n.salary == m.salary);
}
bool SearchElementPercent(Worker n, Worker m)
{
	return n.percent == m.percent;
}
bool SearchElementTax(Worker n, Worker m)
{
	return n.tax == m.tax;
}
bool SearchElementDaysWorked(Worker n, Worker m)
{
	return n.days_worked == m.days_worked;
}
bool SearchElementDaysMonth(Worker n, Worker m)
{
	return n.days_month == m.days_month;
}
bool SearchElementAccured(Worker n, Worker m)
{
	return n.accured == m.accured;
}
bool SearchElementWithheld(Worker n, Worker m)
{
	return n.withheld == m.withheld;
}


// ввод критерия поиска в зависимости от выбранного типа 
Worker InputChangeTypeSearch(int type_search)
{
	MyDate d;
	Worker result;
	switch (type_search)
	{
	case 1:
		result.pers_number = InputNumber(0, 1000000, "Введите табельный номер (0 - 1000000): ");
		return result;
	case 2:
		result.depart_number = InputNumber(0, 1000000, "Введите номер отдела (0 - 1000000): ");
		return result;
	case 3:
		result.surname = InputInformation("Введите фамилию: ");
		return result;
	case 4:
		d.InputDate();
		result.date = d.ToString();
		return result;
	case 5:
		result.salary = InputNumber(0, 1000000, "Введите оклад (0 - 1000000): ");
		return result;
	case 6:
		result.percent = InputNumber(0, 25, "Введите процент надбавки (0 - 25): ");
		return result;
	case 7:
		result.tax = InputNumber(0, 25, "Введите подоходный налог (0 - 25): ");
		return result;
	case 8:
		result.days_worked = InputNumber(0, 31, "Введите количество отработанных дней в месяце (0 - 31): ");
		return result;
	case 9:
		result.days_month = InputNumber(0, 31, "Введите количество рабочих дней в месяце (0 - 31): ");
		return result;
	case 10:
		result.withheld = InputNumber(0, 1000000, "Введите удержанную сумму (0 - 1000000): ");
		return result;
	case 11:
		result.accured = InputNumber(0, 1000000, "Введите начисленную сумму (0 - 1000000): ");
		return result;
	default:
		throw 0;
	}
}

// сравнения структур в зависимости от выбранного поля для сортировки
bool SortePersNumber(Worker n, Worker m)
{
	return n.pers_number > m.pers_number;
}
bool SorteDepart(Worker n, Worker m)
{
	return n.depart_number > m.depart_number;
}
bool SorteSurname(Worker n, Worker m)
{
	return n.surname > m.surname;
}
bool SorteDate(Worker n, Worker m)
{
	return n.date > m.date;
}
bool SorteSalary(Worker n, Worker m)
{
	return n.salary > m.salary;
}
bool SortePercent(Worker n, Worker m)
{
	return n.percent > m.percent;
}
bool SorteTax(Worker n, Worker m)
{
	return n.tax > m.tax;
}
bool SorteDaysWorked(Worker n, Worker m)
{
	return n.days_worked > m.days_worked;
}
bool SorteDaysMonth(Worker n, Worker m)
{
	return n.days_month > m.days_month;
}
bool SorteAccured(Worker n, Worker m)
{
	return n.accured > m.accured;
}
bool SorteWithheld(Worker n, Worker m)
{
	return n.withheld > m.withheld;
}
