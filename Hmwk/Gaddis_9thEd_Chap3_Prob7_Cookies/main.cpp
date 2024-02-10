/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 2, 2024, 12:36 PM
 * Purpose:  Calculate amount of calories consumed
 */

//System Libraries
#include <iostream>  //Input/Output Library
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
    float consume, calorie; //amount of cookies consumed
        
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
cout << "Calorie Counter" << endl //Ask User amount of cookies ate
     << "How many cookies did you eat?" << endl;
cin >> consume;

calorie = consume * 1/40 * 10 * 300; // Ratios to convert amount of cookies eaten to calories eaten 
                                    //#CookiesAte * 1 bag/40 cookies * 10 servings/1 bag * 300 calories/ 1 serving

cout << "You consumed " << calorie << " calories.";
     
    //Exit stage right or left!
    return 0;
}

