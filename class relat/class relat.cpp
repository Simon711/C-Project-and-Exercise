#include<iostream>
#include<fstream>
using namespace std;

//1d
class Course{
	string code;
	string name;
	
	public:
		Course(string code="", string name=""){	//declare as empty string otherwise compiler will call default construtor 
			this->code=code;
			this->name=name;
		}	
		
		string getCode()
		{
			return code;
		}
		
		string getName()
		{
			return name;
		}
};

//1b
class Name{
	string firstname;
	string lastname;
	
	public:
		Name(string firstname="", string lastname=""){	//declare as empty string otherwise will occur error when compiler will call default construtor 
			this->firstname=firstname;
			this->lastname=lastname;
	}
		friend ostream &operator<<(ostream &print, Name &n){ //overload print as the cout function, create an object pointer n to classs Name
			print<<n.firstname<<" "<<n.lastname;  //use the created object on line 37 to store firstname and lastname in it
			return print;	//return the overloading operator
		}
};

//1c
class Student{
	Name name; //create an object name to class Name for accessing the method/function in class Name
	Course course[3];	//create and set object course max to 3, requirement of question, this can make this object can access method/function in class Course
	int count;	//this counter is use to count the number of registered course
	
	public:
		Student(Name name, Course *c=NULL){	//assign to NULL because to prevent occur error when nothing pass to the second parameter 
			count=0;	//means no subject is registered at this moment
			this->name=name; //set the parameter name to member name in private class
			if (c!=NULL)	//check if the registered course is empty, if not, save the new course to course
			{
				course[count]=*c; //*c (address c which is from in main() will save to course[0] 
				count++;	//plus 1 of registered subject
			}
		}
		
		bool addCourse(Course *c)	//addcourse from int main()
		{
			if (count>=3)	//if registered course equal/more than 3 will terminate this bool function
				return false;
			for(int i=0; i<count; i++)
			{
				if(c->getCode()==course[i].getCode()) //compare the new data ( getCode() ) and the exist data ( course[i].getCode() ) in the course
					return false;					  //if same record will terminate this bool function
			}
			course[count]=*c;	//*c (address c which is from in main() will save to course[0] 	
			count++;	//plus 1 of registered subject
			return true;
		}
		
		string getRegisterCourses()
		{
			if (count==0)	//if there is no registered course
				return "None";
			else{
				string s="";	//set s to empty string
				for (int x=0; x<count; x++)	//set the running number, less than count (register course number)
				{
					s+=course[x].getName() + " ";	//use the created object in line 46 to get the name in class Course, and save to string s
				}
				return s;	//pass variable s to int main()
			}
		}
		
		friend ostream &operator<<(ostream &print, Student &stu){	//overload print as the cout function, create an object pointer stu to class Student
			print<<stu.name<<" registered courses: "<< stu.getRegisterCourses()<<endl;	//use the created object in line 88  to save name in it
			return print;
		}
};

int main()
{
	Course cou[5]={ {"0101", "Cryptography"},  //2a
					{"0234", "Programming"},
					{"1234", "Calculus"},
					{"2356", "History"},
					{"3658", "Geography"}	};

	Name nama("Simon","Chong");	//create a object nama to class Name
	Student s(nama, NULL);  //b		//this will call constructor with 2 arguments in class Student
	cout<<s; 			    //b		//display the object
	s.addCourse(&cou[0]);  //c		//add new course line 96 to object s, use & to access the address because cou in line 46 as a pointer that point to class Course
	s.addCourse(&cou[1]);  //C		//add new course line 97 to object s, use & to access the address because cou in line 46 as a pointer that point to class Course
	cout<<s;	//display object s
	if (s.addCourse(&cou[1])) //d		//refer to line 66, if this course has not been register, it will display Registration successful
		cout<<"Registration successful"<<endl;
	else
		cout<<"Registration failed"<<endl;	//if this course is registered, it will display Registration failed
	s.addCourse(&cou[4]);  //e		//add new course line 100 to the s
	cout<<s;
	return 0;
}
