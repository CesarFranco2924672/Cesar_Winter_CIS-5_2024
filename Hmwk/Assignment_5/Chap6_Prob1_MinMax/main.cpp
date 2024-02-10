/* 
 * Author: Cesar Franco
 * Created on January 30, 2024 @ 3:20
 * Purpose: Outputs the factorial of the inputted Integer
 */

//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int fctrl(int);//Function to write for this problem

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int num, //User inputted integer
        fact; //factorial of the integer entered
    //Process/Map inputs to outputs
    cout << "This program calculates the factorial using a function prototype found in the template for this problem." << endl
    << "Input the number for the function." << endl; //Prompt for user input
    cin >> num;
    fact = fctrl(num); //send num value to fctrl function and return value to fact
    //Output data
    cout << num << "! = " << fact;
    //Exit stage right!
    return 0;
}
int fctrl(int value){
    int sum = 1; //declare and intialize sum to 1 since will be multiplied
    for(int i=1; i<=value; i++) //Loop for as many times until value is reached
        sum*=i; //Multiply every term to the previous one up until value
    return sum; //return sum
}
