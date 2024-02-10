/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 31, 2024, 3:53 PM
 * Purpose: Converts military time to 12 hour notation
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <string> //String Library
#include <fstream> //File Library
using namespace std;

//Function Prototypes
void input(string, int&, int&); //Ontained integer inputs from string entered
void convert(int&, string&); //fucntion to fix hours and obtain AM/PM
void output(int, int, string); //functions that outputs standard time
//Program Execution Begins Here
int main(int argc, char** argv){
    //Declare all Variables
    int hours, //hours from military time obtained which iis then fixed
        mins; //mins obtained from military time, constant
    string timeMil, //military time in string format
           TofDay; //dtermines AM/PM
    char choice; //choice for continuing game
   
        
        //Initialize all Variables
    cout << "Military Time Converter to Standard Time" << endl
    << "Input Military Time hh:mm" << endl; //Prompt for user input
    
    do{
        cin >> timeMil; //military time in string format
             
        //Process or Map Solutions
        input(timeMil, hours, mins); //send military time and integers ass pass by reference so can retain value in main
        if (hours>=24 || mins>=60)
            cout << timeMil << " is not a valid time" << endl; //Input validation if time is out of range
            
        else{
            convert(hours, TofDay); //converts hours military to hours standard and detrmines time of day AM/PM
            
            //Display the Output
            cout << timeMil << " = ";
            output(hours, mins, TofDay); //function to output result by storing it in file as string
        }
        
        cout << "Would you like to convert another time (y/n)";
        cin >> choice; //User input for decision
        cout << endl;
    }while(choice=='y'||choice=='Y'); //condition to continue entering times
        
    //Exit the Program
    return 0;
}

void input(string timeMil, int& hours, int& mins){
    fstream replace; //file to obtain integers from string entered military time
    char junk; //junk variable to hold colon
    
    replace.open("obtainInts.dat", ios::out); //open in output
    replace << timeMil; //outpu military time to file
    replace.close(); //close file
    
    replace.open("obtainInts.dat", ios::in); //open in input
    replace >> hours >> junk >> mins; //obtain input in hours then junk then mins
}

void convert(int& hours, string& TofDay){
    if(hours>12){ //past noon so PM
        hours = hours-12; //Hours will be difference with 12
        TofDay = "PM";
    }
    else if (hours==0){ //Midnight so AM
        hours = 12; //Corrects hour value to stndard 12
        TofDay = "AM";
    }
    else if (hours==12){ //Noon so hour is 12 and PM
        hours = 12;
        TofDay = "PM";
    }
    else
        TofDay = "AM"; //Before noon hours are fine, Time of day is AM
}

void output(int hours, int mins, string TofDay){
    fstream outFile; //File for output
    string outTime; //string to obtain line from file and output it
    
    outFile.open("fixTime.dat", ios::out);//open in output mode
    outFile << hours << ":" << mins << " " << TofDay; // write line to file with corrected time
    outFile.close(); //close file
    
    outFile.open("fixTime.dat", ios::in); //open file for input
    getline(outFile, outTime); //getline funcion to obtain line with spaces
    outFile.close(); //close file
    
    cout << outTime << endl; //output string obatined from file
}