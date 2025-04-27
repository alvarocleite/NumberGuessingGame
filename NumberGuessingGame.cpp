#include <iostream>
#include <cstdlib>
#include "cli.h"

#define DIFFICULTYLEVELS 3

int triesbyDifficulty [DIFFICULTYLEVELS] = { 10, 5, 3 };

int getRand();

int main(){
    int difficulty = 0;
    bool win = false;
    int tries = 0;

    Cli cli;
    difficulty = cli.chooseDifficulty() - 1;

    // Get random number
    int randNumber = getRand();

    do{
        win = (cli.getTry() == randNumber);
        tries++;
    } while (tries < triesbyDifficulty[difficulty] && !win);
    
    cli.displayResult(win, tries, randNumber);

    return 0;
}

int getRand(){
    int random;
    
    // Providing seed value
    srand(time(NULL));

    // Generate random value
    random = rand() % 100 + 1;
    
    return random;
}