#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string ClientsDataFileName = "ClientsData.txt";

struct stClientData
{
	string AccountNum = "";
	string PinCode = "";
	string FullName = "";
	string PhoneNum = "";
	double AccountBalance = 0;
};

string ReadText(string Message)
{
	string Text = "";
	cout << Message;
	getline(cin >> ws, Text);
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
	cout << "Adding New Client :\n";
	Client.AccountNum = ReadText("\nEnter Account Number : ");
	Client.PinCode = ReadText("Enter Pin Code : ");
	Client.FullName = ReadText("Enter Full Name : ");
	Client.PhoneNum = ReadText("Enter Phone Number : ");
	Client.AccountBalance = ReadNum("Enter Account Balance : ");

	return Client;
}

string ConvertRecordToLine(stClientData Client , string Separator = "#//#")
{
	string Text = "";
	Text += Client.AccountNum + Separator;
	Text += Client.PinCode + Separator;
	Text += Client.FullName + Separator;
	Text += Client.PhoneNum + Separator;
	Text += to_string(Client.AccountBalance);
	
	return Text;
}

void AddClientToFile(string FileName, string Client)
{
	fstream File;
	File.open(FileName, ios::out | ios::app);

	if (File.is_open())
	{
		File << Client << endl;
		File.close();
	}
}

void AddNewClient()
{
	stClientData NewClient = ReadClientData();
	AddClientToFile(ClientsDataFileName, ConvertRecordToLine(NewClient));
}

void AddClients()
{
	char AddMore = 'Y';
	do
	{
		system("cls");

		AddNewClient();
		cout << "Client added successfully, do you want to add more clients : ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

int main()
{
	AddClients();

	return 0;
}
