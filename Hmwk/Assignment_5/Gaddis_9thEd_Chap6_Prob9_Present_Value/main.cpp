/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 31, 2024, 4:41 PM
 * Purpose: Calculates money needed in present to attain 10000 with specific interest
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <cmath> //Math Library
#include <iomanip> //Format Library
using namespace std;

//Function Prototypes
float psntVal(float, float, int);

//Program Execution Begins Here
int main(int argc, char** argv){
    //Declare all Variables
    float futVal, //Future Value
          curVal, //Current/Present Value
          intRte; //Interest Rate in percentage
    int years; //Number of years being compounded
    
    //Initialize all Variables
    cout << "This is a Present Value Computation" << endl //Prompts user input for interest rate, future, present value
         << "Input the Future Value in Dollars" << endl;  
    cin >> futVal;
    cout << "Input the Number of Years" << endl; 
    cin >> years;
    cout << "Input the Interest Rate %/yr" << endl; 
    cin >> intRte;
    
    //Process or Map Solutions
    curVal = psntVal(futVal, intRte, years); //send inputs as arguments to calculate present value needed
                                            // and return value to curVal
    //Display the Output
    cout << showpoint << fixed << setprecision(2); //format to show cents correctly
    cout << "The Present Value = $" << curVal; //output present value
    
    //Exit the Program
    return 0;
}
float psntVal(float futVal, float intRte, int years){
    float curVal; //Declare present value variable float so can return it
    intRte /=100; //correct percentage tp decimal before calculation
    
    curVal = futVal / pow(1+intRte, years); //perform calculation using interest rate formula
    
    return curVal; //return result/present value
}
