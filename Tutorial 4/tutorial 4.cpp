#include<iostream>
using namespace std;
int main()
{
	float total=0;
	int n;
	int sub[n];
	float avg;
	
	cout<<"Please enter number of subjects taken: ";
	cin>> n;
	
	for (int x=1; x<=n; x++)
	{
		cout <<"Subject "<< x <<" : ";
		cin >> sub[x];
		total += sub[x];
	}
	
	avg = total/n;
	cout<<"Total of Marks: "<<total;
	cout<<"\nAverage of Marks: "<<avg;
	
	return 0;
}
