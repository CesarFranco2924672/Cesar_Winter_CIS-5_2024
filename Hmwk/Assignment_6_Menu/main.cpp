/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 18, 2024, 8:13 PM
 * Purpose: Menu for Assignment 6, allows user to input desired problem number
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <iomanip> //Formatting Library
#include <cmath> //Math Library
#include <cstring> //String Library
#include <fstream> //File Library
#include <vector>
#include <string.h>
#include <ctime>
using namespace std;

//Global Constants
const int COLS=6;

//Function Prototypes
void prob1(); //Functions for each problem 1-8 so that main can just call them to display
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void fillSum(int [][COLS],int); //Function to fill array contents (Prob#1)
void prntTbl(const int [][COLS],int); //Function to print/display array contents(Prob#1)
void fillMul(int [][COLS],int); //(Prob#2)
void  init3(int [],int);//Initialize the array (Prob#3)
void  print3(int [],int,int);//Print the array (Prob#3)
void  revrse3(int [],int);//Reverse the array (Prob#3)
void  init4(float [],int);//Initialize the array (Prob#4)
float avgX(float [],int);//Calculate the Average (Prob#4)
float stdX(float [],int);//Calculate the standard deviation (Prob#4)
void fillAry6(int [],int); //function used to fill array with values (Prob#6)
void prntAry6(int [],int,int); //prints the array to the user, outputs it (Prob#6)
bool linSrch6(int [],int,int,int&); //performs linear search on array for a given value (Prob#6)
void fillAry7(int [],int); //Function to fill array contents (Prob#7)
void prntAry7(int [],int,int); //Function to print array contents to screen (Prob#7)
void selSrt7(int [],int); //function that performs selection sorting (Prob#7)
bool binSrch7(int [],int,int,int&); //function  that performs binary search (Prob#7)
void fillAry8(int [],int); //Function to fill array contents (Prob#8)
void prntAry8(int [],int,int); //Function to print array contents to screen (Prob#8)
void bublSrt8(int [],int); //function that performs selection sorting (Prob#8)
bool binSrch8(int [],int,int,int&); //function  that performs binary search (Prob#8)
void print5(string); //print string contents (Prob#5)
void read5(string &,string &); //funciton to output answer key to (Prob#5)
int  compare5(string,string,string &); //function to compare strings for wrong answers (Prob#5)

//Program Execution Begins Here
int main(int argc, char** argv){
    //seed generator
    srand(static_cast<unsigned short>(time(0)));
    //Declare all Variables
    short int probNum; //User inputted value to decide problem displayed
    
    //Display Menu with problem headings
    do { //Do-While loop to display content min once and then test for continuation
        cout << "This Is A Menu For Homework Assignment 6" << endl
             << "Enter Corresponding Digit For Desired Problem." << endl
             << "\tProblem#1: Dice Table Sum" << endl
             << "\tProblem#2: Product Table" << endl
             << "\tProblem#3: Reverse Array Contents" << endl
             << "\tProblem#4: Standard Deviation" << endl
             << "\tProblem#5: Grading like a Scantron" << endl
             << "\tProblem#6: Linear Search" << endl
             << "\tProblem#7: Binary Search and Selection Sort" << endl
             << "\tProblem#8: Binary Search with Bubble Sort" << endl;
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
            default: //If anything other than integers 1-8 entered than will exit to menu
                cout << "Exiting to Menu";
        }
    }while(probNum > 0 && probNum <= 8); //Condition for continuing loop and allowing multiple problems entered      
            
    return 0; //End of main function
}

void prob1(){
    //Declare Variables
    const int ROWS=6; //Constant size declarator for rows of 2d array
    int tablSum[ROWS][COLS]; //declare int array to hold integer sums of array
    
    //Initialize or input i.e. set variable values
    fillSum(tablSum,ROWS); //Call function to fill array
    
    //Display the outputs
    cout << "Think of this as the Sum of Dice Table" << endl //header for table
         << "           C o l u m n s" << endl
         << "     |   1   2   3   4   5   6" << endl
         << "----------------------------------" << endl;
    prntTbl(tablSum,ROWS); //Print the array to user
}

void prob2(){
   //Declare Variables
    const int ROWS=6; //Constant size declarator for rows of 2d array
    int tabProd[ROWS][COLS]; //declare int array to hold integer products of array
    
    //Initialize or input i.e. set variable values
    fillMul(tabProd,ROWS); //Call function to fill array
    
    //Display the outputs
    cout << "Think of this as a Product/Muliplication Table" << endl //header for table
         << "           C o l u m n s" << endl
         << "     |   1   2   3   4   5   6" << endl
         << "----------------------------------" << endl;
    prntTbl(tabProd,ROWS); //Print the array to user
}

void prob3(){
   //Declare Variables
    const int SIZE=50; //Amount of elements in array
    int test[SIZE]; //Array to store 50 integers
    
    //Initialize or input i.e. set variable values
    cout << "Reverses Array contents" << endl;
    init3(test,SIZE); //sets values in indexes for array tests
    print3(test,SIZE,10); //displays the array test
    cout << endl;
    //Reverse the Values
    revrse3(test,SIZE); //reverses the array order
    
    //Display the outputs
    print3(test,SIZE,10); //displays the array test 
}

void prob4(){
    //Declare Variables
    const int SIZE=20;
    float test[SIZE];
    
    //Initialize or input i.e. set variable values
    init4(test,SIZE);
    
    //Display the outputs
    cout << fixed << setprecision(7);
    cout<<"The average            = "<<avgX(test,SIZE)<<endl;
    cout<<"The standard deviation = "<<stdX(test,SIZE)<<endl;
}

void prob5(){ //Had to modify this one to work, but orignial ones is on Codee with files
    //Declare Variables
    string key,answers,score = "";
    float pRight; //percentage of answers correct
    
    
    //Initialize or input i.e. set variable values
    read5(key,answers); //Read answer key and student answers from file 
    
    //Score the exam
    pRight=compare5(key,answers,score); //compare scores using function with key, answers, and score string
                                      // returns number of responses correct
    //Display the outputs
    cout << left << setw(8) << "Key";
    print5(key);
    cout << left << setw(8) << "Answers";
    print5(answers);
    cout<<"C/W     ";
    print5(score); //Function to print score
    cout<<"Percentage Correct = "<<pRight/20*100<<"%"<<endl; //prints percentage correct
}
void prob6(){
  //Declare Variables
    const int SIZE=100; // size declarator for array
    int array[SIZE]; //integer array that will hold SIZE amount
    int indx,val; //variable indx to hold position if value found, val is target value
    
    //Initialize or input i.e. set variable values
    val=50; //Initialize target value to search for
    fillAry6(array,SIZE); //fill array using function
    
    //Display the outputs
    prntAry6(array,SIZE,10); //----> This is to output array,
    if(linSrch6(array,SIZE,val,indx)) //function to perform linear search, indx rference variable to record location within function
        cout<< endl << val<<" was found at indx = "<<indx<<endl;
    else
        cout<< endl <<val<<" was not found";
}

void prob7(){
    //Declare Variables
    const int SIZE=100; //size declarator for array
    int array[SIZE]; //array with SIZE# of integers
    int indx,val; //index value where target value {val} is found
    
    //Initialize or input i.e. set variable values
    fillAry7(array,SIZE); //send argument with array name and size to fill it

    //Sorted List
    selSrt7(array,SIZE); // send to selection sort function to sort numerically ascending
    
    //Display the outputs
    prntAry7(array,SIZE,10); //print array function with 10 elements per line/row
    cout<<"\nInput the value to find in the array"<<endl; //prompt user to input target value
    cin>>val;
    
    if(binSrch7(array,SIZE,val,indx)) //send to binary search function to find value at certain index if exists
        cout<<val<<" was found at indx = "<<indx<<endl; //output index location of value
    else 
        cout<<val<<" was not found";
}

void prob8(){
    //Declare Variables
    const int SIZE=100; //size declarator for array
    int array[SIZE]; //array with SIZE# of integers
    int indx,val; //index value where target value {val} is found
    
    //Initialize or input i.e. set variable values
    fillAry8(array,SIZE); //send argument with array name and size to fill it

    //Sorted List
    bublSrt8(array,SIZE); // send to selection sort function to sort numerically ascending
    
    //Display the outputs
    prntAry8(array,SIZE,10); //print array function with 10 elements per line/row
    cout<<"\nInput the value to find in the array"<<endl; //prompt user to input target value
    cin>>val;
    if(binSrch7(array,SIZE,val,indx)) //send to binary search function to find value at certain index if exists
        cout<<val<<" was found at indx = "<<indx<<endl; //output index location of value
    else 
        cout<<val<<" was not found";
}

void fillSum(int tbl[][COLS],int ROWS){ //Array as parameter and size declarator for rows
    for(int rowIndx = 0; rowIndx < ROWS; rowIndx++)
        for(int colIndx = 0; colIndx < COLS; colIndx++)
            tbl[rowIndx][colIndx] = (rowIndx+1) + (colIndx+1); //Fill row first with columns needed with sums
}
void fillMul(int tbl[][COLS],int ROWS){ //Array as parameter and size declarator for rows
    for(int rowIndx = 0; rowIndx < ROWS; rowIndx++)
        for(int colIndx = 0; colIndx < COLS; colIndx++)
            tbl[rowIndx][colIndx] = (rowIndx+1) * (colIndx+1); //Fill row first with colums needed with product
}

void prntTbl(const int tbl[][COLS],int ROWS){
    for(int rowIndx = 0; rowIndx < ROWS; rowIndx++){
        cout << (rowIndx == 0 ? "   1 |" : //Conditions to display row contents prior to actual table
                rowIndx == 1 ? "R  2 |" :
                rowIndx == 2 ? "O  3 |" :
                rowIndx == 3 ? "W  4 |" :
                rowIndx == 4 ? "S  5 |" : "   6 |");
        for(int colIndx = 0; colIndx < COLS; colIndx++){
            cout << setw(4) << tbl[rowIndx][colIndx]; //Displays and organizes table within 4 spaces of each other
            if(colIndx == COLS-1) //new line if end of row reached, no more columns to fill within that row
                cout << endl;
        }
    }
}
void  init3(int numLst[],int size){
    for(int index = 0; index < size; index++)
        numLst[index] = (rand()%50+50); //initialize all indexes of array using for loop
}
void  print3(int numLst[],int size,int perLine){
    for(int index = 0; index < size; index++){ //print out each array element by using for loop to increment index
        cout << left << setw(3) << numLst[index]; //format to 3 spaces for output
        if (index%10 == perLine - 1) //newline if at end of 10th term
            cout << endl;
    }
}
void  revrse3(int numLst[],int size){
    for(int index = 0; index < size/2; index++){ //Swap first element with last element, only need to go half way to have swapped all
        int temp; //temporary place holder to swap
        temp = numLst[index]; //assign index value of array in loop to temp
        numLst[index] = numLst[size-index-1]; //reassign current array index to opposing one
        numLst[size-index-1] = temp; //replace other element with temp
    }
}
void  init4(float a[],int size){
    int perLine = 5;
    for(int index = 0; index < size; index++) //Initialize the array for number of elements
        a[index] = rand()%20+1;
    for(int index = 0; index < size; index++){
        cout << showpoint << fixed << setprecision(5);
        cout << setw(9) << a[index] << " ";
        if (index%5 == perLine - 1)
            cout << endl;
    }
}
float avgX(float a[],int size){
    float sum = 0, //Initialize and declare sum and avg
          avg;
    for(int index = 0; index < size; index++)
        sum += a[index]; //loop for sum of array contents
    avg = sum / size;
    return avg; //return avg that is calculated
}
float stdX(float a[],int size){
    float stdDev, //initialize sum again
          sum = 0;
    for(int index = 0; index < size; index++)
        sum += pow(a[index]-avgX(a, size), 2);
    stdDev = sqrt(sum/(size-1)); //calculate sum using std Dev
    return stdDev;
}
void fillAry6(int a[],int size){ // fill Array function
    for(int index = 0; index < size; index++) //start at index 0 and repeat for 1 less than size times, ach time input an index
        a[index] = rand()%99+1;
}
void prntAry6(int a[],int size,int perLine){ //function to print array to screen
    for(int index = 0; index < size; index++){ //loop to repeat output of array
        cout << setw(3) << a[index]; //for every iteration add a space after index term
        if(index%10 == perLine - 1) //skip a line if 10 indexes are already displayed
            cout << endl;
    }    
}
bool linSrch6(int a[],int size,int target,int& spot){ //Performs linear search on the array
    bool found = false; //Initialize bool value to false and then perform search
    for(int index = 0; index < size && found == false; index++) //for loop with 2 conditions, less than size of array and bool is false
        if(a[index] == target){ //condition to perform if index is equal to target value
            found = true, //set bool variable to true
            spot = index; //record the index location in spot
        }
    return found; //return bool value in order to dislay or not in main
}
void fillAry7(int a[],int size){
    for(int index = 0; index < size; index++) //repeat rpetition for filling array (size-1) times
        a[index] = rand()%99+1; // each time loop is iterated next element is filled
}
void prntAry7(int a[],int size,int perLine){
    for(int index = 0; index < size; index++){ //repeat same process as above to print function but output each element rather than input
        cout << setw(3) << a[index]; //output element based on lop iteration with space following it
        if(index%10 == perLine-1) // if elements per line reaches 10 skip a line
            cout << endl;
    }
}
void selSrt7(int a[],int size){
    int minVal, minIndx, //declare variables for minimum value and index 
        temp; //variable to hold values while swapping array contents
    for(int start = 0; start < size-1; start++){ //outer loop to repeat swap for each element first [0] then [1] then [2]...
        minIndx = start, //assign minimum index to loop iteration to find next smallest value
        minVal = a[start]; //minimum value is also initiaized to stat of loop element
        for(int index = start + 1; index < size; index++){ //compare starting at the following term for smallest value
            if(a[index] < minVal ){ //if index of array smaller than record index and minValue
                minIndx = index;
                minVal = a[index];
            }
        }
        temp = a[start]; //after searching whole loop swap loop iteration start element with smallest
        a[start]=a[minIndx]; //start element receives value of smallest element in loop
        a[minIndx]=temp; //previous smallest value receives start element value
    }
}
bool binSrch7(int a[],int size,int val,int& spot){ //binary search function with spot reference variable to remember index# found
    int left = 0, //Initialize to left boundary
        right = size - 1, //Initialize to right boundary
        middle; //declare midpoint
    bool found = false; //Initialize to false before searching

    while (left <= right && !found) { //condition to continue searching
        middle = (right + left) / 2;
        if (a[middle] == val) { //if middle
            found = true;
            spot = middle;
        }
        else if (val < a[middle])//if value is less that middle
            right = middle - 1;
        else //if value is greater than middle
            left = middle + 1;
        
    }
    return found; //return the bool variable after found or seach every element
}
void fillAry8(int a[],int size){
    for(int index = 0; index < size; index++) //repeat rpetition for filling array (size-1) times
        a[index] = rand()%99+1; // each time loop is iterated next element is filled
}
void prntAry8(int a[],int size,int perLine){
    for(int index = 0; index < size; index++){ //repeat same process as above to print function but output each element rather than input
        cout << setw(3) << a[index]; //output element based on lop iteration with space following it
        if(index%10 == perLine-1) // if elements per line reaches 10 skip a line
            cout << endl;
    }
}
void bublSrt8(int a[],int size){ //Bubble sort function to repeat sorting as long as swapping still occurs
    bool swap; //flag bool variable to dtermine if swapping occured
    int temp; //temporary place holder to swap element contents
    do{ //do while loop to repeat for as long as swapping occurs
        swap = false; //initialize swap variable to false before beginning of loop iteration
        for(int index = 0; index < size-1; index++) //repeat logic for element count-1
            if(a[index+1] < a[index]){ //if next index is greater then current swap
                swap = true; //set swap variable to true for loop condition
                temp = a[index+1]; //temp is assigned value of next next index
                a[index+1] = a[index]; //next index is assigned value of current index
                a[index] = temp; //current index assigned value of temp
            }
    }while(swap); //repeat for as long as swapping has occurred
}
void print5(string score){
    for(int index = 0; index < 20; index++) //Prints out score string contents with spaces in between
        cout << score[index] << " ";
    cout << endl;
}
void read5(string &result1, string &result2){
    result1 = "ABCDABCDABCCABCDABCD";
    result2 = "AACAABCDABCDABBDABCD";
}

int compare5(string answers,string key,string &score){
    int crct = 0; //initialize correct running coun to 0 before analyzing
    int size = 20; //Obtain size of both strings to know where to stop comparing
    
    for(int index = 0; index < size; index++){ //start index at 8 since thats where letter answers appear
        if(key[index]==answers[index]){ //if charcters are equal at specific instance and not spaces that increment crct
            
                score += 'C';
                crct++;
        }
        else
            score += 'W'; //otherwise write W for wrong
    }
    return crct; //return the number of crct responses made  
}