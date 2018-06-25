#include "Operation.h"

template <class Type> 
Task<Type>::Task() {}

template <class Type>
Task<Type>::~Task() {}

	// удаление элемента
template <class Type>
void Task<Type>::Remove(int numb)
	{
		if (numb != 0)
			vect.erase(vect.begin() + numb - 1);
	}

	// добавление элемента
template <class Type>
void Task<Type>::Add(Type &elem)
	{
		vect.push_back(elem);
	}

	//размер вектора
template <class Type>
int  Task<Type>::size()
	{
		return vect.size();
	}

	// проверка на пустоту
template <class Type>
bool Task<Type>::Is_empty()
	{
		return (vect.size() == 0);
	}

	// ввод из файла
	// Type(*f)(ifstream&) - указатель на функцию, которая считывает одну структуру из файла 
template <class Type>
bool Task<Type>::ReadFromFile(Type(*f)(ifstream&))
	{
		string newfname = InputFileName();
		std::ifstream input;

		input.open(newfname);

		if (!input)
		{
			cout << "Не удалось открыть файл" << endl;
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

	// ввод с экрана
	//Type(*f)() - указатель на функцию, которая вводит одну структуру с консоли
template <class Type>
void Task<Type>::ReadFromScreen(Type(*f)())
	{
		int n;
		Type elem;
		do
		{
			vect.push_back(f());
			n = InputNumber(0, 1, "Вы хотите добавить элемент? (1 - да, 0 - нет)\nВаш выбор: ");
		} while (n != 0);
	}

	// линейный поиск
	// bool(*Equal)(Type, Type) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим
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

	// бинарный поиск
	// int(*Compare)(Type, Type) - указатель на функцию, которая сравнивает искомый эл-т с текущим
	// bool(*Equal)(Type, Type) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим
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

// вывод в файл
// void(*f) (Type) - указатель на функцию, которая записывает одну структуру в файл 
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
		cout << endl << "Файл заполнен!" << endl;
		fout.close();
	}
	else
	{
		cout << "Файл не заполнен!" << endl;
	}
}
// вывод на экран
// void(*f) (Type) - указатель на функцию, которая считывает одну структуру на экран 
template <class Type>
void OutputScreen(vector<Type> items, void(*f) (Type))
{
	vector<Type>::const_iterator pos;
	int count = 1;
	for (pos = items.begin(); pos != items.end(); ++pos)
	{
		cout << "Запись № " << count << endl;
		f(*pos);
		++count;
	}
	cout << "Конец вывода!" << endl;
}
