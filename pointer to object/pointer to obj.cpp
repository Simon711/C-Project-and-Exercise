#include<iostream>
using namespace std;

class rectangle{
	
	int width, length;
	
	public:
	
	rectangle()
	{
		width=100;
		cout<<"default constructor"<< endl;
	}	
	
	rectangle(int w)
	{
		width=w;
		length=5;
		cout<<"Constructor with width: "<<width<<endl;
	}
	
	rectangle(int w, int l)
	{
		width=w;
		length=l;
		cout<<"Constructor with width: "<<width<<", "<<length<<endl;
	}

	~rectangle()
	{
		cout<<"destroy the object with width= "<<width<<endl;
	}
};

int main()
{
	rectangle *p=new rectangle(9);
	rectangle r1(9,6), r2(1);
	rectangle arr[5]={rectangle(999,777),rectangle(888)}; 	//if not declare the list, it will calls default constructor
	
	delete p;
	return 0;
}
