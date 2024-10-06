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
	bool MarkedToDelete = false;
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

bool FindClientInfoByAccountNumber(string AccountNumber, vector <stClientData> vClients , stClientData& Client)
{
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

string ConvertRecordToLine(stClientData Client,string Separator = "#//#")
{
	string Text = "";
	Text += Client.AccountNum + Separator;
	Text += Client.PinCode + Separator;
	Text += Client.FullName + Separator;
	Text += Client.PhoneNum + Separator;
	Text += to_string(Client.AccountBalance);
	return Text;
}

void SaveVectorToFile(vector <stClientData> &vClients,string FileName)
{
	fstream File;
	File.open(FileName, ios::out);//Write Mode

	if (File.is_open())
	{
		for (stClientData &Client : vClients)
		{
			if (Client.MarkedToDelete == false)
			{
				File << ConvertRecordToLine(Client) << endl;
			}
		}
		File.close();
	}
}

void MarkClientToDelete(string AccountNum, vector <stClientData> &vClients)
{
	for (stClientData &Client : vClients)
	{
		if (Client.AccountNum == AccountNum)
		{
			Client.MarkedToDelete = true;
		}
	}
}

void DeleteClientByAccountNumber(string AccountNumber, vector <stClientData> &vClients)
{
	stClientData Client;
	char Answer = 'Y';

	if (FindClientInfoByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClient(Client);

		cout << "\nAre you sure you want to delete this account number : ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientToDelete(AccountNumber, vClients);
			SaveVectorToFile(vClients, FileOfClientsData);

			vClients = LoadClientsDataFromFile(FileOfClientsData);
			cout << "\n\nThe Client has been deleted successfully.";
		}
	}
	else
	{
		cout << "\nThe Client with the account number " << AccountNumber << " is not found\n";
	}

}


int main()
{
	vector <stClientData> vClients = LoadClientsDataFromFile(FileOfClientsData);
	string AccountNum = ReadString("Enter the account Number you want to delete : ");

	DeleteClientByAccountNumber(AccountNum, vClients);
	return 0;
}