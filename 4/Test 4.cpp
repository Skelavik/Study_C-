#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <cctype>

using namespace std;
string s1, s2, s3;
char c;
int s, lens, len, k = 0, f = 0, d, a0, b0, a1, b1, a2, b2, y = 0, i = 0, p = 0, lens1= 0;

int line()
{
	cout << endl;
	ifstream open("Line.txt");
	getline(open, s1);
	cout << s1 << endl;
	open.close();
	return 0;
}
int symbol()
{
	cout << endl;
	ifstream open("Line.txt");
	getline(open, s1);
	len = s1.length();
	cout << len << endl;
	open.close();
	return 0;
}
int symbols()
{
	cout << endl;
	ifstream open("Line.txt");
	getline(open, s1);
	len = s1.length();
	//cout << len << endl;
	open.close();
	return len;
}
int world()
{
	cout << endl;
	ifstream open("Line.txt");
	while (open.get(c))
	{
		if (c == ' ')
		{
			k++;
		}
	}
	k++;
	cout << k << endl;
	k = 0;
	return 0;
}
int brackets()
{
	cout << endl;
	ifstream open("Line.txt");
	while (open.get(c))
	{
		if (c == '{')
		{
			a0++;
		}
		if (c == '}')
		{
			b0++;
		}

		if (c == '[')
		{
			a1++;
		}
		if (c == ']')
		{
			b1++;
		}

		if (c == '(')
		{
			a2++;
		}
		if (c == ')')
		{
			b2++;
		}
	}

	cout << "{ = " << a0 << endl;
	cout << "} = " << b0 << endl;

	cout << "[ = " << a1 << endl;
	cout << "] = " << b1 << endl;

	cout << "( = " << a2 << endl;
	cout << ") = " << b2 << endl;
	return 0;
}

int one()
{
	cout << endl;
	ifstream open("Line.txt");
	while (open.get(c))
	{
		i = open.tellg();
		if (i % 2 == 0)
		{
			cout << c;
		}
	}
	return 0;
}
int two()
{
	cout << endl;
	ifstream open("Line.txt");
	while (open.get(c))
	{
		i = open.tellg();
		if (i % 2 == 1)
		{
			cout << c;
		}
	}
	return 0;
}
int twoline()
{
	one();
	two();

	return 0;
}

int print(int i, int lens)
{
	ifstream open("Line.txt");
	getline(open, s1);
	lens1 = lens + 1;
	s2 = s1.substr(i - lens1, lens);
	//cout << s2 << endl;
	reverse(s2.begin(), s2.end());
	cout << s2 << endl;

	return 0;
}
int lenght()
{
	cout << endl;
	ifstream open("Line.txt");
	while (open.get(c))
	{
		if (c == ' ')
		{
			if (lens <= p)
			{
				i = open.tellg();
				i = i - 1;
				lens = p;
			}
			p = 0;
			
		}
		p++;
	}
	lens = lens - 1;
	p = 0;
	print(i,lens);

	return 0;
}

int defult()
{
	cout << endl;
	ifstream open("Line.txt");
	string s = "", s1;
	while (getline(open, s1))
	{
		s += s1;
	}
	int f;
	f = symbols();
	int i = 0, u = 0;
	while (i < f)
	{
		if (s[i] == '.' and s[i + 1] == ' ')
		{
			if (s[i + 2] >= 'а' and s[i + 2] <= 'я')
			{
				s[i + 2] -= 'а' - 'А';
			}
		}
		if (s[i] != '.' and s[i + 1] != '\0')
		{
			if (s[i + 2] >= 'А' and s[i + 2] <= 'Я')
			{
				s[i + 2] -= 'А' - 'а';
			}
		}
		cout << s[i];
		fstream open("Line.txt", ios::app);
		if (u == 0)
		{
			open << endl;
			open << s[i];
		}
		else
		{
			open << s[i];
		}
		i++;
		u++;
	}
	cout << endl;
	open.close();
	return 0;
}




int main()
{
	while (y == 0)
	{
		cout << endl;
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "1 - Считать строку" << endl;
		cout << "2 - Cимволов в строке" << endl;
		cout << "3 - Количество слов" << endl;
		cout << "4 - Количество скобок" << endl;
		cout << "5 - Чётность" << endl;
		cout << "6 - Самое длинное слово" << endl;
		cout << "7 - Буквы в строке" << endl;
		cout << "8 - Выход" << endl;
		cin >> s;
		switch (s)

		{
		case 1:
		{
			line();
			break;
		}
		case 2:
		{
			symbol();
			break;
		}
		case 3:
		{
			world();
			break;
		}
		case 4:
		{
			brackets();
			break;
		}
		case 5:
		{
			twoline();
			break;
		}
		case 6:
		{
			lenght();
			break;
		}
		case 7:
		{
			defult();
			break;
		}
		case 8:
		{
			y = 1;
			break;
		}


		}
	}
	
}