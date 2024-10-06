#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandNum(int From, int To)
{
	return rand() %		(To - From + 1) + From;
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

void MultiplyTwoMatrices(int Arr1[3][3], int Arr2[3][3], int Arr3[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			Arr3[i][j] = Arr1[i][j] * Arr2[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr1[3][3], Arr2[3][3], Arr3[3][3];

	FillMatrixWithRandNumFrom1to10(Arr1);
	FillMatrixWithRandNumFrom1to10(Arr2);

	cout << "Matrix 1 : \n";
	PrintMatrix(Arr1);

	cout << "\nMatrix 2 :  \n";
	PrintMatrix(Arr2);

	MultiplyTwoMatrices(Arr1, Arr2, Arr3);

	cout << "\nResult : \n";
	PrintMatrix(Arr3);

	
	return 0;
}