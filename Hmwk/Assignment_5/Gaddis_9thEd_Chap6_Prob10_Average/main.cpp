/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 31, 2024, 5:05 PM
 * Purpose: Drops the lowest test score from a set fo test entries
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <iomanip> //Format Library
using namespace std;

//Function Prototypes
void getScre(int &,int &,int &,int &,int &); //Function to get scores from user
float calcAvg(int,int,int,int,int); //function to calculate average score after one of them is dropped
int fndLwst(int,int,int,int,int); //function to find the lowest test score

//Program Execution Begins Here
int main(int argc, char** argv){
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
    
    //Exit the Program
    return 0;
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
