#include <iostream>
#include <string>
#include <cstdio>

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

int CountVowels(string Text)
{
	int Counter = 0;
	for (int i = 0; i < Text.length(); ++i)
	{
		if (isVowel(Text[i]))
			Counter++;
	}
	return Counter;
}

int main()
{
	string Text = ReadText();

	cout << "\nThe Number of vowels is : " << CountVowels(Text) << endl;

	system("pause>0");

	return 0;
}