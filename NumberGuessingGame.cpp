#include <iostream>
#include <cstdlib>
#include <chrono>
#include "cli.hpp"

#define DIFFICULTYLEVELS 3

int triesbyDifficulty [DIFFICULTYLEVELS] = { 10, 5, 3 };

int gameCycle(Cli& cli, const int difficulty);
int getRand();

int main(){
    int difficulty = 0;
    bool play_again = false;
    int newScore, bestScore = 11;

    Cli cli;
    difficulty = cli.chooseDifficulty() - 1;

    do{
        cli.startingGame();

        newScore = gameCycle(cli, difficulty);
        if (newScore > 0 && newScore < bestScore)
            bestScore = newScore;

        if (bestScore < triesbyDifficulty[difficulty])
            cli.printBestScore(bestScore);
        
        play_again = cli.play_again();
    }while(play_again);

    return 0;
}

/* This function returns:
    - -1 in case of lost
    - number of tries in case of win
*/
int gameCycle(Cli& cli, const int difficulty){
    bool win = false;
    int tries = 0;

    // Time variables
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;

    // Get random number
    int randNumber = getRand();

    // Start timer
    start = std::chrono::system_clock::now();

    do{
        int guess = cli.getTry();
        if (guess == randNumber){
            win = true;
        }
        else {
            cli.hint(guess < randNumber);
        }
        tries++;
    } while (tries < triesbyDifficulty[difficulty] && !win);
    
    // Stop timer
    end = std::chrono::system_clock::now();

    // calculate time in seconds
    elapsed_seconds = end - start;
    
    cli.displayResult(win, tries, randNumber, elapsed_seconds.count());

    return win ? tries : -1;
}

int getRand(){
    int random;
    
    // Providing seed value
    srand(time(NULL));

    // Generate random value
    random = rand() % 100 + 1;
    
    return random;
}