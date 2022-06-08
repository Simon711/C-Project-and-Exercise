#include<iostream>
using namespace std;

class B{
	private:
		int m;
	protected:
		int n;
	public:
		void setM(int M){
			m=M;
		}
		
		int getM(){
			return m;
		}
		
		void setN(int N){
			n=N;
		}
		
		int getN(){
			return n;
		}
		
		int calc(){
			return m*n;
		}
};

class D: public B{
	private:
		double q;
	protected:
		double r;
	public:
		void setQ(double Q){
			q=Q;
		}
		
		double getQ(){
			return q;
		}
		
		void setR(double R){
			r=R;
		}
		
		double getR(){
			return r;
		}
		
		double calc(){
			B::calc();
			return q*r;
			
		}
};

int main(){
	B objB;
	D objD;
	
	objB.setM(9);
	objB.setN(100);
	objD.setM(5000);
	objD.setN(6000);
	
	cout<<objB.getM()<<endl;
	cout<<objB.getN()<<endl;
	cout<<objD.getM()<<endl;
	cout<<objD.getN()<<endl;
	
	objD.setQ(4);
	objD.setR(3);
	
	cout<<objD.getQ()<<endl;
	cout<<objD.getR()<<endl;
	
	cout<<objD.calc()<<endl;

}
