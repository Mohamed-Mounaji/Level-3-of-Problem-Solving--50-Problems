#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

string ChangeWordInText(string Text, string OrigWord, string NewWord)
{
	vector <string> vWords = SplitText(Text);

	for (string &Word : vWords)
	{
		if (Word == OrigWord)
			Word = NewWord;
	}

	return JoinWords(vWords);
}

string ReplaceWord(string Text, string OrigWord, string NewWord)
{
	short WordPos = Text.find(OrigWord);
	while (WordPos != string::npos)
	{
		Text = Text.replace(WordPos, OrigWord.length(), NewWord);
		WordPos = Text.find(OrigWord);
	}
	return Text;
}


int main()
{
	string Text = "Welcome to Jordan , Jordan is a nice country.";

	cout << "Original Text : \n" << Text << endl;
	cout << "\nString after replacing : \n" << ReplaceWord(Text, "Jordan", "USA");
	return 0;
}