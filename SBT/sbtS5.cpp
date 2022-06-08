#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Do not modify the class declaration
class Point{
	private:
		double x, y;
	public:
		Point(int _x=0, int _y=0) {x = _y; y = _y;}
		Point operator+ (const Point &);
		double operator- (const Point &);
		Point operator/ (double);

    	friend ostream &operator<< (ostream &, const Point &); // overloaded output operator
    	friend istream &operator>> (istream &, Point &);       // overloaded input operator
	
};

// Task 1: Complete the definition of the overlaoded operator + (addition). 
//         This operator adds up each coordinate of two points. 
//         For example, if p1 = (1,2) and p2 = (5,7), then p1 + p2 = (6, 9)             (4 marks)

Point Point::operator+ (const Point &right)
{



}

// Task 2: Complete the definition of the overlaoded operator - (subtraction).  
//         This operator calculates the distance between two points.                     
//         For example, if p1 = (1,2) and p2 = (5,7), then p1 - p2 = 6.403              (4 marks)

double Point::operator- (const Point &right)
{




}

// Task 3: Complete the definition of the overlaoded operator / (division). 
//         This operator divides each coordinate with the right operand.
//         For example, if p = (1,2), then p / 2.0 = (0.5, 1.0)                          (4 marks)

Point Point::operator/ (double right)
{




}


int main()
{
	Point vertices[20];  // The list of verices of a polygon
	int nVertex;         // The number of points (vertices) entered by the user.
	Point center;        // The average or center point of the polygon.  
	
	cout << showpoint << fixed << setprecision(1);
	
	cout << "Enter the number of vertices of a polygon => ";
	cin >> nVertex;
	
	// Task 4: Using the overloaded input operator and a proper loop, read a list 
	//          of points from the keyboard.                                      (3 marks)
	
	

	// Task 5: Using another loop, calculate the center point by 
	//         taking the average of the vertices of the polygon.                 (3 marks)
	



	
	cout << endl;
	
	// Task 6: Using the overloaded output operator, print the center point.      (1 mark)   


	
	cout << endl;
	// Task 7: Using another loop, calculate the distance of each 
	//         vertex to the center point of the polygon.                         (5 marks)  
	cout << "Vertex \t Coordinates \t Distance to center" << endl;



   
   return 0;
}


// Definition of the overloaded output operator
istream &operator>> (istream &xin, Point &right)
{
    xin >> right.x >> right.y;
    return xin;
} 

// Definition of the overloaded input operator
ostream &operator<< (ostream &xout, const Point &right) 
{
     xout << "(" << right.x << "," << right.y << ")";
     return xout;
}

