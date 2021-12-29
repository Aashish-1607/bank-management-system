#include <iostream>
#include<fstream>
#include<cctype>
#include "account.h"
#include "account.cpp"
using namespace std;

int main() {
	char ch;
	int num;
	intro();
	do {
		system("cls");
		cout << "\n\n\tMAIN MENU";
		cout << "\n\n\t01. NEW ACCOUNT";
		cout << "\n\t02. DEPOSIT AMOUNT";
		cout << "\n\t03. WITHDRAW AMOUNT";
		cout << "\n\t04. BALANCE ENQUIRY";
		cout << "\n\t05. ALL ACCOUNT HOLDER LIST";
		cout << "\n\t06. CLOSE AN ACCOUNT";
		cout << "\n\t07. MODIFY AN ACCOUNT";
		cout << "\n\t08. EXIT";
		cout << "\n\tSelect Your Option (1-8) ";
		cin >> ch;
		system("cls"); // Clear output screen
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; 
			cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; 
			cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4': 
			cout<<"\n\n\tEnter The account No. : "; 
			cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; 
			cin>>num;
			delete_account(num);
			break;
		case '7':
			cout<<"\n\n\tEnter The account No. : "; 
			cin>>num;
			modify_account(num);
			break;
		case '8':
			cout<<"\n\n\tBank Managemnt system o go riyō itadaki arigatōgozaimasu";
			break;
		default :
		 	cout<<"Please select an option from 1-8 only";
		}
		cin.ignore();
		cin.get();
	} while(ch!='8');
	return 0;
}