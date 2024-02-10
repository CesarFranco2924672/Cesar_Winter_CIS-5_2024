/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 11, 2024, 8:53 PM
 * Purpose: Calculates bank balance and fees for the Month
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    short int checks;
    float curBlnc, //Current Balance
          rate, //Service fee for each check
          chckFee, //Total check fees
          mnthFee, //monthe fee
          lowBlnc, //Charge based on current balance
          newBlnc; //New balance after costs
    
    //Initialize or input i.e. set variable values
    mnthFee = 10; //Constant fee
    
    //Map inputs -> outputs
    cout << "Monthly Bank Fees" << endl
         << "Input Current Bank Balance and Number of Checks" << endl;
         
    cin >> curBlnc >> checks;

    //Executuion based on Balance amount
    if (curBlnc >= 400)
        lowBlnc = 0;
    else if (curBlnc < 400 && curBlnc >=0)
        lowBlnc = 15;
    else 
    {
        lowBlnc = 15;
        cout << "The Account is Overdrawn." << endl;
    }
    
    //Execution based on check amount
    if (checks >= 60)
            rate = .04;
    else if (checks >= 40 && checks < 60)
            rate = .06;
    else if (checks >= 20 && checks < 40)
            rate = .08;
    else if (checks < 20 && checks >= 0)
            rate = .10;
    else 
    {
        cout << "Please enter a non-negative value for checks.\n";
        curBlnc = 0,
        chckFee = 0,
        mnthFee = 0,
        lowBlnc = 0,
        newBlnc = 0;
    }
    
    chckFee = checks * rate,
    newBlnc = curBlnc - mnthFee - chckFee - lowBlnc;
    
    //Display the Outputs
    cout << showpoint << fixed << setprecision(2)
         << "Balance     $" << setw(9) << curBlnc << endl 
         << "Check Fee   $" << setw(9) << chckFee << endl 
         << "Monthly Fee $" << setw(9) << mnthFee << endl 
         << "Low Balance $" << setw(9) << lowBlnc << endl 
         << "New Balance $" << setw(9) << newBlnc;
             
    //Exit stage right or left!
           
    return 0;
}

