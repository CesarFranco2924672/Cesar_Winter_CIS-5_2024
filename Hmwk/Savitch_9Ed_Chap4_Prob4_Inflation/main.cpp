/* 
 * File:   main.cpp
 * Author: Cesar Franco
  * Created on January 17, 2024, 10:48 PM
 * Purpose:  Calculates rate of inflation from 2 prices utilizing function, 
             allows user to repeat as many times as they want by looping
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format Library
using namespace std;

//Function Prototypes
float rate(float, float); //function that returns float value and uses 2 floating type parameters

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float costPre, //Cost of item a year ago
          costCur, //Current cost of item
          infRate; //Inflation rate which is calculated in function [rate] and value returned to infRte
    char choice; //User inputted choice for continuing or stopping looping
    
    //Initialize or input i.e. set variable values
    costPre = 0, //Remove junk memory just to be safe even though all these variables will 
    costCur = 0, //reassigned rather than summed
    infRate = 0;
    
    //Display Prompts using a Do-While loop
    do{
        cout << "Enter current price:";
        cin >> costCur; //Cost of item currently
        cout << endl;
        
        cout << "Enter year-ago price:";
        cin >> costPre; //Cost of price 1 year ago
        
        cout << fixed << setprecision(2); //Display inflation to 2 decimal places
        cout << "\nInflation rate: " << (infRate = rate(costCur, costPre))  //Calls on a function named rate with
             << "%\n\n"; //Outputs inflation rate                           //current cost and previous cost as arguments
             
        cout << "Again:";
        cin >> choice; //User inputted decision for loop construct
        cout << endl;
        
        if (choice == 'Y' || choice == 'y') //Branching construct for new line statement
            cout << endl; //Skips an additional line to repeat loop on new line, otherwise no gap
    }while(choice == 'Y' || choice == 'y'); //Condition that causes loop to repeat
    
    //Exit stage right or left!
    return 0;
}

float rate(float current, float prev) {
    float infRate; //Local variable: inflation rate
    
    infRate = (current - prev)/prev * 100; //Calculation for inflation percentage
    
    return infRate; //Returns local variable float value to main variable infRate, same name but doesn't have to be
}

