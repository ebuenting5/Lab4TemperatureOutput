/*
Ethan Buenting
C++ Fall 2022
Due: Oct. 14, 2022
Lab 4 Temperature Output
This lab is a demonstration of my ability to input values from a file, filter the values for desirable characteristics, and graph both positive and negative values to a set scale.
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
//Precondition: Scale is set
//Poscondition: Data is imported from file to be handled
void Input(int temps);
//Precondition: Data is determined to be a negative value
//Postcondition: Number of stars is determined and values are displayed left of zero
void NegInput(int temps);
//Precondition: Data is determined to be positive
//Postcondition: Number of stars is determined and values are displayed to the right of zero
void PosInput(int temps);
//Preconditon: NA
//Postconditon: Scale is established at the top of the console in degrees Celcius
void Scale();
//Precondition: Data is imported from file and displayed
//Postconditon: Data is determined to either be negative or positive
void Star(int temps);

using namespace std;

string tempsin = "tempin.dat";
//string is established to use for the data input file

int main()
{
	int temps = 0;
	//temp variable is declared import data
	Scale();
	//Scale is created in degrees Celcius
	Input(temps);
	//Data is imported and stars are determined and displayed
	return 0;
}
void Input(int temps)
{
	ifstream infile;
	infile.open(tempsin);
	if (!infile)
		cout << "Can't find file!" << endl;
	//File is located or determind to be unavailable
	infile >> temps;
	//Priming read
	while (infile)
	{
		cout << setw(3) << temps;
		Star(temps);
		infile >> temps;
	}
	//Loop is used to read in file and read all the data within
}
void Scale()
{
	cout << setw(13) << "-30" << setw(10) << "0" << setw(10) << "30";
	cout << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;
}
//Scale is set
void Star(int temps)
{
	if (temps >= -30 && temps < 0)
	{
		NegInput(temps);
	}
	if (temps >= 0 && temps <= 120)
	{
		PosInput(temps);
	}
}
//The data is determined to either be positive or negative

void NegInput(int temps)
{
	int stars, negtemp, mod, i;
	negtemp = temps / -1;
	stars = negtemp / 3;
	mod = negtemp % 3;
	if (mod == 2)
		stars = stars + 1;
	cout << setw(20-stars);
	for (i = 0; i < stars; i++)
		cout << "*";
	cout << "|" << endl;
}
//The negative data is made to be positive, the stars are calculated and are displayed to the left of zero

void PosInput(int temps)
{
	int stars, mod, i;
	cout << setw(20) << "|";
	stars = temps / 3;
	mod = temps % 3;
	if (mod == 2)
		stars = stars + 1;
	for (i = 0; i < stars; i++)
		cout << "*";
	cout << endl;
}
//The data is positive, stars are then calculated and displayed to the right of the zero