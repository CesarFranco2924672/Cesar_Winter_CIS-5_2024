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
            
            hand1 << face << " " << suit << endl; //send face and suit to file hand1
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
            
            hand2 << face << " " << suit << endl; //send face and suit to file hand2   
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
            
            hand0 << face << " " << suit << endl;   //send face and suit to file hand0 
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
                default: //Informs player of invalid entry and to reneter an option
                    cout << "Enter a valid option for YES or for NO: ";
                    cin >> choice; //choice is inputted again
            }   
        }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'); //Evaluates if condition for wile loop is met
        cout << endl << endl << endl;
        //Round 1 really begins here
        if (choice == 'Y' || choice == 'y'){ //ONE OF TWO POSSIBLE PATHS THE GAME CAN TAKE P2 THEN P1, P2 THENN P1,ETC..
            do{//Will loop continuously until either player knocks
                //Flip over middle deck and player 2 can choose
                format.open("displayTable.dat", ios :: out); //Will display the players card as well as middle side by side
                hand2.open("secondHand.dat", ios::in); //open in input mode
                hand0.open("middleHand.dat", ios::in); //open in input mode

                cout << "PLAYER 2 CARDS\t\t\tMIDDLE CARDS" << endl //Header for display table during player 2's turn
                      << "--------------\t\t\t--------------" << endl;
                for(int i=1; i<=5; i++){//Send data to format file for all 5 lines of both hands
                    string display;

                    getline(hand2, display); //display string to obtain lines for display table
                    format << left << setw(10) << display; //stores first card, char and face, in display & sends to format file
                    getline(hand0, display); //stores line from middle deck in display
                    format << "\t\t\t" << display << endl; //tab for appropriate spacing, previous setw allowed for equal spacing between strings
                }
                format.close(); //close files
                hand2.close(); //     |
                hand0.close(); //     |

                format.open("displayTable.dat", ios :: in); //Open it again to start inputting display
                while(format){ //Perform reading until no data left, all 5 lines
                    string display;
                    getline(format, display); //stores line with both decks in display
                    cout << display << endl; //Outputs under display header, shows player 2 hand as well as middle hand
                }
                format.close(); //close file for later use

                do{ //Do-while loop for input validation so that will enter a valid choice
                    cout << "Player 2's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
                    cin >> player2; //Prompt for user to determine choice mentioned above

                    if(player2=='S'||player2=='s'){ //Player decides to swap a card, not case sensitive
                        int swap2, swap0, line; //swap2 is the row in hand 2 that will be swapped, swap0 is row in hand 0 will be swapped, line informs position in reading
                        string replace; //stores string in a row
                        do{ //Loop for Input validation to perform correct logic (only 1-5 rows possible)
                        cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                        cin >> swap2 >> swap0; //Prompt and input to obtain row number of each hand that will be swapped
                        }while(swap2<1 || swap2>5 ||swap0<1 || swap0>5); //condition to repeat statement if invalid

                        hand0.open("middleHand.dat", ios::in); //open in input mode
                        hand2.open("secondHand.dat", ios::in); //      |
                        rowRep.open("replacingRows.dat", ios::out); //Open file in output mode to gather replaced rows from each deck

                        line = 1; //initialize outside while loop
                        while(getline(hand2, replace)){ //Reads lines from hand2 until no further ones available
                            rowRep << (line == swap2 ? replace : ""); //Once line is equal to the row that desires replacing, send to rowRep file
                            line++; //increment to continue reading
                        }
                        rowRep << endl; // newline so that replaced lines will be on separate lines
                        line = 1;
                        while(getline(hand0, replace)){ //perform same logic on hand0, middle deck
                            rowRep << (line == swap0 ? replace : ""); //rowRep will contain the row player 2 wants to replace first then middle row
                            line++;
                        }
                        hand0.close(); //close files for later use
                        hand2.close(); //           |
                        rowRep.close();//           |
                        
                        strge.open("temporaryStorage.dat", ios::out); //open in output mode      
                        line = 1; //initialize at hand 1
                        hand0.open("middleHand.dat", ios::in); //open in input mode
                        while(getline(hand0, replace)){ //transfers content of middle hand, hand0, except line that will be replaced.
                            if(line!=swap0)             
                                strge << replace << endl;
                            else{ //when encounters line that will be replaced gathers input from rowRep in place of hand0
                                rowRep.open("replacingRows.dat", ios::in); //popen in input mode
                                getline(rowRep,replace);
                                strge << replace << endl;
                            }    
                            line++; //increments line to continue reading until false
                        }
                        hand0.close(); //close files for later use
                        strge.close(); //          |
                        hand0.open("middleHand.dat", ios::out); //open in output mode
                        strge.open("temporaryStorage.dat", ios::in); //open in input mode
                        while(getline(strge, replace)) //hand 0 will receive the new hand with swapped line from storage file
                            hand0 << replace << endl;
                        hand0.close(); //close files
                        strge.close(); //     |

                        line = 1; //Initialize line at 1 for proper reading
                        strge.open("temporaryStorage.dat", ios::out); //open in output mode
                        hand2.open("secondHand.dat", ios::in); //open in input mode
                        while(getline(hand2, replace)){ //Similarly will store hand2 in storage file until encounters row being replaced
                            if(line!=swap2)             //in which case reads from the left off line in rowRep
                                strge << replace << endl; //                  |
                            else{                         //                  |
                                getline(rowRep,replace); //                  |
                                strge << replace << endl;
                                rowRep.close(); //closes file, 2 lines have already been read and swapped
                            }    
                            line++; //Increments line
                        }
                        hand2.close(); //closes files for later use
                        strge.close(); //         |
                        hand2.open("secondHand.dat", ios::out); //open in output mode
                        strge.open("temporaryStorage.dat", ios::in); //open in input mode
                        while(getline(strge, replace)) //hand2 file will receive new and fixed deck of cards
                            hand2 << replace << endl;
                        hand2.close(); //close files for later use
                        strge.close(); //           |
                    }
                    else if(player2=='P'||player2=='p'||player2=='K'||player2=='k')
                        cout << ""; //Do nothing for now if player chooses to knock or pass
                    else //error message for invalid input
                        cout << "Invalid character please choose a valid option.\n";
                }while(player2!='S'&&player2!='s'&&player2!='P'&&player2!='p'&&player2!='K'&&player2!='k'); //condition to repeat invaid input

                //Player 1's turn, can choose option similar to player 2
                format.open("displayTable.dat", ios :: out); //Will display player 1 cards as well as middle side by side
                hand1.open("firstHand.dat", ios::in); //open in input mode
                hand0.open("middleHand.dat", ios::in);//       |

                cout << "\n\n\nPLAYER 1 CARDS\t\t\tMIDDLE CARDS" << endl //Dispay header for player 1's turn
                      << "--------------\t\t\t--------------" << endl;   //              |
                for(int i=1; i<=5; i++){//Send data to format file
                    string display;

                    getline(hand1, display); //gather string input from hand1 and hand0 and output to format file with appropriate spacing
                    format << left << setw(10) << display;
                    getline(hand0, display);
                    format << "\t\t\t" << display << endl;
                }
                format.close(); //close files
                hand1.close();  //     |
                hand0.close();  //     |

                format.open("displayTable.dat", ios :: in); //Open it again to start inputting display
                while(format){//reads until nothing is left
                    string display;
                    getline(format, display); //outputs contents from display file
                    cout << display << endl;
                }
                format.close(); //close file

                if(player2=='K'||player2=='k') //Informs player1 that it will be his last turn since player 2 knocked
                        cout << "Last turn!!! Player 2 knocked." << endl;
                do{ //Loop for input validation to continue until valid option
                    cout << "Player 1's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
                    cin >> player1; //Prompt for player 1's turn, same options as player 2

                    if(player1=='S'||player1=='s'){
                        int swap1, swap0, line; //swap1 is line from hand1 that will be replaced, swap0 is line from hand0 that will be replaced
                        string replace;
                        do{//Repeat if player enters invalid row
                        cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                        cin >> swap1 >> swap0;
                        }while(swap1<1 || swap1>5 ||swap0<1 || swap0>5);

                        hand0.open("middleHand.dat", ios::in); //open file in input mode
                        hand1.open("firstHand.dat", ios::in); //open file in input mode
                        rowRep.open("replacingRows.dat", ios::out); //open file in output mode

                        line = 1; //initialize line at 1 
                        while(getline(hand1, replace)){ //sends line to be replaced from hand1 to row Rep
                            rowRep << (line == swap1 ? replace : "");
                            line++;
                        }
                        rowRep << endl;
                        line = 1;
                        while(getline(hand0, replace)){ //sends line to be replaced from hand0 to row Rep
                            rowRep << (line == swap0 ? replace : "");
                            line++;
                        }
                        hand0.close(); //closes file for future use
                        hand1.close(); //           |
                        rowRep.close(); //          |
                        
                        strge.open("temporaryStorage.dat", ios::out); //Open in output mode
                        line = 1;
                        hand0.open("middleHand.dat", ios::in); //open in input mode
                        while(getline(hand0, replace)){ //sends hand0 to storage file but swaps out replaced line using rowRep
                            if(line!=swap0)
                                strge << replace << endl;
                            else{
                                rowRep.open("replacingRows.dat", ios::in); //opens for input
                                getline(rowRep,replace);
                                strge << replace << endl;
                            }    
                            line++; //increments line
                        }
                        hand0.close(); //close for later use
                        strge.close(); //       |
                        hand0.open("middleHand.dat", ios::out); //open in output mode
                        strge.open("temporaryStorage.dat", ios::in); //open in input mode
                        while(getline(strge, replace))
                            hand0 << replace << endl; //Sends new and fixed line to hand0, middle hand
                        hand0.close(); //closes files
                        strge.close(); //     |

                        line = 1; //Initialize line at 1
                        strge.open("temporaryStorage.dat", ios::out); //Open in output mode
                        hand1.open("firstHand.dat", ios::in); //Opens in input mode
                        while(getline(hand1, replace)){ //sends corrected hand1 deck to storage file
                            if(line!=swap1)              //                  |
                                strge << replace << endl;//                  |
                            else{                        //                  |
                                getline(rowRep,replace); //                  |
                                strge << replace << endl;//                  |
                                rowRep.close(); //Closes files
                            }    
                            line++; //Increment line
                        }
                        hand1.close(); //close files
                        strge.close(); //     |
                        hand1.open("firstHand.dat", ios::out); //open in output mode
                        strge.open("temporaryStorage.dat", ios::in); //open in input mode
                        while(getline(strge, replace)) //send corrected deck from storage back into hand1
                            hand1 << replace << endl;        //                  |
                        hand1.close(); //Close files
                        strge.close(); //     |
                    }
                    else if (player1=='P'||player1=='p'||player1=='K'||player1=='k')
                        cout << ""; //Do nothing for now
                    else //error message for invalid input
                        cout << "Invalid character please choose a valid option.\n";        
                }while(player1!='S'&&player1!='s'&&player1!='P'&&player1!='p'&&player1!='K'&&player1!='k'); //condition to repeat initial options
                cout << endl << endl << endl;
            }while(player2!='K' && player2!='k' && player1!='K' && player1!='k');//Repeat the round if no one knocked, player2---->player1 over and over

            if (player2=='K'||player2=='k')//since round started with player2 knocking will have already informed
                cout <<"Game is Finished!";//player1 before making his move so game ends here
            else{ //player1 knocked so give player 2 one more round, player 2 will be given a chance
                //Flip over middle deck and player 2 can choose
                format.open("displayTable.dat", ios :: out); //Will display the players card as well as middle side by side
                hand2.open("secondHand.dat", ios::in);
                hand0.open("middleHand.dat", ios::in);

                cout << "PLAYER 2 CARDS\t\t\tMIDDLE CARDS" << endl     //SAME LOGIC AS ONE ABOVE for player 2!!!!!!!!!!!!!!!!!!!
                      << "--------------\t\t\t--------------" << endl;
                for(int i=1; i<=5; i++){//Send data to format file
                    string display;

                    getline(hand2, display); //Send hand2 and hand0 decks to display file with appropriate spacing
                    format << left << setw(10) << display;
                    getline(hand0, display);
                    format << "\t\t\t" << display << endl;
                }
                format.close(); //close files
                hand2.close(); //      |
                hand0.close(); //      |

                format.open("displayTable.dat", ios :: in); //Open it again to start inputting display
                while(format){
                    string display;
                    getline(format, display);
                    cout << display << endl; //Output display to player 2
                }
                format.close(); //close file

                cout << "Last turn!!!Player 1 knocked." << endl; //Informs last turn, only difference in logic
                do {//Do-while loop for input validation
                    cout << "Player 2's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
                    cin >> player2;

                    if(player2=='S'||player2=='s'){//Branching statement to determine option slected
                        int swap2, swap0, line;
                        string replace;
                        do{
                        cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                        cin >> swap2 >> swap0;
                        }while(swap2<1 || swap2>5 ||swap0<1 || swap0>5); //repeat do statement if invalid entry for rows

                        hand0.open("middleHand.dat", ios::in);//open in input mode
                        hand2.open("secondHand.dat", ios::in);//open in input mode
                        rowRep.open("replacingRows.dat", ios::out); //open in output mode

                        line = 1;
                        while(getline(hand2, replace)){             //Store replaced lines from hand2 and hand0 in rowRep file
                            rowRep << (line == swap2 ? replace : "");//                       |
                            line++;                                  //                       |
                        }                                            //                       |
                        rowRep << endl;                              //                       |
                        line = 1;                                    //                       |
                        while(getline(hand0, replace)){              //                       |
                            rowRep << (line == swap0 ? replace : "");//                       |
                            line++;                                  //                       |
                        }
                        hand0.close(); //closes files for future use
                        hand2.close(); //           |
                        rowRep.close();//           |
                        
                        strge.open("temporaryStorage.dat", ios::out); //open as output      
                        line = 1;
                        hand0.open("middleHand.dat", ios::in); //Send hand0 to storage file with replaced line using if else branch consruct
                        while(getline(hand0, replace)){                   //                         |
                            if(line!=swap0)                               //                         |
                                strge << replace << endl;                 //                         |
                            else{                                         //                         |
                                rowRep.open("replacingRows.dat", ios::in);//                         |
                                getline(rowRep,replace);                  //                         |
                                strge << replace << endl;                 //                         |
                            }                                             //                         |
                            line++;                                       //                         |
                        }
                        hand0.close(); //close files
                        strge.close();
                        hand0.open("middleHand.dat", ios::out); //open in output mode
                        strge.open("temporaryStorage.dat", ios::in); //open in input mode
                        while(getline(strge, replace)) //send the fix and row replaced deck back to hand0, middle deck
                            hand0 << replace << endl; //                         |
                        hand0.close();                //                         |
                        strge.close();                //                         |

                        line = 1;
                        strge.open("temporaryStorage.dat", ios::out); //open in output
                        hand2.open("secondHand.dat", ios::in); //pen in input
                        while(getline(hand2, replace)){ //Send the fixed and row replaced deck to storage
                            if(line!=swap2)              //                         |
                                strge << replace << endl;//                         |
                            else{                        //                         |
                                getline(rowRep,replace); //                         |
                                strge << replace << endl;//                         |
                                rowRep.close(); //closes file
                            }    
                            line++;
                        }
                        hand2.close(); //close files to reopen in appropriate mode
                        strge.close();
                        hand2.open("secondHand.dat", ios::out);
                        strge.open("temporaryStorage.dat", ios::in);
                        while(getline(strge, replace)) //Send the fixed and row replaced deck to storage
                            hand2 << replace << endl; //                         |
                        hand2.close();                //                         |
                        strge.close();                //                         |
                    }
                    else if(player2=='P'||player2=='p'||player2=='K'||player2=='k')
                        cout << ""; //Do nothing for now
                    else //error display message for invalid entry
                        cout << "Invalid character please choose a valid option.\n";
                }while(player2!='S'&&player2!='s'&&player2!='P'&&player2!='p'&&player2!='K'&&player2!='k'); //Repeat question if invalid
            cout << "\n\n\nGame is Finished!"; //End of game
            }
        }     

        //OTHER POSSIBLE PATH THE GAME CAN TAKE P1 THEN P2, P1 THEN P2,ETC.., still round 0
        if (choice == 'N' || choice == 'n'){ //If player 1 didn't want the middle deck player 2 can get it
            cout << "PLAYER 2 CARDS" << endl //Display header for player 2's cards
                 << "--------------" << endl;
            hand2.open("secondHand.dat", ios::in); //open in input mode

            for (int row=1; row<=5; row++){
                string out1; //store string sfrom hand2 to in out1 and then display to player2 his deck
                getline(hand2, out1);
                cout << out1 << endl;
            }
            hand2.close(); //close file

            cout << "\nPlayer 2, Would you like to swap your hand for the Middle one: ";
            cin >> choice; //Prompt user if he wants to swap his hand for the middle one
            do{
                switch (choice){ //switch statement to evaluate choice made
                    case 'Y':{ //player 2 decides to pick up hand that player 1 didn't want
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
                    case 'y':{ //same logic as case above, provides for lowercase entry 
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
                    case 'N': break; //do nothing if player 2 didn't want the hand
                    case 'n': break;
                    default: 
                        cout << "Enter a valid option for YES or for NO: ";
                        cin >> choice; //allows user to re-input valid option        
                }   

            }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'); //if condition true, player entered invalidly 
            cout << endl << endl << endl;

            do{ //Result will always be same starts with player 1 now, whether or not player 2 chooses middle
                //Flip over middle deck and player 1 can choose
                format.open("displayTable.dat", ios :: out); //Will display the players card as well as middle side by side
                hand1.open("firstHand.dat", ios::in);
                hand0.open("middleHand.dat", ios::in);

                cout << "PLAYER 1 CARDS\t\t\tMIDDLE CARDS" << endl //Display menu for player 1
                      << "--------------\t\t\t--------------" << endl;
                for(int i=1; i<=5; i++){//Send data to format file
                    string display;

                    getline(hand1, display); //Send player1's hand and middle hand to format file using output
                    format << left << setw(10) << display;
                    getline(hand0, display);
                    format << "\t\t\t" << display << endl;
                }
                format.close(); //close files no longer in use
                hand1.close(); //             |
                hand0.close(); //             |

                format.open("displayTable.dat", ios :: in); //Open it again to start inputting display
                while(format){
                    string display;
                    getline(format, display); //Display the lines gathered from format file using input, using cout oject
                    cout << display << endl;
                }
                format.close(); //close file

                do{ //do-while loop to repeat player 1 options if invalid entry entered
                    cout << "Player 1's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
                    cin >> player1; //Prompt for user input

                    if(player1=='S'||player1=='s'){ //if else if branching construct to use appropriate logic for user input
                        int swap1, swap0, line; //swap0 is row replaced in hand0, swap1 is row replaced in hand1
                        string replace;
                        do{
                        cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                        cin >> swap1 >> swap0; //Prompt for user input rows that will be swapped
                        }while(swap1<1 || swap1>5 ||swap0<1 || swap0>5); //repeats if invalid entry for rows inputted

                        hand0.open("middleHand.dat", ios::in); //open in input mode
                        hand1.open("firstHand.dat", ios::in); //open in input mode
                        rowRep.open("replacingRows.dat", ios::out); //open in output mode

                        line = 1; //initialize line at 1 to properly trace rows and replace accordingly
                        while(getline(hand1, replace)){
                            rowRep << (line == swap1 ? replace : ""); //ternary operator to send replaced row in hand1
                            line++;                                  // to rowRep file
                        }
                        rowRep << endl;
                        line = 1;
                        while(getline(hand0, replace)){
                            rowRep << (line == swap0 ? replace : ""); //ternary operator to send replaced row in hand0
                            line++;                                   // to rowRep file
                        }
                        hand0.close(); //close files no longer in use
                        hand1.close(); //           |
                        rowRep.close();//           |
                        
                        strge.open("temporaryStorage.dat", ios::out); //open in output mode      
                        line = 1;
                        hand0.open("middleHand.dat", ios::in); //open in  nput mode
                        while(getline(hand0, replace)){ //send hand0 to storage file but replace the special row using rowRep
                            if(line!=swap0)
                                strge << replace << endl;
                            else{
                                rowRep.open("replacingRows.dat", ios::in);
                                getline(rowRep,replace);
                                strge << replace << endl;
                            }    
                            line++; //increment line to continue reading the file until nothing left ot read
                        }
                        hand0.close(); //close files
                        strge.close(); //     |
                        hand0.open("middleHand.dat", ios::out); //open in output mode
                        strge.open("temporaryStorage.dat", ios::in); //open in input mode
                        while(getline(strge, replace)) //get all lines from storage file and send to hand0
                            hand0 << replace << endl; //fixed and row replaced middle hand
                        hand0.close(); //close files
                        strge.close();

                        line = 1;
                        strge.open("temporaryStorage.dat", ios::out); //open in output mode
                        hand1.open("firstHand.dat", ios::in); //open in input mode
                        while(getline(hand1, replace)){ //send hand1 string lines to storage file except for replaced row
                            if(line!=swap1)             //use rowRep to send special case row to storage
                                strge << replace << endl;
                            else{
                                getline(rowRep,replace);
                                strge << replace << endl;
                                rowRep.close(); //close file
                            }    
                            line++; //increment to continue reading until while statement is false
                        }
                        hand1.close(); //close files
                        strge.close(); //     |
                        hand1.open("firstHand.dat", ios::out); //open in output mode
                        strge.open("temporaryStorage.dat", ios::in); //open in input mode
                        while(getline(strge, replace))
                            hand1 << replace << endl; //sends row replaced fixed line to hand1 from storage file
                        hand1.close(); //close files
                        strge.close(); //     |
                    }
                    else if(player1=='P'||player1=='p'||player1=='K'||player1=='k')
                        cout << ""; //Do nothing for now
                    else
                        cout << "Invalid character please choose a valid option.\n";
                }while(player1!='S'&&player1!='s'&&player1!='P'&&player1!='p'&&player1!='K'&&player1!='k');

                //Player 2 can choose
                format.open("displayTable.dat", ios :: out); //Will display the player 2 card as well as middle side by side
                hand2.open("secondHand.dat", ios::in); //open as input
                hand0.open("middleHand.dat", ios::in); //      |

                cout << "\n\n\nPLAYER 2 CARDS\t\t\tMIDDLE CARDS" << endl //Display header for player 2's turn
                      << "--------------\t\t\t--------------" << endl; //player 2 cards on left and midle on right
                for(int i=1; i<=5; i++){//Send data to format file
                    string display;

                    getline(hand2, display); //Format file recieves hand2 card(face and suit) on the same line as middle
                    format << left << setw(10) << display;
                    getline(hand0, display);
                    format << "\t\t\t" << display << endl;
                }
                format.close(); //close files no longer in use and to restart reading position
                hand2.close(); //                           |
                hand0.close(); //                           |

                format.open("displayTable.dat", ios :: in); //Open it again to start inputting display
                while(format){ //will read off contents of file format line by line until nothing left to read
                    string display;
                    getline(format, display); //getline to read spaces in strings
                    cout << display << endl;
                }
                format.close(); //close file

                if(player1=='K'||player1=='k') //Inform player 2 if player1 knocked and that it is their last turn
                        cout << "Last turn!!! Player 1 knocked." << endl;
                do{//loop construct for input validation
                    cout << "Player 2's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
                    cin >> player2; //Prompt for player2 input 


                    if(player2=='S'||player2=='s'){ //if player 2 decides to swap perform same logic as seen previously
                        int swap2, swap0, line; //swap2 is line swapped hand2 and line 0 is line swapped from hand0, line is reading position
                        string replace;
                        do{
                        cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                        cin >> swap2 >> swap0; //Prompt user for valid input for rows, if invalid loop and ask again
                        }while(swap2<1 || swap2>5 ||swap0<1 || swap0>5);

                        hand0.open("middleHand.dat", ios::in); //open as input
                        hand2.open("secondHand.dat", ios::in); //open as input
                        rowRep.open("replacingRows.dat", ios::out); //open as output

                        line = 1;
                        while(getline(hand2, replace)){//outputs line being replaced in hand2 to rowRep
                            rowRep << (line == swap2 ? replace : "");
                            line++;
                        }
                        rowRep << endl;
                        line = 1;
                        while(getline(hand0, replace)){//outputs line being replaced in hand0 to rowRep
                            rowRep << (line == swap0 ? replace : "");
                            line++;
                        }
                        hand0.close(); //closes files for later use
                        hand2.close(); //          |
                        rowRep.close(); //         |
                        
                        strge.open("temporaryStorage.dat", ios::out); //open in output mode     
                        line = 1;
                        hand0.open("middleHand.dat", ios::in);
                        while(getline(hand0, replace)){ //send hand0 contents to storage file except for replaced row,
                            if(line!=swap0)            // that one will be obtained through rowRep
                                strge << replace << endl;
                            else{
                                rowRep.open("replacingRows.dat", ios::in);
                                getline(rowRep,replace);
                                strge << replace << endl;
                            }    
                            line++;
                        }
                        hand0.close(); //close files to reopen in appropriate reading position
                        strge.close();
                        hand0.open("middleHand.dat", ios::out);
                        strge.open("temporaryStorage.dat", ios::in);
                        while(getline(strge, replace)) //Send storage contents which contain fixed hand to hand0
                            hand0 << replace << endl;
                        hand0.close(); //close files
                        strge.close(); //     |

                        line = 1;
                        strge.open("temporaryStorage.dat", ios::out); 
                        hand2.open("secondHand.dat", ios::in);
                        while(getline(hand2, replace)){ //Likewise send hand2 contents to storage with replaced line left in previous reading position
                            if(line!=swap2)
                                strge << replace << endl;
                            else{
                                getline(rowRep,replace);
                                strge << replace << endl;
                                rowRep.close(); //close file as both replaced lines have been read
                            }    
                            line++; //increment line to maintain reading position
                        }
                        hand2.close();
                        strge.close();
                        hand2.open("secondHand.dat", ios::out);
                        strge.open("temporaryStorage.dat", ios::in);
                        while(getline(strge, replace)) //send storage file contents with replaced line back to hand2
                            hand2 << replace << endl;
                        hand2.close();
                        strge.close();
                    }
                    else if (player2=='P'||player2=='p'||player2=='K'||player2=='k')
                        cout << ""; //Do nothing for now
                    else
                        cout << "Invalid character please choose a valid option.\n";        
                }while(player2!='S'&&player2!='s'&&player2!='P'&&player2!='p'&&player2!='K'&&player2!='k'); //repeat if invalid option entered
                cout << endl << endl << endl;

            }while(player1!='K'&&player1!='k' && player2!='K' && player2!='k');//keep looping turns unless someone knocked

            if (player1=='K'||player1=='k')//Since player1 started first, if he knocks it will simply inform player2 as he follows
                cout <<"Game is Finished!";
            else{ //player2 knocked so give player 1 one more round
                //Flip over middle deck and player 2 can choose
                format.open("displayTable.dat", ios :: out); //Will display the players card as well as middle side by side
                hand1.open("firstHand.dat", ios::in);
                hand0.open("middleHand.dat", ios::in);

                cout << "PLAYER 1 CARDS\t\t\tMIDDLE CARDS" << endl
                      << "--------------\t\t\t--------------" << endl;
                for(int i=1; i<=5; i++){//Send data to format file
                    string display;

                    getline(hand1, display);
                    format << left << setw(10) << display;
                    getline(hand0, display);
                    format << "\t\t\t" << display << endl;
                }
                format.close();
                hand1.close();
                hand0.close();

                format.open("displayTable.dat", ios :: in); //Open it again to start inputting display
                while(format){
                    string display;
                    getline(format, display);
                    cout << display << endl;
                }
                format.close();

                cout << "Last turn!!!Player 2 knocked." << endl; //Inform player that it is his lst turnsince player1 kncoked
                do {        
                    cout << "Player 1's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
                    cin >> player1; //Prompt for user input

                    if(player1=='S'||player1=='s'){
                        int swap1, swap0, line;
                        string replace;
                        do{
                        cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                        cin >> swap1 >> swap0; //promp for user input to replace desired rows
                        }while(swap1<1 || swap1>5 ||swap0<1 || swap0>5);

                        hand0.open("middleHand.dat", ios::in); //open in input mode
                        hand1.open("firstHand.dat", ios::in); //open in input mode
                        rowRep.open("replacingRows.dat", ios::out); //open in output mode

                        line = 1;
                        while(getline(hand1, replace)){ //send replaced line in hand1 to rowRep file
                            rowRep << (line == swap1 ? replace : "");
                            line++;
                        }
                        rowRep << endl;
                        line = 1;
                        while(getline(hand0, replace)){//send replaced line in hand0 to rowRep file
                            rowRep << (line == swap0 ? replace : "");
                            line++;
                        }
                        hand0.close(); //close files to reopen in different modes
                        hand1.close(); //               |
                        rowRep.close();//               |
                        
                        strge.open("temporaryStorage.dat", ios::out);        
                        line = 1;
                        hand0.open("middleHand.dat", ios::in);
                        while(getline(hand0, replace)){ //send hand0 contents to storage but with repaired line which was swapped
                            if(line!=swap0)
                                strge << replace << endl;
                            else{
                                rowRep.open("replacingRows.dat", ios::in);
                                getline(rowRep,replace); //will only send line in one instance
                                strge << replace << endl;
                            }    
                            line++;
                        }
                        hand0.close();
                        strge.close();
                        hand0.open("middleHand.dat", ios::out);
                        strge.open("temporaryStorage.dat", ios::in);
                        while(getline(strge, replace))
                            hand0 << replace << endl; //send back deck of cards ot hand0, the middle
                        hand0.close();
                        strge.close();

                        line = 1; //re-initialize to read and repair hand1 with appropriate line
                        strge.open("temporaryStorage.dat", ios::out); 
                        hand1.open("firstHand.dat", ios::in);
                        while(getline(hand1, replace)){
                            if(line!=swap1) //send contents of hand1 to storage with replaced line
                                strge << replace << endl;
                            else{
                                getline(rowRep,replace);
                                strge << replace << endl;
                                rowRep.close();
                            }    
                            line++; //increment o maintain proper replacement
                        }
                        hand1.close();
                        strge.close();
                        hand1.open("firstHand.dat", ios::out);
                        strge.open("temporaryStorage.dat", ios::in);
                        while(getline(strge, replace))//send repaired and row replaced ine back to hand1
                            hand1 << replace << endl;
                        hand1.close();
                        strge.close();
                    }
                    else if(player1=='P'||player1=='p'||player1=='K'||player1=='k')
                        cout << ""; //Do nothing game is over
                    else
                        cout << "Invalid character please choose a valid option.\n";
                }while(player1!='S'&&player1!='s'&&player1!='P'&&player1!='p'&&player1!='K'&&player1!='k'); //loop to enter valid input
            cout << "\n\n\nGame is Finished!";   
            }

        }
    //Exit the Program
    return 0;
}