#include <iostream>
//#include <cstdio>
using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; ++i)
	{
		for (short j = 0; j < Cols; ++j)
		{
			printf("%02d   ", Matrix[i][j]);
		}
		cout << endl;
	}
}

bool isMatrixScalar(short Matrix[3][3], short Rows, short Cols)
{
	short FirstDiagonalElem = Matrix[0][0];
	for (short i = 0; i < Rows; ++i)
	{
		for (short j = 0; j < Cols; ++j)
		{
			if (i == j  && Matrix[i][j] != FirstDiagonalElem)
			{
				return false;
			}
			else if (i != j && Matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	//short Matrix[3][3] = { {1,2,3},{4,5,6},{8,9,7} };

	short Matrix[3][3] = { {9,0,0},{0,1,0},{0,0,9} };
	PrintMatrix(Matrix, 3, 3);

	if (isMatrixScalar(Matrix, 3, 3))
		cout << "Yes, Matrix is Scalar.";
	else
		cout << "No, Matrix is not Scalar.";


	return 0;
}