#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const string FileName = "ClientsData.txt";

struct stClientData
{
	string AccountNum = "";
	string PinCode = "";
	string FullName = "";
	string PhoneNum = "";
	double AccountBalance = 0;
};

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

vector <stClientData>  ReadClientsFromFile(string FileName)
{
	vector <stClientData> vClients;

	fstream File;
	File.open(FileName, ios::in);
	if (File.is_open())
	{
		string Line;
		stClientData Client;
		while (getline(File, Line))
		{
			Client = ConvertClientDataLineToRecord(Line);
			vClients.push_back(Client);
		}
		File.close();
	}
	return vClients;
}

void PrintHeader(int NumOfClients = 0)
{
	printf("\t\t\t\t\tClient List (%d) Client(s)", NumOfClients);
	cout << "\n_____________________________________________________";
	cout << "___________________________________________________________________\n\n";
	cout << left;
	cout << "| " << setw(20) << "Account Number  ";
	cout << "| " << setw(15) << "Pin Code  ";
	cout << "| " << setw(40) << "Client Name ";
	cout << "| " << setw(20) << "Phone ";
	cout << "| " << setw(15) << "Balance ";
	cout << "\n_____________________________________________________";
	cout << "___________________________________________________________________\n";
}

void PrintClient(stClientData Client)
{
	cout << left << "\n";
	cout << "| " << setw(20) << Client.AccountNum;
	cout << "| " << setw(15) << Client.PinCode;
	cout << "| " << setw(40) << Client.FullName;
	cout << "| " << setw(20) << Client.PhoneNum;
	cout << "| " << setw(15) << Client.AccountBalance;
}

void PrintClients(vector <stClientData> vClients)
{
	for (stClientData& Client : vClients)
	{
		PrintClient(Client);
	}
}

void PrintFooter()
{
	cout << "\n________________________________________________________";
	cout << "________________________________________________________________\n";
}

void PrintClientsInfoTable(vector <stClientData> vClients)
{
	PrintHeader(vClients.size());
	PrintClients(vClients);
	PrintFooter();
}


int main()
{
	vector <stClientData> vClients = ReadClientsFromFile(FileName);

	PrintClientsInfoTable(vClients);
	return 0;
}