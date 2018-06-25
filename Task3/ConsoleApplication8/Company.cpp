#include "Company.h"
// �������� �������� �� ��� ����������
bool MyDate::IsLeap(int year)
	{
		if ((year % 4) || ((year % 100) == 0 && (year % 400)))
			return false;
		return true;
	}

// �������� ���� �� ������������
bool  MyDate::CorrectDate(int day, int month, int year, string &message) {

		// ���� ��� ���������                            ���� �� ����������
		if ((month == 2 && day > 29 && IsLeap(year)) || (month == 2 && day > 28 && !IsLeap(year)))
		{
			message = "�������� ���-�� ���� � �������!";
			return false;
		}
		//���-�� ���� � ������
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30)
			{
				message = "�������� ���-�� ���� � ������!";
				return false;
			}
			return true;
		}
		return true;
	}

	// ����������� �� ���������
MyDate::MyDate()
	{
		int day = 1;
		int month = 1;
		int year = 1970;
	}

	// ���� ���� � �������
void  MyDate::InputDate()
	{
		bool correct_date = true; // ��������� �� ��������� ����
		string message = "";  // ��������� � ������� ������
		do
		{
			if (!correct_date)
				cout << message << endl;
			day = InputNumber(1, 31, "���� ����:\n������� ���� (1-31): ");
			month = InputNumber(1, 12, "������� ����� ������ (1-12): ");
			year = InputNumber(1970, 2100, "������� ��� (1970-2100): ");
			correct_date = CorrectDate(day, month, year, message);
		} while (!correct_date);  // ��������� ���� ���� �� ���������� ����
	}

	// ������� ���� � ������ (��� ����������� ������ � ����)
string  MyDate::ToString()
	{
		return (to_string(day) + ' ' + to_string(month) + ' ' + to_string(year));
	}

	//���������� ��������� "����" �� ������ 
	// ������:
	// ���� ����� ���
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
			cout << "������ ������ � ����!" << endl;
		}
		return result;
	}

	// ������������� �������� ���������
bool  MyDate::operator == (const MyDate &c)
	{
		return ((day == c.day) && (month == c.month) && (year == c.year));
	}

	// ����������� �����������
MyDate&  MyDate::operator = (MyDate c)
	{
		day = c.day;
		month = c.month;
		year = c.year;

		return (*this);
	}

	// ������������� �������� ������
bool  MyDate::operator > (const MyDate &c)
	{
		return ((year > c.year) || ((year == c.year) && (month > c.month)) || ((year == c.year) && (month == c.month) && (day>c.day)));
	}

	// ������������� �������� ������
bool  MyDate::operator < (const MyDate &c)
	{
		return ((year < c.year) || ((year == c.year) && (month < c.month)) || ((year == c.year) && (month == c.month) && (day<c.day)));
	}

	// ����������� �� ���������
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


	// ��������� ��������� "��������"
Worker Worker::ChangeWorker(Worker &result)
	{
		if (InputNumber(0, 1, "�� ������ �������� ��������� ����� " + to_string(result.pers_number) + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
			result.pers_number = InputNumber(0, 1000000, "������� ����� ��������� ����� (0 - 1000000): ");
		if (InputNumber(0, 1, "�� ������ �������� ����� ������ " + to_string(result.depart_number) + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
			result.depart_number = InputNumber(0, 1000000, "������� ����� ����� ������ (0 - 1000000): ");
		if (InputNumber(0, 1, "�� ������ �������� ������� " + result.surname + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
			result.surname = InputInformation("������� ����� �������: ");
		if (InputNumber(0, 1, "�� ������ �������� �����" + to_string(result.salary) + " (0-���, 1 - ��)\n��� �����: ") == 1)
			result.salary = InputNumber(0, 1000000, "������� ����� ����� (0 - 1000000): ");
		if (InputNumber(0, 1, "�� ������ �������� ���� ����������� �� ������ (0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.date.InputDate();
		if (InputNumber(0, 1, "�� ������ �������� ������� ��������" + to_string(result.percent) + " (0-���, 1 - ��)\n��� �����: ") == 1)
			result.percent = InputNumber(0, 100, "������� ����� ������� �������� (0 - 1000000): ");
		if (InputNumber(0, 1, "�� ������ �������� ���������� �����" + to_string(result.tax) + " (0-���, 1 - ��)\n��� �����: ") == 1)
			result.tax = InputNumber(0, 1000000, "������� ����� ���������� ����� (0 - 1000000): ");
		if (InputNumber(0, 1, "�� ������ �������� ���������� ������������ ���� � ������" + to_string(result.days_worked) + " (0-���, 1 - ��)\n��� �����: ") == 1)
			result.days_worked = InputNumber(0, 31, "������� ����� ���������� ������������ ���� � ������ (0 - 1000000): ");
		if (InputNumber(0, 1, "�� ������ �������� ���������� ������� ���� � ������" + to_string(result.days_month) + " (0-���, 1 - ��)\n��� �����: ") == 1)
			result.days_month = InputNumber(0, 31, "������� ����� ���������� ������� ���� � ������ (0 - 1000000): ");
		if (InputNumber(0, 1, "�� ������ �������� ����������� �����" + to_string(result.accured) + " (0-���, 1 - ��)\n��� �����: ") == 1)
			result.accured = InputNumber(0, 1000000, "������� ����� ����������� ����� (0 - 1000000): ");
		if (InputNumber(0, 1, "�� ������ �������� ���������� �����" + to_string(result.withheld) + " (0-���, 1 - ��)\n��� �����: ") == 1)
			result.withheld = InputNumber(0, 1000000, "������� ����� ���������� ����� (0 - 1000000): ");

		return result;
	}

	// ������������� �������� ��������� ��� ��������� "��������"
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

// ������� ����� ��������� "��������" � �������
Worker InputScreenWorker()
{
	Worker c;
	c.pers_number = InputNumber(0, 1000000, "������� ��������� ����� (0 - 1000000): ");
	c.depart_number = InputNumber(0, 1000000, "������� ����� ������ (0 - 1000000): ");
	c.surname = InputInformation("������� �������: ");
	c.salary = InputNumber(0, 1000000, "������� ����� (0 - 1000000): ");
	c.date.InputDate();
	c.percent = InputNumber(0, 100, "������� ������� �������� (0 - 100): ");
	c.tax = InputNumber(0, 1000000, "������� ���������� ����� (0 - 1000000): ");
	c.days_worked = InputNumber(0, 31, "������� ���������� ������������ ���� � ������ (0 - 31): ");
	c.days_month = InputNumber(0, 31, "������� ���������� ������� ���� � ������ (0 - 31): ");
	c.accured = InputNumber(0, 1000000, "������� ����������� ����� (0 - 1000000): ");
	c.withheld = InputNumber(0, 1000000, "������� ���������� ����� (0 - 1000000): ");
	return c;
}

// ������� ������ ��������� "��������" �� �������
void OutputScreenWorker(Worker c)
{
	cout << "��������� �����: " << to_string(c.pers_number) << endl;
	cout << "����� ������: " << to_string(c.depart_number) << endl;
	cout << "�������: " << c.surname << endl;
	cout << "�����: " << to_string(c.salary) << endl;
	cout << "����: " << c.date.ToString() << endl;
	cout << "������� ��������: " << to_string(c.percent) << endl;
	cout << "���������� �����: " << to_string(c.tax) << endl;
	cout << "���������� ������������ ���� � ������: " << to_string(c.days_worked) << endl;
	cout << "���������� ������� ���� � ������: " << to_string(c.days_month) << endl;
	cout << "����������� �����: " << to_string(c.accured) << endl;
	cout << "���������� �����: " << to_string(c.withheld) << endl;
}

//������� ��������� "��������" � ������
string ToString(Worker c, int i)
{
	string result = "������ � " + to_string(i) + "\n" + "��������� �����: " + to_string(c.pers_number) + "\n" + "����� ������: " + to_string(c.depart_number) + "\n" + "�������: " + c.surname + "\n" + "�����: " + to_string(c.salary) + "\n" + "����: " + c.date.ToString() + "\n" + "������� ��������: " + to_string(c.percent) + "\n" + "���������� �����: " + to_string(c.tax) + "\n" + "���������� ������������ ���� � ������: " + to_string(c.days_worked) + "\n" + "���������� ������� ���� � ������: " + to_string(c.days_month) + "\n" + "����������� �����: " + to_string(c.accured) + "\n" + "���������� �����: " + to_string(c.withheld) + "\n";
	return result;
}

//���������� ��������� "����" �� ������ 
// ������:
// ���� ����� ���
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
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}

////���������� ��������� "��������" �� ������
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
			string wrd = "��������� �����: ";
			result.pers_number = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� ������: ";
			result.depart_number = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "�������: ";
			result.surname = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "�����: ";
			result.salary = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����: ";
			result.date = FromString(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� ��������: ";
			result.percent = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���������� �����: ";
			result.tax = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���������� ������������ ���� � ������: ";
			result.days_worked = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���������� ������� ���� � ������: ";
			result.days_month = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����������� �����: ";
			result.accured = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���������� �����: ";
			result.withheld = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}


// ����� ������� �������� �� ���������� ��������
//1 - �� ������ ������
//2 - �� �������
//3 - �� ���� �����������
//4 - �� ������
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


// ���� �������� ������ � ����������� �� ���������� ���� 
//1 - �� ������ ������
//2 - �� �������
//3 - �� ���� �����������
//4 - �� ������
Worker InputChangeTypeSearch(int type_search)
{
	Worker result;
	switch (type_search)
	{
	case 1:
		result.depart_number = InputNumber(0, 1000000, "������� ����� ������ (0 - 1000000): ");
		return result;
	case 2:
		result.surname = InputInformation("������� �������: ");
		return result;
	case 3:
		result.date.InputDate();
		return result;
	case 4:
		result.salary = InputNumber(0, 1000000, "������� ����� (0 - 1000000): ");
		return result;
	default:
		return result;
	}
}

// ��������� �������� � ����������� �� ���������� ���� ��� ����������
//1 - �� ������ ������
//2 - �� �������
//3 - �� ���� �����������
//4 - �� ������
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