#include<iostream>
#include<string>
using namespace std;

class Circle
{
	int radius;
	public:
		Circle(int rad)
		{
			radius = rad;
		}
		void show();
		friend void display();
};
void Circle::show()
{
	cout<< radius ;
}
void display()
{
	Circle c(9);
	cout<< c.radius;
}

int main()
{
	Circle c(7);
	display();
	c.show();
	
	return 0;
}




