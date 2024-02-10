/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 2, 2024, 3:03 PM
 * Purpose:  Calculate the minimum amount of insurance needed from replacement cost
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float cost, insur; //cost of replacing structure and minimum insurance needed 
                       
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
cout << "Insurance Calculator" << endl
     << "How much is your house worth?" << endl;
cin >> cost; //user inputs cost of replacement

insur = cost * .80; //calculates insurance minimum of 80%

cout << "You need $" << insur << " of insurance.";

    //Exit stage right or left!
    return 0;
}

