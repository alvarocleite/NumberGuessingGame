#include <iostream>

using namespace std;

void printWelcome(){
    cout << "Welcome to the Number Guessing Game!" << endl;
}

int chooseDifficulty(){
    int difficulty;
    do{
        cout << "Please choose difficulty level (1 - 5)" << endl;
        cin >> difficulty;
    }while(difficulty < 1 || difficulty > 5);
    return difficulty;
}

int getTry(){
    int guess;
    cout << "Enter you guess: ";
    cin >> guess;
    return guess;
}

void displayResult(bool win){
    cout << "You " << (win ? "win" : "lose") << " the game!" << endl;
}
