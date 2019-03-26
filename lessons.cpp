//------------------------------------------------------------------------------
// UNREAL ENGINE C++ DEVELOPEMENT
// Section 02: Bulls and Cows
/*
  \file     lessons.cpp
  \author   José Moreno
  \date     20/11/2018

  \par		Definition for all the lessons functions.
 */
 //------------------------------------------------------------------------------

#include "lessons.h"
#include <iostream>
#include <string>

void lesson21MagicNumbersAndConstants()
{
	// Magic numbers means numbers written "en duro", hard typed(?).
	constexpr int WORD_LENGTH = 5; //we will see the difference with "const".

	//RULE OF THUMB: write '\n' if you have a "" open, use endl otherwise.
	std::cout << "Guess a " << WORD_LENGTH << " letter isogram I am thinking of.\n";

	return;
}
void lesson22VariablesAndCinForInput()
{
	//RULE OF THUMB: Use pseudocode (comments) before starting to actually programming.

	//ask the player for a guess
	std::string Guess = ""; //UNREAL Code STD: all variables start by capital letter.
	std::cout << "Enter your guess: ";
	std::cin >> Guess;

	//if the player input is 2 words, it will only take the first one and leave the
	//	other one in a buffer. A consecutive cin would take that second word from there.

	//repeat the guess back to them
	std::cout << "\nYour guess is " << Guess << ".\n";

	return;
}
void lesson23UsingGetline()
{
	//We can use getline instead of cin. 
	std::string Guess = ""; //UNREAL Code STD: all variables start by capital letter.
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess); //check that you need cin to specify the input buffer.

	//repeat the guess back to them
	std::cout << "\nYour guess is " << Guess << ".\n";

	return;
}
void lesson24SimplifyingWithFunctions()
{
	//Actually i've been using function all the time

	//Encapsulation and abstraction: 
	//	- abstract to give the name, definition, to describe what you are doing, 
	//		to be able to group it up.
	// - to encapsulate is to take a bunch of lines that do that thing and put
	//		them all inside the function. 
	//		You separate in modules making int easier to follow and to understand.

	// Create the functions PrintIntro() and GetGuess().

	return;
}
void lesson25IteratingWithForWhileLoops()
{
	//VISUAL BASIC Tips: ctrl+r, ctrl+r = change the name of all the instances.
	// for versus while.

	//Fist we use the for because we already now that we will loop a fix
	//	number of times.

	//So, get the game to ask 5 guesses. 

	//Better if we use the constexpr to avoid hard typed numbers.

	return;
}
void lesson26ClarityIsWorthFightingFor()
{
	//At this moment, PrintIntro is in a higher level of abstraction than
	//	the next lines.
	// VISUAL BASIC tips: select the lines, right click and select:
	//	"Actions rapides et refactorisations..." -> "Extraire la fonction"
	//
	//	- It will ask for the name of the function, create it under main,
	//		move the selected lines inside that function and
	//		leave the call to the function where the liens where.
	//	
	//	- It also creates the definition line on top.
	//	
	//	- ALTERNATIVE, it creates main.h and rceates there the definition.

	// Note that it doesn't specify "return" in a void funtion.

	// It was nice to know but...

	return;
}
void lesson27BooleansAndComparisions()
{
	//VISUAL STUDIO Tips: right click and select:
	//	"Actions rapides et refactorisations..." -> "Creer la declaration/la definition"
	//
	// Doing this in the declaration (top), will create the definition at the end of the code.
	// 
	// And vice versa.

	//VISUAL STUDIO:
	//	Tools->Options:
	//	- Text editor / C/C++ / New Lines: Position of open braces.
	//
	// To edit the format of the quick actions.

	//Code: 
	/*
	char answer;
	std::cout << "Wanna play again? (y/n)";
	answer = std::getchar();
	if (answer == 'y' || answer == 'Y')
	{
		return true;
	}
	else if (answer == 'n' || answer == 'N')
	{
		return false;
	}
	*/
	return;
}
void lesson28DoAndWhileInC()
{
	//some more basic c++
	//Code from that lesson:
	/*
	bool bPlayAgain = false;
	do
	{
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain); //return bool (0=false, 1=true)
	*/
}
void lesson29IntroducingClasses()
{
	//Mid term stop. Introduce the classes to our project.

	//We will make a class called FBullCowGame acting as a black box.
	// It will have all the thinking inside. 
	//
	//This abstraction + encapsulation alouds us to keep thingns simple while growing
	// in complexity.
}
void lesson30UsingHeaderFilesAsContracts()
{
	//We will have a header file to define our cows and bulls class.

	//RULE OF THUMB: Never put using namespace in a header file.
}
void lesson31IncludingOurOwnHeaderFile()
{
	//Explain why never use 'using namespace' in a header file:
	//
	//VISUAL STUDIO: Ctrl+H to quick replace
	//
	//VISUAL STUDIO:
	//	"Actions rapides et refactorisations..." -> "Creer la declaration/la definition"
	// - When in a header file "BullCowGame.h", it will create the definition and the file:
	//		"BullCowGame.cpp".
}
void lesson32InstantiatingYoutClass()
{
	//Not enough with the definition, we have to create an instance of it.
	// We instatiate it Globaly (out of main) for this time.
	//	We will have only one instance of it and the reset it when we need it.
	//	main() is going to be somehow the game manager.

	//RULE OF THUMB: Put the GET definitions on top in the class.cpp
}
void lesson34IntroducintTheConstKeyword()
{
	//Introducing const as a protection for the Get methods.
	//	
	//	you can only do this in "member functions": functions inside a member(class).
	//	if you try to do const in a "non-member function" it will give a 
	//	 compile error.
}
void lesson35ConstructorsForInitialisation()
{
	//Differ between compile values and runtime values.
	//	Compile time are in a class private member declaration.
	//	Runtime would be the value it has during the code execution.

	// Initialize the values in the contructor definition will help
	//	 to have all the interesting things in the .cpp file.
}
void lesson36PseudocodeProgramming()
{
	//Basiclly, comment the pseudo code before we write
	//	to plan the steps we want to complete.

	//VISUAL STUDIO:
	//	View -> show task list
	// It will show us every "TODO" comment in the code.

	//RULE OF THUMB:
	//	Put only TODO when you will erase the comment. Don't put TODO in every line of 
	//	 pseudocode you write.
	//	DO NOT write code when commenting or pseudocoding. This is higher abstraction.
}
void lesson37UsingUsingForTypeAliases()
{
	using FText = std::string;
	// this is Unreal style already
	
	//Difference between FString and FText:
	// FString is a mutable
	// FText is used for user output

	//we use FText in main instead of std::string but
	//	we use FString in 
}
void lesson38UsingStructForSimpleTypes()
{
	// Use struct to create simple data types

	//UNREAL STYLE: use F prefix to name structs
}
void lesson39UsingIfStatementsInCpp()
{
	//meh
}
void lesson42IntroducingEnumerations()
{
	//When you define the enum, all the enums inside are in global scope.
	// Unreal will suggest to put them on their own namespace

	// BUT C++11 alouds you to use enum class:
	enum class EEnumerator
	{
		A,
		B,
		C
	};

	//So we can refer to them as EEnumerator::A
	EEnumerator::B;

	//This alouds us to use another anumerator with the same member names
	enum class EEnumerator2
	{
		A,
		B,
		C
	};

}
void lesson49TMapAndstdmapDataStructure()
{
	//using FMap = std::map;

	//RULE OF THUMB:
	//	I saw on the Story cave a nice way of retrieving the members of the own class instance (this->_preivateMember)
	//	 But what they do here is to call the private melbers as MyPrivateMember. Which in the end is kind of the same thing.
}

void unrealNorm()
{
	std::cout << "UNREAL STYLE NORMS\n";
	std::cout << "=========================================================================\n\n";

	std::cout << "Names of variables start by Capital Letter.\n";
	std::cout << "In cout, we don't use 'endl' at the end if we have a "" open, we use '\n'.\n";
	std::cout << "We name the BOOLean variables with a b at the beggining.\n";
	std::cout << "We name the classes with an F at the beggining\n";
	std::cout << "Use FText instead of std::string\n";
	std::cout << "Use Fint instead of int32\n";
	std::cout << "We also prefix the structs with F, same as the classes.\n";
	std::cout << "we start enum type names with a E.\n";
	std::cout << "we use TMap instead of std::map\n";

}
