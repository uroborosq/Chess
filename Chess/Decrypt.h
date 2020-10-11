#pragma once

#include <iostream>
#include <string>

using namespace std;

int xret(char a)
{

	if (a == '1')
		return 7;

	else if (a == '2')
		return 6;

	else if (a == '3')
		return 5;

	else if (a == '4')
		return 4;

	else if (a == '5')
		return 3;

	else if (a == '6')
		return 2;

	else if (a == '7')
		return 1;

	else if (a == '8')
		return 0;

	return -1;
}


int yret(char a)
{
	if (a == 'a')
		return 0;
	else if (a == 'b')
		return 1;
	else if (a == 'c')
		return 2;
	else if (a == 'd')
		return 3;
	else if (a == 'e')
		return 4;
	else if (a == 'f')
		return 5;
	else if (a == 'g')
		return 6;
	else if (a == 'h')
		return 7;

	return -1;
}

int retmove(int *x, int *y, string c, char *d, int *x0, int *y0)
{
	char pr1[5] = { 'Q', 'K', 'N', 'C', 'R' };
	char pr2[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	int pr = 0;


	for (int i = 0; i < 5; i++) //Проверка на фигуру
	{
		if (c[0] == pr1[i]) // Первая буковка
		{
			for (i = 0; i < 8; i++) // Проверка 2-й буковки
			{
				if ((c[1] == pr2[i]) && (c.size() == 4)) // Вариант 4-x символов
				{
					for (i = 0; i < 8; i++)
					{
						if (c[2] == pr2[i]) // Проверка 3-й буковки
						{
							for (i = 0; i < 8; i++) // Проверка цифры
							{
								if (c[3] - 48 == i + 1)
								{
									cout << "v1" << endl;
									*y0 = yret(c[1]);
									*y = yret(c[2]);
									*x = xret(c[3]);
									pr = 1;
									*d = c[0];
								}
							}
						}
						else if (c[2] - 48 == i) // Проверка 3-й циферки
						{
							for (i = 0; i < 8; i++) // Проверка цифры
							{
								if (c[3] - 48 == i)
								{
									cout << "v2";

									*y = yret(c[1]);
									*x = xret(c[3]);
									*x0 = xret(c[2]);
									pr = 1;
									*d = c[0];

								}
							}
						}
					}
				}
				else if (c[1] == pr2[i]) // 2-я буковка
				{
					for (i = 0; i < 8; i++)
					{
						if (c[2] - 48 == i + 1) // Стандартный вариант
						{
							cout << "v3" << endl;
							*d = c[0];
							pr = 1;
							*y = yret(c[1]);
							*x = xret(c[2]);

						}
					}
				}
			}
		}
	}

	for (int i = 0; i < 8; i++) //Проверка на пешки
	if (c[0] == pr2[i])
	{
		cout << 1 << endl;
		for (int j = 0; j < 8; j++) // Проверка 2-го члена нотации
		{
			if (c[1] - 48 == j + 1) //стандартный а4
			{
				cout << "v4" << endl;
				pr = 1;
				*y = yret(c[0]);
				*x = xret(c[1]);
				*d = 'p';
				*x0 = -1;
				*y0 = -1;
			}
			else if ((c[1] == pr2[j]) && (c.size() == 2)) // обычное взятие ab
			{
				cout << "v5";
				pr = 1;

				*y0 = yret(c[0]);
				*y = yret(c[1]);

				*x = -1;
				*x0 = -1;
				*d = 'p';
			}
			else if ((c[1] == pr2[j]) && (c.size() == 3)) //самый извращенный
			{
				for (int p = 0; p < 8; p++)
				if (c[2] - 48 == p + 1)
				{
					cout << "v6";
					pr = 1;
					*y0 = yret(c[0]);
					*y = yret(c[1]);
					*x = xret(c[2]);
					*d = 'p';
				}
			}
		}
	}
	if (pr == 0)
		return 0;

	return 1;
}



