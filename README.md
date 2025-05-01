# NumberGuessingGame

This repo contains the Number Guessing Game project. 

This is my answer for the challenge from [roadmap.sh](https://roadmap.sh/projects/number-guessing-game).

## How to build

### Pre Requisites

- g++
- make

### Compiling

Only run the following command at project root after cloning:

```console
$ make all
```

## How to play

After compiling you can run the game with the following command

```console
$ ./NumberGuessingGame
```

After start the game the rules will appear:
- You must guess a number.
- The number are randomly generate each time you play.
- The number are between 1 and 100.
- You got between 3 and 10 chances, depending on the difficulty

You must choose a difficulty level:

- Easy (1): 10 attempts to guess the correct number.
- Medium (2): 5 attempts to guess the correct number.
- Hard (3): 3 attempts to guess the correct number.

Depending on the difficulty you chose you have a fix number of chances to correctly guess the random number

Each time you fail, the game will give you an hint to help you on you next guess.

If you cannot guess the number in the chances you have, you lost. If you correctly guess the number, you win.

The score is based on the number of tries you made. The lower number the best.

**Have fun!**

## Technical Details

This game is done in C++ and uses Make as a build tool.

## Authors

* [Álvaro Castro Leite](https://github.com/alvarocleite)


