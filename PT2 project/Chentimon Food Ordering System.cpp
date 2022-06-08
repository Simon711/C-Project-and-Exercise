#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<fstream> 
#include<limits>
using namespace std;

		class Menu
	{
		protected:
			float price, subTotal;
			string item;
			int qty;
		public:
			Menu(){
				price=0;
				item="";
				qty=0;
				subTotal=0;
			} 
			
			Menu(string item, float price){
				this->price = price;
				this->item = item;
			}
			
			string getItem(){
				return item;
			}
			
			float getPrice(){
				return price;
			}
			
			float getsubTotal(){
				subTotal = price * qty;	//calculate total price for the same item
				return subTotal;
			}
			
			void setQty(int q){
				qty = q;
			}
			
			int getQty(){
				return qty;
			}
			
			virtual void display(){
				cout<< left <<setw(23) << item << setw(10) << price;	//display ordered item and price
			}		
	};
	
		class Food:public Menu
	{
		public:
			Food(){}
			Food(string n, float p): Menu(n, p){}
			
			void display(){
				Menu::display();
				cout<< endl;
			}
	};
	
	class Drink:public Menu
	{
		private:
			string type;
		public:
			Drink(){
			type = "";
			}
			Drink(string n, float p, string t): Menu(n, p){
				type = t;
			}
			
			void display(){
				Menu::display();
				cout<< "\t" << type << endl;
			}
	};
	
	class Order
	{
		private:
			Menu menu;
		public:
			Order(){}
			
			void addItem(Menu m){
				menu = m;			
			}
			
			void changeQty(int q){
				menu.setQty(q);
			}
			
			string getItem(){
				return menu.getItem();	
			}
			
			int getQTY(){
				menu.getQty();
			}
			
			float getPRICE(){
				menu.getPrice();
			}
			
			float getSUBTOTAL(){
				menu.getsubTotal();
			}	
	};
	
	class Contact
	{
		private:
			string phone;
			string address;
			string name;
		public:
			Contact(){ 
			name="";  
			address = ""; 
			phone = ""; 
			}
			
			void setInfo(string n,  string a, string p){
				name = n;
				address = a;
				phone = p;	
			}
			
			string getPhone(){
				return phone;
			}
			
			string getAddress(){
				return address;
			}
			
			string getName(){
				return name;
			}
			
			friend istream& operator>> (istream & i, Contact & a);		
	};
	
	class ReceiptHistory
	{
		private: 
			float price[100], subTotal[100]; string item[100]; int quantity[100];
			int ItemCounter = 0; float total=0;  int ReceiptNo = 10000;
			string name; string contact; string address;
			
		public:
			ReceiptHistory(){
				price[0] = 0;
				subTotal[0] = 0;
				quantity[0] = 0;
				item[0] = "";
				name = "";
				contact = "";
				address = "";
				ReceiptNo = 10000;
			}
			
			void SaveItem(float p, float s, string i, int q){
					this->price[ItemCounter] = p;
					this->subTotal[ItemCounter] = s;
					this->item[ItemCounter] = i;
					this->quantity[ItemCounter] = q;
					ItemCounter++;
			}
			
			void SaveCustomer(string n="", string c="", string a=""){
				this->name = n;
				this->contact = c;
				this->address = a;
			}
			
			void printHistory(){
				string line(28,'=');
				cout << endl << line << " Your Receipt " << line << endl
				     << "Receipt.No: " << ReceiptNo
					 << "\nCustomer's name: " << name
					 << "\nCustomer's contact: " << contact
					 << "\nCustomer's address: " << address;
				cout << left << setw(5) << "\n\nNo" << setw(23) << "  Item" << setw(17) << "  Unit Price" << setw(14) << "  Quantity" << "  Sub Total" << endl << endl;
				
				for(int i = 0; i<ItemCounter ; i++){
					cout << left << setw(5) << (i+1) << setw(23) << item[i] << setw(17) << price[i]
						 << setw(14) << quantity[i] << subTotal[i] << endl;
					total += subTotal[i];
					}
					
				string line3(70,'=');
				cout<< endl << line3 << endl;	
				cout<< right << setw(51) << "Total:" << setw(8) << "RM "<< total << endl
				    << line3 << "\n\n\n";
				total = 0;
			}
			
			void setReceipt(int r){
				ReceiptNo += r ;
			}
			
			int getReceipt(){
				return ReceiptNo;
			}		
	};
	
		class Customer
	{
		private:
			Order *order;
			Contact *c;
			ReceiptHistory *db;
		public:
			Customer(){ 
			order = NULL;
			c = NULL;
			db = NULL;
			}
			
			void addOrder(Order *o){	
				this->order = o;
			}
			
			void addBill(ReceiptHistory *rh){
				this->db = rh;
			}
			
			int getReceipt(){
				db->getReceipt();
			}
			
			void printBill(){
				db->printHistory();
			}
			
			void setContact(Contact *c1){
				this->c = c1;
			}
			
			string getPhone(){
				return c->getPhone();
			}
			
			string getName(){
				return c->getName();
			}
			
			string getAddress(){
				return c->getAddress();
			}
	};
	
istream& operator>> (istream& input, Contact &c) 
{
	string n,a,p;
	cout<<"========= Please Key-in you information =========\n" ;
	cout<<"\nEnter Your Name: "; getline(input,n);
	cout<<"Enter Your Address: "; getline(input,a);
	cout<<"Enter Your Contact: "; getline(input,p);
	c.setInfo(n,a,p);
	return input;
}
	
#define MAX_COUNT 100
Customer cust[MAX_COUNT];
Customer history[MAX_COUNT];
Contact c[MAX_COUNT];
Order order[MAX_COUNT];
ReceiptHistory db[MAX_COUNT];
Menu *m;
int count = 0, countTotal = 0, arrSize;

//item list , save all the food and drink in menu into default constructor 
Food f[] =      {Food("Nasi Goreng Kampung", 5),	//food consists of 2 arguments default constructor, name and price
	            Food("Nasi Goreng Cina", 5),
				Food("Nasi Goreng Pattaya", 6),
				Food("Chicken Chop", 8),
				Food("Steak", 10), 
				};
				
Drink d[] =     {Drink("Coca-cola", 2, "Cold"),	//drink consists of 3 arguments default contrustor, name, price and type (hot/cold)
				Drink("7-up", 2, "Cold"),
				Drink("Orange Juice", 3, "Cold"),
				Drink("Milk Tea", 4, "Cold"),
				Drink("Coffee", 4, "Hot"),
				Drink("Horlick", 5, "Hot")
				};
				
void header()
{
	string line(110, '=');	// display a LED like to attract customer xDDD
	cout<<endl<<line<<endl<<endl;
	cout<<"   *      *      *    * * * * *    *            * * * * *      * * * * *       **       **     * * * * *\n"          
		<<"   *     * *     *    *            *           *              *         *      * *     * *     *\n"                   
		<<"    *   *   *   *     * * * *      *          *               *         *      *  *   *  *     * * * *\n"                   
		<<"     * *     * *      *            *           *              *         *      *   * *   *     *\n"                   
		<<"      *       *       * * * * *    * * * * *    * * * * *      * * * * *       *    *    *     * * * * *\n\n"<<line<<endl<<endl; 
}		

void menu()
{
	 cout << "Choose one option from the menu below: \n" 
		  << "[1] Make an order\n"
		  << "[2] View Cart\n"
		  << "[3] Find Bill\n"
		  << "[4] Quit\n\n" 
		  << "Select option : ";
}

bool checkFood(int o)	//check if the input of food id is in the list
{
	arrSize = sizeof(f)/sizeof(f[0]);
	if(o<=arrSize && o>0)
		return true;
	else
		cout<< "-Please enter the option between 1 to 5-\n";
}

bool checkDrink(int o)	//check if the input of drink id is in the list
{
	arrSize = sizeof(d)/sizeof(d[0]);
	if(o<=arrSize && o>0)
		return true;
	else
		cout<< "-Please enter the option between 1 to 6-\n";
}

void addItem()
{		
	int option; char select; int qty; int choice; bool menuCheck; int temp;
	do
	{
		while(1){
		cout << "Pick one: \n"  //the second menu in "make an order"
		 	 << "1. Food \n"
		 	 << "2. Drink \n"
			 << endl;
		cout <<"Your choice: ", cin  >> choice;
		if(cin.fail() || choice != 1 && choice != 2)
			{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout<< "\n-Invalid option, please try again-\n\n";
			}
		if(choice == 1 || choice == 2) break;
		}
		
		switch(choice)
			{
				case 1:
					cout<<endl<<left << setw(5)<< "Id" <<setw(23) << "Name" << setw(10) << "Price";
					cout << endl;
			 		m = new Food(); //Polymorphism
			 		arrSize = sizeof(f)/sizeof(f[0]); //find the number of total food
			 		for (int i = 0; i < arrSize; i++) //to display the ID number of food
			 		{
					cout << setw(5)<<i+1;
					f[i].display(); //display the food name and price listv
					}	
						while(1){
						cout << "\nPick one food: ";
						cin >> option;
						if(cin.fail())
						{	
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "\n-Invalid input-\n";
						}
						if(checkFood(option)) break;
						}
					m = &f[option-1]; 	//if user enter 1, means 1-1=0, so the food in array zero will be selected ("Nasi Goreng Kampung")	
					break;
					
				case 2:
					cout<<endl<<left << setw(5)<< "Id" <<setw(23) << "Name" << setw(10) << "Price";
			 		cout << "\t" << "Type" <<endl;
			 		m = new Drink(); //Polymorphism
			 		arrSize = sizeof(d)/sizeof(d[0]);  //find the number of total drink
			 		for (int i = 0; i < arrSize; i++)  //to display the ID number of drink
			 		{
				 	 cout <<setw(5)<<i+1;
					 d[i].display(); 	//display the food name and price list
					}	
						while(1){
						cout << "\nPick one drink: ";
						cin >> option;
						if(cin.fail())
						{	
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "\n-Invalid input-\n";
						}
						if(checkDrink(option)) break;
						}
					m = &d[option-1];	 //if user enter 3, means 3-1=2, so the drink in array two will be selected ("Orange Juice")	
					break;
					
				default:
					cout << "\n-Invalid option, please try again-\n" <<endl; break;
		 	}
			
					while(1){
					cout<< "\nHow many quantity you want to order: ";
					cin >> qty; 			   //let cutomer to choose quantity for the selected items
					if(cin.fail() || qty <= 0)
						{	
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							cout<< "\n-Invalid input, you can only enter the quantity more than 0-\n";
						}
					if(qty > 0) break;
					}
				
			for (int i = 0; i<count ; i++){
			if (order[i].getItem() == m->getItem())		
				{
				menuCheck = true;	
				temp = i;
				}
			}
			if (menuCheck == true){
				qty += order[temp].getQTY();	//sum up the total quantity of an item
				order[temp].changeQty(qty);		//set the new quantity to the function					
				}
			else{
				m->setQty(qty);  //pass the quantity into function and store in object of menu
				order[count].addItem(*m);	//the new order item will be added in the new array in sequence	 	 		
				cust[count].addOrder(&order[count]);	//pass the new order into object of customer
				count ++;	//array +1
				}	
							
				cout << "\n============== DONE ORDER ==============" << endl;
				
					while(1){
					cout << "\nWould you like to continue order?" << endl;
					cout << "Y/N: ";
					cin >> select;
					cout << endl;
					if (!isalpha(select) && toupper(select) != 'N' || toupper(select) != 'Y')
						{	
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout<< "\n-Invalid input, you can only enter 'Y' or 'N'-\n";
						}
					if (isalpha(select) && toupper(select) == 'N' || toupper(select) == 'Y') break;
					}
					
	}while (toupper(select) != 'N');  	//convert any input from user to uppercase to ease user for using the program
	system ("CLS");  //clear the current screen contents
}

void printReceipt()
{
	string filename = cust[count].getName(); 
	db[countTotal].setReceipt(countTotal+1);
	filename = to_string(db[countTotal].getReceipt());
	filename += ".txt";
	ofstream show(filename);
	string line(26,'=');
	show<<endl<<line<<" Receipt "<<line<<endl;
	show<<"Receipt No: " <<db[countTotal].getReceipt() <<endl;
	show<<"\nCustomer's name: " << cust[count].getName();	//to print the customer name, phone number, and address that has been entered by user 
	show<<"\nCustomer's address: " << cust[count].getAddress();
	show<<"\nCustomer's contact: " << cust[count].getPhone();	
	float total = 0;
	show<<left<<setw(5)<<"\n\nNo"<< setw(23)<< "  Item"<<setw(17)<<"  Unit Price"<<setw(14)<<"  Quantity"<< "  Sub Total"<<endl<<endl;
		for (int i = 0 ; i < count ; i++)
			{
			show<<left<<setw(5)<<(i+1)<< setw(23) <<order[i].getItem()<<setw(17)<< order[i].getPRICE()	//display all order list of customer
			<<setw(14)<<order[i].getQTY()<< order[i].getSUBTOTAL()  << endl;
			total = order[i].getSUBTOTAL() + total;	//calculate all the prices of items
			}
			
	string line3(60,'=');
	show<<endl<<line3<<endl;	
	show<<right<<setw(45)<< "TOTAL:" <<setw(8)<< "RM "<< total <<endl;
	show<<line3<<endl<<endl;
	show<<"\n\nEstimate delivery time : 30 minutes after\nThank you !!!!!\n\n";
	show<<"Chentimon Restaurant,\nTaman University,\nSkudai 80990,\nJohor";
	show.close();
}

void modifyOrder()
{
	int option, select, temp_qty;
	system("CLS");
		
		while(1){
		cout<< "Your order lists: \n\n";
		cout<<left<<setw(3)<<"No"<< setw(21)<< "Item" <<setw(15)<<"Unit Price"<<setw(12)<<"Quantity"<< "Sub Total"<<endl<<endl;
		for (int i = 0; i<count; i++)
		{
			cout <<left<<setw(3)<<(i+1)<< setw(21) << order[i].getItem() << setw(15) << order[i].getPRICE()	
			     <<setw(12)<<order[i].getQTY()<< order[i].getSUBTOTAL() << endl;
		} 	
		    cout << "\nPlease choose an operation\n[1] Add \n"
				 << "[2] Substract\n"
				 << "[3] Remove\n"
				 << "[4] Quit\n"
				 << "\nYour Choice: ";
			cin>>select;
		if (cin.fail() || select < 1 || select > 4)
			{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("CLS");
			cout << "-Invalid input, You can only enter the option between 1 and 4-\n\n";
			}
		if (select > 0 && select < 5) break;
		}
	
	if (select == 1){
			while(1){	
			cout<< "\nWhich item do you want to modify? \n";
			cin >> option;
			if (cin.fail() || option > count || option < 1)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "-Invalid input, You can only enter the Number based on the cart-\n";
			}
			if (option <= count && option > 0) break;
			}
		
			while(1){
			cout << "How many do you want to add? \n";
			cin >> select;
			if (cin.fail() || select < 1)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "-Invalid input, Your quantity must be more than 0-\n";
			}
			if (select > 0) break;
			}
			
		temp_qty = select + order[option-1].getQTY();
		order[option-1].changeQty(temp_qty);
		system("CLS");
		cout << "Item added successfully.\n\n";
	}
	
	else if (select == 2){
			while(1){	
			cout<< "\nWhich item do you want to modify? \n";
			cin >> option;
			if (cin.fail() || option > count || option < 1)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "-Invalid input, You can only enter the Number based on the cart-\n";
			}
			if (option <= count && option > 0) break;
			}
		
			while(1){
			cout << "How many do you want to substract?\n";
			cin >> select;
			if (cin.fail() || select > order[option-1].getQTY() || select <= 0)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "-Invalid input, You cannot substract more than current quantity-\n\n";
			}
			if (select <= order[option-1].getQTY() && select > 0) break;
			}
		
		if (select < order[option-1].getQTY())
		{
	 		temp_qty = order[option-1].getQTY() - select;
			order[option-1].changeQty(temp_qty);
			system("CLS");
			cout << "Item substracted successfully.\n";
		}
		else if (select == order[option-1].getQTY())
		{
			int j = option - 1;
			for(j ; j<count; j++)
			{
				order[j] = order[j+1];
			}	
			count--;
			system("CLS");
			cout << "Item substracted to 0 quantity, item has been removed.\n" << endl;
		}
	}
	
	else if (select == 3){
			while(1){	
			cout<< "\nWhich item do you want to modify? \n";
			cin >> option;
			if (cin.fail() || option > count || option < 1)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "-Invalid input, You can only enter the Number based on the cart-\n";
			}
			if (option <= count && option > 0) break;
			}
			
		int j = option - 1;
		for(j ; j<count; j++)
		{
			order[j] = order[j+1];
		}	
		count--;
		system("CLS");
		cout << "Item removed successfully.\n" << endl;
	}
	
	else if (select == 4){
		cout << "";
		system("CLS");
	}
	
	else 
		cout << "-Invalid input, please try again-";
}

void remove()
{
	Order o_temp; Customer cust_temp; Contact c_temp;
	for(int i=0; i<count; i++){
		order[i] = o_temp;
		cust[i] = cust_temp;
		c[i] = c_temp;
	}
	while(count != 0 ){
		count--;
	}
}

void purchaseOrder()
{
	system ("CLS");
	cin.ignore();
	cin >> c[count];
	cust[count].setContact(&c[count]);	//pass the data to customer object and stored into array
	printReceipt();	//call the print receipt function
	for(int i = 0; i < count; i++)
	{	
		db[countTotal].SaveItem(order[i].getPRICE(),order[i].getSUBTOTAL(),order[i].getItem(),order[i].getQTY());
	}
	db[countTotal].SaveCustomer(c[count].getName(),c[count].getPhone(),c[count].getAddress());
	history[countTotal].addBill(&db[countTotal]);
	system("CLS");
	cout<< "Receipt printed successfully.\n";
	cout<< "Your Receipt No.: " << history[countTotal].getReceipt() << endl << endl;
	countTotal++;
	remove();	
}

void viewCart()
{
	float total; int option;
		
	if(count != 0)	//to check if the cart is empty, if so, display warning
		{
		cout<< "Your cart list: ----------------------------------------------\n\n";
		cout<<left<<setw(3)<<"No"<< setw(21)<< "Item"<<setw(15)<<"Unit Price"<<setw(12)<<"Quantity"<< "Sub Total"<<endl<<endl;
			for (int i = 0 ; i < count ; i++)
			{
				cout<<left<<setw(3)<<(i+1)<< setw(21) <<order[i].getItem()<<setw(15)<< order[i].getPRICE()	//display all the order list, quantity, subtotal, total
				<<setw(12)<<order[i].getQTY()<< order[i].getSUBTOTAL()  << endl;
				total += order[i].getSUBTOTAL();
			}
					
		string line1(68, '=');
		cout<<endl<<line1<<endl;
		cout<<right<<setw(55)<< "TOTAL:" <<setw(8)<< "RM "<<total<<endl;
		cout<<line1<<endl<<endl;
		string line2(20, '=');

		do{
			while(1){
			cout<< "\nCart Option \n"
			    << "[1] Edit order\n"
			    << "[2] Checkout\n"
			    << "[3] Back to menu\n" <<endl
			    << "Select option : ";
			cin >> option;
			if (cin.fail() || option < 1 || option > 3)
			{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("CLS");
			cout << "-Invalid input, Please enter the option between 1 and 3-\n";
			}
			if(option > 0 && option < 4) break;
			}
			
		switch(option)
		{
			case 1:
				modifyOrder();
				viewCart();
				break;
				
			case 2:
				purchaseOrder();
				break;
				
			case 3:
				system("CLS");
				header();
				break;
		}
		
	 }while(option != 3 && option != 2 && option != 1);

	}
	else 
	cout << "Your cart list is empty, please make order! \n" <<endl<<endl;	//if user try to display cart but no item in it		
}

bool findBill()
{
	int Receipt;  int temp; bool check = false;
		while(1){
		cout << "Please key-in your receipt number: ";
		cin >> Receipt;
		if (cin.fail()){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("CLS");
			cout << "-Invalid input, Please enter proper Receipt No-\n";
		}
		if(Receipt > 0 ) break;
		}
		
	for (int i = 0; i < countTotal; i++){
		if (history[i].getReceipt() == Receipt)
		{
			temp = i;
			check = true;
		}		    
	}
	
	if(check == true)
		history[temp].printBill();
	else
		cout<< "Bill not found!\n\n";		
}

int error(int c){
	if (c!=1 && c!=2 && c!=3 && c!=4)
		throw "-Invalid input, please insert 1 or 2 or 3 or 4-\n\n";	//throw the sentence if the condition is true
	return c;
}

int main()
{
	int choice;
	header();
	while(1)
	{
	try{
		menu();	
		cin >> choice; cout<< endl;
		error(choice);	//exception handling function (throw)
			switch (choice)
			{
				case 1: 	/* Add */
				addItem();
				header();	//print the LED like, "WELCOME" word
				break;
				
				case 2: 	/* View */
				viewCart(); 
				break;
				
				case 3:
				system("CLS");
				findBill();	//to search the bill with bill number
				break;
				
				case 4:
				cout << "Thank you ! :)  Have a good day!\n\n" << endl;
				return 0;
				 
				default:
				cout<< "-Wrong Selection, please input again-" <<endl<<endl;
			}	
		}
		catch (const char* msg) 	//catch the input error, if false, this will catch it
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//ignore the input other than integer/numeric
				system("CLS");
				cout<<"ERROR MESSAGE  ----->  "<< msg;
			}	
	}
	return 0;
}
