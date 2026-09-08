// CSCI 2 - 2. Paint Job Estimator.cpp : This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
// using this to format my money
#include <iomanip>
// cmath to round my gallons up, can't buy 2.1 gallons at home depot...
#include <cmath>
using namespace std;
// cout << fixed << setprecision(2); <-- had to look this up...

// prototype functions
int GetTotalRooms();
double GetPaintPrice();
double GetRoomSizes(int roomCount);
void GetAllCalculations(double totalRoomSize, double paintCost,
    int& paintTotal, double& laborHours, double& paintTotalCost,
    double& laborCost, double& totalCost);
void DisplayResults(int paintTotal, double laborHours,
    double paintTotalCost, double laborCost, double totalCost);

int main()
{
	cout << "Welcome to the Paint Job Estimator program!\n";
	cout << "This program will help you calculate everything about your paint job.\n";
    cout << endl;
    
    // i declared these like this as there is no referencing required
	int roomCount = GetTotalRooms();
	double paintCost = GetPaintPrice();
	double totalRoomSize = GetRoomSizes(roomCount);

	int paintTotal;
    double laborHours, paintTotalCost, laborCost, totalCost;
    // i had to make the name really long on this one to make one function to calculate everything
	GetAllCalculations(totalRoomSize, paintCost, paintTotal, laborHours,
                       paintTotalCost, laborCost, totalCost);
    // same with this one, really long name
    DisplayResults(paintTotal, laborHours, paintTotalCost, laborCost, totalCost);
}

int GetTotalRooms()
{
    int roomCount;
    // using a do while loop to validate user inputs
    do
    {
        cout << "How many rooms will be painted for this job: ";
        cin >> roomCount;

        if (roomCount < 0 || roomCount == 0)
        {
            cout << "Please enter a valid number of rooms to be painted.\n";
        }
    } while (roomCount < 0 || roomCount == 0);

    cout << endl;
	return roomCount;
}

double GetPaintPrice()
{
    double paintCost;
    // another do while loop for validation
    do
    {
        cout << "What is the price of the paint you wish to use: $";
        cin >> paintCost;
        if (paintCost < 10)
        {
            cout << "Please enter a valid price for the paint.\n";
        }
    } while (paintCost < 10);

    cout << endl;
	return paintCost;
}

double GetRoomSizes(int roomCount)
{
    double roomSize;
    // remember to initialize before loop, can't add something to nothing...
    double totalRoomSize = 0;
    // a for loop to iterate through the number of rooms previously given
	for (int i = 0; i < roomCount; i++)
	{
        // trusty do while validation
        do
        {
            cout << "What is the size of room " << (i + 1) << " in square feet: ";
            cin >> roomSize;
            // requirements said 0 or greater...
            if (roomSize < 0)
            {
                cout << "Please enter a valid size for the room.\n";
            }
		} while (roomSize < 0);
        // totalRoomSize adds to itself, STARTING AT 0...
		totalRoomSize += roomSize;
	}

    cout << endl;
    // figured that i need to return something here, so i returned totalRoomSize
    // the requirements didnt state i had to return any totals for individual rooms,
	// so i just returned the total of all rooms
	return totalRoomSize;
}

// voided this function and passed by reference to get all my calcs, really long name though...
void GetAllCalculations(double totalRoomSize, double paintCost,
    int& paintTotal, double& laborHours, double& paintTotalCost,
    double& laborCost, double& totalCost)
{
    // using ceil to round up gallons of paint
    // had to look up static cast as i couldn't change a double to int...
    // and i really wanted this to make sense to me...
    paintTotal = static_cast<int>(ceil(totalRoomSize / 110));
	laborHours = (totalRoomSize / 110) * 8;
	paintTotalCost = paintTotal * paintCost;
    laborCost = laborHours * 25.00;
	totalCost = paintTotalCost + laborCost;
}

void DisplayResults(int paintTotal, double laborHours, double paintTotalCost,
	double laborCost, double totalCost)
{
	cout << "Gallons of paint required: " << paintTotal << '\n';
    // using the formatting i looked up
    cout << fixed << setprecision(2);
	cout << "Hours of labor required: " << laborHours << '\n';
	cout << "Total paint cost: $" << paintTotalCost << '\n';
	cout << "Total labor cost: $" << laborCost << '\n';
	cout << "Total cost for the job: $" << totalCost << '\n';
}
