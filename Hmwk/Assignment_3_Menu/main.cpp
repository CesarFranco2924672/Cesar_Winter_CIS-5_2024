/* 
 * File:   main.cpp
 * Author: Cesar Franco
 * Created on January 4, 2024, 1:53 PM
 * Purpose: Menu for Homework Assignment 3
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <iomanip> //Format Library
#include <string> //String Library
using namespace std;

//Program Execution Begins Here
int main(int argc, char** argv)
{
    //Declare all Variables
    short int probNum; //Problem number from homework
    
    do
    {
        //Display Menu
        cout << "\n\nThis Is A Menu For Homework Assignment 3" << endl // new line escape sequence so that loop starts on new line
             << "\tProblem#1: Book points" <<endl
             << "\tProblem#2: Bank Charges" <<endl
             << "\tProblem#3: Race Results" <<endl
             << "\tProblem#4: ISP" <<endl
             << "\tProblem#5: Sort Names Alphabetically" <<endl
             << "\tProblem#6: Rock, Paper, Scissors" <<endl
             << "\tProblem#7: Compatible Horoscope Signs" <<endl
             << "\tProblem#8: Roman Conversion" <<endl
             << "Enter Corresponding Digit For Desired Problem" << endl;
        cin >> probNum; //Input for which problem to display
        
        cout << endl;

        switch (probNum)
        {
            case 1:
            {
                //Declare Variables
                unsigned short books, points;

                //Initialize or input i.e. set variable values
                books = 0,
                points = 0;

                //Map inputs -> outputs
                cout << "Book Worm Points" << endl
                     << "Input the number of books purchased this month." << endl;

                cin >> books;

                books >= 4 ? points = 60 : //Use ternary operator to find scenario that is valid
                books == 3 ? points = 30 :
                books == 2 ? points = 15 :
                books == 1 ? points = 5 :
                books == 0 ? points = 0 : 0;

                //Display the outputs
                cout << "Books purchased =" << setw(3) << books << endl
                     << "Points earned   =" << setw(3) << points;

                break;
            }

            case 2:
            {
                //Declare Variables
                short int checks; //Number of checks cashed
                float curBlnc, //Current Balance
                      rate, //Service fee for each check
                      chckFee, //Total check fees
                      mnthFee, //month fee
                      lowBlnc, //Charge based on current balance
                      newBlnc; //New balance after costs

                //Initialize or input i.e. set variable values
                mnthFee = 10; //Constant fee

                //Map inputs -> outputs
                cout << "Monthly Bank Fees" << endl
                     << "Input Current Bank Balance and Number of Checks" << endl;

                cin >> curBlnc >> checks;

                //Execution based on Balance amount
                if (curBlnc >= 400)
                    lowBlnc = 0;
                else if (curBlnc < 400 && curBlnc >=0)
                    lowBlnc = 15;
                else 
                {
                    lowBlnc = 15;
                    cout << "The Account is Overdrawn." << endl;
                }

                //Execution based on check amount
                if (checks >= 60)
                        rate = .04;
                else if (checks >= 40 && checks < 60)
                        rate = .06;
                else if (checks >= 20 && checks < 40)
                        rate = .08;
                else if (checks < 20 && checks >= 0)
                        rate = .10;
                else 
                {
                    cout << "Please enter a non-negative value for checks.\n";
                    curBlnc = 0, // Blank default assignment
                    chckFee = 0,
                    mnthFee = 0,
                    lowBlnc = 0,
                    newBlnc = 0;
                }

                chckFee = checks * rate,
                newBlnc = curBlnc - mnthFee - chckFee - lowBlnc;

                //Display the Outputs
                cout << showpoint << fixed << setprecision(2)
                     << "Balance     $" << setw(9) << curBlnc << endl 
                     << "Check Fee   $" << setw(9) << chckFee << endl 
                     << "Monthly Fee $" << setw(9) << mnthFee << endl 
                     << "Low Balance $" << setw(9) << lowBlnc << endl 
                     << "New Balance $" << setw(9) << newBlnc;

                break;
            }

            case 3:
            {
                //Declare Variables
                string name1, name2, name3; //name of each runner
                short time1, time2, time3; //time finished race in seconds presumably

                //Initialize or input i.e. set variable values
                time1 = time2 = time3 = 0;

                //Map inputs -> outputs
                cout << "Race Ranking Program" << endl
                    << "Input 3 Runners" << endl
                    << "Their names, then their times" << endl;


                cin >> name1 >> time1 //inputs name followed by time
                    >> name2 >> time2
                    >> name3 >> time3;

                //Display the Outputs 
                if (time1 < 0 || time2 < 0 || time3 < 0) //if an invalid time entered will inform the user
                    cout << "You've entered an invalid time. Please enter a positive value.";

                else
                {
                    if (time1 < time2 && time1 < time3) //If player 1 finishes first
                    {
                        if (time2 < time3) //player 2 finishes second
                        {
                            cout << name1 << "\t" << setw(3) << time1 << endl
                                 << name2 << "\t" << setw(3) << time2 << endl
                                 << name3 << "\t" << setw(3) << time3;
                        }
                        else //player 3 finishes second
                        {
                            cout << name1 << "\t" << setw(3) << time1 << endl
                                 << name3 << "\t" << setw(3) << time3 << endl
                                 << name2 << "\t" << setw(3) << time2;
                        }
                    }


                    else if (time2 < time1 && time2 < time3) //If player 2 finishes first
                    {
                        if (time1 < time3) //player 1 finishes second
                        {
                            cout << name2 << "\t" << setw(3) << time2 << endl
                                 << name1 << "\t" << setw(3) << time1 << endl
                                 << name3 << "\t" << setw(3) << time3;
                        }
                        else //player 3 finishes second
                        {
                            cout << name2 << "\t" << setw(3) << time2 << endl
                                 << name3 << "\t" << setw(3) << time3 << endl
                                 << name1 << "\t" << setw(3) << time1;
                        }
                    }


                    else if (time3 < time1 && time3 < time2) //If player 3 finishes first
                    {
                        if (time1 < time2) //player 1 finishes second
                        {
                            cout << name3 << "\t" << setw(3) << time3 << endl
                                 << name1 << "\t" << setw(3) << time1 << endl
                                 << name2 << "\t" << setw(3) << time2;
                        }
                        else //player 2 finishes second
                        {
                            cout << name3 << "\t" << setw(3) << time3 << endl
                                 << name2 << "\t" << setw(3) << time2 << endl
                                 << name1 << "\t" << setw(3) << time1;
                        }
                    }
                }
                break;
            }

            case 4:
            {
                //Declare Variables
                char choice;
                short unsigned hours; //Valid only for integer hours
                float priceA, //Price per month for each service, not counting exceeded hours
                      priceB,
                      priceC,
                      bill; //The monthly bill

                //Initialize or input i.e. set variable values
                priceA = 9.95,
                priceB = 14.95,
                priceC = 19.95;

                //Map inputs -> outputs
                cout << "ISP Bill" << endl
                     << "Input Package and Hours" << endl;

                cin >> choice >> hours;

                //Display Outputs
                if (hours < 744 && hours >=0)
                {
                    switch (choice) //Executes one of the cases only since used break, if invalid will return default
                    {
                        case 'A' : bill = hours > 10 ? (priceA + (hours - 10) * 2) : priceA;
                            cout << "Bill = $" << setw(6) << bill;
                            break;

                        case 'B' : bill = hours > 20 ? (priceB + (hours - 20)) : priceB;
                            cout << "Bill = $" << setw(6) << bill;
                            break;

                        case 'C' : bill = priceC;
                            cout << "Bill = $" << setw(6) << bill;
                            break;

                        default : cout << "You've Entered an invalid character. Please enter either A, B, or C.";
                    }
                }
                else
                    cout << "Number of hours in a month cannot exceed 744. Please enter a valid amount.";

                break;
            }

            case 5:
            {
                //Declare Variables
                string name1, name2, name3; //Single word strings

                //Map inputs -> outputs
                cout << "Sorting Names" << endl
                     << "Input 3 names" << endl;

                cin >> name1 >> name2 >> name3;

                //Display the outputs
                if (name1 < name2 && name1 < name3 && name2 < name3) //Alphabetical order means that first one will have lowest ASCII value ex. A < Z --> 65 < 90
                    {
                        cout << name1 << endl
                             << name2 << endl
                             << name3;
                    }
                else if (name1 < name2 && name1 < name3 && name3 < name2)//if words have same fist letter than will compare second letter and so forth
                    {
                        cout << name1 << endl
                             << name3 << endl
                             << name2;
                    }
                else if (name2 < name1 && name2 < name3 && name1 < name3)
                    {
                        cout << name2 << endl
                             << name1 << endl
                             << name3;
                    }
                else if (name2 < name1 && name2 < name3 && name3 < name1)
                    {
                        cout << name2 << endl
                             << name3 << endl
                             << name1;
                    }
                else if (name3 < name1 && name3 < name2 && name1 < name2)
                    {
                        cout << name3 << endl
                             << name1 << endl
                             << name2;
                    }
                else //Last possible condition isn't required to write but its (name3 > name1 && name3 > name2 && name2 > name1)
                    {
                        cout << name3 << endl
                             << name2 << endl
                             << name1;
                    }
                break;
            }

            case 6:
            {
                char player1, player2; //choice that player makes in rock, paper, scissors

                //prompt user to input player1 and player2 choice
                cout << "Rock Paper Scissors Game" << endl 
                     << "Input Player 1 and Player 2 Choices" <<endl; 

                cin >> player1 >> player2; //player choices
                
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
                            cout << "Invalid character. Please enter valid characters: P, p, R, r, S, s."; 
                        break; // break statement to stop other cases from executing

                    case 'r': 
                        if (player2 == 'R' || player2 == 'r') 
                            cout << "Nobody wins.";
                        else if (player2 == 'P' || player2 == 'p') 
                            cout << "Paper covers rock."; 
                        else if (player2 == 'S' || player2 == 's') 
                            cout << "Rock breaks scissors.";
                        else
                            cout << "Invalid character. Please enter valid characters: P, p, R, r, S, s."; //reports to user an invalid choice was entered
                        break; 

                    case 'P': //if else statements to find valid seed of the game after appropriate case is determined
                        if (player2 == 'R' || player2 == 'r') 
                            cout << "Paper covers rock."; 
                        else if (player2 == 'P' || player2 == 'p') 
                            cout << "Nobody wins."; 
                        else if (player2 == 'S' || player2 == 's') 
                            cout << "Scissors cuts paper."; 
                        else
                            cout << "Invalid character. Please enter valid characters: P, p, R, r, S, s."; 
                        break; 

                    case 'p': 
                        if (player2 == 'R' || player2 == 'r') 
                            cout << "Paper covers rock."; 
                        else if (player2 == 'P' || player2 == 'p') 
                            cout << "Nobody wins."; 
                        else if (player2 == 'S' || player2 == 's') 
                            cout << "Scissors cuts paper."; 
                        else    
                            cout << "Invalid character. Please enter valid characters: P, p, R, r, S, s."; 
                        break; 

                    case 'S': 
                        if (player2 == 'R' || player2 == 'r') 
                            cout << "Rock breaks scissors"; 
                        else if (player2 == 'P' || player2 == 'p') 
                            cout << "Scissors cuts paper."; 
                        else if (player2 == 'S' || player2 == 's') 
                            cout << "Nobody wins."; 
                        else
                            cout << "Invalid character. Please enter valid characters: P, p, R, r, S, s."; 
                        break; 

                    case 's': 
                        if (player2 == 'R' || player2 == 'r') 
                            cout << "Rock breaks scissors"; 
                        else if (player2 == 'P' || player2 == 'p') 
                            cout << "Scissors cuts paper."; 
                        else if (player2 == 'S' || player2 == 's') 
                            cout << "Nobody wins."; 
                        else   
                            cout << "Invalid character. Please enter valid characters: P, p, R, r, S, s."; 
                        break; 

                    default : cout << "Invalid character. Please enter valid characters: P, p, R, r, S, s.";
                }
                break;
            }

            case 7: 
            {
                //Declare Variables
                string sign1, //Inputted horoscope signs
                       sign2,
                       msg; //message that will be outputted

                string fire1, fire2, fire3, //Horoscope signs separated by element type(3 in each)
                       water1, water2, water3,
                       earth1, earth2, earth3,
                       air1, air2, air3;

                //Initialize or input i.e. set variable values
                 fire1 = "Aries",       fire2 = "Leo",           fire3 = "Sagittarius", //Assigns corresponding horoscope sign to its element type
                water1 = "Cancer",     water2 = "Scorpio",      water3 = "Pisces",
                earth1 = "Taurus",     earth2 = "Virgo",        earth3 = "Capricorn",
                  air1 = "Gemini",       air2 = "Libra",          air3 = "Aquarius";

                //Prompt User to input variable
                cout << "Horoscope Program which examines compatible signs." << endl
                     << "Input 2 signs. Capitalize the first letter of each." << endl;

                cin >> sign1 >> sign2;
                //Map inputs -> outputs
                if      ( (sign1==fire1 ||  sign1==fire2  ||  sign1==fire3) &&  (sign2==fire1 ||  sign2==fire2 || sign2==fire3) ) //Using parenthesis to maintain correct precedence
                    msg = sign1 + " and " + sign2 + " are compatible Fire signs."; //message sign varies based on if compatible with sign

                else if ( (sign1==water1 || sign1==water2 || sign1==water3) && (sign2==water1 || sign2==water2 || sign2==water3) )
                    msg = sign1 + " and " + sign2 + " are compatible Water signs.";

                else if ( (sign1==earth1 || sign1==earth2 || sign1==earth3) && (sign2==earth1 || sign2==earth2 || sign2==earth3) )
                    msg = sign1 + " and " + sign2 + " are compatible Earth signs.";

                else if  ( (sign1==air1  ||  sign1==air2  ||   sign1==air3) &&  (sign2==air1  ||  sign2==air2  || sign2==air3) )
                    msg = sign1 + " and " + sign2 + " are compatible Air signs.";

                else
                    msg = sign1 + " and " + sign2 + " are not compatible signs."; //if none of the above ae true than not compatible
                //Display the outputs
                cout << msg;

                break;
            }

            case 8:
            {
                //Declare Variables
                int x, //User input ordinary number
                    num1, //integer value of corresponding digits in 1's, 10's, 100's, and 1000's place
                    num10, //truncates unimportant values using integer division
                    num100, 
                    num1000;

                //Initialize or input i.e. set variable values
                string msg = "";

                //Prompt user for input
                cout << "Arabic to Roman numeral conversion." << endl
                     << "Input the integer to convert. Only integers from 1000-3000 are accepted." << endl;

                cin >> x;

                //Only accept values according to range declared
                if (x >= 1000 && x <= 3000)
                {
                    //strips of unimportant digits using integer division and modulus
                    num1000 = x / 1000, //number in the 1000's place
                    num100 = (x / 100) % 10, //number in the 100's place
                    num10 = (x / 10) % 10, //number in the 10's place
                    num1 = x % 10; //number in the 1's place

                    //switch combined with break statements to only utilize specific case for 1000's place
                    switch (num1000) {
                        case 1 : msg += "M";
                            break;
                        case 2 : msg += "MM";
                            break;
                        case 3 : msg += "MMM";
                    }
                    //ternary operator that adds specific roman string to msg  
                    msg += num100 == 1 ? "C" :
                           num100 == 2 ? "CC" :
                           num100 == 3 ? "CCC" :
                           num100 == 4 ? "CD" :
                           num100 == 5 ? "D" :
                           num100 == 6 ? "DC" :
                           num100 == 7 ? "DCC" :
                           num100 == 8 ? "DCCC" :
                           num100 == 9 ? "CM" : "";
                    //roman numerals corresponding to 10's place
                    msg += num10 == 1 ? "X" :
                           num10 == 2 ? "XX" :
                           num10 == 3 ? "XXX" :
                           num10 == 4 ? "XL" :
                           num10 ==5 ? "L" :
                           num10 == 6 ? "LX" :
                           num10 == 7 ? "LXX" :
                           num10 == 8 ? "LXXX" :
                           num10 == 9 ? "XC" : "";
                    //roman numerals corresponding to 1's place      
                    msg += num1 == 1 ? "I" :
                           num1 == 2 ? "II" :
                           num1 == 3 ? "III" :
                           num1 == 4 ? "IV" :
                           num1 == 5 ? "V" :
                           num1 == 6 ? "VI" :
                           num1 == 7 ? "VII" :
                           num1 == 8 ? "VIII" :
                           num1 == 9 ? "IX" : "";

                    msg = " is equal to " + msg;
                }    
                else 
                    msg = " is Out of Range!"; //failed msg if invalid number x entered

                //Display the outputs
                cout << x << msg;

                break;
            }

            default: cout << "Exiting to Menu" << endl;      
        }
    } while (probNum>0 && probNum <= 8);
    
    //Exit the Program
    return 0;
}

