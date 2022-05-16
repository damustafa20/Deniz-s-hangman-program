//hangman.cpp
//a simple hangman project done by Deniz Ali Mustafa
//"I'm certain you can find some fun in it."
#include <iostream>
#include <string>
#include <random>

using namespace std;

//declaring the variables on a global scale
//useful for the void functions right below
string theWord = "          ";
string yourGuess = "          ";
int incorrectGuesses = 0;
char letter;
int length = theWord.length();


//void randomWord
//we spin a wheel and when the user presses enter, a word has been chosen.
//uses a switch so it can easily be editable
void randomWord()
{
	random_device r;
	default_random_engine e1(r());
	uniform_int_distribution<int> uniform_dist(0, 4);
	int randomNumber = uniform_dist(e1);
	
	switch (randomNumber)
	{
		case 0:
		theWord = "APPLE     ";
		yourGuess = "_____     ";
		break;
		
		case 1:
		theWord = "KEY       ";
		yourGuess = "___       ";
		break;
		
		case 2:
		theWord = "JEEP      ";
		yourGuess = "____      ";
		break;
		
		case 3:
		theWord = "PLEASURE  ";
		yourGuess = "________  ";
		break;
		
		case 4:
		theWord = "SNUFF     ";
		yourGuess = "_____     ";
		break;
		
		default:
		theWord = "CAR       ";
		yourGuess = "___       ";
		break;
	}
}

//void isItThere
//checks if a letter matches the given word
//if there's a match, that's good! If not, we're drawing the hangyboy/girl
//Just a code trimmer, I made it so It looks a little nicer
void isItThere()
{
	if (letter >= 97 && letter <= 122)
	{
		letter = letter - 32;
	}
	
	bool flag = false;
	
	for (int i = 0; i <= length; i++)
	{
		if (theWord[i] == letter)
		{
			yourGuess[i] = letter;
			flag = true;
		}
	}
	
	if (flag == false)
	{
		incorrectGuesses++;
	}
}


//main function
int main()
{
	system("clear"); //clears out the screen
	
	cout << "************************************************" << endl;
	cout << "Welcome to hangman! Press Enter to begin a game." << endl;
	cout << "************************************************" << endl;
	
	cin.get();
	randomWord();
	
	//while below is the main game
	//have fun trying to decipther the whole switch
	//P.S. keep it && (AND), it doesn't work with || (OR)
	while ( (incorrectGuesses < 6) && (theWord != yourGuess) )
	{
		system("clear");
		
		switch(incorrectGuesses)
		{
			case 0:
			cout << "***************************************************" << endl;
			cout << "HANGMAN" << endl;
			cout << "***************************************************" << endl;
			cout << yourGuess << "  << Your guess!" << endl << endl;
			cout << "-------" << endl;
			cout << " |    |" << endl;
			cout << "      |" << endl;
			cout << "      |" << endl;
			cout << "      |" << endl << endl;
			break;
			
			case 1:
			cout << "***************************************************" << endl;
			cout << "HANGMAN" << endl;
			cout << "***************************************************" << endl;
			cout << yourGuess << "  << Your guess!" << endl << endl;
			cout << "-------" << endl;
			cout << " |    |" << endl;
			cout << " 0    |" << endl;
			cout << "      |" << endl;
			cout << "      |" << endl << endl;
			break;
			
			case 2:
			cout << "***************************************************" << endl;
			cout << "HANGMAN" << endl;
			cout << "***************************************************" << endl;
			cout << yourGuess << "  << Your guess!" << endl << endl;
			cout << "-------" << endl;
			cout << " |    |" << endl;
			cout << " 0    |" << endl;
			cout << " |    |" << endl;
			cout << "      |" << endl << endl;
			break;
			
			case 3:
			cout << "***************************************************" << endl;
			cout << "HANGMAN" << endl;
			cout << "***************************************************" << endl;
			cout << yourGuess << "  << Your guess!" << endl << endl;
			cout << "-------" << endl;
			cout << " |    |" << endl;
			cout << " 0    |" << endl;
			cout << "/|    |" << endl;
			cout << "      |" << endl << endl;
			break;
			
			//Keep in mind
			//The reason why we have "\\" is because g++ thinks "\" is an escape sequence
			case 4:
			cout << "***************************************************" << endl;
			cout << "HANGMAN" << endl;
			cout << "***************************************************" << endl;
			cout << yourGuess << "  << Your guess!" << endl << endl;
			cout << "-------" << endl;
			cout << " |    |" << endl;
			cout << " 0    |" << endl;
			cout << "/|\\   |" << endl;
			cout << "      |" << endl << endl;
			break;
			
			case 5:
			cout << "***************************************************" << endl;
			cout << "HANGMAN" << endl;
			cout << "***************************************************" << endl;
			cout << yourGuess << "  << Your guess!" << endl << endl;
			cout << "-------" << endl;
			cout << " |    |" << endl;
			cout << " 0    |" << endl;
			cout << "/|\\   |" << endl;
			cout << "/     |" << endl << endl;
			break;
			
			default:
			cout << "***************************************************" << endl;
			cout << "HANGMAN" << endl;
			cout << "***************************************************" << endl;
			cout << yourGuess << endl << endl;
			cout << "hangman went kaboom sorry" << endl;
			break;
		}
		
		/** cout << incorrectGuesses << endl; **/ //uncoment to show incorrect guesses
		/** cout << letter; **/ //uncomment to show previously enterered character
		cin >> letter;
		isItThere();
	}
	
	//after we exit the while, we determine whether or not the player was victorious
	//a simple if statement will suffice
	system("clear");
	
	if(incorrectGuesses == 6)
	{
		cout << "-------" << endl;
		cout << " |    |" << endl;
		cout << " 0    |" << endl;
		cout << "/|\\   |" << endl;
		cout << "/ \\   |" << endl << endl;
		
		cout << "Uh oh! Looks like you've lost." << endl;
		cout << "The correct word was " << theWord << endl << endl;
	}
	else
	{
		cout << "***************************************************" << endl;
		cout << "HANGMAN: WINNER!" << endl;
		cout << "***************************************************" << endl;
		cout << theWord << endl << endl;
		
		cout << "\\0/" << endl;
		cout << " |" << endl;
		cout << "/ \\" << endl << endl;
		
		cout << "Would you look at that. You did it!" << endl;
		cout << "Thanks for sticking around! Have a nice day." << endl << endl;
	}
}
