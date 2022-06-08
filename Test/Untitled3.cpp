#include<iostream>
#include<string>
using namespace std;

class Flower
{
	int petals;
	public:
		Flower(int petals = 10)
		{
			this->petals = petals;
		}
	bool operator!=(Flower f) 
	{
		return petals!= f.petals? true: false;
	}

};


int main()
{
	Flower f1(13);
	Flower f2 = Flower(7);
	if (f2 != f1)
	{
		cout<< "Different";
	}
	else{
		cout<<"Same";
	}
	return 0;
}
