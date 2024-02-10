/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 9, 2024, 12:36 PM
 * Purpose:  Calculates new salary as well as retroactive pay
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float prevSal, //previous annual salary
          month, //New monthly and annual salary
          annual,
          rtroAct; //payment due from months passed
          
    const float rate = .076;
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    cout << "Input previous annual salary." << endl;
     cin >> prevSal;
     
    annual = prevSal * (1 + rate),
    month = annual / 12,
    rtroAct = prevSal * rate / 12 * 6;
    
    //Display the outputs
cout << fixed << setprecision(2);
cout << "Retroactive pay    = $" << setw(7) << rtroAct << endl;
cout << "New annual salary  = $" << setw(7) << annual << endl;
cout << "New monthly salary = $" << setw(7) << month;
 
    //Exit stage right or left!
    return 0;
}