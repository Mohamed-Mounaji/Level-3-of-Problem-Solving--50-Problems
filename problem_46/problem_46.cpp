#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

void PrintClientData(stClientData Client)
{
	cout << "\n\nAccount Number  : " << Client.AccountNum;
	cout << "\nPin Code        : " << Client.PinCode;
	cout << "\nFull Name       : " << Client.FullName;
	cout << "\nPhone Number    : " << Client.PhoneNum;
	cout << "\nAccount Balance : " << Client.AccountBalance << endl;
}

int main()
{
	string DataLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
	
	stClientData Client1 = ConvertClientDataLineToRecord(DataLine);

	PrintClientData(Client1);
	
	return 0;
}