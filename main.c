#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
#define PRINTLN(x) {printf(x); printf("\n");}
#define PRINTLNINT(x) {printf("%d", x); printf("\n");}

//The guessable letters in the game. All other characters will be printed instead.
char letters[] = "abcdefgijklmnopqrstuvwxyz";

/**
 * Finds all instances of a character in a string by index
 * Adds the indices of these instances to indices
 * indices should be empty
 */
int findInstances(char string[], char toFind, int* indices[]) 
{
    for(int i = 0; i < strlen(string); i++) 
    {
        if(string[i] == toFind)
        {
            *indices[NELEMS(*indices)] = i;
        }
    }
    return 1;
}

/**
 * Prints the gallows
 * progress is a number from 0 to 6 representing the amount of the hanged man to draw
 * This should correspond to number of incorrect guesses
 */
int printGallows(int progress)
{
    printf(" _________\n|         |\n");
    if(progress < 1) printf("|\n");
    else printf("|         0\n");
    if(progress < 2) printf("|\n");
    else if(progress == 2) printf("|         |\n");
    else if(progress == 3) printf("|        /|\n");
    else if(progress >= 4) printf("|        /|\\ \n");
    if(progress < 5) printf("|\n");
    else if(progress == 5) printf("|        / \n");
    else printf("|        / \\ \n");
    printf("|\n|______________\n");
}

/**
 * Prints the guessed letters of the word or underscores if not guessed correctly
 */
int printGuessed(char * guessedCorrectly)
{
    for(int i = 0; i < strlen(guessedCorrectly) - 1; i++)
    {
        printf("%c", guessedCorrectly[i]);
        printf(" ");
    }
    printf("%c\n", guessedCorrectly[strlen(guessedCorrectly) - 1]);
    return 1;
}

/**
 * Entry point of the program
 */
int main()
{
    char * word = "Helloworld"; //The correct word. Placeholder for now
    char guessed[27];
    int numberOfGuesses = 0;
    char * guessedCorrectly = malloc(strlen(word) * sizeof(char));
    int incorrectGuesses = 0; //The amount of incorrect guesses that have been made
    for(int i = 0; i < strlen(word); i++)
    {
        guessedCorrectly[i] = '_';
    }
    guessedCorrectly[strlen(word)] = '\0';
    char guess = '_';
    char * placeholder = malloc(128 * sizeof(char));
    while(guessedCorrectly != word)
    {
        printGallows(incorrectGuesses);
        printGuessed(guessedCorrectly);
        printf("Guess: ");
        scanf("%s", placeholder, 1);
        guess = placeholder[0];
        guessed[numberOfGuesses] = guess;
        numberOfGuesses++;
        guessed[numberOfGuesses] = '\0';
        printf("\n");
        printf("You have guessed the following letters: %s", guessed);
        printf("\n");
        if(strchr(word, guess) == NULL)
        {
            incorrectGuesses++;
        }
        //guessedCorrectly = "Helloworld";
    }
    free(guessedCorrectly);
}