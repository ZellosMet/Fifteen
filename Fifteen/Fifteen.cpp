#include<iostream>
#include<conio.h>
using namespace std;

const int SIZE = 4;

#define MOVE_LEFT 75  //Задание переменных для отлова с клавиатуры
#define MOVE_RIGHT 77
#define MOVE_UP 72
#define MOVE_DOWN 80
#define ESC 27

void Fill_Grid(int arr[SIZE][SIZE], int size);
void Print_Grid(int arr[SIZE][SIZE], int size);
void Move(int arr[SIZE][SIZE], int SIZE);

void main()
{
	int arr[SIZE][SIZE] = {};
	int control;

	Fill_Grid(arr, SIZE);
	Print_Grid(arr, SIZE);

	do //Цикл отлова событий
	{
		control = _getch();
		switch (control)
		{
		case MOVE_UP: Check_Move_Сursor(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_DOWN: Check_Move_Сursor(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_RIGHT: Check_Move_Сursor(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_LEFT: Check_Move_Сursor(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		}
	} while (control != ESC);
}

void Fill_Grid(int arr[SIZE][SIZE], int size)
{
	int cnt = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < (i==size-1? size-1 : size); j++)
		{
			arr[i][j] = cnt;
			cnt++;			
		}
	}
}

void Print_Grid(int arr[SIZE][SIZE], int size)
{

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << "[    ]";
			}
			else if (arr[i][j]<10)
			{
				cout << "[  " << arr[i][j] << " ] ";
			}
			else if (arr[i][j] >= 10)
			{
				cout << "[ " << arr[i][j] << " ] ";
			}
		}
		cout << endl;
	}
}

