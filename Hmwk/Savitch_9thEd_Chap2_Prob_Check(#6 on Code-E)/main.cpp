/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 9, 2024, 5:34 PM
 * Purpose:  Calculates paycheck from hours worked depending on overtime or not
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip> //Format manipulor Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) 
{
    //Set the random number seed
    
    //Declare Variables
    float payRate, hrsWrk; //Assuming integer values for hours worked(straight and overtime) and pay rate 
    float grssPay; //gross pay
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "This program calculates the gross paycheck." << endl
         << "Input the pay rate in $'s/hr and the number of hours." << endl;
     cin >> payRate >> hrsWrk;
    
    grssPay = payRate * hrsWrk; //straight time
    grssPay += hrsWrk > 40 ? (hrsWrk - 40) * payRate : 0;
     
    cout << fixed << setprecision(2) << showpoint
         << "Paycheck = $" << setw(7) << grssPay;
         
    //Exit stage right or left!
    return 0;
}