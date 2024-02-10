/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 14, 2024, 2:56 PM
 * Purpose:  Converts standard number from 1000-3000 to roman numerals
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <string> //String library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int x, //User input ordinary number
        num1, //integer value of corresponding digits in 1's, 10's, 100's, and 1000's place
        num10, //truncates unimportant values using integer division
        num100, 
        num1000;
    
    //Initialize or input i.e. set variable values
    string msg = "";

    //Prompt user for input
    cout << "Arabic to Roman numeral conversion." << endl
         << "Input the integer to convert." << endl;
         
    cin >> x;
    
    //Only accept values according to range declared
    if (x >= 1000 && x <= 3000)
    {
        //strips of unimportant digits using integer division and modulus
        num1000 = x / 1000, //number in the 1000's place
        num100 = (x / 100) % 10, //number in the 100's place
        num10 = (x / 10) % 10, //number in the 10's place
        num1 = x % 10; //number in the 1's place
        
        //switch combined with break statements to only utilize specific case for 1000's place
        switch (num1000) {
            case 1 : msg += "M";
                break;
            case 2 : msg += "MM";
                break;
            case 3 : msg += "MMM";
        }
        //ternary operator that adds specific roman string to msg  
        msg += num100 == 1 ? "C" :
               num100 == 2 ? "CC" :
               num100 == 3 ? "CCC" :
               num100 == 4 ? "CD" :
               num100 == 5 ? "D" :
               num100 == 6 ? "DC" :
               num100 == 7 ? "DCC" :
               num100 == 8 ? "DCCC" :
               num100 == 9 ? "CM" : "";
        //roman numerals corresponding to 10's place
        msg += num10 == 1 ? "X" :
               num10 == 2 ? "XX" :
               num10 == 3 ? "XXX" :
               num10 == 4 ? "XL" :
               num10 ==5 ? "L" :
               num10 == 6 ? "LX" :
               num10 == 7 ? "LXX" :
               num10 == 8 ? "LXXX" :
               num10 == 9 ? "XC" : "";
        //roman numerals corresponding to 1's place      
        msg += num1 == 1 ? "I" :
               num1 == 2 ? "II" :
               num1 == 3 ? "III" :
               num1 == 4 ? "IV" :
               num1 == 5 ? "V" :
               num1 == 6 ? "VI" :
               num1 == 7 ? "VII" :
               num1 == 8 ? "VIII" :
               num1 == 9 ? "IX" : "";
        
        msg = " is equal to " + msg;
    }    
    else 
        msg = " is Out of Range!"; //failed msg if invalid number x entered
     
    //Display the outputs
    cout << x << msg;
    
    //Exit stage right or left!
    return 0;
}