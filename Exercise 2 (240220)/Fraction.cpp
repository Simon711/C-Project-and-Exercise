//Implementation file includes regular functions definition
#include "Fraction.h"
#include <iostream>
using namespace std;

void Fraction::readFrac()  //Reads a fraction
{
	char opr;
	
	cout << "Enter numerator / denominator: ";
	cin >> num >> opr >> denom;
}
		
void Fraction::dispFrac() const //Displays a fraction
{
	cout << num << "/" << denom;
}
		
Fraction Fraction::multiply (Fraction f) const //Multiplies fractions
{
	Fraction obj; //Create one local object to store the results of operation
			
	obj.num = num * f.num;
	obj.denom = denom * f.denom;
			
	return obj;
}

Fraction Fraction::divide(Fraction f) const //Divides fractions
{
	Fraction obj; 
			
	obj.num = num * f.denom;
	obj.denom = denom * f.num;
			
	return obj;
}
	
Fraction Fraction::add(Fraction f) const //Adds fractions
{
	Fraction obj; 
	
	if (denom == f.denom)		
	{
		obj.num = num + f.num;
		obj.denom = denom;
	}
	else
	{
		obj.num = (num * f.denom) + (f.num * denom);
		obj.denom = denom * f.denom;
	}		
	return obj;
}

Fraction Fraction::substract(Fraction f) const //Substracts fractions	
{
	Fraction obj; 
	
	if (denom == f.denom)		
	{
		obj.num = num - f.num;
		obj.denom = denom;
	}
	else
	{
		obj.num = (num * f.denom) - (f.num * denom);
		obj.denom = denom * f.denom;
	}		
	return obj;
}

