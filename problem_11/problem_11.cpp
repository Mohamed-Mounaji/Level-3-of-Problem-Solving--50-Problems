#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandNum(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandNumFrom1to10(short Matrix[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			Matrix[i][j] = RandNum(1, 10);
		}
	}
}

void PrintMatrix(short Matrix[3][3])
{
	for (short i = 0; i < 3; ++i)
	{
		for (short j = 0; j < 3; ++j)
		{
			printf(" %0*d   ", 2, Matrix[i][j]);
		}
		cout << endl << endl;
	}
}

int GetMatrixSum(short Matrix[3][3], short Rows, short Cols)
{
	int Sum = 0;
	for (short i = 0; i < Rows; ++i)
	{
		for (short j = 0; j < Cols; ++j)
		{
			Sum += Matrix[i][j];
		}
	}
	return Sum;
}

bool areMatricesEqual(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
{
	return GetMatrixSum(Matrix1, Rows, Cols) == GetMatrixSum(Matrix2, Rows, Cols);
}

void PrintAreOrNotEqual(bool areEqual)
{
	if (areEqual)
		cout << "\nYes, Matrices are equal.";
	else
		cout << "\nNo, Matrices are not equal.";

}

int main()
{
	srand((unsigned)time(NULL));

	short Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandNumFrom1to10(Matrix1);
	cout << "Matrix 1 :\n";
	PrintMatrix(Matrix1);

	FillMatrixWithRandNumFrom1to10(Matrix2);
	cout << "\nMatrix 2 : \n";
	PrintMatrix(Matrix2);

	PrintAreOrNotEqual(areMatricesEqual(Matrix1, Matrix2, 3, 3));

	cout << endl;

	return 0;
}
