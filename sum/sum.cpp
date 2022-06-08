#include<iostream>
using namespace std;
int main(){
	
	int n,m,z,sum = 0;
	
	cin>>m;
	cin>>n;
	
	if (m<=n){
		//z= n-m;
		for (int x=m; x<=n; x++)
		{
			sum+=x;
		}
}
	if (m>=n){
		for (int y=m; y>=n; y--)
		{
			sum+=y;
		}
	}
	cout<<sum;

	return 0;
		
}
