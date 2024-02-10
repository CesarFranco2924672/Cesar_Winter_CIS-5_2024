/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 11, 2024, 7:24 PM
 * Purpose:  Determines amount of points based on number of books purchased
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
   
    //Declare Variables
    unsigned short books, points;
    
    //Initialize or input i.e. set variable values
    books = 0,
    points = 0;
    
    //Map inputs -> outputs
    cout << "Book Worm Points" << endl
         << "Input the number of books purchased this month." << endl;
         
    cin >> books;
    
    books >= 4 ? points = 60 : //Use ternary operator to find scenario that is valid
    books == 3 ? points = 30 :
    books == 2 ? points = 15 :
    books == 1 ? points = 5 :
    books == 0 ? points = 0 : 0;
     
    //Display the outputs
   cout << "Books purchased =" << setw(3) << books << endl
        << "Points earned   =" << setw(3) << points;
     
    //Exit stage right or left!
    return 0;
}
