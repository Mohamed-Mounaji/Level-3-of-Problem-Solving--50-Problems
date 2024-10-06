#include <iostream>
#include <string>

using namespace std;

char ReadChar()
{
	char Letter;
	cout << "Please enter a character : ";
	cin >> Letter;
	return Letter;
}

void InvertCharacter(char &Letter)
{
	Letter = (islower(Letter) ? toupper(Letter) : tolower(Letter));
}

int main()
{
	char Letter = ReadChar();

	InvertCharacter(Letter);
	cout << "The character after inversion :  " << Letter;
	
}