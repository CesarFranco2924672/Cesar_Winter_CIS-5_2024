/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 17, 2024, 11:46 AM
 * Purpose:  Displays pattern of '+' based on user input amount
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int num, // User inputted value that goes from 1-->num and num-->1
        count; //keeps track of digit reached
    
    //Prompt for user to input value
    cout << "Enter an integer value which will display an increase from "
         << "1 to n then decreases from n to 1." << endl;
            
    //Initialize or input i.e. set variable values
    cin >> num;
    count = 1; //Starts off at 1 for first half
    
    //Map inputs -> outputs and display outputs
    while(count <= num){ //if true will enter a for loop that outputs "count" number of '+'
        for (int reps = 1; reps <= count; reps++) //repeatedly initialized for each row
            cout << "+";
            
        cout << endl << endl;
        count++; //adds 1 to count
    }
    
    count -= 1; //Reverts number back to it max value, essentially, count = num or count--
    
    while (count >= 1){
        for (int reps = 1; reps <= count; reps++)
            cout << "+";
            
        if (count != 1) //Prevents endl from executing if on last iteration
            cout << endl << endl;
        count--;//Subtracts 1 from count
    }    
    
    //Exit stage right or left!
    return 0;
}

