#include <iostream>
#include <string>
#include"Decrypt.h"
#include<algorithm>

using namespace std;
extern char desk[8][8] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
extern char pr1[6] = { 'Q', 'N', 'R', 'K', 'C', 'P' };
extern char pr2[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
extern char pr3[6] = { 'q', 'n', 'r', 'k', 'c', 'p' };
#include"figures.h"
#include"Check.h"



int main()
{
	setlocale(LC_CTYPE, "RUS");
	char typefigure;
	char *ptype = &typefigure;
	int q = 0;
	//    int res = -1;
	//    int que = 0;
	//	  int *qq = &que;

	int x1;
	int y1;
	int *x1p = &x1;
	int *y1p = &y1;
	int x0, y0;
	int buff;
	int *y00 = &y0;
	int *x00 = &x0;

	string move;


	init();//init fig


	for (;;) //game
	{
		x0 = -1; 
		x1 = -1;
		y0 = -1;
		y1 = -1;

		cout << " " << " ";
		for (int i = 0; i < 8; i++)
		{
			cout << i << " ";
		}
		cout << endl;

		for (int i = 0; i < 8; i++) //Output desk
		{
			cout << i << " ";
			for (int j = 0; j < 8; j++)
			{
				cout << desk[i][j] << " ";
				if (j == 7)
					cout << endl;
			}
		} 
		if (q == 0)
			cout << "Ход белых..." << endl;
		else
			cout << "Ход черных..." << endl;
		cin >> move;

		buff = retmove(x1p, y1p, move, ptype, x00, y00); //Decrypt
		if (buff == 1)
			cout << "Расшифровано успешно" << endl;
		else
			cout << "Ошибка расшифровки" << endl;
		
		switch (typefigure) // Выбор соответствующей фигуры
		{
			case 'Q':
			{
			  buff = Q(x1, y1, x0, y0, q);
			  break;
			}
			case 'K':
			{
			    buff = K(x1, y1, q);
				break;
			}
			case 'R':
			{
				buff = R(x1, y1, x0, y0, q);
				break;
			}
			case 'N':
			{
				buff = N(x1, y1, x0, y0, q);
				break;
			}
			case 'C':
			{
				buff = C(x1, y1, x0, y0, q);
				break;
			}
			case 'p':
			{
				buff = P(x1, y1, x0, y0, q);
				break;
			}
		}
		if (buff == 1)
		{
			cout << "Ход заделан" << endl;
			if (q == 0)
				q = 1;
			else
				q = 0;
			
		}
		else
			cout << "Ход не забацан" << endl;
		buff = poisk(q);
		
		if (buff == 1)
			cout << "Мат" << endl;
		else if (buff == 2)
			cout << "Шах" << endl;

		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}
