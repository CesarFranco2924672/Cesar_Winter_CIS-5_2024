/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 4, 2024, 7:28 PM
 * Purpose: Calculates and Displays the transaction of share of stock
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
    short int stckAmt; //Amount of stock purchased
    float cmsnRt, //commission percentage from transaction
          stckPrc, //price stock is purchased at
          cmsnAmt, //dollar amount payed as commission
          subTtl, //Cost prior to commission
          total; //cost after including commission
            
    //Initialize all Variables
        stckAmt = 750, //750 stocks purchased
        cmsnRt = .02, //2 percent commission owed to seller
        stckPrc = 35.00, // $35.00 per stock
                
    //Process or Map Solutions
        subTtl = stckAmt * stckPrc, //cost before commission
        cmsnAmt = subTtl * cmsnRt, //commission amount owed
        total = subTtl + cmsnAmt; //total cost with commission included
        
    //Display the Output
        cout << "Stock Transaction" << endl << endl //Outputs list of costs
             << "Subtotal: $" << subTtl << endl
             << "Commission Owed: $" << cmsnAmt << endl
             << "Total: $" << total;
        
    //Exit the Program
    return 0;
    }

