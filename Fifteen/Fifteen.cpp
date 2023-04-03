#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;

const int SIZE = 4;

#define MOVE_LEFT 75  //Задание переменных для отлова с клавиатуры
#define MOVE_RIGHT 77
#define MOVE_UP 72
#define MOVE_DOWN 80
#define ESC 27

void Fill_Grid(int grid[SIZE][SIZE], int SIZE); //Функция заполнения сетки
void Print_Grid(int grid[SIZE][SIZE], int SIZE); // Функция вывода сетки
void Move_Up(int grid[SIZE][SIZE], int SIZE, int *pemp_i, int* pemp_j); //Функции перемещения пустого блока
void Move_Down(int grid[SIZE][SIZE], int SIZE, int *pemp_i, int* pemp_j);
void Move_Right(int grid[SIZE][SIZE], int SIZE, int *pemp_i, int* pemp_j);
void Move_Left(int grid[SIZE][SIZE], int SIZE, int *pemp_i, int* pemp_j);
void Mix_Grid(int grid[SIZE][SIZE], int arr_move[SIZE], int SIZE, int* pemp_i, int *pemp_j); //Функция перемешивания сетки
int Check_Win(int grid[SIZE][SIZE], int SIZE, int control); //Функция проерки сетки на попеду

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int grid[SIZE][SIZE] = {};
	int arr_move[SIZE] = { MOVE_UP, MOVE_LEFT, MOVE_RIGHT, MOVE_DOWN };
	int control, emp_i, emp_j;
	emp_i = emp_j = SIZE - 1;

	int *pemp_i, *pemp_j;
	pemp_i = &emp_i;
	pemp_j = &emp_j;

	Fill_Grid(grid, SIZE);
	Mix_Grid(grid, arr_move, SIZE, pemp_i, pemp_j);
	Print_Grid(grid, SIZE);
	cout << "\nПравила: Необходимо расположить числа в порядке возрастания начиная с верхнего левого угла.";
	cout << "\nПеремещение чисел осуществляется перемещением пустого квадрата стрелочками.";	

	do //Цикл отлова событий
	{
		control = _getch();
		switch (control)
		{
		case MOVE_UP: Move_Up(grid, SIZE, pemp_i, pemp_j); Print_Grid(grid, SIZE); control = Check_Win(grid, SIZE, control); break;
		case MOVE_DOWN: Move_Down(grid, SIZE, pemp_i, pemp_j); Print_Grid(grid, SIZE); control = Check_Win(grid, SIZE, control); break;
		case MOVE_RIGHT: Move_Right(grid, SIZE, pemp_i, pemp_j); Print_Grid(grid, SIZE); control = Check_Win(grid, SIZE, control); break;
		case MOVE_LEFT: Move_Left(grid, SIZE, pemp_i, pemp_j); Print_Grid(grid, SIZE); control = Check_Win(grid, SIZE, control); break;
		}
	} while (control != ESC);
}

void Fill_Grid(int grid[SIZE][SIZE], int SIZE)
{
	int cnt = 1;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < (i==SIZE-1? SIZE-1 : SIZE); j++)
		{
			grid[i][j] = cnt;
			cnt++;			
		}
	}
}

void Print_Grid(int grid[SIZE][SIZE], int SIZE)
{
	system("cls");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (grid[i][j] == 0) cout << "[    ] ";
			else if (grid[i][j]<10) cout << "[  " << grid[i][j] << " ] ";
			else if (grid[i][j] >= 10) cout << "[ " << grid[i][j] << " ] ";
		}
		cout << endl;
	}
}

void Move_Up(int grid[SIZE][SIZE], int SIZE, int* pemp_i, int* pemp_j)
{
	if (*pemp_i != 0)
	{
		grid[(*pemp_i) - 1][*pemp_j] ^= grid[*pemp_i][*pemp_j];
		grid[*pemp_i][*pemp_j] ^= grid[(*pemp_i) - 1][*pemp_j];
		grid[(*pemp_i) - 1][*pemp_j] ^= grid[*pemp_i][*pemp_j];
		*pemp_i = *pemp_i - 1;
	}
}
void Move_Down(int grid[SIZE][SIZE], int SIZE, int* pemp_i, int* pemp_j)
{
	if (*pemp_i != SIZE - 1)
	{
		grid[(*pemp_i) + 1][*pemp_j] ^= grid[*pemp_i][*pemp_j];
		grid[*pemp_i][*pemp_j] ^= grid[(*pemp_i) + 1][*pemp_j];
		grid[(*pemp_i) + 1][*pemp_j] ^= grid[*pemp_i][*pemp_j];
		*pemp_i = *pemp_i + 1;
	}
}
void Move_Right(int grid[SIZE][SIZE], int SIZE, int* pemp_i, int* pemp_j)
{
	if (*pemp_j != SIZE - 1)
	{
		grid[*pemp_i][(*pemp_j) + 1] ^= grid[*pemp_i][*pemp_j];
		grid[*pemp_i][*pemp_j] ^= grid[*pemp_i][(*pemp_j) + 1];
		grid[*pemp_i][(*pemp_j) + 1] ^= grid[*pemp_i][*pemp_j];
		*pemp_j = *pemp_j + 1;
	}
}
void Move_Left(int grid[SIZE][SIZE], int SIZE, int* pemp_i, int* pemp_j)
{
	if (*pemp_j != 0)
	{
		grid[*pemp_i][(*pemp_j) - 1] ^= grid[*pemp_i][*pemp_j];
		grid[*pemp_i][*pemp_j] ^= grid[*pemp_i][(*pemp_j) - 1];
		grid[*pemp_i][(*pemp_j) - 1] ^= grid[*pemp_i][*pemp_j];
		*pemp_j = *pemp_j - 1;
	}
}

void Mix_Grid(int grid[SIZE][SIZE], int arr_move[SIZE], int SIZE, int *pemp_i, int *pemp_j)
{
	int cntrl, old_cntrl = SIZE;
	for (int i = 0; i < 100; )
	{
		int cntrl = rand() % 4;
		if (cntrl != old_cntrl)
		{
			if (arr_move[cntrl] == MOVE_UP) Move_Up(grid, SIZE, pemp_i, pemp_j);
			else if (arr_move[cntrl] == MOVE_DOWN) Move_Down(grid, SIZE, pemp_i, pemp_j);
			else if (arr_move[cntrl] == MOVE_RIGHT) Move_Right(grid, SIZE, pemp_i, pemp_j);
			else if (arr_move[cntrl] == MOVE_LEFT) Move_Left(grid, SIZE, pemp_i, pemp_j);
			i++;
		}
		old_cntrl = cntrl;
	}
}

int Check_Win(int grid[SIZE][SIZE], int SIZE, int control)
{
	int check = 1;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < (i == SIZE - 1 ? SIZE - 1 : SIZE); j++)
		{
			if (grid[i][j] == check) check++;
			else return 0;
		}
	}
	cout << "\n\t Победа!\n"; 
	return control = ESC;
}