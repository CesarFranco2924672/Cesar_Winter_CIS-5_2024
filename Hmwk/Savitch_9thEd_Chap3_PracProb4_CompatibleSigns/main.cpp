/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 14, 2024, 5:36 PM
 * Purpose: Determines if 2 people are compatibles based on horoscope signs
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string> //String Library
using namespace std;

//Execution Begins Here!
int main() {
    //Declare Variables
    string sign1, //Inputted horoscope signs
           sign2,
           msg; //message that will be outputted
    
    string fire1, fire2, fire3, //Horoscope signs separated by element type(3 in each)
           water1, water2, water3,
           earth1, earth2, earth3,
           air1, air2, air3;
    
    //Initialize or input i.e. set variable values
     fire1 = "Aries",       fire2 = "Leo",           fire3 = "Sagittarius", //Assigns corresponding horoscope sign to its element type
    water1 = "Cancer",     water2 = "Scorpio",      water3 = "Pisces",
    earth1 = "Taurus",     earth2 = "Virgo",        earth3 = "Capricorn",
      air1 = "Gemini",       air2 = "Libra",          air3 = "Aquarius";
    
    //Prompt User to input variable
    cout << "Horoscope Program which examines compatible signs." << endl
         << "Input 2 signs." << endl;
         
    cin >> sign1 >> sign2;
    //Map inputs -> outputs
    if      ( (sign1==fire1 ||  sign1==fire2  ||  sign1==fire3) &&  (sign2==fire1 ||  sign2==fire2 || sign2==fire3) ) //Using parenthesis to maintain correct precedence
        msg = sign1 + " and " + sign2 + " are compatible Fire signs."; //message sign varies based on if compatible with sign
    
    else if ( (sign1==water1 || sign1==water2 || sign1==water3) && (sign2==water1 || sign2==water2 || sign2==water3) )
        msg = sign1 + " and " + sign2 + " are compatible Water signs.";
        
    else if ( (sign1==earth1 || sign1==earth2 || sign1==earth3) && (sign2==earth1 || sign2==earth2 || sign2==earth3) )
        msg = sign1 + " and " + sign2 + " are compatible Earth signs.";
        
    else if  ( (sign1==air1  ||  sign1==air2  ||   sign1==air3) &&  (sign2==air1  ||  sign2==air2  || sign2==air3) )
        msg = sign1 + " and " + sign2 + " are compatible Air signs.";
        
    else
        msg = sign1 + " and " + sign2 + " are not compatible signs."; //if none of the above ae true than not compatible
    //Display the outputs
    cout << msg;
    
    //Exit stage right or left!
    return 0;
}
