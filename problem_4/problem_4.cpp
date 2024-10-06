#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


int randNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void FillMatrixWithRandNums(int Arr[3][3], short RowsNum, short ColusNum)
{
	for (int i = 0; i < RowsNum; ++i)
	{
		for (int j = 0; j < ColusNum; ++j)
		{
			Arr[i][j] = randNum(1, 100);
		}
	}
}

void PrintMatrix(int Arr[3][3], short RowsNum, short ColusNum)
{
	for (int i = 0; i < RowsNum; ++i)
	{
		for (int j = 0; j < ColusNum; ++j)
		{
			cout << left << setw(3) << Arr[i][j] << "   ";
		}
		cout << endl << endl;
	}
}

int ColSum(int Arr[3][3], short ColNum, short RowsNums)
{
	int Sum = 0;
	for (int i = 0; i < RowsNums; ++i)
	{
		Sum += Arr[i][ColNum];
	}
	return Sum;
}

void PrintEachColSum(int Arr[3][3], short ColsNum, short RowsNum)
{
	for (int i = 0; i < ColsNum; i++)
	{
		cout << "Column " << i + 1 << "  Sum = " << ColSum(Arr, i, RowsNum) << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int Arr[3][3];
	int SumsArr[3];

	FillMatrixWithRandNums(Arr, 3, 3);

	cout << "The Array Numbers : \n";
	PrintMatrix(Arr, 3, 3);

	cout << "\nThe Columns Sum \n";
	PrintEachColSum(Arr, 3, 3);
	


}