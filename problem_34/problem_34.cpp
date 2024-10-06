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

bool isVowel(char Letter)
{
	Letter = tolower(Letter);
	return (Letter == 'a') || (Letter == 'i') || (Letter == 'u') || (Letter == 'o') || (Letter == 'e');
}

void PrintTextVowels(string Text)
{
	for (int i = 0; i < Text.length(); ++i)
	{
		if (isVowel(Text[i]))
		{
			cout << Text[i] << "    ";
		}
	}
}

int main()
{
	string Text = ReadText();

	cout << "The vowels in the text are : ";
	PrintTextVowels(Text);

	return 0;
}