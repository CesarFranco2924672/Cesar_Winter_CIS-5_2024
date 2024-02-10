/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 4, 2024, 5:46 PM
 * Purpose: Calculates the annual salary
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
    char payPrd; //Amount of pay periods in a given year
    
    unsigned short int payAmt, //Amount payed each period
                       salary; //Total annual pay
    
    //Initialize all Variables
    payPrd = 26, // total of 26 periods of pay in a given year
    payAmt = 2200, // dollar amount of each pay period
           
    //Process or Map Solutions
    salary = payAmt * payPrd;
            
    //Display the Output
    cout << "Annual Pay = $" << salary;
    //Exit the Program
    return 0;
    }

