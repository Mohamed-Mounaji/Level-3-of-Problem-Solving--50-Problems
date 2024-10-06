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

char ReadCharacter()
{
	char Letter;
	cout << "Enter your letter : ";
	cin >> Letter;
	return Letter;
}

int CountLetterInText(string Text, char Letter)
{
	int Counter = 0;
	for (int i = 0; i < Text.length(); ++i)
	{
		if (Text[i] == Letter)
			Counter++;
	}
	return Counter;
}

int main()
{
	string Text = ReadText();

	char Letter = ReadCharacter();

	printf("Letter '%c' count = %d ", Letter, CountLetterInText(Text, Letter));
}
