#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
	string Text = "";
	cout << "Enter your text : ";
	getline(cin, Text);
	return Text;
}

void PrintEachWordInLine(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		cout << Text[i];
		if (Text[i] == ' ')
			cout << "\n";
	}
}

void TeacherSolution(string Text)
{
	string Delim = " ";
	short DeliPos = 0;
	string Word;
	while ((DeliPos = Text.find(Delim)) != string::npos)
	{
		Word = Text.substr(0, DeliPos);
		if (Word != "")
		{
			cout << Word << endl;
		}
		Text.erase(0, DeliPos + Delim.length());
	}

	if (Text != "")
		cout << Text << endl;
}

int main()
{
	string Text = ReadText();

	return 0;
}