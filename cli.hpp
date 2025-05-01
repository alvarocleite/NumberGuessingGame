
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
        void displayResult(bool, int, int);
        void startingGame();
        bool play_again();
        void hint(bool bigger);
};
