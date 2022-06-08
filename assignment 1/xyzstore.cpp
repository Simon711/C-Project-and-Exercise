#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

#define MAX_STORE_NAME	10
#define MAX_MONTH		12

/* StoreData
   ---------
   a) This class store the 'name' of a store and 'sales' data (for 12 months) of a store.
   b) There is a member called 'id' which is set based on an internal counter '_counter'.
   c) get*** functions are accessors while set*** functions are mutators.
   d) The class overloads operator<< to enable easy display of its internal data (via cout)
      such as 'id', 'name', and 'sales'. */

class StoreData {
	static int	_counter;						/* internal counter */
	int			id;								/* store id, value is derived from _counter */
	char		name[MAX_STORE_NAME];			/* store name */
	float		sales[MAX_MONTH];				/* sales data for every month */

public:
	StoreData();
	StoreData(const char name[], float sales[]);

	int		getId() const;
	char*	getName() const;
	float*	getSales() const;

	void setCounter(int c);
	void setName(char name[]);							
	void setSales(float sales[]);

	friend ostream& operator<<(ostream& os, const StoreData& dt);	/* display all data */
};

/* StoreManager
   ------------
	a) This class store manages a dynamically allocated array of 'storedata'.
	b) 'store_data_count' keeps track of the number of StoreData pointed by 'storedata'.
	c) 'addStore' adds StoreData s into the array 'storedata'.
	d) 'deleteStore' deleted StoreData pointed by 'storedata' which matched the given 'id'.
	e) 'modifyStore' will update 'name' and 'sales' of StoreData pointed by 'storedata' 
	    which matched the given 'id' with StoreData in 's'.
	f) 'putStoreData' will update 'storedata' and 'store_data_count' with 's' and 'count'.
	g) 'printStore' will print out data from each of the StoreData in 'storedata' using operator<<.
	h) 'getStoreData' is an accessor for 'storedata'.
	i) 'getStoreDataLength' is an accessor for 'store_data_count'. */
	
class StoreManager {
	unsigned long store_data_count;
	StoreData*	storedata;

public:
	StoreManager() : store_data_count(0), storedata(0) {};
	~StoreManager();

	void addStore(StoreData s);
	void deleteStore(int id);
	void modifyStore(int id, StoreData s);
	void putStoreData(StoreData* s, unsigned int count);

	void printStore() const;
	StoreData* getStoreData() const;
	unsigned long getStoreDataLength() const;
};

// -------------------------------------------------------------------------------------------------------------------
// Implementations for class Store Data  -----------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

int StoreData::_counter = 0;	/* Initialize internal counter _counter to 0 */

//
// Task 1: Write a default constructor for StoreData that sets/ initializes id, name, and sales to 0 (5M)
//










StoreData::StoreData(const char name[], float sales[])
{
	_counter++;			/* increment internal counter */
	id = _counter;		/* set id to current value of  _counter */

	/* Initialize name from the 1st parameter of the constructor */
	if (strlen(name) >= MAX_STORE_NAME)
	{
		/* Only copy the first (MAX_STORE_NAME - 1) characters if name if too large to fit  */
		for (int i = 0; i < MAX_STORE_NAME - 1; i++)
			this->name[i] = name[i];
		this->name[MAX_STORE_NAME] = 0;
	}
	else
	{
		#pragma warning(suppress : 4996)  //ignore/ comment this line if you are not using visual studio
		strcpy(this->name, name);
	}

	/* Initialize sales data from the 2nd parameter of the constructor */
	for (int i = 0; i < MAX_MONTH; i++)
	{
		this->sales[i] = sales[i];
	}
}

//
// Task 2: Write an accessor function for StoreData's id 
//





//
// Task 3: Write an accessor function for StoreData's name 
//






//
// Task 4: Write an accessor function for StoreData's sales 
//






//
// Task 5: Write a mutator function for StoreData's _counter
//






//
// Task 6: Write a mutator function for StoreData's name 
//









//
// Task 7: Write a mutator function for StoreData's sales 
//








//
// Task 8: Overload operator<< to provide access to the value of id, name, and sales of StoreData 
//























// -------------------------------------------------------------------------------------------------------------------
// Implementations for class StoreManager  ---------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------


//
// Task 9: Write a destructor for StoreManager that will deallocate any allocated memory for storedata, if any 
//









void StoreManager::addStore(StoreData s)			
{
	if (storedata != 0)				//if space has already been allocated
	{
		StoreData* temp;
		
		//
		//Task 10(a): Allocate memory to temp to contain current + new StoreData 
		//



		//
		//Task 10(b): Copy existing StoreData to newly allocated space 
		//

		
		
		
		

		//
		//Task 10(c): Copy new StoreData s to end of newly allocated space 
		//


		//
		//Task 10(d): Update store_data_count to mark current size of storedata 
		//


		/* Free previous allocated space in storedata */
		delete[] storedata;

		/* Update storedat to point to newly allocated space */
		storedata = temp;
	}
	else							//No space allocated yet, this is the first item
	{
		//
		//Task 10(e): Allocate memory for StoreData array of 1 element  
		//
		
		
		storedata[0] = s;
		store_data_count++;
	}
}

void StoreManager::deleteStore(int id)
{
	StoreData* temp;
	int i, j;

	if (store_data_count > 0) {
		temp = new StoreData[store_data_count];

		j = 0;
		for (i = 0; i < store_data_count; i++)
		{
			/* If current storedata id does not match 'id' */
			if (storedata[i].getId() != id)
			{
				/* Copy storedata to newly allocated space */
				temp[j] = storedata[i];

				/* Update j */
				j++;
			}
		}

		if (i == j) //If 'id' not in the list
		{
			cout << "Error !!! Id " << id << " not found !" << endl;

			/* Delete newly allocated space */
			delete[] temp;
		}
		else
		{
			/* Free previously allocated space */
			delete[] storedata;

			/* Update store_data_count */
			store_data_count--;

			/* Update storedata to point to newly allocated space */
			storedata = temp;
		}
	}
	else
	{
		cout << "Error ! no store data to delete !" << endl;
	}
}

void StoreManager::modifyStore(int id, StoreData s)			
{
	//
	// Task 11: Search for StoreData in storedata with id matching the
	//	one given in the first parameter (id), and set it's name and sales
	//  to the one in second parameter. Exit the function once done. 
	//
	
	
	
	
	
	
	
	
	
	
	
	

	/* display error message */
	cout << "Error !!! Id of store not found !"<<endl;
}

void StoreManager::printStore() const			
{
	//
	// Task 12(a): Print " No data to print ! " message if there is no StoreData added, and exit the function. 
	//

	
	
	
	


	cout << endl << "Sales data (id, name, sales) :" << endl;
	
	//
	// Task 12(b): Print all StoreData in storedata 
	//

	
	
	
	
	
	cout << endl;
}

//
// Task 13: Write an accessor function for StoreManager's storedata 
//






unsigned long StoreManager::getStoreDataLength() const		//Returns the size of data pointed by storedata in bytes
{
	return (store_data_count * sizeof(StoreData));
}

//Update members with data given by parameters (for storedata, and store_data_count)
void StoreManager::putStoreData(StoreData* s, unsigned int count)	
{
	/* Free memory currently used by storedata, if any  */
	if (storedata != 0)
		delete[] storedata;

	/* Update storedata and store_data_count with values from the parameters of this function */
	storedata = s;
	store_data_count = count;

	/* Update counter so that _counter is one larger that the final id in 'storedata' */
	storedata->setCounter(s[count - 1].getId());
}

void menu()
{
	cout << endl
		<< "Welcome to XYZ Pvt Ltd -=<[XYZ]>=- " << endl
		<< "[1] Add new sales data" << endl
		<< "[2] Modify sales data" << endl
		<< "[3] Delete sales data" << endl
		<< "[4] Displays sales data" << endl
		<< "-" << endl
		<< "[5] Write sales data to file" << endl
		<< "[6] Load sales data from file" << endl
		<< "-" << endl
		<< "[0] Exit" << endl
		<< " Select task : ";
}

void add(StoreManager& s)
{
	string name;
	float sales[MAX_MONTH];

	cout << "Enter store name: ";
	getline(cin, name);

	cout << "Enter sales data : ";
	for (int i = 0; i < MAX_MONTH; i++)
		cin >> sales[i];

	StoreData temp(name.c_str(), sales);
	s.addStore(temp);
}

void modify(StoreManager& s)
{
	int id;
	string name;
	float sales[MAX_MONTH];

	cout << "Enter id of store to modify : ";
	cin >> id;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter new store name : ";
	getline(cin, name);

	cout << "Enter new sales data : ";
	for (int i = 0; i < MAX_MONTH; i++)
		cin >> sales[i];

	StoreData temp(name.c_str(), sales);
	s.modifyStore(id, temp);
}

void remove(StoreManager& s)
{
	int id;

	cout << "Enter id of store to Delete : ";
	cin >> id;

	s.deleteStore(id);
}

void prints(StoreManager& s)
{
	s.printStore();
}

void write(StoreManager& s)			
{
	string filename;				/* store name of file to be written to */

	cout << "[SAVE] Enter filename : ";
	getline(cin, filename);

	//
	//Task 14(a): Open filename for output in binary mode 
	//

	
	//
	//Task 14(b): Write all StoreData in s to the file 
	//

	
	//
	//Task 14(c): Close the opened file 
	//

}

void load(StoreManager& s)			
{
	string filename;				/* Store name of file to be loaded */
	unsigned long file_length;		/* Store length of file in bytes */
	unsigned int count;				/* Store the number of StoreData records in filename */
	StoreData* temp;				/* Store address of newly allocated memory */

	cout << "[LOAD] Enter filename : ";
	getline(cin, filename);

	//
	//Task 15(a): Open filename for input in binary mode 
	//

	
	//
	//Task 15(b): Display an error message and exit function if unable to open file 
	//

	
	
	
	

	//
	//Task 15(c): Get size of file into file_length 
	//

	
	
	//
	//Task 15(d): Calculate the number of StoreData object is in the file
	//

	
	//
	//Task 15(e): Allocate memory to contain all StoreData object  
	//

	
	//
	//Task 15(f): Read all data from the file into the newly allocated memory 
	//

	
	
	//
	//Task 15(g): Close the opened file 
	//

	
	
	s.putStoreData(temp, count);
}

int main()
{
	int choice;
	StoreManager stores;

	do {
		menu();
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (choice)
		{
		case 1: 	/* Add */
			add(stores);
			break;
		case 2: 	/* Modify */
			modify(stores);
			break;
		case 3: 	/* Delete */
			remove(stores);
			break;
		case 4: 	/* Print */
			prints(stores);
			break;
		case 5: 	/* Write */
			write(stores);
			break;
		case 6: 	/* Load */
			load(stores);
			break;
		default:
			cout << "Unknown option !" << endl;
		}
	} while (choice != 0);

	cout << "Thank you ! :)" << endl;

	return 0;
}
