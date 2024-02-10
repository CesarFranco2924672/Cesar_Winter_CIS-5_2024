/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 3, 2024, 1:41 PM
 * Purpose: Calculates tax and tip on a restaurant bill & displays the various costs on receipt
 */

//System Libraries
#include <iostream> //Input-Output Library
using namespace std;

//User Libraries

//Global Constants - Math, Physics, Chemistry

//Function Prototypes

//Program Execution Begins Here
int main(int argc, char** argv)
    {
    //Set a random seed
    
    //Declare all Variables
    const float TAX_RT = .0675, //Tax percentage applied only to meal
                TIP_RT = .2; //Tip percentage applied to meal plus tax
    
    float mealCst, //Price of the meal solely
          taxAmt, //Amount taxed on the meal
          tipAmt, //Amount tipped
          total; //Total bill
    
    //Initialize all Variables
    mealCst = 88.67, //Price of meal is $88.67
            
    //Process or Map Solutions
    taxAmt = mealCst * TAX_RT, //Tax is 6.75% of meal cost
    tipAmt = (mealCst + taxAmt) * TIP_RT, //Tip based on sum of meal cost with tax
    total = mealCst + taxAmt + tipAmt; //Total is sum of all costs
    
    //Display the Output
    cout << " meal cost = $" << mealCst << endl //List the various costs to user/consumer
         << "tax amount = $" << taxAmt << endl
         << "       tip = $" << tipAmt << endl
         << "     total = $" << total << endl;
    
    //Exit the Program
    return 0;
    }

