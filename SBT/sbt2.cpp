#include <iostream>
using namespace std;

class Array
{
    private:
        int size; //pointer-based array size
        int *ptr; //pointer to first element of pointer-based array
    
    public:
        Array(int = 10); //default constructor
        ~Array(); //destructor
        int getSize() const; //return size of array
        bool operator== (const Array &) const; //overloaded equality operator
        const Array& operator= (const Array &); //overloaded assignment operator
        Array operator+ (const Array &); //overloaded addition operator
    
    //Overloaded stream operators    
    friend ostream &operator<< (ostream &, const Array &);
    friend istream &operator>> (istream &, Array &); 
};

//Task 1: Define the default constructor, to create an array with the default 
//        size of 10, and initialize each element of the array with 0
Array::Array(int arrSize) //5 marks
{
    size=arrSize;
}//End default constructor


//Start destructor
Array::~Array()
{
    delete [] ptr;
} //End destructor

//Start function to return number of elements of array
int Array::getSize() const
{
    return size;
} //End function


//Task 2: Define the overloaded equality operator, to determine if
//        two arrays are equal and return true, otherwise return false.
//        The arrays are considered equal if their corresponding elements are equal.
bool Array::operator== (const Array &right) const //7 marks
{
     
} //End function


//Task 3: Define overloaded assignment operator, with assumption that two arrays
//        have same size. Then, copy all values from right array into left array
const Array& Array::operator= (const Array &right) //3 marks
{
     
} //End function 


// Task 4: Define overloaded addition operator, return an object of class Array that 
//         summing up the elements of left array with the passed object (right array) elements. 
//         Make sure the value of elements in left array and right array are not changed. 
Array Array::operator+ (const Array &right) //4.5 marks
{
	
}
     
     
// Task 5: Define overloaded input operator, to input values for entire array
istream &operator>> (istream &input, Array &right) //3 marks
{
     
} //End function


// Task 6: Define overloaded output operator, to display two numbers per row of output
ostream &operator<< (ostream &output, const Array &right) //7.5 marks
{
     
} //End function
 
     
int main()
{
    Array Num1(4); //Four element array
    Array Num2(4); 
    
    //Display Num1 size and contents
    cout << "Size of array Num1: " << Num1.getSize() << endl
         << "After initialization, contents of array Num1: " << endl
         << Num1 << endl;
    
    //Display Num2 size and contents
    cout << "Size of array Num2: " << Num2.getSize() << endl
         << "After initialization, contents of array Num2: " << endl
         << Num2 << endl;

    //Input Num1 and Num2
    cout << "Enter 8 numbers: " << endl;
    cin >> Num1 >> Num2;
    cout << endl;
    
    //Display Num1 and Num2 after input entered
    cout << "After input, contents of array Num1: " << endl
         << Num1 << endl;
    cout << "After input, contents of array Num2: " << endl
         << Num2 << endl;
    
    //Use overloaded equality (==) operator
    cout << "\nEvaluating Num1 == Num2 >> ";
    if (Num1 == Num2)
      cout << "Num1 and Num2 are equal" << endl;      
    else
      cout << "Num1 and Num2 are not equal" << endl;
    
    //Use overloaded assignmet (=) operator
    cout << "\nAssigning Num2 to Num1 " << endl;
    Num1 = Num2;
    
    //Display Num1 and Num2 after assigning
    cout << "After assigning, contents of array Num1: " << endl
         << Num1 << endl;
    cout << "After assigning, contents of array Num2: " << endl
         << Num2 << endl;
    
    //Use overloaded equality (==) operator
    cout << "\nEvaluating Num1 == Num2 >> ";
    if (Num1 == Num2)
      cout << "Num1 and Num2 are equal" << endl;      
    else
      cout << "Num1 and Num2 are not equal" << endl;
    
    Array Num3(4); //New ten element array by default
    
    //Display Num3 contents
    cout << "\nCreate new object of class Array named Num3" << endl;
    cout << "After initializing, contents of array Num3: " << endl
         << Num3 << endl;
    
    //Use overloaded addition (+) operator
    Num3 = Num1 + Num2;
    
    //Display Num3 after assigning new values
    cout << "After assigning new values, contents of array Num3: " << endl
         << Num3 << endl;
    
    return 0;
}
    
     
