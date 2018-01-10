/*5. —оздать класс Decimal дл€ работы с беззнаковыми целыми дес€тичными числами,
использу€ дл€ представлени€ числа массив из 100 элементов типа unsigned char, каждый
из которых €вл€етс€ дес€тичной цифрой.ћладша€ цифра имеет меньший индекс
(единицы Ц в нулевом элементе массива).–еальный размер массива задаетс€ как
аргумент конструктора инициализации.–еализовать арифметические операции сложени€
и вычитани€, а также сравнени€.*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

#include "Decimal.cpp"

using namespace std;

int main()
{
	TDecimal a, b;
	int k;
	do {
		cout << "--Menu:\n"
			<< "1.Read\n"
			<< "2.Display\n"
			<< "3.toString\n"
			<< "4.Summ\n"
			<< "5.Difference\n"
			<< "6.Compare\n"
			<< "0.Exit\n"
			<< "Your choise: ";
		cin >> k;
		switch (k)
		{
		case 1:
		{
			cout << "A: ";
			a.Read();
			cout << "B: ";
			b.Read();
			break;
		}
		case 2:		a.Display(b);	break;
		case 3:		cout << a.toString(b) << endl;	break;
		case 4:		cout << "Summ: " << (a + b) << endl; break;
		case 5:		cout << "Difference: " << (a - b) << endl; break;
		case 6:
		{
			char* n;
			if (a.Compare(b) == 1)
				n = ">";
			else if (a.Compare(b) == 0)
				n = "=";
			else n = "<";
			cout << a << n << b << endl;
			break;
		}
		case 0: cout << "Now exit"; break;
		default:	cout << "error inputing,try again" << endl;
		}
	} while (k != 0);
	return 0;
}