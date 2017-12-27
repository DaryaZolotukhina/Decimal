#include "Deque.h"

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
void Deque<T>::AddHead(T n)//���������� �������� � ������
{
	List<T> * temp = new List<T>;

	temp->prev = nullptr;

	temp->val = n;//����������� ����� ��������
	temp->next = Head;//��������� ������� ���������� ������� 

	if (Head != nullptr)//���� ��� ��� �������� �������, �� ��� ��������� prev ������ ��������� �� ����� ��������� �������
		Head->prev = temp;

	if (Tail == nullptr)//���� ����� ������, �� ����� ���������� ������ �������� �� ������ ��������� �� ����
		Tail = temp;

	Head = temp;//������ ����������� ����� ��������

	Count++;
}

template <typename T>
void Deque<T>::AddTail(T n)//���������� �������� � �����
{
	List<T> * temp = new List<T>;

	temp->next = nullptr;

	temp->val = n;//����������� ����� ��������
	temp->prev = Tail;//���������� ������� ���������� �������

	if (Tail != nullptr)//���� ��� ��� ������� � ������, �� ��� ��������� next ������ ��������� �� ����� ��������� �������
		Tail->next = temp;

	if (Head == nullptr)//���� ������ ������, �� ����� ���������� ������ �������� ��� ������� ��������� �� ����
		Head = temp;

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
	else
		Head->prev = nullptr;
	Count--;
}

template <typename T>
void Deque<T>::DelTail()//�������� �������� � �����
{
	List<T> * Del = Tail;//��������� ������� - �����
	List<T> * PrevDel = Del->prev;
	Tail = PrevDel;//������� ���������� ���������� �������
	delete Del;//�������
	if (Count == 1)
		Head = nullptr;
	else
		Tail->next = nullptr;
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
			cout << temp->val << endl;
			temp = temp->next;
		}
	}
	else cout << "is empty" << "\n";
}

template <typename T>
T Deque<T>::GetHead()//��������� �������� � ������
{
	if (Count == 0)
		throw 1;
	else return Head->val;
}

template <typename T>
T Deque<T>::GetTail()//��������� �������� � �����
{
	if (Count == 0)
		throw 1;
	else return Tail->val;
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
