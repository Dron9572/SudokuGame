#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
#include <math.h> 
#include <conio.h>

void Show_Desk_Sudoku(char sq[13][9], char sq_dop[13][1])
{
	system("cls");
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == 0)
				printf("%c   ", sq_dop[i][j]);

			if (j == 3 || j == 6)
				printf("\t");

			if (j != 3 || j != 6 || j != 9)
				printf("%c   ", sq[i][j]);
			else
				printf("%c", sq[i][j]);
		}
		printf("\n");
	}

	char down_line = '-';
	printf("\n");
	for (int i = 0; i < 50; i++)
		printf("%c", down_line);
	printf("\nWrite \"EX\" to end the game\n");
}

void Enter_Location(char loc[])
{
	char temp = ' ';

	printf("\nEnter the location in the format (A1): ");
	for (int i = 0; i < 2; i++)
		scanf_s("%c", &loc[i]);
	scanf_s("%c", &temp);
}

char Enter_Value()
{
	char temp = ' ', res = ' ';

	printf("\nEnter a value: ");
	scanf_s("%c", &res);
	scanf_s("%c", &temp);

	return res;
}

void Change_Value_Sudoku(int r, int s, char sq[13][9], char val)
{
	sq[r][s] = val;
}

int Search_Rad(int temp)
{
	if (temp <= 3)
		temp += 1;
	else if (temp >= 4 && temp <= 6)
		temp += 2;
	else if (temp >= 7 && temp <= 9)
		temp += 3;

	return temp;
}

void Search_Location(int& r, int& s, char loc[])
{
	switch (loc[0])
	{
	case 'A':
		r = Search_Rad(loc[1] - '0');
		s = 0;
		break;
	case 'B':
		r = Search_Rad(loc[1] - '0');
		s = 1;
		break;
	case 'C':
		r = Search_Rad(loc[1] - '0');
		s = 2;
		break;
	case 'D':
		r = Search_Rad(loc[1] - '0');
		s = 3;
		break;
	case 'E':
		if (loc[1] == 'X' || loc[1] == 'x')
		{
			r = -2;
			s = -2;
		}
		else
		{
			r = Search_Rad(loc[1] - '0');
			s = 4;
		}
		break;
	case 'F':
		r = Search_Rad(loc[1] - '0');
		s = 5;
		break;
	case 'G':
		r = Search_Rad(loc[1] - '0');
		s = 6;
		break;
	case 'H':
		r = Search_Rad(loc[1] - '0');
		s = 7;
		break;
	case 'O':
		r = Search_Rad(loc[1] - '0');
		s = 8;
		break;
	case 'a':
		r = Search_Rad(loc[1] - '0');
		s = 0;
		break;
	case 'b':
		r = Search_Rad(loc[1] - '0');
		s = 1;
		break;
	case 'c':
		r = Search_Rad(loc[1] - '0');
		s = 2;
		break;
	case 'd':
		r = Search_Rad(loc[1] - '0');
		s = 3;
		break;
	case 'e':
		if (loc[1] == 'X' || loc[1] == 'x')
		{
			r = -2;
			s = -2;
		}
		else
		{
			r = Search_Rad(loc[1] - '0');
			s = 4;
		}
		break;
	case 'f':
		r = Search_Rad(loc[1] - '0');
		s = 5;
		break;
	case 'g':
		r = Search_Rad(loc[1] - '0');
		s = 6;
		break;
	case 'h':
		r = Search_Rad(loc[1] - '0');
		s = 7;
		break;
	case 'o':
		r = Search_Rad(loc[1] - '0');
		s = 8;
		break;
	default:
		s = -1;
		r = -1;
		break;
	}
}

void Game_Close()
{
	system("cls");
	printf("Thanks for playing!!!");
}

void Search_Square(int r, int s, int& finish_r, int& finish_s, int& start_r, int& start_s)
{
	if ((r >= 2 && r <= 4) && (s >= 0 && s <= 2)) //Square 0
	{
		start_r = 2;
		finish_r = 4;
		start_s = 0;
		finish_s = 2;
	}
	else if ((r >= 2 && r <= 4) && (s >= 3 && s <= 5)) //Square 1
	{
		start_r = 2;
		finish_r = 4;
		start_s = 3;
		finish_s = 5;
	}
	else if ((r >= 2 && r <= 4) && (s >= 6 && s <= 8)) //Square 2
	{
		start_r = 2;
		finish_r = 4;
		start_s = 6;
		finish_s = 8;
	}
	else if ((r >= 6 && r <= 8) && (s >= 0 && s <= 2)) //Square 3
	{
		start_r = 6;
		finish_r = 8;
		start_s = 0;
		finish_s = 2;
	}
	else if ((r >= 6 && r <= 8) && (s >= 3 && s <= 5)) //Square 4
	{
		start_r = 6;
		finish_r = 8;
		start_s = 3;
		finish_s = 5;
	}
	else if ((r >= 6 && r <= 8) && (s >= 6 && s <= 8)) //Square 5
	{
		start_r = 6;
		finish_r = 8;
		start_s = 6;
		finish_s = 8;
	}
	else if ((r >= 10 && r <= 12) && (s >= 0 && s <= 2)) //Square 6
	{
		start_r = 10;
		finish_r = 12;
		start_s = 0;
		finish_s = 2;
	}
	else if ((r >= 10 && r <= 12) && (s >= 3 && s <= 5)) //Square 7
	{
		start_r = 10;
		finish_r = 12;
		start_s = 3;
		finish_s = 5;
	}
	else if ((r >= 10 && r <= 12) && (s >= 6 && s <= 8)) //Square 8
	{
		start_r = 10;
		finish_r = 12;
		start_s = 6;
		finish_s = 8;
	}
}

int Check_Square(int finish_r, int finish_s, int start_r, int start_s, char sq[13][9], char val)
{
	int temp = 0;

	for (int i = start_r; i != finish_r; i++)
	{
		for (int j = start_s; j != finish_s; j++)
		{
			if (sq[i][j] != val)
				temp = 1;
			else
				return 0;
		}
	}

	return temp;
}

int Check_Value(int r, int s, char sq[13][9], char val)
{
	int temp = 0;

	if (sq[r][s] == val) temp = 2;
	else
	{
		for (int i = 0; i < 9; i++)
			if (i != s)
			{
				if (sq[r][i] != val)
					temp = 1;
				else
				{
					temp = 0;
					break;
				}
			}

		if (temp != 0)
			for (int i = 2; i < 13; i++)
				if (r != i && i != 5 && i != 9)
				{
					if (sq[i][s] != val)
						temp = 1;
					else
					{
						temp = 0;
						break;
					}
				}

		if (temp != 0)
		{
			int finish_r, finish_s, start_r, start_s;
			Search_Square(r, s, finish_r, finish_s, start_r, start_s);
			temp = Check_Square(finish_r, finish_s, start_r, start_s, sq, val);
		}
	}
	return temp;
}

int Check_Game_End(char sq[13][9])
{
	int check = 1;

	for (int i = 2; i < 13; i++)
		if (i != 5 || i != 9)
			for (int j = 0; j < 9; j++)
			{
				if (sq[i][j] == '0')
				{
					check = 1;
					return check;
				}
				else
					check = 0;
			}

	return check;
}

void Create_Map(char sq[13][9], char pole[])
{
	char arr[117];
	int i = 0;
	FILE* fl;
	errno_t err;
	err = fopen_s(&fl, pole, "r");

	if (err != 0)
	{
		printf("ERROR: File not found, check files and restart the program.\n\nPress \"Enter\" to continue");
		_getch();
		exit(1);
	}

	while (fgets(arr, 117, fl) != NULL)
	{
		for (int j = 0; j < 9; j++)
			sq[i][j] = arr[j];
		i++;
	}

	fclose(fl);
}

void Random_Map(char sq[13][9])
{
	int temp = rand() % (4 + 1);
	if (temp == 1)
	{
		char f1[] = "Maps/1.txt";
		Create_Map(sq, f1);
	}
	else if (temp == 2)
	{
		char f2[] = "Maps/2.txt";
		Create_Map(sq, f2);
	}
	else if (temp == 3)
	{
		char f3[] = "Maps/3.txt";
		Create_Map(sq, f3);
	}
}

void Start_Game()
{
	char sq[13][9];
	Random_Map(sq);
	char sq_dop[13][1] = {
		' ', ' ', '1','2','3', ' ', '4','5','6', ' ', '7','8','9'
	};
	int game = 1;
	char loc[2];
	char val = ' ';

	Show_Desk_Sudoku(sq, sq_dop);

	while (game == 1)
	{
		Enter_Location(loc);

		int r = 0, s = 0;
		Search_Location(r, s, loc);

		if (r == -1 || s == -1)
		{
			printf("\nSyntax error, try setting again\nPress \"Enter\" to continue");
			_getch();
		}
		else if (r == -2 || s == -2)
			game = 0;
		else
		{
			val = Enter_Value();
			game = Check_Value(r, s, sq, val);
			if (game == 0)
			{
				printf("\nThis value is not suitable, try again\nPress \"Enter\" to continue");
				_getch();
				game = 1;
			}
			else if (game == 2)
			{
				printf("\nThis value is already in this cell\nPress \"Enter\" to continue");
				_getch();
				game = 1;
			}
			else
			{
				Change_Value_Sudoku(r, s, sq, val);
				game = Check_Game_End(sq);
			}
		}

		Show_Desk_Sudoku(sq, sq_dop);
	}

	Game_Close();
}

int main()
{
	Start_Game();
}