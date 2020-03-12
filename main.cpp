#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <ctime> // for time function
#include <cstdlib> // for srand
#include <fstream> //for IO of file
using namespace std;

// GLOBAL VARIABLES
string admin;
string pass;
int choice;
int c;
int numPassenger;

ofstream outfile("adminData.txt", std::ios_base::app);
ifstream file("adminData.txt");

class Data{
	public:
	string flyF;
	string flyT,depOn,retOn;
	string depTime,retTime;
	int adult,child,infant;
};


//FUNCTIONS
void outReceipt();
void menu();
bool checklogin(const string &username, const string &password);
void logo();
void reg();
void search();
void intoData();
void makeReg();
string pickDate();
string pickTime();
void login();
string getRandomCode();
string code = getRandomCode();

int main(){ // main function
	bool logincheck ;
	int c;
	bool loop = 1;
	while(loop){
		logo();
		cout << "\t\t\t\t1 - LOG IN\n";
		cout << "\t\t\t\t2 - CREATE AN ACCOUNT\n";
		cout << "\t\t\t\t3 - SEARCH PASSENGER\n";
		cout << "\t\t\t\t4 - EXIT PROGRAM\n\t\t\t\t>: ";
		cin >> c;
		switch (c){
			case 1:
				login();
				logincheck = checklogin(admin,pass);
				if(logincheck){
					cout << "\n\t\t\t\tWELCOME BACK " << admin << endl;
					cout << "\t\t\t\t." << system("pause");
					system("cls");
					menu();
				} else {
					cout << "\n\t\t\t\tINVALID USER CREDENTIALS";
				}
				break;
			case 2:
				reg();
				cout << "\t\t\t\tYOUR ACCOUNT HASE BEEN MADE!!\n";
				cout << "\t\t\t\t" << system("pause");
				system("cls");
				c = 1;
				break;
			case 3:
				system ("cls");
				logo();
				search();
				system("pause");
				break;
			case 4:
				return 0;
			default:
				cout << "INVALID CHOICE!";
				break;
		}
	}
}


bool checklogin(const string &username, const string &password) {
    string fusername, fpassword;
    while (file) {
        getline(file, fusername, ';'); 
        getline(file, fpassword); 
 
        if (fusername == username && fpassword == password)
            return true;
    }
    return false;
}

void menu(){
	bool loop=1;
	while(loop){
		system("cls");
		logo();
		cout << "\t\t\t\t1 - MAKE RESERVATION\n";
		cout << "\t\t\t\t2 - CANCEL RESERVATION\n";
		cout << "\t\t\t\t3 - PRINT RECEIPT\n";
		cout << "\t\t\t\t4 - QUIT\n\t\t\t\t>: ";
		cin >> choice;
		system ("cls");
		switch (choice) {
			case 1:
				makeReg();
				break;
			case 3:
				outReceipt();
				break;
			case 4:
				loop = false;
				break;
		}
	}

}

	Data info;
void makeReg(){

	system ("cls");
	logo();
	cout << "\t\t\t\tFLYING FROM: ";
	cin >> info.flyF;
	cout << "\t\t\t\tFLYING TO: ";
	cin >> info.flyT;
	system("cls");	
	logo();
	cout << "\n\t\t\t\tDEPARTING ON: ";
	info.depOn = pickDate();
	info.depTime = pickTime();
	system("cls");
	logo();
	cout << "\n\t\t\t\tRETURNING ON: ";
	info.retOn = pickDate();
	info.retTime = pickTime();
	system("cls");
	logo();
	cout << "\n\t\t\t\tPASENGERS: \n";
	cout << "\t\t\t\tADULT: ";
	cin >> info.adult;
	cout << "\t\t\t\tCHILD(2-11years): ";
	cin >> info.child;
	cout << "\t\t\t\tINFANT(under 2years): ";
	cin >> info.infant;
	numPassenger = info.child + info.adult + info.infant;
	intoData();
}




void logo() {
	cout << "______  ___             ______             ____________                                        \n";
	cout << "___   |/  /___  ___________  /_________    ___    |__(_)_________      _______ _____  _________\n";
	cout << "__  /|_/ /_  / / /_  ___/_  //_/_  ___/    __  /| |_  /__  ___/_ | /| / /  __ `/_  / / /_  ___/\n";
	cout << "_  /  / / / /_/ /_(__  )_  ,<  _(__  )     _  ___ |  / _  /   __ |/ |/ // /_/ /_  /_/ /_(__  )\n";
	cout << "/_/  /_/  \\__,_/ /____/ /_/|_| /____/      /_/  |_/_/  /_/    ____/|__/ \\__,_/ _\\__, / /____/\n";
	cout << "                                                                               /____/        \n";
}

void reg(){
	string nUser;
	string nPass;
	cout << "\t\t\t\tCreate a User Name: ";
	cin >> nUser;
	cout << "\t\t\t\tCreate a Password: ";
	cin >> nPass;
	outfile << nUser << ";" <<nPass << endl;
	outfile.close();
}

void login() {
	cout << "\n\t\t\t\tLOG IN:\n\n";
	cout << "\t\t\t\tUser Name: ";
	cin >> admin;
	cout << "\t\t\t\tPassword: ";
	cin >> pass;
}

// this will get randome code for FLIGHT CODE
string getRandomCode(){
	string s;
	int i;
	char cmptchoice[5];
    for (i=0; i<5; i++){
		cmptchoice [i] = (90 - (rand() % 26));
    }
    s = cmptchoice;
    return s;
}

string pickTime(){
	int a;
	cout << "\n\t\t\t\tPICK TIME: ";
	cout << "\n\n\t\t\t\t1 - 7am \n";
	cout << "\t\t\t\t2 - 9am \n";
	cout << "\t\t\t\t3 - 11am \n";
	cout << "\t\t\t\t4 - 2pm \n";
	cout << "\t\t\t\t5 - 5pm \n";
	cout << "\t\t\t\t6 - 8pm \n";
	cout << "\t\t\t\t>: ";
	cin >> a;
	switch(a){
		case 1:
			return "7am";
			break;
		case 2:
			return "9am";
			break;
		case 3:
			return "11am";
			break;
		case 4:
			return "2pm";
			break;
		case 5:
			return "5pm";
			break;
		case 6:
			return "8am";
			break;
		default:
			cout << "\t\t\t\tINVALID CHOICE!";
			break;
	}
}

string pickDate(){
	string a;
	cout << "\n\n\t\t\t\tPlease type the date on mm/dd/yyyy format: \n";
	cout << "\n\t\t\t\t>: ";
	cin >> a;
	return a;
}

void outReceipt(){
	system("del.\\receipt.txt"); // this will delete the old receipt
	ofstream outFile("receipt.txt", std::ios_base::app);
	//ifstream file("flightUserData.txt", std::ios_base::app);
	outFile << "FLIGHT CODE: " << code << endl;
	outFile << "NAME: " << admin << endl;
	outFile << "FLYING FROM: " << info.flyF << " AIRPORT" << endl;
	outFile << "FLYING TO: " << info.flyT << " AIRPORT"  << endl;
	outFile << "DEPARTING ON: " << info.depOn << endl;
	outFile << "DEPARTING TIME: " << info.depTime << endl;
	outFile << "RETURNING ON: " <<  info.retOn << endl;
	outFile << "RETURNING TIME: "<< info.retTime << endl;
	outFile << "NUMBER OF ADULTS: " << info.adult << endl;
	outFile << "NUMBER OF CHILD(s): " << info.child << endl;
	outFile << "NUMBER OF INFANT(s): " << info.infant << endl;
	outFile << "NUMBER OF PASSENGER(s): " << numPassenger << endl;
	float gtotal = numPassenger * 2020;
	outFile << "GRAND TOTAL P " << gtotal<< endl;
	outFile.close();

}

void intoData(){
	//this will go into flightdata.txt make search algo work
	ofstream outFile2("flightDatas.txt", std::ios_base::app);
	outFile2 << code << endl;
	outFile2 << admin << endl;
	outFile2 << info.flyF << " AIRPORT" << endl;
	outFile2 << info.flyT << " AIRPORT"  << endl;
	outFile2 << info.depOn << endl;
	outFile2 << info.depTime << endl;
	outFile2 <<  info.retOn << endl;
	outFile2 << info.retTime << endl;
	outFile2 << info.adult << endl;
	outFile2 << info.child << endl;
	outFile2 << info.infant << endl;
	outFile2 << numPassenger << endl;
	float gtotal = numPassenger * 2020;
	outFile2 <<gtotal<< endl;
	outFile2.close();
}

void search(){
	string line;
	string fnum;
	ifstream inFile("flightDatas.txt", std::ios_base::app);
	cout << "\n\t\t\t\t\tTYPE THE FLIGHT CODE: \n\t\t\t\t\t>: ";
	cin >> fnum;
	// this will find the code and cout the 13lines after it
	while(!inFile.eof()){
		inFile >> line;
		if (line == fnum){
			for(int i = 0; i < 13;i++){
				switch (i){
					case 0:
						cout <<"\t\t\t\tFLIGHT CODE: " << line << endl;
						break;
					case 1:
						cout <<"\t\t\t\tNAME: " << line << endl;
						break;
					case 2:
						cout <<"\t\t\t\tFLYING FROM: " << line << endl;
						break;
					case 3:
						cout <<"\t\t\t\tFLYING TO: " << line << endl;
						break;		
					case 4:
						cout <<"\t\t\t\tDEPARTING ON: " << line << endl;
						break;
					case 5:
						cout <<"\t\t\t\tDEPARTING TIME: " << line << endl;
						break;
					case 6:
						cout <<"\t\t\t\tRETURNING ON: " << line << endl;
						break;
					case 7:
						cout <<"\t\t\t\tRETURNING TIME: " << line << endl;
						break;		
					case 8:
						cout <<"\t\t\t\tNUMBER OF ADULT(s): "<< line << endl;
						break;
					case 9:
						cout <<"\t\t\t\tNUMBER OF CHILD(s): " << line << endl;
						break;
					case 10:
						cout <<"\t\t\t\tNUMBER OF INFANT(s): " << line << endl;
						break;
					case 11:
						cout <<"\t\t\t\tTOTAL PASSENGERS(s): " << line << endl;
						break;
					case 12:
						cout <<"\t\t\t\tGRAND TOTAL P" << line << endl;
						break;		
					default:
						break;																
				}
				inFile >> line;
			}
		}
	}
	inFile.close();
}


