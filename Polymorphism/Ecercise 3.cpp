#include<iostream>
#include<cmath>
#include<string>
#define pi 3.1415
using namespace std;

class Shape{
	public:
		Shape(){};
		virtual double getArea(){}
		virtual void read(){}
		virtual void print(){}
};

class Point{
	private:
		double x, y;
	public:
		Point(){
		x=0;
		y=0;
	}
	
		void set(double x, double y){
			this->x = x;
			this->y = y;
		}
		
		double getX(){
			return x;
		}
		
		double getY(){
			return y;
		}
};

class Rectangle: public Shape{
	private:
		int x1,x2,y1,y2;
		Point point1, point2;
		
		double getWidth(){
			return x2-x1;
			};
			
		double getHeight(){
			return y1-y2;
		};
	public:
		Rectangle(){};
	
		void read(){
			cout<<"Enter the top left corner coordinates of the rectangle (x y) => ";
			cin>>x1, cin>>y1;
			cout<<"\nEnter the bottom right corner coordinates of the rectangle (x y) => ";
			cin>>x2, cin>>y2;
			cout<<endl;
			point1.set(x1,y1);
			point2.set(x2,y2);
		};
		
		double getArea(){
			return getWidth()*getHeight();
		};
		
		void print(){
			cout<<"Rectangle's top left corner: "
				<<"X="<<x1<<"  Y="<<y1
				<<"\nRectangle's bottom right corner: "
				<<"X="<<x2<<"  Y="<<y2		
				<<"\nRectangle's width  = "<<getWidth()
				<<"\nRectangle's height = "<<getHeight()
				<<"\nRectangle's area   = " <<getArea()<<endl;
		};
};

class Circle: public Shape{
	private:
		Point point;
		double radius;
	public:
		int x,y;
		Circle(){}
		
		void read(){		
		cout<<"Enter the center coordinates of the circle (x y)=> ";
		cin>>x, cin>>y;
		cout<<"\nEnter the circle's radius=> ";
		cin>>radius;
		point.set(x,y);
		}
		
		double getArea(){
			return pi*pow(radius,2);
		}
		
		void print(){
			cout<<"Circle's center: "
				<<"X="<<x<<"  Y="<<y
				<<"\nCircle's radius ="
				<<radius
				<<"\nCircle's area   ="<<getArea()<<endl;
		}
};

int main(){
	
	string line(10, '=');
	double totalArea=0;	
	Shape *shape[3];
	
	int choice, choice2;
	int counter=0;
	
	do{
	cout<<endl<<line<<"[MENU]"<<line;
	
	cout<<"\n\n1. Add a shape \n"
		<<"2. Print all shapes \n"
		<<"3. Calculate total area \n"
		<<"4. Exit \n\n";
		
		cout<<"Enter your choice => ";
		cin>>choice;
					
	if(choice==1){
		cout<<"\nWhat type of shape you want to enter? \n"
			<<"\t1. Circle\n"
			<<"\t2. Rectangle \n\n";
			
		cout<<"Your choice => ";
		cin>> choice2, cout<<endl<<endl;	
		

		if (choice2==1){
			shape[counter]= new Circle;
			shape[counter]->read();
		}
		
		else if (choice2==2){
			shape[counter]= new Rectangle;
			shape[counter]->read();
		}
		counter++;
}

	else if (choice==2){
		for(int x=0; x<counter; x++){
			cout<<endl<<"Shape #"<<(x+1)<<endl;
			shape[x]->print();
		}
	}
	
	else if (choice==3){
		for (int x=0; x<counter; x++){
			totalArea+=shape[x]->getArea();
		}
		cout<<"Total Area= "<< totalArea<<endl<<endl;	
	}
	
}while(choice!=4);

	return 0;
}
