#include<iostream>
#include<iomanip>
using namespace std;

class Breads
{
	int code;
	double price;
	string name;
	
	public:
		Breads()
		{
			code=0;
			price=0;
			name= " ";
		}
		
		Breads(int a, double b, string c)
		{
			code=a;
			price=b;
			name=c;
		}
		
		~Breads()
		{
		};
		
		void setCode(int c)
		{
			code=c;
		}
		
		void setPrice(double p)
		{
			price=p;
		}
		
		string setBreadname(string n)
		{
			name=n;
			switch (code)
			{
				case 101:
					cout<<"Plain Croissant"; 
					name="\tPlain Croissant";
					break;
				case 102:
					cout<<"Cream-filled Croissant"; 
					name="\tCream-filled Croissant";
					break;
				case 103:
					cout<<"Sausage Croissant";
					name="\tSausage Croissant";
					break;
				case 202:
					cout<<"Plain Bun";
					name="\tPlain Bun";
					break;
				case 204:
					cout<<"Sambal Bun";
					name="\tSambal Bun";
					break;
				case 205:
					cout<<"Cheese Bun";
					name="\tCheese Bun";
					break;
				case 301:
					cout<<"Plain Braid";
					name="\tPlain Braid";
					break;
				case 305:
					cout<<"Cheese Braid";
					name="\tCheese Braid";
					break;
				case 306:
					cout<<"Sugar Braid";
					name="\tSugar Braid";
					break;
				return n;
			}
				
		}
		
		int getCode()
		{
			return code;
		}
		
		double getPrice()
		{
			return price;
		}
		
		string getBreadname()
		{
			return name;
		}
};

int main()
{
	int n,code,price;
	string name;
	double total,avg;
	Breads obj[100];
	Breads obj2(100, 1.00, "blabla");
	obj[n]=obj2;

	cout<<"How many bread types to enter? ";
	cin>>n;
	
	for (int x=0; x<=n; x++)
	{
		cout<<"\nEnter the information of brade #" <<(x+1)<<endl;
		
		cout<<"Bread code: ";
		cin>>code;
		obj[x].setCode(code);
		
		cout<<"\nBread name : ";
		obj[x].setBreadname(name);
		
		cout<<"\nPrice (RM): ";
		cin>>price;
		cout<<endl;
		obj[x].setPrice(price);
		total+=obj[x].getPrice();
}

	cout<<endl<<"No \t Bread Code \t\t Bread Name \t \tPrice(RM) \n\n";
	
	for (int x=0; x<n; x++)
	{
		cout<<(x+1)<<setw(14)<<obj[x].getCode()<<"       "<<obj[x].getBreadname()<<setw(15)<<obj[x].getPrice()<<endl;
	}
	
	avg=total/n;
	cout<<"\nAverage Price (RM): "<<avg;
	
	return 0;
}

