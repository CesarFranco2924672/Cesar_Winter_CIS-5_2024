/* 
 * File:   main.cpp
 * Author: Cesar Franco
  * Created on January 17, 2024, 10:28 PM
 * Purpose:  Calculates miles per gallon by calling on a function, 
             also loops if User desires it.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include<iomanip> //Format Library
using namespace std;

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float galPLit = .264179; //global constant that can be utilized in all functions including main

//Function Prototypes
float eff(int lit, int mil); //Prototype function for calculating Efficiency in mpg, will return a float value
                                 //Accepts two integer values for parameter, parameter variable names not needed
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int liters1, liters2, //Inputted integer number for liters consumed and number of miles traveled
        miles1, miles2;
    float mpg1, mpg2; //Efficiency of vehicle in miles per gallon
    char choice; //Character decision for continuing program
    
    //Format to display 2 digits after decimal place for floating values
    cout << fixed << setprecision(2);
    
    //Do-While loop to Display Once than tests expression if user wants to continue
    do{ 
        //Car 1
        cout << "Car 1" << endl
             << "Enter number of liters of gasoline:"; //Prompt for liters
         cin >> liters1; //Number of liters consumed by Car#1
        cout << endl;
         
        cout << "Enter number of miles traveled:"; //Prompt for miles
         cin >> miles1; //Number of miles traveled by Car#1
        cout << endl;
         
        mpg1 = eff(liters1, miles1); //Calls for efficiency function with inputted values as arguments
                                 //Returns float value (mpg) to mpg1
        
        cout << "miles per gallon: "
             << mpg1 << endl << endl; //Displays miles per gallon for Car#1
        
        //Car 2     
        cout << "Car 2" << endl
             << "Enter number of liters of gasoline:"; //Prompt for liters
         cin >> liters2; //Number of liters consumed by Car#2
        cout << endl;
         
        cout << "Enter number of miles traveled:"; //Prompt for miles
         cin >> miles2; //Number of miles traveled by Car#2
        cout << endl;
         
        mpg2 = eff(liters2, miles2); //Calls for efficiency function with inputted values as arguments
                                 //Returns float value (mpg) to mpg2
        
        cout << "miles per gallon: "
             << mpg2 << endl << endl; //Displays miles per gallon for Car#2
             
        cout << ((mpg1 > mpg2) ? "Car 1 is more fuel efficient" : "Car 2 is more fuel efficient");
        cout << endl << endl;
             
        cout << "Again:" << endl;
         cin >> choice; //User inputted character for Decision
         
        if (choice == 'y' || choice == 'Y')
            cout << endl; //Newline to repeat loop on following line if user decides to continue
        
    }while(choice == 'y' || choice == 'Y'); //Condition for continuing loop

    //Exit stage right or left!
    return 0;
}

float eff(int lit, int mil) { //Function definition that outlines procedure
    float mpg, //2 local variables of type float declared, miles per gallon and gallons
          gals;
    
    gals = lit * galPLit, //Operation that utilizes global constant to convert to gallons
    mpg = mil/gals; //mil gets promoted and float mpg calculated
    
    return mpg; //returns float value to expression that called function
               //Note: local variable mpg doesn't have to be same name as 
              // expression variable it is being returned too, Different scopes.
}