#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const string FileOfClientsData = "ClientsData.txt";

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
	getline(cin >> ws, Text);
	return Text;
}

vector<string> SplitString(string S1, string Delim) {

	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word 
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}

stClientData ConvertClientDataLineToRecord(string ClientDataLine, string Separator = "#//#")
{
	stClientData Client;
	vector <string> vDataSplitted = SplitString(ClientDataLine, Separator);

	Client.AccountNum = vDataSplitted[0];
	Client.PinCode = vDataSplitted[1];
	Client.FullName = vDataSplitted[2];
	Client.PhoneNum = vDataSplitted[3];
	Client.AccountBalance = stod(vDataSplitted[4]);

	return Client;
}

vector <stClientData> LoadClientsDataFromFile(string FileName)
{
	vector <stClientData> vClients;
	stClientData Client;
	fstream File;
	File.open(FileName, ios::in);//ReadMode
	if (File.is_open())
	{
		string Line;
		while (getline(File, Line))
		{
			Client = ConvertClientDataLineToRecord(Line);
			vClients.push_back(Client);
		}
		File.close();
	}

	return vClients;
}

bool FindClientInfoByAccountNumber(string AccountNumber, stClientData& Client)
{
	vector <stClientData> vClients = LoadClientsDataFromFile(FileOfClientsData);
	for (stClientData C : vClients)
	{
		if (C.AccountNum == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void PrintClient(stClientData Client)
{
	cout << "\n\t[Clients Detail]\n";
	cout << "\nAccount Number  : " << Client.AccountNum;
	cout << "\nPin Code        : " << Client.PinCode;
	cout << "\nFull Name       : " << Client.FullName;
	cout << "\nPhone Number    : " << Client.PhoneNum;
	cout << "\nAccount Balance : " << Client.AccountBalance;
	cout << endl;
}


int main()
{
	string AccountNumber = ReadString("Please, Enter your account Number : ");
	stClientData Client;

	if (FindClientInfoByAccountNumber(AccountNumber, Client))
	{
		PrintClient(Client);
	}
	else
	{
		cout << "\nThe Client With The Account Number \'" << AccountNumber << "\' is not found ! \n";
	}

	
	
	return 0;
}