/*5. ����������� ������ ������ ��� (Deque<X>), �������� �������� ������������� ����.
����� ������ � ������������ ������� ��������� ������:
���������� ����� ����;
���������� ������ �������� � �����;
���������� ������ �������� � ������;
�������� �������� � ������;
�������� �������� � �����;
��������� �������� � ������;
��������� �������� � �����;
������.
b) ���������� ���� � ������� ������.*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct MyStruct {//������������ ���������
	char char1;
	char char2;
};

template <typename T>
struct deque {//��������� ���

	T val;
	deque *next, *prev;

};

template <typename T>
class Deque {

	deque<T> *Head, *Tail;
	int Count;

public:

	Deque();
	~Deque();

	void DelAll();
	void DelHead();
	void DelTail();

	void AddTail();

	void AddHead();

	void Print();
	
	void Deque<T>::GetHead();
	void Deque<T>::GetTail();
	void Deque<T>::GetSize();

	void Deque<T>::Program();
};

template <typename T>
Deque<T>::Deque()
{
	Head = Tail = 0;
	Count = 0;
}


template <typename T>
Deque<T>::~Deque()
{
	DelAll();
}

template <typename T>
void Deque<T>::AddHead()//���������� �������� � ������
{
	deque<T> * temp = new deque<T>;

	temp->prev = 0;

	T n;//���� ��������
	cout << "Input new elem: " << endl;
	cin >> n;

	temp->val = n;//����������� ����� ��������
	temp->next = Head;//��������� ������� ���������� ������� 

	if (Head!=0)//���� ��� ��� �������� �������, �� ��� ��������� prev ������ ��������� �� ����� ��������� �������
		Head->prev = temp;

	if (Tail == 0)//���� ����� ������, �� ����� ���������� ������ �������� �� ������ ��������� �� ����
		Tail = temp;

	Head = temp;//������ ����������� ����� ��������

	Count++;
}

template <typename T>
void Deque<T>::AddTail()//���������� �������� � �����
{
	deque<T> * temp = new deque<T>;

	temp->next = 0;

	T n;//���� ������ ��������
	cout << "Input new elem: "<< endl;
	cin >> n;

	temp->val = n;//����������� ����� ��������
	temp->prev = Tail;//���������� ������� ���������� �������

	if (Tail != 0)//���� ��� ��� ������� � ������, �� ��� ��������� next ������ ��������� �� ����� ��������� �������
		Tail->next = temp;

	if (Head == 0)//���� ������ ������, �� ����� ���������� ������ �������� ��� ������� ��������� �� ����
		Head  = temp;

		Tail = temp;//������ ����������� ����� ��������

	Count++;
}

template <typename T>
void Deque<T>::DelHead()//�������� �������� � ������
{
	deque<T> * Del = Head;//��������� ������� - ������
	deque<T> * AfterDel = Del->next;
	Head = AfterDel;//������� ���������� ��������� �� ��������� �������
	delete Del;//�������

	Count--;
}

template <typename T>
void Deque<T>::DelTail()//�������� �������� � �����
{
	int i = 1;
	deque<T> * Del = Head;//��������� ������� - ������

	while (i < Count)// ������� �� ��������, ������� ���������
	{
		Del = Del->next;
		i++;
	}

	// ������� �� ��������, ������� ������������ ����������
	deque<T> * PrevDel = Del->prev;
	// ������� �� ��������, ������� ������� �� ���������
	deque<T> * AfterDel = Del->next;

	if (Count != 1)//���� � ���� ������ ������ �������� 
		PrevDel->next = AfterDel;

	Tail = PrevDel;

	delete Del;

	Count--;
}

template <typename T>
void Deque<T>::Print()//������
{
	cout << "Deque:" << endl;
	if (Count != 0)
	{
		deque<T> * temp = Head;
		while (temp != 0)
		{
			cout<<temp->val<<endl;
			temp = temp->next;
		}
	}
}

template <typename T>
void Deque<T>::GetHead()//��������� �������� � ������
{
	cout << Head->val << "\n";
}

template <typename T>
void Deque<T>::GetTail()//��������� �������� � �����
{
	cout << Tail->val << "\n";
}

template <typename T>
void Deque<T>::GetSize()//������
{
	cout << "Size" << endl;
	cout << Count << "\n";
}

template <typename T>
void Deque<T>::DelAll()//������� ���
{
	while (Count != 0)
		DelHead();
}


template <typename T>
void Deque<T>::Program()//����
{
	int k;
	do {
		cout << "--Menu:\n"
			<< "1.Get size\n"
			<< "2.Add tail\n"
			<< "3.Add head\n"
			<< "4.Delete head\n"
			<< "5.Delete tail\n"
			<< "6.Get head\n"
			<< "7.Get tail\n"
			<< "8.Print\n"
			<< "0.Exit\n"
			<< "Your choise: ";
		cin >> k;
		switch (k)
		{
		case 1: GetSize(); break;
		case 2: AddTail(); break;
		case 3: AddHead(); break;
		case 4: DelHead(); break;
		case 5: DelTail(); break;
		case 6: GetHead(); break;
		case 7: GetTail(); break;
		case 8: Print(); break;
		case 0: cout << "Now exit"; break;
		default:	cout << "error inputing,try again" << endl;
		}
	} while (k != 0);
}

ostream& operator<<(ostream& os, const  MyStruct& a)//����� ��� ����������
{
	os << a.char1 << " " << a.char2 << endl;
	return os;
}

istream& operator>>(istream& is, MyStruct& a)//���� ��� ���������
{
	cout << "Input char1:" << endl;
	is >> a.char1;
	cout << "Input char2:" << endl;
	is >> a.char2;
	return is;
}

int main() {
	Deque <MyStruct> C;
	Deque <int> A;
	Deque <string> B;
	int k;
	cout << "Select data type: 1 - int, 2 - string, 3 - MyStruct"<<endl;
	cin >> k;
	switch (k)
	{
	case 1: A.Program();break;
	case 2: B.Program();break;
	case 3: C.Program();break;
	}
}
