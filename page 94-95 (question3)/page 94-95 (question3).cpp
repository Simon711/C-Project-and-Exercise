#include<iostream>
#include<string>
using namespace std;

class Car{	///////////////// class car
	string plate;
	
	public:
		Car(string p);
		string getPlate();
};

class Contact{	/////////////// class contact
	string phone;
	
	public:
		Contact(string p);
		string getPhone();
};

Car::Car(string p="")
{
	plate=p; 
}

string Car::getPlate()
{
	return plate;
}


Contact::Contact(string p="")
{
	phone=p;
}

string Contact::getPhone()
{
	return phone;
}

class Customer{	//////////////////// class customer
	string name;
	Car *c; 	//aggregation
	Contact ct;	//composition
	
	public:
		Customer(string name, string phone);
		string getName();
		string getPhoneNumber();
		string getRentedCarPlate();
		void setRentedCar(Car *c);
};

Customer::Customer(string name="", string phone="") : ct(phone)
{
	this->name=name;
	c=NULL;
}

string Customer::getName()
{
	return name;
}

string Customer::getPhoneNumber()
{
	return ct.getPhone();
}

string Customer::getRentedCarPlate()
{
	if (c)
		return c->getPlate();
	else
		return "";
}

void Customer::setRentedCar(Car *c)
{
	this->c=c;
}

int main()
{
	Car Car("JSQ245");
	Customer pelanggan[]={Customer("Ahmad Kamal", "015-75769800"),
						  Customer("Siti Durdiana Abdullah", "014-889900")
						  };
						  
	pelanggan[0].setRentedCar(&Car);
	
	for (int i=0; i<2; i++)
	{
		cout<<"Customer's Name "<<pelanggan[i].getName()<<endl;
		cout<<"Phone Number "<<pelanggan[i].getPhoneNumber()<<endl;
		cout<<"Rented Car "<<pelanggan[i].getRentedCarPlate()<<endl<<endl;
	}
	
	return 0;
}
