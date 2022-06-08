#include<iostream>
#include"atom.h"
using namespace std;

void Chemical::setName(){
	cout<<"Please enter the request information to create a new chemical object.\n";
	cout<<"Enter the chemical's name: ";
	cin>> name;
}

void Chemical::setSymbol(){
	cout<<"\nPlease enter the chemical's symbol: ";
	cin>>symbol;
}

void Chemical::setNumber(){
	cout<<"\nPlease enter the atomic's number: ";
	cin>>atomicNumber;
}

void Chemical::setWeight(){
	cout<<"\nPlease enter the atomic's weight: ";
	cin>>atomicWeight;
}

string Chemical::getName(){
return name;
}

string Chemical::getSymbol(){
return symbol;
}

int Chemical::getNumber(){
return atomicNumber;
}

double Chemical::getWeight(){
return atomicWeight;
}

void Chemical::readInput(){
	cout<<"You jsut entered information for hydrogen.\n";
	cout<<"And here are its datails: "<<getName()<<"["<<getSymbol()<<", #"<<getNumber()<<", "<<getWeight()<<"]"<<endl;
}

