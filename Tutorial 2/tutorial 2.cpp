#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;
int main(){

	string name[100];
	int score[100], n=0;
	ifstream inp;
	inp.open("scores.txt");
	
	if(!inp){
		cout << "Cannot open file. Try again";
		exit(0); //or return 0 
	}	
	for(int i=0; inp>>name[i]; i++){
		inp>>score[i];
		n++;
	}
	inp.close();
	
	ofstream out;
	out.open("report.txt");

	for(int i=0; i<n; i++){
		 out << left
			 << setw(18) 
			 << name[i]
			 << score[i] << endl;
	}
	cout << "OUTPUT PRINTED TO REPORT.TXT";
}
