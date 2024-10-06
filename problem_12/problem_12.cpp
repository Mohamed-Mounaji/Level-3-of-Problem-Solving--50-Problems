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

bool areMatricesTypical(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; ++i)
	{
		for (short j = 0; j < Cols; ++j)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
				return false;
		}
	}
	return true;
}

int main()
{
	srand(unsigned(time(NULL)));

	short Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandNumFrom1to10(Matrix1);
	cout << "Matrix 1 : \n";
	PrintMatrix(Matrix1);

	FillMatrixWithRandNumFrom1to10(Matrix2);
	cout << "\nMatrix 2 : \n";
	PrintMatrix(Matrix2);

	if (areMatricesTypical(Matrix1, Matrix2, 3, 3))
		cout << "Yes, Matrices are typical.";
	else
		cout << "No, Matrices are not typical.";


}
