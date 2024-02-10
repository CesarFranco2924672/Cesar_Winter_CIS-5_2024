/* 
 * Author: Cesar Franco
 * Created on January 30, 2024 @ 3:30
 * Purpose: Determines if an Integer is prime or not
 */

//System Libraries
#include <iostream> //Input Output Library
#include <string> //String Library
#include <cmath> //Math Library
using namespace std;

//Function Prototypes
bool isPrime(int);//Determine if the input number is prime.

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int num; //User inputted Integer
    string result; //Message outputting if number is or is not prime
    
    //Process/Map inputs to outputs
    cout << "Input a number to test if Prime." << endl; //Prompt for user input
    cin >> num;
    result = isPrime(num) ? " is prime." : " is not prime.";//Send num as argument into function isPrime & retrun messae if true or false
    //Output data
    cout << num << result; //output number followed by the message
    //Exit stage right!
    return 0;
}
bool isPrime(int num){
    int test; //value to test up to
    test = sqrt(num); //the sqrt of a number is the range youd have to test up to, beacause factors bigger also will have smaller
    
    for(int i=2; i<=test; i++){ //start i at 2 since evr number divisible by 1
        if(num%i==0) //condition to see if even one case was evenly divided with no remainder
            return 0; //returns false value 0 for bool since no remainder
    }
    return 1; // if gets through all the test cases with remainders than will return true for bool
}