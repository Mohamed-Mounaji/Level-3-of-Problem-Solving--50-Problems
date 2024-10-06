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

void UncapitalizeFirstLetters(string &Text)
{
	bool isFirstLetter = true;

	for (int i = 0; i < Text.length(); ++i)
	{
		if (isFirstLetter && Text[i] != ' ')
			Text[i] = tolower(Text[i]);
		isFirstLetter = (Text[i] == ' ' ? true : false);
	}
}


int main()
{
	string Text = ReadText();

	UncapitalizeFirstLetters(Text);

	cout << "This is the text after uncapitalizing first letters : \n" << Text;



}