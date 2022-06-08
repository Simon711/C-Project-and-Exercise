#include<iostream>
#include<string>
using namespace std;

class Painting
{
		string artist;
		int yearPainted;
		double auctionPrice;
		
	public:
		Painting(string a, int year)
		{
			artist=a;
			yearPainted=year;
			auctionPrice=1000;
		}
		
		void setA(string a)
		{
			artist=a;
		}
		
		void setY(int y)
		{
			yearPainted=y;
		}
		
		void setaP(double aP)
		{
			auctionPrice=aP;
		}
		
		string getA()
		{
			return artist;
		}
		
		int getY()
		{
			return yearPainted;
		}
		
		double getaP()
		{
			return auctionPrice;
		}
		
		void auction()
		{
			auctionPrice = auctionPrice + 500;
		}
		
		void displayPrice()
		{
			cout<<auctionPrice;
		}
};

int main()
{
	Painting obj("simon", 2020);
	
	for(int x=0; x<=4; x++)
	{
		obj.auction();
	}
	obj.displayPrice();	
}


