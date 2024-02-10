/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 4, 2024, 7:12 PM
 * Purpose: Displays the sales price of a circuit board after accounting for profit margin
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
    float profit, //profit made on each sale of a circuit board
          cost, //Cost to the seller
          price; //Price sold to consumers
    
    //Initialize all Variables
    profit = 0.35, // 35 cents profited from each sell
    cost = 14.95, // original cost to the seller
           
    //Process or Map Solutions
    price = cost + profit; //price circuit board sold at
    
    //Display the Output
    cout << "The selling price of the circuit board is $" << price; //Outputs the price to consumer
    
    //Exit the Program
    return 0;
    }

