// CSCI 2 - 3. Chips and Salsa Sales Report.cpp : This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
using namespace std;

// function prototypes
void PrintSalsaChart(int jarSold[], string salsaArray[]);
void CalcJarTotal(int jarSold[]);
void JarsBubbleSort(int jarSold[], string salsaArray[]);

int main()
{
    // initialized array for salsa names
    string salsaArray[] = { "Mild", "Medium", "Sweet", "Hot", "Zesty" };
    // array that will be filled with salsa sales
    int jarSold[5] = {};
    // loop to fill salsa jars sold
    for (int i = 0; i < 5; i++)
    {
        cout << "How many jars of " << salsaArray[i] << " salsa were sold: ";
		cin >> jarSold[i];
		// validating inputs: no negatives
        // zero is ok
        if (jarSold[i] < 0)
		{
			// give user error message when bad sale input
            cout << "Please enter an appropriate amount of jars sold..." << endl;
			// decrement i to go back a cycle, so it asks for the same salsa again
            i--;
		}
    }
    cout << endl;

    // function calls
	PrintSalsaChart(jarSold, salsaArray);
    CalcJarTotal(jarSold);
    JarsBubbleSort(jarSold, salsaArray);
}

// this will print our salsa chart
void  PrintSalsaChart(int jarSold[], string salsaArray[])
{
    cout << "----------------------" << endl;
    // was able to keep the formatting on this simple, it just fits
    cout << "|" << " Salsa Sales Report " << "|" << endl;
	cout << "----------------------" << endl;
	for (int i = 0; i < 5; i++)
	{
        // this took so long to tweak and figure out... really a trial and error situation...
        cout << "|" << setw(6) << left << salsaArray[i] << "|" << setw(13) << setfill(' ') << jarSold[i] << "|" << endl;
	}
    cout << "----------------------" << endl;
}

// this will add all jars for total jars sold
void CalcJarTotal(int jarSold[])
{
    int jarsTotal = 0;
    // very simple total sum
    for (int i = 0; i < 5; i++)
    {
        jarsTotal += jarSold[i];
    }
    // printing out the total
    cout << "Number of total Salsa jars sold: " << jarsTotal << endl;
}

// this will bubble sort for the highest and lowest selling salsas
void JarsBubbleSort(int jarSold[], string salsaArray[])
{
    for (int i = 0; i < 5; i++)
    {
        // had a little trouble till i figured out the -1 was essential...
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (jarSold[j] > jarSold[j + 1])
            {
                // swap the jarSold element for the sort
                swap(jarSold[j], jarSold[j + 1]);
                // mirrors the swap for the salsaArray, to sync the name with the sales
                swap(salsaArray[j], salsaArray[j + 1]);
            }
        }
    }
	// printing the last element (highest) and first element (lowest) for most/least
    cout << "The Salsa that sold the most is: " << salsaArray[4] << " @ " << jarSold[4] << " jars" << endl;
    cout << "The salsa that sold the least is: " << salsaArray[0] << " @ " << jarSold[0] << " jars" << endl;
}