/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 4, 2024, 6:51 PM
 * Purpose: Calculates the acre amount of a land given the square footage
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
    unsigned short int conv; //Conversion rate for feet^2 and acres
    
    float sqFt, //Size of given land in feet^2
          acreAmt; //Size of given land in acres
    
    //Initialize all Variables
    conv = 43560, //43560 feet^2 in one acre
    sqFt = 391876, //Square footage of property
            
    //Process or Map Solutions
    acreAmt = sqFt / conv; //total acre of property
    
    //Display the Output
    cout << "The land is " << acreAmt << " acres in size."; //Outputs the amount of acres to the user
    
    //Exit the Program
    return 0;
    }

