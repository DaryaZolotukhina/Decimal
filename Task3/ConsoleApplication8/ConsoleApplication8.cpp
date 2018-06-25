/* 6 ���������� � ���������� ������������ ������� � ������: ��������� �����, ����� ������, �������,
�����, ���� ���������� �� ������, ������� ��������, ���������� �����, ���������� ������������ ���� � ������, 
���������� ������� ���� � �����, ���������, ��������. ����� �� ������ ������, �������, ���� ����������� � ������.*/
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
	cout << " --------------------����---------------------  " << endl;
	cout << "1 - �������� �������" << endl;
	cout << "2 - ������� �������" << endl;
	cout << "3 - �������� �������" << endl;
	cout << "4 - ����� �� �����" << endl;
	cout << "5 - ��������� � ���� " << endl;
	cout << "6 - �������� �����" << endl;
	cout << "7 - �������� �����" << endl;
	cout << "8 - ������� ����������� �� �����" << endl;
	cout << "9 - ��������� ������������ � ����" << endl;
	cout << "0 - �����" << endl;
	int n = InputNumber(0, 9, "��� �����: ");
	cout << "\n";
	return n;
}

void ChangeInputData()
{
	Task<Worker> task;
	bool change = true;
	cout << " --------------------����---------------------  " << endl;
	cout << "1 - ���������� ���������� � �������" << endl;
	cout << "2 - ���������� ���������� �� ����� " << endl;
	cout << "0 - �����" << endl;
	int changemenu = InputNumber(0, 2, "��� �����: ");
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
				task.Remove(InputNumber(0, task.size(), "������� ����� ���������� ��-�� (0 - ���� ���������� �������): "));
				break;

			case 3:
				OutputScreen(task.vect, OutputScreenWorker);
				numb = InputNumber(0, task.size(), "������� ����� ����������� ��-�� (0 - ���� ���������� ��������): ");
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
				numb = InputNumber(1, 4, "�������� ��� ������:\n 1 - �� ������ ������\n 2 - �� �������\n 3 - �� ���� �����������\n 4 - �� ������ \n��� �����: ");
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
					cout << "�������� �� �������" << endl;
				break;

			case 7:
				numb = InputNumber(1, 4, "�������� ��� ������:\n 1 - �� ������ ������\n 2 - �� �������\n 3 - �� ���� �����������\n 4 - �� ������ \n��� �����: ");
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
					cout << "�������� �� �������" << endl;
				break;


			case 8:
				OutputScreen(subset, OutputScreenWorker);
				break;

			case 9:
				OutputFile(subset, ToString);
				break;


			default:
				cout << "����� " << endl; exit(0);
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