#include "../include/generator.h"

#define NULL_CHAR '\0'

char *randStrGen(int length, char *charset)
{
    char *password = (char *)malloc((length + 1) * sizeof(char));
    int charsetLength = strlen(charset);

    for (int i = 0; i < length; ++i)
    {
        password[i] = charset[rand() % charsetLength];
    }
    password[length] = NULL_CHAR;
    return password;
}

int *randIntGen(int size)
{
    int *password = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        password[i] = rand() % (int)pow(10, size);
    }
    return password;
}
