#include<iostream>
using namespace std;

class cylinder //declare the class name
{
	private:
		float radius;  //attribute for the class
		float height;
		
	public:
		void readInput();	//to read the input from user
		//friend void displayResult(const cylinder);  	//display the result , stand alone function
		float calArea();	//calculate the area base on the input, put the fomula here
		float calVolume();	//cal the volume base on the input, put the fomula here
};

void cylinder::readInput()	//call the public function name and declare the function here
							//use void becasue there is no return value;
{
	cout<<"Enter the radius :";
	cin>>radius;
	cout<<"Enter the height :";
	cin>>height;	
}

float cylinder::calArea()
{
	float pi=3.142;	
	return pi*radius*radius;	//return to the fomula and save it to the function
}

float cylinder::calVolume()
{
	return height*calArea();//call the calArea function in this function as the fomula
}

void displayResult(const cylinder c)
{
	cout<<"The radius is: "<<c.radius<<endl
		<<"The height is: "<<c.height<<endl
		<<"The area is: "<<c.calArea()<<endl
		<<"The volume is: "<<c.calVolume();
}

int main()
{
	cylinder cy;	//create an object call as cy in the class cylinder (like open a new box to store data)
	cy.readInput();
	cy.calArea();
	cy.calVolume();
	displayResult(cy);
	
	return 0;
}
