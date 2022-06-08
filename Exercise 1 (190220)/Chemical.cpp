//Implementation file
#include "Chemical.h" //Include your class specification that you want to use in the implementation 
#include <iostream>
using namespace std;

//Member functions definition

//Mutators - to assign a value to the instance variables (attributes)
void Chemical::setName (string n)
{
	name = n;
}

void Chemical::setSymbol (string s)
{
	symbol = s;
}

void Chemical::setNumber (int n)
{
	atomicNumber = n;
}

void Chemical::setWeight (double w)
{
	atomicWeight = w;
}

//Accesors - to retrieve a value of instance variables (attributes)
string Chemical::getName() const
{
	return name;
}

string Chemical::getSymbol() const
{
	return symbol;
}

int Chemical::getNumber() const
{
	return atomicNumber;
}

double Chemical::getWeight() const
{
	return atomicWeight;
}

//Other method
void Chemical::readInput()
{
	cout << "Please enter the requested information to create a new chemical object." << endl;
	cout << "Enter the chemical's name: ";
	cin >> name; 
	cout << "Enter the chemical's symbol: ";
	cin >> symbol; 
	cout << "Enter the chemical's atomic number: ";
	cin >> atomicNumber; 
	cout << "Enter the chemical's atomic weight: ";
	cin >> atomicWeight; 
}
