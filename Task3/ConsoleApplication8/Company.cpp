#include "Company.h"
// проверка является ли год високосным
bool MyDate::IsLeap(int year)
	{
		if ((year % 4) || ((year % 100) == 0 && (year % 400)))
			return false;
		return true;
	}

// проверка даты на корректность
bool  MyDate::CorrectDate(int day, int month, int year, string &message) {

		// если год вискосный                            если не високосный
		if ((month == 2 && day > 29 && IsLeap(year)) || (month == 2 && day > 28 && !IsLeap(year)))
		{
			message = "Неверное кол-во дней в феврале!";
			return false;
		}
		//кол-во дней в месяце
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30)
			{
				message = "Неверное кол-во дней в месяце!";
				return false;
			}
			return true;
		}
		return true;
	}

	// конструктор по умолчанию
MyDate::MyDate()
	{
		int day = 1;
		int month = 1;
		int year = 1970;
	}

	// ввод даты с консоли
void  MyDate::InputDate()
	{
		bool correct_date = true; // корректна ли введенная дата
		string message = "";  // сообщение о причине ошибки
		do
		{
			if (!correct_date)
				cout << message << endl;
			day = InputNumber(1, 31, "Ввод даты:\nВведите день (1-31): ");
			month = InputNumber(1, 12, "Введите номер месяца (1-12): ");
			year = InputNumber(1970, 2100, "Введите год (1970-2100): ");
			correct_date = CorrectDate(day, month, year, message);
		} while (!correct_date);  // повторять ввод пока не корректная дата
	}

	// перевод даты в строку (для последующей записи в файл)
string  MyDate::ToString()
	{
		return (to_string(day) + ' ' + to_string(month) + ' ' + to_string(year));
	}

	//извлечение структуры "дата" из строки 
	// Формат:
	// день месяц год
MyDate  MyDate::FromString(string str)
	{
		MyDate result;
		try
		{
			istringstream is(str);
			string s;
			if (getline(is, s, ' '))
				result.day = atoi(s.c_str());
			if (getline(is, s, ' '))
				result.month = atoi(s.c_str());
			if (getline(is, s, ' '))
				result.year = atoi(s.c_str());
		}
		catch (...)
		{
			cout << "Ошибка записи в файл!" << endl;
		}
		return result;
	}

	// перегруженный оператор равенства
bool  MyDate::operator == (const MyDate &c)
	{
		return ((day == c.day) && (month == c.month) && (year == c.year));
	}

	// конструктор копирования
MyDate&  MyDate::operator = (MyDate c)
	{
		day = c.day;
		month = c.month;
		year = c.year;

		return (*this);
	}

	// перегруженный оператор больше
bool  MyDate::operator > (const MyDate &c)
	{
		return ((year > c.year) || ((year == c.year) && (month > c.month)) || ((year == c.year) && (month == c.month) && (day>c.day)));
	}

	// перегруженные оператор меньше
bool  MyDate::operator < (const MyDate &c)
	{
		return ((year < c.year) || ((year == c.year) && (month < c.month)) || ((year == c.year) && (month == c.month) && (day<c.day)));
	}

	// конструктор по умолчанию
Worker::Worker()
	{
		int pers_number = 0;
		int depart_number = 0;
		string surname = "";
		float salary = 0;
		MyDate date;
		float percent = 0;
		float tax = 0;
		int days_worked = 0;
		int days_month = 0;
		float accured = 0;
		float withheld = 0;
	}


	// изменение структуры "компания"
Worker Worker::ChangeWorker(Worker &result)
	{
		if (InputNumber(0, 1, "Вы хотите изменить табельный номер " + to_string(result.pers_number) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
			result.pers_number = InputNumber(0, 1000000, "Введите новый табельный номер (0 - 1000000): ");
		if (InputNumber(0, 1, "Вы хотите изменить номер отдела " + to_string(result.depart_number) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
			result.depart_number = InputNumber(0, 1000000, "Введите новый номер отдела (0 - 1000000): ");
		if (InputNumber(0, 1, "Вы хотите изменить фамилию " + result.surname + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
			result.surname = InputInformation("Введите новую фамилию: ");
		if (InputNumber(0, 1, "Вы хотите изменить оклад" + to_string(result.salary) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.salary = InputNumber(0, 1000000, "Введите новый оклад (0 - 1000000): ");
		if (InputNumber(0, 1, "Вы хотите изменить дату поступления на работу (0 - нет, 1 - да) \nВыш выбор: ") == 1)
			result.date.InputDate();
		if (InputNumber(0, 1, "Вы хотите изменить процент надбавки" + to_string(result.percent) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.percent = InputNumber(0, 100, "Введите новый процент надбавки (0 - 1000000): ");
		if (InputNumber(0, 1, "Вы хотите изменить подоходный налог" + to_string(result.tax) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.tax = InputNumber(0, 1000000, "Введите новый подоходный налог (0 - 1000000): ");
		if (InputNumber(0, 1, "Вы хотите изменить количество отработанных дней в месяце" + to_string(result.days_worked) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.days_worked = InputNumber(0, 31, "Введите новое количество отработанных дней в месяце (0 - 1000000): ");
		if (InputNumber(0, 1, "Вы хотите изменить количество рабочих дней в месяце" + to_string(result.days_month) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.days_month = InputNumber(0, 31, "Введите новое количество рабочих дней в месяце (0 - 1000000): ");
		if (InputNumber(0, 1, "Вы хотите изменить начисленную сумму" + to_string(result.accured) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.accured = InputNumber(0, 1000000, "Введите новую начисленную сумму (0 - 1000000): ");
		if (InputNumber(0, 1, "Вы хотите изменить удержанную сумму" + to_string(result.withheld) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.withheld = InputNumber(0, 1000000, "Введите новую удержанную сумму (0 - 1000000): ");

		return result;
	}

	// перегруженный оператор равенства для структуры "компания"
Worker& Worker::operator = (Worker c)
	{
		pers_number = c.pers_number;
		depart_number = c.depart_number;
		surname = c.surname;
		salary = c.salary;
		date = c.date;
		percent = c.percent;
		tax = c.tax;
		days_worked = c.days_worked;
		days_month = c.days_month;
		accured = c.accured;
		withheld = c.withheld;

		return (*this);
	}

// функция ввода структуры "компания" с консоли
Worker InputScreenWorker()
{
	Worker c;
	c.pers_number = InputNumber(0, 1000000, "Введите табельный номер (0 - 1000000): ");
	c.depart_number = InputNumber(0, 1000000, "Введите номер отдела (0 - 1000000): ");
	c.surname = InputInformation("Введите фамилию: ");
	c.salary = InputNumber(0, 1000000, "Введите оклад (0 - 1000000): ");
	c.date.InputDate();
	c.percent = InputNumber(0, 100, "Введите процент надбавки (0 - 100): ");
	c.tax = InputNumber(0, 1000000, "Введите подоходный налог (0 - 1000000): ");
	c.days_worked = InputNumber(0, 31, "Введите количество отработанных дней в месяце (0 - 31): ");
	c.days_month = InputNumber(0, 31, "Введите количество рабочих дней в месяце (0 - 31): ");
	c.accured = InputNumber(0, 1000000, "Введите начисленную сумму (0 - 1000000): ");
	c.withheld = InputNumber(0, 1000000, "Введите удержанную сумму (0 - 1000000): ");
	return c;
}

// функция вывода структуры "компания" на консоль
void OutputScreenWorker(Worker c)
{
	cout << "Табельный номер: " << to_string(c.pers_number) << endl;
	cout << "Номер отдела: " << to_string(c.depart_number) << endl;
	cout << "Фамилия: " << c.surname << endl;
	cout << "Оклад: " << to_string(c.salary) << endl;
	cout << "Дата: " << c.date.ToString() << endl;
	cout << "Процент надбавки: " << to_string(c.percent) << endl;
	cout << "Подоходный налог: " << to_string(c.tax) << endl;
	cout << "Количество отработанных дней в месяце: " << to_string(c.days_worked) << endl;
	cout << "Количество рабочих дней в месяце: " << to_string(c.days_month) << endl;
	cout << "Начисленная сумма: " << to_string(c.accured) << endl;
	cout << "Удержанная сумма: " << to_string(c.withheld) << endl;
}

//перевод структуры "компания" в строку
string ToString(Worker c, int i)
{
	string result = "Запись № " + to_string(i) + "\n" + "Табельный номер: " + to_string(c.pers_number) + "\n" + "Номер отдела: " + to_string(c.depart_number) + "\n" + "Фамилия: " + c.surname + "\n" + "Оклад: " + to_string(c.salary) + "\n" + "Дата: " + c.date.ToString() + "\n" + "Процент надбавки: " + to_string(c.percent) + "\n" + "Подоходный налог: " + to_string(c.tax) + "\n" + "Количество отработанных дней в месяце: " + to_string(c.days_worked) + "\n" + "Количество рабочих дней в месяце: " + to_string(c.days_month) + "\n" + "Начисленная сумма: " + to_string(c.accured) + "\n" + "Удержанная сумма: " + to_string(c.withheld) + "\n";
	return result;
}

//извлечение структуры "дата" из строки 
// Формат:
// день месяц год
MyDate FromString(string str)
{
	MyDate result;
	try
	{
		istringstream is(str);
		string s;
		if (getline(is, s, ' '))
			result.day = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.month = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.year = atoi(s.c_str());
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}

////считывание структуры "компания" из строки
Worker ReadFromString(ifstream& input)
{
	Worker result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Табельный номер: ";
			result.pers_number = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Номер отдела: ";
			result.depart_number = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Фамилия: ";
			result.surname = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Оклад: ";
			result.salary = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Дата: ";
			result.date = FromString(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Процент надбавки: ";
			result.percent = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Подоходный налог: ";
			result.tax = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Количество отработанных дней в месяце: ";
			result.days_worked = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Количество рабочих дней в месяце: ";
			result.days_month = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Начисленная сумма: ";
			result.accured = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Удержанная сумма: ";
			result.withheld = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}


// поиск равного элемента по выбранному критерию
//1 - по номеру отдела
//2 - по фамилии
//3 - по дате поступления
//4 - по окладу
bool SearchElementDepart(Worker n, Worker m)
{
	return (n.depart_number == m.depart_number);
}

bool SearchElementSurname(Worker n, Worker m)
{
	return (n.surname == m.surname);
}

bool SearchElementDate(Worker n, Worker m)
{
	return (n.date == m.date);
}
bool SearchElementSalary(Worker n, Worker m)
{
	return (n.salary == m.salary);
}


// ввод критерия поиска в зависимости от выбранного типа 
//1 - по номеру отдела
//2 - по фамилии
//3 - по дате поступления
//4 - по окладу
Worker InputChangeTypeSearch(int type_search)
{
	Worker result;
	switch (type_search)
	{
	case 1:
		result.depart_number = InputNumber(0, 1000000, "Введите номер отдела (0 - 1000000): ");
		return result;
	case 2:
		result.surname = InputInformation("Введите фамилию: ");
		return result;
	case 3:
		result.date.InputDate();
		return result;
	case 4:
		result.salary = InputNumber(0, 1000000, "Введите оклад (0 - 1000000): ");
		return result;
	default:
		return result;
	}
}

// сравнения структур в зависимости от выбранного поля для сортировки
//1 - по номеру отдела
//2 - по фамилии
//3 - по дате поступления
//4 - по окладу
bool SorteDepart(Worker n, Worker m)
{
	return n.depart_number > m.depart_number;
}
bool SorteSurname(Worker n, Worker m)
{
	return n.surname > m.surname;
}
bool SorteDate(Worker n, Worker m)
{
	return n.date > m.date;
}
bool SorteSalary(Worker n, Worker m)
{
	return n.salary > m.salary;
}