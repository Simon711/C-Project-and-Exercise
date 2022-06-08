//Simon Chong Kai Yuen	A09EC3028
//Clive Lai Yi Cheng	A09EC3019

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class AcademicAdvisor{
private:
	string name;
public:
	AcademicAdvisor(){this->name="";}
	string getName(){return this->name;}
	void setName(string name){this->name=name;}
};

class ProjectAdvisor{
private:
	string name;
public:
	ProjectAdvisor(){this->name="";}
	string getName(){return this->name;}
	void setName(string name){this->name=name;}
};

class Program{
private:
	string course;
public:
	Program(){this->course="";}
	string getCourse(){return this->course;}
	void setCourse(string course){this->course=course;}
};

class Student{
protected:
	string name;
	Program program;
	AcademicAdvisor* academicAdvisor;
public:
	Student():program(){this->name="";}
	string getName(){return this->name;}
	void setName(string name){this->name=name;}
	string getProgram(){return this->program.getCourse();}
	void setProgram(string program){this->program.setCourse(program);}
	AcademicAdvisor getAA(){return *academicAdvisor;}
	void setAA(AcademicAdvisor* academicAdvisor){this->academicAdvisor=academicAdvisor;}
};

class UndergraduateStudent: public Student{
private:
	float cgpa;
public:
	UndergraduateStudent(){this->cgpa=0.0;}
	float getCgpa(){return this->cgpa;}
	void setCgpa(float cgpa){this->cgpa=cgpa;}
};

class PostgraduateStudent: public Student{
private:
	string project;
	ProjectAdvisor* projectAdvisor;
public:
	PostgraduateStudent(){this->project="";projectAdvisor=NULL;}
	string getProject(){return this->project;}
	void setProject(string project){this->project=project;}
	ProjectAdvisor getPA(){return *projectAdvisor;}
	void setPA(ProjectAdvisor* projectAdvisor){this->projectAdvisor=projectAdvisor;}
};

int main(){
	UndergraduateStudent* ugstudent;
	PostgraduateStudent* pgstudent;
	AcademicAdvisor* aa_ug;
	AcademicAdvisor* aa_pg;
	ProjectAdvisor* pa;
	string line;
	int size_ug, size_pg, size_check, student_count, element_count;

	size_ug = 0, size_check = 0, student_count = -1, element_count = 0;
	ifstream input("ugstudents.txt");
	if(input){
		while(getline(input, line)){
			if(size_check == 0){
				size_ug = stoi(line);
				ugstudent = new UndergraduateStudent[stoi(line)];
				aa_ug = new AcademicAdvisor[stoi(line)];
				size_check = 1;
			}else if(line == " "){
				element_count = 1;
				student_count++;
			}else{
				switch(element_count){
					case 1:
					ugstudent[student_count].setName(line); 
					element_count++; break;
					case 2:
					ugstudent[student_count].setProgram(line); 
					element_count++; break;
					case 3:
					aa_ug[student_count].setName(line); 
					ugstudent[student_count].setAA(&aa_ug[student_count]);  
					element_count++; break;
					case 4:
					ugstudent[student_count].setCgpa(stof(line));
					element_count++; break;
					default: break;
				}
			}
		}
	}
	input.close();

	size_pg = 0, size_check = 0, student_count = -1, element_count = 0;
	ifstream input2("pgstudents.txt");
	if(input2){
		while(getline(input2, line)){
			if(size_check == 0){
				size_pg = stoi(line);
				pgstudent = new PostgraduateStudent[stoi(line)];
				aa_pg = new AcademicAdvisor[stoi(line)];
				pa = new ProjectAdvisor[stoi(line)];
				size_check = 1;
			}
			else if(line == " "){
				element_count = 1;
				student_count++;
			}else{
				switch(element_count){
					case 1:
					pgstudent[student_count].setName(line);
					element_count++; break;
					case 2:
					pgstudent[student_count].setProgram(line);
					element_count++; break;
					case 3:
					aa_pg[student_count].setName(line);
					pgstudent[student_count].setAA(&aa_pg[student_count]);
					element_count++; break;
					case 4:
					pa[student_count].setName(line);
					pgstudent[student_count].setPA(&pa[student_count]);
					element_count++; break;
					case 5:
					pgstudent[student_count].setProject(line);
					element_count++; break;
					default: break;
				}
			}
		}
	}
	input2.close();

	ofstream output;
	output.open("output.txt");
	output << "THE LIST OF UNDERGRAUATE STUDENTS" << endl;
	output << 
	left << setw(3) << "No" << 
	setw(30) << " Name" << 
	setw(30) << "Program" << 
	setw(30) << "Advisor" << 
	setw(10) << "CGPA" << endl;
	for(int i=0; i<size_ug; i++){
		output << 
		right << setw(3) << i+1 << 
		left << setw(30) << " " + ugstudent[i].getName() << 
		setw(30) << ugstudent[i].getProgram() << 
		setw(30) << ugstudent[i].getAA().getName() <<
		setw(10) << ugstudent[i].getCgpa() << endl;
	}
	output << endl << endl;
	output << "THE LIST OF POSTGRADUATE STUDENTS" << endl;
	output << 
	left << setw(3) << "No" << 
	setw(30) << " Name" << 
	setw(30) << "Supervisor" << 
	setw(30) << "Project" << endl;
	for(int i=0; i<size_ug; i++){
		output << 
		right << setw(3) << i+1 << 
		left << setw(30) << " " + pgstudent[i].getName() << 
		setw(30) << pgstudent[i].getPA().getName() << 
		setw(30) << pgstudent[i].getProject() << endl;
	}
	return 0;
}
