/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 18, 2024, 8:13 PM
 * Purpose: Menu for Assignment 5, allows user to input desired problem number
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <iomanip> //Formatting Library
#include <cmath> //Math Library
#include <string> //String Library
#include <fstream> //File Library
using namespace std;

//Function Prototypes
void prob1(); //Functions for each problem 1-9 so that main can just call them to display
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void minmax(int,int,int,int&,int&);//Function to find the min and max for Prob#1
int fctrl(int);//Function to calculate factorial for Prob#2
bool isPrime(int);//Determine if the input number is prime. For Prob#3
int collatz(int);//3n+1 sequence. For Prob#4
int collatzWOut(int);//3n+1 sequence. For Prob#5. Outputs sequence
void stdTime(int&, int&,int&, char&);//To time after waiting. For Prob#6
void input(string, int&, int&); //Contains integer inputs from string entered .For Prob#7
void convert(int&, string&); //function to fix hours and obtain AM/PM. For Prob#7
void output(int, int, string); //functions that outputs standard time. For Prob#7
float psntVal(float, float, int); //Calculates present value needed for future. For Prob#8
void getScre(int &,int &,int &,int &,int &); //Function to get scores from user. For Prob#9
float calcAvg(int,int,int,int,int); //function to calculate average score after one of them is dropped. For Prob#9
int fndLwst(int,int,int,int,int); //function to find the lowest test score. For Prob#9


//Program Execution Begins Here
int main(int argc, char** argv){
    //Declare all Variables
    short int probNum; //User inputted value to decide problem displayed
    
    //Display Menu with problem headings
    do { //Do-While loop to display content min once and then test for continuation
        cout << "This Is A Menu For Homework Assignment 5" << endl
             << "Enter Corresponding Digit For Desired Problem." << endl
             << "\tProblem#1: MinMax" << endl
             << "\tProblem#2: Factorial" << endl
             << "\tProblem#3: isPrime" << endl
             << "\tProblem#4: Collatz Sequence" << endl
             << "\tProblem#5: Collatz Sequence with Output of Sequence" << endl
             << "\tProblem#6: Time Clock for Waiting" << endl
             << "\tProblem#7: Military Time Converter" << endl
             << "\tProblem#8: Present Value" << endl
             << "\tProblem#9: Average" << endl;
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
            default: //If anything other than integers 1-9 entered than will exit to menu
                cout << "Exiting to Menu";
        }
    }while(probNum > 0 && probNum <= 10); //Condition for continuing loop and allowing multiple problems entered      
            
    return 0; //End of main function
}

void prob1(){
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
}

void prob2(){
    //Declare Variables
    int num, //User inputted integer
        fact; //factorial of the integer entered
    //Process/Map inputs to outputs
    cout << "This program calculates the factorial using a function prototype found in the template for this problem." << endl
    << "Input the number for the function." << endl; //Prompt for user input
    cin >> num;
    fact = fctrl(num); //send num value to fctrl function and return value to fact
    //Output data
    cout << num << "! = " << fact;
}

void prob3(){
    //Declare Variables
    int num; //User inputted Integer
    string result; //Message outputting if number is or is not prime
    
    //Process/Map inputs to outputs
    cout << "Input a number to test if Prime." << endl; //Prompt for user input
    cin >> num;
    result = isPrime(num) ? " is prime." : " is not prime.";//Send num as argument into function isPrime & retrun messae if true or false
    //Output data
    cout << num << result; //output number followed by the message
}

void prob4(){
    //Declare Variables
    int n; //Integer value which the sequence will start at
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl; //Prompt for User input
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            collatz(n)<<" steps"; //Send n as argument to collatz functions to determine # of steps to obtain 1
}

void prob5(){
    //Declare Variables
    int n,ns; //n is the sequence start and ns is the amount of terms in the sequence
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl; //Prompt for User input
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    ns=collatzWOut(n); // will store number of term in ns but also outputsa the sequnce
    
    //Output data
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            ns<<" steps";
}

void prob6(){
    int hours, //hours inputted at start that will be altered
        mins, //minutes
        wait; //wait time in minutes
    char TofDay, //Either AM or PM
         choice; //User decision if would like to continue entering times
         
    //Initialize or input i.e. set variable values
    do{ //beginning of Do-While Loop
        do{
        cout << "Enter hour:"<< endl; //Prompt for hours
        cin >> hours;
        cout << endl;
        }while(hours>12||hours<=0);
        
        do{
        cout << "Enter minutes:"<< endl; //Prompt for minutes
        cin >> mins;
        cout << endl;
        }while(mins>60||mins<0);
        
        do{
        cout << "Enter A for AM, P for PM:"<< endl; //Prompt for Time of Day
        cin >> TofDay;
        cout << endl;
        }while(TofDay!='A'&&TofDay!='P');
    
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
             << "Again:" << endl; //Prompt to continue entering times
        cin >> choice;
        if(choice=='Y'||choice=='y')
            cout << endl; //will skip a line if decision is yes
    }while(choice=='Y'||choice=='y'); //condition for continuing
}

void prob7(){
    int hours, //hours from military time obtained which iis then fixed
        mins; //mins obtained from military time, constant
    string timeMil, //military time in string format
           TofDay; //determines AM/PM
    char choice; //choice for continuing game
   
        
        //Initialize all Variables
    cout << "Military Time Converter to Standard Time" << endl;
    do{
        cout << "Input Military Time hh:mm" << endl; //Prompt for user input
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
        
        cout << "Would you like to convert another time (y/n)" << endl;
        cin >> choice; //User input for decision
        cout << endl;
    }while(choice=='y'||choice=='Y'); //condition to continue entering times
}

void prob8(){
    //Declare all Variables
    float futVal, //Future Value
          curVal, //Current/Present Value
          intRte; //Interest Rate in percentage
    int years; //Number of years being compounded
    
    //Initialize all Variables
    cout << "This is a Present Value Computation" << endl //Prompts user input for interest rate, future, present value
         << "Input the Future Value in Dollars" << endl;  
    cin >> futVal;
    cout << "Input the Number of Years" << endl; 
    cin >> years;
    cout << "Input the Interest Rate %/yr" << endl; 
    cin >> intRte;
    
    //Process or Map Solutions
    curVal = psntVal(futVal, intRte, years); //send inputs as arguments to calculate present value needed
                                            // and return value to curVal
    //Display the Output
    cout << showpoint << fixed << setprecision(2); //format to show cents correctly
    cout << "The Present Value = $" << curVal; //output present value
}

void prob9(){
    //Declare all Variables
    int score1, score2, score3, score4, score5; //scores 1-->5
    float avg;//average value of the scores kept
    
    //Initialize all Variables
    cout << "Find the Average of Test Scores" << endl //Prompt user about program
         << "by removing the lowest value." << endl;
    getScre(score1, score2, score3, score4, score5); //send pass by reference score values to maintain changed values 
    
    //Process or Map Solutions
    avg = calcAvg(score1, score2, score3, score4, score5); //send test scores to function to calculate
                                                          //average and return it to variable avg
    //Display the Output
    cout << fixed << setprecision(1); //format to make only 1 decimal place
    cout << "The average test score = " << avg; //output the result
}
void minmax(int num1,int num2,int num3,int &min,int &max){//pass by reference for min and max so their value is changed in main as well
    min=(num1<num2 && num1<num3) ? num1 : //ternary operator to find largest
        (num2<num1 && num2<num3) ? num2 : num3;
        
    max=(num1>num2 && num1>num3) ? num1 : //ternary operator to find smallest
        (num2>num1 && num2>num3) ? num2 : num3;
}
int fctrl(int value){
    int sum = 1; //declare and initialize sum to 1 since will be multiplied
    for(int i=1; i<=value; i++) //Loop for as many times until value is reached
        sum*=i; //Multiply every term to the previous one up until value
    return sum; //return sum
}
bool isPrime(int num){
    int test; //value to test up to
    test = sqrt(num); //the sqrt of a number is the range you'd have to test up to, because factors bigger also will have smaller
    
    for(int i=2; i<=test; i++){ //start i at 2 since every number divisible by 1
        if(num%i==0) //condition to see if even one case was evenly divided with no remainder
            return 0; //returns false value 0 for bool since no remainder
    }
    return 1; // if gets through all the test cases with remainders than will return true for bool
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
            value=value*3+1; //multiply value by 3 and add 1
        temp++; //Increment temp
    }
    temp++;//Increment one last time to count integer 1
return temp; //return the step amount through temp
}
int collatzWOut(int num){ //Takes an integer value as argument and stores it in num
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
        hours = 12; //Corrects hour value to standard 12
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
    getline(outFile, outTime); //getline function to obtain line with spaces
    outFile.close(); //close file
    
    cout << outTime << endl; //output string obtained from file
}
float psntVal(float futVal, float intRte, int years){
    float curVal; //Declare present value variable float so can return it
    intRte /=100; //correct percentage tp decimal before calculation
    
    curVal = futVal / pow(1+intRte, years); //perform calculation using interest rate formula
    
    return curVal; //return result/present value
}
void getScre(int &score1, int &score2, int &score3, int &score4, int &score5){
    do{
        cout << "Input the 5 test scores." << endl; //prompt for score inputs
        cin >> score1 >> score2 >> score3 >> score4 >> score5;
        
        if(score1>100||score2>100||score3>100||score4>100||score5>100||//Display message if one of the scores are out of range
           score1<1  ||score2<1  ||score3<1  ||score4<1  ||score5<1)
            cout << "Invalid entry. Enter only scores 1-100.\n";
            
    }while(score1>100||score2>100||score3>100||score4>100||score5>100||//Condition to keep loop repeating if
           score1<1  ||score2<1  ||score3<1  ||score4<1  ||score5<1); //one of the test scores is out of range
}

float calcAvg(int score1, int score2, int score3, int score4, int score5){
    float avg; //declare float variable to hold average
    int lowest; //lowest test score
    lowest = fndLwst(score1, score2, score3, score4, score5);//call function to find lowest test score and return it to lowest
    
    avg = (score1==lowest) ? (score2+score3+score4+score5)/4.0f : //ternary operator to detemine which score to drop 
          (score2==lowest) ? (score1+score3+score4+score5)/4.0f : //in order to properly calculate average
          (score3==lowest) ? (score1+score2+score4+score5)/4.0f :
          (score4==lowest) ? (score1+score2+score3+score5)/4.0f : (score1+score2+score3+score4)/4.0f; 
          
    return avg; //return average value to main
}

int fndLwst(int num1,int num2,int num3,int num4,int num5){
    int temp; //temporary place holder for swapping values
    if(num2>num1){ //score2 is bigger than score1
        temp=num2,
        num2=num1,
        num1=temp;
    }

    if(num3>num2){ //score3 is bigger than score2
        if (num3>num1){ //score3 also bigger than score1
            temp=num3,
            num3=num2,
            num2=num1,
            num1=temp;
        }
        else{ //score2 is in between score 1 and 3
            temp=num3,
            num3=num2,
            num2=temp;
        }
    }
    if(num4>num3&&num4>num2&&num4>num1){ //score4 is the largest
        temp=num4,
        num4=num3,
        num3=num2,
        num2=num1,
        num1=temp;
    }
    else if(num4>num3&&num4>num2){ //score4 is the second largest
        temp=num4,
        num4=num3,
        num3=num2,
        num2=temp;
    }
    else if (num4>num3){ //score4 is the third largest
        temp=num4,
        num4=num3,
        num3=temp;
    }
    else //score4 is the smallest
        num4=num4;

    if(num5>num4&&num5>num3&&num5>num2&&num5>num1){ //score5 is the largest
        temp=num5,
        num5=num4,
        num4=num3,
        num3=num2,
        num2=num1,
        num1=temp;
    }
    else if (num5>num4&&num5>num3&&num5>num2){ //score5 is the second largest
        temp=num5,
        num5=num4,
        num4=num3,
        num3=num2,
        num2=temp;
    }
    else if (num5>num4&&num5>num3){ //score5 is the third largest
        temp=num5,
        num5=num4,
        num4=num3,
        num3=temp;
    }
    else if (num5>num4){ //score5 is the fourth largest
        temp=num5,
        num5=num4,
        num4=temp;
    }
    else
        num5=num5; //score5 is the smallest
    return num5; //return lowest score
}