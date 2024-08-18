#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;
class Person
{
protected:
	//Attributes
	int id;
	string first_name, last_name, password;
public:
	//constructor
	Person() {
		this->id = 0;
	}
	Person(int id, string first_name, string last_name, string password) {
		this->first_name = first_name;
		this->last_name = last_name;
		this->id = id;
		this->password = password;
	}

	//setterrs
	void set_id(int id)
	{
		this->id = id;
	}
	void set_first_name(string first_name)
	{
		this->first_name = first_name;
	}
	void set_last_name(string last_name)
	{
		this->last_name = last_name;
	}
	void set_password(string password)
	{
		this->password = password;
	}

	//getters
	string get_first_name() {
		return this->first_name;
	}
	string get_last_name() {
		return this->last_name;
	}
	string get_password() {
		return this->password;
	}
	int get_id() const {
		return this->id;
	}
	virtual void displayRole() const = 0;

};

class Client :public Person {
	double balance;
public:
	Client() {
		this->balance = 1500;
	}
	Client(string first_name, string last_name, int id, string password, double balance) :Person(id, first_name, last_name, password)
	{
		this->balance = balance;
	}
	void set_balance(double balance) {
		this->balance = balance;
	}


	double get_balance() const {
		return this->balance;
	}

	void ch_name(string first_name, string last_name) {
		bool found = false;
		int b;
		cout << "Enter the first name\n";
		cin >> first_name;

		for (char ch : first_name)
			if (isdigit(ch)) {
				found = true;
			}
		if (found == true) {
			cout << "It must be only litter\n";
			cout << "Enter the first name\n";
			cin >> first_name;
		}
		cout << "Enter the last name\n";
		cin >> last_name;

		for (char ch : last_name)
			if (isdigit(ch)) {
				found = true;
			}

		if (found == true)cout << "It must be only litter\n";

		b = first_name.length() + last_name.length();
		if (b < 5 || b>20)
		{
			cout << "Enter the name from 5 to 20 character\n";
		}

	}

	void set_password(string password) {
		cout << "Enter the password\n";
		cin >> password;
		if (password.length() < 8 || password.length() > 20)
			cout << "Enter the password from 8 to 20 character\n";

	}


	void name() {
		cout << "Name : " << get_first_name() << " " << get_last_name() << endl;
		cout << "Id   : " << get_id() << endl;
		cout << "Balane : " << balance << endl;

	}

	void deposit(double amount) {
		balance += amount;
		cout << "The operation was completed successfuly\n";
		cout << "Your current balance : " << balance << endl;
	}

	void withdraw(double amount) {
		if (amount <= balance)
		{
			balance -= amount;
			cout << "The operation was completed successfuly\n";
			cout << "Your current balance : " << balance << endl;
		}
		else
		{
			cout << "your balance is insufficient\n";
		}
	}


	void transferTo(Client c2, double amount) {
		if (amount <= balance)
		{
			balance -= amount;
			c2.deposit(amount);
			cout << "The operation was completed successfuly\n";
			cout << "Your current balance : " << balance << endl;
		}
		else
		{
			cout << "your balance is insufficient\n";
		}
	}
	void recipient(Client c, double amount) {
		balance += amount;
		c.withdraw(amount);
		cout << "The operation was completed successfuly\n";
		cout << "Your current balance : " << balance << endl;
	}
	void displayRole() const override {
		cout << "Role: Cleint" << endl;
	}
};
class BankAccount {
private:
	int accountNumber;
	string accountHolder;
	double balance;

public:

	BankAccount(int accNumber, string accHolder, double initialBalance) {
		accountNumber = accNumber;
		accountHolder = accHolder;
		balance = initialBalance;
	}

	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "Successfully deposited $" << amount << endl;
		}
		else {
			cout << "Invalid deposit amount!" << endl;
		}
	}
	void withdraw(double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			cout << "Successfully withdrew $" << amount << endl;
		}
		else {
			cout << "Insufficient balance or invalid amount!" << endl;
		}
	}

	void displayAccountDetails() const {
		cout << "Account Number: " << accountNumber << endl;
		cout << "Account Holder: " << accountHolder << endl;
		cout << "Balance: $" << balance << endl;
	}

	// Getter for account number
	int getAccountNumber() const {
		return accountNumber;
	}
};



class Admin : public Person {
private:
	vector<BankAccount> accounts;

public:
	Admin(string name, int id) : Person(id, first_name, last_name, password) {}

	void displayRole() const override {
		cout << "Role: Admin" << endl;
	}

	void createAccount(int accountNumber, string accountHolder, double initialBalance) {
		BankAccount newAccount(accountNumber, accountHolder, initialBalance);
		accounts.push_back(newAccount);
		cout << "Account created successfully!" << endl;
	}

	void deleteAccount() {
		bool repeat = false;
		int account_num;
		cout << "please enter acc.num";
		cin >> account_num;
		while (repeat == false) {
			for (auto it = accounts.begin(); it != accounts.end(); ++it) {
				if (it->getAccountNumber() == account_num) {
					accounts.erase(it);
					cout << "Account deleted successfully!" << endl;
					repeat = true;
					return;
				}
			}
			cout << "Account not found!\n please enter valid ID" << endl;
			cin >> account_num;

		}
	}

	void viewAllAccounts() const {

		for (const auto& account : accounts) {
			displayRole();
			account.displayAccountDetails();
			cout << "-----------------" << endl;
		}
	}
};



class Employee :public Person {
private:
	//attributes
	int id;
	string name;
	string password;
	double salary;


public:
	//constructors
	void setid(int i) {


		id = i;


	}

	void setname(const string& N) {
		name = N;
		cin >> name;
		if (N.length() >= 5 || N.length() <= 20 && isAlphabetic(N)) {




		}
		else {
			cout << "error :Name must be alphabetic and between 5 and 20 characters.\n" << endl;
		}

	}
	void setpassword(const string& p) {

		password = p;
		cin >> password;
		if (p.length() >= 8 || p.length() <= 20) {


		}
		else {
			cout << "error :password must be  and between 8 and 20 number.\n" << endl;
		}

	}
	void setsalary(const double s) {
		salary = s;
		cin >> salary;
		if (s <= 5000) cout<<"no";



		else {
			cout << "error salary mutst be at least 5000\n";

		}



	}
	int getid()const {

		return id;

	}


	string getname()const {
		return name;
	}

	string getpassword()const {
		return password;
	}
	double getsalary()const {
		return salary;
	}

	void display()const {

		cout << "\nEmployee Name\n" << name << endl;
		cout << "\nEmployee Id\n" << id << endl;
		cout << "\nEmployee Salary\n" << salary << endl;
		cout << "\nEmployee Password\n" << password << endl;

	}

private:
	bool isAlphabetic(const string& s)const {
		for (char c : s) {
			if (isalpha(c)) {
				return true;
			}
		}

		return false;

	}
};



int main() {
	Client c1, c2;

	cout << "Welcome to the National Bank\n\n";

	string first_name, last_name;
	c1.ch_name(first_name, last_name);
	cout << "Enter id \n";

	int i;
	cin >> i;
	c1.set_id(i);

	c1.get_password();

	cout << "1- Deposit\n";
	cout << "2- Withdraw\n";
	cout << "3- Transfer To\n";
	cout << "4- Balance Check\n";

	cout << "Enter the operation number\n";
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "Enter the balance\n ";
		double amount;
		cin >> amount;
		c1.deposit(amount);
	}

	else if (n == 2)
	{
		cout << "Enter the balance\n ";
		double amount;
		cin >> amount;
		c1.withdraw(amount);
	}

	else if (n == 3)
	{
		cout << "Enter the account and balance\n ";
		double amount;
		cin >> amount;
		c1.transferTo(c2, amount);
	}

	else if (n == 4)
	{
		c1.name();
	}
	Admin admin1("Mariam", 402);
	admin1.createAccount(1001, " Ammar ", 500.0);


	admin1.viewAllAccounts();

	admin1.deleteAccount();
	admin1.viewAllAccounts();

	Employee ;



		int id;
		string name,  password;
		double salary;

		// ??? ?????? ?????? ?? ????????


		cout << "\nEnter  Name: \n";
		cin >> name;
		cout << "\nEnter Employee ID:\n ";
		cin >> id;

		cout << "\nEnter Salary: \n";
		cin >> salary;
		cout << "\nEnter Password:\n ";
		cin >> password;

		cout<<(id, first_name, last_name, password, salary);
		cout << name<<(" \n name  \n");

		cout << id << (" \n id \n");
		cout << salary << ("\n salary \n ");
		cout << password << ("\n password  \n ");
		// ??? ????????? ???????
		Employee display();

		return 0;
	}



