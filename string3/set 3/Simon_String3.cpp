#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	string filename, name, IC;
	
	cout<<"Enter the input file: ";
	cin>>filename;
	ifstream read;
	read.open(filename);
	
	if(!read){
	cout<<"Error! Unable to open the input file."
		<<"No output file is created.";
	exit(0); //or return 0 
	}	

	while (getline(read, IC, '\t')) //while (getline(read, ic, '\t'))
	{
	getline(read,name);
	string a(IC,0,12); //IC
	
	string gender(IC,11,1);
	string gen;              
	if(stoi(gender)%2==0)
		gen="Female";
	else
		gen="Male";
	
	string year(a,0,2);	//first 2 digit in IC number
	int age;
	age=2014-(1900+stoi(year));
	
	ofstream out;
	a+=".txt";
	out.open(a.data()); //c_str()
	out<<name<<endl<<gen<<endl<<age<<" years old";
	out.close();
	}
	
	cout<<"\nThe information of each person has been written into the corresponding file."
		<<"\nPlease check you file";
}
