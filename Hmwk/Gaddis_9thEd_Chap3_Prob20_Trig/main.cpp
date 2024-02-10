/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 2, 2024, 4:32 PM
 * Purpose:  Calculates trig function by converting degree to radian then performing operation
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <cmath> //Math library that allows trig functions
#include <iomanip> //Allows for format manipulation
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float degree, radian; //Different methods to measure angles
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
cout << "Calculate trig functions" << endl
     << "Input the angle in degrees." << endl;
 cin >> degree;

radian = degree * 4 * atan(1) / 180; //Use conversion rate of pi/180, pi is equivalent to 4*arctan(1)

cout << fixed << setprecision(4);
cout << "sin(" << static_cast<int>(degree) << ") = " << sin(radian) << endl //Use fixed and setprecision to display values after decimal accordingly
     << "cos(" << static_cast<int>(degree) << ") = " << cos(radian) << endl
     << "tan(" << static_cast<int>(degree) << ") = " << tan(radian); //static cast to integer for degree
     
    //Exit stage right or left!
    return 0;
}