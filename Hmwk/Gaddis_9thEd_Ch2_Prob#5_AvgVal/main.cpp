/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 4, 2024, 1:53 PM
 * Purpose: Calculates the average value of given list of numbers
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
    short int val_1, //Stores integer values that will later be initialized
              val_2,
              val_3,
              val_4,
              val_5;
    
    float sum, avgVal; //Float data type so that average value is calculated with decimals
    
    //Initialize all Variables
    val_1 = 28, //Assigns respective integer values to given variables 
    val_2 = 32,
    val_3 = 37,
    val_4 = 24,
    val_5 = 33;
            
    //Process or Map Solutions
    sum = (val_1 + val_2 + val_3 + val_4 + val_5), //Adds all values to obtain sum
    avgVal = sum / 5; //Divides sum by number of integers
    
    //Display the Output
    cout << "The average value of the given list of integers is " << avgVal << endl;
    
    //Exit the Program
    return 0;
    }

