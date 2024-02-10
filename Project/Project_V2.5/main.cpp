/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on February 9, 2024, 3:23 PM
 * Purpose: Game Project for CIS-5
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <iomanip> //Format Library
#include <cmath> //Math Library
#include <cstdlib> //To use random number generator
#include <fstream> //File Library, for input & output
#include <string> //String Library
#include <cstring> //Null terminated character array strings
#include <ctime> //Time file to use system clock
#include <vector> //STL Vector Library

using namespace std;

//Function Prototypes
void dealt(int [], const int, vector<int>&); //Function to deal integer hand(1-52) to player array, const is size of array, vector records unique values
void convert(int[], const int, fstream&, string); //takes in player array hand, file identifier & file name.Converts numerical hand into card equivalent,stored in file
int unique(vector<int>&); //function to store previously occurred numbers for 1-52, repeats random# until unique and returns it to dealt(stores all unique numbers in vector)
void swapLgc(fstream&, string, fstream&, string, int plySwap=0, int midSwap=0);//Swap rows from player file and middle file, if defaulted swaps entire contents
void path1(fstream&, string, fstream&, string, fstream&, string); //function if path1 taken, gives reference file from each hand 
void path2(fstream&, string, fstream&, string, fstream&, string); //function if path2 taken, gives reference file from each hand 
void header(fstream&, string, fstream&, string); //display header before each players turn, shows their hand and middle hand
void header(fstream&, string, fstream&, string, string, string);//overflow header for final display, shows player 1 and player 2 hands side by side & string results for each
void bubSort(char[][11], int[], int); //sorts player1 hand using the player array(ints), converts the equivalent index row for 2d char(parallel arrays)
void selSort(char[][11], int[], int);// same as above, sorts player2's hand instead
void revert(char[][11], int[], int); //Function to make player array numerical equivalent(1-13) of face, uses[0]column of 2d array for face then reverts
string analyze(fstream&, string, int[], int&);//analyzes hand returns result(eg.Full House), reference score equivalent of result(1-10)
void calcDev(float&, int, float&, int); //calculates standard deviation of both player's scores
bool rowVal(char, char, int&, int&); //validates swapping of rows in path1/2 before entering swpLgc

//Program Execution Begins Here
int main(int argc, char** argv){
    //Set a random seed
    srand(static_cast<unsigned short>(time(0))); //seed random number generator
    //Declare all Variables
    const unsigned short SIZE = 5, //max size of 1D arrays, or max row for 2D array
                         COL = 11; //Face Character + Diamonds suit will be max columns(10) then null,includes space as characters
    int play1[SIZE],//Number values of hand 1-52 for each player and middle
        play2[SIZE],        
        play0[SIZE],
        score1, //records score of current game round for player 1
        score2, //records score of current game round for player 2
        wins1, wins2, gameCt; //records wins for both players and the games elapsed
    
    vector<int> allCard; //Records all numerical values(1-52)of all 15 cards dealt 
    string fleNme1 = "player1Hand.dat", //Name of player files that store their cards
           fleNme2 = "player2Hand.dat",
           fleNme0 = "middleHand.dat",
           display, //display string for displaying rows of files
           result1, //hand attained in current round for player1 (eg. "4 of a King")
           result2; //same as above but for player2
          
    char choice1, //Player 1 choice in regards to swapping whole hand with middle
         choice2, //same as above but for player2
         crdLst[SIZE][COL]; //2D array to store card as 5 strings(row) composed of columns
                            //example one row might be "9 Diamonds"
    float stdDev1, //variable to store standard deviation for player 1
          stdDev2; //variable to store standard deviation for player 2
    
    //Declare files
    fstream hand1, //where player 1 hand is stored (with face and suit)
            hand2, //player2....
            hand0; //middle hand....
    
    //Initialize Variables
    wins1 = 0, wins2 = 0, gameCt = 0; //initialize tracker for each to 0 before incrementing an entering the loop
       
    do{ //Do-While loop to repeat the game
        //Deal numerical hand for each player, player 0 is middle
        dealt(play1, SIZE, allCard);    
        dealt(play2, SIZE, allCard);
        dealt(play0, SIZE, allCard);

        //Convert numerical Hand into card hand with face and suit, store it in respective file hand
        convert(play1, SIZE, hand1, fleNme1);
        convert(play2, SIZE, hand2, fleNme2);
        convert(play0, SIZE, hand0, fleNme0);

        //Initial round 0, ask player1 if they would like to swap for middle
        cout << "PLAYER 1 CARDS" << endl //display player1 header and their cards
             << "--------------" << endl;
        hand1.open(fleNme1, ios::in); 
        for(int row=1; row<=5; row++){
            getline(hand1, display);
            cout << display << endl;
        }
        hand1.close();
        cout << "\nPlayer 1, Would you like to swap your hand for the Middle one: ";//prompt for decision by player1

        do{ //Do-While loop to repeat task if invalid choice is entered
            cin >> choice1;
            switch (choice1){ //Switch loop to evaluate entries, break statement to only perform one
                case 'Y':{ //Player1 decides to swap
                    swapLgc(hand1, fleNme1, hand0, fleNme0); //since no row swap entered as arguments will swap entire hand in swpLgc           
                    break;
                }
                case 'y':{ 
                    swapLgc(hand1, fleNme1, hand0, fleNme0); //same logic as the other yes case 'Y'                            
                    break;
                }
                case 'N': break; //If player1 doesn't decide to swap cards do nothing
                case 'n': break; //                    |
                default: //Informs player of invalid entry and to re-enter an option
                    cout << "Enter a valid option for YES or for NO: ";            
            }   
        }while(choice1 != 'Y' && choice1 != 'y' && choice1 != 'N' && choice1 != 'n'); //Evaluates if valid option was entered and loops accordingly
        cout << endl << "________________________________________________________________" << endl << endl; //skips to next turn, makes easier to see
        if (choice1 == 'Y' || choice1 == 'y'){
            path1(hand1, fleNme1, hand2, fleNme2, hand0, fleNme0); //if player1 said yes then path1 is taken, goes plyr2 then plyr1 and repeats
        }
        else{ //otherwise give player 2 same option to swap entire hand
            cout << "PLAYER 2 CARDS" << endl //display header for player 2 and their cards
                      << "--------------" << endl;
                hand2.open(fleNme2, ios::in); 
                for(int row=1; row<=5; row++){
                    getline(hand2, display);
                    cout << display << endl;
                }
                hand2.close();
            cout << "\nPlayer 2, Would you like to swap your hand for the Middle one: "; //prompt for player2 choice

            do{ //Do-While loop to repeat task if invalid choice is entered
                cin >> choice2;
                switch (choice2){ //Switch loop to evaluate entries, break statement to only perform one
                    case 'Y':{ //Player1 decides to swap
                        swapLgc(hand2, fleNme2, hand0, fleNme0);           
                        break;
                    }
                    case 'y':{ 
                        swapLgc(hand2, fleNme2, hand0, fleNme0);                              
                        break;
                    }
                    case 'N': break; //If player2 doesn't decide to swap cards do nothing
                    case 'n': break; //                    |
                    default: //Informs player of invalid entry and to re-enter an option
                        cout << "Enter a valid option for YES or for NO: ";            
                }   
            }while(choice2 != 'Y' && choice2 != 'y' && choice2 != 'N' && choice2 != 'n'); //Evaluates if condition for while loop is met
            cout << endl << "________________________________________________________________" << endl << endl; //next turn
            path2(hand1, fleNme1, hand2, fleNme2, hand0, fleNme0); //path2 is taken regardless if player 2 say yes or no, goes plyr1 then plyr2 and repeats
        }    
        cout << endl; 

        hand1.open(fleNme1, ios::in); //store lines from player 1 file into 2D array
        for(int row = 0; row < SIZE; row++){
            hand1.getline(crdLst[row], COL); //string inputted into row of 2D array from file
        }
        hand1.close(); //close file
        revert(crdLst, play1, SIZE); //send 2d array to function to re-enter numerical values into int array of player(1-13)
        bubSort(crdLst, play1, SIZE);//sort the hand ascending to descending using player int array but also swap 2D crdLst using same index(parallel arrays)
        hand1.open(fleNme1, ios::out);
        for(int row = 0; row < SIZE; row++){ //after sorted loop to write 2D crdLst array back into player file
            hand1 << crdLst[row] << endl; //string inputted into row of 2D array from file
        }
        hand1.close();

        hand2.open(fleNme2, ios::in); //do same for player 2, store his file into the 2D char array
        for(int row = 0; row < SIZE; row++){
            hand2.getline(crdLst[row], COL); //string inputted into row of 2D array from file
        }
        hand2.close();
        revert(crdLst, play2, SIZE); //revert/modify player int array to resemble equivalent face in crdLst
        selSort(crdLst, play2, SIZE); //sort player2's hand using their integer array but this time using selection sort
        hand2.open(fleNme2, ios::out);
        for(int row = 0; row < SIZE; row++){ //restore the sorted hand into player's file
            hand2 << crdLst[row] << endl; //string inputted into row of 2D array from file
        }
        hand2.close();

        //Analyze each hand
        result1=analyze(hand1, fleNme1, play1, score1); //send each players file and integer array to evaluate what they obtained(eg. Full House)
        result2=analyze(hand2, fleNme2, play2, score2); //same as above, result is returned into corresponding player strings

        header(hand1, fleNme1, hand2, fleNme2, result1, result2);//overflow header function, this ones takes in the 2 results as arguments
        cout << endl;                                           //will display player hands side by side along with results
        //Display the Output
        if(score1 < score2){//if player 1 obtains a better score(lower is better, Straight Flush = 1 whereas High Card = 10)
            cout << "Player 1 Wins!" << endl;
            wins1++;
        }
        else if(score2 < score1){//if player 2 obtains a better score
            cout << "Player 2 Wins!" << endl;
            wins2++;
        }
        else //if both player received the same score(same hand type),DOES NOT take into account highest card of each hand to break the tie
            cout << "Tie Game, Nobody Wins." << endl;
        gameCt++; //Increment the game counter to hold number of games elapsed
        //Calculate standard deviation of scores in function, 10 is lowest hand & 1 is best hand(Royal Flush)
        calcDev(stdDev1, score1, stdDev2, score2); //stdDev variables are referenced so that they are modified in main
        cout << showpoint << fixed << setprecision(2); //format the display to show end game results
        cout <<"Player 1---> win rate: %"<<setw(6)<<static_cast<float>(wins1)/gameCt*100<<"\t\tStandard Deviation: "<<stdDev1;
        cout <<"\nPlayer 2---> win rate: %"<<setw(6)<<static_cast<float>(wins2)/gameCt*100<<"\t\tStandard Deviation: "<<stdDev2;
        cout << "\nWould you like to play again?\n"; //Prompt if would like to play again
        cin >> choice1; //reused choice1 here but could've been any other char
        cout << endl << "________________________________________________________________" << endl << endl;
    }while(choice1=='Y' || choice1=='y');//continue the game if user enters yes 
    
    //Exit the Program
    return 0;
}
void dealt(int player[], const int size, vector<int>& allCard){
    for(int index = 0; index < size; index++){ //loop to repeat 5 times to fill player array of cards(1-52)
        player[index] = unique(allCard); //current element is assigned value attained from unique function which takes vector as argument
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
    if(!hand){ //condition if file failed to open
        cout << "Error opening file";
        exit(1); //exit entire program with error code 1
    }
    else{
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
        hand.close(); //close file after all have been converted and stored in file
    }
}
void swapLgc(fstream& plyrFle, string fleNmeP, fstream& midFle,string fleNme0, int plySwap, int midSwap){//swaps file row contents or sometimes entire contents
    fstream strge, //declare files for storage and row replacing
            rowRep;
    string replace; //declare string to store the strings that are being transferred/swapped
    int line; //declare integer to use as counter for row number loop is on
    if(plySwap == 0 && midSwap == 0){//Default values for parameter, means that this is initial swap for entire hand(beginning phase of game)
            //Send player hand to storage file
            plyrFle.open(fleNmeP, ios::in);
            strge.open("temporaryStorage.dat", ios::out);
            while(getline(plyrFle,replace)) //store line from player file into replace then output it to storage
                strge << replace << endl;  //file, do this for as long as lines are being read
            plyrFle.close();
            strge.close();

            //Send middle hand to player file
            midFle.open(fleNme0, ios::in);
            plyrFle.open(fleNmeP, ios::out);
            while(getline(midFle,replace))  //store line from middle file into replace then output it to player file
                plyrFle << replace << endl;//file, do this for as long as lines are being read
            midFle.close();
            plyrFle.close();

            //send storage to middle file
            strge.open("temporaryStorage.dat", ios::in);
            midFle.open(fleNme0, ios::out);
            while(getline(strge,replace))  //store line from storage file into replace then output it to middle file
                midFle << replace << endl;//file, do this for as long as lines are being read
            strge.close();
            midFle.close();
    }
    else{ //otherwise swap values were not left defaulted and this occurred in the middle of the game
        midFle.open(fleNme0, ios::in); //open in input mode
        plyrFle.open(fleNmeP, ios::in); //      |
        rowRep.open("replacingRows.dat", ios::out); //Open file in output mode to gather replaced rows from each deck

        line = 1; //initialize outside while loop
        while(getline(plyrFle, replace)){ //Reads lines from player hand until no further ones available
            rowRep << (line == plySwap ? replace : ""); //Once line is equal to the row that desires replacing, send to rowRep file
            line++; //increment to continue reading
        }
        rowRep << endl; // newline so that replaced lines will be on separate lines
        line = 1;
        while(getline(midFle, replace)){ //perform same logic on middle file
            rowRep << (line == midSwap ? replace : ""); //rowRep will contain the row that the player wants to replace from his deck
            line++;                                    //then on subsequent line will contain middle row line wishing to be swapped with
        }
        midFle.close(); //close files for later use
        plyrFle.close(); //           |
        rowRep.close();//             |

        strge.open("temporaryStorage.dat", ios::out); //open in output mode      
        line = 1; //initialize at line 1 for correct reading, allowing to swap correctly
        midFle.open(fleNme0, ios::in);
        while(getline(midFle, replace)){ //transfers content of middle hand file to storage except line that will be replaced.
            if(line!=midSwap)             
                strge << replace << endl;
            else{ //when encounters line that will be replaced gathers input from rowRep in place of middle file
                rowRep.open("replacingRows.dat", ios::in);
                getline(rowRep,replace);
                strge << replace << endl; //output to storage the first line which will be the one player 2 discarded
            }    
            line++; //increments line to continue reading until false
        }
        midFle.close(); //close files for later use
        strge.close(); //          |
        midFle.open(fleNme0, ios::out); //open middle file in output mode
        strge.open("temporaryStorage.dat", ios::in); //open storage file in input mode
        while(getline(strge, replace)) //store lines from storage into replace, and then send corrected lines to middle file
            midFle << replace << endl;
        midFle.close(); //close files
        strge.close(); //     |

        line = 1; //Initialize line at 1 for proper reading
        strge.open("temporaryStorage.dat", ios::out); //open storage in output mode, repeat for correcting player's hand
        plyrFle.open(fleNmeP, ios::in); //open player file in input mode
        while(getline(plyrFle, replace)){ //Similarly will store player file in storage file until encounters row being replaced
            if(line!=plySwap)             //in which case reads from the left off line in rowRep
                strge << replace << endl; //                  |
            else{                         //                  |
                getline(rowRep,replace); //                   |
                strge << replace << endl;
                rowRep.close(); //closes file, 2 lines have already been read and swapped
            }    
            line++; //Increments line
        }
        plyrFle.close(); //closes files for later use
        strge.close(); //         |
        plyrFle.open(fleNmeP, ios::out); //open player file in output mode
        strge.open("temporaryStorage.dat", ios::in); //open storage file in input mode
        while(getline(strge, replace)) //player file will receive corrected deck of cards from storage
            plyrFle << replace << endl;
        plyrFle.close(); //close files
        strge.close();
    }    
}
void path1(fstream& hand1, string fleNme1, fstream& hand2, string fleNme2, fstream& hand0, string fleNme0){//Path if player 1 said yes to swapping initially
    char choice1, choice2, rowP, rowM;//char to for player's choices, if choice is to swap will input character for row player wants to swap with middle
    int swap1, swap2, swap0; //integers to hold rows that will be swapped from players and middle, above character rows are for input validation will be converted to integer equivalent
    bool isRow; //bool variable to determine if rows entered were valid(true) or invalid(false)
    
    do{//Will loop continuously until either player knocks, player 2 then player 1....repeats
        header(hand2, fleNme2, hand0, fleNme0); //function to display header for player2's turn, will show their cards side by side with middle cards
        do{ //Do-while loop for input validation so that will enter a valid choice for turn
            cout << "Player 2's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
            cin >> choice2; //Prompt for user to determine choice mentioned above

            if(choice2=='S'||choice2=='s'){ //Player decides to swap a card, not case sensitive
                do{ //Loop for Input validation to perform correct logic (only 1-5 rows possible)
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> rowP >> rowM; //Row input as characters
                    isRow = rowVal(rowP, rowM, swap2, swap0);//send row character as arguments alongside reference integer swap equivalent
                    if(!isRow) //if the returned bool isRow is false then will display invalid
                        cout << "Invalid!\n";
                }while(!isRow); //condition to repeat statement if an invalid row is entered
                swapLgc(hand2, fleNme2, hand0, fleNme0, swap2, swap0); //other wise perform swap using swpLgc function
            }
            else if(choice2=='P'||choice2=='p'||choice2=='K'||choice2=='k')
                cout << ""; //Do nothing for now if player chooses to knock or pass
            else //error message for invalid input
                cout << "Invalid character please choose a valid option.\n";
        }while(choice2!='S'&&choice2!='s'&&choice2!='P'&&choice2!='p'&&choice2!='K'&&choice2!='k'); //condition to repeat turn if invalid input
        cout << endl << "________________________________________________________________" << endl << endl; //next turn, improves readability
        
        //Player 1's turn, can choose option similar to player 2
        header(hand1, fleNme1, hand0, fleNme0);
        if(choice2=='K' || choice2=='k') //Informs player1 that it will be his last turn since player 2 knocked
            cout << "Last turn!!! Player 2 knocked." << endl;
        do{ //Loop for input validation to continue until valid option entered for turn
            cout << "Player 1's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
            cin >> choice1; //Prompt for player 1's turn, same options as player 2

            if(choice1=='S'||choice1=='s'){
                do{ //Loop for Input validation to perform correct logic (only 1-5 rows possible)
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> rowP >> rowM; //Prompt and input to obtain row number of each hand that will be swapped
                    isRow = rowVal(rowP, rowM, swap1, swap0);//send row character as arguments alongside reference integer swap equivalent
                    if(!isRow)//if not a valid row then will display invalid message
                        cout << "Invalid!\n";
                }while(!isRow); //condition to repeat statement if invalid row is entered
                swapLgc(hand1, fleNme1, hand0, fleNme0, swap1, swap0); //performs row swaps using swpLgc function
            }
            else if (choice1=='P'||choice1=='p'||choice1=='K'||choice1=='k')
                cout << ""; //Do nothing for now
            else //error message for invalid input
                cout << "Invalid character please choose a valid option.\n";        
        }while(choice1!='S'&&choice1!='s'&&choice1!='P'&&choice1!='p'&&choice1!='K'&&choice1!='k'); //condition to repeat initial turn options
        cout << endl << "________________________________________________________________" << endl << endl;
    }while(choice2!='K' && choice2!='k' && choice1!='K' && choice1!='k');//Repeat the round if no one knocked, player2---->player1 over and over

    if (choice2=='K'||choice2=='k') //since round started with player2 knocking will have already informed
        cout <<"Game is Finished!"; //player1 before making his move so game ends here
    else{ //player1 knocked so give player 2 one more round, player 2 will be given a chance
        header(hand2, fleNme2, hand0, fleNme0);
        cout << "Last turn!!!Player 1 knocked." << endl; //Informs last turn, only difference in logic from rest
        do {//Do-while loop for input validation
            cout << "Player 2's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
            cin >> choice2;

            if(choice2=='S'||choice2=='s'){ //Player decides to swap a card, not case sensitive
                do{ //Loop for Input validation to perform correct logic (only 1-5 rows possible)
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> rowP >> rowM; //Prompt and input to obtain row number of each hand that will be swapped
                    isRow = rowVal(rowP, rowM, swap2, swap0);
                    if(!isRow)
                        cout << "Invalid!\n";
                }while(!isRow); //condition to repeat statement if invalid row is entered
                swapLgc(hand2, fleNme2, hand0, fleNme0, swap2, swap0);
            }
            else if(choice2=='P'||choice2=='p'||choice2=='K'||choice2=='k')
                cout << ""; //Do nothing for now
            else //error display message for invalid entry
                cout << "Invalid character please choose a valid option.\n";
        }while(choice2!='S'&&choice2!='s'&&choice2!='P'&&choice2!='p'&&choice2!='K'&&choice2!='k'); //Repeat question if invalid entry for turn
        cout << endl << "________________________________________________________________" << endl << endl;
        cout << "Game is Finished!"; //End of game
    }
}
void path2(fstream& hand1, string fleNme1, fstream& hand2, string fleNme2, fstream& hand0, string fleNme0){//Other path game can take if player 1 said no initially
    char choice1, choice2, rowP, rowM;//char to for player's choices, if choice is to swap will input character for row player wants to swap with middle
    int swap1, swap2, swap0; //integers to hold rows that will be swapped from players and middle, above character rows are for input validation will be converted to integer equivalent
    bool isRow; //bool variable to determine if rows entered were valid(true) or invalid(false)
    
    do{
        header(hand1, fleNme1, hand0, fleNme0); //display header for player 1 cards alongside middle cards
        do{ //Loop for input validation to continue player 1's turn until valid option
            cout << "Player 1's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;//Prompt for player 1's turn
            cin >> choice1; 

            if(choice1=='S'||choice1=='s'){
                do{ //Loop for Input validation to perform correct logic (only 1-5 rows possible)
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> rowP >> rowM; //Row input as characters
                    isRow = rowVal(rowP, rowM, swap1, swap0);//send row character as arguments alongside reference integer swap equivalent
                    if(!isRow)//if invalid row is entered will display an invalid message
                        cout << "Invalid!\n";
                }while(!isRow); //condition to repeat statement if invalid row(s) were entered
                swapLgc(hand1, fleNme1, hand0, fleNme0, swap1, swap0);//otherwise send row numbers to swpLgc alongside files to swap
            }
            else if (choice1=='P'||choice1=='p'||choice1=='K'||choice1=='k')
                cout << ""; //Do nothing for now
            else //error message for invalid input
                cout << "Invalid character please choose a valid option.\n";        
        }while(choice1!='S'&&choice1!='s'&&choice1!='P'&&choice1!='p'&&choice1!='K'&&choice1!='k'); //condition to repeat if player enters an invalid option for turn 
        cout << endl << "________________________________________________________________" << endl << endl; // next turn

        header(hand2, fleNme2, hand0, fleNme0); //display header for player 2 cards alongside middle cards
        if(choice1=='K' || choice1=='k') //Informs player2 that it will be his last turn since player 1 knocked
            cout << "Last turn!!! Player 1 knocked." << endl;
        do{ //Do-while loop for input validation so that will enter a valid choice for turn
            cout << "Player 2's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
            cin >> choice2; //Prompt for user to determine choice mentioned above

            if(choice2=='S'||choice2=='s'){ //Player decides to swap a card, not case sensitive
                do{ //Loop for Input validation to perform correct logic (only 1-5 rows possible)
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> rowP >> rowM; //Row input as characters
                    isRow = rowVal(rowP, rowM, swap2, swap0);//send row character as arguments alongside reference integer swap equivalent
                    if(!isRow)//if invalid row is entered will display an invalid message
                        cout << "Invalid!\n";
                }while(!isRow); //condition to repeat statement if invalid row(s) are entered
                swapLgc(hand2, fleNme2, hand0, fleNme0, swap2, swap0);//otherwise send row numbers to swpLgc alongside files to swap
            }
            else if(choice2=='P'||choice2=='p'||choice2=='K'||choice2=='k')
                cout << ""; //Do nothing for now if player chooses to knock or pass
            else //error message for invalid input
                cout << "Invalid character please choose a valid option.\n";
        }while(choice2!='S'&&choice2!='s'&&choice2!='P'&&choice2!='p'&&choice2!='K'&&choice2!='k'); //condition to repeat invalid input
        cout << endl << "________________________________________________________________" << endl << endl;
    }while(choice2!='K' && choice2!='k' && choice1!='K' && choice1!='k');//Repeat the round if no one knocked, player1---->player2 over and over
    
    if (choice1=='K'||choice1=='k')//since round started with player1, knocking will have already informed
        cout <<"Game is Finished!";//player2 before making his move so game ends here
    else{ //give player 1 another attempt
        header(hand1, fleNme1, hand0, fleNme0); //display header for player 2 cards alongside middle cards
        cout << "Last turn!!!Player 2 knocked." << endl; //Informs last turn, only difference in logic
        do {//Do-while loop for input validation for turn
            cout << "Player 1's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
            cin >> choice1;
            if(choice1=='S'||choice1=='s'){ //Player decides to swap a card, not case sensitive
                do{ //Loop for Input validation to perform correct logic (only 1-5 rows possible)
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> rowP >> rowM;  //Row input as characters
                    isRow = rowVal(rowP, rowM, swap1, swap0);//send row character as arguments alongside reference integer swap equivalent
                    if(!isRow)//if invalid row is entered will display an invalid message
                        cout << "Invalid!\n";
                }while(!isRow); //condition to repeat statement if invalid row(s) are entered
                swapLgc(hand1, fleNme1, hand0, fleNme0, swap1, swap0);//otherwise send row numbers to swpLgc alongside files to swap
            }
            else if(choice1=='P'||choice1=='p'||choice1=='K'||choice1=='k')
                cout << ""; //Do nothing for now
            else //error display message for invalid entry
                cout << "Invalid character please choose a valid option.\n";
        }while(choice1!='S'&&choice1!='s'&&choice1!='P'&&choice1!='p'&&choice1!='K'&&choice1!='k'); //Repeat question if invalid entry for turn
        cout << endl << "________________________________________________________________" << endl << endl;
        cout << "Game is Finished!"; //End of game
    }
}
void header(fstream& plyrFle, string fleNmeP, fstream& midFle, string fleNme0){//function to display header for each players turn
    fstream format; //file to display header for each player's turn in a formatted perspective
    int number; //integer to determine which player's turn it is, used to display (PLAYER # CARDS)  
    string display; //string to store lines from file and output it
    number = fleNmeP == "player1Hand.dat" ? 1 : 2;//if file name entered in argument was player 1 then number will be 1 otherwise will be 2
    
    format.open("displayTable.dat", ios :: out); //Will display the players card as well as middle side by side
    plyrFle.open(fleNmeP, ios::in); //open player file in input mode
    midFle.open(fleNme0, ios::in); //open middle file in input mode

    cout << "PLAYER " << number << " CARDS\t\t\tMIDDLE CARDS" << endl //Header for display table during player's turn
          << "--------------\t\t\t--------------" << endl;
    for(int i=1; i<=5; i++){//Send data to format file for all 5 lines of both hands
        getline(plyrFle, display); //display string to store lines for display table
        format << left << setw(10) << display; //stores first card in format(char and face) with space of 10 character(largest is "F Diamonds", 10 chars)
        getline(midFle, display); //stores line from middle deck in display
        format << "\t\t\t" << display << endl; //tab for appropriate spacing, previous setw allowed for equal spacing between strings
    }
    format.close(); //close files
    plyrFle.close(); //     |
    midFle.close(); //      |

    format.open("displayTable.dat", ios :: in); //Open it again to start inputting display
    while(format){ //Perform reading until no data left, all 5 lines
        getline(format, display); //stores line with both decks in display
        cout << display << endl; //Outputs under display header, shows player's hand as well as middle hand side by side
    }
    format.close(); //close format file after done
}
void header(fstream& hand1, string fleNme1, fstream& hand2, string fleNme2, string res1, string res2){//Overloading header function, this one has two more
    fstream format;//file to display header for final results in a formatted perspective              //parameters & displays final hands rather than player & middle
    string display; //string to store lines from file and output it
    
    format.open("displayTable.dat", ios :: out); //Will display both player's cards, first player1 then player 2
    hand1.open(fleNme1, ios::in); //open player 1 file in input mode
    hand2.open(fleNme2, ios::in); //open player 2 file in input mode

    cout << "PLAYER 1 CARDS\t\t\tPLAYER 2 CARDS" << endl //small header for display table
          << "--------------\t\t\t--------------" << endl;
    for(int i=1; i<=5; i++){//Send data to format file for all 5 lines of both hands
        getline(hand1, display); //display string to obtain lines for display table
        format << left << setw(10) << display; //stores player 1 card, char and face, in display & sends to format file
        getline(hand2, display); //stores card from player 2 deck in display
        format << "\t\t\t" << display << endl; //tab for appropriate spacing, previous setw allowed for equal spacing between strings
    }
    format.close(); //close files
    hand1.close(); //     |
    hand2.close(); //     |

    format.open("displayTable.dat", ios :: in); //Open format again to start inputting display, in input mode
    while(format){ //Perform reading until no data left, all 5 lines
        getline(format, display); //stores line with both decks in display
        cout << display << endl; //Outputs under display header, shows player 1 card as well as player 2 card
    }
    format.close(); //close format file   
    
    cout << "Player 1: " << res1 << endl //Inform players the hands they obtained from parameter arguments
         << "Player 2: " << res2 << endl;
}
void bubSort(char crdLst[][11], int plyr[], int rowMax){//sorts numerical hand of player[] and swap if needed, both int[] and char[][] are swapped accordingly(parallel)
    bool swap; //bool flag to determine if swapping occurred
    int temp; //holds integer value for player numeric face card representation 1-13
    char replace[11]; //holds row/string to replace from 2D char array (crdLst)
    do{
        swap = false; //Initialize swap flag to false
        for(int index = 0; index < rowMax-1; index++){//loop for one less than number of cards since will evaluate one higher in loop
            if(plyr[index+1] > plyr[index]){ //swap to make higher cards appear first, numerically descending
                swap = true; //reassign swap flag to true since swapping will occur
                temp = plyr[index]; //store the smaller value in temp
                plyr[index] = plyr[index+1]; //assign previous element the higher value
                plyr[index+1] = temp; //assign the previously bigger element the new smaller one from temp
                //must also swap rows in char 2D array which holds actual cards(eg. "2 Diamonds")
                strcpy(replace, crdLst[index]); //copy string row into replace 
                strcpy(crdLst[index], crdLst[index+1]); //copy higher value card row into previously smaller index
                strcpy(crdLst[index+1], replace);//copy smaller value card row into previously bigger index
            }
        }
    }while(swap); //condition to repeat if swapping still occurs
}
void selSort(char crdLst[][11], int plyr[], int rowMax){//sorts cards from player 2 using selection sort
    int maxIndx, //records maximum index of highest value
        maxVal; //records the highest value
    char replace[11];

    for(int index = 0; index < rowMax-1; index++){//loop for entire hand(5 times)
        maxVal=plyr[index]; //initialize max value to current element from index
        maxIndx=index; //initialize max index to loop index
        for(int count = index +1; count < rowMax; count++){//inner loop to scan through all subsequent values for bigger values
            if(plyr[count]>maxVal){//condition if bigger value is encountered throughout inner loop
                maxVal=plyr[count];//re-initialize max value to element from count
                maxIndx=count; //re-initialize max index to count
            }
        }
        //after scanning complete for outer loop index iteration swap it
        plyr[maxIndx] = plyr[index]; //assign to the element where max values was found the current index element
        plyr[index]=maxVal; //assign current element from index the the largest value
        strcpy(replace, crdLst[maxIndx]); //similarly copy row strings to replace alongside integer array[], they work in parallel
        strcpy(crdLst[maxIndx], crdLst[index]);
        strcpy(crdLst[index], replace);    
    }       
}
void revert(char crdLst[][11], int plyr[], int rowMax){ //function to revert player integer array into order in which cards are in for crdLst
    for(int row = 0; row < rowMax; row++){ //repeat loop for rowMax times(5)
        plyr[row] = crdLst[row][0] == 'A' ? 1 : //conditional operator to assign corresponding integer (1-13) into player array
                    crdLst[row][0] == '2' ? 2 : //                                 |
                    crdLst[row][0] == '3' ? 3 : //                                 |
                    crdLst[row][0] == '4' ? 4 : //                                 |
                    crdLst[row][0] == '5' ? 5 : //                                 |
                    crdLst[row][0] == '6' ? 6 : //                                 |
                    crdLst[row][0] == '7' ? 7 : //                                 |
                    crdLst[row][0] == '8' ? 8 : //                                 |
                    crdLst[row][0] == '9' ? 9 : //                                 |
                    crdLst[row][0] == 'T' ? 10: //                                 |
                    crdLst[row][0] == 'J' ? 11: //                                 |
                    crdLst[row][0] == 'Q' ? 12: 13;                                        
    }
}
string analyze(fstream& hand, string fleNme, int num[],int& score){//function to return hand attained by player, already sorted at this point
    string result; //stores the players hand obtained(eg. "Royal Flush")
    char junk; //simple char variable to rid the junk face values(will compare using player integer array not face values)
    string suit[5]; //string array to hold suits of players card
    bool onePair; //bool variable to determine between one pair or two pairs
    
    hand.open(fleNme, ios::in); //open player file in input mode to obtain suits
    for(int index=0; index < 5; index++) //loop for all 5 cards
        hand >> junk >> suit[index]; //store suits in suit array
    hand.close(); //close player file
   
    if((num[0]==num[1]&&num[1]==num[2]&&num[2]==num[3])||(num[4]==num[3]&&num[3]==num[2]&&num[2]==num[1]))
            result="4 of a Kind", score=3;//Having a 4 of a kind means will not have a royal flush or straight flush so will always give higher regardless
    else if((num[0]==num[1]&&num[1]==num[2]&&num[3]==num[4])||(num[4]==num[3]&&num[3]==num[2]&&num[1]==num[0]))//a 3 of a kind and a pair will give full house
            result="Full House", score=4;
    else if(suit[0]==suit[1]&&suit[1]==suit[2]&&suit[2]==suit[3]&&suit[3]==suit[4]){//nested if else statements to determine type of flush obtained
        if(num[4]==1&&num[0]==13&&num[1]==12&&num[2]==11&&num[3]==10)
            result="Royal Flush", score=1;
        else if (num[0]==num[1]+1&&num[1]==num[2]+1&&num[2]==num[3]+1&&num[3]==num[4]+1)
            result="Straight Flush", score=2;
        else
            result="Flush", score=5;
    }
    else if((num[0]==num[1]+1&&num[1]==num[2]+1&&num[2]==num[3]+1&&num[3]==num[4]+1) //considers normal ascending cards of any value
            ||(num[4]==1&&num[0]==13&&num[1]==12&&num[2]==11&&num[3]==10))//consider if ace was present in the case of K,Q,J,&T
        result="Straight", score=6;
    else if ((num[0]==num[1]&&num[1]==num[2])||(num[1]==num[2]&&num[2]==num[3])||(num[2]==num[3]&&num[3]==num[4]))
        result="3 of a Kind", score=7; //two possible methods to obtain 3 of a Kind, first 3 same or last 3 same
    else if(num[0]==num[1]||num[1]==num[2]||num[2]==num[3]||num[3]==num[4]){ //determines if one pair was encountered
        int count=0;
        if(num[0]==num[1])//initialize temp to 0 and every time a pair is encountered increment
            count++;
        if(num[1]==num[2])
            count++;
        if(num[2]==num[3])
            count++;
        if(num[3]==num[4])
            count++;
        onePair = (count == 1);//will assign true if indeed is a pair or false if its two pairs were encountered
        result = (onePair) ? "One Pair" : "Two Pairs";
        score = (onePair) ? 9 : 8;
    }       
    else
        result="High Card", score=10; //otherwise lowest hand received will be a high card
    return result; //return the players result, his score is referenced
}
void calcDev(float& stdDev1, int score1, float& stdDev2, int score2){
    static int count = 0; //keeps track of how many times function is called so that proper 
                         //average & #data point can be calculated and then applied to standard deviation 
    fstream dvtn1, dvtn2; //file to hold scores from both players over series of games
    float sum, mean; //float variables to calculate sum and mean within standard deviation calculation
    unsigned short temp; //temporary integer too read in scores(ints) from files and add it to sum
    
    if (count == 0){ //Clear file contents of std deviation for both plater 1 and player 2 if first time running program
        dvtn1.open("p1Deviation.dat",ios::out); //opening file in out will create new one, overwriting the original
        dvtn2.open("p2Deviation.dat",ios::out); //                                |
        dvtn1.close(); //close files
        dvtn2.close(); //     |
    }
    count++; //Increment counter to start calculation of standard deviation
    //PLAYER 1 STANDARD DEVIATION
    dvtn1.open("p1Deviation.dat",ios::app); //open file for player 1 deviation in append mode to prevent overriding data
    dvtn1<<score1<<endl; //send current score 1 to file
    dvtn1.close(); //close file

    sum=0; //initialize to 0 for proper sum and mean
    mean=0;
    dvtn1.open("p1Deviation.dat",ios::in); //open in input mode
    while(dvtn1>>temp)//read all file contents then close
        sum+=temp;//each term added to the sum
    mean=sum/count; //mean determined by dividing sum by static variable(was only initialized once then incremented each time for game count)
    dvtn1.close(); //close file

    dvtn1.open("p1Deviation.dat",ios::in); //open in input mode
    sum=0; //initialize to 0 again to find sum of squared differences
    while(dvtn1>>temp)
        sum+=pow((temp-mean), 2);//sum of squared differences
    dvtn1.close();
    stdDev1=sqrt(sum/count);//sqrt the sum of squared difference divide by number of instances
    
    //PLAYER 2 STANDARD DEVIATION
    dvtn2.open("p2Deviation.dat",ios::app); //open file for player 2 deviation in append mode to prevent overriding data
    dvtn2<<score2<<endl; //send current score 2 to file
    dvtn2.close(); //close file

    sum=0; //initialize to 0 for proper sum and mean
    mean=0;
    dvtn2.open("p2Deviation.dat",ios::in); //open in input mode
    while(dvtn2>>temp)//read all file contents then close
        sum+=temp;//each term added to the sum
    mean=sum/count;
    dvtn2.close(); //close file

    dvtn2.open("p2Deviation.dat",ios::in); //open in input mode
    sum=0; //initialize to 0 again to find sum of squared differences
    while(dvtn2>>temp)
        sum+=pow((temp-mean), 2);//sum of squared differences
    dvtn2.close();
    stdDev2=sqrt(sum/count);//sqrt the sum of squared difference divide by number of instances
}
bool rowVal(char rowP, char rowM, int& swapP, int& swapM){//Validates row swap of player and row swap of middle(has to be 1-5)
    if (rowP >= '1' && rowP <= '5')//condition if row swap from player's deck falls within range
        swapP = rowP - '0'; //if yes subtract ASCII character entered value with ASCII value of '0'
    else
        return false;//otherwise return false which will require player to enter again
    if(rowM >= '1' && rowM <= '5') //condition if row swap from middle deck falls within range
        swapM = rowM - '0'; //if yes subtract ASCII character entered value with ASCII value of '0'
    else
        return false;//otherwise return false which will require player to enter again
    return true; //if passes test conditions then will proceed by returning true
}