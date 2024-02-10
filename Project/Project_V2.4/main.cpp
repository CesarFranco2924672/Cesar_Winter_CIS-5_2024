/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 23, 2024, 2:53 PM
 * Purpose: Game Project for CIS-5
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <iomanip> //Format Library
#include <cmath> //Math Library
#include <cstdlib> //To use random number generator
#include <fstream> //File Library, for input & output
#include <cstring> //String Library
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

//Program Execution Begins Here
int main(int argc, char** argv){
    //Set a random seed
    srand(static_cast<unsigned short>(time(0)));
    //Declare all Variables
    const unsigned short SIZE = 5,
                         COL = 11; //Face Character + Diamonds suit will be max columns (10) then null,including space
    int play1[SIZE],//Number values of hand 1-52 for each player and middle
        play2[SIZE],        
        play0[SIZE],
        score1, //records score of current game round for player 1
        score2; //records score of current game round for player 2
    
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
    //Declare files
    fstream hand1, //where player 1 hand is stored (with face and suit)
            hand2, //player2....
            hand0; //middle hand....
             
    //Deal numerical hand for each player, player 0 is middle
    dealt(play1, SIZE, allCard);    
    dealt(play2, SIZE, allCard);
    dealt(play0, SIZE, allCard);
    
    //Convert numerical Hand into card hand with face and suit, store it in respective file hand
    convert(play1, SIZE, hand1, fleNme1);
    convert(play2, SIZE, hand2, fleNme2);
    convert(play0, SIZE, hand0, fleNme0);
    
    //Initial round 0, ask player1 if they would like to swap for middle
    cout << "PLAYER 1 CARDS" << endl
         << "--------------" << endl;
    hand1.open(fleNme1, ios::in); 
    for(int row=1; row<=5; row++){
        getline(hand1, display);
        cout << display << endl;
    }
    hand1.close();
    cout << "\nPlayer 1, Would you like to swap your hand for the Middle one: ";
         
    do{ //Do-While loop to repeat task if invalid choice is entered
        cin >> choice1;
        switch (choice1){ //Switch loop to evaluate entries, break statement to only perform one
            case 'Y':{ //Player1 decides to swap
                swapLgc(hand1, fleNme1, hand0, fleNme0);           
                break;
            }
            case 'y':{ 
                swapLgc(hand1, fleNme1, hand0, fleNme0);                              
                break;
            }
            case 'N': break; //If player1 doesn't decide to swap cards do nothing
            case 'n': break; //                    |
            default: //Informs player of invalid entry and to re-enter an option
                cout << "Enter a valid option for YES or for NO: ";            
        }   
    }while(choice1 != 'Y' && choice1 != 'y' && choice1 != 'N' && choice1 != 'n'); //Evaluates if condition for while loop is met
    cout << endl << "________________________________________________________________" << endl << endl;
    if (choice1 == 'Y' || choice1 == 'y'){
        path1(hand1, fleNme1, hand2, fleNme2, hand0, fleNme0);
    }
    else{
        cout << "PLAYER 2 CARDS" << endl
                  << "--------------" << endl;
            hand2.open(fleNme2, ios::in); 
            for(int row=1; row<=5; row++){
                getline(hand2, display);
                cout << display << endl;
            }
            hand2.close();
        cout << "\nPlayer 2, Would you like to swap your hand for the Middle one: ";

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
                case 'N': break; //If player1 doesn't decide to swap cards do nothing
                case 'n': break; //                    |
                default: //Informs player of invalid entry and to re-enter an option
                    cout << "Enter a valid option for YES or for NO: ";            
            }   
        }while(choice2 != 'Y' && choice2 != 'y' && choice2 != 'N' && choice2 != 'n'); //Evaluates if condition for while loop is met
        cout << endl << "________________________________________________________________" << endl << endl; 
        path2(hand1, fleNme1, hand2, fleNme2, hand0, fleNme0);
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
          
    //Process or Map Solutions
    
    //Display the Output
    
    //Exit the Program
    return 0;
}
void dealt(int player[], const int size, vector<int>& allCard){
    for(int index = 0; index < size; index++){
        player[index] = unique(allCard);
    }
}
int unique(vector<int>& allCard){
    const unsigned short deckSze = 52;
    unsigned short cardNum;
    bool found;
    do{
        found = false;
        cardNum = rand()%deckSze+1;
        for(int index = 0; index < allCard.size(); index++){
            if(allCard[index] == cardNum)
                found = true;        
        }        
    }while(found);
    allCard.push_back(cardNum);
    return cardNum;
}
void convert(int a[], const int size, fstream& hand, string fleNme){
    string suit;
    char face;
    hand.open(fleNme, ios::out);
    if(!hand){
        cout << "Error opening file";
        exit(1);
    }
    else{
        for(int index = 0; index < size; index++){
            suit = (a[index] >= 1  && a[index] <=13) ? "Diamonds" :
                   (a[index] >= 14 && a[index] <=26) ? "Hearts" :
                   (a[index] >= 27 && a[index] <=39) ? "Spades" : "Clubs";

            face = a[index]== 1 || a[index]==14 || a[index]==27 || a[index]==40 ? 'A' : //ternary operator to determine appropriate face
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
            hand << face << " " << suit << endl;
        }    
        hand.close();  
    }
}
void swapLgc(fstream& plyrFle, string fleNmeP, fstream& midFle,string fleNme0, int plySwap, int midSwap){
    fstream strge,
            rowRep;
    string replace;
    int line;
    if(plySwap == 0 && midSwap == 0){//Default values for parameter, means that this is initial swap for entire hand
            //Send player hand to storage file
            plyrFle.open(fleNmeP, ios::in);
            strge.open("temporaryStorage.dat", ios::out);
            while(getline(plyrFle,replace))
                strge << replace << endl;
            plyrFle.close();
            strge.close();

            //Send middle hand to player file
            midFle.open(fleNme0, ios::in);
            plyrFle.open(fleNmeP, ios::out);
            while(getline(midFle,replace))
                plyrFle << replace << endl;
            midFle.close();
            plyrFle.close();

            //send storage to middle file
            strge.open("temporaryStorage.dat", ios::in);
            midFle.open(fleNme0, ios::out);
            while(getline(strge,replace))
                midFle << replace << endl;
            strge.close();
            midFle.close();
    }
    else{
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
        while(getline(midFle, replace)){ //perform same logic on hand0, middle deck
            rowRep << (line == midSwap ? replace : ""); //rowRep will contain the row player 2 wants to replace first then middle row
            line++;
        }
        midFle.close(); //close files for later use
        plyrFle.close(); //           |
        rowRep.close();//             |

        strge.open("temporaryStorage.dat", ios::out); //open in output mode      
        line = 1; //initialize at hand 1
        midFle.open(fleNme0, ios::in); //open in input mode
        while(getline(midFle, replace)){ //transfers content of middle hand, hand0, except line that will be replaced.
            if(line!=midSwap)             
                strge << replace << endl;
            else{ //when encounters line that will be replaced gathers input from rowRep in place of hand0
                rowRep.open("replacingRows.dat", ios::in); //open in input mode
                getline(rowRep,replace);
                strge << replace << endl;
            }    
            line++; //increments line to continue reading until false
        }
        midFle.close(); //close files for later use
        strge.close(); //          |
        midFle.open(fleNme0, ios::out); //open in output mode
        strge.open("temporaryStorage.dat", ios::in); //open in input mode
        while(getline(strge, replace)) //hand 0 will receive the new hand with swapped line from storage file
            midFle << replace << endl;
        midFle.close(); //close files
        strge.close(); //     |

        line = 1; //Initialize line at 1 for proper reading
        strge.open("temporaryStorage.dat", ios::out); //open in output mode
        plyrFle.open(fleNmeP, ios::in); //open in input mode
        while(getline(plyrFle, replace)){ //Similarly will store hand2 in storage file until encounters row being replaced
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
        plyrFle.open(fleNmeP, ios::out); //open in output mode
        strge.open("temporaryStorage.dat", ios::in); //open in input mode
        while(getline(strge, replace)) //hand2 file will receive new and fixed deck of cards
            plyrFle << replace << endl;
        plyrFle.close(); //close files for later use
        strge.close();
    }    
}
void path1(fstream& hand1, string fleNme1, fstream& hand2, string fleNme2, fstream& hand0, string fleNme0){
    fstream format;
    string display;
    char choice1, choice2;
    int swap1, swap2, swap0;
    
    do{//Will loop continuously until either player knocks
        header(hand2, fleNme2, hand0, fleNme0);
       /////////////////////////////////////////////////////////////////////////////////////
        do{ //Do-while loop for input validation so that will enter a valid choice
            cout << "Player 2's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
            cin >> choice2; //Prompt for user to determine choice mentioned above

            if(choice2=='S'||choice2=='s'){ //Player decides to swap a card, not case sensitive
                do{ //Loop for Input validation to perform correct logic (only 1-5 rows possible)
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> swap2 >> swap0; //Prompt and input to obtain row number of each hand that will be swapped
                    if(swap2<1 || swap2>5 ||swap0<1 || swap0>5)
                        cout << "Invalid!\n";
                }while(swap2<1 || swap2>5 ||swap0<1 || swap0>5); //condition to repeat statement if invalid
                
                swapLgc(hand2, fleNme2, hand0, fleNme0, swap2, swap0);
            }
            else if(choice2=='P'||choice2=='p'||choice2=='K'||choice2=='k')
                cout << ""; //Do nothing for now if player chooses to knock or pass
            else //error message for invalid input
                cout << "Invalid character please choose a valid option.\n";
        }while(choice2!='S'&&choice2!='s'&&choice2!='P'&&choice2!='p'&&choice2!='K'&&choice2!='k'); //condition to repeat invalid input
        cout << endl << "________________________________________________________________" << endl << endl;
        
        //Player 1's turn, can choose option similar to player 2
        header(hand1, fleNme1, hand0, fleNme0);

        if(choice2=='K' || choice2=='k') //Informs player1 that it will be his last turn since player 2 knocked
            cout << "Last turn!!! Player 2 knocked." << endl;
        do{ //Loop for input validation to continue until valid option
            cout << "Player 1's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
            cin >> choice1; //Prompt for player 1's turn, same options as player 2

            if(choice1=='S'||choice1=='s'){
                do{//Repeat if player enters invalid row
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> swap1 >> swap0;
                    if(swap1<1 || swap1>5 ||swap0<1 || swap0>5)
                        cout << "Invalid!\n";
                }while(swap1<1 || swap1>5 ||swap0<1 || swap0>5);

                swapLgc(hand1, fleNme1, hand0, fleNme0, swap1, swap0);
            }
            else if (choice1=='P'||choice1=='p'||choice1=='K'||choice1=='k')
                cout << ""; //Do nothing for now
            else //error message for invalid input
                cout << "Invalid character please choose a valid option.\n";        
        }while(choice1!='S'&&choice1!='s'&&choice1!='P'&&choice1!='p'&&choice1!='K'&&choice1!='k'); //condition to repeat initial options
        cout << endl << "________________________________________________________________" << endl << endl;
    }while(choice2!='K' && choice2!='k' && choice1!='K' && choice1!='k');//Repeat the round if no one knocked, player2---->player1 over and over

    if (choice2=='K'||choice2=='k')//since round started with player2 knocking will have already informed
        cout <<"Game is Finished!";//player1 before making his move so game ends here
    else{ //player1 knocked so give player 2 one more round, player 2 will be given a chance
        header(hand2, fleNme2, hand0, fleNme0);
        cout << "Last turn!!!Player 1 knocked." << endl; //Informs last turn, only difference in logic
        do {//Do-while loop for input validation
            cout << "Player 2's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
            cin >> choice2;

            if(choice2=='S'||choice2=='s'){ //Player decides to swap a card, not case sensitive
                do{ //Loop for Input validation to perform correct logic (only 1-5 rows possible)
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> swap2 >> swap0; //Prompt and input to obtain row number of each hand that will be swapped
                    if(swap2<1 || swap2>5 ||swap0<1 || swap0>5)
                        cout << "Invalid!\n";
                }while(swap2<1 || swap2>5 ||swap0<1 || swap0>5); //condition to repeat statement if invalid
                
                swapLgc(hand2, fleNme2, hand0, fleNme0, swap2, swap0);
            }
            else if(choice2=='P'||choice2=='p'||choice2=='K'||choice2=='k')
                cout << ""; //Do nothing for now
            else //error display message for invalid entry
                cout << "Invalid character please choose a valid option.\n";
        }while(choice2!='S'&&choice2!='s'&&choice2!='P'&&choice2!='p'&&choice2!='K'&&choice2!='k'); //Repeat question if invalid
        cout << endl << "________________________________________________________________" << endl << endl;
        cout << "Game is Finished!"; //End of game
    }
}
void path2(fstream& hand1, string fleNme1, fstream& hand2, string fleNme2, fstream& hand0, string fleNme0){
    fstream format;
    string display;
    char choice1, choice2;
    int swap1, swap2, swap0;
    
    do{
        header(hand1, fleNme1, hand0, fleNme0);  
        do{ //Loop for input validation to continue until valid option
            cout << "Player 1's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
            cin >> choice1; //Prompt for player 1's turn, same options as player 2

            if(choice1=='S'||choice1=='s'){
                do{//Repeat if player enters invalid row
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> swap1 >> swap0;
                    if(swap1<1 || swap1>5 ||swap0<1 || swap0>5)
                        cout << "Invalid!\n";
                }while(swap1<1 || swap1>5 ||swap0<1 || swap0>5);

                swapLgc(hand1, fleNme1, hand0, fleNme0, swap1, swap0);
            }
            else if (choice1=='P'||choice1=='p'||choice1=='K'||choice1=='k')
                cout << ""; //Do nothing for now
            else //error message for invalid input
                cout << "Invalid character please choose a valid option.\n";        
        }while(choice1!='S'&&choice1!='s'&&choice1!='P'&&choice1!='p'&&choice1!='K'&&choice1!='k');
        cout << endl << "________________________________________________________________" << endl << endl;

        header(hand2, fleNme2, hand0, fleNme0);
        if(choice1=='K' || choice1=='k') //Informs player2 that it will be his last turn since player 1 knocked
            cout << "Last turn!!! Player 1 knocked." << endl;
        do{ //Do-while loop for input validation so that will enter a valid choice
            cout << "Player 2's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
            cin >> choice2; //Prompt for user to determine choice mentioned above

            if(choice2=='S'||choice2=='s'){ //Player decides to swap a card, not case sensitive
                do{ //Loop for Input validation to perform correct logic (only 1-5 rows possible)
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> swap2 >> swap0; //Prompt and input to obtain row number of each hand that will be swapped
                    if(swap2<1 || swap2>5 ||swap0<1 || swap0>5)
                        cout << "Invalid!\n";
                }while(swap2<1 || swap2>5 ||swap0<1 || swap0>5); //condition to repeat statement if invalid

                swapLgc(hand2, fleNme2, hand0, fleNme0, swap2, swap0);
            }
            else if(choice2=='P'||choice2=='p'||choice2=='K'||choice2=='k')
                cout << ""; //Do nothing for now if player chooses to knock or pass
            else //error message for invalid input
                cout << "Invalid character please choose a valid option.\n";
        }while(choice2!='S'&&choice2!='s'&&choice2!='P'&&choice2!='p'&&choice2!='K'&&choice2!='k'); //condition to repeat invalid input
        cout << endl << "________________________________________________________________" << endl << endl;
    }while(choice2!='K' && choice2!='k' && choice1!='K' && choice1!='k');//Repeat the round if no one knocked, player1---->player2 over and over
    
    if (choice1=='K'||choice1=='k')//since round started with player1 knocking will have already informed
        cout <<"Game is Finished!";//player2 before making his move so game ends here
    else{ //give player 1 another attempt
        header(hand1, fleNme1, hand0, fleNme0);
        cout << "Last turn!!!Player 2 knocked." << endl; //Informs last turn, only difference in logic
        do {//Do-while loop for input validation
            cout << "Player 1's turn, Enter p-->pass, k-->knock, or s-->swap one card" << endl;
            cin >> choice1;
            if(choice1=='S'||choice1=='s'){ //Player decides to swap a card, not case sensitive
                do{ //Loop for Input validation to perform correct logic (only 1-5 rows possible)
                    cout << "Enter the row from your deck that you'd like to swap(1-5). Then enter the middle row you'd like to swap it with.\n";
                    cin >> swap1 >> swap0; //Prompt and input to obtain row number of each hand that will be swapped
                    if(swap1<1 || swap1>5 ||swap0<1 || swap0>5)
                        cout << "Invalid!\n";
                }while(swap1<1 || swap1>5 ||swap0<1 || swap0>5); //condition to repeat statement if invalid
                
                swapLgc(hand1, fleNme1, hand0, fleNme0, swap1, swap0);
            }
            else if(choice1=='P'||choice1=='p'||choice1=='K'||choice1=='k')
                cout << ""; //Do nothing for now
            else //error display message for invalid entry
                cout << "Invalid character please choose a valid option.\n";
        }while(choice1!='S'&&choice1!='s'&&choice1!='P'&&choice1!='p'&&choice1!='K'&&choice1!='k'); //Repeat question if invalid
        cout << endl << "________________________________________________________________" << endl << endl;
        cout << "Game is Finished!"; //End of game
    }
}
void header(fstream& plyrFle, string fleNmeP, fstream& midFle, string fleNme0){
    fstream format;
    int number;
    string display;
    number = fleNmeP == "player1Hand.dat" ? 1 : 2;
    
    format.open("displayTable.dat", ios :: out); //Will display the players card as well as middle side by side
    plyrFle.open(fleNmeP, ios::in); //open player file in input mode
    midFle.open(fleNme0, ios::in); //open middle file in input mode

    cout << "PLAYER " << number << " CARDS\t\t\tMIDDLE CARDS" << endl //Header for display table during player 2's turn
          << "--------------\t\t\t--------------" << endl;
    for(int i=1; i<=5; i++){//Send data to format file for all 5 lines of both hands
        getline(plyrFle, display); //display string to obtain lines for display table
        format << left << setw(10) << display; //stores first card, char and face, in display & sends to format file
        getline(midFle, display); //stores line from middle deck in display
        format << "\t\t\t" << display << endl; //tab for appropriate spacing, previous setw allowed for equal spacing between strings
    }
    format.close(); //close files
    plyrFle.close(); //     |
    midFle.close(); //     |

    format.open("displayTable.dat", ios :: in); //Open it again to start inputting display
    while(format){ //Perform reading until no data left, all 5 lines
        getline(format, display); //stores line with both decks in display
        cout << display << endl; //Outputs under display header, shows player 2 hand as well as middle hand
    }
    format.close(); //close file for later use
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