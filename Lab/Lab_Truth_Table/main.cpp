/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 4, 2024, 1:53 PM
 * Purpose: Truth Table Menu
 */

//System Libraries
#include <iostream> //Input-Output Library
using namespace std;

//Program Execution Begins Here
int main(int argc, char** argv)
    {
    //Declare all Variables
    bool X,Y;
    
    //display Menu Columns
    cout << "X  " << "Y  " << "!X  " << "!Y  " << "X&&Y  " << "X||Y  "
         << "X^Y  " << "(X^Y)^X  " << "(X^Y)^Y  " << "!(X&&Y)  " << "!X||!Y  "   
         << "!(X||Y)  " << "!X&&!Y  " << endl;
    
    //Row 1 Display
    X = true, Y = true; //Condition 1
            X   ? cout << "T  "       : cout << "F  ";
            Y   ? cout << "T   "      : cout << "F   ";
           !X   ? cout << "T   "      : cout << "F   ";
           !Y   ? cout << "T   "      : cout << "F   ";
          X&&Y  ? cout << "T     "    : cout << "F     ";
          X||Y  ? cout << "T     "    : cout << "F     ";
          X^Y   ? cout << "T      "   : cout << "F      ";
        (X^Y)^X ? cout << "T        " : cout << "F        ";
        (X^Y)^Y ? cout << "T        " : cout << "F        ";
        !(X&&Y) ? cout << "T       "  : cout << "F       ";
         !X||!Y ? cout << "T        " : cout << "F        ";
        !(X||Y) ? cout << "T       "  : cout << "F       ";
         !X&&!Y ? cout << "T\n"         : cout << "F\n";
    
    //Row 2 Display
    X = true, Y = false; //Condition 2
        X ? cout << "T  " : cout << "F  ";
        Y ? cout << "T   " : cout << "F   ";
        !X ? cout << "T   " : cout << "F   ";
        !Y ? cout << "T   " : cout << "F   ";
        X&&Y ? cout << "T     " : cout << "F     ";
        X||Y ? cout << "T     " : cout << "F     ";
        X^Y ? cout << "T      " : cout << "F      ";
        (X^Y)^X ? cout << "T        " : cout << "F        ";
        (X^Y)^Y ? cout << "T        " : cout << "F        ";
        !(X&&Y) ? cout << "T       " : cout << "F       ";
        !X||!Y ? cout << "T        " : cout << "F        ";
        !(X||Y) ? cout << "T       " : cout << "F       ";
        !X&&!Y ? cout << "T\n"         : cout << "F\n";
     
    //Row 3 Display
    X = false, Y = true; //Condition 3
        X       ? cout << "T  "       : cout << "F  ";
        Y       ? cout << "T   "      : cout << "F   ";
        !X      ? cout << "T   "      : cout << "F   ";
        !Y      ? cout << "T   "      : cout << "F   ";
        X&&Y    ? cout << "T     "    : cout << "F     ";
        X||Y    ? cout << "T     "    : cout << "F     ";
        X^Y     ? cout << "T      "   : cout << "F      ";
        (X^Y)^X ? cout << "T        " : cout << "F        ";
        (X^Y)^Y ? cout << "T        " : cout << "F        ";
        !(X&&Y) ? cout << "T       "  : cout << "F       ";
        !X||!Y  ? cout << "T        " : cout << "F        ";
        !(X||Y) ? cout << "T       "  : cout << "F       ";
        !X&&!Y  ? cout << "T\n"         : cout << "F\n";
         
    //Row 4 Display
    X = false, Y = false; //Condition 4
        X       ? cout << "T  "       : cout << "F  ";
        Y       ? cout << "T   "      : cout << "F   ";
        !X      ? cout << "T   "      : cout << "F   ";
        !Y      ? cout << "T   "      : cout << "F   ";
        X&&Y    ? cout << "T     "    : cout << "F     ";
        X||Y    ? cout << "T     "    : cout << "F     ";
        X^Y     ? cout << "T      "   : cout << "F      ";
        (X^Y)^X ? cout << "T        " : cout << "F        ";
        (X^Y)^Y ? cout << "T        " : cout << "F        ";
        !(X&&Y) ? cout << "T       "  : cout << "F       ";
        !X||!Y  ? cout << "T        " : cout << "F        ";
        !(X||Y) ? cout << "T       "  : cout << "F       ";
        !X&&!Y  ? cout << "T"         : cout << "F";
    
    //Exit the Program
    return 0;
    }

