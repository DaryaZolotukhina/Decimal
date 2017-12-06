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
struct List {//��������� ���

	T val;
	List *next, *prev;

};

template <typename T>
class Deque {

	List<T> *Head, *Tail;
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
};

template <typename T>
Deque<T>::Deque()
{
	Head = Tail = nullptr;
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
	List<T> * temp = new List<T>;

	temp->prev = nullptr;

	T n;//���� ��������
	cout << "Input new elem: " << endl;
	cin >> n;

	temp->val = n;//����������� ����� ��������
	temp->next = Head;//��������� ������� ���������� ������� 

	if (Head!= nullptr)//���� ��� ��� �������� �������, �� ��� ��������� prev ������ ��������� �� ����� ��������� �������
		Head->prev = temp;

	if (Tail == nullptr)//���� ����� ������, �� ����� ���������� ������ �������� �� ������ ��������� �� ����
		Tail = temp;

	Head = temp;//������ ����������� ����� ��������

	Count++;
}

template <typename T>
void Deque<T>::AddTail()//���������� �������� � �����
{
	List<T> * temp = new List<T>;

	temp->next = nullptr;

	T n;//���� ������ ��������
	cout << "Input new elem: "<< endl;
	cin >> n;

	temp->val = n;//����������� ����� ��������
	temp->prev = Tail;//���������� ������� ���������� �������

	if (Tail != nullptr)//���� ��� ��� ������� � ������, �� ��� ��������� next ������ ��������� �� ����� ��������� �������
		Tail->next = temp;

	if (Head == nullptr)//���� ������ ������, �� ����� ���������� ������ �������� ��� ������� ��������� �� ����
		Head  = temp;

		Tail = temp;//������ ����������� ����� ��������

	Count++;
}

template <typename T>
void Deque<T>::DelHead()//�������� �������� � ������
{
	List<T> * Del = Head;//��������� ������� - ������
	List<T> * AfterDel = Del->next;
	Head = AfterDel;//������� ���������� ��������� �� ��������� �������
	delete Del;//�������
	if (Count == 1)
		Tail = nullptr;

	Count--;
}

template <typename T>
void Deque<T>::DelTail()//�������� �������� � �����
{
	int i = 1;
	List<T> * Del = Head;//��������� ������� - ������

	while (i < Count)// ������� �� ��������, ������� ���������
	{
		Del = Del->next;
		i++;
	}

	// ������� �� ��������, ������� ������������ ����������
	List<T> * PrevDel = Del->prev;
	// ������� �� ��������, ������� ������� �� ���������
	List<T> * AfterDel = Del->next;

	if (Count != 1)//���� � ���� ������ ������ �������� 
		PrevDel->next = AfterDel;

	Tail = PrevDel;

	delete Del;

	if (Count == 1)
		Head = nullptr;

	Count--;
}

template <typename T>
void Deque<T>::Print()//������
{
	cout << "Deque:" << endl;
	if (Count != 0)
	{
		List<T> * temp = Head;
		while (temp != nullptr)
		{
			cout<<temp->val<<endl;
			temp = temp->next;
		}
	}
	else cout << "Deque is empty" << "\n";
}

template <typename T>
void Deque<T>::GetHead()//��������� �������� � ������
{
	if (Count==0)
		cout<<"Deque is empty"<< "\n";
	else cout << Head->val << "\n";
}

template <typename T>
void Deque<T>::GetTail()//��������� �������� � �����
{
	if (Count == 0)
		cout << "Deque is empty" << "\n";
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
void Program(T A)//����
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
		case 1: A.GetSize(); break;
		case 2: A.AddTail(); break;
		case 3: A.AddHead(); break;
		case 4: A.DelHead(); break;
		case 5: A.DelTail(); break;
		case 6: A.GetHead(); break;
		case 7: A.GetTail(); break;
		case 8: A.Print(); break;
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
	case 1: Program(A);break;
	case 2: Program(B);break;
	case 3: Program(C);break;
	}
}
