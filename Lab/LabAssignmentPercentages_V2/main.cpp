/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 9, 2024, 1:53 PM
 * Purpose: Calculating Military budget as percentage of Federal budget using 2021 values
 */

//System Libraries
#include <iostream>//Input-Output Library
# include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math, Physics, Chemistry

//Function Prototypes

//Program Execution Begins Here
int main(int argc, char** argv)
    {
    //Set a random seed
    
    //Declare all Variables
    float federal, //federal and military budget as well as percentage rate
          mili,
          percent;
    
    //Initialize all Variables
    mili = 7.2e11f, //budget for each in U.S. dollars
    federal = 6.8e12f,
            
    //Process or Map Solutions
    percent = mili/federal * 100; //calculates percentage using ratio
            
    //Display the Output
            cout << setprecision(2), // 2 sig figs to output result
            cout << "The military budget is $" << mili<< ", which is ~" 
                 << percent << "% of the federal budget: $" << federal;
            
    //Exit the Program
    return 0;
    }

