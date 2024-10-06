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

int CountLetter(string Text, char Letter, bool MatchCase = true)
{
	int Counter = 0;
	
	for (int i = 0; i < Text.length(); ++i)
	{
		if (MatchCase)
		{
			if (Text[i] == Letter)
				Counter++;
		}
		else
		{
			if (tolower(Text[i]) == tolower(Letter))
				Counter++;
		}
	}
	return Counter;
}

char InvertLetter(char Letter)
{
	return (islower(Letter) ? toupper(Letter) : tolower(Letter));
}


int main()
{
	string Text = ReadText();

	char Letter = ReadCharacter();

	printf("\nLetter '%c' count = %d ", Letter, CountLetter(Text, Letter));

	printf("\n\nLetter '%c' Or '%c' count = %d\n", Letter, InvertLetter(Letter), CountLetter(Text, Letter,false));
}
