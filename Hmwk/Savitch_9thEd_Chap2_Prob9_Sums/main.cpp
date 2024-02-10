/* 
 * File:   main.cpp
 * Author: Cesar Franco 
 * Created on January 9, 2024, 9:03 PM
 * Purpose:  Calculates positive sum and negative sum from user input
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <cmath> //Math Library
#include <iomanip> //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) 
{
    //Set the random number seed
    
    //Declare Variables
    short int num,
              pstv,
              ngtv,
              ttl;
        
    //Initialize or input i.e. set variable values
    num = 0, // Initialize all with 0 before performing operations
    pstv = 0,
    ngtv = 0,
    ttl = 0;
    
    //Map inputs -> outputs
    cout << "Input 10 numbers, any order, positive or negative" << endl;
    
    cin >> num; // Use ternary operator 10 times and add it to the appropriate sum
    num > 0 ? pstv += num : ngtv += num;
    
    cin >> num;
    num > 0 ? pstv += num : ngtv += num;
    
    cin >> num;
    num > 0 ? pstv += num : ngtv += num;
    
    cin >> num;
    num > 0 ? pstv += num : ngtv += num;
    
    cin >> num;
    num > 0 ? pstv += num : ngtv += num;
    
    cin >> num;
    num > 0 ? pstv += num : ngtv += num;
    
    cin >> num;
    num > 0 ? pstv += num : ngtv += num;
    
    cin >> num;
    num > 0 ? pstv += num : ngtv += num;
    
    cin >> num;
    num > 0 ? pstv += num : ngtv += num;
    
    cin >> num;
    num > 0 ? pstv += num : ngtv += num;
    
    ttl = pstv + ngtv;
    
    //Display the outputs
    cout << "Negative sum =" << setw(4) << ngtv << endl
         << "Positive sum =" << setw(4) << pstv << endl
         << "Total sum    =" << setw(4) << ttl;
         
    //Exit stage right or left!
    return 0;
}