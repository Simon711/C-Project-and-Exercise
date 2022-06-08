//exercise 3, q1, page 41
#include<iostream>
using namespace std;

class Mechanic
{
	private:
		string name, staffid;
		float hourworked, salary, rate; //a
	
	public:
		Mechanic(string a, string b, float c, float d, float e); //b
		void caculateSalary(); //c
		void display(); //d
		friend caculateEPF(const Mechanic obj);

};

Mechanic::Mechanic(string a, string b, float c, float d, float e)	//constructor
{
	name=a;
	staffid=b;
	hourworked=c;
	salary=d;
	rate=e;

	caculateSalary();
}

void Mechanic::caculateSalary()
{
	salary= hourworked*rate;
}

void Mechanic::display()
{
	cout<<"Name= "<<name<<endl	
		<<"Staff id= "<<staffid<<endl
		<<"Hour works= "<<hourworked<<endl
		<<"Rate per hour= "<<rate<<endl
		<<"Salary is RM " <<salary;
}

caculateEPF(const Mechanic obj)
		{
			return 0.05 * obj.salary;
		}
		
int main()
{
	Mechanic m("simon", "Simon711", 12, 7,11);
	m.display();
	cout<<"\nEPF is RM "<<caculateEPF(m)<<endl;
	
	return 0;
}
