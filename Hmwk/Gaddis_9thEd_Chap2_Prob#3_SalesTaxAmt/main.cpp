/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 3, 2024, 1:41 PM
 * Purpose: To calculate the sales tax on a given purchase
 */

//System Libraries
#include <iostream> //Input-Output Library
using namespace std;

//User Libraries

//Global Constants - Math, Physics, Chemistry

//Function Prototypes

//Program Execution Begins Here
int main(int argc, char** argv)
    {
    //Set a random seed
    
    //Declare all Variables
    char price; //The cost of the purchase before tax
    float statRte, //State tax rate
          cntyRte, //County tax rate
          taxAmt, //Amount Taxed on purchase
          total; //The total amount owed with tax
    
    //Initialize all Variables
    price = 95; //The bill is $95 prior to tax
    statRte = 4.0e-2f; //Decimal value of respective tax percentages                   
    cntyRte = 2.0e-2f;
        
    //Process or Map Solutions
    total = price * (1 + statRte + cntyRte); //Static cast not needed since not being displayed
    taxAmt = total - price; //Subtracts the price from the gross to obtain tax amount
    
            
    //Display the Output
    cout << "The total sales tax on a $95 purchase is $" << taxAmt << endl; //Outputs the sales tax Amount
    
    //Exit the Program
    return 0;
    }

