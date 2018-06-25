//7. Умножить каждое третье число на удвоенную сумму первого и последнего отрицательных чисел.
#include "stdafx.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
using namespace std;

//создание файла из рандомных значений с помощью цикла
ofstream CreateFileRand(string FileName, int N, int M) {
	ofstream fs(FileName);
	for (int i = 0; i < N; ++i) {
		int r = rand() % (2 * M + 1) - M;
		fs << r << " ";
	}
	fs.close();
	return fs;
}

//создание файла из рандомных значений с помощью generate
ofstream CreateFileGenerate(string FileName, int N, int M) {
	ofstream fs;
	fs.open(FileName);
	generate_n(std::ostream_iterator<int>(fs, " "), N, [M]() {int i = rand() % (2 * M + 1) - M; return i; });
	fs.close();
	return fs;
}

// загрузка чисел из файла в список
list<int> LoadFromFile(ifstream &fin) {
	list<int> numbers;
	if (!fin) {
		cout << "Файл не найден." << endl;
		return numbers;
	}

	int a;
	if (!(fin >> a)) {
		cout << "Неверный формат данных" << endl;
		return numbers;
	}
	if (fin.eof()) {
		cout << "Файл пуст." << endl;
	}
	else {
		while (!fin.eof()) {
			numbers.push_back(a);

			if (!(fin >> a) && !fin.eof()) {
				cout << "Неверный формат данных" << endl;
				numbers.clear();
				return numbers;
			}
		}
	}
	return numbers;
}

//вспомогательная функция для CountDoubleSum
int HelpCountDoubleSum(list<int>::iterator begin, list<int>::iterator end,list<int>::reverse_iterator rbegin, list<int>::reverse_iterator rend)
{
	int first = 0;
	int last = 0;
	for (auto iter = begin; iter != end; iter++)
	{
		if ((*iter < 0) && (first == 0))
			first = *iter;
	}
	for (auto iter = rbegin; iter != rend; iter++)
	{
		if ((*iter < 0) && (last == 0))
			last = *iter;
	}
	if (first == 0)
	{
		cout << "В списке нет отрицательных чисел!" << endl;
		return 0;
	}
	else return (first + last) * 2;
}

// вычисление удвоенной суммы первого и последнего отрицательных чисел
int CountDoubleSum(list<int> &numbers)
{
	return HelpCountDoubleSum(numbers.begin(), numbers.end(), numbers.rbegin(), numbers.rend());
}


// вычисление удвоенной суммы первого и последнего отрицательных чисел (через итераторы)
int CountDoubleSum(list<int>::iterator begin, list<int>::iterator end, list<int>::reverse_iterator rbegin, list<int>::reverse_iterator rend)
{
	return HelpCountDoubleSum(begin, end, rbegin, rend);
}

//вспомогательная функция для modify
list<int> HelpModify(list<int>::iterator begin, list<int>::iterator end, int sum)
{
	int count = 1;
	list<int> numbers2;
	for (auto iter = begin; iter != end; iter++)
	{
		if ((count % 3) == 0)
		{
			*iter *= sum;
		}
		numbers2.push_back(*iter);
		count++;
	}
	return numbers2;
}

// функция modify для изменения списка
list<int> Modify(list<int> &numbers)
{
	if (numbers.empty())
		return numbers;
	return HelpModify(numbers.begin(), numbers.end(), CountDoubleSum(numbers));
}

// перегруженная функция modify для изменения списка
list<int> Modify(list<int>::iterator begin, list<int>::iterator end, list<int>::reverse_iterator rbegin, list<int>::reverse_iterator rend)
{
	return HelpModify(begin, end, CountDoubleSum(begin, end, rbegin, rend));
}

// функция  для изменения списка через transform
void TransformList(list<int> &numbers) {
	int sum = CountDoubleSum(numbers);
	int count = 0;
	transform(numbers.begin(), numbers.end(), numbers.begin(), [sum, &count](int i) {++count; return ((count % 3) == 0) ? (i*sum) : i; });
}

// функция  для изменения списка через for_each
void ForEachList(list<int> &numbers)
{
	int sum = CountDoubleSum(numbers);
	int count = 0;
	for_each(numbers.begin(), numbers.end(), [sum, &count](int &i) {++count; i = ((count % 3) == 0) ? (i*sum) : i; });
}

// функция  для вычисления суммы
int Summ(list<int> numbers) {
	int summ = 0;
	for_each(numbers.begin(), numbers.end(), [&summ](int i) {summ += i; });
	return summ;
}

// функция  для вычисления среднего арифметического
double Average(list<int> &numbers) {
		if (numbers.empty())
			throw 0;
		else return (double)Summ(numbers) / numbers.size();
}

//печать в файл
void  Print(fstream &st, list<int> &numbers) {
	for_each(numbers.begin(), numbers.end(), [&st](int i) {st << i << " "; });
}

//перегруженный метод, печать в консоль
void  Print(ostream &st, list<int> numbers) {
	for_each(numbers.begin(), numbers.end(), [&st](int i) {st << i << " "; });
	st << endl;
}

//консольное меню
int Menu(int flag) {
	cout << "Menu:" << endl;
	cout << 1 << " Создать новый файл со случайными чиселами." << endl;
	cout << 2 << " Загрузить из файла." << endl;
	if (flag > 0) {
		cout << 3 <<  " Умножить каждое третье число на удвоенную сумму первого и последнего отрицательных чисел." << endl;
		cout << 4 <<  " Вычислить сумму." << endl;
		cout << 5 <<  " Вычислить среднее арифметическое." << endl;
		cout << 6 <<  " Вывод в файл." << endl;
		cout << 7 <<  " Вывод на экран." << endl;
	}
	cout << 0 <<  " Выход." << endl << endl;
	int res;
	while (!(cin >> res) || flag <= 0 && (res > 2) || (flag > 0) && (res > 7));
	return res;
}

//ввод ответа да/нет
bool InputQuery(string question) {
	cout << question << endl;
	cout << 1 << " Да" << endl;
	cout << 0 << " Нет" << endl;
	int res;
	while (!(cin >> res) || res != 0 && res != 1);
	return res == 1;
}

// проверка корректности символа в имени файла
bool CorrectSymbol(char c)
{
	switch (c)
	{
	case '.':
	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
	case '/':
		return false;
	default:
		return true;
	}
}


// проверка проверка корректности имени
bool CorrectName(string name)
{
	int i = 1;
	bool goodsm = false;
	if (name[0] != '\0')
	{
		goodsm = CorrectSymbol(name[0]);
		while (name[i] != '\0' && goodsm)
			goodsm = CorrectSymbol(name[i++]);
	}
	return goodsm;
}

//ввод имени файла
string InputFileName() {
	string name;
	do
	{
		cout << "Введите имя файла" << endl;
		cin >> name;
		if (CorrectName(name))
			break;
		else
		cout << "Файл не удалось создать\n";
	} while (true);
	return name;
}

//ввод числа
int InputNum(string str) {
	int Num;
	cout << str << endl;
	while (!(cin >> Num) || Num <= 0);
	return Num;
}

int main() {
	setlocale(LC_ALL, "Russian");
	bool exit = false;
	list<int> numbers;
	string FileName = "";
	int N;
	int M;
	ofstream ofs;
	ifstream ifs;
	do {
		switch (Menu(numbers.size())) {
		case 1:
			N = InputNum("Введите количество элементов.");
			M = InputNum("Введите максимальный модуль чисел.");
			FileName = InputFileName();
			//ofs=CreateFileRand(FileName,N,M);
			ofs = CreateFileGenerate(FileName, N, M);
			break;
		case 2:
			if (FileName == "") FileName = InputFileName();
			else if (!InputQuery("Использовать текущий файл?")) {
				FileName = InputFileName();
			}
			ifs.open(FileName);
			numbers = LoadFromFile(ifs);
			ifs.close();
			break;
		case 3:
			numbers = Modify(numbers);
			//Modify(dec.begin(), dec.end());
			//Modify_Transform(dec.begin(), dec.end());
			//Modify_For_Each(dec.begin(), dec.end());
			break;
		case 4:
			cout << "Сумма элементов равна " << Summ(numbers) << endl;
			break;
		case 5:
			try
			{
				cout << "Среднее арифметическое равно " << Average(numbers) << endl;
			}
			catch (int i)
			{
				cout << "Невозожно посчитать среднее орифметическое пустого множества!"  << endl;
			}
			break;
		case 6:
			FileName = InputFileName();
			ofs.open(FileName);
			Print(ofs, numbers);
			ofs.close();
			break;
		case 7:
			Print(cout, numbers);
			break;
		default:
			return 0;
		}
	} while (1);

}
