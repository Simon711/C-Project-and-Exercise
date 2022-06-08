#include<iostream>
using namespace std;

int main(){
	string str="UTM Sanjungan Bangsa";

//Display the word of (Sanjung) in str (2 marks)
cout<<
str.substr(4,7)
<<endl;

//Change the word of (Bangsa) in str with (Malaysia) (3 marks)
str.replace(14,6,"Malaysia");

cout<<str<<endl;

//Display the number of characters in str (1 mark)
cout<<
str.length()
<<endl;

//Remove the second word and second whitespace in str (2 marks)
str.erase(4,10);

cout<<str<<endl;

//Add the word of (Johor) with whitespace before the word of (Malaysia) in str (2 marks)
str.insert(4,"Johor ");

cout<<str<<endl;
	
}
