#include<iostream>
using namespace std;

class point{
	
	private:
		double x;
		double y;

	public:
		point(double a=0, double b=0);
		void shift(double a, double b);
		void set_x(double a);		
		void set_y(double b);
		double get_x();
		double get_y();
};

point::point(double a, double b)
{
	x=a;
	y=b;
}
	
void point::set_x(double a)
{
	x=a;
}

void point::set_y(double b)
{
	y=b;
}

double point::get_x()
{
	return x;
}

double point::get_y()
{
	return y;
}

void point::shift(double x_amount, double y_amount)
{
	x+=x_amount;
	y+=y_amount;
}

main()
{
	point p1(3,8), p2;
	p2.set_x(66.66);
	p2.set_y(88.88);
	cout<<p1.get_x()<<endl;
	cout<<p1.get_y()<<endl;
	cout<<p2.get_x()<<endl;
	cout<<p2.get_y()<<endl;
	p1.shift(-12,2);
	p2.shift(-100,88.88);
	cout<<p1.get_x()<<endl;
	cout<<p1.get_y()<<endl;
	cout<<p2.get_x()<<endl;
	cout<<p2.get_y()<<endl;
	
	return 0;
}
