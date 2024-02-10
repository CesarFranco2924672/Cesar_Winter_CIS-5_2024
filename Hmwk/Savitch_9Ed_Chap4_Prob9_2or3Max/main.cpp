/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 18, 2024, 11:15 AM
 * Purpose:  Uses rate of inflation to estimate cost in 1 year and in 2 years
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Function Prototypes
float maxVal(float = 0, float = 0, float = 0); //Function to calculate max value from 3 parameters,
                                              //default value set for parameters
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float num1, // 3 Inputted numbers
          num2,
          num3,
          lrgst; //Largest value of the arguments
          
    //Initialize or input i.e. set variable values
     num1 = 0, num2 = 0, num3 = 0;
     
    //Map inputs -> outputs
    cout << "Enter first number:" << endl; //Prompt for Number 1
    cin >> num1;
    cout << endl;
    
    cout << "Enter Second number:" << endl; //prompt for Number 2
    cin >> num2;
    cout << endl;
    
    cout << "Enter third number:" << endl; //Prompt for Number 3
    cin >> num3;
    cout << endl;
    
    //Display the outputs
    cout << "Largest number from two parameter function:" << endl
         << (lrgst = maxVal(num1, num2)) << endl << endl; //Calls function to determine max value of argument num1 & num2
         
    cout << "Largest number from three parameter function:" << endl
         << (lrgst = maxVal(num1, num2, num3)) << endl; //Calls function to determine max value of arguments: num1, num2, num3
         
    //Exit stage right or left!
    return 0;
}

float maxVal(float first, float second, float third) { //definition for float function
    float lrgst;
    
    if (third == 0) //If the third parameter remains default value then just calculate largest of first 2 numbers,
        lrgst = first > second ? first : second;                     //otherwise negatives would affect program
    else { //All arguments were provided so determine largest of the 3
        if (first > second && first > third)
            lrgst = first;
        else if (second > first && second > third)
            lrgst = second;
        else
            lrgst = third;
    }
    return lrgst; //Return largest number from arguments 
}

