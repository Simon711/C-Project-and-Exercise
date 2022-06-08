#include<iostream>
using namespace std;

class Fraction
{
	int num, denom;
	
	public: 
		Fraction(int n=4, int d=9) //default argument constructor
		
		//Fraction(int) this is default constructor, so line 37 cannot be executed
		
		/*otherwise you have to add one default constructor on your own
		//Fraction()
		//{
		//	num=0;
		//	denom=0;
		}*/
		
		{
			num=n;
			denom=d;
			cout<<"Creaat the object with "
				<<num << " "<< denom<<" values "<<endl;
		}
		
		~Fraction()
		{
			cout<<"Destroy the object with "
				<<num << " "<< denom<<" values "<<endl;
		}
};

int main()
{
	Fraction f1(5);
	//Fraction f2;
	Fraction *f2 =new Fraction (3,2);
	Fraction f3(1,1);
	delete f2;
	return 0;
}
