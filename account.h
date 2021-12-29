#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class Account{
private:
	int acno;
	char name[100];
	int deposit;
	char type;
public:
	void createAccount();
	void showAccount() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int getAcno() const;
	int getDeposit() const;
	char getType() const;
};

void writeAccount();	//function to write record in binary file
void displaySp(int);	//function to display account details given by user
void modifyAccount(int);	//function to modify record of file
void deleteAccount(int);	//function to delete record of file
void displayAll();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function

#endif