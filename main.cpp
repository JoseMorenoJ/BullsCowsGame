//------------------------------------------------------------------------------
// UNREAL ENGINE C++ DEVELOPEMENT
// Section 02: Bulls and Cows
/*
  \file     main.cpp
  \author   José Moreno
  \date     28/03/2006

  \par		main file for the bulls and cows lessons.

  This is the console executable that makes use of the BullCow class.
  This acts as the view in a MVC patter and is responsible for all 
	user interactions. For game logic see the FBullCowGame class.

 */
 //------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "FBullCowGame.h"
#include "lessons.h" //all the headers of the lessons functions.

//To make the syntax Unreal-friendly.
using FText = std::string; // FText is for interactions with the user: printing info.
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGameSummary();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate the game here. We only use this one.

int main() 
{
	PrintIntro();

	bool bPlayAgain = false;
	do
	{
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain); //return bool (0=false, 1=true)
	std::cout << "\nGoodbye, until next time!\n";
}

void PrintIntro()
{
	std::cout << "\n\n\n";
	std::cout << "Hello guys, welcome to Bulls & Cows game.\n";
	std::cout << "Hello guys, wellcome to Bulls & Cows game.\n";
	std::cout << "==========================================\n\n";
	std::cout << "Enjoy!\n\n";

	return;
}

//Plays a single game until is complete, win or lose.
void PlayGame()
{
	BCGame.Reset();

	const int32 MaxTries = BCGame.GetMaxTries();

	std::cout << "\n\nGuess the " << BCGame.GetHiddenWordLength() << " letter isogram I am thinking of.\n\n";
	
	FText Guess = "";
	//loop until the game is NOT won
	while ( !BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries )
	{	
		Guess = GetValidGuess(); //Get a valid guess from user

		//Submit the valid guess to the game.
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "\tNumber of bulls: " << BullCowCount.Bulls;
		std::cout << ", cows: " << BullCowCount.Cows << " (" << BullCowCount.String << ").\n"; //TODO fix the string
	}

	//Congrats when win, shame when lose.
	PrintGameSummary();

	return;
}

//loop until it gets a valid guess from the user
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid;
	FText Guess = "";
	do {
		//Get the guess
		std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
		std::getline(std::cin, Guess);
		
		//Controling the validity of the guess.
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Not_Isogram:
			std::cout << "\n";
			std::cout << "Please enter a word without repeating letters." << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "\n";
			std::cout << "Please enter a lowercase word." << std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "\n";
			std::cout << "Please enter a word with the proper length (";
			std::cout << BCGame.GetHiddenWordLength() << ")." << std::endl;
			break;
		default: //Assuming the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
}

void PrintGameSummary()
{
	if ( BCGame.IsGameWon() )
	{
		std::cout << "\n\nWell done! You win!\n\n";
	}
	else
	{
		std::cout << "\n\nOh... Better luck next time!\n\n";
	}
}

//Control of the loop that calls the Game
bool AskToPlayAgain()
{
	FText answer;
	std::cout << "Do you wanna play again with the same word? (y/n)";
	std::getline(std::cin, answer);
	
	if (answer[0] == 'y' || answer[0] == 'Y')
	{
		return true;
	}
	else if (answer[0] == 'n' || answer[0] == 'N')
	{
		return false;
	}
}
