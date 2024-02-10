/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 16, 2024, 6:50 PM
 * Purpose: Calculates money earned from exponential penny increase based on day
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format Library
#include <cmath> //Math Library
using namespace std;

int main(int argc, char** argv){
    //Declare Variables
    unsigned int days, //Amount of days elapsed
              minDays, //Minimum amount of days
              pennies, //Tracks amount of pennies earned
              count; //Day tracker
    
    //Initialize or input i.e. set variable values
    minDays = 1, //Minimum amount of days must be 1
    count = 1, //Start day counter at 1
    pennies = 0; //remove junk memory to properly track
    
    //Prompt to ask user days passed
    cout << "How many days have passed since you started working." << endl;
    
    //Input number of days passed
    cin >> days;
    
    //loop for input validation
    while (days < minDays){
        cout << "That is not a valid number of days. Enter a valid number greater than or equal to 1.\n";
        cin >> days; //once number of days are valid can continue
    }
    
    //loop for calculating salary
    while (count <= days){
        pennies += pow(2,count-1); //power function from cmath library
        count ++; //add counter until reaches days amount
    }
    
    //Display the outputs
    cout << "Pay = $" << pennies/100 << "." 
         << ((pennies%100<10) ? "0" : "") << pennies%100; //Use ternary operator to display correctly the dollar amount
         
    //Exit stage right or left!
    return 0;
}
