#ifndef ATOM_H
#define ATOM_H
using namespace std;
class Chemical{
	
	string name;
	string symbol;
	int atomicNumber;
	double atomicWeight;
	
	public:
		string getName();
		void setName();
		string getSymbol();
		void setSymbol();
		int getNumber();
		void setNumber();
		double getWeight();
		void setWeight();
		void readInput();
};

#endif
