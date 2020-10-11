#pragma once

#include <iostream>
#include <string>
#include <map>
#include<algorithm>
int c = 0;
char type;
int xq;
int yq;

int mate(int, int, int);
int pere(int, int, int);
int check(int, int, int);




int sw(int q) // Смена цвета
{
	if (q == 0)
		return 1;
	else
		return 0;
}
int pere(int x, int y, int q) // Функция проверки закрытия/взятия //гребаная функция, задолбала, работай давай
{
	int n = 0;
	cout << "Функция pere начала работу и опять нихрена" << endl;
	
	cout << type << endl;
	if (type == 'k')
	{
		if (check(xq, yq, sw(q) == 0))
			return 1;
	}
	else if (type == 'p')
	{
		if (check(xq, yq, sw(q) == 0))
			return 1;
	}
	else if (type == 'd')
	{
		for (int i = min(x, xq)+1, j = min(y, yq)+1; i < max(x, xq); i++, j++) 
		{
			if (check(i, j, sw(q) == 1))
			{
				n++;
			}
		}
		if (check(xq, yq, sw(q) == 0))
			n++;
		if (n == 0)
			return 1;
		else
			return 0;
	}
	else // Ладейный ход
	{
		if (yq == y)
		{
			for (int i = min(x, xq)+1; i < (x, xq); i++)
			{
				if (check(x, i, sw(q) == 1))
				{
					n++;
				}
			}
		}
		else
		{
			for (int i = min(y, yq) + 1; i < (y, yq); i++)
			{
				if (check(i, y, sw(q) == 1))
				{
					n++;
				}
			}
		}
		if (check(xq, yq, sw(q) == 0))
			n++;

		if (n == 0)
			return 1;
	}
	return 0;
}
int poisk(int q)
{
	char typ;
	int x, y;
	
	if (q == 0) // Определили очередь хода
	{
		typ = 'K';
	}
	else {

		typ = 'k';
	}


	for (int i = 0; i < 8; i++) // Ищем короля
	for (int j = 0; j < 8; j++)
	{
		if (desk[i][j] == typ) // Определили координаты
		{
			x = i;
			y = j;
		}
	}

	if (check(x, y, q) == 0)
		return 0;
	else
		if (mate(x, y, q) == 1)
			return 1;
		else
			return 2;
}
int check(int x, int y, int q)
{
	int ff;
	char g[5];
	if (q == 1) // Определили очередь хода
	{
		g[0] = 'Q';
		g[1] = 'R';
		g[2] = 'C';
		g[3] = 'N';
		g[4] = 'P';
		ff = 1;
	}
	else {
		g[0] = 'q';
		g[1] = 'r';
		g[2] = 'c';
		g[3] = 'n';
		g[4] = 'p';
		ff = -1;
		
	
	}
	
	if ((x > 7) || (x < 0) || (y<0) || (y>7))
		return 666;

	for (int i = x+1; i < 8; i++) // Проверочка на ладьи и ферзи
	{
		if ((desk[i][y] == g[0]) || (desk[i][y] == g[1]))
		{
			c++;
			xq = i;
			yq = y;
			type = 'v';
		
		}
		else if (desk[i][y] != ' ')
			break;
	}
	for (int i = x-1; i > -1; i--)
	{
		if ((desk[i][y] == g[0]) || (desk[i][y] == g[1]))
		{
			c++;

			xq = i;
			yq = y;
			type = 'v';
		}
		else if (desk[i][y] != ' ')
			break;
	}
	for (int i = y+1; i < 8; i++)
	{
		if ((desk[x][i] == g[0]) || (desk[x][i] == g[1]))
		{
			c++;
			xq = x;
			yq = i;
			type = 'v';
		}
		else if (desk[i][y] != ' ')
			break;
	}
	for (int i = y-1; i > -1; i--)
	{
		if ((desk[x][i] == g[0]) || (desk[x][i] == g[1]))
		{
			c++;
			xq = x;
			yq = i;
			type = 'v';
		}
		else if (desk[i][y] != ' ')
			break;
	}



	for (int i = x+1, j = y+1; i < 8 && j < 8; i++, j++) // Проверочка на слонов и ферзей
	{
		if ((desk[i][j] == g[0]) || (desk[i][j] == g[2]))
		{
			c++;
			xq = i;
			yq = j;
			type = 'd';
		}
		else if (desk[i][j] != ' ')
			break;
	}
	for (int i = x-1, j = y+1; i >= 0 && j < 8; i--, j++)
	{
		if ((desk[i][j] == g[0]) || (desk[i][j] == g[2]))
		{
			c++;
			xq = i;
			yq = j;
			type = 'd';
			
		}
		else if (desk[i][j] != ' ')
			break;
	}
	for (int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--)
	{
		if ((desk[i][j] == g[0]) || (desk[i][j] == g[2]))
		{
			c++;
			xq = i;
			yq = j;
			type = 'd';
		}
		else if (desk[i][j] != ' ')
			break;

	}
	for (int i = x+1, j = y-1; i < 8 && j >= 0; i++, j--)
	{
		if ((desk[i][j] == g[0]) || (desk[i][j] == g[2]))
		{
			c++;
			xq= i;
			yq = j;
			type = 'd';
		}
		else if (desk[i][j] != ' ')
			break;
	}


	for (int i = 0; i < 8; i++) // Проверочка на коней
	for (int j = 0; j < 8; j++)
	{
		if (desk[i][j] == g[3])
		{
			if (((abs(x - i) == 2) && (abs(y - j) == 1)) || ((abs(x - i) == 2) && (abs(y - j) == 1)) || ((abs(x - i) == 1) && (abs(y - j) == 2)) || ((abs(x - i) == 1) && (abs(y - j) == 2)))
			{
				c++;
				xq = i;
				yq= j;
				type = 'k';
			}
		}
	}

	if (desk[x + ff][y + 1] == g[4]) // Проверочка на пешки
	{
		cout << q;
		c++;
		xq = x+ff;
		yq = y+1;
		type = 'p';
	}
	else if (desk[x + ff][y - 1] == g[4])
	{
		cout << q;
		c++;
		xq = x+ff;
		yq = y-1;
		type = 'p';
	}

	if (c == 0)
	{
		cout << "Для q = " << q << "шаха нет" << endl;
			return 0;
	}
	else
		return 1;
}
int mate(int x, int y, int q) // Проверка на мат
{
	
	if (c == 1) // Single check
	{
		if (check(x + 1, y, q) == 0)
		{
			if (desk[x+1][y] == ' ')
			return 0;
		}
		else if (check(x, y + 1, q) == 0)
		{
			if (desk[x][y+1] == ' ')
			return 0;
		}
		else if (check(x + 1, y + 1, q) == 0)
		{
			if (desk[x+1][y+1] == ' ')
			return 0;
		}
		else if (check(x - 1, y, q) == 0)
		{
			if (desk[x-1][y] == ' ')
			return 0;
		}
		else if (check(x, y - 1, q) == 0)
		{
			if (desk[x][y-1] == ' ')
			return 0;
		}
		else if (check(x - 1, y - 1, q) == 0)
		{
			if (desk[x-1][y-1] == ' ')
			return 0;
		}
		else if (check(x + 1, y - 1, q) == 0)
		{
			if (desk[x+1][y-1] == ' ')
			return 0;
		}
		else if (check(x - 1, y + 1, q) == 0)
		{
			if (desk[x-1][y+1] == ' ')
			return 0;
		}

		if (pere(x, y, q) == 1)
		{
			return 1;
		}
		else
			return 0;

	}
	else // Double check
	{
		if (check(x+1, y, q) == 0)
		{
			return 0;
		}
		else if (check(x, y+1, q) == 0)
		{
			return 0;
		}
		else if (check(x+1, y+1, q) == 0)
		{
			return 0;
		}
		else if (check(x-1, y, q) == 0)
		{
			return 0;
		}
		else if (check(x, y-1, q) == 0)
		{
			return 0;
		}
		else if (check(x-1, y-1, q) == 0)
		{
			return 0;
		}
		else if (check(x+1, y-1, q) == 0)
		{
			return 0;
		}
		else if (check(x-1, y+1, q) == 0)
		{
			return 0;
		}
		if (pere(x, y, q) == 1)
			return 1;
		else
			return 0;
	}

}



