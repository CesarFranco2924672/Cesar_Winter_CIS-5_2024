/* 
 * File:   main.cpp
 * Author: Cesar Franco
  * Created on January 18, 2024, 10:44 AM
 * Purpose:  Uses rate of inflation to estimate cost in 1 year and in 2 years
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format Library
using namespace std;

//Function Prototypes
float rate(float, float); //inflation rate function that returns float value and uses 2 floating type parameters
float estCost(float, float); //Calculates estimated cost with current cost and inflation rate as arguments

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float costPre, //Cost of item a year ago
          costCur, //Current cost of item
          infRate, //Inflation rate which is calculated in function [rate] and value returned to infRte
          cost1Y, //Estimated costs both 1 year and 2 years from current
          cost2Y;
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
             
        //Estimated cost in 1 years and 2 years using same inflation rate
        cout << "Price in one year: $" << (cost1Y = estCost(costCur, infRate)) << endl //Same rate of inflation
             << "Price in two year: $" << (cost2Y = estCost(cost1Y, infRate)) << endl << endl;

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

float estCost(float cost, float infRate){
    float costNew; //Local variable to store new cost after accounting for inflation
    
    costNew = cost * (1 + infRate/100); //Calculation for new cost, infRate is given in percentage
    
    return costNew; //Returns new cost to main variable that called it
}

