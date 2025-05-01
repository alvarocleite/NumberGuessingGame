#ifndef _CLI_H
#define _CLI_H

class Cli{
    private:
        void printWelcome();
        void printRules();
        bool getProtectedIntInput(int&);

    public:
        Cli();
        ~Cli();
        int chooseDifficulty();
        int getTry();
        void displayResult(bool, int, int, double);
        void startingGame();
        bool play_again();
        void hint(bool bigger);
};

#endif /* _CLI_H */
