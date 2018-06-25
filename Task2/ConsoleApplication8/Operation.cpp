#include "Operation.h"

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

	// ���� �� �����
	// Type(*f)(ifstream&) - ��������� �� �������, ������� ��������� ���� ��������� �� ����� 
template <class Type>
bool Task<Type>::ReadFromFile(Type(*f)(ifstream&))
	{
		string newfname = InputFileName();
		std::ifstream input;

		input.open(newfname);

		if (!input)
		{
			cout << "�� ������� ������� ����" << endl;
			return false;
		}
		else
		{
			while (!input.eof())
			{
				vect.push_back(f(input));
			}
			vect.erase(vect.begin() + vect.size() - 1);

			input.close();
			return true;
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

// ����� � ����
// void(*f) (Type) - ��������� �� �������, ������� ���������� ���� ��������� � ���� 
template <class Type>
void OutputFile(vector<Type> items, string(*f)(Type, int))
{
	string newfname = InputFileName();
	ofstream fout(newfname);
	if (fout)
	{
		vector<Type>::const_iterator pos;
		int count = 1;
		for (pos = items.begin(); pos != items.end(); ++pos)
		{
			fout << f(*pos, count) << ' ';
			count++;
		}
		cout << endl << "���� ��������!" << endl;
		fout.close();
	}
	else
	{
		cout << "���� �� ��������!" << endl;
	}
}
// ����� �� �����
// void(*f) (Type) - ��������� �� �������, ������� ��������� ���� ��������� �� ����� 
template <class Type>
void OutputScreen(vector<Type> items, void(*f) (Type))
{
	vector<Type>::const_iterator pos;
	int count = 1;
	for (pos = items.begin(); pos != items.end(); ++pos)
	{
		cout << "������ � " << count << endl;
		f(*pos);
		++count;
	}
	cout << "����� ������!" << endl;
}
