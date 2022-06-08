#include<iostream>
#include"atom.h"
//#include"atom.cpp"

int main(){
	Chemical hello,bla;
	hello.setName();
	hello.setSymbol();
	hello.setNumber();
	hello.setWeight();
	
	bla.setName();
	bla.setSymbol();
	bla.setNumber();
	bla.setWeight();
	hello.readInput();

	cout<<"Here is another chemical: " << bla.getName() << "[" << bla.getSymbol() << ", #" << bla.getNumber()<< ", " << bla.getWeight() << "]";
	//cout<<"Here is another chemical: "<<name<<"["<<symbol()<<", #"<<atomicNumber()<<", "<<atomicWeight()<<"]";
	//cout<<"Here is another chemical : "<<name<<"["<<symbol
	return 0;
}

