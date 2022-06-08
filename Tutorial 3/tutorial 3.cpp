#include<iostream>
#include <cmath>
using namespace std;

	void getProblem(){
		cout<<"Enter the number of the problem you wish to solve.\n\n";
		cout<<"        GIVEN A MEDICAL ORDER IN 				CALCULATE RATE IN\n";
		cout<<"(1) ml/hr & tubing drop factor 					     drops/min\n";
		cout<<"(2) mg/kg/hr & concentration in mg/ml 		                      ml/hr\n";
		cout<<"(3) QUIT\n\n";	
    }
    
    int getRateDropFactor(){ //first choise
    	float a,b,r;
    	float value;
    	cout<<"Enter rate in ml/hr => ";
    	cin>>a;
    	cout<<"Enter tubing's drop factor(drops/ml) => ";
    	cin>>b;
    	value=(a/60)*b;
    	r=round(value);
    	cout<<r;
	 	return value;
	}
 
 	int getKgRateConc(){  //second choise
 		float a,b,c;
 		float rate,r;
 		cout<<"Enter rate in mg/hr => ";
 		cin>>a;
 		cout<<"\nEnter patient weight in kg => ";
 		cin>>b;
 		cout<<"\nEnter concentration in mg/ml => ";
 		cin>>c;
 		rate=a*b*c;
 		r=round(rate);
 		cout<<r;
 		return rate;
	 }
	 
	 int figDropsMin(){  
	 	int a,b,value;
		 value=a/60*b;
	 	return value;
	 }
	 
	 int byWeight(){
	 	
	 }
    
int main()
{
   int choise;
   getProblem(); 
   cout<<"Problem => ";
   cin>>choise;
   

   if(choise==1){
   	getRateDropFactor();
   }
   
   else if (choise==2){
   	getKgRateConc();
	}
	   
   else if (choise==3){
   	cout<<"You have chosen to quit the program.\nThank you for using our system.";
	return 0;
   }

	else{
		cout<<"Please run the system again and choose a problem number between 1 and 3.\n\n\n";
	}

}

