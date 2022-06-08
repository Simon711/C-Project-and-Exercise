#include <iostream>
#include <sstream>

using namespace std;

int convint(string a)	//input as string and return number to int main
{
	if (a=="zero") return 0;
	else if (a=="one") return 1;
	else if (a=="two") return 2;
	else if (a=="three") return 3;
	else if (a=="four") return 4;
	else if (a=="five") return 5;
}

string conv(int ans)	//input as int and return string to int main
{
	if (ans==0) return "zero";
	else if (ans==1) return "one";
	else if (ans==2) return "two";
	else if (ans==3) return "three";
	else if (ans==4) return "four";	
	else if (ans==5) return "five";
	else if (ans==6) return "six";
	else if (ans==7) return "seven";
	else if (ans==8) return "eight";
	else if (ans==9) return "nine";
	else if (ans==10) return "ten";
	else if (ans==0) return "zero";
	else if (ans==-1) return "negative one";
	else if (ans==-2) return "negative two";
	else if (ans==-3) return "negative three";
	else if (ans==-4) return "negative four";
	else if (ans==-5) return "negative five";	
}

int main()
{
	string engNum1,opr,engNum2;
	
	cout<<"What is: ";
	cin>>engNum1>>opr>>engNum2;
	
	int x,y;
	x=convint(engNum1);
	y=convint(engNum2);

	if (opr=="plus") {
		cout<<"Answer: "<<engNum1<<" "<<opr<<" "<<engNum2<<" is "<<conv(x+y);
	}
	if (opr=="minus"){
		cout<<"Answer: "<<engNum1<<" "<<opr<<" "<<engNum2<<" is "<<conv(x-y);
	}
 } 
