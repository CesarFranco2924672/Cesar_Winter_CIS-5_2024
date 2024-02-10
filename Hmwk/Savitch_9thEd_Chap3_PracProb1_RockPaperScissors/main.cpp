/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 13, 2024, 2:56 PM
 * Purpose:  Determines winner of rock, paper, scissors and says reason why
 */
 
 //System Libraries
#include <iostream> 
using namespace std;

//Execution Begins Here!
int main() 
{ 
    //Declare Variables
    char player1, player2; //choice that player makes in rock, paper, scissors
    
    //prompt user to input player1 and player2 choice
    cout << "Rock Paper Scissors Game" << endl 
         << "Input Player 1 and Player 2 Choices" <<endl; 

    cin.get(player1); //used a getline function to input char variable
    cin.ignore(); //ignore the newline character or any other blank space that is entered directly after inputting player 1
    cin.get(player2); //obtains player 2's choice
    cin.ignore();

    //Display the outputs
    switch (player1) //switch statement using player 1's response
    { 
        case 'R': //six possible responses from player 1 so 6 cases total
            if (player2 == 'R' || player2 == 'r') //3 valid options game can play out
                cout << "Nobody wins."; 
            else if (player2 == 'P' || player2 == 'p') 
                cout << "Paper covers rock."; 
            else if (player2 == 'S' || player2 == 's') 
                cout << "Rock breaks scissors."; 
            else
                cout << "Invalid character. Please enter a valid character."; 
            break; // break statement to stop other cases from executing
            
        case 'r': 
            if (player2 == 'R' || player2 == 'r') 
                cout << "Nobody wins.";
            else if (player2 == 'P' || player2 == 'p') 
                cout << "Paper covers rock."; 
            else if (player2 == 'S' || player2 == 's') 
                cout << "Rock breaks scissors.";
            else
                cout << "Invalid character. Please enter a valid character."; //reports to user an invalid choice was entered
            break; 

        case 'P': //if else statements to find valid seed of the game after appropriate case is determined
            if (player2 == 'R' || player2 == 'r') 
                cout << "Paper covers rock."; 
            else if (player2 == 'P' || player2 == 'p') 
                cout << "Nobody wins."; 
            else if (player2 == 'S' || player2 == 's') 
                cout << "Scissors cuts paper."; 
            else
                cout << "Invalid character. Please enter a valid character."; 
            break; 

        case 'p': 
            if (player2 == 'R' || player2 == 'r') 
                cout << "Paper covers rock."; 
            else if (player2 == 'P' || player2 == 'p') 
                cout << "Nobody wins."; 
            else if (player2 == 'S' || player2 == 's') 
                cout << "Scissors cuts paper."; 
            else    
                cout << "Invalid character. Please enter a valid character."; 
            break; 

        case 'S': 
            if (player2 == 'R' || player2 == 'r') 
                cout << "Rock breaks scissors"; 
            else if (player2 == 'P' || player2 == 'p') 
                cout << "Scissors cuts paper."; 
            else if (player2 == 'S' || player2 == 's') 
                cout << "Nobody wins."; 
            else
                cout << "Invalid character. Please enter a valid character."; 
            break; 

        case 's': 
            if (player2 == 'R' || player2 == 'r') 
                cout << "Rock breaks scissors"; 
            else if (player2 == 'P' || player2 == 'p') 
                cout << "Scissors cuts paper."; 
            else if (player2 == 'S' || player2 == 's') 
                cout << "Nobody wins."; 
            else   
                cout << "Invalid character. Please enter a valid character."; 
            break; 

        default : cout << "Invalid character. Please enter a valid character."; 
    } 
//Exit stage right or left!    
return 0; 
} 
