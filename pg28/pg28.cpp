#include<iostream>
#include<string>
using namespace std;

class Product
{
	int Code;
	double Price;
	
	public:
		Product()	//constructor (to initialize value)
		{
			Code=0;
			Price=0;
		}
		
		Product(int a, double b)	//default argument constructor 
		{
			Code=a;		//set argument a to Code in private
			Price=b;	//set argument b to code in private
		}
		
		~Product()		//destructor
		{				//no body in it
		}
		
		void setCode(int c)		//setCode 
		{
			Code=c;		//only assign Code=c, no return value
		}
		
		void setPrice(double p)
		{
			Price=p;
		}
		
		int getCode()	//for displaying, calculation
		{
			return Code;
		}
		
		double getPrice()
		{
			return Price;
		}
};

int main()
{
	int n, code;
	double p, total = 0;
	Product obj[100];
	cout<<"How many products to enter? ";
	cin>>n;
	
		for (int x=0; x<n; x++)		//looping for the input 
		{
		cout<<"Enter the information of product  #"<<(x+1);
			cin>>code;		
			cin>>p;
			obj[x].setCode(code);	//pass the input to setcode, (pass the other input/identifier to the attribute)
			obj[x].setPrice(p);		//pass the input to setPrice
		}							//we use pass value becasue we cannot access the private attributes outside the class
	
	Product b(100,1);	//set the default value to the overloaded constructor
	obj[n]=b;	//set the 2nd object to the obj array n, which is input from user
	
	cout<<"No   "<<"Product code   "<<"Price"<<endl;
	for (int y=0; y<=n; y++)		//looping for the displaying output
	{
		cout<<y<<"   "<<obj[y].getCode()<< "   "<<obj[y].getPrice();	//only display, so use get
		total += obj[y].getPrice();		//to save the total of each obj[x]
	}
	cout<<"Average Price: "<< total/(n+1);		//to get average
}
