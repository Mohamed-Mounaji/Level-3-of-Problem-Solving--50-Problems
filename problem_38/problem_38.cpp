#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
	string Text;
	cout << "Enter Your Text : ";
	getline(cin, Text);
	return Text;
}

string TrimLeft(string Text)
{
	short Counter = 0;
	for (int i = 0; i < Text.length(); ++i)
	{
		if (isalpha(Text[i]))
			break;
		if (Text[i] == ' ')
			Counter++;
	}
	Text = Text.erase(0, Counter);
	return Text;
}

string TrimRight(string Text)
{
	int Counter = 0;
	for (int i = Text.length() - 1; i >= 0; --i)
	{
		if (isalpha(Text[i]))
			break;
		else if (Text[i] == ' ')
			Counter++;
	}
	Text.erase(Text.length() - Counter, Text.length());
	return Text;
}

string Trim(string Text)
{
	Text = TrimLeft(Text);
	Text = TrimRight(Text);
	return Text;
}

string TeacherSolutionTrimLeft(string Text)
{
	for (int i = 0; i < Text.length(); ++i)
	{
		if (Text[i] != ' ')
			return Text.substr(i, Text.length() - i);
	}
	return "";
}

string TeacherSolutionTrimRight(string Text)
{
	for (int i = Text.length() - 1; i >= 0; --i)
	{
		if (Text[i] != ' ')
			return Text.substr(0, i+1);
	}
	return "";
}

string TeacherSolutionTrim(string Text)
{
	return TeacherSolutionTrimLeft(TeacherSolutionTrimRight(Text));
}

int main()
{
	string Text = ReadText();

	cout << "\nTrim Left  :" << TeacherSolutionTrimLeft(Text) << ".\n";
	cout << "\nTrim Right :" << TeacherSolutionTrimRight(Text) << ".\n";
	cout << "\nTrim       :" << TeacherSolutionTrim(Text) << ".\n";

}