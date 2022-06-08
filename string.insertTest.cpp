#include<iostream>
using namespace std;

int main(){
	string num;
	
	cout<<"Enter your handphone no. -> ";
	cin>>num;
	
	num.insert(0,"+");
	num.insert(4,"-");
	num.insert(9,"-");
	
	cout<<num;
	return 0;
}
