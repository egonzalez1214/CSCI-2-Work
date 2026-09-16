// 9-16 Classwork.cpp
// This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

// TODO: Define the BankAccount class here
// Include:
// - private data members
// - constructor
// - deposit()
// - withdraw() 
// - displayInfo()

int main()
{
	string name;
	int accNum;
	double startBal;

	cout << "Enter account owner's name: ";
	getline(cin, name);
	cout << "Enter account number: ";
	cin >> accNum;
	cout << "Enter starting balance: $";
	cin >> startBal;

	// TODO: Create a BankAccount object using the constructor
	BankAccount account(name, accNum, startBal);

	double depAmount, withdrawAmount;
	cout << "Enter deposit amount: $";
	cin >> depAmount;
	// TODO: Call deposit()
	account.Deposit(depAmount);

	cout << "Enter withdrawal amount: $";
	cin >> withdrawAmount;
	// TODO: Call withdraw()
	account.Withdraw(withdrawAmount);

	cout << "\nAccount Information:\n";
	// TODO: Call displayInfo()
	account.DisplayInfo();

	return 0;
}