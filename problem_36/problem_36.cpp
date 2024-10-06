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

int CountWords(string Text)
{
	short Counter = 0;
	string Delim = " ";
	short DelimPos = 0;
	string Word;
	while ((DelimPos = Text.find(Delim)) != string::npos)
	{
		Word = Text.substr(0, DelimPos);
		if (Word != "")
			Counter++;
		Text.erase(0, DelimPos + Delim.length());
	}

	if (Text != "")
		Counter++;
	return Counter;
}

int main()
{
	string Text = ReadText();


	cout << "\nThe number of word in the text is : " << CountWords(Text) << endl;
	return 0;
}