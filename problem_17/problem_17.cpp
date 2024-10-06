#include <iostream>
using namespace std;

short ReadNumber(string Message)
{
	short Number;
	cout << Message;
	cin >> Number;
	return Number;
}

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

bool isNumExistInMatrix(short Number, short Matrix[3][3], short Rows, short Cols)
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

int main()
{
	short Matrix[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

	cout << "Matrix : \n";
	PrintMatrix(Matrix, 3, 3);

	short Number = ReadNumber("Enter a number to check if it exists in the matrix : ");

	if (isNumExistInMatrix(Number, Matrix, 3, 3))
		cout << "\nYes, Number exists in the matrix.\n";
	else
		cout << "\No, Number Does Not exist in the matrix.\n";



}