//Class specification file

#ifndef CHEMICAL_H
#define CHEMICAL_H
#include <string> //You need to include if you want to use standard string class
using namespace std;

class Chemical
{
	private:
		string name, symbol;
		int atomicNumber;
		double atomicWeight;
		
	public:
		//Mutators - to assign a value to the instance variables (attributes)
		void setName (string n);
		void setSymbol (string s);
		void setNumber (int n);
		void setWeight (double w);
		
		//Accesors - to retrieve a value of instance variables (attributes)
		string getName() const;
		string getSymbol() const;
		int getNumber() const;
		double getWeight() const;
		
		//Other method
		void readInput();
};

#endif
