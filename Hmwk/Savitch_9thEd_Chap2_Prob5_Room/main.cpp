/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 9, 2024, 8:14 PM
 * Purpose:  Displays message based on if fire hazard exists
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <cmath> //Math operations Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
int attend, //amount of people attending
    max, //max amount of people allowed
    diff; //difference between max capacity and attendance
    
    //Initialize or input i.e. set variable values

    
    //Map inputs -> outputs
    cout << "Input the maximum room capacity and the number of people" << endl;
     cin >> max >> attend;
     
     diff = attend - max; // stores difference, will use absolute value later
     
    attend > max ? cout << "Meeting cannot be held.\nReduce number of people by " << abs(diff) << " to avoid fire violation." //statement if true
                 : cout << "Meeting can be held.\nIncrease number of people by " << abs(diff) << " will be allowed without violation."; //statement if false
    
    
    
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}
