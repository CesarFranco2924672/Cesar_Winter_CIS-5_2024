/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 16, 2024, 6:30 PM
 * Purpose:  Calculates sum of integers from 1 up to inputted value
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    unsigned short posNumb, //inputted positive integer
                   sum; //Sum of integers from 1 up to numb
                   
    //Initialize or input i.e. set variable values
    sum = 0; //Initialize with 0 to remove memory default
    
    //Prompt for number to sum up to
    cout << "Enter a positive number to sum up to. "
         << "Example for 3, Sum = 1+2+3=6." << endl;
    //User input for posNumb which will be used as sentinel to end loop
    cin >> posNumb;
    
    //for loop to loop until reaches value of numb
    for (int i = 1; i <= posNumb; i++)
        sum += i;//adds i to sum then repeats with count++
    
    //Display the outputs
    cout << "Sum = " << sum;
    
    //Exit stage right or left!
    return 0;
}
