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

void PrintArr(int Arr[3][3], short RowsNum, short ColusNum)
{
	for (int i = 0; i < RowsNum; ++i)
	{
		for (int j = 0; j < ColusNum; ++j)
		{
			cout << setw(3) << Arr[i][j] << "  ";
		}
		cout << endl;
	}
}

int RowSum(int Arr[3][3], short RowNum , short AllColusNum)
{
	int Sum = 0;
	for (int j = 0; j < AllColusNum; ++j)
	{
		Sum += Arr[RowNum][j];
	}
	return Sum;
}

void PrintEachRowSum(int Arr[3][3] , short RowsNum, short ColusNum)
{
	for (short i = 0; i < RowsNum; ++i)
	{
		cout << "Row " << i + 1 << " Sum = " << RowSum(Arr, i , ColusNum) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[3][3];
	FillMatrixWithRandNums(Arr,3,3);

	cout << "The arr with random nums : " << endl;
	PrintArr(Arr, 3, 3);

	cout << "Each Row Sum : \n";
	PrintEachRowSum(Arr,3,3);


	return 0;
}