#include <iostream>
#include <vector>

using namespace std;

string JoinString(vector <string>& vWords, string Delim)
{
	string Text = "";
	for (string& Word : vWords)
	{
		Text += Word + Delim;
	}
	return Text.substr(0, Text.length() - Delim.length());
}

string JoinString(string Arr[], int ArrLength, string Delim)
{
	string Text = "";
	for (int i = 0; i < ArrLength; i++)
	{
		Text += Arr[i] + Delim;
	}
	return Text.substr(0, Text.length() - Delim.length());
}

int Return(int Num)
{
	return Num;
}

string Return(string Text)
{
	return Text;
}

int main()
{
	vector <string> vWords = { "Mohamed","Mounaji","is", "the","best","programmer","in","the","world." };
	string Arr[] = { "Mohamed","Mounaji","is", "the","best","programmer","in","the","world." };

	cout << "After join vector: \n" << JoinString(vWords, " ");
	cout << "\n\nAfter join Array : \n" << JoinString(Arr, 9, " ");
	system("pause>0");
	return 0;
}