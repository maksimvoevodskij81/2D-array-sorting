#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void showArr(int arr[][5], const int  SIZE_ROW, const int SIZE_COL);
void fillArr(int arr[][5], const int  SIZE_ROW, const int SIZE_COL);
const int SIZE_ROW = 5;
const int SIZE_COL = 5;
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int arr[SIZE_ROW][SIZE_COL];
	int tmp = 0;
	int tmpIndexRow = 0;
	int tmpIndexCol = 0;
	fillArr(arr, SIZE_ROW, SIZE_COL);
	showArr(arr, SIZE_ROW, SIZE_COL);
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	
			for (int h = 0; h < SIZE_ROW; h++)
			{
				for (int v = 0; v < SIZE_COL; v++)
				{
						tmp = arr[h][v];
						tmpIndexRow = h;
						tmpIndexCol = v;
					
					for (int i = h + 1; i < SIZE_ROW; i++)
					{
						for (int j = v + 1; j < SIZE_COL; j++)
						{
							if (tmp > arr[h][v])
							{
								tmp = arr[i][j];
								tmpIndexRow = i;
								tmpIndexCol = j;
							}
						}
					}
					arr[tmpIndexRow][tmpIndexCol] = arr[h][v];
					arr[h][v] = tmp;
				}
			}
	
	showArr(arr, SIZE_ROW, SIZE_COL);
}
void showArr(int arr[][5], const int  SIZE_ROW, const int SIZE_COL)
{
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void fillArr(int arr[][5], const int  SIZE_ROW, const int SIZE_COL)
{
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			arr[i][j] = rand() % 50;

		}
	}
}