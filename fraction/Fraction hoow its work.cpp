#include <iostream>
using namespace std;

class Fraction
{
	private:
		int num, denom;
		
	public:
		void readFrac() //No return value
		{
			cin >> num >> denom;
		}
		
		void dispFrac()
		{
			cout << num << "/" << denom;
		}
		
		Fraction multiply(Fraction f)	//Return Fraction, because fraction is the object need to be recall. (the reason of we put fraction f withnin parenthesis is because we need to pass the value from function 
		{
			Fraction obj;
			obj.num = num * f.num;    //f1.num is belong to the object f1, so we can just take off the f1. f2.num is belong to f2's num
			obj.denom = denom * f.denom;
			
			return obj;
		}
		
};
		
int main()
{
	Fraction f1, f2, f3;
	
	cout << "Enter first fraction: ";
	f1.readFrac();
	cout << "Your fraction: \n";
	f1.dispFrac();
	
	cout << "\nEnter second fraction: \n";
	f2.readFrac();
	cout << "Your fraction: ";
	f2.dispFrac();
	return 0; 
	
	f3 = f1.multiply(f2);
	cout << "Your result is: ";
	f3.dispFrac();
	
	
	
	
	return 0;
}
