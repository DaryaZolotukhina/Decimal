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
using namespace std;




int Menu()
{
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Добавить элемент" << endl;
	cout << "2 - Удалить элемент" << endl;
	cout << "3 - Изменить элемент" << endl;
	cout << "4 - Вывод на экран" << endl;
	cout << "5 - Сохранить в файл " << endl;
	cout << "6 - Линейный поиск" << endl;
	cout << "7 - Двоичный поиск" << endl;
	cout << "8 - Вывести подможество на экран" << endl;
	cout << "9 - Сохранить подмножество в файл" << endl;
	cout << "0 - Выход" << endl;
	int n = InputNumber(0, 9, "Ваш выбор: ");
	cout << "\n";
	return n;
}

void ChangeInputData()
{
	Task<Worker> task;
	bool change = true;
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Заполнение контейнера с консоли" << endl;
	cout << "2 - Заполнение контейнера из файла " << endl;
	cout << "0 - Выход" << endl;
	int changemenu = InputNumber(0, 2, "Ваш выбор: ");
	switch (changemenu)
	{
	case 1:
		task.ReadFromScreen(InputScreenWorker);
		break;

	case 2:
		change = task.ReadFromFile(ReadFromString);
		break;

	default:
		change = false;
		break;
	}
	if (change)
	{
		bool(*compare)(Worker, Worker) = NULL;
		bool(*sort)(Worker, Worker) = NULL;
		Worker elem;
		vector<Worker> subset;
		Worker search_elem;
		int numb;
		while (1)
		{
			int n = Menu();
			switch (n)
			{
			case 1:
				task.Add(InputScreenWorker());
				break;

			case 2:
				OutputScreen(task.vect, OutputScreenWorker);
				task.Remove(InputNumber(0, task.size(), "Введите номер удаляемого эл-та (0 - если передумали удалять): "));
				break;

			case 3:
				OutputScreen(task.vect, OutputScreenWorker);
				numb = InputNumber(0, task.size(), "Введите номер изменяеиого эл-та (0 - если передумали изменять): ");
				if (numb != 0)
					task.vect[numb - 1] = elem.ChangeWorker(task.vect[numb - 1]);
				break;

			case 4:
				OutputScreen(task.vect, OutputScreenWorker);
				break;

			case 5:
				OutputFile(task.vect, ToString);
				break;

			case 6:
				numb = InputNumber(1, 4, "Выберите тип поиска:\n 1 - по номеру отдела\n 2 - по фамилии\n 3 - по дате поступления\n 4 - по окладу \nВаш выбор: ");
				search_elem = InputChangeTypeSearch(numb);
				switch (numb)
				{
				case 1:
					compare = SearchElementDepart;
					break;
				case 2:
					compare = SearchElementSurname;
					break;
				case 3:
					compare = SearchElementDate;
					break;
				case 4:
					compare = SearchElementSalary;
					break;
				}
				subset = task.LinearySearch(search_elem, compare);
				if (subset.size() != 0)
					OutputScreen(subset, OutputScreenWorker);
				else
					cout << "Элементы не найдены" << endl;
				break;

			case 7:
				numb = InputNumber(1, 4, "Выберите тип поиска:\n 1 - по номеру отдела\n 2 - по фамилии\n 3 - по дате поступления\n 4 - по окладу \nВаш выбор: ");
				search_elem = InputChangeTypeSearch(numb);
				switch (numb)
				{
				case 1:
					compare = SearchElementDepart;
					sort = SorteDepart;
					break;
				case 2:
					compare = SearchElementSurname;
					sort = SorteSurname;
					break;
				case 3:
					compare = SearchElementDate;
					sort = SorteDate;
					break;
				case 4:
					compare = SearchElementSalary;
					sort = SorteSalary;
					break;
				}
				subset = task.BinarySearch(search_elem, sort, compare);
				if (subset.size() != 0)
					OutputScreen(subset, OutputScreenWorker);
				else
					cout << "Элементы не найдены" << endl;
				break;


			case 8:
				OutputScreen(subset, OutputScreenWorker);
				break;

			case 9:
				OutputFile(subset, ToString);
				break;


			default:
				cout << "Выход " << endl; exit(0);
				break;

			}
		}
	}
	else
	system("pause");
}

void main()
{
	setlocale(LC_ALL, "Russian");
	ChangeInputData();
}