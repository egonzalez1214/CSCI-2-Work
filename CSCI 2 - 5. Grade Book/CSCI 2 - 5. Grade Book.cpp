// CSCI 2 - 5. Grade Book.cpp : This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
using namespace std;

int main()
{
	string studentNames[5];
	char studentGrade[5];
	double student1Scores[4], student2Scores[4], student3Scores[4],
		   student4Scores[4], student5Scores[4];

	void GetStudentInfo(string studentNames[5], double student1Scores[4],
						double student2Scores[4], double student3Scores[4],
						double student4Scores[4], double student5Scores[4]);
}

void GetStudentInfo(string studentNames[5], double student1Scores[4],
					double student2Scores[4], double student3Scores[4],
					double student4Scores[4], double student5Scores[4])
{
	// the * declares this as a pointer array, so its like a 2D array,
	// but it only points to the array im filling at the time...
	double* allScores[5] = {student1Scores, student2Scores, student3Scores,
							student4Scores, student5Scores};
	char studentGrade[5];
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
			cout << "Enter the score for test " << j + 1 << ": ";
			cin >> allScores[i][j];
		}
		studentGrade[i] = GetLetterGrade(CalculateStudentAvg(allScores[i]));
	}
}

double CalculateStudentAvg(double studentScores[4])
{
	double sumScores = 0;
	// simple avg calculator, since i am just passing values to get the
	// sum, i dont need to pass all the score arrays, just the one that
	// i will call at the time...
	for (int i = 0; i < 4; i++)
	{
		sumScores += studentScores[i];
	}
	return sumScores / 4;
}

char GetLetterGrade(double studentAvg)
{
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

void PrintResults (string studentNames[5], double student1Scores[4],
					double student2Scores[4], double student3Scores[4],
					double student4Scores[4], double student5Scores[4])
{
	
}