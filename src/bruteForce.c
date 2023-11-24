#include "../include/bruteForce.h"
#include "../include/generator.h"

int incrementGuessBruteForce(int pwd, int size)
{
    // First step: the pwd is a number (10 possibilities for each digit)
    int i;
    for (i = 0; i < (int)pow(10, size); ++i)
    {
        if (pwd == i)
            return i;
    }
    return -1;
}

int randomGuessBruteForce(int pwd, int size)
{
    // Problem with this approach:
    // the algorithm can guess the same number twice
    int guess;
    while (guess != pwd)
    {
        guess = rand() % (int)pow(10, size);
    }
    return guess;
}

int randomGuessBruteForceMemory(int targetPwd, int size)
{
    // Objective: guessing the password with each attempt
    // having a higher probability of being correct.

    // Fill the array with all the possible numbers
    int *guessTab = (int *)malloc(sizeof(int) * (int)pow(10, size));
    int tabSize = (int)pow(10, size);
    for (int i = 0; i < (int)pow(10, size); ++i)
    {
        guessTab[i] = i;
    }

    while (1)
    {
        int randomIndex = rand() % tabSize;
        int guess = guessTab[randomIndex];
        // printf("Guess: %i\t Target: %i\n", guess, targetPwd);
        if (guess != targetPwd)
        {
            // Remove the guessed number from the array
            for (int i = randomIndex; i < tabSize - 1; ++i)
            {
                guessTab[i] = guessTab[i + 1];
            }
            tabSize--;
        }
        else
        {
            free(guessTab);
            return guess;
        }
    }
}

// Second step: the pwd is a string
char *randomGuessBruteForceString(char *targetPwd, int length, char *charset)
{
    // Problem with this approach:
    // the algorithm can guess the same string twice
    // (and it's very unlikely to guess the right string)
    char *guessPassword = randStrGen(length, charset);

    while (strcmp(guessPassword, targetPwd) != 0)
    {
        free(guessPassword);
        guessPassword = randStrGen(length, charset);
    }
    return guessPassword;
}
