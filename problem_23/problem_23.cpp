#include <iostream>
#include <string>

using namespace std;

string ReadText(string Message)
{
	string Text = " ";
	cout << Message;
	getline(cin, Text);
	return Text;
}

void PrintFirstLetters(string Text)
{
	cout << Text.at(0) << endl;

	for (int i = 0; i < Text.length(); ++i)
	{
		if (Text.at(i) == ' ' && Text.at(i + 1) != ' ')
			cout << Text.at(i + 1) << endl;
	}
}

void TeacherSolution(string Text)
{
	bool isFirstLetter = true;
	for (int i = 0; i < Text.length(); ++i)
	{
		if (Text[i] != ' ' && isFirstLetter)
			cout << Text[i] << "   ";
		isFirstLetter = (Text[i] == ' ' ? true : false);
	}
}

int main()
{
	string Text = ReadText("Print Enter your string : ");

	cout << "First Letters of this string :  \n";

	TeacherSolution(Text);
	
}