//Allina Khan
//Homework #2 Mini Database
//Inputs for update, addPhone, print, and display functions.
#include <iostream>
#include <cstdlib>

using namespace std;

//function prototypes
int findID(string[], string , int );
void addPhone(string[], double[], int[], int &);
void update(string *,double *,int *, int , string);
void print(string *,double *,int *,int);
void display(string *,double *,int *,int,string);

/*Function display
Input:
    arrays ID, price, and quantity. Int Size holds Size of arrays. String prdct is a given product ID
Process:
    finds index of given product ID, stores it in initiated variable exist. If exist is not = to -1,
    displays product price and quantity.
Output: None
*/

void display(string *ID, double *pri, int *qua, int Size, string prdct) {
    int exist;
    exist=findID(ID,prdct, Size);

    if (exist==-1)
        cout << "Function display failed. Item " << prdct<<" does not exist." <<endl<<endl;
    else {
        cout << "Product: " << *(ID+exist) << endl << "Price: "<< *(pri+exist)
             << endl<<"Quantity: "<<*(qua+exist) <<endl<<endl;
    }
return;
}

/*Function print database
Input:
    array ID, price, and quantity and int Size for the Size of these arrays.
Process:
    for loop to print each product in one line.
Output: prints entire database
*/

void print(string *ID, double *price, int *qua, int Size) {
    cout <<"Product ID: \tPrice: \t\tQuantity: " << endl;

    for (int i=0;i<Size;i++) {
        cout << *(ID+i) << "\t\t $"<<*(price+i)<<"\t "<<*(qua+i)<<endl;
    }
    cout << endl;
    
return;
}

/*Function update to update price or quantity
Input:
    array ID, double price array, integer quantity array, Size of arrays, and given product ID
Process:
    Uses findID function to find give product ID index. Initiates variable exist to hold index
    and variable option for the user to choose to update either price or quantity. Switch statement to
    input data.
Output: None.
*/

void update(string *ID, double *price, int *qua, int Size, string updatePrdct) {
    int exist, option;
    exist=findID(ID,updatePrdct, Size);

    if (exist==-1)
        cout << "Function update failed. This product does not exist." << endl<<endl;
    else {
        cerr << "Press 1 to change price, or 2 to change quantity. "<<endl;
        cin >> option;

        switch(option) {
            case 1:
                cin >> price[exist];
                cout << "You changed the price of "<<ID[Size] <<" to: $" << price[exist]<<endl<<endl;
                break;
            case 2:
                cin >> qua[exist];
                cout << "You channged the quantity of "<<ID[Size] <<" to: " << qua[exist]<<endl<<endl;
                break;
            default:
                cout << "Incorrect input for update function." << endl<<endl;
                break;
        }
 	}
return;
}

/*Function addPhone
Input:
    ID, price, and quantity arrays, int size is the size of these arrays.
Process:
    Taking in the input for product name, price of product, and quantity
    and increasing the size of the array by one.
Output: None. Changes the value of Size by reference
*/

void addPhone(string ID[], double price[], int qua[], int &Size) {
    int exist;
    string productID;
    
    cerr << "Input product ID, then price, then quantity of product. (seperate with space) ";
    cin >> ID[Size] >> price[Size] >> qua[Size];
    
    productID=ID[Size];
    exist=findID(ID, productID, Size);

    if (exist==-1)
        Size++;
    else
        cout << "Function addPhone failed. Item " <<productID<< " already exists." << endl<<endl;
return;
}

/* Function findID
Input:
    ID array for phone ID’s. string idfind holds the given product ID number,
    int Size is the total Size of array
Process:
    for loop to compare each value of array ID with the given product ID. If =,
    puts index value of given product ID in variable exist.
Output:
    returns exist, which holds the index of the given product ID number or -1
    if productID doesn’t exist
*/

int findID(string id[], string idfind, int Size) {
    int exist=-1;

    for (int i=0; i<=(Size-1); i++)
        if(id[i]==idfind)
            exist=i;
return exist;
}

int main() {
    string productID[1000];
    double price[1000];
    int quantity[1000];
    int Size=0;
    string prdct;
    int option; 

    cout << "Allina Khan HW#2"<<endl<< endl;

    //Menu
    cerr << "1. Add item \n2. Update item" << endl
        << "3. Display item \n4. Print database" <<endl
        << "5. Exit program" << endl;

    cerr <<"Enter an option: 1,2,3,4, or 5 from the menu: " << endl;
    cin >> option;

    while(option) {
        switch(option) {
            case 1:
                addPhone(productID,price,quantity,Size);
                break;
            case 2:
                cerr << "Which product do you want to update? " << endl;
                cin >> prdct;
                update(productID,price,quantity,Size,prdct);
                break;
            case 3:
                cerr << "Which product do you want to display? " << endl;
                cin >> prdct;
                display(productID,price,quantity,Size,prdct);
                break;
            case 4:
            	print(productID,price,quantity,Size);
                break;
            case 5:
                cout << "You're now exiting the program."<<endl;
                exit(1);
                break;
            default:
                cout << option << " is not a menu option." << endl<<endl;
                break;
        }
    cerr << "1. Add item \n2. Update item" << endl
        << "3. Display item \n4. Print database" <<endl
        << "5. Exit program" << endl <<
        "Enter an option: 1,2,3,4, or 5 from the menu: " <<endl;
    cin >> option;
    }
return 0;
}