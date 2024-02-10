/* 
 * Author: Cesar Franco
 * Created on January 30, 2024 @ 4:23
 * Purpose: Calculates the number of terms in a sequence to obtain 1 and outputs the sequence
 */

//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int collatz(int);//3n+1 sequence

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n,ns; //n is the sequence start and ns is the amount of terms in the sequence
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl; //Prompt for User input
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    ns=collatz(n); // will store number of term in ns but also outputsa the sequnce
    
    //Output data
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            ns<<" steps";
    
    //Exit stage right!
    return 0;
}
int collatz(int num){ //Takes an integer value as argument and stores it in num
    int value, //current value of the sequence
        temp; //counter to see how many steps
    value=num, //Initialize value to num to start sequence
    temp=0; //Remove junk value to properly account for running count
    
    while(value>1){//Repeat while the value is not 1 yet
        cout << value << ", "; //Will output value up until 1
        if (value%2==0)
            value=value/2; //divide value by 2
        else
            value=value*3+1; //multiply value by 3 and add 1
        temp++; //Increment temp
        
    }
    cout << value << endl; //output the last value 1
    temp++;//Increment one last time to count integer 1
return temp; //return the step amount through temp
}