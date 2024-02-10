/* 
 * Author: Cesar Franco
 * Created on January 30, 2024 @ 11:23
 * Purpose: Use a function to find the minimum and maximum from a set of 3 Integers
 */

//System Libraries
#include <iostream>
using namespace std;
//Function Prototypes
void minmax(int,int,int,int&,int&);//Function to find the min and max

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int num1, num2, num3, //3 integers user inputs
        min, //minimum value from set of integers
        max; //maximum value from set of integers
    //Initialize Variables
    min=0, //Initialize to 0 to remove junk value, will be re-initialized in void anyway
    max=0;
    //Process/Map inputs to outputs
    cout << "Input 3 numbers" << endl;
    cin >> num1 >> num2 >> num3;
    minmax(num1, num2, num3, min, max);//send all 5 numbers as arguments to function minmax
    //Output data
    cout << "Min = " << min << endl //output to the user their minimum and maximum values
         << "Max = " << max;
    //Exit stage right!
    return 0;
}
void minmax(int num1,int num2,int num3,int &min,int &max){//pass by reference for min and max so their value is changed in main as well
    min=(num1<num2 && num1<num3) ? num1 : //ternary operator to find largest
        (num2<num1 && num2<num3) ? num2 : num3;
        
    max=(num1>num2 && num1>num3) ? num1 : //ternary operator to find smallest
        (num2>num1 && num2>num3) ? num2 : num3;
}

