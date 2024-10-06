#include <iostream>

using namespace std;

void PrintFibonacciSeries(int StartNum, int AllNum)
{
	int CurrNum = StartNum;
	int Per1 = 0;
	int Per2 = 0;
	
	for (int i = 0; i < AllNum; ++i)
	{
		Per1 = CurrNum;
		cout << CurrNum << "   ";
		CurrNum = Per1 + Per2;
		Per2 = Per1;
	}
}

int main()
{
	int Number = 0;

	PrintFibonacciSeries(3, 3);
}