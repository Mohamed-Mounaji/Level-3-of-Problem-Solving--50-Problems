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

int MinNumInMatrix(short Matrix[3][3], short Rows, short Cols)
{
	int Number = Matrix[0][0];
	for (short i = 0; i < Rows; ++i)
	{
		for (short j = 0; j < Cols; ++j)
		{
			if (Matrix[i][j] < Number)
			{
				Number = Matrix[i][j];
			}
		}
	}
	return Number;
}

int MaxNumInMatrix(short Matrix[3][3], short Rows, short Cols)
{
	int Number = Matrix[0][0];
	for (short i = 0; i < Rows; ++i)
	{
		for (short j = 0; j < Cols; ++j)
		{
			if (Matrix[i][j] > Number)
				Number = Matrix[i][j];
		}
	}
	return Number;
}


int main()
{
	short  Matrix[3][3] = { {77,5,12},{22,20,6},{14,3,9} };

	cout << "Matrix : \n";
	PrintMatrix(Matrix, 3, 3);

	int MinNum = MinNumInMatrix(Matrix, 3, 3);
	int MaxNum = MaxNumInMatrix(Matrix, 3, 3);

	cout << "\nMinimum Number is : " << MinNum << endl;
	cout << "\nMax Number is : " << MaxNum;


}
