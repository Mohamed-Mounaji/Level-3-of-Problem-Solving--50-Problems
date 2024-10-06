#include <iostream>
#include <vector>

using namespace std;

string JoinString(vector <string> &Words, string Delim)
{
	string Text = "";
	for (string& Word : Words)
	{
		if (Word != Words[0])
			Text += Delim;
		Text += Word;
	}
	return Text;
}

string TeacherSolution(vector <string>& vWords, string Delim)
{
	string Text = "";
	for (string Word : vWords)
	{
		Text += Word + Delim;
	}
	//return Text;
	return Text.substr(0, Text.length() - Delim.length());
}

int main()
{
	vector <string> Words = { "Mohamed", "Mounaji" , "is", "a", "programmer." };

	cout << "\nVector after join : " << TeacherSolution(Words, "#''#");
}