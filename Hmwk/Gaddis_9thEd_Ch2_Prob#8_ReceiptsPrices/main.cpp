/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 4, 2024, 6;03 PM
 * Purpose: Receipt that displays items purchased with subtotal, tax, and total
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
    const float taxRt = .07; //tax rate of 7% on purchase
    float item1, item2, item3, item4, item5, // list of items purchased
          subTtl, slsTax, total; // Displayed on receipt accordingly
    
    //Initialize all Variables
            item1 = 15.95, // List of item prices that were bought
            item2 = 24.95,
            item3 = 6.95,
            item4 = 12.95,
            item5 = 3.95,
    
    //Process or Map Solutions
                subTtl = item1 + item2 + item3 + item4 + item5, //Price sum of all items before tax
                slsTax = subTtl * taxRt, //Amount taxed on the bill
                total = subTtl + slsTax; //total cost with tax included
            
    //Display the Output
            cout << "Item 1 = $" << item1 << endl //Displaying to user item costs and receipt for it
                  << "Item 2 = $" << item2 << endl
                  << "Item 3 = $" << item3 << endl
                  << "Item 4 = $" << item4 << endl
                  << "Item 5 = $" << item5 << endl << endl
                  << "Sub Total = $" << subTtl << endl
                  << "Sales Tax = $" << slsTax << endl
                  << "    Total = $" << total << endl;
            
    //Exit the Program
    return 0;
    }

