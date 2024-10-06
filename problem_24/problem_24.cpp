#include <iostream>
#include <string>
using namespace std;

string ReadText(string Message)
{
	string Text;
	cout << Message;
	getline(cin, Text);
	return Text;
}

void CapitalizeFirstLetters(string &Text)
{
	bool isFirstLetter = true;

	for (int i = 0; i < Text.length(); ++i)
	{
		if (isFirstLetter && Text[i] != ' ')
			Text[i] = toupper(Text[i]);

		isFirstLetter = (Text[i] == ' ' ? true : false);
	}

}

int main()
{
	string Text = ReadText("Enter Your String : ");

	CapitalizeFirstLetters(Text);

	cout << "After Capitalizing First letters : " << endl << Text;


}