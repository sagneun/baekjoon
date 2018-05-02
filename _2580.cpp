#include<iostream>
#include<vector>
using namespace std;

int sudoku[9][9];
bool toCheck[9][10]; // 3*3크기의 배열 9개, v가 여부 확인 방법 : toCheck[(x/3)*3+y/3,v] 1<=v<=9이므로 10
bool rows[9][10]; // 해당 행
bool cols[9][10]; // 해당 열
void printAll()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ",sudoku[i][j]);
		}
		printf("\n");
	}
}
void DFS(int row, int col)
{
	printf("input : %d, %d \n", row, col);

	for (int j = col; j < 9; j++)
	{
		if (sudoku[row][j] == 0)
		{
			printf("%d, %d \n",row, j);
			for (int v = 1; v < 10; v++)
			{
				if (rows[row][v] != true && cols[j][v] != true && toCheck[(row / 3) * 3 + (j / 3)][v] != true)
				{
					sudoku[row][j] = v;
					rows[row][v] = cols[j][v] = toCheck[(row / 3) * 3 + (j / 3)][v] = true;
					DFS(row, j+1);
					sudoku[row][j] = 0;
					rows[row][v] = cols[col][v] = toCheck[(row / 3) * 3 + (j / 3)][v] = false;
				}
			}

		}
	}
	DFS(row+1, 0);
}
int main()
{
	int v;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> v;
			sudoku[i][j] = v;
			if (v != 0)
			{
				rows[i][v] = true;
				cols[j][v] = true;
				toCheck[(i / 3) * 3 + (j / 3)][v] = true;
			}
		}
	}
	DFS(0,0);
	return 0;
}