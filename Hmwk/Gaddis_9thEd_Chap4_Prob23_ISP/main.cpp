/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 11, 2024, 9:46 PM
 * Purpose:  Calculates Customer's Monthly Bill for Internet Service
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    short unsigned hours; //Valid only for integer hours
    float priceA, //Price per month for each service, not counting exceeded hours
          priceB,
          priceC,
          bill; //The monthly bill
    
    //Initialize or input i.e. set variable values
    priceA = 9.95,
    priceB = 14.95,
    priceC = 19.95;
    
    //Map inputs -> outputs
    cout << "ISP Bill" << endl
         << "Input Package and Hours" << endl;
         
    cin >> choice >> hours;
    
    //Display Outputs
    if (hours < 744 && hours >=0)
    {
        switch (choice) //Executes one of the cases only since used break, if invalid will return default
        {
            case 'A' : bill = hours > 10 ? (priceA + (hours - 10) * 2) : priceA;
                cout << "Bill = $" << setw(6) << bill;
                break;
                
            case 'B' : bill = hours > 20 ? (priceB + (hours - 20)) : priceB;
                cout << "Bill = $" << setw(6) << bill;
                break;
                
            case 'C' : bill = priceC;
                cout << "Bill = $" << setw(6) << bill;
                break;
                
            default : cout << "You've Entered an invalid character. Please enter either A, B, or C.";
        }
    }
    else
        cout << "Number of hours in a month cannot exceed 744. Please enter a valid amount.";
   
    //Exit stage right or left!
    return 0;
}
