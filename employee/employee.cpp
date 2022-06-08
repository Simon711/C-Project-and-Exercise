//programming technique 2 c++, fourth edition 2015, page 148

#include<iostream>
using namespace std;

class Employee{
	
	string name;
	int idNumber;
	string department;
	string position;
	
	public:
//v)		
		Employee(string a, int b, string c, string d) 	//accept arguments, and assign to the members
		{
			name=a;
			idNumber=b;
			department=c;
			position=d;
		}
//vi)		
		Employee(string a, int b)	//base on question, only put " " in body and put name and idNumber in argument
		{
			name=a;
			idNumber=b;
			department=" ";
			position=" ";
		}		
//vii)	
		Employee()		//this is default construstor not default argument constructor, cannot put any argument in it 
		{
			name=" ";		//question ask to set " " to the members
			idNumber=0;
			department=" ";
			position=" ";
		}
//viii)
		void setName(string a)		//mutator
		{
			name=a;
		}
	
		void setNumber(int b)
		{
			idNumber=b;
		}
		
		void setDepart(string c)
		{
			department=c;
		}
		
		void setPosition(string d)
		{
			position=d;
		}
//ix)
		string getName()	//acessor
		{
			return name;
		}
		
		int getNumber()
		{
			return idNumber;
		}
		
		string getDepart()
		{
			return department;
		}
		
		string getPosition()
		{
			return position;
		}///getline(cin, a)
};

int main() //i)
{
	Employee emp1("Syed Mahadi", 47899, "Accounting", "Vice President"); // set the data and send to the construction
	//emp1.Employee("Syed Mahadi", 47899, "Accounting", "Vice President");  //you have to do this in the previious line (creat object direct assign
	cout<<emp1.getName()<<endl;
	cout<<emp1.getNumber()<<endl;
	cout<<emp1.getDepart()<<endl;
	cout<<emp1.getPosition()<<endl;
}
