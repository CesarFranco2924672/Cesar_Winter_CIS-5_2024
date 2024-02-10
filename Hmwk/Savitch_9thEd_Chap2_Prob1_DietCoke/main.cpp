/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 9, 2024 6:02 PM
 * Purpose:  Calculates max amount of soda consumption with respect to sweetner amount
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
int wgtDiet, //weight of dieter in pounds
      massM, //mass of mouse in grams
      massL, //mass of sweetener lethal to mouse
      massSod; //mass of soda in grams
float conv, //conversion rate from pounds to grams
      ratio, //Ratio of grams sweetener to grams body-weight that is lethal
      maxSoda; //maximum amount of cans of soda before lethal
const float conc = .001f; //concentration of sweetener in 1 can of Soda
    
    //Initialize or input i.e. set variable values
    massM = 35,
    massL = 5,
    conv = 45359.2 / 100, // conversion rate is 45359.2 grams = 1 lb
    ratio = static_cast<float>(massL) / massM, //Ratio of grams lethal to bodyweight
    massSod = 350;
    
    //Map inputs -> outputs
    
    //Display the outputs
cout << "Program to calculate the limit of Soda Pop Consumption." << endl
     << "Input the desired dieters weight in lbs." << endl;
 cin >> wgtDiet;
 
maxSoda = wgtDiet * conv * ratio * 1 / (conc * massSod); //#lbsD*(45359.2 grams/100 pounds)*(1 gram lethal/7 grams)*(1 soda/{.001*350}gram lethal)

cout << "The maximum number of soda pop cans" << endl
     << "which can be consumed is " << static_cast<int>(maxSoda) << " cans";
     
    //Exit stage right or left!
    return 0;
}