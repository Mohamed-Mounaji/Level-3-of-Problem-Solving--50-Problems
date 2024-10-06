#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
	string Text;
	cout << "Enter your text : ";
	getline(cin, Text);

	return Text;
}

void UpperAllText(string& Text)
{
	for (int i = 0; i < Text.length(); ++i)
	{
		Text[i] = toupper(Text[i]);
	}
}

void LowerAllText(string& Text)
{
	for (int i = 0; i < Text.length(); ++i)
	{
		Text[i] = tolower(Text[i]);
	}
}

int main()
{
	string Text = ReadText();

	UpperAllText(Text);
	cout << "The Text After Capitalization : \n" << Text << endl;

	LowerAllText(Text);
	cout << "\nThe Text after upcapitalization : \n" << Text;

	system("pause>0");

}