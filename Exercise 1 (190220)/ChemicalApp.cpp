//Application file
#include "Chemical.h" //Include your class specification that you want to use to create the object
#include <iostream>
using namespace std;

int main()
{
	Chemical obj1, obj2; //For hydrogen and sodium
	
	//You need to use the object that you are created to access the public member functions/ attributes of Chemical class
	obj1.readInput(); //To let the user enter the chemical info
	
	//To display the info that you already entered via readInput function
	cout << "\nYou just entered information for " 
		 << obj1.getName() << endl; //Use getName function to retrieve the value of name of obj1 
	cout << "And here are its details: "
		 << obj1.getName() << " ["
		 << obj1.getSymbol() << ", #"
		 << obj1.getNumber() << ", "
		 << obj1.getWeight() << "]" << endl; //You need to use the accessors to retrieve all the info of obj1
	
	//To assign the value to the instance variables/ attributes of obj2 via mutators
	obj2.setName("Sodium");
	obj2.setSymbol("Na");
	obj2.setNumber(11);
	obj2.setWeight(22.98977);
	
	////To display all the info of obj2 via accessors
	cout << "Here is another chamical: "
		 << obj2.getName() << " ["
		 << obj2.getSymbol() << ", #"
		 << obj2.getNumber() << ", "
		 << obj2.getWeight() << "]" << endl; //You need to use the accessors to retrieve all the info of obj1

	return 0;
}
