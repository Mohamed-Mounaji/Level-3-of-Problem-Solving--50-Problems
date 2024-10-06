#include <iostream>

using namespace std;

void PrintFibonacciSerieUsingRecursion(int Number)
{
	static int CurrNum = 1;
	static int Per1 = 0;
	static int Per2 = 0;
	if (Number > 0)
	{
		Per1 = CurrNum;
		cout << CurrNum << "   ";
		CurrNum = Per1 + Per2;
		Per2 = Per1;
		PrintFibonacciSerieUsingRecursion(--Number);
	}
}

void TeacherFunction(int Number, int Per1, int Per2)
{
	int CurrNum = 0;
	if (Number > 0)
	{
		CurrNum = Per1 + Per2;
		Per2 = Per1;
		Per1 = CurrNum;
		cout << CurrNum << "   ";
		TeacherFunction(--Number, Per1, Per2);
	}
}

int main()
{
	TeacherFunction(10, 0,1);

}