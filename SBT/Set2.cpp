#include<iostream>
using namespace std;

// Task 1: Complete the definition of class Box.

class Box{
	private:
		int width;
		int length;
		int height;
		
	public:
		Box()
		{
			width=0;
			length=0;
			height=0;
		}
		
		Box(int w, int l, int h)
		{
			width=w;
			length=l;
			height =h;
		}

		void setWidth(int w)
		{
			width=w;
		}
		
		void setLength(int l)
		{
			length=l;
		}
		
		void setHeight(int h)
		{
			height=h;
		}
		
		int getWidth()
		{
			return width;
		}
		
		int getLength()
		{
			return length;
		}
		
		int getHeight()
		{
			return height;
		}
		
		int getVolume()
		{
			return width*length*height;
		}

};

// Task 2: The following function is partialy given. The function is meant to print the dimension and volume of a box.
//          Complete the code of the function.

void printBox(Box b)
{
	cout <<"\nDimension = " <<b.getWidth()
		 <<"x"<<b.getLength()
		 <<"x"<<b.getHeight()<<endl;
		 
	cout << "Volume    = "<<b.getVolume() << endl << endl;
}

int main()
{
	int w,l,h,total;
	// Task 3: Create an array to hold 5 boxes and initliize the first two boxes with specified dimensions.
	Box a[5]={Box(10,10,10),Box(20,20,20)};
	
	// Task 4: Using a loop, set the dimensions the remaining boxes with data entered from the keyboard
	for (int i=2;i<5;i++)
	{
		cout<<"Enter box dimensions (w l h) => ";
		cin>>w>>l>>h;
		a[i].setWidth(w);
		a[i].setLength(l);
		a[i].setHeight(h);
	}
	// Task 5: Using an appropriate function and another loop, print all the boxes.
	for(int i=0; i<5; i++)
		printBox(a[i]);
	
	// Task 6: Calculate and print the total volume of all boxes.
	for(int i=0;i<5;i++)
	{
		total+=a[i].getVolume();
	}
		cout<<"\nTotal volume = "<<total;

	return 0;
}
