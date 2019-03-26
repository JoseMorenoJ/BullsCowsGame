//------------------------------------------------------------------------------
// UNREAL ENGINE C++ DEVELOPEMENT
// Section 02: Bulls and Cows
/*
  \file     FBullCowGame.h
  \author   José Moreno
  \date     20/11/2018

  \par		Definition of the class FBullCowGame that is the main class of the
			game, Bulls and Cows.
 */
 //------------------------------------------------------------------------------

#pragma once //ensures that the file is only loaded once.
#include <string>

//To make the syntax Unreal-friendly.
using FString = std::string; // FString is for strings that are not printed out. We use FText for that.
using int32 = int;

//Counter for the bulls and cows of a valid guess
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
	FString String = ""; //Cows and Bulls as comparing the try with the hidden word.
};

//enum for the guess validation checks
enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

//The game class, all the game happens here.
class FBullCowGame {
public: //Interface with the player (other programs)

	//Constructor.
	FBullCowGame(); 
	// ~FBullCowGame(); //leave default if you can

	//Getters.
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	int32 GetMaxTries() const;

	//Control of the players input.
	EGuessStatus CheckGuessValidity(FString s);
	//Send the game the valid input.
	FBullCowCount SubmitValidGuess(FString validGuess);

	//Reset the game.
	void Reset();
private:
	// initialize in the constrcutor.
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

	//Helper methods, called by this->functions.
	bool bGameWon;
	bool IsLowercase(FString) const;
	bool IsIsogram(FString) const;
	void SetHiddenWord(int32 ChosenLength);
};
