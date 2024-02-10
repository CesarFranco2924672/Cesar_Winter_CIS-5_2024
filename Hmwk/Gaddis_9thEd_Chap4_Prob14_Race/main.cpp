/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 11, 2024, 9:20 PM
 * Purpose:  Alligns runners based on time finished in race
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <string> //String Library for input data
#include <iomanip> //Format Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    string name1, name2, name3; //name of each runner
    short time1, time2, time3; //time finished race in seconds presumably
    
    //Initialize or input i.e. set variable values
    time1 = time2 = time3 = 0;
    
    //Map inputs -> outputs
    cout << "Race Ranking Program" << endl
         << "Input 3 Runners" << endl
         << "Their names, then their times" << endl;

     
     cin >> name1 >> time1 //inputs name followed by time
         >> name2 >> time2
         >> name3 >> time3;
    
    //Display the Outputs 
    if (time1 < 0 || time2 < 0 || time3 < 0) //if an invalid time entered will infrom the user
        cout << "You've entered an invalid time. Please enter a positive value.";
        
    else
    {
        if (time1 < time2 && time1 < time3) //combination expression using logical operator and
        {
            if (time2 < time3) //player 2 finishes second
            {
                cout << name1 << "\t" << setw(3) << time1 << endl
                     << name2 << "\t" << setw(3) << time2 << endl
                     << name3 << "\t" << setw(3) << time3;
            }
            else //player 3 finishes second
            {
                cout << name1 << "\t" << setw(3) << time1 << endl
                     << name3 << "\t" << setw(3) << time3 << endl
                     << name2 << "\t" << setw(3) << time2;
            }
        }
    
    
        else if (time2 < time1 && time2 < time3)//player 2 finishes first
        {
            if (time1 < time3) //player 1 finishes second
            {
                cout << name2 << "\t" << setw(3) << time2 << endl
                     << name1 << "\t" << setw(3) << time1 << endl
                     << name3 << "\t" << setw(3) << time3;
            }
            else //player 3 finishes second
            {
                cout << name2 << "\t" << setw(3) << time2 << endl
                     << name3 << "\t" << setw(3) << time3 << endl
                     << name1 << "\t" << setw(3) << time1;
            }
        }
    
    
        else if (time3 < time1 && time3 < time2) //player 3 finsihes first
        {
            if (time1 < time2) //player 1 finishes second
            {
                cout << name3 << "\t" << setw(3) << time3 << endl
                     << name1 << "\t" << setw(3) << time1 << endl
                     << name2 << "\t" << setw(3) << time2;
            }
            else //player 2 finishes second
            {
                cout << name3 << "\t" << setw(3) << time3 << endl
                     << name2 << "\t" << setw(3) << time2 << endl
                     << name1 << "\t" << setw(3) << time1;
            }
        }
    }
    //Exit stage right or left!
    return 0;
}