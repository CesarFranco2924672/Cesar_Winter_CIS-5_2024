/* 
 * Author: Cesar Franco
 * Created on January 30, 2024 @ 4:57
 * Purpose: Ouputs the time clock after waiting time has passed
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format Library for clock
using namespace std;

//Function Prototypes
void stdTime(int&, int&,int&, char&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int hours, //hours inputted at start that will be altered
        mins, //minutes
        wait; //wait time in minutes
    char TofDay, //Either AM or PM
         choice; //User decision if would like to continue entering times
         
    //Initialize or input i.e. set variable values
    do{ //beginning of Do-While Loop
        cout << "Enter hour:"<< endl; //Prompt for hours
        cin >> hours;
        cout << endl;
    
        cout << "Enter minutes:"<< endl; //Prompt for minutes
        cin >> mins;
        cout << endl;
    
        cout << "Enter A for AM, P for PM:"<< endl; //Prompt for Time of Day
        cin >> TofDay;
        cout << endl;
    
        cout << "Enter waiting time:"<< endl; //Prompt for minutes to wait
        cin >> wait;
        cout << endl;
    
        cout << "Current time = " << setw(2) << setfill('0') << hours << ":" //Output current time to 2 spaces
             << setw(2) <<setfill('0') << mins << " " << TofDay << "M" << endl;
        
        //Map inputs -> outputs
        stdTime(hours, mins, wait, TofDay); //send to function as pass by reference so that values will be altered
        
        //Display the outputs
        cout << "Time after waiting period = " << setw(2) << setfill('0') << hours << ":" 
             << setw(2) << setfill('0')<< mins << " " << TofDay <<"M" //Output to correct digits and Time of Day
             << endl << endl
             << "Again:" << endl; //Prompt to cntinue entering times
        cin >> choice;
        if(choice=='Y'||choice=='y')
            cout << endl; //will skip a line if decisin is yes
    }while(choice=='Y'||choice=='y'); //condition for continuing
    
    //Exit stage right or left!
    return 0;
}
void stdTime(int& hours, int& mins, int& wait, char& TofDay){
    //Converts time to minutes and starts from 00:00 like military time
    if(TofDay=='A'){ //Between 00:00 & 11:59
        if(hours==12){ //12 am is simply 0 with regard to military time
            hours=0;
            mins=mins; //keep the mins
        }
        else
            mins=hours*60+mins; //otherwise hours is converted to mins and added to mins
                
    }
    else //between 12:00 & 23:59
        if(hours==12) //12 pm is still 12 in military time
            mins=hours*60+mins; //calculate total minutes
        else
            mins=(12+hours)*60+mins; //Otherwise minutes is past noon and military clock is 12+hour
                
    mins+=wait; //add the wait time to minutes
    hours=mins/60; //use integer division to calculate hours by truncating remainder
    mins=mins%60; //use mod operator to obtain remainder and store for minutes
        
    int AorP; //declare integer to determine AM or PM based on odd or even
    AorP=hours/12; //divide by 12 to split up sections of day, even# are AM & odd are PM
        
    if(AorP%2==0){//It is AM
        TofDay='A';
    }
    else //it is PM
        TofDay='P';
            
        
    hours = (hours>12) ? hours%12 : hours; //if hours is greater than std clock then mod for remainder otherwise keep value
    hours = hours%12==0 ? 12 : hours; //if no remainder than hour time is 12  
}