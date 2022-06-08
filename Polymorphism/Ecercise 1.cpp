//Program 9.8
#include<iostream>
#include<cmath>
using namespace std;

#define PI 3.1415
// Task 1: Complete the definition of the parent class 
//'Object3D'. Allow two methods below to be polymorphic 
//(i.e, make those methods to be virtual methods)
//   + void print() const;
//   + double getVolume() const;

class Object3D {
public:
		Object3D(){}
		virtual void print() const {}
		virtual double getVolume()const {return 0;}
};

// Task 2: Complete the definition of the class 'Sphere'. 
// Redefine the following methods accordingly.
//   + void print() const; //to print the radius of the sphere
//   + double getVolume() const; //to calculate the volume of 
                                 // the sphere

class Sphere : public Object3D {
	protected:
		double r;
	public:
		Sphere(double _r=0){setRadius(_r);}
		void setRadius(double _r){ r = _r;}
		double getRadius()const {return r;}		
		void print() const {cout << "Sphere: r=" << r <<endl;}	
		double getVolume() const {return (4)*PI*(pow(r,3)/3); }
};

// Task 3: Complete the definition of the class 'Cylinder'. 
// Redefine the following methods accordingly.
//   + void print() const; //to print the radius and 
                           //height of the cylinder

//   + double getVolume() const; //to calculate the volume of 
                                 //the cylinder

class Cylinder : public Object3D {
	protected:
		double r,h;
	public:
		Cylinder(double _r=0, double _h=0){
		   setRadius(_r);
		   setHeight(_h);
		}
		   
		void setRadius(double _r){ r = _r; }
		void setHeight(double _h){ h = _h; }
		double getRadius()const {return r;}
		double getHeight()const {return h;}
		
		void print() const{
	   cout << "Cylinder: r=" << r << ", h=" << h << endl;
		}

	double getVolume() const { return PI*pow(r,2)*h ;}
};


// Task 4: Complete the definition of the class 'Cuboid'. 
// Redefine the following methods accordingly.
//   + void print() const; //to print the width, length, 
                           //and height of the cuboid
//   + double getVolume() const; //to calculate the volume of 
                                 //the cuboid

class Cuboid : public Object3D {
	protected:
		 double w,l,h;
	public:
		 Cuboid(double _w=0, double _l=0, double _h=0){
	    setWidth(_w);
	    setLength(_l);
	    setHeight(_h);
		 }
		
		 void setWidth(double _w){ w = _w;}
		 void setLength(double _l){ l = _l;}
		 void setHeight(double _h){ h = _h;}
		 double getWidth()const {return w;}
		 double getLength()const {return l;}
		 double getHeight()const {return h;}

		 void print() const{
		    cout << "Cuboid: dimension = " 
               << w << " x " << l << " x " << h << endl;
       }
		
	 double getVolume() const { return w*l*h ;}
};

int main( )
{
  // Task 5: Create an array of pointers of Object3D.
  Object3D *obj[5];    

  // Task 6: Fill in the array with different types of 
  // objects, for example cuboids, spheres and cylinders.
  // Put all the objects in the same array.
  Cuboid cu(10,20,30);
  Sphere sp(10),Sphere sp2(3); 
  Cylinder cy(20,20);
  
  Cylinder cy2(2,5);
  
  obj[0] = &cu;
  obj[1] = &cy;
  obj[2] = &sp;
  obj[3] = &cy2;
  obj[4] = &sp2;

  // Task 7: Print the information of all objects along with 
  // their volume
	
  for (int i=0; i<5; i++){
    cout << "Object #" << (i+1) << endl;
    // print object here
    obj[i]->print();
    cout << "Volume= " << obj[i]->getVolume() <<endl;
	cout << endl;
  }
    
  // Task 8: Calculate and print the total volume of the 
  // objects
	
  double totalVolume = 0;

  // do summation of volume using a loop here
  for (int i=0; i<5; i++){
  	totalVolume += obj[i]->getVolume();
  }	
  cout << "Total volume = " << totalVolume << endl;    
  return 0;
}


