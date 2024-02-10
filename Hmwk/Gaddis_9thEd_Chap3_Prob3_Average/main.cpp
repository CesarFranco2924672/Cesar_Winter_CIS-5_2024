/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 4, 2024, 1:53 PM
 * Purpose: Display average value of a list of numbers given by user
 */

//System Libraries
#include <iostream>//Input-Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math, Physics, Chemistry

//Function Prototypes

//Program Execution Begins Here
int main(int argc, char** argv)
    {
    //Set a random seed
    
    //Declare all Variables
    short int num1, num2, num3, num4, num5, sum;
    float avg;//Average as float so that can show decimal value
    
    //Initialize all Variables
    
    //Process or Map Solution
    
    //Display the Output
    cout << "Input 5 numbers to average." << endl;
    cin >> num1 >> num2 >> num3 >> num4 >> num5;//user inputs series of numbers separated by space
    
    sum = num1 + num2 + num3 + num4 + num5,
    avg = static_cast<float>(sum)/5;//convert sum to float to obtain float result and store in average
    
    cout << showpoint << setprecision(2)//express trailing zeroes while maintaining 2 sig figs
         << "The average = " << avg;
    //Exit the Program
    return 0;
    }

