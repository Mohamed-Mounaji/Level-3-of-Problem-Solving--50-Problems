#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandNum(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandNumFrom1to10(int Arr[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			Arr[i][j] = RandNum(1, 10);
		}
	}
}

void PrintMatrix(int Arr[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf(" %0*d   ", 2, Arr[i][j]);
		}
		cout << endl << endl;
	}
}

void PrintMiddleRow(int Arr[3][3],short Rows, short Cols)
{
	short MiddleRow = Rows / 2;
	for (int i = 0; i < Cols; ++i)
	{
		printf(" %02d   ", Arr[MiddleRow][i]);
	}
}

void PrintMiddleCol(int Arr[3][3],short Rows, short Cols)
{
	short MiddleCols = Cols / 2;
	for (int i = 0; i < Rows; ++i)
	{
		printf(" %02d\n\n", Arr[i][MiddleCols]);
	}
}
int main()
{
	srand(unsigned(time(NULL)));

	int Arr[3][3];
	FillMatrixWithRandNumFrom1to10(Arr);

	cout << "Matrix 1 : \n";
	PrintMatrix(Arr);

	cout << "\nMiddle Row : \n";
	PrintMiddleRow(Arr,3,3);

	cout << "\n\nMiddle Column : \n";
	PrintMiddleCol(Arr,3,3);
	cout <<endl;


}