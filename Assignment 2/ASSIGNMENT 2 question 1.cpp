/* Simon Chong Kai Yuen - A19EC3028
   Clive Lai Yi Cheng - A19EC3019
   Section 4
   15/5/2020 */

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

class Contact{
	private:
		string phone;
		string email;
	public:
		Contact(){
			phone="";
			email="";
		}
		
		Contact(string Phone, string Email){
			phone=Phone;
			email=Email;
		}
		
		void setPhone(string _phone){
			phone=_phone;
		}
		
		void setEmail(string _email){
			email=_email;
		}
		
		string getPhone(){
			return phone;
		}
		
		string getEmail(){
			return email;
		}
};

class Project{
	protected:
		string title;
	public:
		Project(){
			title="";
		}
		
		Project(string Title){
			title=Title;
		}
		
		void setTitle(string _title){
			title=_title;
		}
		
		string getTitle(){
			return title;
		}
};

class Person{
	protected:
		string name;
		Contact con;	
	public:
		Person(){
			name="";
		};
		
		void setName(string _name){
			name=_name;
		}
		
		void setContact(string e, string p){
			con.setEmail(e);
			con.setPhone(p);
		}

		string getName(){
			return name;
		}
		
		string getPhone(){	//composition to Contact Class
			return con.getPhone();
		}
		
		string getEmail(){	//composition to Contact Class
			return con.getEmail();
		}
};

class Staff: public Person{
	protected:
		string position;
	public:
		Staff(){
			position="";
		}
		
		void setPosition(string post){
			position=post;
		}
		
		string getPosition(){
			return position;
		}
};

class Student: public Person{
	private:
		Project pro;
		Staff *staff;
	protected:
		string program;
		
	public:
		Student(){
			program="";
			staff=NULL;
		}

	void setProgram(string prog){
		program=prog;
	}
	
	void setProject(Project proj){
		pro=proj;
	}
	
	void setAdvisor(Staff* adv){	//aggregration to Staff class
		staff=adv;	
	}
	
	void removeAdvisor(){
		staff=NULL;
	}
	
	string getProjectTitle(){
		return pro.getTitle();
	}
	
	string getProgram(){
		return program;
	}
	
	string getAdvisorName(){
		if (staff != NULL)
			return staff->getName();
		else
			return "";
	}
	
	string getAdvisorPosition(){
		return staff->getPosition();
	}
};

int main(){
	Staff staff[4];
	Student student[4];
	
	ifstream input;
	input.open("inpAdvisor.txt");
	
	string NAME,PHONE,EMAIL,POSITION;
	int x=0;
	while (getline(input, NAME, ',')) 
	{
		getline(input,PHONE,',');
		getline(input,EMAIL,',');
		getline(input,POSITION);
	
		staff[x].setName(NAME);
		staff[x].setContact(EMAIL,PHONE);
		staff[x].setPosition(POSITION);
		x++;
	}
	
	input.close();
	
	input.open("inpStudent.txt");
	
	Project p;
	string NAME2, PHONE2, EMAIL2, COURSE2, PROJECT2;
	x=0;
	while (getline(input,NAME2,','))
	{
		getline(input,PHONE2,',');
		getline(input,EMAIL2,',');
		getline(input,COURSE2,',');
		getline(input,PROJECT2);
		
		student[x].setName(NAME2);
		student[x].setContact(EMAIL2, PHONE2);
		student[x].setProgram(COURSE2);
		p.setTitle(PROJECT2);
		student[x].setProject(p);
		x++;
	}
	
	cout<<left<<setw(5)<<"NO"<<setw(30)<<"NAME"<<setw(20)<<"PHONE"
		<<setw(30)<<"EMAIL"<<setw(30)<<"PROGRAM"
		<<setw(40)<<"PROJECT"<<setw(50)<<"ADVISOR"<<endl;
		
	for(int x=0; x<4; x++){
		student[x].setAdvisor(&staff[x]); //c
		cout<<setw(5)<<(x+1)<<setw(30)
			<<student[x].getName()<<setw(20)
			<<student[x].getPhone()<<setw(30)
			<<student[x].getEmail()<<setw(30)
			<<student[x].getProgram()<<setw(40)
			<<student[x].getProjectTitle()<<setw(50)
			<<student[x].getAdvisorName()<<endl;
	}
	
	input.close(); //////////////////////////////////////////////
	
	student[0].setAdvisor(&staff[1]);
	student[1].setAdvisor(&staff[0]);
	student[2].removeAdvisor();
	cout<<endl<<endl;
	
	cout<<left<<setw(5)<<"NO"<<setw(30)<<"NAME"<<setw(20)<<"PHONE"
		<<setw(30)<<"EMAIL"<<setw(30)<<"PROGRAM"
		<<setw(40)<<"PROJECT"<<setw(50)<<"ADVISOR"<<endl;
	
	for(int x=0; x<4; x++){
		cout<<setw(5)<<(x+1)<<setw(30)
			<<student[x].getName()<<setw(20)
			<<student[x].getPhone()<<setw(30)
			<<student[x].getEmail()<<setw(30)
			<<student[x].getProgram()<<setw(40)
			<<student[x].getProjectTitle()<<setw(50)
			<<student[x].getAdvisorName()<<endl;
	}
}

