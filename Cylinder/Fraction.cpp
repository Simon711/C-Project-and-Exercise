#include <iostream>
using namespace std;

	class fraction
	{
		private:
			int num, denom;
		
		public:
			void setNum(int n);
			void setDenom(int d);
			void readFrac();
			void displayFrac();
			
			fraction multiply(fraction);
			fraction divide(fraction);
			fraction add(fraction);
			fraction subtract(fraction);
			
			int getNum();
			int getDenom();
			
	 } ;
	 
	 void fraction:: setNum(int n)
	 {
	 	num=n;
	 }
	 
	 void fraction::setDenom(int d)
	 {
	 	denom=d;
	 }
	 
	 int fraction::getNum()
	 {
	 	return num;
	 }
	 
	 int fraction::getDenom()
	 {
	 	return denom;
	 }
	 
	 void fraction::displayFrac()
	 {
	 	cout<< num << "/" <<denom;
	 }
	 
	 fraction fraction::multiply(fraction f)
	 {
	 	fraction x;
	 	x.num= num * f.num;
	 	x.denom= denom * f.denom;
	 	return x;
	 }
	 
	 fraction fraction::divide(fraction f)
	 {
	 	fraction x;
	 	x.num= num * f.denom;
	 	x.denom= denom * f.num;
	 	return x;
	 }
	 
	 fraction fraction::subtract(fraction f)
	 {
	 	fraction x;
	 	if (denom == f.denom)
	 	{
	 		x.num= num + f.num;
	 		x.denom= denom;
		 }
		else
		{
			x.num= (num*f.denom)-(f.num*denom);
			x.denom= (denom*f.denom);
		}
		return x;
	 }
	 
	 fraction fraction::add(fraction f)
	 
	 {
	 	fraction x;
	 	if (denom == f.denom)
	 	{
	 		x.num = num - f.num;
	 		x.denom = denom;
		 }
		 else 
		 {
		 	x.num= (num*f.denom) + (f.num*denom);
		 	x.denom= (denom * f.denom);
		 }
		 return x;
	 }
	 
	 void fraction::readFrac()
	 {
	 	char opr;
	 	cin>> num >> opr >> denom;
	 }
	 
	 int main()
	 {
	 	fraction f1,f2,f3;
	 	cout<< "Enter 1st fraction: "<<endl;
	 	cout<< "Enter numerator / denominator: ";
		f1.readFrac();
		cout<< "Enter 2nd fraction: "<<endl;
	 	cout<< "Enter numerator / denominator: ";
	 	f2.readFrac();
	 	
	 	f1.displayFrac();
	 	cout<< " * ";
	 	f2.displayFrac();
	 	cout<< " = ";
	 	
	 	f3= f1.multiply(f2);
	 	f3.displayFrac();
	 	cout<< endl;
	 	
	 	f1.displayFrac();
	 	cout<< " / ";
	 	f2.displayFrac();
	 	cout<< " = ";
	 	f3=f1.divide(f2);
	 	f3.displayFrac();
	 	cout<< endl;
	 	
	 	f1.displayFrac();
	 	cout<< " + ";
	 	f2.displayFrac();
	 	cout<< " = ";
	 	f3= f1.add(f2);
	 	f3.displayFrac();
	 	cout<< endl;
	 	
	 	f1.displayFrac();
	 	cout<< " - ";
	 	f2.displayFrac();
	 	cout<< " = ";
	 	f3= f1.subtract(f2);
	 	f3.displayFrac();
	 	cout<< endl;
	 	
	 	return 0;
	 }
