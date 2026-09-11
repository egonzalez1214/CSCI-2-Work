// CSCI 2 - 4. Payroll Calculator.cpp : This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// prototype functions
void GetEmployeeInfo(int empID[7], int empHours[7], double empRate[7], double empWage[7]);
void PrintEmployeeInfo(int empID[7], double empWage[7]);

int main()
{
    // initialized employee IDs
    int empID[7] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    // all arrays are going to have 7 elements... one for each employee
    int empHours[7];
    double empRate[7];
    double empWage[7];

    // print each employee's ID number
    cout << "---------------------" << endl;
    cout << "| List of Employees |" << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i < 7; i++)
    {
        // trying something new... a string command to help center my ids
        // the string command outputs how many (6) and what its outputting (' ')
        cout << "|" << string(6, ' ') << empID[i] << string(6, ' ') << "|" << endl;
    }
    cout << "---------------------" << endl << endl;

    // calling my functions
    GetEmployeeInfo(empID, empHours, empRate, empWage);
    PrintEmployeeInfo(empID, empWage);
}

void GetEmployeeInfo(int empID[7], int empHours[7], double empRate[7], double empWage[7])
{
    // iterating through each employee id one at a time
    for (int i = 0; i < 7; i++)
    {
        // do while loop to validate employee hours submitted: zero or greater
        // doing it here so it doesnt continue though the for loop and mess up the other arrays...
        do
        {
            cout << "Please enter the amount of hours employee " << empID[i] << " worked this week: ";
            cin >> empHours[i];
            // this error message will only loop when asking for this parameter
            if (empHours[i] < 0)
            {
                cout << "Please enter an appropriate amount of hours worked..." << endl;
            }
        } while (empHours[i] < 0);
        // do while loop to validate employee hourly rate submitted: 15 or greater
        // doing it here so it doesnt continue though the for loop and mess up the other arrays...
        do
        {
            cout << "What is this employee's hourly rate: $";
            cin >> empRate[i];
            // this error message will only loop when asking for this parameter
            if (empRate[i] < 15)
            {
                cout << "Please enter an appropriate wage (mininum $15.00)..." << endl;
            }
        } while (empRate[i] < 15);
        cout << endl;
        // calculate employee wages using empHours x empRate
        // doing this here as i am in the correct element to do the calcs
        // and will be able to use the loop to get each elements calc
        empWage[i] = empHours[i] * empRate[i];
    }
}

void PrintEmployeeInfo(int empID[7], double empWage[7])
{
    // the header for my data display
    cout << "-----------------------------" << endl;
    cout << "| Employee ID | Gross Wages |" << endl;
    cout << "-----------------------------" << endl;
    // loop to display each employee id with its corresponding gross wage
    for (int i = 0; i < 7; i++)
    {
        // unlike the string(#, 'char'), im using this sort of like formatting a table
        // inherently its different from adding spaces to one side, it sets the length with setw()
        // and fills in whatever isnt already filled in with a char using setfill()
        cout << "| " << setw(12) << setfill(' ') << left << empID[i];
        cout << "| $" << setw(11) << setfill(' ') << left << fixed << setprecision(2) << empWage[i];
        cout << "|" << endl;
    }
    cout << "-----------------------------";
}
