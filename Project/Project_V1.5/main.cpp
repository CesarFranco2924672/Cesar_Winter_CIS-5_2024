/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 23, 2024, 2:53 PM
 * Purpose: Game Project for CIS-5
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <fstream> //File Library, for input & output
#include <ctime> //Time file to use system clock fro rand()
#include <cstdlib> //To use random number generator
#include <iomanip> //Format Library
#include <string> //String Library
#include <cmath> //Math Library

using namespace std;

//Program Execution Begins Here
int main(int argc, char** argv){
    //Set a random seed
    srand(static_cast<unsigned short>(time(0)));
    //Declare all Variables
    const int numCard = 52; //52 cards in a deck
    float winRte1, //Player win rate
          winRte2,
          dev1,
          dev2,
          sum, mean;
    fstream hand0, //Middle table hand file, stores cards
            hand1, //First player hand file
            hand2, //Second player hand file
            strge, //Temporary storage for full hand(5) of cards
            rowRep, //Stores lines that will be replaced
            format, //Format to the player their cards and middle cards
            stdDev1,
            stdDev2;
   
    string suit, //Suit: Diamonds, Hearts, Spades, Clubs
           suit1, suit2, suit3, suit4, suit5,
           result1, //Player 1 final hand, (poker, flush, etc...)
           result2; //PLayer 2 final hand
            
    char face, //Temp face holder when transferring from files
         choice, //Decision if player wants middle deck, also to continue game (Y,y,N,n)
         player1, //Player options in game for pass, knock, switch (P,p,K,k,S,s)
         player2,
         face1, face2, face3, face4, face5; //faces of dealt hand
    unsigned short num1,     num6,      num11, //Type of card from Aces up to Kings(int representative)
                   num2,     num7,      num12, //15 variable ints to maintain unique card pulls
                   num3,     num8,      num13, //by comparing their values
                   num4,     num9,      num14,
                   num5,     num10,     num15,
                   temp, score1, score2, //temp number used as place holder, score ranks hand type 1--> best 10-->worst
                   gameCt, //Amount of games played
                   wins1, wins2; //Amount of wins attained by player 1 and 2 respectively
    bool onePair;
                   
    
    //Initialize variables
    gameCt=0, wins1=0, wins2=0; //running count starts at 0
    stdDev1.open("p1Deviation.dat",ios::out); //Clear file contents before so can properly account standard deviation
    stdDev1.close();
    stdDev2.open("p2Deviation.dat",ios::out); //Clear file contents before so can properly account standard deviation
    stdDev2.close();
    
    //Do Loop to Re-run entire game if player chooses to
    do{
        hand1.open("firstHand.dat", ios::out); //Open files in output mode to send
        hand2.open("secondHand.dat", ios::out); // dealt cards to each
        hand0.open("middleHand.dat", ios::out);

        if(hand1){ //CARDS 1-5, if statement to test if file opens successfully
            //Unique cards
            num1 = rand()%numCard+1; //Random number modded by max # of cards in a deck +1 for [1-52]
            do{
                num2 = rand()%numCard+1;
            }while(num1==num2); //Repeats if first 2 numbers are the same

            do{
                num3 = rand()%numCard+1;
            }while(num3==num1||num3==num2); //repeats if third number is duplicate

            do{
                num4 = rand()%numCard+1;
            }while(num4==num1||num4==num2||num4==num3); //repeats if fourth number is duplicate

            do{
                num5 = rand()%numCard+1;
            }while(num5==num1||num5==num2||num5==num3||num5==num4); //repeats if fifth number is duplicate

            strge.open("temporaryStorage.dat", ios::out);
            strge << num1 << endl //Sends all 5 integer values to storage file 
                  << num2 << endl //which will kind of be used similar as function to 
                  << num3 << endl //output in loop and assign face
                  << num4 << endl
                  << num5;
            strge.close(); //close file to start from beginning
            strge.open("temporaryStorage.dat", ios::in); //open file in input mode

            //Card type based on number
            for(int i=1;i<=5;i++){ //loop that reads in all 5 lines and converts to face
                strge>>temp; //temp is assigned the ith term
                face = temp== 1 || temp==14 || temp==27 || temp==40 ? 'A' : //ternary operator to determine appropriate face
                       temp== 2 || temp==15 || temp==28 || temp==41 ? '2' : //                    |
                       temp== 3 || temp==16 || temp==29 || temp==42 ? '3' : //                    |
                       temp== 4 || temp==17 || temp==30 || temp==43 ? '4' : //                    |
                       temp== 5 || temp==18 || temp==31 || temp==44 ? '5' : //                    |
                       temp== 6 || temp==19 || temp==32 || temp==45 ? '6' : //                    |
                       temp== 7 || temp==20 || temp==33 || temp==46 ? '7' : //                    |
                       temp== 8 || temp==21 || temp==34 || temp==47 ? '8' : //                    |
                       temp== 9 || temp==22 || temp==35 || temp==48 ? '9' : //                    |
                       temp==10 || temp==23 || temp==36 || temp==49 ? 'T' : //                    |
                       temp==11 || temp==24 || temp==37 || temp==50 ? 'J' : //                    |
                       temp==12 || temp==25 || temp==38 || temp==51 ? 'Q' : 'K'; 

                suit = temp>= 1 && temp<=13 ? "Diamonds" : //determines each suit for the ith row card
                       temp>=14 && temp<=26 ?  "Hearts"  : //each suit corresponds to 13 cards
                       temp>=27 && temp<=39 ?  "Spades"  : "Clubs";

                hand1 << face << " " << suit << endl; //outputs to file hand1 with face followed by the string suit
            }
            strge.close(); //closes files for later use
            hand1.close(); //          |
        }
        else{ //Flag that ends the program if hand1 file couldn't be open, since hand would not be dealt
            cout << "Failed to deal First hand";
            return 1; //returns error indicating failed run
        }

        if(hand2){ //CARDS 6-10, deals hand 2 to player 2, tests if open successful
            //Unique cards
            do{ //Again do-while loops to compare integer value of cards and prevent duplicates
                num6 = rand()%numCard+1;
            }while(num6==num1||num6==num2||num6==num3||num6==num4||num6==num5);
            do{
                num7 = rand()%numCard+1;
            }while(num7==num1||num7==num2||num7==num3||num7==num4||num7==num5||num7==num6);
            //Compares all cards to previous cards also in hand 1
            do{
                num8 = rand()%numCard+1;
            }while(num8==num1||num8==num2||num8==num3||num8==num4||num8==num5||num8==num6||num8==num7);

            do{
                num9 = rand()%numCard+1;
            }while(num9==num1||num9==num2||num9==num3||num9==num4||num9==num5||num9==num6||num9==num7||num9==num8);

            do{
                num10 = rand()%numCard+1;
            }while(num10==num1||num10==num2||num10==num3||num10==num4||num10==num5||num10==num6||num10==num7||num10==num8||num10==num9);

            strge.open("temporaryStorage.dat", ios::out); //Open storage file in output mode
            strge << num6 << endl //send integer corresponding values for face to file
                  << num7 << endl
                  << num8 << endl
                  << num9 << endl
                  << num10;
            strge.close(); //close file
            strge.open("temporaryStorage.dat", ios::in); //reopen in input mode for evaluation of card type

            //Card type based on number
            for(int i=1;i<=5;i++){//repeats for all five row of the file
                strge>>temp;
                face = temp== 1 || temp==14 || temp==27 || temp==40 ? 'A' : //Ternary operator to determine suit and face type
                       temp== 2 || temp==15 || temp==28 || temp==41 ? '2' : //                    |
                       temp== 3 || temp==16 || temp==29 || temp==42 ? '3' : //                    |
                       temp== 4 || temp==17 || temp==30 || temp==43 ? '4' : //                    |
                       temp== 5 || temp==18 || temp==31 || temp==44 ? '5' : //                    |
                       temp== 6 || temp==19 || temp==32 || temp==45 ? '6' : //                    |
                       temp== 7 || temp==20 || temp==33 || temp==46 ? '7' : //                    |
                       temp== 8 || temp==21 || temp==34 || temp==47 ? '8' : //                    |
                       temp== 9 || temp==22 || temp==35 || temp==48 ? '9' : //                    |
                       temp==10 || temp==23 || temp==36 || temp==49 ? 'T' : //                    |
                       temp==11 || temp==24 || temp==37 || temp==50 ? 'J' : //                    |
                       temp==12 || temp==25 || temp==38 || temp==51 ? 'Q' : 'K'; //               |

                suit = temp>= 1 && temp<=13 ? "Diamonds" : //Assigns corresponding suit
                       temp>=14 && temp<=26 ?  "Hearts"  : //to hand 2
                       temp>=27 && temp<=39 ?  "Spades"  : "Clubs";

                hand2 << face << " " << suit << endl;//Stores card type char for face and string for suit
            }
            strge.close(); //Closes files for later use
            hand2.close(); //           |
        }
        else{
            cout << "Failed to deal Second hand";
            return 1; //Ends program if failed as second hand would not be dealt
        }

        if(hand0){ //CARDS 11-15, middle cards, test if open successful
            //Unique cards
            do{ //Once again Do-While loops to repeat after first time if condition true
                num11 = rand()%numCard+1;
            }while(num11==num1||num11==num2||num11==num3||num11==num4||num11==num5||num11==num6
                 ||num11==num7||num11==num8||num11==num9||num11==num10); //Tests all other previous cards to new ones generated
            do{                                                          //                             |
                num12 = rand()%numCard+1;                                //                             |
            }while(num12==num1||num12==num2||num12==num3||num12==num4||num12==num5||num12==num6//       |
                 ||num12==num7||num12==num8||num12==num9||num12==num10||num12==num11);         //       |
                                                                                               //       |
            do{                                                                                //       |
                num13 = rand()%numCard+1;                                                      //       |
            }while(num13==num1||num13==num2||num13==num3||num13==num4||num13==num5||num13==num6//       |
                 ||num13==num7||num13==num8||num13==num9||num13==num10||num13==num11||num13==num12);//  |
                                                                                               //       |
            do{                                                                                //       |
                num14 = rand()%numCard+1;                                                      //       |
            }while(num14==num1||num14==num2||num14==num3||num14==num4||num14==num5||num14==num6//       |
                 ||num14==num7||num14==num8||num14==num9||num14==num10||num14==num11||num14==num12||num14==num13);
                                                                                               //       |
            do{                                                                                //       |
                num15 = rand()%numCard+1;                                                      //       |
            }while(num15==num1||num15==num2||num15==num3||num15==num4||num15==num5||num15==num6||num15==num7
                 ||num15==num8||num15==num9||num15==num10||num15==num11||num15==num12||num15==num13||num15==num14);

            strge.open("temporaryStorage.dat", ios::out);
            strge << num11 << endl //Stores middle hand to temporary storage
                  << num12 << endl //in the form of integer values 1-52
                  << num13 << endl
                  << num14 << endl
                  << num15;
            strge.close(); //Close file to later use from start
            
            strge.open("temporaryStorage.dat", ios::in); //Open in inputm mode
            //Card type based on number
            for(int i=1;i<=5;i++){//loop to read all 5 lines of storage contents
                strge>>temp; //temp is the ith row integer which is converted to a face character using ternary op                                            
                face = temp== 1 || temp==14 || temp==27 || temp==40 ? 'A' ://        |
                       temp== 2 || temp==15 || temp==28 || temp==41 ? '2' ://        |
                       temp== 3 || temp==16 || temp==29 || temp==42 ? '3' ://        |
                       temp== 4 || temp==17 || temp==30 || temp==43 ? '4' ://        |
                       temp== 5 || temp==18 || temp==31 || temp==44 ? '5' ://        |
                       temp== 6 || temp==19 || temp==32 || temp==45 ? '6' ://        |
                       temp== 7 || temp==20 || temp==33 || temp==46 ? '7' ://        |
                       temp== 8 || temp==21 || temp==34 || temp==47 ? '8' ://        |
                       temp== 9 || temp==22 || temp==35 || temp==48 ? '9' ://        |
                       temp==10 || temp==23 || temp==36 || temp==49 ? 'T' ://        |
                       temp==11 || temp==24 || temp==37 || temp==50 ? 'J' ://        |
                       temp==12 || temp==25 || temp==38 || temp==51 ? 'Q' : 'K';//   |

                suit = temp>= 1 && temp<=13 ? "Diamonds" : //Assigns suit to respective card
                       temp>=14 && temp<=26 ?  "Hearts"  : 
                       temp>=27 && temp<=39 ?  "Spades"  : "Clubs";

                hand0 << face << " " << suit << endl; //Outputs to hand0 file, stores middle hand deck
            }
            strge.close(); //Closes files for future use
            hand0.close();
        }
        else{
            cout << "Failed to deal Middle hand";
            return 1; //Fails program if unsuccesSful to open file
        }

        //Round 0, initial "round" but really logic is determined in round 1
        cout << "PLAYER 1 CARDS" << endl //Display header for player 1
              << "--------------" << endl;//          |
        hand1.open("firstHand.dat", ios::in); //Open hand 1 in input mode
        for(int row=1; row<=5; row++){ //Reads all 5 lines including spaces using for loop
            string out1; //defines string variable that will e used to output current hand
            getline(hand1, out1);//stores ith line in out1 string
            cout << out1 << endl; //displays string separated by newlines
        }
        hand1.close(); //close hand1 for future use

        //Ask player 1 if swap
        cout << "\nPlayer 1, Would you like to swap your hand for the Middle one: ";
        cin >> choice; //After showing player 1 his hand ask if he would like to swap for middle
                       //Player does not know contents of middle hand, only his
        do{ //Do-While loop to repeat task if invalid choice is entered
            switch (choice){ //Switch loop to evaluate entries, break statement to only perform one
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
                default: //Informs player of invalid entry and to re-enter an option
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
                            if(swap2<1 || swap2>5 ||swap0<1 || swap0>5)
                                cout << "Invalid!\n";
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
                                rowRep.open("replacingRows.dat", ios::in); //open in input mode
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
                                getline(rowRep,replace); //                   |
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
                }while(player2!='S'&&player2!='s'&&player2!='P'&&player2!='p'&&player2!='K'&&player2!='k'); //condition to repeat invalid input

                //Player 1's turn, can choose option similar to player 2
                format.open("displayTable.dat", ios :: out); //Will display player 1 cards as well as middle side by side
                hand1.open("firstHand.dat", ios::in); //open in input mode
                hand0.open("middleHand.dat", ios::in);//       |

                cout << "\n\n\nPLAYER 1 CARDS\t\t\tMIDDLE CARDS" << endl //Display header for player 1's turn
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
                            if(swap1<1 || swap1>5 ||swap0<1 || swap0>5)
                                cout << "Invalid!\n";
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
                            if(swap2<1 || swap2>5 ||swap0<1 || swap0>5)
                                cout << "Invalid!\n";
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
        else {//(choice == 'N' || choice == 'n'),If player 1 didn't want the middle deck player 2 can get it
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
                format.open("displayTable.dat", ios :: out); //Will display the player 1 card as well as middle side by side
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
                            if(swap1<1 || swap1>5 ||swap0<1 || swap0>5)
                                cout << "Invalid!\n";
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
                            if(swap2<1 || swap2>5 ||swap0<1 || swap0>5)
                                cout << "Invalid!\n";
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

                cout << "Last turn!!!Player 2 knocked." << endl; //Inform player that it is his lst turn since player1 knocked
                do {        
                    cout << "Player 1's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
                    cin >> player1; //Prompt for user input

                    if(player1=='S'||player1=='s'){
                        int swap1, swap0, line;
                        string replace;
                        do{
                            cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                            cin >> swap1 >> swap0; //prompt for user input to replace desired rows
                            if(swap1<1 || swap1>5 ||swap0<1 || swap0>5)
                                cout << "Invalid!\n";
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
                        while(getline(strge, replace))//send repaired and row replaced line back to hand1
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

        //Ranking hands from best to worst for Hand1
        hand1.open("firstHand.dat", ios::in);

        hand1 >> face1 >> suit1 //Store contents from hand1 into respective char variables and strings
              >> face2 >> suit2 //                          |
              >> face3 >> suit3 //                          |
              >> face4 >> suit4 //                          |
              >> face5 >> suit5;//                          |

        strge.open("temporaryStorage.dat", ios::out);
        strge << face1 << endl //send char face values to storage only
              << face2 << endl //                  |
              << face3 << endl //                  |
              << face4 << endl //                  |
              << face5 << endl; //                 |
        strge.close(); // close files to reopen later in different mode
        hand1.close();

        strge.open("temporaryStorage.dat", ios::in); //input mode
        rowRep.open("replacingRows.dat", ios::out); // output mode
        for(int i=1;i<=5;i++){
            int temp;
            strge >> face; //convert the char face values into their respective integer values and send to rowRep
            temp = face == 'A'? 1 ://                          |
                   face == '2'? 2 ://                          |
                   face == '3'? 3 ://                          |
                   face == '4'? 4 ://                          |
                   face == '5'? 5 ://                          |
                   face == '6'? 6 ://                          |
                   face == '7'? 7 ://                          |
                   face == '8'? 8 ://                          |
                   face == '9'? 9 ://                          |
                   face == 'T'? 10://                          |
                   face == 'J'? 11://                          |
                   face == 'Q'? 12: 13;//                      |
            rowRep << temp << endl;                  
        }
        strge.close();
        rowRep.close();

        rowRep.open("replacingRows.dat", ios::in);
        rowRep >> num1 >> num2 >> num3 >> num4 >>num5; //Store integers from rowRep as follwing ints
        rowRep.close();

        //Organize it from highest to lowest

        //Analyzing Card 2
        if(num2>num1){//compare first and second and reorganize
            temp=num2, suit=suit2,
            num2=num1, suit2=suit1,
            num1=temp, suit1=suit;
        }

        //Analyzing Card 3
        if(num3>num2){ //compare first, second, and third and reorganize
            if (num3>num1){
                temp=num3, suit=suit3,
                num3=num2, suit3=suit2,
                num2=num1, suit2=suit1,
                num1=temp, suit1=suit;
            }
            else{
                temp=num3, suit=suit3,
                num3=num2, suit3=suit2,
                num2=temp, suit2=suit;
            }
        }

        //Analyzing Card 4
        if(num4>num3&&num4>num2&&num4>num1){ //Card 4 is the largest
            temp=num4, suit=suit4, //compare first, second, third and fourth and reorganize
            num4=num3, suit4=suit3,
            num3=num2, suit3=suit2,
            num2=num1, suit2=suit1,
            num1=temp, suit1=suit;
        }
        else if(num4>num3&&num4>num2){ //Card 4 is second largest
            temp=num4, suit=suit4,
            num4=num3, suit4=suit3,
            num3=num2, suit3=suit2,
            num2=temp, suit2=suit;
        }
        else if (num4>num3){ //Card 4 is the third largest
            temp=num4, suit=suit4,
            num4=num3, suit4=suit3,
            num3=temp, suit3=suit;
        }
        else//Card 4 is smaller than all
            num4=num4, suit4=suit4;

        //Analyzing Card 5, //compare all cards and reorganize
        if(num5>num4&&num5>num3&&num5>num2&&num5>num1){ //Card 5 is the largest
            temp=num5, suit=suit5, 
            num5=num4, suit5=suit4,
            num4=num3, suit4=suit3,
            num3=num2, suit3=suit2,
            num2=num1, suit2=suit1,
            num1=temp, suit1=suit;
        }
        else if (num5>num4&&num5>num3&&num5>num2){ //Card 5 is the second largest
            temp=num5, suit=suit5,
            num5=num4, suit5=suit4,
            num4=num3, suit4=suit3,
            num3=num2, suit3=suit2,
            num2=temp, suit2=suit;
        }

        else if (num5>num4&&num5>num3){ //Card 5 is the third largest
            temp=num5, suit=suit5,
            num5=num4, suit5=suit4,
            num4=num3, suit4=suit3,
            num3=temp, suit3=suit;
        }
        else if (num5>num4){ //Card 5 is the fourth largest
            temp=num5, suit=suit5,
            num5=num4, suit5=suit4,
            num4=temp, suit4=suit;
        }
        else //Card 5 is smallest card
            num5=num5, suit5=suit5;

        //Figuring out what hand Player 1 has
        if((num1==num2&&num2==num3&&num3==num4)||(num5==num2&&num2==num3&&num3==num4))
            result1="4 of a Kind", score1=3; //third highest ranking
        else if((num1==num2&&num2==num3&&num4==num5)||(num5==num4&&num4==num3&&num1==num2))
            result1="Full House", score1=4; //fourth highest ranking
        else if(suit1==suit2&&suit2==suit3&&suit3==suit4&&suit4==suit5){
            if(num5==1&&num1==13&&num2==12&&num3==11&&num4==10)
                result1="Royal Flush", score1=1; //first highest ranking
            else if (num1==num2+1&&num2==num3+1&&num3==num4+1&&num4==num5+1)
                result1="Straight Flush", score1=2; //second highest ranking
            else
                result1="Flush", score1=5; //fifth highest ranking
        }
        else if((num1==num2+1&&num2==num3+1&&num3==num4+1&&num4==num5+1)
                ||(num5==1&&num1==13&&num2==12&&num3==11&&num4==10))
            result1="Straight", score1=6; //sixth highets ranking
        else if ((num1==num2&&num2==num3)||(num3==num4&&num4==num5)||(num2==num3&&num3==num4))
            result1="3 of a Kind", score1=7; //seventh highest ranking
        else if(num1==num2||num2==num3||num3==num4||num4==num5){
            temp=0;
            if(num1==num2) //every time a pair is encountered temp incremented
                temp++;
            if(num2==num3) //only four possible pairs when alligned by highest to lowest
                temp++;
            if(num3==num4)
                temp++;
            if(num4==num5)
                temp++;
            onePair = (temp == 1);
            result1 = (onePair) ? "One Pair" : "Two Pairs"; //9th and 8th rank resectively
            score1 = (onePair) ? 9 : 8;
        }       
        else
            result1="High Card", score1=10; //lowest ranked

        strge.open("temporaryStorage.dat", ios::out);
        strge << num1 << " " << suit1 << endl //send integer face value and suit to storage file
              << num2 << " " << suit2 << endl
              << num3 << " " << suit3 << endl
              << num4 << " " << suit4 << endl
              << num5 << " " << suit5;
        strge.close();

        strge.open("temporaryStorage.dat", ios::in);
        hand1.open("firstHand.dat", ios::out);

        for(int i=1;i<=5;i++){
            int temp;
            strge >> temp >> suit; //read input from storage file and convert integer values back into their 
            face = temp == 1 ? 'A' ://charcter counter parts
                   temp == 2 ? '2' :
                   temp == 3 ? '3' :
                   temp == 4 ? '4' :
                   temp == 5 ? '5' :
                   temp == 6 ? '6' :
                   temp == 7 ? '7' :
                   temp == 8 ? '8' :
                   temp == 9 ? '9' :
                   temp == 10? 'T' :
                   temp == 11? 'J' :
                   temp == 12? 'Q' : 'K';
            hand1 << face << " " << suit << endl;                  
        }
        strge.close();
        hand1.close();



        //Ranking hands from best to worst for Hand2
        hand2.open("secondHand.dat", ios::in); //SAME EXACT PROCESS FOR ANALYZING HAND2, except that replace result1 with result2
                                                                                       //and replace score1 with score2
        hand2 >> face1 >> suit1
              >> face2 >> suit2
              >> face3 >> suit3
              >> face4 >> suit4
              >> face5 >> suit5;

        strge.open("temporaryStorage.dat", ios::out);
        strge << face1 << endl
              << face2 << endl
              << face3 << endl
              << face4 << endl
              << face5 << endl;
        strge.close();
        hand2.close();

        strge.open("temporaryStorage.dat", ios::in);
        rowRep.open("replacingRows.dat", ios::out);
        for(int i=1;i<=5;i++){
            int temp;
            strge >> face;
            temp = face == 'A'? 1 :
                   face == '2'? 2 :
                   face == '3'? 3 :
                   face == '4'? 4 :
                   face == '5'? 5 :
                   face == '6'? 6 :
                   face == '7'? 7 :
                   face == '8'? 8 :
                   face == '9'? 9 :
                   face == 'T'? 10:
                   face == 'J'? 11:
                   face == 'Q'? 12: 13;
            rowRep << temp << endl;                  
        }
        strge.close();
        rowRep.close();

        rowRep.open("replacingRows.dat", ios::in);
        rowRep >> num1 >> num2 >> num3 >> num4 >>num5;
        rowRep.close();

        //Organize it from highest to lowest

        //Analyzing Card 2
        if(num2>num1){
            temp=num2, suit=suit2,
            num2=num1, suit2=suit1,
            num1=temp, suit1=suit;
        }

        //Analyzing Card 3
        if(num3>num2){
            if (num3>num1){
                temp=num3, suit=suit3,
                num3=num2, suit3=suit2,
                num2=num1, suit2=suit1,
                num1=temp, suit1=suit;
            }
            else{
                temp=num3, suit=suit3,
                num3=num2, suit3=suit2,
                num2=temp, suit2=suit;
            }
        }

        //Analyzing Card 4
        if(num4>num3&&num4>num2&&num4>num1){ //Card 4 is the largest
            temp=num4, suit=suit4,
            num4=num3, suit4=suit3,
            num3=num2, suit3=suit2,
            num2=num1, suit2=suit1,
            num1=temp, suit1=suit;
        }
        else if(num4>num3&&num4>num2){ //Card 4 is second largest
            temp=num4, suit=suit4,
            num4=num3, suit4=suit3,
            num3=num2, suit3=suit2,
            num2=temp, suit2=suit;
        }
        else if (num4>num3){ //Card 4 is the third largest
            temp=num4, suit=suit4,
            num4=num3, suit4=suit3,
            num3=temp, suit3=suit;
        }
        else//Card 4 is smaller than all
            num4=num4, suit4=suit4;

        //Analyzing Card 5
        if(num5>num4&&num5>num3&&num5>num2&&num5>num1){ //Card 5 is the largest
            temp=num5, suit=suit5,
            num5=num4, suit5=suit4,
            num4=num3, suit4=suit3,
            num3=num2, suit3=suit2,
            num2=num1, suit2=suit1,
            num1=temp, suit1=suit;
        }
        else if (num5>num4&&num5>num3&&num5>num2){ //Card 5 is the second largest
            temp=num5, suit=suit5,
            num5=num4, suit5=suit4,
            num4=num3, suit4=suit3,
            num3=num2, suit3=suit2,
            num2=temp, suit2=suit;
        }

        else if (num5>num4&&num5>num3){ //Card 5 is the third largest
            temp=num5, suit=suit5,
            num5=num4, suit5=suit4,
            num4=num3, suit4=suit3,
            num3=temp, suit3=suit;
        }
        else if (num5>num4){ //Card 5 is the fourth largest
            temp=num5, suit=suit5,
            num5=num4, suit5=suit4,
            num4=temp, suit4=suit;
        }
        else //Card 5 is smallest card
            num5=num5, suit5=suit5;


        //Figuring out what hand Player 1 has
        if((num1==num2&&num2==num3&&num3==num4)||(num5==num2&&num2==num3&&num3==num4))
            result2="4 of a Kind", score2=3;//Having a 4 of a kind means will not have a royal flush or straight flush so will always give
        else if((num1==num2&&num2==num3&&num4==num5)||(num5==num4&&num4==num3&&num1==num2))//the highest score regardless if comes first in if else
            result2="Full House", score2=4;
        else if(suit1==suit2&&suit2==suit3&&suit3==suit4&&suit4==suit5){
            if(num5==1&&num1==13&&num2==12&&num3==11&&num4==10)
                result2="Royal Flush", score2=1;
            else if (num1==num2+1&&num2==num3+1&&num3==num4+1&&num4==num5+1)
                result2="Straight Flush", score2=2;
            else
                result2="Flush", score2=5;
        }
        else if((num1==num2+1&&num2==num3+1&&num3==num4+1&&num4==num5+1)
                ||(num5==1&&num1==13&&num2==12&&num3==11&&num4==10))
            result2="Straight", score2=6;
        else if ((num1==num2&&num2==num3)||(num3==num4&&num4==num5)||(num2==num3&&num3==num4))
            result2="3 of a Kind", score2=7;
        else if(num1==num2||num2==num3||num3==num4||num4==num5){
            temp=0;
            if(num1==num2)//initialize temp to 0 and every time a pair is encountered increment
                temp++;
            if(num2==num3)
                temp++;
            if(num3==num4)
                temp++;
            if(num4==num5)
                temp++;
            onePair = (temp == 1);//will assign true if indeed is a pair or false if its two pairs
            result2 = (onePair) ? "One Pair" : "Two Pairs";
            score2 = (onePair) ? 9 : 8;
        }       
        else
            result2="High Card", score2=10;

        strge.open("temporaryStorage.dat", ios::out);
        strge << num1 << " " << suit1 << endl //send to num integer cards along with suits to storage
              << num2 << " " << suit2 << endl
              << num3 << " " << suit3 << endl
              << num4 << " " << suit4 << endl
              << num5 << " " << suit5;
        strge.close();

        strge.open("temporaryStorage.dat", ios::in);
        hand2.open("secondHand.dat", ios::out);

        for(int i=1;i<=5;i++){
            int temp;
            strge >> temp >> suit; //replace the integer values with appropriate face values and output to hand2
            face = temp == 1 ? 'A' :
                   temp == 2 ? '2' :
                   temp == 3 ? '3' :
                   temp == 4 ? '4' :
                   temp == 5 ? '5' :
                   temp == 6 ? '6' :
                   temp == 7 ? '7' :
                   temp == 8 ? '8' :
                   temp == 9 ? '9' :
                   temp == 10? 'T' :
                   temp == 11? 'J' :
                   temp == 12? 'Q' : 'K';
            hand2 << face << " " << suit << endl;                  
        }
        strge.close();
        hand2.close();

        format.open("displayTable.dat", ios :: out); //Will display the players card as well as middle side by side
        hand2.open("secondHand.dat", ios::in);
        hand1.open("firstHand.dat", ios::in);

        cout << "\nPLAYER 1 CARDS\t\t\tPLAYER 2 CARDS" << endl//Display prompt but this time with player 1 and player 2
              << "--------------\t\t\t--------------" << endl;
        for(int i=1; i<=5; i++){//Send data to format file
            string display;

            getline(hand1, display); //use same method as display table when players were playing the game
            format << left << setw(10) << display;
            getline(hand2, display);
            format << "\t\t\t" << display << endl;
        }
        format.close();
        hand2.close();
        hand1.close();   

        format.open("displayTable.dat", ios :: in); //Open it again to start inputting display
        while(format){
            string display;
            getline(format, display);//display table to the users showing their respective hands
            cout << display << endl;
        }
        format.close();

        cout << "Player 1: " << result1 << endl //Inform players the hands they obtained
             << "Player 2: " << result2 << endl;

        if(score1 < score2){ //if player1's score is ranked higher will win
            cout << "\nPlayer 1 Wins!";
            wins1++;
        }
        else if(score2 < score1){//if player2's score is ranked higher will win
            cout << "\nPlayer 2 wins!";
            wins2++;
        }
        else 
            cout << "\nTie Game, Nobody Wins."; //does not consider highest card of equivalent hand
        gameCt++;
        //Open in append mode to account for previous entries of score1's
        stdDev1.open("p1Deviation.dat",ios::app); 
        stdDev1<<score1<<endl; //send current score 1 to file
        stdDev1.close(); //close file
        
        sum=0; //initialize to 0 for proper sum and mean
        mean=0;
        stdDev1.open("p1Deviation.dat",ios::in); //open in input mode
        while(stdDev1>>temp)//read all file contents then close
            sum+=temp;//each term added to the sum
        mean=sum/gameCt;
        stdDev1.close(); //close file
        
        stdDev1.open("p1Deviation.dat",ios::in); //open in input mode
        sum=0; //initialize to 0 again to find sum of squared differences
        while(stdDev1>>temp)
            sum+=pow((temp-mean), 2);//sum of squared differences
        stdDev1.close();
        dev1=sqrt(sum/gameCt);//sqrt the sum of squared difference divide by number of instances
        
        //Open in append mode to account for previous entries of score2's
        stdDev2.open("p2Deviation.dat",ios::app);
        stdDev2<<score2<<endl; //send current score 1 to file
        stdDev2.close(); //close file
        
        sum=0; //initialize to 0 for proper sum and mean
        mean=0;
        stdDev2.open("p2Deviation.dat",ios::in);  //open in input mode
        while(stdDev2>>temp) //read all file contents then close
            sum+=temp;//each term added to the sum
        mean=sum/gameCt;
        stdDev2.close(); //close file
        
        stdDev2.open("p2Deviation.dat",ios::in); //open in input mode
        sum=0; //initialize to 0 again to find sum of squared differences
        while(stdDev2>>temp)
            sum+=pow((temp-mean), 2); //sum of squared differences
        stdDev2.close();
        dev2=sqrt(sum/gameCt); //sqrt the sum of squared difference divide by number of instances
        
        winRte1=static_cast<float>(wins1)/gameCt*100;
        winRte2=static_cast<float>(wins2)/gameCt*100;
        
        cout << showpoint << fixed << setprecision(2); //show win percentage of each player, NOT WIN-LOSS, over total games played & std deviation
        cout << "\nPlayer 1---> win rate: %"<<setw(6)<<winRte1<<"\t\tStandard Deviation: "<<dev1;
        cout << "\nPlayer 2---> win rate: %"<<setw(6)<<winRte2<<"\t\tStandard Deviation: "<<dev2;

        //prompt user if they would like to play again
        cout << "\nWould you like to play again?\n";
        cin >> choice;
        cout << endl;

    }while(choice=='Y' || choice=='y');//continue the game if user enters yes
    //Exit the Program
    return 0;
}