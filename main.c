#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Gets the number of elements in an array by taking the size of the array in bytes divided by the size of the array's first element
#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

//Defines a print line function that prints the given argument and then prints a newline afterwards
#define PRINTLN(x) { printf(x); printf("\n"); }

//Defines a print line function that only takes in integer arguments to print
#define PRINTLNINT(x) { printf("%d", x); printf("\n"); }

//The guessable letters in the game. All other characters will be printed instead.
const char letters[] = "abcdefghijklmnopqrstuvwxyz";

/**
 * Prints the gallows
 * progress is a number from 0 to 6 representing the amount of the hanged man to draw
 * This should correspond to number of incorrect guesses
 */
void printGallows(int progress)
{
    printf(" _________\n|         |\n");
    if (progress < 1) printf("|\n");
    else printf("|         0\n");
    if (progress < 2) printf("|\n");
    else if (progress == 2) printf("|         |\n");
    else if (progress == 3) printf("|        /|\n");
    else if (progress >= 4) printf("|        /|\\ \n");
    if (progress < 5) printf("|\n");
    else if (progress == 5) printf("|        / \n");
    else printf("|        / \\ \n");
    printf("|\n|______________\n");
}

/**
 * Prints the guessed letters of the word or underscores if not guessed correctly
 */
void printGuessed(char * guessedCorrectly)
{
    for (int i = 0; i < strlen(guessedCorrectly) - 1; i++)
    {
        printf("%c", guessedCorrectly[i]);
        printf(" ");
    }
    printf("%c\n", guessedCorrectly[strlen(guessedCorrectly) - 1]);
}

/**
 * Entry point of the program
 */
int main()
{
    char * word = "hello, world!"; //The correct word. Placeholder for now
    char guessed[27]; //27 to hold the length of the alphabet
    int numberOfGuesses = 0;
    char * guessedCorrectly = malloc(strlen(word) * sizeof(char));
    int incorrectGuesses = 0; //The amount of incorrect guesses that have been made
    for (int i = 0; i < strlen(word); i++)
    {
        if (strchr(letters, word[i]) != NULL)
        {
            guessedCorrectly[i] = '_';
        }
        else
        {
            guessedCorrectly[i] = word[i];
        }
    }
    guessedCorrectly[strlen(word)] = '\0';
    char guess = '_';
    char * placeholder = malloc(128 * sizeof(char));
    while (strcmp(guessedCorrectly,word) != 0 && incorrectGuesses < 6)
    {
        printGallows(incorrectGuesses);
        printGuessed(guessedCorrectly);
        printf("You have guessed the following letters: %s", guessed);
        printf("\n");
        printf("Guess: ");
        scanf("%s", placeholder, 1);
        guess = placeholder[0];
        printf("\n");
        //Verify that the guess is valid, or notify the player
        if (strchr(letters, guess) == NULL || strchr(guessed, guess) != NULL)
        {
            PRINTLN("Your guess is invalid.");
        }
        else
        {
            guessed[numberOfGuesses] = guess;
            numberOfGuesses++;
            guessed[numberOfGuesses] = '\0';
            if (strchr(word, guess) == NULL)
            {
                PRINTLN("Incorrect!");
                incorrectGuesses++;
            }
            else
            {
                //Replace the letters at the indices of the correctly guessed letters in guessedCorrectly
                for (int i = 0; i < strlen(word); i++)
                {
                    if (word[i] == guess)
                    {
                        guessedCorrectly[i] = guess;
                    }
                }
                PRINTLN("Correct!");
            }
        }
    }
    if (incorrectGuesses >= 6)
    {
        printGallows(incorrectGuesses);
        printGuessed(guessedCorrectly);
        PRINTLN("You lose... nice try.");
    }
    else
    {
        PRINTLN("You win!");
    }
    free(guessedCorrectly);
}