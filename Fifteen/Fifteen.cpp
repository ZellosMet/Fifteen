#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;

const int SIZE1 = 4;

#define MOVE_LEFT 75  //Задание переменных для отлова с клавиатуры
#define MOVE_RIGHT 77
#define MOVE_UP 72
#define MOVE_DOWN 80
#define ESC 27

void Fill_Grid(int grid[SIZE1][SIZE1], int SIZE1);
void Print_Grid(int grid[SIZE1][SIZE1], int SIZE1);
void Move_Up(int grid[SIZE1][SIZE1], int SIZE1, int *pemp_i, int* pemp_j);
void Move_Down(int grid[SIZE1][SIZE1], int SIZE1, int *pemp_i, int* pemp_j);
void Move_Right(int grid[SIZE1][SIZE1], int SIZE1, int *pemp_i, int* pemp_j);
void Move_Left(int grid[SIZE1][SIZE1], int SIZE1, int *pemp_i, int* pemp_j);
void Mix_Grid(int grid[SIZE1][SIZE1], int arr_move[SIZE1], int SIZE1, int* pemp_i, int *pemp_j);

void main()
{
	srand(time(NULL));

	int grid[SIZE1][SIZE1] = {};
	int arr_move[SIZE1] = { MOVE_UP, MOVE_LEFT, MOVE_RIGHT, MOVE_DOWN };
	int control;
	int emp_i, emp_j;
	emp_i = emp_j = SIZE1 - 1;

	int *pemp_i, *pemp_j;
	pemp_i = &emp_i;
	pemp_j = &emp_j;

	Fill_Grid(grid, SIZE1);
	Mix_Grid(grid, arr_move, SIZE1, pemp_i, pemp_j);
	Print_Grid(grid, SIZE1);

	do //Цикл отлова событий
	{
		control = _getch();
		switch (control)
		{
		case MOVE_UP: Move_Up(grid, SIZE1, pemp_i, pemp_j); Print_Grid(grid, SIZE1); break;
		case MOVE_DOWN: Move_Down(grid, SIZE1, pemp_i, pemp_j); Print_Grid(grid, SIZE1); break;
		case MOVE_RIGHT: Move_Right(grid, SIZE1, pemp_i, pemp_j); Print_Grid(grid, SIZE1); break;
		case MOVE_LEFT: Move_Left(grid, SIZE1, pemp_i, pemp_j); Print_Grid(grid, SIZE1); break;
		}
	} while (control != ESC);
}

void Fill_Grid(int grid[SIZE1][SIZE1], int SIZE1)
{
	int cnt = 1;
	for (int i = 0; i < SIZE1; i++)
	{
		for (int j = 0; j < (i==SIZE1-1? SIZE1-1 : SIZE1); j++)
		{
			grid[i][j] = cnt;
			cnt++;			
		}
	}
}

void Print_Grid(int grid[SIZE1][SIZE1], int SIZE1)
{
	system("cls");
	for (int i = 0; i < SIZE1; i++)
	{
		for (int j = 0; j < SIZE1; j++)
		{
			if (grid[i][j] == 0)
			{
				cout << "[    ] ";
			}
			else if (grid[i][j]<10)
			{
				cout << "[  " << grid[i][j] << " ] ";
			}
			else if (grid[i][j] >= 10)
			{
				cout << "[ " << grid[i][j] << " ] ";
			}
		}
		cout << endl;
	}
}

void Move_Up(int grid[SIZE1][SIZE1], int SIZE1, int* pemp_i, int* pemp_j)
{
	if (*pemp_i != 0)
	{
		grid[(*pemp_i) - 1][*pemp_j] ^= grid[*pemp_i][*pemp_j];
		grid[*pemp_i][*pemp_j] ^= grid[(*pemp_i) - 1][*pemp_j];
		grid[(*pemp_i) - 1][*pemp_j] ^= grid[*pemp_i][*pemp_j];
		*pemp_i = *pemp_i - 1;
	}
}
void Move_Down(int grid[SIZE1][SIZE1], int SIZE1, int* pemp_i, int* pemp_j)
{
	if (*pemp_i != SIZE1 - 1)
	{
		grid[(*pemp_i) + 1][*pemp_j] ^= grid[*pemp_i][*pemp_j];
		grid[*pemp_i][*pemp_j] ^= grid[(*pemp_i) + 1][*pemp_j];
		grid[(*pemp_i) + 1][*pemp_j] ^= grid[*pemp_i][*pemp_j];
		*pemp_i = *pemp_i + 1;
	}
}
void Move_Right(int grid[SIZE1][SIZE1], int SIZE1, int* pemp_i, int* pemp_j)
{
	if (*pemp_j != SIZE1 - 1)
	{
		grid[*pemp_i][(*pemp_j) + 1] ^= grid[*pemp_i][*pemp_j];
		grid[*pemp_i][*pemp_j] ^= grid[*pemp_i][(*pemp_j) + 1];
		grid[*pemp_i][(*pemp_j) + 1] ^= grid[*pemp_i][*pemp_j];
		*pemp_j = *pemp_j + 1;
	}
}
void Move_Left(int grid[SIZE1][SIZE1], int SIZE1, int* pemp_i, int* pemp_j)
{
	if (*pemp_j != 0)
	{
		grid[*pemp_i][(*pemp_j) - 1] ^= grid[*pemp_i][*pemp_j];
		grid[*pemp_i][*pemp_j] ^= grid[*pemp_i][(*pemp_j) - 1];
		grid[*pemp_i][(*pemp_j) - 1] ^= grid[*pemp_i][*pemp_j];
		*pemp_j = *pemp_j - 1;
	}
}

void Mix_Grid(int grid[SIZE1][SIZE1], int arr_move[SIZE1], int SIZE1, int *pemp_i, int *pemp_j)
{
	int cntrl, old_cntrl = 5;
	for (int i = 0; i <= 100; )
	{
		int cntrl = rand() % 4;
		if (cntrl != old_cntrl)
		{
			if (arr_move[cntrl] == MOVE_UP) Move_Up(grid, SIZE1, pemp_i, pemp_j);
			else if (arr_move[cntrl] == MOVE_DOWN) Move_Down(grid, SIZE1, pemp_i, pemp_j);
			else if (arr_move[cntrl] == MOVE_RIGHT) Move_Right(grid, SIZE1, pemp_i, pemp_j);
			else if (arr_move[cntrl] == MOVE_LEFT) Move_Left(grid, SIZE1, pemp_i, pemp_j);
			i++;
		}
		old_cntrl = cntrl;
	}
}