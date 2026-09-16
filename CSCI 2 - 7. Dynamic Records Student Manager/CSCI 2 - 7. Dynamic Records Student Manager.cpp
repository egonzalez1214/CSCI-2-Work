// CSCI 2 - 7. Dynamic Records Student Manager.cpp
// This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string studentName;
	double studentGPA;
};

void CreateStudentArray(int size, Student* studentArray);
void PrintStudentArray(int size, Student* studentArray);
void ResizeStudentArray(int size, Student* studentArray);
void CurveStudentGrades();

int main()
{
	int size;
	// initializing size to start our pointer array
	cout << "How many students do you want to add: ";
	cin >> size;
	// pointer array to fill in our struct
	Student* studentArray = new Student[size];
	// function to fill our array
	CreateStudentArray(size, studentArray);
	// printing our info
	PrintStudentArray(size, studentArray);

	string response;
	do
	{
		// get user input for more students
		cout << "Do you want to add any more students? (Y/Yes/N/No): ";
		cin >> response;
		cin.ignore();
		// toupper to not have to deal with cases
		for (int i = 0; i < response.length(); i++)
		{
			response[i] = toupper(response[i]);
		}
		// checking for valid response
		if (response != "Y" || response != "YES"
			|| response != "N" || response != "NO")
		{
			cout << "Please enter a valid response (Y/Yes/N/No): ";
		}
	} while (response != "Y" || response != "YES"
			|| response != "N" || response != "NO");

	CurveStudentGrades();
	// reprint

	delete[] studentArray;
}

void CreateStudentArray(int size, Student* studentArray)
{
	// fill in our struct info with this pointer array
	for (int i = 0; i < size; i++)
	{
		// i + 1 since i = 0...
		cout << "What is student " << i + 1 << "'s name: ";
		getline(cin,studentArray[i].studentName);
		cout << "What is that students GPA: ";
		cin >> studentArray[i].studentGPA;
	}
}

void PrintStudentArray(int size, Student* studentArray)
{
	// just an extra function to print student info
	cout << "--------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "| " << studentArray[i].studentName << " ";
		cout << "| " << studentArray[i].studentGPA << " |";
		cout << "--------------------" << endl;
	}
}

void ResizeStudentArray(int size, Student* studentArray)
{
	// placeholder to get newSize
	int moreStudents;
	cout << "How many students did you want to add: ";
	cin >> moreStudents;
	// placeholder till we replace size with newSize
	int newSize = size + moreStudents;
	// copy the elements from old array to the temp new array
	Student* newStudentArray = new Student[newSize];
	for (int i = 0; i < size; i++)
	{
		newStudentArray[i] = studentArray[i];
	}
	// get new students info
	// i will start at size as that will be the last element of
	// the old array + 1, filling in the missing elements
	for (int i = size; i < newSize; i++)
	{
		cout << "What is student " << i << "'s name: ";
		getline(cin, newStudentArray[i].studentName);
		cout << "What is the student's GPA: ";
		cin >> newStudentArray[i].studentGPA;
	}
	// delete our old aray that is now in the new array
	delete[] studentArray;
	// replace our old array with the new array
	studentArray = newStudentArray;
	// replace size with our new size
	size = newSize;
}

void CurveStudentGrades()
{

}