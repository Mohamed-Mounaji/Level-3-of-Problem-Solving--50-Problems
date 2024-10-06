#include <iostream>
#include <string>
#include <vector>

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

vector <string> vSplitWords(string Text, string Delimiter)
{
	string Word;
	short DeliPos = 0;
	vector <string> vTempVec;
	while ((DeliPos = Text.find(Delimiter)) != string::npos)
	{
		Word = Text.substr(0, DeliPos);
		if (Word != "")
			vTempVec.push_back(Word);
		Text.erase(0, DeliPos + Delimiter.length());
	}
	if (Text != "")
		vTempVec.push_back(Text);
	return vTempVec;
}


int main()
{
	string Text = "Hello#''#Guys#''#How#''#Are#''#You";

	vector <string> vSplitedWords = vSplitWords(Text, "#''#");

	cout << "\n\n";
	cout << "Tokens :  " << vSplitedWords.size() << endl;
	for (string& Word : vSplitedWords)
	{
		cout << Word << endl;
	}

	return 0;
}