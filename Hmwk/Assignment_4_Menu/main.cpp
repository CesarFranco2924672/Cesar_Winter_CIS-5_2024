/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 18, 2024, 8:13 PM
 * Purpose: Menu for Assignment 4, allows user to input desired problem number
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <iomanip> //Formatting Library
#include <cmath> //Math Library
using namespace std;

//Function Prototypes
void prob1(); //Functions for each problem 1-10 so that main can just call them to display
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void prob10();
float eff(int liters, int miles); //Function for calculating Efficiency in mpg, will return a float value, problems #6 & #7
float rate(float, float); //function for calculating inflation rate from 2 prices, problems #8 & #9
float estCost(float, float); //Calculates estimated cost with current cost and inflation rate as arguments, problem #9
float maxVal(float = 0, float = 0, float = 0); //Function to calculate max value from 3 parameters,
                                              //default value set for parameters, problem #10
//Program Execution Begins Here
int main(int argc, char** argv){
    //Declare all Variables
    short int probNum; //User inputted value to decide problem displayed
    
    //Display Menu with problem headings
    do { //Do-While loop to display content min once and then test for continuation
        cout << "This Is A Menu For Homework Assignment 4" << endl
             << "Enter Corresponding Digit For Desired Problem." << endl
             << "\tProblem#1: Sum of Positive Integers" << endl
             << "\tProblem#2: Pay in Pennies" << endl
             << "\tProblem#3: Min and Max Value" << endl
             << "\tProblem#4: Rectangle" << endl
             << "\tProblem#5: Pattern" << endl
             << "\tProblem#6: Miles per Gallon" << endl
             << "\tProblem#7: Fuel Efficiency" << endl
             << "\tProblem#8: Inflation" << endl
             << "\tProblem#9: Estimated Cost" << endl
             << "\tProblem#10: 2 or 3 Max" << endl;
        cin >> probNum; //Problem number inputted
        cout << endl;
        
        //Switch statement to control branching based on input value
        switch (probNum){
            case 1: //Each case number corresponds to problem number
                prob1(); //Call to function 1
                cout << endl << endl;
                break;
            case 2: 
                prob2(); //Call to function 2
                cout << endl << endl;
                break;
            case 3: 
                prob3(); //Call to function 3
                cout << endl << endl;
                break;
            case 4: 
                prob4(); //Call to function 4
                cout << endl << endl;
                break;
            case 5: 
                prob5(); //Call to function 5
                cout << endl << endl;
                break;
            case 6: 
                prob6(); //Call to function 6
                cout << endl << endl;
                break;
            case 7: 
                prob7(); //Call to function 7
                cout << endl << endl;
                break;
            case 8: 
                prob8(); //Call to function 8
                cout << endl << endl;
                break;
            case 9: 
                prob9(); //Call to function 9
                cout << endl << endl;
                break;
            case 10: 
                prob10(); //Call to function 10
                cout << endl << endl;
                break;
            default: //If anything other than integers 1-10 entered than will exit to menu
                cout << "Exiting to Menu";
        }
    }while(probNum > 0 && probNum <= 10); //Condition for continuing loop and allowing multiple problems entered      
            
    return 0; //End of main function
}

void prob1(){
    //Declare Variables
    unsigned short posNumb, //inputted positive integer
                   sum; //Sum of integers from 1 up to numb
                   
    //Initialize or input i.e. set variable values
    sum = 0; //Initialize with 0 to remove memory default
    
    //Prompt for number to sum up to
    cout << "Enter a positive number to sum up to. "
         << "Example for 3, Sum = 1+2+3=6." << endl;
    //User input for posNumb which will be used as sentinel to end loop
    cin >> posNumb;
    
    //for loop to loop until reaches value of numb
    for (int i = 1; i <= posNumb; i++)
        sum += i;//adds i to sum then repeats with count++
    
    //Display the outputs
    cout << "Sum = " << sum;
}

void prob2(){
    //Declare Variables
    unsigned int days, //Amount of days elapsed
              minDays, //Minimum amount of days
              pennies, //Tracks amount of pennies earned
              count; //Day tracker
    
    //Initialize or input i.e. set variable values
    minDays = 1, //Minimum amount of days must be 1
    count = 1, //Start day counter at 1
    pennies = 0; //remove junk memory to properly track
    
    //Prompt to ask user days passed
    cout << "How many days have passed since you started working." << endl;
    
    //Input number of days passed
    cin >> days;
    
    //loop for input validation
    while (days < minDays){
        cout << "That is not a valid number of days. Enter a valid number greater than or equal to 1.\n";
        cin >> days; //once number of days are valid can continue
    }
    
    //loop for calculating salary
    while (count <= days){
        pennies += pow(2,count-1); //power function from cmath library
        count ++; //add counter until reaches days amount
    }
    
    //Display the outputs
    cout << "Pay = $" << pennies/100 << "." 
         << ((pennies%100<10) ? "0" : "") << pennies%100; //Use ternary operator to display correctly the dollar amount
}

void prob3(){
    //Declare Variables
    int sentnl, //Sentinel value that signals end of loop
        large, //Largest number entered 
        small, //smallest number entered
        num; //User inputted value which is looped
    
    //Initialize or input i.e. set variable values
    sentnl = -99, //If user enters values will terminate loop
    
    //Map inputs -> outputs
    cout << "Enter a series of integers, then enter -99 when finished. "
         << "The smallest and largest integer will be displayed, "
         << "not including -99." << endl;
    cin >> num;
    
    large = num, //one time initialization so that loop has reference values
    small = num;
    //loop for entering numbers repeatedly
    while (num != sentnl){
        if (num > large) //if the number is larger than it stores it in large
            large = num;
        if (num < small) //if the number is smaller than it stores it in small
            small = num;
        cin >> num; //Inputs numbers continuously for loop
    }    
    //Display the outputs
    cout << "Smallest number in the series is " << small << endl
         << "Largest  number in the series is " << large << endl;
}

void prob4(){
    //Declare Variables
    char letter; //Character which will make up the rectangle
    int num, //User inputted value for units per side
        length, //Length of rectangle
        height; //Height of rectangle
        
    //Prompt User information about program an ask for input
    cout << "Enter an integer for an n*n rectangle followed by the "
         << "character that will make it up." << endl;
    cin >> num >> letter; //user inputted value and character to make up rectangle
    cout << endl;
    length = num, //will control columns
    height = num; //will control rows
    
    //Map inputs -> outputs using For loop then display
    for(int rowNum = 1; rowNum <= height; rowNum++){ //begin at row 1 then increment every subsequent time
        for(int colNum =1; colNum <= length; colNum++){ //inner loop to perform column work
            cout << letter;
        }
        if (rowNum != height) //Will skip a line if continuing with rectangle
            cout << endl; //New line for next row
    }
    cout << endl;
}

void prob5(){
    //Declare Variables
    int num, // User inputted value that goes from 1-->num and num-->1
        count; //keeps track of digit reached
    
    //Prompt for user to input value
    cout << "Enter an integer value which will display an increase from "
         << "1 to n then decreases from n to 1." << endl;
            
    //Initialize or input i.e. set variable values
    cin >> num;
    count = 1; //Starts off at 1 for first half
    
    //Map inputs -> outputs and display outputs
    while(count <= num){ //if true will enter a for loop that outputs "count" number of '+'
        for (int reps = 1; reps <= count; reps++) //repeatedly initialized for each row
            cout << "+";
            
        cout << endl << endl;
        count++; //adds 1 to count
    }
    
    count -= 1; //Reverts number back to it max value, essentially, count = num or count--
    
    while (count >= 1){
        for (int reps = 1; reps <= count; reps++)
            cout << "+";
            
        if (count != 1) //Prevents endl from executing if on last iteration
            cout << endl << endl;
        count--;//Subtracts 1 from count
    }   
    cout << endl;
}

void prob6(){
    //Declare Variables
    int liters, miles; //Inputted integer number for liters consumed and number of miles traveled
    float mpg; //Efficiency of vehicle in miles per gallon
    char choice; //Character decision for continuing program
    
    //Format to display 2 digits after decimal place for floating values
    cout << fixed << setprecision(2);
    
    //Do-While loop to Display Once than tests expression if user wants to continue
    do{ 
        cout << "Enter number of liters of gasoline: "; //Prompt for liters
         cin >> liters; //Number of liters consumed by User's car
         
        cout << "Enter number of miles traveled: "; //Prompt for miles
         cin >> miles; //Number of miles traveled by User's car
         
        mpg = eff(liters, miles); //Calls for efficiency function with inputted values as arguments
                                 //Returns float value (mpg)
        
        cout << "Miles per Gallon: "
             << mpg << endl; //Displays miles per gallon 
             
        cout << "\nAgain:" << endl;
         cin >> choice; //User inputted character fo Decision
        if (choice == 'y')
            cout << endl; //Newline to repeat loop on following line if user decides to continue
        
    }while(choice == 'y' || choice == 'Y'); //Condition for continuing loop
}

void prob7(){
    //Declare Variables
    int liters1, liters2, //Inputted integer number for liters consumed and number of miles traveled
        miles1, miles2;
    float mpg1, mpg2; //Efficiency of vehicle in miles per gallon
    char choice; //Character decision for continuing program
    
    //Format to display 2 digits after decimal place for floating values
    cout << fixed << setprecision(2);
    
    //Do-While loop to Display Once than tests expression if user wants to continue
    do{ 
        //Car 1
        cout << "Car 1" << endl
             << "Enter number of liters of gasoline: "; //Prompt for liters
         cin >> liters1; //Number of liters consumed by Car#1
         
        cout << "Enter number of miles traveled: "; //Prompt for miles
         cin >> miles1; //Number of miles traveled by Car#1
         
        mpg1 = eff(liters1, miles1); //Calls for efficiency function with inputted values as arguments
                                 //Returns float value (mpg) to mpg1
        
        cout << "miles per gallon: "
             << mpg1 << endl << endl; //Displays miles per gallon for Car#1
        
        //Car 2     
        cout << "Car 2" << endl
             << "Enter number of liters of gasoline: "; //Prompt for liters
         cin >> liters2; //Number of liters consumed by Car#2
         
        cout << "Enter number of miles traveled: "; //Prompt for miles
         cin >> miles2; //Number of miles traveled by Car#2
         
        mpg2 = eff(liters2, miles2); //Calls for efficiency function with inputted values as arguments
                                 //Returns float value (mpg) to mpg2
        
        cout << "miles per gallon: "
             << mpg2 << endl << endl; //Displays miles per gallon for Car#2
             
        if(mpg1 > mpg2) 
            cout << "Car 1 is more fuel efficient";
        else if (mpg2 > mpg1)
            cout << "Car 2 is more fuel efficient";
        else
            cout << "Both cars have the same fuel efficiency";
        cout << endl << endl;
             
        cout << "Again: ";
         cin >> choice; //User inputted character for Decision
     
        if (choice == 'y' || choice == 'Y')
            cout << endl; //Newline to repeat loop on following line if user decides to continue
        
    }while(choice == 'y' || choice == 'Y'); //Condition for continuing loop
}

void prob8(){
    //Declare Variables
    float costPre, //Cost of item a year ago
          costCur, //Current cost of item
          infRate; //Inflation rate which is calculated in function [rate] and value returned to infRte
    char choice; //User inputted choice for continuing or stopping looping
    
    //Initialize or input i.e. set variable values
    costPre = 0, //Remove junk memory just to be safe even though all these variables will 
    costCur = 0, //reassigned rather than summed
    infRate = 0;
    
    //Display Prompts using a Do-While loop
    do{
        cout << "Enter current price: $";
        cin >> costCur; //Cost of item currently
        
        cout << "Enter year-ago price: $";
        cin >> costPre; //Cost of price 1 year ago
        
        cout << fixed << setprecision(2); //Display inflation to 2 decimal places
        cout << "Inflation rate: " << (infRate = rate(costCur, costPre))  //Calls on a function named rate with
             << "%\n\n"; //Outputs inflation rate                           //current cost and previous cost as arguments
             
        cout << "Again: ";
        cin >> choice; //User inputted decision for loop construct
        
        if (choice == 'Y' || choice == 'y') //Branching construct for new line statement
            cout << endl; //Skips an additional line to repeat loop on new line, otherwise no gap
    }while(choice == 'Y' || choice == 'y'); //Condition that causes loop to repeat
}

void prob9(){
    //Declare Variables
    float costPre, //Cost of item a year ago
          costCur, //Current cost of item
          infRate, //Inflation rate which is calculated in function [rate] and value returned to infRte
          cost1Y, //Estimated costs both 1 year and 2 years from current
          cost2Y;
    char choice; //User inputted choice for continuing or stopping looping
    
    //Initialize or input i.e. set variable values
    costPre = 0, //Remove junk memory just to be safe even though all these variables will 
    costCur = 0, //reassigned rather than summed
    infRate = 0;
    
    //Display Prompts using a Do-While loop
    do{
        cout << "Enter current price: ";
        cin >> costCur; //Cost of item currently
        
        cout << "Enter year-ago price: ";
        cin >> costPre; //Cost of price 1 year ago
        
        cout << fixed << setprecision(2); //Display inflation to 2 decimal places
        cout << "Inflation rate: " << (infRate = rate(costCur, costPre))  //Calls on a function named rate with
             << "%\n\n"; //Outputs inflation rate                           //current cost and previous cost as arguments
             
        //Estimated cost in 1 years and 2 years using same inflation rate
        cout << "Price in one year: $" << (cost1Y = estCost(costCur, infRate)) << endl //Same rate of inflation
             << "Price in two years: $" << (cost2Y = estCost(cost1Y, infRate)) << endl << endl;

        cout << "Again: ";
        cin >> choice; //User inputted decision for loop construct
        
        if (choice == 'Y' || choice == 'y') //Branching construct for new line statement
            cout << endl; //Skips an additional line to repeat loop on new line, otherwise no gap
    }while(choice == 'Y' || choice == 'y'); //Condition that causes loop to repeat
}

void prob10(){
    //Declare Variables
    float num1, // 3 Inputted numbers
          num2,
          num3,
          lrgst; //Largest value of the arguments
          
    //Initialize or input i.e. set variable values
     num1 = 0, num2 = 0, num3 = 0;
     
    //Map inputs -> outputs
    cout << "Enter first number: ";  //Prompt for Number 1
    cin >> num1;
    
    cout << "Enter Second number: "; //prompt for Number 2
    cin >> num2;
    
    cout << "Enter third number: "; //Prompt for Number 3
    cin >> num3;
    cout << endl;
    
    //Display the outputs
    cout << "Largest number from two parameter function: " << endl
         << (lrgst = maxVal(num1, num2)) << endl; //Calls function to determine max value of argument num1 & num2
         
    cout << "Largest number from three parameter function:" << endl
         << (lrgst = maxVal(num1, num2, num3)) << endl; //Calls function to determine max value of arguments: num1, num2, num3
}

float eff(int lit, int mil){ //Function definition that outlines procedure
    const float galPLit = .264179; //Constant gallons per liter
    float mpg, //2 local variables of type float declared, miles per gallon and gallons
          gals;
    
    gals = lit * galPLit, //Operation that utilizes global constant to convert to gallons
    mpg = mil/gals; //mil gets promoted and float mpg calculated
    
    return mpg; //returns float value to expression that called function
               //Note: local variable mpg doesn't have to be same name as 
              // expression variable it is being returned too, Different scopes.
}

float rate(float current, float prev) {
    float infRate; //Local variable: inflation rate
    
    infRate = (current - prev)/prev * 100; //Calculation for inflation percentage
    
    return infRate; //Returns local variable float value to main variable infRate, same name but doesn't have to be
}

float estCost(float cost, float infRate){
    float costNew; //Local variable to store new cost after accounting for inflation
    
    costNew = cost * (1 + infRate/100); //Calculation for new cost, infRate is given in percentage
    
    return costNew; //Returns new cost to main variable that called it
}

float maxVal(float first, float second, float third) {
    float lrgst; //Largest value
    
    if (third == 0) //If the third parameter remains default value then just calculate largest of first 2 numbers,
        lrgst = first > second ? first : second;                     //otherwise negatives would affect program
    else { //All arguments were provided so determine largest of the 3
        if (first > second && first > third)
            lrgst = first;
        else if (second > first && second > third)
            lrgst = second;
        else
            lrgst = third;
    }
    return lrgst; //Return largest number from arguments 
}