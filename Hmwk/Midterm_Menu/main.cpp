/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 23, 2024, 6:18 PM
 * Purpose: Menu for MIdterm, allows user to input desired problem number
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <iomanip> //Formatting Library

using namespace std;

//Function Prototypes
void prob1(); //Functions for each problem 1-6 so that main can just call them to display
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();

void shapeX(int); //Used to print out shape x for problem 1
float costA(int); //Cost for package A with int hours                                      Problem 4
float costB(int); //Cost for package B with int hours                                          |
float costC(int); //Cost for package C with int hours                                          |
char bestPac(float, float, float); //Function for best Package, returns char                   |
float saving(float, float, float); //Function for calculating savings with best package        |

//Program Execution Begins Here
int main(int argc, char** argv){
    //Declare all Variables
    short int probNum; //User inputted value to decide problem displayed
    
    //Display Menu with problem headings
    do { //Do-While loop to display content min once and then test for continuation
        cout << "This Is A Menu For The Midterm" << endl
             << "Enter Corresponding Digit For Desired Problem." << endl
             << "\tProblem#1: Size of Shapes" << endl
             << "\tProblem#2: Histogram" << endl
             << "\tProblem#3: Numeric dollars to English" << endl
             << "\tProblem#4: ISP charges" << endl
             << "\tProblem#5: Gross Paycheck" << endl
             << "\tProblem#6: Series Calculation" << endl;
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
            default: //If anything other than integers 1-10 entered than will exit to menu
                cout << "Exiting to Menu";
        }
    }while(probNum > 0 && probNum <= 6); //Condition for continuing loop and allowing multiple problems entered      
            
    return 0; //End of main function
}

void prob1(){
    //Declare all Variables Here
    unsigned short size;
    char shape;       //f-> forward b->backward x->cross
    unsigned short mid, diff;
    
    //Input or initialize values Here
    cout<<"Create a numbered shape that can be sized."<<endl;
    cout<<"Input an integer number [1,50] and a character [x,b,f]."<<endl;
    cin>>size>>shape;
    
    //Switch branch construct for appropriate shape
    switch(shape){
        case 'x':
            shapeX(size); 
            break;
            
        case 'b':
            if (size%2 != 0){ //Size is odd
                for(int row = 1; row <= size; row++){ //Starts at row 1
                    for(int col = 1; col < row; col++)//Skips appropriate number of spaces before displaying digit
                        cout << " ";
                    cout << (size + 1 - row); //Displays high-->low 
                    
                    for(int space = 1; space <= (size - row); space++ ) //Skips spaces that follow the digit
                        cout << " ";
                    cout << endl;
                }
            }
            else { //Size is even
                for(int row = 1; row <= size; row++){ //Starts at row 1
                    for(int col = 1; col < row; col++)//Skips appropriate number of spaces before displaying digit
                        cout << " ";
                    cout << row; //Displays low-->high
                
                    for(int space = 1; space <= (size - row); space++ ) //Skips spaces that follow the digit
                        cout << " ";
                    cout << endl;
                }
            }
            break;
            
        case 'f':
            if (size% 2!= 0){ //Size is odd
                for(int row = 1; row <= size; row++){ //Starts at row 1
                    for(int col = 1; col <= (size - row); col++)//Skips appropriate number of spaces before displaying digit
                        cout << " ";
                cout << row; //Displays high-->low 
                
                for(int space = 1; space < row; space++ ) //Skips spaces that follow the digit
                    cout << " ";
                cout << endl;
                }
            }
            else { //Size is even
                for(int row = 1; row <= size; row++){ //Starts at row 1
                    for(int col = 1; col <= (size - row); col++)//Skips appropriate number of spaces before displaying digit
                        cout << " ";
                cout << (size + 1 - row); //Displays low-->high 
                
                for(int space = 1; space < row; space++ ) //Skips spaces that follow the digit
                    cout << " ";
                cout << endl;
                }
            }
            break;
    }
}

void prob2(){
    //Declare all Variables Here
    char first, //character inputs in order from first to fourth
         second,
         third,
         fourth;
    
    //Input or initialize values Here
    cout<<"Create a histogram chart."<<endl; //Prompt for program information and User input
    cout<<"Input 4 digits as characters."<<endl;
    cin >> first >> second >> third >> fourth;
    
    //Histogram Here
    
    //Analyzing 4th character
    if (fourth>='0' && fourth<='9') { //Compare ascii value with corresponding characters, NOT DIGITS
        cout << fourth << " ";
        for (int i='0'; i<fourth; i++) //Counter starts at ascii value for character '0'
            cout << "*"; //Loop until it reaches value of digit inputted
        cout << endl;
    }
    else //Character is not a digit
        cout << fourth << " ?" << endl; //If not in ascii range for digit then output ?
        
    //Analyzing 3rd character
    if (third>='0' && third<='9') { //Essentially states if third >=48 & <=57
        cout << third << " ";
        for (int i='0'; i<third; i++)
            cout << "*";
        cout << endl;
    }
    else //Character is not a digit
        cout << third << " ?" << endl;
        
    //Analyzing 2nd character
    if (second>='0' && second<='9') { 
        cout << second << " ";
        for (int i='0'; i<second; i++)
            cout << "*";
        cout << endl;
    }
    else //Character is not a digit
        cout << second << " ?" << endl;
        
    //Analyzing 1st character
    if (first>='0' && first<='9') {
        cout << first << " ";
        for (int i='0'; i<first; i++)
            cout << "*";
        cout << endl;
    }
    else //Character is not a digit
        cout << first << " ?" << endl;
}

void prob3(){
    unsigned short number, //Number that will be converted into English
                   digit1, //First digit from left
                   digit2, //Second digit    |
                   digit3, //Third digit     |
                   digit4; //Fourth digit    |
    
    
    //Input or initialize values Here
    cout << "Input an integer [1-3000] convert to an English Check value."<<endl; //Prompt for input
    cin >> number;
    
    //Verify Range
    if(number >= 0 && number <= 3000){
        //Calculate the 1000's, 100's, 10's and 1's
        digit1 = number/1000, //Number in the thousands place
        digit2 = number/100 % 10, //Number in the hundreds place
        digit3 = number/10 % 10, //Number in the tens place
        digit4 = number % 10; //Number in the ones place
        
        //Output the check value
        switch(digit1){ //Each case corresponds to the text for the thousands place
            case 0: 
                cout << "";
                break; //Break statements to prevent waterfalling
            case 1:
                cout << "One Thousand ";
                break;
            case 2:
                cout << "Two Thousand ";
                break;
            case 3:
                cout << "Three Thousand ";
                break;
            case 4:
                cout << "Four Thousand ";
                break;
            case 5:
                cout << "Five Thousand ";
                break;
            case 6:
                cout << "Six Thousand ";
                break;
            case 7:
                cout << "Seven Thousand ";
                break;
            case 8:
                cout << "Eight Thousand ";
                break;
            case 9:
                cout << "Nine Thousand ";
                break;
        }
        
        switch(digit2){ //Each case corresponds to the text for the hundreds place
            case 0: 
                cout << "";
                break;
            case 1:
                cout << "One Hundred ";
                break;
            case 2:
                cout << "Two Hundred ";
                break;
            case 3:
                cout << "Three Hundred ";
                break;
            case 4:
                cout << "Four Hundred ";
                break;
            case 5:
                cout << "Five Hundred ";
                break;
            case 6:
                cout << "Six Hundred ";
                break;
            case 7:
                cout << "Seven Hundred ";
                break;
            case 8:
                cout << "Eight Hundred ";
                break;
            case 9:
                cout << "Nine Hundred ";
                break;
        }
        
        switch(digit3){ //Each case corresponds to the text for the tens place
            case 0: 
                cout << "";
                break;
            case 1:
                cout << (digit4 == 1 ? "Eleven " : //Special cases where if one is in tens place,
                        digit4 == 2 ? "Twelve " : // then, will have appropriate suffix
                        digit4 == 3 ? "Thirteen " :
                        digit4 == 4 ? "Fourteen " :
                        digit4 == 5 ? "Fifteen " :
                        digit4 == 6 ? "Sixteen " : //Ternanry operator to branch to true statement
                        digit4 == 7 ? "Seventeen " :
                        digit4 == 8 ? "Eighteen " :
                        digit4 == 9 ? "Nineteen " : "Ten "); //If digit4 is zero then simply 10
                break;
            case 2:
                cout << "Twenty ";
                break;
            case 3:
                cout << "Thirty ";
                break;
            case 4:
                cout << "Forty ";
                break;
            case 5:
                cout << "Fifty ";
                break;
            case 6:
                cout << "Sixty ";
                break;
            case 7:
                cout << "Seventy ";
                break;
            case 8:
                cout << "Eighty ";
                break;
            case 9:
                cout << "Ninety ";
                break;
        }
         
        switch(digit4){ //Each case corresponds to the text for the ones place
            case 0: 
                cout << "";
                break;
            case 1:
                cout << (digit3 != 1 ? "One " : "");  //Condition that states if the previous digit was 1, ignore the suffix
                break;                                //                             |
            case 2:                                   //                             |
                cout << (digit3 != 1 ? "Two " : "");  //                             |
                break;                                //                             |
            case 3:                                   //                             |
                cout << (digit3 != 1 ? "Three " : "");//                             |
                break;                                //                             |
            case 4:                                   //                             |
                cout << (digit3 != 1 ? "Four " : ""); //                             |
                break;                                //                             |
            case 5:                                   //                             |
                cout << (digit3 != 1 ? "Five " : ""); //                             |
                break;                                //                             |
            case 6:                                   //                             |
                cout << (digit3 != 1 ? "Six " : "");  //                             |
                break;                                //                             |
            case 7:                                   //                             |
                cout << (digit3 != 1 ? "Seven " : "");//                             |
                break;                                //                             |
            case 8:                                   //                             |
                cout << (digit3 != 1 ? "Eight " : "");//                             |
                break;                                //                             |
            case 9:                                   //                             |
                cout << (digit3 != 1 ? "Nine " : ""); //                             |
                break;
        }
        cout<<"and no/100's Dollars"<<endl; //Zero cents
    }
    else
        cout << "Out of Range! Enter Only Within Bounds" << endl; //Fail message if out of bounds
}

void prob4(){
    //Declare all Variables Here
    char package, //Package owned
         best; //Best package option based on savings;
    unsigned short hours;
    float bill, //Bill with selected package
          saveA, //Savings with A
          saveB, //Savings with B
          saveC, //Savings with C
          saveTtl; //Savings with best package option
    
    //Input or initialize values Here
    cout<<"ISP charges for service delivered."<<endl;
    cout<<"Input package A,B,C then hours used for the month"<<endl; //Prompt User for Input
    cin>>package>>hours;
    
    //Output the Charge
    switch(package){ //Switch branch to determine package selected
        case 'A':
            bill = costA(hours); //Send hours into function for package A costs
            
            //Use functions to calculate savings and best choice
            saveA = 0, //Savings with same package
            saveB = bill - costB(hours), //Savings with package B
            saveC = bill - costC(hours), //Savings with package C
            
            best = bestPac(saveA, saveB, saveC), //Best package, returns character
            saveTtl = saving(saveA, saveB, saveC); //Amount saved with best package
            
            break;
            
        case 'a': //Same as package 'A'
            bill = costA(hours);
            
            saveA = 0,
            saveB = bill - costB(hours),
            saveC = bill - costC(hours),
            
            best = bestPac(saveA, saveB, saveC),
            saveTtl = saving(saveA, saveB, saveC);
            
            break;
                
        case 'B':
            bill = costB(hours); //Send hours into function for package B costs
            
            //Use functions to calculate savings and best choice
            saveA = bill - costA(hours),
            saveB = 0,
            saveC = bill - costC(hours),
            
            best = bestPac(saveA, saveB, saveC),
            saveTtl = saving(saveA, saveB, saveC);
            
            break;
            
        case 'b': //Same as package 'B'
            bill = costB(hours);
            
            saveA = bill - costA(hours),
            saveB = 0,
            saveC = bill - costC(hours),
            
            best = bestPac(saveA, saveB, saveC),
            saveTtl = saving(saveA, saveB, saveC);
            
            break;
            
        case 'C':
            bill = costC(hours); //Send hours into function for package C costs
            
            //Use functions to calculate savings and best choice
            saveA = bill - costA(hours),
            saveB = bill - costB(hours),
            saveC = 0,
            
            best = bestPac(saveA, saveB, saveC),
            saveTtl = saving(saveA, saveB, saveC);
            
            break;
            
        case 'c': //Same as package 'C'
            bill = costC(hours);
            
            saveA = bill - costA(hours),
            saveB = bill - costB(hours),
            saveC = 0,
            
            best = bestPac(saveA, saveB, saveC),
            saveTtl = saving(saveA, saveB, saveC);
            
            break;
            
        default:
            cout << "Invalid choice! Enter a valid option."; //Invalid package choice!
    }

    //Output the cheapest package and the savings
    cout << showpoint << fixed << setprecision(2); //Format dollars to two decimal places
    cout << "$" << bill << " " << best << " $" << saveTtl << endl;//Output original cost followed by best package type and saving amount
}

void prob5(){
    //Declare all Variables Here
    float payRate, //Dollars pers hour
          grssPay; //Total earned without deductions
    unsigned short hrsWrkd; //Amount of hours worked
    
    //Input or initialize values Here
    cout<<"Paycheck Calculation."<<endl;
    cout<<"Input payRate in $'s/hour and hours worked"<<endl; //Prompt for User input
    cin>>payRate>>hrsWrkd;
    
    //Calculate Paycheck
    if (hrsWrkd <= 20) //Equations to solve gross pay based on depicted range of hours worked
        grssPay = hrsWrkd * payRate;
    else if (hrsWrkd > 20 && hrsWrkd <= 40)
        grssPay = 20*payRate + (hrsWrkd-20)*payRate*1.5;
    else //Hours worked are greater than 40
        grssPay = 20*payRate + 20*payRate*1.5 + (hrsWrkd-40)*payRate*2;
    
    //Output the check
    cout << showpoint << fixed << setprecision(2) //Format to 2 decimal places to show dollar amount
         << "$" << grssPay << endl;
}

void prob6(){
    //Declare all Variables Here
    float x, fx, term; //fx is sum and x is variable, term is term number
    int nterms; //number of terms in series
    
    //Input or initialize values Here
    cout << "Calculate a series f(x)=x-x^3/3!+x^5/5!-x^7/7!+......." << endl;
    cout << "Input x and the number of terms, output f(x)" << endl; //Prompt User
    cin >> x >> nterms;
    
    fx = x, //Removing junk value to propery account running sum
    term = x; //start term at x so loop will begin at 2
    
    //Calculate Sequence sum here
    for (int i = 2; i <= nterms; i++){ //i is the term number, starts at 2
        term *= -1*x*x/((i*2-1)*(i*2-2)),
        fx += term;
    }
    //Output the result here
    cout << showpoint << fixed << setprecision(6) //Format to proper decimal places
         << fx << endl;
}

void shapeX(int size){
    if (size%2 != 0){ //Size is odd
        int mid = size/2 + 1;
        
        //Displays first half up until middle row
        for(int row = 1; row < mid; row++){
            int diff = (mid - row); //Difference in row from current to middle
            
            for(int col = 1; col < row; col++) //Spaces before first digit
                cout << " ";
            cout << (size + 1 - row);
            
            for(int betw = 1; betw <= (diff*2-1); betw++) //Spaces between both digits, every difference
                cout << " ";                             // is 2 more spaces in between the previous
            cout << row;
            
            for(int space = 1; space < row; space++ ) //Skips spaces that follow Second digit
                cout << " ";
            cout << endl;
        }
        //Displays middle row
        for(int i = 1; i <= (size-1)/2; i++) //Skips spaces before digit
            cout << " ";
        cout << (size/2 + 1); //Outputs middle number
        for(int i = 1; i <= (size-1)/2; i++) //Skips spaces after digit
            cout << " ";
        cout << endl;
        
        //Displays second half after middle row
        for(int row = mid+1; row <= size; row++){
            int diff = (row - mid); //Differnce in row from current to middle
            
            for(int col = 1; col <= (size - row); col++) //Spaces before first digit
                cout << " ";
            cout << row; //Displays high-->low
            
            for(int betw = 1; betw <= (diff*2-1); betw++) //Spaces between both digits, every difference
                cout << " ";                             // is 2 more spaces in between the previous
            cout << (size + 1 - row);
            
            for(int space = 1; space <= (size - row); space++ ) //Skips spaces that follow the second digit
                cout << " ";
            cout << endl;
        }
    }
    else { //Size is even
        int mid = (size / 2);
        
        //Displays first half including the first middle(even will have 2 middles)
        for(int row = 1; row <= mid; row++){ //Starts at row 1
            int diff = (mid - row);
            
            for(int col = 1; col < row; col++) //Spaces before first digit
                cout << " ";
            cout << row;
            
            for(int betw = 1; betw <= (diff*2); betw++) //Spaces between both digits, every difference
                cout << " ";                             // is 2 more spaces in between the previous
            cout << (size + 1 - row);
            
            for(int space = 1; space < row; space++ ) //Skips spaces that follow the digit
                cout << " ";
            cout << endl;
        }
        //Display second half including second middle
        for(int row = (mid + 1); row <= size; row++){ 
            int diff = (row - mid - 1);
            
            for(int col = 1; col <= (size - row); col++) //Spaces before first digit
                cout << " ";
            cout << (size + 1 - row);
            
            for(int betw = 1; betw <= (diff*2); betw++) //Spaces between both digits, every difference
                cout << " ";                             // is 2 more spaces in between the previous
            cout << row;
            
            for(int space = 1; space <= (size - row); space++ ) //Skips spaces that follow the digit
                cout << " ";
            cout << endl;
        }
    }
}

float costA(int hours){ //Function body to calculate cost with package A
    const float packA = 16.99; //Monthly constant charge not including hours
    float bill;
    
    //Determine charge type based on hours
    if (hours>10 && hours<=20)
        bill = packA + (hours-10)*0.95;
    else if (hours>20)
        bill = packA + 10*0.95 + (hours-20)*0.85;
    else
        bill = packA;
        
    return bill; //returns float value for bill
}

float costB(int hours){ //Function body to calculate cost with package A
    const float packB = 26.99; //Monthly constant charge not including hours
    float bill;
    
    //Determine charge type based on hours
    if (hours>20 && hours<=30)
        bill = packB + (hours-20)*0.74;
    else if (hours>30)
        bill = packB + 10*0.74 + (hours-30)*0.64;
    else
        bill = packB;
    
    return bill;
}

float costC(int hours){
    const float packC = 36.99; //Monthly constant charge including hours
    float bill;
    
    bill = packC; //Unlimited hour access so only monthly charge
    
    return bill;
}

//Char function to return best package type
char bestPac(float saveA, float saveB, float saveC){
    char best; //Best bang for buck
    
    best = (saveA>saveB && saveA>saveC) ? 'A' : //Assigns best to corresponding packages using ternary op
           (saveB>saveA && saveB>saveC) ? 'B' : 'C';
    
    return best;
}

//Float function type to calculate amount saved with best package selected
float saving(float saveA, float saveB, float saveC){
    float savings;
    
    savings = (saveA>saveB && saveA>saveC) ? saveA : //Assigns savings to Save amount of corresponding package
              (saveB>saveA && saveB>saveC) ? saveB : saveC;
    
    return savings;//Returns highest savings
}
