/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 4, 2024, 6:40 PM
 * Purpose: Calculates miles per gallon of vehicle with given tank size and distance traveled 
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
    char tank, //variable for tank size
         mpg; // miles per gallon
    
    short int dist; //distance traveled by car
    
    //Initialize all Variables
    tank = 15, //gallon amt
    dist = 375, //travel distance in miles
            
    //Process or Map Solutions
    mpg = dist / tank; // miles per gallon is miles divided by gallons
    
    //Display the Output
    cout << "Mpg = " << static_cast<int>(mpg); //outputs the miles per gallon of vehicle
    
    //Exit the Program
    return 0;
    }

