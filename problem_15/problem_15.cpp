#include <iostream>
#include <cstdlib>

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

short ReadNumber(string Message)
{
	short Number;
	cout << Message;
	cin >> Number;
	return Number;
}

int CountNumInMatrix(short NumberToCount, short Matrix[3][3], short Rows, short Cols)
{
	short Counter = 0;
	for (short i = 0; i < Rows; ++i)
	{
		for (short j = 0; j < Cols; ++j)
		{
			if (Matrix[i][j] == NumberToCount)
				Counter++;
		}
	}
	return Counter;
}

int main()
{
	short Matrix[3][3] = { {7,5,3},{3,5,6},{3,9,2} };

	cout << "Matrix : \n";
	PrintMatrix(Matrix, 3, 3);

	short ReapNum = ReadNumber("Enter the number to count in matrix : ");

	cout << "\nThe Number " << ReapNum << " count in matrix is " << CountNumInMatrix(ReapNum, Matrix, 3, 3);


	return 0;
}