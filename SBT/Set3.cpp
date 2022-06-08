#include<iostream>
#include<cmath>
using namespace std;

class Particle
{
	float x,y,z,r;
	
	public:
		Particle()
		{
			x=0;
			y=0;
			z=0;
			r=0;
		}
		
		void read(float a,float b,float c,float d)
		{
			x=a;
			y=b;
			z=c;
			r=d;
		}
		
		void print()
		{
			cout<<x
				<<y
				<<z
				<<r;
		}
		
		Particle operator-(Particle a)
		{
			float d;
			Particle b;
			b.x= (a.x - this->x);
			b.y= (a.y - this->y);
			b.z= (a.z - this->z);
			d=sqrt((b.x*b.x) +(b.y*b.y) + (b.z*b.z));
			return b;
		}
		
		friend void collision();

};

		float collision(float r)
		{
			float d;
			if(d<=r)
				cout<<"The particles are colliding\n";
			else
				cout<<"No collision detected";
				return 0;
				
		}
		
int main()
{
	Particle p1,p2;
	float w,x,y,z;
	float ww,xx,yy,zz;
	cout<<"Enter data for the first particle"<<"\nCenter: ";
	cin>>w>>x>>y;
	cout<<"Radius: ", cin>>z, cout<<endl;;
	p1.read(w,x,y,z);
	
	cout<<"Enter data for the second particle"<<"\nCenter: ";
	cin>>ww>>xx>>yy;
	cout<<"Radius: ", cin>>zz,cout<<endl;
	p2.read(ww,xx,yy,zz);
	
	collision(z); 

	cout<<"\nFirst particle:\nCenter: "
		<<"("<<w<<","<<x<<","<<y<<")"
		<<"\nRadius: "<<z<<endl;
		
	cout<<"\nSecond particle:\nCenter: "
		<<"("<<ww<<","<<xx<<","<<yy<<")"
		<<"\nRadius: "<<zz<<endl;	
	return 0;
}
