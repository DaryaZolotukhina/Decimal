/* 6 ���������� � ���������� ������������ ������� � ������: ��������� �����, ����� ������, �������,
�����, ���� ���������� �� ������, ������� ��������, ���������� �����, ���������� ������������ ���� � ������,
���������� ������� ���� � �����, ���������, ��������. ����� �� ������ ������, �������, ���� ����������� � ������.*/
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
	// ��������� �����
	__int32 pers_number;
	// ����� ������
	__int32 depart_number;
	// �������
	string surname;
	// �����
	__int32 salary;
	// ���� �����������
	string date;
	// ������� ��������
	__int32 percent;
	// ���������� �����
	__int32 tax;
	// ���������� ������������ ����
	__int32 days_worked;
	// ���������� ���� � ������
	__int32 days_month;
	// ���������
	__int32 accured;
	// ��������
	__int32 withheld;


	// ����������� �� ���������
	Worker();


	// ��������� ��������� "��������"
	Worker ChangeWorker(Worker &result);

	// ������������� �������� ��������� ��� ��������� "��������"
	Worker& operator = (Worker c);
};



