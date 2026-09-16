#pragma once
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
	string custName;
	int custAccNum;
	double custBal;

public:
	BankAccount(string name, int accNum, double startBal)
	{
		custName = name;
		custAccNum = accNum;
		custBal = startBal;
	}

	void Deposit(double amount)
	{
		custBal += amount;
	}

	void Withdraw(double amount)
	{
		if (amount < custBal)
		{
			custBal -= amount;
		}
		else
		{
			cout << "Insufficient funds for withdrawal...";
		}
	}

	void DisplayInfo()
	{
		cout << custName << endl;
		cout << "Acc #: " << custAccNum << endl;
		cout << "Remaining Balance: $" << custBal << endl;
	}
};
