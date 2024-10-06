#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int randNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void FillMatrixWithRandNums(int Arr[3][3])
{
	for (int i = 0; i <= 2; ++i)
	{
		for (int j = 0; j <= 2; ++j)
		{
			Arr[i][j] = randNum(1,100);
		}
	}
}

void PrintArr(int Arr[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << left << setw(3) <<  Arr[i][j] << "   ";
		}
		cout  << endl << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[3][3];
	FillMatrixWithRandNums(Arr);

	cout << "The arr with random nums : " << endl;
	PrintArr(Arr);


	return 0;
}