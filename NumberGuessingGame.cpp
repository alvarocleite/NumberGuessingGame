#include <iostream>
#include <cstdlib>
#include "cli.h"

int getRand(int difficulty);

int main(){
    int difficulty = 1;
    bool win = false;
    int tries = 0;

    printWelcome();
    difficulty = chooseDifficulty();

    // Providing seed value
    srand(time(NULL));

    // Get random number
    int randNumber = getRand(difficulty);

    do
    {
        win = (getTry() == randNumber);
        tries++;
    } while (tries < 3 && !win);
    
    displayResult(win);

    return 0;
}

int getRand(int difficulty){
    int random, temp;
    switch (difficulty)
    {
    case 1:
        temp = 11;
        break;
    case 2:
        temp = 21;
        break;
    case 3:
        temp = 51;
        break;
    case 4:
        temp = 76;
        break;
    case 5:
        temp = 101;
        break;
    default:
        exit(1);
        break;
    }
    random = rand() % temp;
    return random;
}