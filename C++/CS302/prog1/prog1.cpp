//NAME: Zachary Carlson
//INCLUDE FILES
#include<iostream>
#include<fstream>
#include "adt1.h"
using namespace std;
//GLOBAL

//PROTOTYPES
void loadfile(char file[10], ifstream& fin, item& product, inventory& list);

void totalmanager(double& total, double& rettax, double price, char tax);

//MAIN PROGRAM
int main()
  { 
   //initialize variables
   double returnedtax = 0.0, total = 0.0;
   inventory list;
   item product;
   ifstream fin;
   fin.clear();
   ofstream fout;
   fout.clear();
   bool result = false;
   char input[] = "Input1.txt";
   char output[] = "Output1.txt";
   int productnumber = 1, times, i;
   bool cont = true;
   char insert = 'y';
   //load input from file(Input1.txt)
      //write function (ERROR CHECKING)
 	loadfile(input, fin, product, list);
	list.print();
	//open output file
	fout.open(output);
   	/*loop through each customer. at the end of the loop if will prompt the user if there is another customer*/
	cout << "Type the product number and then type how many items of that product(0 for the product number will complete transaction): "<<endl;
	for(i = 1; cont; i++){
		fout << "Customer " << i << endl;
		productnumber = 1;
   		//loop through customer input (0 for a product number ends order)
		while(productnumber != 0){
		//inputs

			cin >> productnumber >> times;
			//Search
			result = list.search(productnumber);
				//Get if found
				if(result == true){
					//get item
					list.getItem(product);
					fout << product.description <<':'<< times << '@' << product.price << "   " << (product.price * times) << endl;
					//Add the total
					totalmanager(total, returnedtax, (product.price * times), product.tax);
					
				}
				//Error if not found
				else {
					if(productnumber!= 0){
					fout << "*** item "<< productnumber<<" not in inventory ***" << endl;
					cout << "*** item "<< productnumber<<" not in inventory ***" << endl;
					}
				}
		}
		//PRINT OUT FINAL RECEIPT INFO
		//prepare for next customer
		fout <<"Subtotal  "<< total << endl;
		fout <<"Tax       "<<returnedtax << endl<< endl << endl;
		fout <<"Total     "<< total+returnedtax <<endl; 
		fout << "------------------------------------------------------" << endl;
		total = 0.0;
		returnedtax = 0.0;
   	//end of customer loop
	cout << "Would you like to continue to another customer?(y/n)" << endl;
	cin >> insert;
		switch(insert){
		case 'y':
		case 'Y':
		cont = true;
		break;
		default:
		cont = false;
		}
   	}
    fout.close();
   //end program
   return 0;
  }

//IMPLEMENTATION
void loadfile(char file[10], ifstream& fin, item& product, inventory& list){
  bool response;
  int tempid;
  fin.open(file);
	if(fin.good()){
	fin >> product.id >> product.description >> product.price >> product.tax;
	list.insertAtEnd(product);
		while(fin.good()){
		fin >> product.id >> product.description >> product.price >> product.tax;
		if(tempid != product.id){
			tempid = product.id;
			response = list.search(product.id);	
				if(response == false){
				list.insertAtEnd(product);
				}
				if(response == true){
				cout << "DUPLICATE Product Number: Line Skipped" << endl;
				}
		}
		}
	//list.print();
	}
	
  fin.close();
}

void totalmanager(double& total, double& rettax, double price, char tax){
  if(tax == 'T'){
	double temp;
	temp = price * (7.5 / 100);
	rettax = rettax + temp;
  }
  total = total + price;

}
