/* 
 * Author: Cesar Franco
 * Created on January 30, 2024 @ 4:00
 * Purpose: Calculates the number of terms in a sequence to obtain 1
 */

//System Libraries
#include <iostream> //Input-Ouput Library
using namespace std;

//Function Prototypes
int collatz(int);//3n+1 sequence

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n; //Integer value which the sequence will start at
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl; //Prompt for User input
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            collatz(n)<<" steps"; //Send n as argument to collats functions to determine # of steps to obtain 1
    
    //Exit stage right!
    return 0;
}
int collatz(int num){ //Takes an integer value as argument and stores it in num
    int value, //current value of the sequence
        temp; //counter to see how many steps
    value=num, //Initialize value to num to start sequence
    temp=0; //Remove junk value to properly account for running count
    
    while(value>1){//Repeat while the value is not 1 yet
        if (value%2==0)
            value=value/2; //divide value by 2
        else
            value=value*3+1; //multiply valu by 3 and add 1
        temp++; //Increment temp
    }
    temp++;//Increment one last time to count integer 1
return temp; //return the step amount through temp
}