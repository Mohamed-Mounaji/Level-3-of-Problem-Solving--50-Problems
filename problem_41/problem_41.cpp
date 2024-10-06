#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ReadText()
{
	string Text = "";
	cout << "Enter your text : ";
	getline(cin, Text);
	return Text;
}

vector <string> SplitText(string Text, string Delimiter)
{
	vector <string> vWords;
	short DeliPos = 0;
	string Word = "";
	while ((DeliPos = Text.find(Delimiter)) != string::npos)
	{
		Word = Text.substr(0, DeliPos);
		if (Word != "")
			vWords.push_back(Word);
		Text.erase(0, DeliPos + Delimiter.length());
	}

	if (Text != "")
		vWords.push_back(Text);
	return vWords;
}

string ReverseWords(string Text)
{
	vector <string> vWords = SplitText(Text, " ");
	vector <string>::iterator iter = vWords.end();
	string Text2 = "";
	while (iter != vWords.begin())
	{
		iter--;
		Text2 += *iter + " ";
	}
	return Text2.substr(0, Text2.length() - 1);
}

int main()
{
	string Text = ReadText();

	cout << "\nString after reversing words : \n" << ReverseWords(Text);
}