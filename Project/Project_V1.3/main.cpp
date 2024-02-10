/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 23, 2024, 2:53 PM
 * Purpose: Game Project for CIS-5
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <fstream> //File Library, for input & output
#include <ctime> //Time file to use system clock
#include <cstdlib> //To use random number generator
#include <iomanip>
#include <string>
using namespace std;

//Program Execution Begins Here
int main(int argc, char** argv){
    //Set a random seed
    srand(time(0));
    //Declare all Variables
    fstream hand0, //Middle table hand result
            hand1, //First player hand result
            hand2, //Second player hand result
            strge, //Temporary storage for full set of cards
            rowRep, //Stores lines that will be replaced
            format; //Format to the player
   
    string suit; //Suit: Diamonds, Hearts, Spades, Clubs
    char face, //Type of card from Aces up to Kings
         choice,
         player1,
         player2;
             
    //Initialize file parameter and open
    hand1.open("firstHand.dat", ios::out);
    hand2.open("secondHand.dat", ios::out);
    hand0.open("middleHand.dat", ios::out);
    
    
    
    if(hand1){
        for(int i=1; i<=5; i++){
            int tempF = rand()%13+1; //Card number temporarily before conversion
            face = tempF==1  ? 'A'  :
                   tempF==2  ? '2'  :
                   tempF==3  ? '3'  :
                   tempF==4  ? '4'  :
                   tempF==5  ? '5'  :
                   tempF==6  ? '6'  :
                   tempF==7  ? '7'  :
                   tempF==8  ? '8'  :
                   tempF==9  ? '9'  :
                   tempF==10 ? 'T' :
                   tempF==11 ? 'J'  :
                   tempF==12 ? 'Q'  : 'K';
            
            int tempS = rand()%4+1; //Card suit random generator 1-4
            suit = tempS==1 ? "Diamonds" :
                   tempS==2 ?  "Hearts"  :
                   tempS==3 ?  "Spades"  : "Clubs";
            
            hand1 << face << " " << suit << endl;
        }   
        hand1.close();
    }
    else{
        cout << "Failed to deal First hand";
        return 0;       
    }
    
    if(hand2){
        int i=1;
        do{
           int tempF = rand()%13+1; //Card number temporarily before conversion
           face = tempF==1  ? 'A'  :
                  tempF==2  ? '2'  :
                  tempF==3  ? '3'  :
                  tempF==4  ? '4'  :
                  tempF==5  ? '5'  :
                  tempF==6  ? '6'  :
                  tempF==7  ? '7'  :
                  tempF==8  ? '8'  :
                  tempF==9  ? '9'  :
                  tempF==10 ? 'T'  :
                  tempF==11 ? 'J'  :
                  tempF==12 ? 'Q'  : 'K';
            
            int tempS = rand()%4+1; //Card suit random generator 1-4
            suit = tempS==1 ? "Diamonds" :
                   tempS==2 ?  "Hearts"  :
                   tempS==3 ?  "Spades"  : "Clubs";
            
            hand2 << face << " " << suit << endl;    
            i++;
        }while(i<=5);
        hand2.close();
        
    }
    else{
        cout << "Failed to deal Second hand";
        return 0;       
    }
    
    if(hand0){
        int i=1;
        while(i<=5){
            int tempF = rand()%13+1; //Card number temporarily before conversion
            face = tempF==1  ? 'A'  :
                   tempF==2  ? '2'  :
                   tempF==3  ? '3'  :
                   tempF==4  ? '4'  :
                   tempF==5  ? '5'  :
                   tempF==6  ? '6'  :
                   tempF==7  ? '7'  :
                   tempF==8  ? '8'  :
                   tempF==9  ? '9'  :
                   tempF==10 ? 'T' :
                   tempF==11 ? 'J'  :
                   tempF==12 ? 'Q'  : 'K';
            
            int tempS = rand()%4+1; //Card suit random generator 1-4
            suit = tempS==1 ? "Diamonds" :
                   tempS==2 ?  "Hearts"  :
                   tempS==3 ?  "Spades"  : "Clubs";
            
            hand0 << face << " " << suit << endl;    
            i++;
        }
        hand0.close();
    }
    else{
        cout << "Failed to deal Middle hand";
        return 0;       
    }
    
    //Round 0
    cout << "PLAYER 1 CARDS" << endl
          << "--------------" << endl;
    hand1.open("firstHand.dat", ios::in);
    for (int row=1; row<=5; row++){
        string out1;
        getline(hand1, out1);
        cout << out1 << endl;
    }
    hand1.close();
    
    //Ask player 1 if swap
    cout << "\nPlayer 1, Would you like to swap your hand for the Middle one: ";
        cin >> choice; //After showing player 1 his hand ask if he would like to swap for middle
                       //Player does not know contents of middle hand, only his
        do{ //Do-While loop to repeat task if invalid choice is entered
            switch (choice){ //Switch loop to evaluate entries, break statement to noly perform one
                case 'Y':{ //Player1 decides to swap
                    string replace; //string named replace to obtain line from file that wants to get replaced
                    //Store hand 1 in storage file
                    hand1.open("firstHand.dat", ios::in); //open in input mode
                    strge.open("temporaryStorage.dat", ios::out); //open in output mode
                    while(getline(hand1,replace)){//while function on file used this time rather than for loop 
                        strge << replace << endl; //to continue reading until end(5th line)
                    }
                    hand1.close(); //Closes files for later use
                    strge.close(); //           |

                    //Send hand 0 to hand 1
                    hand0.open("middleHand.dat", ios::in); //Open in input mode
                    hand1.open("firstHand.dat", ios::out); //open in output mode
                    while(getline(hand0,replace)){ //while loop to read entire content
                        hand1 << replace << endl; //sends lines(1-5) from middle deck to player1 deck
                    }
                    hand0.close(); //closes files for later use
                    hand1.close(); //             |

                    //send storage hand to hand 0
                    strge.open("temporaryStorage.dat", ios::in); //input mode
                    hand0.open("middleHand.dat", ios::out); //output mode
                    while(getline(strge,replace)){ //reads entire content of strge file
                        hand0 << replace << endl; //replace string is sent to hand 0
                    } //this ends the transfer from hand1(player1)--->hand0(middle) & hand0---->hand1
                    strge.close(); //Closes files for future use
                    hand0.close(); //            |
                    break;
                }
                case 'y':{          // Same result/logic as case 'Y', allows for upper and lowercase entries
                    string replace;                              //    |
                    //Store hand 1 in storage file               //    |
                    hand1.open("firstHand.dat", ios::in);        //    |
                    strge.open("temporaryStorage.dat", ios::out);//    |
                    while(getline(hand1,replace)){               //    |
                        strge << replace << endl;                //    |
                    }                                            //    |
                    hand1.close();                               //    |
                    strge.close();                               //    |
                                                                 //    |
                    //Send hand 0 to hand 1                            |
                    hand0.open("middleHand.dat", ios::in);       //    |
                    hand1.open("firstHand.dat", ios::out);       //    |
                    while(getline(hand0,replace)){               //    |
                        hand1 << replace << endl;                //    |
                    }                                            //    |
                    hand0.close();                               //    |
                    hand1.close();                               //    |
                                                                 //    |
                    //send storage hand to hand 0                      |
                    strge.open("temporaryStorage.dat", ios::in); //    |
                    hand0.open("middleHand.dat", ios::out);      //    |
                    while(getline(strge,replace)){               //    |
                        hand0 << replace << endl;                //    |
                    }                                            //    |
                    strge.close();                               //    |
                    hand0.close();                               //    |
                    break;
                }
                case 'N': break; //If player1 doesn't decide to swap cards do nothing
                case 'n': break; //                    |
                default: //Informs player of invalid entry and to re enter an option
                    cout << "Enter a valid option for YES or for NO: ";
                    cin >> choice; //choice is inputted again
            }   
        }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'); //Evaluates if condition for wile loop is met
        cout << endl << endl << endl;
    
    if (choice == 'Y' || choice == 'y'){ //Flip over middle deck and player 2 can choose
        format.open("displayTable.dat", ios :: out); //Will display the players card as well as middle side by side
        hand2.open("secondHand.dat", ios::in);
        hand0.open("middleHand.dat", ios::in);
        
        cout << "PLAYER 2 CARDS\t\t\tMIDDLE CARDS" << endl //display table for player 2 to choose option for turn
              << "--------------\t\t\t--------------" << endl;
        for(int i=1; i<=5; i++){//Send data to format file
            string display;
            
            getline(hand2, display);
            format << left << setw(10) << display;
            getline(hand0, display);
            format << "\t\t\t" << display << endl;
        }
        format.close();
        hand2.close();
        hand0.close();
        
        format.open("displayTable.dat", ios :: in); //Open it again to start inputting display
        while(format){
            string display;
            getline(format, display);
            cout << display << endl;
        }
        cout << "Player 2's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
        cin >> player2;
        
        if(player2=='s'){
            int swap2, swap0, line;
            string replace;
            cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
            cin >> swap2 >> swap0;
            
            hand0.open("middleHand.dat", ios::in);
            hand2.open("secondHand.dat", ios::in);
            strge.open("temporaryStorage.dat", ios::out);
            rowRep.open("replacingRows.dat", ios::out);
            
            line = 1;
            while(getline(hand2, replace)){
                rowRep << (line == swap2 ? replace : "");
                line++;
            }
            rowRep << endl;
            line = 1;
            while(getline(hand0, replace)){
                rowRep << (line == swap0 ? replace : "");
                line++;
            }
            rowRep.close();
            hand0.close();
            hand2.close();
                    
            line = 1;
            hand0.open("middleHand.dat", ios::in);
            while(getline(hand0, replace)){
                if(line!=swap0)
                    strge << replace << endl;
                else{
                    rowRep.open("replacingRows.dat", ios::in);
                    getline(rowRep,replace);
                    strge << replace << endl;
                }    
                line++;
            }
            hand0.close();
            strge.close();
            hand0.open("middleHand.dat", ios::out);
            strge.open("temporaryStorage.dat", ios::in);
            
            while(getline(strge, replace))
                hand0 << replace << endl;
            
                    
        }            
    }
    
    if (choice == 'N' || choice == 'n'){ //If player 1 didn't want the middle deck player 2 can get it
        cout << "PLAYER 2 CARDS" << endl
             << "--------------" << endl;
        hand2.open("secondHand.dat", ios::in);
        
        for (int row=1; row<=7; row++){
            string out1;
            getline(hand2, out1);
            cout << out1 << endl;
        }
        hand2.close();

        //Ask if swap
        cout << "\nPlayer 2, Would you like to swap your hand for the Middle one: ";
        cin >> choice;

        do{
            switch (choice){
                case 'Y':{
                    string replace;
                    //Store hand 2 in storage file
                    hand2.open("secondHand.dat", ios::in);
                    strge.open("temporaryStorage.dat", ios::out);
                    while(getline(hand2,replace)){
                        strge << replace << endl;
                    }
                    hand2.close();
                    strge.close();

                    //Send hand 0 to hand 2
                    hand0.open("middleHand.dat", ios::in);
                    hand2.open("secondHand.dat", ios::out);
                    while(getline(hand0,replace)){
                        hand2 << replace << endl;
                    }
                    hand0.close();
                    hand2.close();

                    //send storage hand to hand 0
                    strge.open("temporaryStorage.dat", ios::in);
                    hand0.open("middleHand.dat", ios::out);
                    while(getline(strge,replace)){
                        hand0 << replace << endl;
                    }
                    strge.close();
                    hand0.close();
                    break;
                }
                case 'y':{
                    string replace;
                    //Store hand 2 in storage file
                    hand2.open("secondHand.dat", ios::in);
                    strge.open("temporaryStorage.dat", ios::out);
                    while(getline(hand2,replace)){
                        strge << replace << endl;
                    }
                    hand2.close();
                    strge.close();

                    //Send hand 0 to hand 1
                    hand0.open("middleHand.dat", ios::in);
                    hand2.open("secondHand.dat", ios::out);
                    while(getline(hand0,replace)){
                        hand2 << replace << endl;
                    }
                    hand0.close();
                    hand2.close();

                    //send storage hand to hand 0
                    strge.open("temporaryStorage.dat", ios::in);
                    hand0.open("middleHand.dat", ios::out);
                    while(getline(strge,replace)){
                        hand0 << replace << endl;
                    }
                    strge.close();
                    hand0.close();
                    break;
                }
                case 'N': break;
                case 'n': break;
                default: 
                    cout << "Enter a valid option for YES or for NO: ";
                    cin >> choice;        
            }   

        }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
    }
    
    
    //Process or Map Solutions
    
    //Display the Output
    
    //Exit the Program
    return 0;
}

