#include <iostream>
#include <string>

using namespace std;

string RemovePunct(string Text)
{
	string Text2 = "";
	for (int i = 0; i < Text.length(); ++i)
	{
		if (!ispunct(Text[i]))
			Text2 += Text[i];
	}
	return Text2;
}

int main()
{
	string Text = "Hello, How: ;;;are bro; it's Great to see you.";

	cout << "\nThe text before removing punctuations : " << Text;
	cout << "\n\nThe text after removing punctuations  : " << RemovePunct(Text) << endl;
	cout << "\nUsing Teacher solution                : " << RemovePunct(Text) << endl;


}