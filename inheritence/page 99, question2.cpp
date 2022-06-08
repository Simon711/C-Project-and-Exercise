#include<iostream>
using namespace std;

class Rectangle{
	protected:
		double width;
		double length;
		double calculateArea(){
			return width*length;
		}
	public:
		Rectangle(double width, double length){
			this->width=width;
			this->length=length;
		}
		void display(){
			cout<<width<<endl;
			cout<<length<<endl;
		}
		
};

class Square:private Rectangle{
	private:
		double height;
	public:
		Square(double height, double width, double length): Rectangle(width, length){
			this->height=height;
			this->width=width;
			this->length=length;
		}
		
		double calculateVolume(){
			return calculateArea()*height;
		}
		
		void display(){
			Rectangle::display();
			cout<<height<<endl;
			cout<<calculateVolume();
		}
};

int main(){
	Square squareBox(15, 10, 10);
	squareBox.calculateVolume();
	squareBox.display();
	return 0;
}
