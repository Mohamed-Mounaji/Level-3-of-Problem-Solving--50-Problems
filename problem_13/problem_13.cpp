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

bool isMatrixIdentity(short Matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == j && Matrix[i][j] != 1)
			{
					return false;
			}
			else if(i != j && Matrix[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	srand(unsigned(time(NULL)));
	short Matrix[3][3];

	short Matrix2[3][3] = {
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

	FillMatrixWithRandNumFrom1to10(Matrix);
	cout << "Matrix : \n";
	PrintMatrix(Matrix2);

	if (isMatrixIdentity(Matrix2))
		cout << "Yes, Matrix is identity.\n";
	else
		cout << "No, Matrix is not identity.\n";

}
