#include <iostream>
#include "cli.h"

using namespace std;

Cli::Cli(){
    printWelcome();
    cout << endl;
    printRules();
    cout <<endl;
}

Cli::~Cli(){
    cout << "Closing Game!" << endl;
}

void Cli::printWelcome(){
    cout << "Welcome to the Number Guessing Game!" << endl;
}

int Cli::chooseDifficulty(){
    int difficulty;
    bool valid = false;
    do{
        cout << "Please choose difficulty level (1 - 3)" << endl;
        cin >> difficulty;
        cout << endl;
        switch (difficulty) {
        case 1:
            cout << "Good! You have selected Easy difficulty level." << endl;
            valid = true;
            break;
        case 2:
            cout << "Great! You have selected Medium difficulty level." << endl;
            valid = true;
            break;
        case 3:
            cout << "Are you feeling luck!? You have selected Hard difficulty level." << endl;
            valid = true;
            break;
        default:
            cout << "The value you chose is not valid! Please try again!" << endl; 
            break;
        }
        cout << endl;
    }while(!valid);

    return difficulty;
}

int Cli::getTry(){
    int guess;
    cout << "Enter you guess: ";
    cin >> guess;
    return guess;
}

void Cli::displayResult(bool win, int tries, int rightNumber = -1){
    cout << "It took " << tries << " tries." << endl;
    cout << "You " << (win ? "win" : "lost") << " the game!" << endl;
    cout << (win ? "Congratulations!!" : "Better luck next time!") << endl;
    
    if (rightNumber != -1) {
        cout << "The right number was: " << rightNumber << endl;
    }
}

void Cli::printRules(){
    cout << "The Rules are: " << endl;
    cout << " - You must guess a number." << endl;
    cout << " - The number are randomly generate each time you play." << endl;
    cout << " - The number are between 1 and 100." << endl;
    cout << " - You got between 3 and 10 chances, depending on the difficulty" << endl;
}
