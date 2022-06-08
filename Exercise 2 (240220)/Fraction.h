//Class specification file
#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
	private:
		int num, denom;
		
	public:
		////Inline member functions
		//Mutators
		void setNum(int n) { 
			num = n; //Sets the value for numerator
		}
		
		void setDenom(int d) {
			denom = d; //Sets the value for denominator
		}

		//Accessors
		int getNum() const { 
			return num; //Returns the value of numerator
		}
		
		int getDenom() const { 
			return denom; //Returns the value of denominator
		}		
		
		//Regular functions
		void readFrac(); //Reads a fraction
		void dispFrac() const; //Displays a fraction
		Fraction multiply(Fraction) const; //Multiplies fractions
		Fraction divide(Fraction) const; //Divides fractions
		Fraction add(Fraction) const; //Adds fractions
		Fraction substract(Fraction) const; //Substracts fractions
};

#endif
