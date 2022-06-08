#include<iostream>
using namespace std;
 
class Product{
	
	int Code;
	double Price;
	
	public:
		Product(){
			Code=0;
			Price=0;
		}
		
		Product(int C, double P){
			Code=C;
			Price=P;
		}
		
		~Product(){
		}
		
		void setCode(int C){
			Code=C;
		}
		
		void setPrice(double P){
			Price=P;
		}
		
		double getCode(){
			return Code;
		}
		
		double getPrice(){
			return Price;
		}
};

int main(){
	int num, CODE;
	double PRICE;
	Product obj[100];
	cout<<"How many product to enter? ";
	cin>>num;
	
	for(int x=0; x<num; x++){
		cout<<"\nEnter the information of product #"<<x+1;
		cout<<"\nProduct code: ", cin>>CODE;
		cout<<"Price: ", cin>>PRICE;		
		obj[x].setCode(CODE);
		obj[x].setPrice(PRICE);
	}
	 
	double price=0;
	Product obj2(100, 1.00);
	obj[num] =obj2  ;
	
	cout<<"\nNo\t"<<"Product Code\t"<<"Price\n\n";	
	
	for (int x=0; x<num; x++)
	{
		cout<< (x+1) <<"\t"<< obj[x].getCode()
			<< "\t\t"<< obj[x].getPrice() <<endl;
		price += obj[x].getPrice();
	}
	
	cout<<"\nAverage Price: "<<price/num;
	return 0;
}
