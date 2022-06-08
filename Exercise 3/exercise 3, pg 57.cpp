// page 57, pt2, exercise 3

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string students[]={"Muhamas Husin, A123456",
						"Nor Asma, A156782",
						"Raja Kumar, A187623",
						"Muhamas Ali, A123908",
						"Ali Shah, A145234",
						"Nor Nadia, A128734",
						"Siti Sarah, A154237",
						"Syed Azamn, A2766456",
						"Chong Wei, A156278"};

string line(30,'-'), name;
cout<<"Searching Student's info "<<endl
	<<line<<endl
	<<"Enter the name or partial name, "<<endl
	<<"You would like to search for: ";
getline(cin,name);

int arrSize= sizeof(students)/sizeof(students[0]);
cout<<arrSize<<endl<<sizeof(students)<<endl<<sizeof(students[0])<<endl<<students[8].size(); //testing use

cout<<"Search Result: "<<endl;

for (int i=0; i<arrSize; i++)
{
	if (students[i].find(name) < students[i].size())
	cout<<students[i]<<endl;
}

return 0;
}
