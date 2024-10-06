#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ReadText(string Message)
{
	string Text = "";
	cout << Message;
	getline(cin, Text);
	return Text;
}

vector <string> SplitText(string Text, string Deli = " ")
{
	vector <string> vWords;
	string Word = "";
	short DeliPos = 0;
	while ((DeliPos = Text.find(Deli)) != string::npos)
	{
		Word = Text.substr(0, DeliPos);
		if (Word != "")
			vWords.push_back(Word);
		Text.erase(0, DeliPos + Deli.length());
	}

	if (Text != "")
		vWords.push_back(Text);
	return vWords;
}

string JoinWords(vector <string> vWords, string Deli = " ")
{
	string Text2;
	for (string& Word : vWords)
	{
		Text2 += Word + " ";
	}
	return Text2.substr(0, Text2.length() - Deli.length());
}

string LowerWord(string Word)
{
	for (int i = 0; i < Word.length(); i++)
	{
		Word[i] = tolower(Word[i]);
	}
	return Word;
}

string ReplaceWord(string Text, string OrigWord, string NewWord , bool MatchCase = true)
{
	vector <string > vWords = SplitText(Text);
	for (string& Word : vWords)

	{
		if (MatchCase)
		{
			if (Word == OrigWord)
				Word = NewWord;
		}
		else
		{
			if (LowerWord(Word) == LowerWord(OrigWord))
				Word = NewWord;
		}
	}
	return JoinWords(vWords);
}

int main()
{
	string Text = ReadText("Enter the text : ");
	string OrigWord = ReadText("Enter the word you want to replace : ");
	string NewWord = ReadText("Enter the New Word : ");

	cout << "\n\nThe Original Text                  : " << Text << endl;
	cout << "\nThe Replacement with match case    : " << ReplaceWord(Text, OrigWord, NewWord) << endl;
	cout << "\nThe Replacement without match case : " << ReplaceWord(Text, OrigWord, NewWord, false) << endl;

	return 0;
}