#include <iostream>
#include "account.h"
#include<fstream>
#include<cctype>

using namespace std;

void Account::create_account(){
	cout<<"\nEnter The account No. :";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	cout<<"\n\n\nAccount Created..";
}

void Account::show_account() const{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}


void Account::modify(){
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}

	
void Account::dep(int x){
	deposit+=x;
}
	
void Account::draw(int x){
	deposit-=x;
}
	
void Account::report() const{
	cout<<acno<<" "<<name<<" "<<type<<" "<<deposit<<endl;
}

	
int Account::getacno() const{
	return acno;
}

int Account::getdeposit() const{
	return deposit;
}

char Account::gettype() const{
	return type;
}



void write_account(){
	Account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
	outFile.close();
}

void display_sp(int n){
	Account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile){
		cout<<"File could not be opened !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))){
		if(ac.getacno()==n){
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}

void modify_account(int n){
	bool found=false;
	Account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
		if(ac.getacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(Account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

void delete_account(int n){
	Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))){
		if(ac.getacno()!=n){
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}

void display_all(){
	Account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))){
		ac.report();
	}
	inFile.close();
}

void deposit_withdraw(int n, int option){
	int amt;
	bool found=false;
	Account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false){
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
		if(ac.getacno()==n){
			ac.show_account();
			if(option==1){
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2){
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.getdeposit()-amt;
				if((bal<500 && ac.gettype()=='S') || (bal<1000 && ac.gettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
        }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

void intro(){
    cout<<"\n\n\n\tIRASSHAIMASE!";
	cout<<"\n\n\t  BANK";
	cout<<"\n\tMANAGEMENT";
	cout<<"\n\t  SYSTEM";
	cout<<"\n\n\nMADE BY : Aashish\n\n";
	cin.get();
}