#include <iostream>
#include <string>

using namespace std;

enum enWhatToCount {SmallLetters, CapitalLetters, Digits , All};

string ReadText()
{
	string Text;
	cout << "Enter your text : ";
	getline(cin, Text);
	return Text;
}

int NumberOfLowerCases(string Text)
{
	int Counter = 0;
	for (int i = 0; i < Text.length(); ++i)
	{
		if (islower(Text[i]))
			Counter++;
	}
	return Counter;
}

int NumberOfUpperCases(string Text)
{
	int Counter = 0;
	for (int i = 0; i < Text.length(); ++i)
	{
		if (isupper(Text[i]))
			Counter++;
	}
	return Counter;
}

int CountLetters(string Text, enWhatToCount WhatToCount = enWhatToCount::All)
{
	int Counter = 0;
	if (WhatToCount == enWhatToCount::All)
		return Text.length();

	for (int i = 0; i < Text.length(); ++i)
	{
		if (WhatToCount == enWhatToCount::SmallLetters && islower(Text[i]))
			Counter++;
		else if (WhatToCount == enWhatToCount::CapitalLetters && isupper(Text[i]))
			Counter++;
		else if (WhatToCount == enWhatToCount::Digits && isdigit(Text[i]))
			Counter++;
	}
	return Counter;
}


int main()
{
	string Text = ReadText();

	cout << "Text length : " << CountLetters(Text) << endl;

	cout << "Number Of lower Letters : " << CountLetters(Text, enWhatToCount::SmallLetters) << endl;

	cout << "Number Of Upper Letters : " << CountLetters(Text, enWhatToCount::CapitalLetters) << endl;

	cout << "Number Of Digits : " << CountLetters(Text, enWhatToCount::Digits);
}