#include<iostream>
using namespace std;

class sbt{
	float mark;
	
	public:
		sbt(float=0);
		
//		friend void read(sbt &s)
//		{
//			cout<<"Enter the mark: ";
//			cin>>s.mark;
//		}
		
//		friend void display(sbt s)
//		{
//			cout<<"Your mark: "<<s.mark<<endl;
//		}
		
		bool compare(sbt a)
		{
			if(mark == a.mark)
				return true;
			else
				return false;
		}
		
		friend istream& operator>>(istream &in, sbt &o)
		{
			cout<<"Enter the mark: ";
			in>>o.mark;
			
			return in;
		}
		
		friend ostream& operator<<(ostream &out, sbt &p)
		{
			out<<"Your mark: "<<p.mark<<endl;
			
			return out;
		}
		
		bool operator==(sbt s)
		{
			if(mark==s.mark)
				return true;
			else
				return false;
		}
		
		operator float()
		{
			return mark+2;
		}
		
};

sbt::sbt(float m)
{
	mark=m;
}

int main()
{
	sbt s1, s2(66);
	
	float m=s2;	//operator conversion
	cout<<m<<endl; //operator conversion
	
	cout<<"Enter the input for your object: "<<endl;
	cin>>s1;
	cout<<"The output for your object: "<<s1<<endl;
	
//	read(s1);	this is used in friend 
//	display(s1);

	//if(s1.compare(s2)) // this will be used in normall way, not operator overloading
	
	if(s1==s2) 	//s1.operator==(s2)
		cout<<"both objects have same marks"<<endl;
	else
		cout<<"both objects have different marks"<<endl;
	return 0;
	
}
