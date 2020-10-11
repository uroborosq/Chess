#pragma once

#include <iostream>
#include <string>



void init()
{
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
		desk[i][j] = ' ';

	for (int i = 0; i < 8; i++)
		desk[6][i] = 'P';

	for (int i = 0; i < 8; i++)
		desk[1][i] = 'p';

	desk[7][0] = 'R';
	desk[7][7] = 'R';
	desk[0][0] = 'r';
	desk[0][7] = 'r';

	desk[7][1] = 'N';
	desk[7][6] = 'N';
	desk[0][1] = 'n';
	desk[0][6] = 'n';

	desk[7][2] = 'C';
	desk[7][5] = 'C';
	desk[0][2] = 'c';
	desk[0][5] = 'c';

	desk[0][3] = 'q';
	desk[7][3] = 'Q';

	desk[0][4] = 'k';
	desk[7][4] = 'K';
}
int vz(int x, int y, int q)
{
	if (q == 0)
	{
		for (int i = 0; i < 6; i++)
		if (desk[x][y] == pr3[i])
			return 1;
	}
	else
	{
		for (int i = 0; i < 6; i++)
		if (desk[x][y] == pr1[i])
			return 1;
	}
	cout << "Ошибка фунции vz" << endl;
	return 0;
}
int pr(char typ, int q, int x, int x0, int y, int y0)
{
	if (desk[x][y] == ' ')
	{
		desk[x0][y0] = ' ';
		desk[x][y] = typ;
		return 1;
	}
	else if (vz(x, y, q) == 1)
	{
		desk[x0][y0] = ' ';
		desk[x][y] = typ;
		return 1;
	}
	else
	{
		cout << "Ошибка функции pr, взятие своих или нулевой ход" << endl;
		return 0;
	}
}
int prp(char typ, int q, int x, int x0, int y, int y0)
{
	if (desk[x][y] == ' ')
	{
		return 1;
	}
	else if (vz(x, y, q) == 1)
	{
		return 2;
	}
	else
	{
		cout << "Ошибка функции pr, взятие своих или нулевой ход" << endl;
		return 0;
	}
}
void ura(int q, int x, int y)
{
	char typ;
	if (q == 0)
	{
		cout << "Давай фигуру" << endl;
		cin >> typ;
		for (int i = 0; i < 6; i++)
		{
			if (pr1[i] == typ)
			{
				desk[x][y] = typ;
			}
		}

	}
	else
	{
		cout << "Давай фигуру" << endl;
		cin >> typ;
		for (int i = 0; i < 6; i++)
		{
			if (pr3[i] == typ)
			{
				desk[x][y] = typ;
			}
		}
	}
}
int R(int x, int y, int x0, int y0, int q) // Ход ладьи
{
	int n = 0;
	char typ;

	if (q == 0)
		typ = 'R';
	else
		typ = 'r';


	if (x0 != -1 || y0 != -1) // Есть нач кор
	{
		if (x0 != -1 && y0 == -1) // Есть х
		{
			for (int i = 0; i < 8; i++)
			{
				if (desk[x0][i] == typ)
				{
					y0 = i;
					n++;
				}
			}
			for (int i = min(y, y0)+1; i < max(y, y0); i++)
			{
				if (desk[x][i] != ' ')
					n = 1000;
			}
		}
		else if (y0 != -1 && x0 == -1) // Есть у
		{
			for (int i = 0; i < 8; i++)
			{
				if (desk[i][y0] == typ)
				{
					x0 = i;
					n++;
				}
			}
			for (int i = min(x, x0)+1; i < max(x, x0); i++)
			{
				if (desk[i][y] != ' ')
					n = 1000;
			}
		}
		
	}

	else // Нет нач кор
	{

		for (int i = 0; i < 8; i++) // Ищем ладьи
		for (int j = 0; j < 8; j++)
		{
			if (desk[i][j] == typ)
			{
				int gg = 0;
				if (x == i && y != j)
				{
					for (int o = min(y, j) + 1; o < max(y, j); o++)
					if (desk[x][o] != ' ')
						gg++;
					if (gg == 0)
					{
						x0 = i;
						y0 = j;
						n = 1;
					}
				}

				else if (x != i && y == j)

				{
					for (int o = min(x, i) + 1; o < max(x, i); o++)
					if (desk[o][y] != ' ')
						gg++;
					if (gg == 0)
					{
						x0 = i;
						y0 = j;
						n = 1;
					}
				}
			}
		}
	}
	cout << "n = " << n << endl;
	if (n == 1)
	{

		if ((pr(typ, q, x, x0, y, y0) == 1) || (pr(typ, q, x, x0, y, y0) == 2))
			return 1;
		else
			return 0;
	}

	return 0;
}
int K(int x, int y, int q) // РљРѕСЂРѕР»СЊ
{
	int x0;
	int y0;
	char typ;
	if (q == 0) // РџСЂРѕРІРµСЂРєР° РЅР° РѕС‡РµСЂРµРґСЊ С…РѕРґР°
		typ = 'K';
	else
		typ = 'k';

	for (int i = 0; i < 8; i++) // РС‰РµРј РєРѕСЂРѕР»СЏ
	for (int j = 0; j < 8; j++)
	{
		if (desk[i][j] == typ)
		{
			x0 = i;
			y0 = j;
			break;
		}
	}
	if ((x == x0) && (y == y0))
		return 0;
	if ((abs(x - x0) <= 1) && (abs(y - y0) <= 1))
	{
		if (desk[x][y] == ' ')
		{
			desk[x0][y0] = ' ';
			desk[x][y] = typ;
			return 1;
		}
		else if (vz(x, y, q) == 1)
		{
			desk[x0][y0] = ' ';
			desk[x][y] = typ;
			return 1;
		}
	}
	return 0;
}
int P(int x, int y, int x0, int y0, int q)
{
	char typ;
	int n = 0;

	if (q == 0) // Определить очередь хода
	{
		typ = 'P';
		bool v = 0; // Индетификатор взятия
		cout << n << endl;
		if ((y0 != -1))
		{
			if (abs(y - y0) != 1)
			{
				cout << "Введен ход, не вызывающий доверия" << endl;
				return 0;
			}
			if (x != -1)  // Взятие элитное
			{
				x0 = x + 1;
				v = 1;
				cout << "Взятие с у" << endl;
			}
			else if (x == -1) // Обычное взятие
			{
				for (int i = 0; i < 8; i++)
				{
					if (desk[i][y0] == typ)
					{
						x0 = i;
						x = x0 - 1;
						v = 1;
						cout << "Обычное взятие" << endl;

					}

				}
			}
			else
			{
				cout << "Ошибка определения типа взятия" << endl;
				return 0;
			}

		}
		else // Стандартный ход
		{
			if (x == 4) //Двойной ход
			{
				for (int i = 5; i <= 6; i++)
				{
					cout << "Проверка на двойной ход 1" << endl;
					if (desk[i][y] == typ)
					{
						x0 = i;
						y0 = y;
						cout << "Проверка на двойной ход 2" << endl;
					}

				}
			}
			else // Все-таки обычный ход
			{
				y0 = y;
				x0 = x + 1;
				cout << "Обычный ход" << endl;
			}
		}


		if (desk[x0][y0] == typ)
		{
			if (v == 0)
			{
				if (prp(typ, q, x, x0, y, y0) == 1)
				{
					cout << "Проверка 1 пройдена" << endl;
					desk[x][y] = typ;
					desk[x0][y0] = ' ';
					if (x == 0)
					{
						// Превращение 1
						ura(q, x, y);
					}
					return 1;
				}
				else
				{
					cout << "Ошибка: хреновый ход 1" << endl;
					return 0;
				}

			}
			else
			{
				if (prp(typ, q, x, x0, y, y0) == 2)
				{
					cout << "Проверка 2 пройдена" << endl;
					desk[x][y] = typ;
					desk[x0][y0] = ' ';
					// Превращение 1
					if (x == 0)
					{
						ura(q, x, y);
					}
					return 1;
				}
				else
				{
					cout << "Ошибка: хреновый ход 2" << endl;
					return 0;
				}
			}

		}
		else
			cout << "Ошибка: пешка не найдена" << endl;

	}
	else // -----------------------------------------------------------------------------------------------------------------	
	{
		typ = 'p';
		bool v = 0; // Индетификатор взятия
		cout << n << endl;
		if ((y0 != -1))
		{
			if (abs(y - y0) != 1)
			{
				cout << "Введен ход, не вызывающий доверия" << endl;
				return 0;
			}
			if (x != -1)  // Взятие элитное
			{
				x0 = x - 1;
				v = 1;
				cout << "Взятие с у" << endl;
			}
			else if (x == -1) // Обычное взятие
			{
				for (int i = 0; i < 8; i++)
				{
					if (desk[i][y0] == typ)
					{
						x0 = i;
						x = x0 + 1;
						v = 1;
						cout << "Обычное взятие" << endl;

					}

				}
			}
			else
			{
				cout << "Ошибка определения типа взятия" << endl;
				return 0;
			}

		}
		else // Стандартный ход
		{
			if (x == 3) //Двойной ход
			{
				for (int i = 2; i >= 1; i--)
				{
					cout << "Проверка на двойной ход 1" << endl;
					if (desk[i][y] == typ)
					{
						x0 = i;
						y0 = y;
						cout << "Проверка на двойной ход 2" << endl;
					}

				}
			}
			else // Все-таки обычный ход
			{
				y0 = y;
				x0 = x - 1;
				cout << "Обычный ход" << endl;
			}
		}


		if (desk[x0][y0] == typ)
		{
			if (v == 0)
			{
				if (prp(typ, q, x, x0, y, y0) == 1)
				{
					cout << "Проверка 1 пройдена" << endl;
					desk[x][y] = typ;
					desk[x0][y0] = ' ';
					if (x == 7)
					{
						// Превращение 1
						ura(q, x, y);
					}
					return 1;
				}
				else
				{
					cout << "Ошибка: хреновый ход 1" << endl;
					return 0;
				}

			}
			else
			{
				if (prp(typ, q, x, x0, y, y0) == 2)
				{
					cout << "Проверка 2 пройдена" << endl;
					desk[x][y] = typ;
					desk[x0][y0] = ' ';
					if (x == 7)
					{
						// Превращение 1
						ura(q, x, y);
					}
					return 1;
				}
				else
				{
					cout << "Ошибка: хреновый ход 2" << endl;
					return 0;
				}
			}

		}
		else
			cout << "Ошибка: пешка не найдена" << endl;

	}

	return 0;
}
int C(int x, int y, int x0, int y0, int q)
{
	int n = 0;
	char typ;

	if (q == 0)
		typ = 'C';
	else
		typ = 'c';


	if (x0 != -1 || y0 != -1) // Есть нач кор
	{
		
		if (x0 != -1 && y0 == -1) // Есть х
		{
			for (int i = 0; i < 8; i++)
			{
				if (desk[x0][i] == typ)
				{
					y0 = i;
					n++;
				}
			}
		}
		else if (y0 != -1 && x0 == -1) // Есть у
		{
			for (int i = 0; i < 8; i++)
			{
				if (desk[i][y0] == typ)
				{
					x0 = i;
					n++;
				}
			}
		}
		for (int i = min(x, x0), j = min(y, y0); i < max(x, x0); i++, j++) // проверка на препятствия
		{
			if (desk[i][j] != ' ')
			{
				n = 1000;
			}
		}
	}

	else // Нет нач кор
	{
		
		
		for (int i = x, j = y; i < 8 && j < 8; i++, j++)
		{
			if (desk[i][j] == typ)
			{
				n++;
				x0 = i;
				y0 = j;
			}
			else if (desk[i][j] != ' ')
				break;
		}
		for (int i = x, j = y; i >= 0 && j < 8; i--, j++)
		{
			if (desk[i][j] == typ)
			{
				n++;
				x0 = i;
				y0 = j;
			}
			else if (desk[i][j] != ' ')
				break;
		}
		for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
		{
			if (desk[i][j] == typ)
			{
				n++;
				x0 = i;
				y0 = j;
			}
			else if (desk[i][j] != ' ')
				break;

		}
		for (int i = x, j = y; i < 8 && j >= 0; i++, j--)
		{
			if (desk[i][j] == typ)
			{
				n++;
				x0 = i;
				y0 = j;
			}
			else if (desk[i][j] != ' ')
				break;
		}
		if (n != 1)
		{
			cout << "Ошибка: Найдено несколько возможных фигур для хода:" << n << endl;
			return 0;
		}


	}
	cout << "n = " << n << endl;
	if (n == 1)
	{
		if ((pr(typ, q, x, x0, y, y0) == 1) || (pr(typ, q, x, x0, y, y0) == 2))
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
int Q(int x, int y, int x0, int y0, int q)
{
		int n = 0;
		char typ;

		if (q == 0)
			typ = 'Q';
		else
			typ = 'q';


		if (x0 != -1 || y0 != -1) // Есть нач кор
		{
			if (x0 != -1 && y0 == -1) // Есть х
			{
				for (int i = 0; i < 8; i++)
				{
					if (desk[x0][i] == typ)
					{
						y0 = i;
						n++;
					}
				}
			}
			else if (y0 != -1 && x0 == -1) // Есть у
			{
				for (int i = 0; i < 8; i++)
				{
					if (desk[i][y0] == typ)
					{
						x0 = i;
						n++;
					}
				}

			}
			if (n == 1)
			{
				if (abs(x0 - x) == abs(y0 - y)) // проверка слонового хода
				{
					for (int i = min(x, x0), j = min(y, y0); i < max(x, x0); i++, j++)
					{
						if (desk[i][j] != ' ')
						{
							n = 1000;
						}
					}
				}
				else if (x0 == x) // проверка ладейного хода по у
				{
					for (int i = min(y, y0) + 1; i < max(y, y0); i++)
					{
						if (desk[x][i] != ' ')
							n = 1000;
					}
				}
				else if (y0 == y) // проверка ладейного хода по х
				{
					for (int i = min(x, x0) + 1; i < max(x, x0); i++)
					{
						if (desk[i][y] != ' ')
							n = 1000;
					}
				}
				else
				{
					cout << "Ферзь: я нихрена не нашел" << endl;
					n = 1000;
				}
			}
		}

		else // Нет нач кор
		{

			for (int i = 0; i < 8; i++) // Ищем ФЕРЗЯ
			for (int j = 0; j < 8; j++)
			{
				if (desk[i][j] == typ) // нашли
				{
					int gg = 0;

					if (x == i && y != j) // ладейный ход 1
					{
						for (int o = min(y, j) + 1; o < max(y, j); o++)
						if (desk[x][o] != ' ')
							gg++;

						if (gg == 0)
						{
							x0 = i;
							y0 = j;
							n = 1;
						}
					}

					else if (x != i && y == j) // ладейный ход 2

					{
						for (int o = min(x, i) + 1; o < max(x, i); o++)
						if (desk[o][y] != ' ')
							gg++;
						if (gg == 0)
						{
							x0 = i;
							y0 = j;
							n = 1;
						}
					}
					
					else // слоновый ход
					{
				
						for (int i = x, j = y; i < 8 && j < 8; i++, j++)
						{
							if (desk[i][j] == typ)
							{
								n++;
								x0 = i;
								y0 = j;
							}
							else if (desk[i][j] != ' ')
								break;
						}
						for (int i = x, j = y; i >= 0 && j < 8; i--, j++)
						{
							if (desk[i][j] == typ)
							{
								n++;
								x0 = i;
								y0 = j;
							}
							else if (desk[i][j] != ' ')
								break;
						}
						for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
						{
							if (desk[i][j] == typ)
							{
								n++;
								x0 = i;
								y0 = j;
							}
							else if (desk[i][j] != ' ')
								break;

						}
						for (int i = x, j = y; i < 8 && j >= 0; i++, j--)
						{
							if (desk[i][j] == typ)
							{
								n++;
								x0 = i;
								y0 = j;
							}
							else if (desk[i][j] != ' ')
								break;
						}
					}
				}
			}
		}
		cout << "n = " << n << endl;
		
		if (n == 1)
		{
			if ((pr(typ, q, x, x0, y, y0) == 1))
				return 1;
			else
				return 0;
		}
		else
			return 0;
}
int N(int x, int y, int x0, int y0, int q)
{
	int n = 0;
	char typ;

	if (q == 0)
		typ = 'N';
	else
		typ = 'n';


	if (x0 != -1 || y0 != -1) // Есть нач кор
	{
		if (x0 != -1 && y0 == -1) // Есть х
		{		
			for (int i = 0; i < 8; i++)
			{
				if (desk[x0][i] == typ)
				{
					y0 = i;
					n++;
				}
			}
			
		}
		else if (y0 != -1 && x0 == -1) // Есть у
		{
			for (int i = 0; i < 8; i++)
			{
				if (desk[i][y0] == typ)
				{
					x0 = i;
					n++;
				}
			}
		}

		if (((abs(x - x0) == 2) && (abs(y - y0) == 1)) || ((abs(x - x0) == 2) && (abs(y - y0) == 1)) || ((abs(x - x0) == 1) && (abs(y - y0) == 2)) || ((abs(x - x0) == 1) && (abs(y - y0) == 2))) //корректность хода
		{
			n = 1;
		}
		else
		{
			cout << "Конь: ты шо" << endl;
			n = 1000;
		}
	}

	else // Нет нач кор
	{

		for (int i = 0; i < 8; i++) // Ищем nursov
		for (int j = 0; j < 8; j++)
		{
			if (desk[i][j] == typ)
			{
				if (((abs(x - i) == 2) && (abs(y - j) == 1)) || ((abs(x - i) == 2) && (abs(y - j) == 1)) || ((abs(x - i) == 1) && (abs(y - j) == 2)) || ((abs(x - i) == 1) && (abs(y - j) == 2)))
				{
					n++;
					x0 = i;
					y0 = j;
				}
			}
		}
	}
	cout << "n = " << n << endl;
	if (n == 1)
	{

		if ((pr(typ, q, x, x0, y, y0) == 1) || (pr(typ, q, x, x0, y, y0) == 2))
			return 1;
		else
			return 0;
	}
	else
		return 0;
}