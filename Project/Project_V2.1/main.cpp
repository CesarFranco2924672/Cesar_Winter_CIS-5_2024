/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on February 5, 2024, 2:53 PM
 * Purpose: Game Project for CIS-5
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <iomanip> //Format Library
#include <cmath> //Math Library
#include <cstdlib> //To use random number generator
#include <fstream> //File Library, for input & output
#include <string> //String Library
#include <ctime> //Time file to use system clock
#include <vector> //STL Vector Library

using namespace std;

//Function Prototypes
void dealt(int [], const int, vector<int>&);//Function to deal integer hand(1-52) to player array, const is size of array, vector records unique values
void convert(int[], const int, fstream&, string);//takes in player array hand, file identifier & file name.Converts numerical hand into card equivalent,stored in file
int unique(vector<int>&);//function to store previously occurred numbers for 1-52, repeats random# until unique and returns it to dealt(stores all unique numbers in vector)

//Program Execution Begins Here
int main(int argc, char** argv){
    //Set a random seed
    srand(static_cast<unsigned short>(time(0)));//seed random number generator
    //Declare all Variables
    const unsigned short SIZE = 5;//max size of 1D arrays, or max row for 2D array
    int play1[SIZE], //Number values of hand 1-52
        play2[SIZE],        
        play0[SIZE];   
    vector<int> allCard; //Records all numerical values(1-52)of all 15 cards dealt 
    string fleNme1 = "player1Hand.dat", //Name for player files and middle file
           fleNme2 = "player2Hand.dat",
           fleNme0 = "middleHand.dat";
    //Declare files
    fstream hand1, //files to hold player hands and middle
            hand2,
            hand0;
             
    //Deal first hand into array play1
    dealt(play1, SIZE, allCard);//function to deal numerical cards to player1
    for(int index = 0; index < SIZE; index++){ //outputs numerical value for all 5 cards of player1
        cout << play1[index] << endl;
    }
    convert(play1, SIZE, hand1, fleNme1);//function to convert numerical value into corresponding face & suit, will store in file
    hand1.open(fleNme1, ios::in);
    string display;
    while(getline(hand1, display))//displays contents of file1 which will be actual cards with face and suit
        cout << display << endl;
    hand1.close(); 
    cout << endl;
    
    //Deal second hand into array play2
    dealt(play2, SIZE, allCard);//function to deal numerical cards to player2
    for(int index = 0; index < SIZE; index++){ //outputs numerical value for all 5 cards of player2
        cout << play2[index] << endl;
    }
    convert(play2, SIZE, hand2, fleNme2);//function to convert numerical value into corresponding face & suit, will store in file
    hand2.open(fleNme2, ios::in);
    while(getline(hand2, display))//displays contents of file2 which will be actual cards with face and suit
        cout << display << endl;
    hand2.close();  
    cout << endl;
    
    //Deal middle hand into array play0
    dealt(play0, SIZE, allCard);//function to deal numerical cards to middle   
    for(int index = 0; index < SIZE; index++){ //outputs numerical value for all 5 cards of middle
        cout << play0[index] << endl;
    }
    convert(play0, SIZE, hand0, fleNme0);//function to convert numerical value into corresponding face & suit, will store in file
    hand0.open(fleNme0, ios::in);
    while(getline(hand0, display))//displays contents of file0 which will be actual cards with face and suit
        cout << display << endl;
    hand0.close();    
    
    
            
    //Process or Map Solutions
    
    //Display the Output
    
    //Exit the Program
    return 0;
}
void dealt(int player[], const int size, vector<int>& allCard){
    for(int index = 0; index < size; index++){ //repeat 5 times(is size) for hand
        player[index] = unique(allCard); //store value in corresponding index after being returned from unique
    }
}
int unique(vector<int>& allCard){
    const unsigned short deckSze = 52; //constant number of cards in a single deck
    unsigned short cardNum; //will store card number (1-52)
    bool found; //flag to repeat number generator if card number is a duplicate
    do{
        found = false; //initialize bool flag to false before searching
        cardNum = rand()%deckSze+1; //acquire random number within range (1-52)
        for(int index = 0; index < allCard.size(); index++){//search loop for as many elements that are within the vector, initially zero at very start
            if(allCard[index] == cardNum)
                found = true; //modify bool flag to true since duplicate was found        
        }        
    }while(found); //condition to repeat if a duplicate was found otherwise exit
    allCard.push_back(cardNum); //once value is unique store it in vector using push back function, will be used to search subsequent times
    return cardNum; //return the unique card number to the corresponding element of the player array in dealt()
}
void convert(int a[], const int size, fstream& hand, string fleNme){
    string suit; //string variable to hold suit of card (Diamonds, Clubs, etc...)
    char face; //char variable to hold face value of card ('A', '5', 'T',...)
    hand.open(fleNme, ios::out); //open the player's files to output to it its face followed by string
    for(int index = 0; index < size; index++){ //Loop to continue for all 5 elements of player integer array
        suit = (a[index] >= 1  && a[index] <=13) ? "Diamonds" : //conditional operator to assign suit based on numerical value(split into sections of 13's)
               (a[index] >= 14 && a[index] <=26) ? "Hearts" :
               (a[index] >= 27 && a[index] <=39) ? "Spades" : "Clubs";

        face = a[index]== 1 || a[index]==14 || a[index]==27 || a[index]==40 ? 'A' : //ternary operator to determine appropriate face(every other 13 cards repeat)
               a[index]== 2 || a[index]==15 || a[index]==28 || a[index]==41 ? '2' : //                    |
               a[index]== 3 || a[index]==16 || a[index]==29 || a[index]==42 ? '3' : //                    |
               a[index]== 4 || a[index]==17 || a[index]==30 || a[index]==43 ? '4' : //                    |
               a[index]== 5 || a[index]==18 || a[index]==31 || a[index]==44 ? '5' : //                    |
               a[index]== 6 || a[index]==19 || a[index]==32 || a[index]==45 ? '6' : //                    |
               a[index]== 7 || a[index]==20 || a[index]==33 || a[index]==46 ? '7' : //                    |
               a[index]== 8 || a[index]==21 || a[index]==34 || a[index]==47 ? '8' : //                    |
               a[index]== 9 || a[index]==22 || a[index]==35 || a[index]==48 ? '9' : //                    |
               a[index]==10 || a[index]==23 || a[index]==36 || a[index]==49 ? 'T' : //                    |
               a[index]==11 || a[index]==24 || a[index]==37 || a[index]==50 ? 'J' : //                    |
               a[index]==12 || a[index]==25 || a[index]==38 || a[index]==51 ? 'Q' : 'K'; 
        hand << face << " " << suit << endl; //output to file line the face followed by suit, newline for next card
    }    
    hand.close(); //close file hand      
}
