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

bool isMatrixSparse(short Matrix[3][3], short Rows, short Cols)
{
	short MatrixSize = Rows * Cols;
	return CountNumInMatrix(0, Matrix, Rows, Cols) >= float(MatrixSize) / 2;
}

int main()
{
	short Matrix[3][3] = { {0,0,0},{1,0,4},{1,2,3} };
	PrintMatrix(Matrix, 3, 3);

	if (isMatrixSparse(Matrix, 3, 3))
		cout << "Yes, Matrix is sparse.";
	else
		cout << "No, Matrix is NOT sparse.";


}
