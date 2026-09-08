// CSCI 2 - 1. Lowest Score Drop.cpp : This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
using namespace std;

void getScore(int& score);
void calcAverage(int score1, int score2, int score3, int score4, int score5);
int(findLowest(int score1, int score2, int score3, int score4, int score5));

int main()
{
	int score1, score2, score3, score4, score5;

	// intro to the program, its just a me thing...
	cout << "Welcome to the Lowest Score Drop Program!\n"
			"This program will take your five scores, drop the lowest, "
			"and average the remaining four scores.\n";

	// "should be called by main for each score" so i called it five times
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);

	// called the average function here, since its a void it just prints results...
	calcAverage(score1, score2, score3, score4, score5);
}

void getScore(int& score)
{
	// used a do while loop since a while loop wastes an input when filtering...
	do
	{
		cout << "Please enter a score: ";
		cin >> score;

		// used this to verify that the input is not above 100 or a negative
		if (score < 0 || score > 100)
		{
			cout << "Invalid score. Please enter a score between 0 and 100." << endl;
		}
	} while (score < 0 || score > 100);
}

void calcAverage(int score1, int score2, int score3, int score4, int score5)
{
	// as the assignment said there will be 5 scores, the average wasn't too bad
	// made the average a double to account for decimals in the average
	double average = (score1 + score2 + score3 + score4 + score5) / 5.0;
	cout << "The average score is: " << average << endl;

	// called findLowest in here as per assignment, and again just prints the result
	int lowest = findLowest(score1, score2, score3, score4, score5);
	cout << "The lowest score is: " << lowest << endl;
}

int findLowest(int score1, int score2, int score3, int score4, int score5)
{
	// initialized lowest to score1, then just compared it to the other scores
	int lowest = score1;

	if (score2 < lowest)
	{
		lowest = score2;
	}
	if (score3 < lowest)
	{
		lowest = score3;
	}
	if (score4 < lowest)
	{
		lowest = score4;
	}
	if (score5 < lowest)
	{
		lowest = score5;
	}

	// returning a value as the function is an int, and not void
	return lowest;
}