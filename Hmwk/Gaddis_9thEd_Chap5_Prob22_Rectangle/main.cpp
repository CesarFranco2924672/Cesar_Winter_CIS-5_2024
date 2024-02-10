/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 16, 2024, 10:36 AM
 * Purpose:  Creates an (n * n) rectangle where n is the user inputted positive integer
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char letter; //Character which will make up the rectangle
    int num, //User inputted value for units per side
        length, //Length of rectangle
        height; //Height of rectangle
        
    //Prompt User information about program an ask for input
    cout << "Enter an integer for an n*n rectangle followed by the "
         << "character that will make it up." << endl;
    cin >> num >> letter; //user inputted value and character to make up rectangle
    length = num, //will control columns
    height = num; //will control rows
    
    //Map inputs -> outputs using For loop then display
    for(int rowNum = 1; rowNum <= height; rowNum++){ //begin at row 1 then increment every subsequent time
        for(int colNum =1; colNum <= length; colNum++){ //inner loop to perform column work
            cout << letter;
        }
        if (rowNum != height) //Will skip a line if continuing with rectangle
            cout << endl; //New line for next row
    }
    
    //Exit stage right or left!
    return 0;
}

