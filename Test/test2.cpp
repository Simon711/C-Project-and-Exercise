#include <iostream>
using namespace std;

class Product
{
    string name;
    float price;

    public:
        //Write a function prototype for the constructor with default value of name = "Oreo Biscuit" and price = 5.35 (2 marks)
       Product(string n="Oreo Biscuit",float p=5.35);

        ~Product(){
             cout<<"In destructor: "<<name<<"(RM"<<price<<")"<<endl;
        }
};

Product::Product(string n,float p){
     name=n;
     price=p;
     cout<<"In constructor: "<<name<<"(RM"<<price<<")"<<endl;
}

int main(){
     //Declare a Product pointer named p (1 mark)
	Product *p;

     //Based on the output given, create a Product object named p1 (2 marks)
     
	Product p1("Oreo Biscuit",5.35);

     //Based on the output given, dynamically allocate a Product object by using p pointer (2 marks)
     p=new Product("Ferrero Rocher",39.99);

     //Based on the output given, create a Product object named p2 (2 marks)
     
	Product p2("Ovaltine Biscuit",5.35);

     //Release memory pointed by p (1 mark)
	delete p;
     return 0;
}
