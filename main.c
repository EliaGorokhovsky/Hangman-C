#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
#define PRINTLN(x) {printf(x); printf("\n");}
#define PRINTLNINT(x) {printf("%d", x); printf("\n");}

//The guessable letters in the game. All other characters will be printed instead.
const char letters[] = "abcdefgijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

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
    char * guessed = ""; //The letters that have already been guessed
    char * guessedCorrectly = malloc(strlen(word) * sizeof(char));
    PRINTLNINT(strlen(word));
    for(int i = 0; i < strlen(word); i++)
    {
        guessedCorrectly[i] = '_';
    }
    guessedCorrectly[strlen(word)] = '\0';
    printGuessed(guessedCorrectly);
    int * indices;
    findInstances(word, 'o', &indices);
    free(guessedCorrectly);
}