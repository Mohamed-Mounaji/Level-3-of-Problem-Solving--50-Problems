#include <iostream>
#include <string>

using namespace std;

struct stClientData
{
	string AccountNum = "";
	string PinCode = "";
	string FullName = "";
	string PhoneNum = "";
	double AccountBalance = 0;
};

string ReadString(string Message)
{
	string Text = "";
	cout << Message;
	getline(cin, Text);
	return Text;
}

double ReadNum(string Message)
{
	double Num = 0;
	cout << Message;
	cin >> Num;
	return Num;
}

stClientData ReadClientData()
{
	stClientData Client;
	Client.AccountNum = ReadString("Enter Account Number : ");
	Client.PinCode = ReadString("Enter Pin Code : ");
	Client.FullName = ReadString("Enter Name : ");
	Client.PhoneNum = ReadString("Enter Phone Number : ");
	Client.AccountBalance = ReadNum("Enter Account Balance : ");
	return Client;
}

string ConvertClientRecordIntoLine(stClientData Client, string Separator = "#//#")
{
	string Text = "";
	Text += Client.AccountNum + Separator;
	Text += Client.PinCode + Separator;
	Text += Client.FullName + Separator;
	Text += Client.PhoneNum + Separator;
	Text += to_string(Client.AccountBalance);
	return Text;
}

int main()
{
	cout << "Please Enter the Cliend Data\n\n";
	stClientData Client1 = ReadClientData();

	cout << "\nClient Record For Saving is : \n" << ConvertClientRecordIntoLine(Client1);
	
	return 0;
}