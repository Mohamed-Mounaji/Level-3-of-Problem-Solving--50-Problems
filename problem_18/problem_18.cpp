#include <iostream>
using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; ++i)
	{
		for (short j = 0; j < Cols; ++j)
		{
			printf(" %02d    ", Matrix[i][j]);
		}
		cout << endl;
	}
}

bool isNumInMatrix(short Number, short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; ++i)
	{
		for (short j = 0; j < Cols; ++j)
		{
			if (Matrix[i][j] == Number)
				return true;
		}
	}
	return false;
}

void PrintIntersecedNumbers(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
{
	for(short i =0; i<Rows ; ++i)
	{
		for (short j = 0; j < Cols; ++j)
		{
			if (isNumInMatrix(Matrix1[i][j], Matrix2, Rows, Cols))
				printf(" %d    ", Matrix1[i][j]);
		}
	}
}


int main()
{
	short Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
	short Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

	cout << "Matrix 1 :\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "Matrix 2 :\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "Intersected numbers are: \n";
	PrintIntersecedNumbers(Matrix1, Matrix2, 3, 3);

}