/*
file:	block.cpp
by:		Justin Smith
org:	COP 2001, Spring 2020
for:	Implementation file for a player class object
*/

#include "player.h"

using namespace std;


//----------------------------------------------
// Constructors	
//----------------------------------------------
/********************************************************
Default constructor of a player class, will instantiate
playerName to an empty string and score to 0

parameters:
returns:
	Player( "", 0)
********************************************************/
Player::Player() {
	playerName = " ";
	playerScore = 0;

	return;
};

/********************************************************
Instantiate a Player class object with score 0,
and a user inputted name

parameters: 
	string	- playername by user
		
returns:
	Player(inputName, 0)
********************************************************/
Player::Player(string inputName) {
	playerName = inputName;
	playerScore = 0;

	return;
};


//----------------------------------------------
// Accessors
//----------------------------------------------
/********************************************************
Returns the player name

parameters:
returns:
	string	- empty string or user input name
********************************************************/
string Player::getName() {
	return playerName;
};

/********************************************************
Modify the player name string

parameters: 
	string - playername by user

returns:
	void
********************************************************/
void Player::setName(string inputName) {
	playerName = inputName;

	return;
};

/********************************************************
Returns the current player score

parameters:
returns:
	int		- current score or 0 if empty
********************************************************/
int Player::getScore() {
	return playerScore;
};

/********************************************************
Sets the player score

parameters: 
	int	- player score

returns:
********************************************************/
void Player::setScore(int score) {
	playerScore = score;

	return;
};


//----------------------------------------------
// Methods
//----------------------------------------------
/********************************************************
Will append the player score by adding their previous score
with the score at the end of the round
parameters:
	int score	- score at the end of the round
returns:
********************************************************/
void Player::appendScore(int score) {
	playerScore += score;
	
	return;
};

/********************************************************
Will return a string with the player name and their score
parameters:
returns:
	string	- player name with their score
********************************************************/
string Player::formattedString() {
	string formattedString = playerName + '_' + to_string(playerScore);

	return formattedString;
};