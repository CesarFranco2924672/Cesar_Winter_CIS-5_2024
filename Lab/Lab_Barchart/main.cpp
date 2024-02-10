/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 18, 2024, 1:53 PM
    * Purpose: Displays store sells in asterisks for every 100$ earned
 */

//System Libraries
#include <iostream> //Input-Output Library
using namespace std;

//Function Prototypes
void ast(int); //void function to perform repetitive looping for different sale amounts

//Program Execution Begins Here
int main(int argc, char** argv){
    //Declare all Variables
    int sales1, //Sales for store 1
        sales2, //Sales for store 2
        sales3, //Sales for store 3
        sales4, //Sales for store 4
        sales5; //Sales for store 5
    
    //Display prompts for user to input store sales
    cout << "Enter today's sales for store 1: ";
    cin >> sales1;
    cout << endl;
     
    cout << "Enter today's sales for store 2: ";
    cin >> sales2;
    cout << endl;
     
    cout << "Enter today's sales for store 3: ";
    cin >> sales3;
    cout << endl;
     
    cout << "Enter today's sales for store 4: ";
    cin >> sales4;
    cout << endl; 
    
    cout << "Enter today's sales for store 5: ";
    cin >> sales5;
    cout << endl;
   
    //Header for sales bar chart in terms of *
    cout << "SALES BAR CHART(Each* = $100)" << endl << endl;
    
    //Output sales for each store in terms of * 
    cout << "Store 1: ";
    ast(sales1); //Send to function[ast] with sales1 as argument
             
    cout << "\n\nStore 2: ";
    ast(sales2); //Send to function[ast] with sales2 as argument
             
    cout << "\n\nStore 3: ";
    ast(sales3); //Send to function[ast] with sales3 as argument
             
    cout << "\n\nStore 4: ";
    ast(sales4); //Send to function[ast] with sales4 as argument
     
    cout << "\n\nStore 5: ";
    ast(sales5); //Send to function[ast] with sales5 as argument
     
    //Exit the Program
    return 0;
}

void ast(int saleAmt) { //Argument stored as parameter variable saleAmt
    int astAmt = saleAmt / 100; //One '*' for every 100 earned
    
    for(int i=1; i <= astAmt; i++) //Loop to continuously output asterisks until
        cout << "*";              // max value reached
}

