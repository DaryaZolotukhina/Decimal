/* 6 Информация о сотруднике представлена записью с полями: табельный номер, номер отдела, фамилия,
оклад, дата поступлния на работу, процент надбавки, подоходный налог, количество отработанных дней в месяце, 
количество рабочих дней в мсяце, начислено, удержано. Поиск по номеру отдела, фамилии, дате поступления и окладу.*/
#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "HelpUtils.h"
#include "Operation.cpp"
#include "Company.cpp"
#include "MyDate.cpp"
using namespace std;




int Menu()
{
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Просмотреть табель" << endl;
	cout << "2 - Добавить элемент" << endl;
	cout << "3 - Удалить элемент" << endl;
	cout << "4 - Изменить элемент" << endl;
	cout << "5 - Линейный поиск" << endl;
	cout << "6 - Двоичный поиск" << endl;
	cout << "7 - Сортировка" << endl;
	cout << "8 - Вычисление заработной платы" << endl;
	cout << "0 - Выход" << endl;
	int n = InputNumber(0, 9, "Ваш выбор: ");
	cout << "\n";
	return n;
}

void ChangeInputData()
{
		string filename_workers = "workers.dat";
		Task<Worker> task;
		bool(*compare)(Worker, Worker) = NULL;
		bool(*sort)(Worker, Worker) = NULL;
		Worker elem;
		vector<Worker> subset;
		Worker search_elem;
		int numb;
		task.ReadFromFile(ReadWorkerFile, filename_workers);
		while (1)
		{
			int n = Menu();
			switch (n)
			{
			case 1:
				if (task.Is_empty())
					cout << "Нет данных";
				else
				task.OutputScreen(task.vect, OutputScreenWorker, OutputScreenHeaderWorker);
				break;
			case 2:
				task.Add(InputScreenWorker());
				task.OutputFile(task.vect, WriteWorkerToFile, filename_workers);
				break;

			case 3:
				if (task.Is_empty())
					cout << "Нет данных";
				else
				{
					task.OutputScreen(task.vect, OutputScreenWorker, OutputScreenHeaderWorker);
					task.Remove(InputNumber(0, task.size(), "\nВведите номер удаляемого эл-та (0 - если передумали удалять): "));
					task.OutputFile(task.vect, WriteWorkerToFile, filename_workers);
				}
				break;
			case 4:
				if (task.Is_empty())
					cout << "Нет данных";
				else
					{
						task.OutputScreen(task.vect, OutputScreenWorker, OutputScreenHeaderWorker);
						int numb = InputNumber(0, task.size(), "Введите номер изменяемого эл-та (0 - если передумали изменять): ");
						if (numb != 0)
						{
							task.vect[numb - 1] = elem.ChangeWorker(task.vect[numb - 1]);
							task.OutputFile(task.vect, WriteWorkerToFile, filename_workers);
							cout << "Элемент изменен!" << endl;
						}
					}
				break;

			case 5:
				numb = InputNumber(1, 11, "Выберите тип поиска:\n 1 - по табельному номеру\n 2 - по номеру отдела\n 3 - по фамилии\n 4 - по дате поступления\n 5 - по окладу\n 6 - по процентц надбавки\n 7 - по опдоходному налогу\n 8 - по количеству отработанных дней в месяце\n 9 - по количеству рабочих дней в месяце\n 10 - по удержанной сумме\n 11 - по начисленной сумме\nВаш выбор: ");
				search_elem = InputChangeTypeSearch(numb);
				switch (numb)
				{
				case 1:
					compare = SearchElementPersNumber;
					break;
				case 2:
					compare = SearchElementDepart;
					break;
				case 3:
					compare = SearchElementSurname;
					break;
				case 4:
					compare = SearchElementDate;
					break;
				case 5:
					compare = SearchElementSalary;
					break;
				case 6:
					compare = SearchElementPercent;
					break;
				case 7:
					compare = SearchElementTax;
					break;
				case 8:
					compare = SearchElementDaysWorked;
					break;
				case 9:
					compare = SearchElementDaysMonth;
					break;
				case 10:
					compare = SearchElementWithheld;
					break;
				case 11:
					compare = SearchElementAccured;
					break;
				}
				subset = task.LinearySearch(search_elem, compare);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputScreenWorker, OutputScreenHeaderWorker);
				else
					cout << "Элементы не найдены" << endl;
				break;

			case 6:
				numb = InputNumber(1, 11, "Выберите тип поиска:\n 1 - по табельному номеру\n 2 - по номеру отдела\n 3 - по фамилии\n 4 - по дате поступления\n 5 - по окладу\n 6 - по процентц надбавки\n 7 - по опдоходному налогу\n 8 - по количеству отработанных дней в месяце\n 9 - по количеству рабочих дней в месяце\n 10 - по удержанной сумме\n 11 - по начисленной сумме\nВаш выбор: ");
				search_elem = InputChangeTypeSearch(numb);
				switch (numb)
				{
				case 1:
					compare = SearchElementPersNumber;
					sort= SortePersNumber;
					break;
				case 2:
					compare = SearchElementDepart;
					sort = SorteDepart;
					break;
				case 3:
					compare = SearchElementSurname;
					sort = SorteSurname;
					break;
				case 4:
					compare = SearchElementDate;
					sort = SorteDate;
					break;
				case 5:
					compare = SearchElementSalary;
					sort = SorteSalary;
					break;
				case 6:
					compare = SearchElementPercent;
					sort = SortePercent;
					break;
				case 7:
					compare = SearchElementTax;
					sort = SorteTax;
					break;
				case 8:
					compare = SearchElementDaysWorked;
					sort = SorteDaysWorked;
					break;
				case 9:
					compare = SearchElementDaysMonth;
					sort = SorteDaysMonth;
					break;
				case 10:
					compare = SearchElementWithheld;
					sort = SorteWithheld;
					break;
				case 11:
					compare = SearchElementAccured;
					sort = SorteAccured;
					break;
				}
				subset = task.BinarySearch(search_elem, sort, compare);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputScreenWorker, OutputScreenHeaderWorker);
				else
					cout << "Элементы не найдены" << endl;
				break;
			case 7:			
				numb = InputNumber(1, 11, "Выберите тип поиска:\n 1 - по табельному номеру\n 2 - по номеру отдела\n 3 - по фамилии\n 4 - по дате поступления\n 5 - по окладу\n 6 - по процентц надбавки\n 7 - по опдоходному налогу\n 8 - по количеству отработанных дней в месяце\n 9 - по количеству рабочих дней в месяце\n 10 - по удержанной сумме\n 11 - по начисленной сумме\nВаш выбор: ");
				switch (numb)
				{
				case 1:
					sort = SortePersNumber;
					break;
				case 2:
					sort = SorteDepart;
					break;
				case 3:
					sort = SorteSurname;
					break;
				case 4:
					sort = SorteDate;
					break;
				case 5:
					sort = SorteSalary;
					break;
				case 6:
					sort = SortePercent;
					break;
				case 7:
					sort = SorteTax;
					break;
				case 8:
					sort = SorteDaysWorked;
					break;
				case 9:
					sort = SorteDaysMonth;
					break;
				case 10:
					sort = SorteWithheld;
					break;
				case 11:
					sort = SorteAccured;
					break;
				}
				subset = task.Sort(sort);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputScreenWorker, OutputScreenHeaderWorker);
				else
					cout << "Элементы не найдены" << endl;
				break;
			case 8:
				numb = InputNumber(1, 3, "Выберите период:\n 1 - квартал\n 2 - полугодие\n 3 - год\nВаш выбор: ");
				OutputScreenHeaderSumSalary();
				task.OutputScreenSalary(task.SumSalary(numb));
				break;
			default:
				cout << "Выход " << endl; exit(0);
				break;

			}
		}
}

void main()
{
	system("chcp 1251");
	ChangeInputData();
}