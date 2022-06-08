#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Lecturer{
	private:
		string name;
	public:
		string getName(){
			return name;
		}
		
		void setName(string n){
			name=n;
		}
};

class Course{
	protected:
		string cCode;
		string cName;
	public:
		string getName(){
			return cName;
		}
};

class LecturedCourse:public Course{
	private:
		Lecturer *lec;

	public:
		string getLecturer(){
			return lec->getName();
		}
		
		void setLecturer(Lecturer *l){  //subjects[counter].setLecturer(&LEC[counter]);
			lec=l;
		}
		
		void read(){
			cout<<"\nAdding a new subject course:"
			<<"\nCode => ";
			getline(cin, cCode);
			cout<<"Name => ";
			getline(cin, cName);	
		}
};

class NonLecturedCourse:public Course{
	private:
		int credit;

	public:
		int getMinCredit(){
			return credit;
		}
		
		void read(){
			cout<<"\nAdding a new project course:\n"
				<<"Code => ";
			getline(cin,cCode),
			cout<<"Name => ";
			getline(cin,cName);
			cout<<"Credit => ";
			cin>>credit;
			cout<<endl;
		}
};

int main(){
	int choice;
	LecturedCourse subjects[4];
	NonLecturedCourse projects[4];
	Lecturer LEC[4];
	string lName;
	int counter=0;
	int counter2=0;
	
	do{
		
	string line(8,'-');
	cout<<endl<<line<<"Menu"<<line<<endl
		<<"1. Add subject\n"
		<<"2. Add project\n"
		<<"3. Print subjects\n"
		<<"4. Print projects\n"
		<<"5. Exit\n\n"
		<<"Enter your choice => ";
	cin>>choice;
	cin.ignore();
	
	/////////////////////////////////////////////////// 1
		if(choice==1){
			subjects[counter].read(); 
			cout<<"Lecturer => ";
			getline(cin,lName);
			LEC[counter].setName(lName);
			subjects[counter].setLecturer(&LEC[counter]);
			counter++;
		}

	/////////////////////////////////////////////////// 2	
		if(choice==2){
			projects[counter2].read(); 
			counter2++;	
		}
	
	////////////////////////////////////////////////// 3
		if(choice==3){
			cout<<"\nThe list of subject courses: \n"
				<<left<<setw(27)<<"Course Name"<<"Lecturer\n\n";
				
			for (int x=0; x<counter; x++){
				cout<<setw(27)<<subjects[x].getName()
					<<subjects[x].getLecturer()<<endl;   }
		}
	
	
	////////////////////////////////////////////////// 4
		if(choice==4){
				cout<<"\nThe list of project courses: \n"
					<<left<<setw(45)<<"Course Name"<<"Min Credit Hour\n\n";
					
			for (int x=0; x<counter2; x++){
				cout<<setw(45)<<projects[x].getName()
					<<projects[x].getMinCredit()<<endl;	}
			}
			
	////////////////////////////////////////////////// 5	
		if(choice==5){
			cout<<"\nProgram ends!";
			return 0;
		}
	
		}while(choice!=5);
		
	return 0;
};
