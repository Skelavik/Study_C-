#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;
int s = 0, a , c = 0, b = 0, d = 0, f = 0, n, y = 0, g = 10;

void bin()
{
	cout << "Ввод числа" << endl;
	cin >> a;
	for (n;n > -1;n = n - 1)
		{
			f = pow(2, n);
			c = a / f;
			if (c == 1)
			{
				a = a - f;
			}
			cout << c;
		}
}

void oct(int a)
{
	cout << "Ввод числа" << endl;
	cin >> a;
	for (n; n > -1; n = n - 1)
		{
			f = pow(8, n);
			c = a / f;
			if (c > 0)
			{
				a = a - (f * c);
			}
			cout << c;
		}
}
void hex(int a)
{
	cout << "Ввод числа" << endl;
	cin >> a;
	for (n; n > -1; n = n - 1)
		{
			f = pow(16, n);
			c = a / f;
			if (c > 0)
			{
				a = a - (f * c);
			}
			if (c == 10) { cout << "A"; }
			if (c == 11) { cout << "B"; }
			if (c == 12) { cout << "C"; }
			if (c == 13) { cout << "D"; }
			if (c == 14) { cout << "E"; }
			if (c == 15) { cout << "F"; }
			if (c < 10) { cout << c; }
		}	
}	



int main()
{
	while (y == 0)
	{
		cout<<" "<<endl;
		n = g;
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		if (s != 0) s = 0;
		cout << "Выбирите действие" << endl;
		cout << "1 - Перевод в двойчный код" << endl;
		cout << "2 - Перевод в восьмеричный код" << endl;
		cout << "3 - Перевод в шестнадцатеричный код" << endl;
		cout << "4 - Выход из программы" << endl;
		cin >> s;
		
		switch (s)
		{
		case 1:
		{
			bin();
			break;
		}
		case 2:
		{
			
			oct(a);
			break;
		}
		case 3:
		{
			hex(a);
			break;
		
		}
		case 4:
		{
			y = 1;
		}
		default:
		{
			if (y == 0)
			{
			cout << "Ошибка" << endl;
			}
		}
		}	
	}
	system("Pause");
}
