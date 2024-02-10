/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 23, 2024, 2:53 PM
 * Purpose: Game Project for CIS-5
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <fstream> //File Library, for input & output
#include <ctime> //Time file to use system clock
#include <cstdlib> //To use random number generator
using namespace std;

//Program Execution Begins Here
int main(int argc, char** argv)
    {
    //Set a random seed
    srand(time(0));
    //Declare all Variables
    ofstream hand0, //Middle table hand
             hand1, //Hand dealt to first player
             hand2; //Hand dealt to second player
             
    //Initialize file parameter and open
    hand1.open("firstHand.dat"); //Open file before using it
    if(hand1){
        for(int i=1; i<=5; i++)
            hand1 << rand()%13+1 << endl;
    }
    else{
        cout << "Failed to deal First hand";
        return 0;       
    }
    
    hand2.open("secondHand.dat"); //Open file before using it
    if(hand2){
        int i=1;
        do{
            hand2 << rand()%13+1 << endl;
            i++;
        }while(i<=5);
    }
    else{
        cout << "Failed to deal Second hand";
        return 0;       
    }
    
    hand0.open("middleHand.dat"); //Open file before using it
    if(hand0){
        int i=1;
        while(i<=5){
            hand0 << rand()%13+1 << endl;
            i++;
        }
    }
    else{
        cout << "Failed to deal Middle hand";
        return 0;       
    }
            
    //Process or Map Solutions
    
    //Display the Output
    
    //Exit the Program
    return 0;
}

