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

int ColSum(int Arr[3][3], short ColNum, short RowsNum)
{
	int Sum = 0;
	for (int i = 0; i < RowsNum; ++i)
	{
		Sum += Arr[i][ColNum];
	}
	return Sum;
}

void FillArrWithColsSum(int Arr[3][3], int ArrSum[3], short ColsNum, short RowsNum)
{
	for (int ColNum = 0; ColNum < ColsNum; ColNum++)
	{
		ArrSum[ColNum] = ColSum(Arr, ColNum, RowsNum);
	}
}
 
void PrintSumArr(int Arr[3])
{
	for (int i = 0; i < 3; ++i)
	{
		cout << "Column " << i + 1 << " Sum = " << Arr[i] << endl;
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

	FillArrWithColsSum(Arr, SumsArr, 3, 3);

	cout << "\nThe Columns Sum \n";
	PrintSumArr(SumsArr);



}