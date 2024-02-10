/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 11, 2024, 6:36 PM
 * Purpose:  Displays names in alphabetical order
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <string> //String Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    string name1, name2, name3; //Single word strings
    
    //Map inputs -> outputs
    cout << "Sorting Names" << endl
         << "Input 3 names" << endl;
         
    cin >> name1 >> name2 >> name3;
    
    //Display the outputs
 if (name1 < name2 && name1 < name3 && name2 < name3) //Alphabetical order means that first one will have lowest ASCII value ex. A < Z --> 65 < 90
    {
        cout << name1 << endl
             << name2 << endl
             << name3;
    }
    else if (name1 < name2 && name1 < name3 && name3 < name2)//if words have same fist letter than will compare second letter and so forth
    {
        cout << name1 << endl
             << name3 << endl
             << name2;
    }
    else if (name2 < name1 && name2 < name3 && name1 < name3)
    {
        cout << name2 << endl
             << name1 << endl
             << name3;
    }
    else if (name2 < name1 && name2 < name3 && name3 < name1)
    {
        cout << name2 << endl
             << name3 << endl
             << name1;
    }
    else if (name3 < name1 && name3 < name2 && name1 < name2)
    {
        cout << name3 << endl
             << name1 << endl
             << name2;
    }
    else //Last possible condition isn't required to write but its (name3 > name1 && name3 > name2 && name2 > name1)
    {
        cout << name3 << endl
             << name2 << endl
             << name1;
    }
    //Exit stage right or left!
    return 0;
}
