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

bool FindClientInfoByAccountNumber(string AccountNumber, vector <stClientData> vClients, stClientData& Client)
{
	for (stClientData &C : vClients)
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

string ConvertRecordToLine(stClientData Client, string Separator = "#//#")
{
	string Text = "";
	Text += Client.AccountNum + Separator;
	Text += Client.PinCode + Separator;
	Text += Client.FullName + Separator;
	Text += Client.PhoneNum + Separator;
	Text += to_string(Client.AccountBalance);
	return Text;
}

void SaveVectorToFile(vector <stClientData>& vClients, string FileName)
{
	fstream File;
	File.open(FileName, ios::out);//Write Mode

	if (File.is_open())
	{
		for (stClientData& Client : vClients)
		{
			if (Client.MarkedToDelete == false)
			{
				File << ConvertRecordToLine(Client) << endl;
			}
		}
		File.close();
	}
}


stClientData ReadNewData(string AccountNum)
{
	stClientData Data;
	Data.AccountNum = AccountNum;
	Data.PinCode = ReadString("Enter Pin Code  : ");
	Data.FullName = ReadString("Enter Name      : ");
	Data.PhoneNum = ReadString("Enter Phone     : ");
	cout << "Enter Account Blance : ";
	cin >> Data.AccountBalance;
	return Data;
}

void UpdateClientData(vector <stClientData>& vClients, string AccountNum)
{
	stClientData Client;
	char Answer = 'n';

	if (FindClientInfoByAccountNumber(AccountNum, vClients, Client))
	{
		PrintClient(Client);

		cout << "\nAre you sure you want to update this client's date y/n : ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			for (stClientData& C : vClients)
			{
				if (C.AccountNum == AccountNum)
				{
					C = ReadNewData(AccountNum);
					break;
				}
			}

			SaveVectorToFile(vClients, FileOfClientsData);

			cout << "\nThe client's Data is updated successfully.\n";
		}

	}

	else
	{
		cout << "\nClient with account number " << AccountNum << " is not found!\n";
	}
}

int main()
{
	system("color 0C");
	system("color F4"); 
	vector <stClientData> vClients = LoadClientsDataFromFile(FileOfClientsData);
	string AccountNum = ReadString("Enter the account Number you want to update : ");

	UpdateClientData(vClients, AccountNum);

	return 0;
}