#include<iostream>
using namespace std;

class Point{
	int x, y;
	
	public:
		Point()
		{
			x=0;
			y=0;
		}
		Point(int a,int b)
		{
			x=a;
			y=b;
		}
		
		Point(const Point &d)
		{
			x = d.x;
			y = d.y;
		}
		
		void display()
		{
			cout<<"x= "<<x;
			cout<<"\ty= "<<y<<endl;
		}	
		
		void display(string a)
		{
			cout<<a<<": ";
			cout<<"x= "<<x;
			cout<<"\ty= "<<y<<endl;
		}
		
//		Point operator+(Point p) //accept form int main()
//		{
//			Point a;
//			a.x = x+p.x;
//			a.y = y+p.y;
//			return a; //pass to int main()
//		}
//		
		Point operator+(Point p)
		{
			Point a;
			a.x = this -> x + p.x; //p.x is the x in point 2
			a.y = this -> y + p.y; //this->y is the member in the class 
			// a.x is save the (result) into the object a
			return a;
		}
		
		friend float slope(Point a, Point b);
};

		float slope(Point a, Point b)
		{
			float c;
			c = (b.y-a.y)/(b.x-a.x);
			return c;
		}
		
int main()
{
	Point p1(1,2);
	Point p2(3,4);

	Point p3=p1+p2;
	p1.display();
	p2.display();
	p3.display("\nThird point");
	cout<<"Slope= "<<slope(p1,p2);
}






