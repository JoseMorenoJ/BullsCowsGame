//------------------------------------------------------------------------------
// UNREAL ENGINE C++ DEVELOPEMENT
// Section 02: Bulls and Cows
/*
  \file     FBullCowGame.cpp
  \author   José Moreno
  \date     20/11/2018

  \par		Definition of the class FBullCowGame that is the main class of the
			game, Bulls and Cows.
 */
 //------------------------------------------------------------------------------

#include "FBullCowGame.h"
#include <iostream>
#include <algorithm>
#include <map>

//To make the syntax Unreal-friendly.
#define TMap std::map //same as "using FText = std::string;" but we save ourselves to use parameters

//Constructor: Every time we start the game we reset it.
FBullCowGame::FBullCowGame() { this->Reset(); }

//Getters
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return this->MyHiddenWord.size(); }
bool  FBullCowGame::IsGameWon() const { return this->bGameWon; } 

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries = { {3,4}, {4,7}, {5,10}, {6,15}, {7,20}, {8,30} };
	return WordLengthToMaxTries[ this->MyHiddenWord.length() ]; 
}

//Gives the state of the Guess introduced by the player.
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	//We leave the first check the most likely to happen so it won't run the other checks.

	//Size of the guess is not equal to the word length in the intro.
	if ( Guess.size() != this->GetHiddenWordLength() )
	{
		return EGuessStatus::Wrong_Length;
	}
	//Guess has repeated letters.
	else if ( !IsIsogram(Guess) )
	{
		return EGuessStatus::Not_Isogram;
	}
	//Guess has a lowercase letter.
	else if (!this->IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	//If it reaches here, it passed the guess controls
	return EGuessStatus::OK;
}

//Counts Bulls and Cows and increases try number.
FBullCowCount FBullCowGame::SubmitValidGuess(FString ValidGuess)
{
	//Increment the try number
	this->MyCurrentTry++;

	const int32 WORD_SIZE = this->GetHiddenWordLength(); //same for guess and hidden word

	FBullCowCount BullCowCount;
	BullCowCount.String.resize(WORD_SIZE); // FString('0', WORD_SIZE); //reset the String counter

	for (int32 i = 0; i < WORD_SIZE; ++i) //Loop every ValidGuess letter
	{
		if (this->MyHiddenWord[i] == ValidGuess[i]) //BULL
		{
			BullCowCount.Bulls++;
			BullCowCount.String[i] = 'B';
		}
		else
		{
			for (int32 j = 0; j < WORD_SIZE; ++j) //Loop the rest of the HiddenWord's letters
			{
				if (this->MyHiddenWord[j] == ValidGuess[i]) //COW
				{
					BullCowCount.Cows++;
					BullCowCount.String[i] = 'C';
					break;
				}
				else {
					BullCowCount.String[i] = 'x';
				}
			}
		}
	}
	//Check if the game is won or not.
	if (BullCowCount.Bulls == WORD_SIZE)
	{
		this->bGameWon = true;
	}
	else
	{
		this->bGameWon = false;
	}
	return BullCowCount;
}

//Prepare the game to start again.
void FBullCowGame::Reset()
{
	//TODO Ask for the hidden word length and store it
	//set the hidden word: SetHiddenWord(Chosenlength)

	const FString HIDDEN_WORD = "ant"; //it doesnt let us use constexpr here, too strong
	this->MyHiddenWord = HIDDEN_WORD;
	this->MyCurrentTry = 1;
	this->bGameWon = false;

	return;
}

//Private method: check if there are lowercase letters in a given word.
bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}

//Private method: check if the given word is an isogram (no repeated letters).
bool FBullCowGame::IsIsogram(FString Word) const
{
	//Consider as isograms when the length is 0 or 1.
	if (this->GetHiddenWordLength() == 0 || this->GetHiddenWordLength() == 1)
	{
		return true;
	}

	TMap<char,bool> LettersSeen; //Keep count of the letters.
	
	for (auto Letter : Word) 
	{
		//Not necessary since the "IsLowercase()" control is before IsIsogram
		//	We leave it to make the functions self dependent
		Letter = tolower(Letter); //make sure it is a lowercase letter

		if (LettersSeen[ Letter ]) //C++11: If you look for an element of the map, 
			// it will automatically create it and initialize the value as default. Here: {Letter, false}.
		{
			return false; //Not an isogram.
		}
		else 
		{
			LettersSeen[ Letter ] = true; //Add the letter to the map with the value true.
		}
	}
	//If it doesn't get in the if statemet, it has no repeated letters.
	return true; //Isogram
}

//Private method: Called from reset to set the hidden word to one of the list
void FBullCowGame::SetHiddenWord(int32 ChosenLength)
{
	//List of Hidden Words to play.
	TMap<int32, FString> HiddenWordsSet
	{
		{3, "ant"},
		{4, "bear"},
		{5, "pilot"},
		{6, "planet"},
		{7, "rainbow"},
		{8, "aliments"}
	};

	this->MyHiddenWord = HiddenWordsSet[ChosenLength];
}
