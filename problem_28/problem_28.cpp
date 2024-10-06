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

char InvertCharacter(char Letter)
{
	return (islower(Letter) ? toupper(Letter) : tolower(Letter));
}


string InvertTextLetters(string Text)
{
	for (int i = 0; i < Text.length(); ++i)
	{
		Text[i] = InvertCharacter(Text[i]);
	}
	return Text;
}

int main()
{
	string Text = ReadText();

	Text = InvertTextLetters(Text);

	cout << "\nThe text after inverting its letters : \n" << Text << endl;

}