// CSCI 2 - 5. Grade Book.cpp : This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// HUGE function prototypes
void GetStudentInfo(string studentNames[5], char studentGrade[5], double student1Scores[4],
					double student2Scores[4], double student3Scores[4],
					double student4Scores[4], double student5Scores[4]);
double CalculateStudentAvg(double studentScores[4]);
char GetLetterGrade(double studentAvg);
void PrintResults(string studentNames[5], char studentGrade[5], double student1Scores[4],
				  double student2Scores[4], double student3Scores[4],
				  double student4Scores[4], double student5Scores[4]);

int main()
{
	// declaring all my empty arrays...
	string studentNames[5];
	char studentGrade[5];
	double student1Scores[4], student2Scores[4], student3Scores[4],
		   student4Scores[4], student5Scores[4];

	// only running two functions, the others are just for calculating...
	GetStudentInfo(studentNames, studentGrade, student1Scores, student2Scores,
				   student3Scores, student4Scores, student5Scores);
	PrintResults(studentNames, studentGrade, student1Scores, student2Scores,
				 student3Scores, student4Scores, student5Scores);
}

void GetStudentInfo(string studentNames[5], char studentGrade[5], double student1Scores[4],
					double student2Scores[4], double student3Scores[4],
					double student4Scores[4], double student5Scores[4])
{
	// the * declares this as a pointer array, so its like a 2D array,
	// but it only points to the array im filling at the time...
	double* allScores[5] = {student1Scores, student2Scores, student3Scores,
							student4Scores, student5Scores};
	// looping to fill our first array, with student names...
	for (int i = 0; i < 5; i++)
	{	
		cout << "Enter the name of student " << i + 1 << ": ";
		cin >> studentNames[i];
		// second loop, using the pointer array i declared earlier...
		// this lets me fill in each score array one by one, which falls
		// in line with what i wanted to do, just better...
		for (int j = 0; j < 4; j++)
		{
			// filling in each element in score array using j
			cout << "Enter the score for test " << j + 1 << ": ";
			cin >> allScores[i][j];
			// input validation: no negatives, zero ok
			if (allScores[i][j] < 0)
			{
				// error message, and decrement j to redo this element
				cout << "Please input an appropriate test score..." << endl;
				j--;
			}
		}
		// while we're here, can use allScores to get our avg...
		double  studentAvg = CalculateStudentAvg(allScores[i]);
		// and use that avg to fill in our studentGrade array...
		studentGrade[i] = GetLetterGrade(studentAvg);
		cout << endl;
	}
}

double CalculateStudentAvg(double studentScores[4])
{
	// simple avg calculator, since i am just passing values to get the
	// sum, i dont need to pass all the score arrays, just the one that
	// i will call at the time...
	double sumScores = 0;
	for (int i = 0; i < 4; i++)
	{
		sumScores += studentScores[i];
	}
	return sumScores / 4;
}

char GetLetterGrade(double studentAvg)
{
	// simple else if to get letter grade
	if (studentAvg >= 90)
	{
		return 'A';
	}
	else if (studentAvg >= 80)
	{
		return 'B';
	}
	else if (studentAvg >= 70)
	{
		return 'C';
	}
	else if (studentAvg >= 60)
	{
		return 'D';
	}
	else
	{
		return 'F';
	}
}

void PrintResults (string studentNames[5], char studentGrade[5], double student1Scores[4],
					double student2Scores[4], double student3Scores[4],
					double student4Scores[4], double student5Scores[4])
{
	// reusing this concept again...
	double* allScores[5] = {student1Scores, student2Scores, student3Scores,
							student4Scores, student5Scores};
	// needed something to actually pad... so i am using an empty string --> ""
	cout << setw(70) << setfill('-') << "" << endl;
	// headers, centering manually and using them for my line lenghts (70)
	cout << "| Student Name | Test 1 | Test 2 | Test 3 | Test 4 | Average | Grade |" << endl;
	cout << setw(70) << setfill('-') << "" << endl;
	// same thing as my first function, pointer is i...
	for (int i = 0; i < 5; i++)
	{
		// can use the pointer to get the name index
		cout << "|" << setw(14) << setfill(' ') << left << studentNames[i] << "|";
		// this goes through the array that i pointed to
		for (int j = 0; j < 4; j++)
		{
			// fetching each element in pointed array...
			cout << setw(8) << setfill(' ') << left << allScores[i][j] << "|";
		}
		// since i didn't store it, calculating this again...
		cout << setw(9) << setfill(' ') << left << CalculateStudentAvg(allScores[i]) << "|";
		// same as name, pointer is also char array element
		cout << setw(7) << setfill(' ') << left << studentGrade[i] << "|" << endl;
	}
	cout << setw(70) << setfill('-') << "" << endl;
}