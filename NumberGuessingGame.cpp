#include <iostream>
#include <cstdlib>
#include "cli.hpp"

#define DIFFICULTYLEVELS 3

int triesbyDifficulty [DIFFICULTYLEVELS] = { 10, 5, 3 };

int gameCycle(Cli& cli, const int difficulty);
int getRand();

int main(){
    int difficulty = 0;
    bool play_again = false;

    Cli cli;
    difficulty = cli.chooseDifficulty() - 1;

    do{
        cli.startingGame();

        gameCycle(cli, difficulty);

        play_again = cli.play_again();
    }while(play_again);

    return 0;
}

int gameCycle(Cli& cli, const int difficulty){
    bool win = false;
    int tries = 0;
    // Get random number
    int randNumber = getRand();

    do{
        win = (cli.getTry() == randNumber);
        tries++;
    } while (tries < triesbyDifficulty[difficulty] && !win);
    
    cli.displayResult(win, tries, randNumber);

    return 1;
}

int getRand(){
    int random;
    
    // Providing seed value
    srand(time(NULL));

    // Generate random value
    random = rand() % 100 + 1;
    
    return random;
}