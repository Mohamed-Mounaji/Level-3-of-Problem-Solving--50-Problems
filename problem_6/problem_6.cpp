#include <iostream>

using namespace std;

void FillArrayWithOrderedNums(int Arr[3][3], short RowsNum, short ColsNum)
{
	int Num = 1;
	for (int i = 0; i < RowsNum; i++)
	{
		for (int j = 0; j < ColsNum; j++)
		{
			Arr[i][j] = Num++;
		}
	}
}

void PrintMatrix(int Arr[3][3], short RowsNum, short ColsNum)
{
	for (int i = 0; i < RowsNum; ++i)
	{
		for (int j = 0; j < ColsNum; ++j)
		{
			cout << Arr[i][j] << "    ";
		}
		cout << endl << endl;
	}
}

int main()
{
	int Arr[3][3];
	FillArrayWithOrderedNums(Arr, 3, 3);
	
	cout << "Ordered arr : \n";
	PrintMatrix(Arr,3,3);

}