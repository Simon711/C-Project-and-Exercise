#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int main() {
	
	int array1[5];	//declare array with a fixed data size
	int array2[5];	//declare array with a fixed data size
	int array3[10]; //this variable will save the elements in array1 and array2
	float totalArray3 = 0;
	float avgArray3;
	
	
	cout << "Enter table array1" << endl;
	for(int x=0; x <5; x++)	//there is 5 elements need to be saved
	{
		cout << "Please enter an integer : ";
		cin >> array1[x];	//x will be started at 0,1,2,3,4 (total 5), smaller than 5 or can be saved as x<=4
		array3[x] = array1[x];	//save every element from array1 into array3 as well
		totalArray3 += array3[x]; 	//sum up all the elements/numbers together to use in the next 
	}
	
	cout << "\n\nEnter table array2" << endl;
	for(int y=5; y <10; y++)
	{
		cout << "Please enter an integer : ";
		cin >> array2[y];	//this will be started at 5,6,7,8,9 (total 5), smaller than 10 or can be set as y<=9
		array3[y] = array2[y];	//save every element from array2 into array3 as well
		totalArray3 += array3[y];	//sum up all the elements/numbers together to use in the next
	}
	
	// display all the elements in array3
	cout << "\n\nTable array3 : \n";
	
	for(int z = 0; z < 10; z++) //0,1,2,3,4,5,6,7,8,9 (total 10 elements)
	{
		cout << array3[z] << " "; //display all elements starting from 1 to 10 with index starting from 0-9
		
	}
	
	//count and display average for array3
	avgArray3 = totalArray3/10;
	cout << "\nThe average of ten numbers in array3 = " << avgArray3;
	
	//find highest and lowest in array3 to find the range then display it
	
	int highest = array3[0]; //set the variable higehest from the first number
	
	for( int x = 1; x < 10; x++)	/*start 1,2,3,4,5,6,7,8,9,    10 get ignored here because the first number has been 
									save into variable highest, so only 9 elements left*/
	{
		if(highest < array3[x])		/*if the first number is lower than the second number, 
									second number will saved into highest variable, vise versa*/
			highest = array3[x];
	}
	
	
	int lowest = array3[0];		//set the variable lowest from the first number
	
	for( int x = 1; x < 10; x++)    /*start 1,2,3,4,5,6,7,8,9,    10 get ignored here because the first number has been 
									save into variable highest, so only 9 elements left*/
	{
		if(lowest > array3[x])			/*if the first number is higher than the second number, 
									first number will saved into highest variable, vise versa*/
			lowest = array3[x];
	}
	
	cout << "\nThe range of values in array3 = " << highest - lowest << endl;
	
	//find and count total odd number in array3
	
	int totalOdd = 0;
	
	for(int y = 0; y < 10; y++)  //0,1,2,3,4,5,6,7,8,9 (total 10)
	{
		if(array3[y]%2 == 1)		/*elements will be divided by 2 and the remaining will be taken, 
									if ramaining is 1 (odd), the totalOdd will + 1 until the elements finish*/
			totalOdd++;
	}
	
	cout << "The numbers of odd numbers in array3 = " << totalOdd;
	return 0;
}
