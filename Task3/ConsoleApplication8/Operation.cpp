#include "Operation.h"
#include <stdio.h>
#include <conio.h>
#include <sstream>
#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>

template <class Type> 
Task<Type>::Task() {}

template <class Type>
Task<Type>::~Task() {}

	// �������� ��������
template <class Type>
void Task<Type>::Remove(int numb)
	{
		if (numb != 0)
			vect.erase(vect.begin() + numb - 1);
	}

	// ���������� ��������
template <class Type>
void Task<Type>::Add(Type &elem)
	{
		vect.push_back(elem);
	}

	//������ �������
template <class Type>
int  Task<Type>::size()
	{
		return vect.size();
	}

	// �������� �� �������
template <class Type>
bool Task<Type>::Is_empty()
	{
		return (vect.size() == 0);
	}

	// �������� �����
	// bool(*Equal)(Type, Type) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � �������
template <class Type>
vector<Type> Task<Type>::LinearySearch(Type search_elem, bool(*Equal)(Type, Type))
	{
		vector<Type> NewVect;
		for (auto iter = vect.begin(); iter != vect.end(); iter++)
		{
			if (Equal(search_elem, *iter))
				NewVect.push_back(*iter);

		}

		return NewVect;
	}

	// �������� �����
	// int(*Compare)(Type, Type) - ��������� �� �������, ������� ���������� ������� ��-� � �������
	// bool(*Equal)(Type, Type) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � �������
template <class Type>
vector<Type> Task<Type>::BinarySearch(Type find_element, bool(*Compare)(Type, Type), bool(*Equal)(Type, Type))
{
	vector<Type> NewVect;

	sort(vect.begin(), vect.end(), Compare);
	int left = 0;
	int right = vect.size();
	auto index = std::lower_bound(vect.begin(), vect.end(), find_element, Compare);
	if (index != vect.end() && !Compare(*index, find_element))
	{
		NewVect.push_back(*index);
		while ((++index != vect.end()) && Equal(*index, find_element))
			NewVect.push_back(*index);
	}
	return NewVect;
}

//����������
template <class Type>
vector<Type> Task<Type>::Sort(bool(*Compare)(Type, Type))
{
	vector<Type> NewVect;

	sort(vect.begin(), vect.end(), Compare);
	NewVect = vect;

	return NewVect;
}
// ����� � ����
// void(*f) (Type) - ��������� �� �������, ������� ���������� ���� ��������� � ����  
template <class Type>
void Task<Type>::OutputFile(vector<Type> items, void(*f)(Type, ofstream&), string newfname)
{
	ofstream fout(newfname, ios::binary);
	if (fout)
	{
		int i = vect.size();
		fout.write((char*)&i, sizeof(int));
		vector<Type>::const_iterator pos;
		for (pos = items.begin(); pos != items.end(); ++pos)
		{
			f(*pos, fout);
		}
		fout.close();
	}
}

// ����� �� �����
template <class Type>
void Task<Type>::OutputScreen(vector<Type> items, void(*f)(Type), void(*Header)())
{
	vector<Type>::const_iterator pos;
	int count = 1;
	Header();
	for (pos = items.begin(); pos != items.end(); ++pos)
	{
		cout << setw(4) << setiosflags(ios::left) << count << "|";
		f(*pos);
		++count;
	}
}

//���������� ���������� ����� ����������� �� ������������ ������
template <class Type>
vector<int> Task<Type>::SumSalary(int type)
{
	int sum;
	vector<int> NewVect;
	int a;
	switch (type)
	{
	case 1:
		a = 3;
		break;
	case 2:
		a = 6;
		break;
	case 3:
		a = 12;
		break;
	}
	for (auto iter = vect.begin(); iter != vect.end(); iter++)
	{
		sum = a * CalcSumSalary(*iter);
		NewVect.push_back(sum);
	}
	return NewVect;
}

// ����� ���������� ��� ���������� ���������� ����� �� ������������ ������
void OutputScreenHeaderSumSalary()
{
	cout << setw(11) << setiosflags(ios::left) << "��������� �" << "|";
	cout << setw(12) << setiosflags(ios::left) << "����� ������" << "|";
	cout << setw(10) << setiosflags(ios::left) << "�������" << "|";
	cout << setw(10) << setiosflags(ios::left) << "�����" << endl;
	cout << "------------------------------------------------" << endl;
}

//����� ���������� ����� �� ������������ ������ �� �����
template <class Type>
void Task<Type>::OutputScreenSalary(vector<int> items)
{
	vector<int>::const_iterator pos;
	for (auto iter = vect.begin(); iter != vect.end(); iter++)
	{
		cout << setw(11) << setiosflags(ios::left) << (*iter).pers_number << "|";
		cout << setw(12) << setiosflags(ios::left) << (*iter).depart_number << "|";
		cout << setw(10) << setiosflags(ios::left) << (*iter).surname << "|";
	}
	for (pos = items.begin(); pos != items.end(); ++pos)
	{
		cout << setw(10) << setiosflags(ios::left) << (*pos) << endl;
	}
}

// ���� �� �����
// Type(*f)(ifstream&) - ��������� �� �������, ������� ��������� ���� ��������� �� ����� 
template <class Type>
void Task<Type>::ReadFromFile(Type(*f)(ifstream&), string newfname)
{
	std::ifstream input;

	input.open(newfname, ios::binary);

	if (!input)
	{
		cout << "�� ������� ������� ����" << endl;
	}
	else
	{
		int size;
		Type elem;
		input.read((char*)&size, sizeof(int));
		for (int i = 0; i < size; i++)
		{
			vect.push_back(f(input));
		}

		input.close();
	}
}

// ���� � ������
//Type(*f)() - ��������� �� �������, ������� ������ ���� ��������� � �������
template <class Type>
void Task<Type>::ReadFromScreen(Type(*f)())
{
	int n;
	Type elem;
	do
	{
		vect.push_back(f());
		n = InputNumber(0, 1, "�� ������ �������� �������? (1 - ��, 0 - ���)\n��� �����: ");
	} while (n != 0);
}