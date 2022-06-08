//Implementation file includes main function
#include "Fraction.h"
#include <iostream>
using namespace std;

int main()
{
	Fraction f1, f2; //2 objects for 2 fractions
	Fraction f3; //Fraction to store the result after each of operation
	
	cout << "Enter 1st fraction: " << endl;
	f1.readFrac(); //Call readfrac to enter the values of num and denom for object, f1
	cout << "\nEnter 2nd fraction: " << endl;
	f2.readFrac(); //Call readfrac to enter the values of num and denom for object, f2
	
	cout << "\nOutput for all the arithematic operations: " << endl;
	f3 = f1.multiply(f2); //Call multiply by passing the object, f2 and assign the value returned to object, f3
	f1.dispFrac(); //Call dispFrac to display the values of num and denom for object, f1
	cout << " * ";
	f2.dispFrac(); //Call dispFrac to display the values of num and denom for object, f2
	cout << " = ";
	f3.dispFrac(); //Call dispFrac to display the values of num and denom for object, f3
	cout << endl;
	
	f3 = f1.divide(f2); //Call multiply by passing the object, f2 and assign the value returned to object, f3
	f1.dispFrac(); //Call dispFrac to display the values of num and denom for object, f1
	cout << " / ";
	f2.dispFrac(); //Call dispFrac to display the values of num and denom for object, f2
	cout << " = ";
	f3.dispFrac(); //Call dispFrac to display the values of num and denom for object, f3
	cout << endl;

	f3 = f1.add(f2); //Call multiply by passing the object, f2 and assign the value returned to object, f3
	f1.dispFrac(); //Call dispFrac to display the values of num and denom for object, f1
	cout << " + ";
	f2.dispFrac(); //Call dispFrac to display the values of num and denom for object, f2
	cout << " = ";
	f3.dispFrac(); //Call dispFrac to display the values of num and denom for object, f3
	cout << endl;

	f3 = f1.substract(f2); //Call multiply by passing the object, f2 and assign the value returned to object, f3
	f1.dispFrac(); //Call dispFrac to display the values of num and denom for object, f1
	cout << " - ";
	f2.dispFrac(); //Call dispFrac to display the values of num and denom for object, f2
	cout << " = ";
	f3.dispFrac(); //Call dispFrac to display the values of num and denom for object, f3
	cout << endl;
				
	return 0;
}
