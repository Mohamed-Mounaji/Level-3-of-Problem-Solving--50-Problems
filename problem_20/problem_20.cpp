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

bool isMatrixPalindrome(short Matrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; ++i)
	{
		for (int j = 0; j < Cols/2; ++j)
		{
			if (Matrix[i][j] != Matrix[i][Cols - j - 1])
				return false;
		}
	}
	return true;
}

int main()
{
	short  Matrix[3][3] = { {1,2,1},{2,0,2},{2,3,1} };

	cout << "Matrix : \n";
	PrintMatrix(Matrix, 3, 3);


	if (isMatrixPalindrome(Matrix, 3, 3))
		cout << "\nYes, Matrix is Palindrome.\n";
	else
		cout << "\nNo, Matrix is Not Palindrome.\n";

	return 0;
}
