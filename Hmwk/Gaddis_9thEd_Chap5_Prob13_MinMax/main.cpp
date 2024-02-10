/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 17, 2024, 10:10 AM
 * Purpose:  Displays largest and smallest number after inputting sentinel value
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int sentnl, //Sentinel value that signals end of loop
        large, //Largest number entered 
        small, //smallest number entered
        num; //User inputted value which is looped
    
    //Initialize or input i.e. set variable values
    sentnl = -99, //If user enters values will terminate loop
    
    //Map inputs -> outputs
    cout << "Enter a series of integers, then enter -99 when finished. "
         << "The smallest and largest integer will be displayed, "
         << "not including -99." << endl;
    cin >> num;
    
    large = num, //one time initialization so that loop has reference values
    small = num;
    //loop for entering numbers repeatedly
    while (num != sentnl){
        if (num > large) //if the number is larger than it stores it in large
            large = num;
        if (num < small) //if the number is smaller than it stores it in small
            small = num;
        cin >> num; //Inputs numbers continuously for loop
    }    
    //Display the outputs
    cout << "Smallest number in the series is " << small << endl
         << "Largest  number in the series is " << large;

    //Exit stage right or left!
    return 0;
}

