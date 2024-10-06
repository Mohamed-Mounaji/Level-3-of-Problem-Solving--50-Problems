#include <iostream>
#include <string>

using namespace std;

char ReadCharacter()
{
	char Letter;
	cout << "Enter your letter : ";
	cin >> Letter;
	return Letter;
}

bool isVowel(char Letter)
{
	Letter = tolower(Letter);
	return (Letter == 'a') || (Letter == 'i') || (Letter == 'u') || (Letter == 'o') || (Letter == 'e');
}

int main()
{
	char Character = ReadCharacter();

	if (isVowel(Character))
		printf("\nYes, Letter '%c' is a vowel.\n", Character);
	else
		printf("\nNo, Letter '%c' is Not a vowel.\n", Character);
}