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
void Deque<T>::AddHead(T n)//добавление элемента в начало
{
	List<T> * temp = new List<T>;

	temp->prev = nullptr;

	temp->val = n;//присваиваем новое значение
	temp->next = Head;//следующий элемент становитс€ головой 

	if (Head != nullptr)//если уже был головной элемент, то его указатель prev должен ссылатьс€ на вновь созданный элемент
		Head->prev = temp;

	if (Tail == nullptr)//если хвост пустой, то после добавлени€ нового элемента он должен ссылатьс€ на него
		Tail = temp;

	Head = temp;//голове присваиваем новое значение

	Count++;
}

template <typename T>
void Deque<T>::AddTail(T n)//добавление элемента в конец
{
	List<T> * temp = new List<T>;

	temp->next = nullptr;

	temp->val = n;//присваиваем новое значение
	temp->prev = Tail;//предыдущий элемент становитс€ хвостом

	if (Tail != nullptr)//если уже был элемент в хвосте, то его указатель next должен ссылатьс€ на вновь созданный элемент
		Tail->next = temp;

	if (Head == nullptr)//если голова пуста€, то после добавлени€ нового элемента она должена ссылатьс€ на него
		Head = temp;

	Tail = temp;//хвосту присваиваем новое значение

	Count++;
}

template <typename T>
void Deque<T>::DelHead()//удаление элемента с начала
{
	List<T> * Del = Head;//удал€емый элемент - голова
	List<T> * AfterDel = Del->next;
	Head = AfterDel;//головой становитс€ следующий за удал€емым элемент
	delete Del;//удал€ем
	if (Count == 1)
		Tail = nullptr;
	else
		Head->prev = nullptr;
	Count--;
}

template <typename T>
void Deque<T>::DelTail()//удаление элемента с конца
{
	List<T> * Del = Tail;//удал€емый элемент - хвост
	List<T> * PrevDel = Del->prev;
	Tail = PrevDel;//хвостом становитс€ предыдущий элемент
	delete Del;//удал€ем
	if (Count == 1)
		Head = nullptr;
	else
		Tail->next = nullptr;
	Count--;
}

template <typename T>
void Deque<T>::Print()//печать
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
T Deque<T>::GetHead()//полученик элемента с начала
{
	if (Count == 0)
		throw 1;
	else return Head->val;
}

template <typename T>
T Deque<T>::GetTail()//получение элемента с конца
{
	if (Count == 0)
		throw 1;
	else return Tail->val;
}

template <typename T>
void Deque<T>::GetSize()//размер
{
	cout << "Size" << endl;
	cout << Count << "\n";
}

template <typename T>
void Deque<T>::DelAll()//удалить все
{
	while (Count != 0)
		DelHead();
}
