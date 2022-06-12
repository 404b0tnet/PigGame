/*
file:	player.h
by:		Justin Smith
org:	COP 2001, Spring 2020
for:	Header file for the player class object
*/

#pragma once

#include <string>
using namespace std;


class Player {

private:
	string playerName;
	int playerScore;


public:

	//----------------------------------------------
	// Constructors	
	//----------------------------------------------
	Player();
	Player(string inputName);


	//----------------------------------------------
	// Accessors
	//----------------------------------------------
	string getName();
	void setName(string name);

	int getScore();
	void setScore(int score);


	//----------------------------------------------
	// Methods
	//----------------------------------------------
	void appendScore(int score);
	string formattedString();


};