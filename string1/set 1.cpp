#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

string convstr(string a)
{

	if(a=="01") return "January";
	else if (a=="02") return "February";
	else if (a=="03") return "March";
	else if (a=="04") return "April";	
	else if (a=="05") return "May";
	else if (a=="06") return "June";		 
	else if (a=="07") return "July";		 
	else if (a=="08") return "August";
	else if (a=="09") return "September";		 
	else if (a=="10") return "October";
	else if (a=="11") return "November";
	else return "December";	 		 	
}

int main()
{
	string dob;
	cout<<"Enter your date of birth => ";
	cin>>dob;
	
	if (dob.length()!=8)
	{
		cout<<"Error! The date must be 8 digits. Program ends here.";
		return 0;
	}
	
	for (int x=0; x<dob.length(); x++)
	{
		if (isdigit(dob[x])==false)
		{
			cout<<"Error! The ID contains non-digit characters. Program ends here. ";
			return 0;
		}
	}
	string year(dob,0,4);
	string month(dob,4,2);
	string day(dob,6,2);

	if(stoi(month)<1 || stoi(month)>12) {
		cout<<"Error! The month must be between 1 to 12. Program ends here.";
		return 0;
	}
	
	ofstream file;
	file.open(dob+".txt");
	file<<"You was born on "<<day<<" "<<convstr(month)<<" "<<year;
	file<<"\nNow, you are "<<2020-stoi(year)<<" years old";
	file.close();
	return 0;
}
