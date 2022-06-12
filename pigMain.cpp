/*
file:	pigMain.cpp
by:		Justin Smith
org:	COP 2001, Spring 2020
for:	Pig (dice game)
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "player.h"


using namespace std;

int const MAX_NUM_PLAYERS = 5;
int const MAX_SCORE = 100;
int const SPACE_WIDTH = 25;

string const SPACES = "                         ";      // 25 spaces
string const DASHES = "-------------------------";      // 25 dashes



/*
Function Prototypes
*/
void gameIntro(Player playerList[], int playerIndex);
void scoreSummary(Player playerList[], int playerIndex, int round);
void endScoreScreen(Player playerList[], int playerIndex);
bool endGame(Player playerList[], int playerIndex);





/*
Each turn, a player repeatedly rolls a die until either a 1 is rolled or the player decides to "hold":

    If the player rolls a 1, they score nothing and it becomes the next player's turn.
    If the player rolls any other number, it is added to their turn total and the player's turn continues.
    If a player chooses to "hold", their turn total is added to their score, and it becomes the next player's turn.

The first player to score 100 or more points wins.--

For example, the first player, Donald, begins a turn with a roll of 5.
Donald could hold and score 5 points, but chooses to roll again.
Donald rolls a 2, and could hold with a turn total of 7 points, but chooses to roll again.
Donald rolls a 1, and must end his turn without scoring. 
The next player, Alexis, rolls the sequence 4-5-3-5-5, after which she chooses to hold,
and adds her turn total of 22 points to her score.
*/

int main() {

    srand(time(NULL));


    bool resume = false;
    char choice;
    int playerIndex = 0;
    Player playerList[MAX_NUM_PLAYERS];
    string playerName;


    gameIntro(playerList, playerIndex);



    // the do loop creates the number of players 
    do {
        cout << "Do you want to add more players? Y/N   ";
        cin >> choice;
        cin.ignore();

        // checks to see if they want to add more players
        if (choice == 'Y' || choice == 'y') {
            playerIndex++;

            cout << "Name of player " << playerIndex + 1 << ": ";
            cin >> playerName;

            playerList[playerIndex] = Player(playerName);
        }
        else 
        {
            resume = true;
        }

    } while (!resume);


    bool nextRound = true,
        endTurn = false;
    int roundCounter = 1;
    int diceRoll = 0,
        endOfRoundScore,
        counter;

    while (nextRound) {
        // loop to cycle through each player for the current round
        for (int i = 0; i <= playerIndex; i++) {

            endTurn = false;
            endOfRoundScore = 0;

            scoreSummary(playerList, playerIndex, roundCounter);

            cout << endl << DASHES << endl;

            cout << "Starting turn for " << playerList[i].getName() << endl;


            // Dice roll loop
            do {

                diceRoll = (rand() % 6 + 1);

                switch (diceRoll) {

                    // end turn if dice roll is 1
                case 1:
                    cout << "You rolled a 1. Better luck next time!" << endl;
                    system("PAUSE");
                    endTurn = true;
                    break;

                    // any dice roll other than 1
                default:
                    cout << "Dice roll: " << diceRoll << endl;
                    endOfRoundScore += diceRoll;
                    cout << "End of round Score: " << endOfRoundScore << endl;
                    cout << "Keep going and risk it all (Y/N)? ";
                    cin >> choice;
                    cin.ignore();

                    // checks to see if player wants to hold their score
                    // or keep rolling the dice
                    if (toupper(choice) != 'Y') {
                        // sets counter equal to players current score
                        counter = playerList[i].getScore();

                        // player score is updated with the score
                        // at the end of the round
                        playerList[i].setScore(counter += endOfRoundScore);

                        cout << "\nEnding turn for " << playerList[i].getName()
                            << "\t Score: " << playerList[i].getScore() << endl;
                        endTurn = true;
                    }

                    cout << endl;

                } // end of switch

            } while (!endTurn);     // end of player turn loop

            if (endGame(playerList, playerIndex)) {
                i = playerIndex + 1;
                nextRound = false;
            }
        }       // for loop

        roundCounter++;
    }


    endScoreScreen(playerList, playerIndex);


	return 0;
}



/********************************************************

Creates first character and gives the game rules
parameters:
    playerlist[]    -	array that holds each players information
    playerIndex		-	index in the array for each player

returns:

**********************************************************/
void gameIntro(Player playerList[], int playerIndex) {
    string playerName;

    cout << "Welcome to the Pig game! " <<
        "Where your survival is dependant on your gambling skills!" << endl; 
    cout << "Here are the rules.." << endl;

    cout << "\nEach turn, a player repeatedly rolls a die " <<
        " until either a 1 is rolled or the player decides to hold."
        << endl <<
        "If the player rolls a 1, they score nothing and it becomes the next player's turn."
        << endl <<
        "If the player rolls any other number, " <<
        " it is added to their turn total and the player's turn continues."
        << endl <<
        "If a player chooses to hold, their turn total is added to their score, " <<
        "and it becomes the next player's turn."
        << endl <<
        "The first player to score " << MAX_SCORE<< " or more points lives! \n" << endl;

    cout << "Name of player 1: ";
    cin >> playerName;

    playerList[playerIndex] = Player(playerName);
}



/********************************************************

Summary of current players and their scores
parameters:
    playerlist[]    -	array that holds each players information
    playerIndex		-	index in the array for each player
    int round       -   current round

returns:

**********************************************************/
void scoreSummary(Player playerList[], int playerIndex, int round) {
    int nameLength,
        scoreLength;

    system("CLS");
    cout << DASHES << endl;
    cout << "Starting Round " << round << endl;
    for (int i = 0; i <= playerIndex; i++) {

        nameLength = playerList[i].getName().length();
        scoreLength = to_string(playerList[i].getScore()).length();

        cout << playerList[i].getName() <<
            SPACES.substr(0, SPACE_WIDTH - nameLength - 12 - scoreLength) <<
            "\t score: " << playerList[i].getScore() << endl;

    }
    cout << DASHES << endl;
    return;
}


/********************************************************

End game screen of of scores
parameters:
    playerlist[]    -	array that holds each players information
    playerIndex		-	index in the array for each player

returns:
**********************************************************/
void endScoreScreen(Player playerList[], int playerIndex) {
    int nameLength,
        scoreLength;

    system("CLS");
    cout << DASHES << endl;
    cout << "The game has ended! " << endl;
    for (int i = 0; i <= playerIndex; i++) {

        nameLength = playerList[i].getName().length();
        scoreLength = to_string(playerList[i].getScore()).length();

        cout << playerList[i].getName() <<
            SPACES.substr(0, SPACE_WIDTH - nameLength - 12 - scoreLength) <<
            "\t score: " << playerList[i].getScore() << endl;
    }
    cout << DASHES << endl;
    return;
}


/********************************************************

Will keep track of the high score and end game once score is met
parameters:
    playerlist[]    -	array that holds each players information
    playerIndex		-	index in the array for each player
    maxScore        -   max score to end the game

returns:
    bool        -   will return true if high score is met
**********************************************************/
bool endGame(Player playerList[], int playerIndex) {
    int highScore = 0;
    bool endGame = false;

    for (int i = 0; i <= playerIndex; i++) {
        if (playerList[i].getScore() >= MAX_SCORE)
            endGame = true;
    }

    return endGame;
}