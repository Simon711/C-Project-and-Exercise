#include<iostream>
using namespace std;

 class Course{
 	string name;
 	string course;
 	
 	public:
 		Course(string n, string c);
 		string getName();
 		string getCode();
 };
 
 class Student{
 	string name;
 	string matrix;
 	Course *subject;	//declare an object
 	
 	public:
 		Student(string n, string m);
 		void regCourse(Course *subject); //pass the object in line 17 as parameter into class Course
 		void display();
 };
 
 Course::Course(string n, string c)
 {
 	name=n;
 	course=c;
 }
 
 string Course::getName()
 {
 	return name;
 }
 
 string Course::getCode()
 {
 	return course;
 }
 
 Student::Student(string n, string m)
 {
 	name=n;
 	matrix=m;
 }
 
 void Student::regCourse(Course *c)
 {
 	subject=c;
 }
 
 void Student::display()
 {
 	cout<<name<<" ("<<matrix<<") registered " 
 		<<subject->getName()<<" ("
 		<<subject->getCode()<< ")" <<endl;
}
 		
int main(){
	Course *c=new Course("PT2", "SECV1023");
	Student s("Simon Chong", "A19EC3028");
	
	s.regCourse(c);
	s.display();
	return 0;
}
