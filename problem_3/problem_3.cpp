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

int RowSum(int Arr[3][3], short RowNum, short ColusNum)
{
	int Sum = 0;
	for (int i = 0; i < ColusNum; ++i)
	{
		Sum += Arr[RowNum][i];
	}
	return Sum;
}

void FillSumOfRowsInArr(int Arr[3][3], short RowsNum, short ColusNum, int ArrSum[3])
{
	for (int i = 0; i < RowsNum; ++i)
	{
		ArrSum[i] = RowSum(Arr, i, ColusNum);
	}
}

void PrintArr(int Arr[3], short ColusNum)
{
	for (int i = 0; i < ColusNum; ++i)
	{
		cout << "Row " << i + 1 << " Sum = " << Arr[i] << endl;
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

	FillSumOfRowsInArr(Arr, 3, 3, SumsArr);
	
	cout << "\nThe Rows Sum :  \n";
	PrintArr(SumsArr, 3);


}