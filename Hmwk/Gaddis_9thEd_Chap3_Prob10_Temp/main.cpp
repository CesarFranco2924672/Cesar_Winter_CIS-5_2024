/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 2, 2024, 12:36 PM
 * Purpose:  Converts Fahrenheit to appropriate Celsius temperature
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip> //Format Manipulator Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float C, F; //Celsius and Fahrenheit values
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
cout << "Temperature Converter" << endl
     << "Input Degrees Fahrenheit" << endl; //Prompt user to enter in value of Fahrenheit
cin >> F;

C = static_cast<float>(5) / 9 *(F - 32); //Conversion formula from Fahrenheit to Celsius

cout << fixed << setprecision(1) //Display 1 significant figure after decimal
     << F << " Degrees Fahrenheit = " << C << " Degrees Centigrade";

    //Exit stage right or left!
    return 0;
}

