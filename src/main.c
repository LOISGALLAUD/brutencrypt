/*
 * Brute Force attack
 * on a password
 */

#include "../include/bruteForce.h"
#include "../include/generator.h"
#include <time.h>

#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define SPECIAL_CHARSET CHARSET "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

int main(void)
{
    srand(time(NULL));
    int size = 15;
    char *targetStrPwd = randStrGen(size, SPECIAL_CHARSET);

    printf("Target password: %s\n", targetStrPwd);

    return 0;
}
