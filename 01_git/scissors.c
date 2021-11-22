#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* choise(char c)
{
    switch (c)
    {
        case 0:
        case 'r':
        case 'R':
            return "rock";
        case 1:
        case 'p':
        case 'P':
            return "paper";
        case 2:
        case 's':
        case 'S':
            return "scissors";
    }
    return "wrong";
}

char game(char c1, char c2)
{
    if (c1 == c2)
        return 0; // noone wins

    switch (c1+c2)
    {
        case 'p'+'r':
            return c1 == 'p'? 1 : 2; // papper wins (either 1st or 2nd player)
        case 'r'+'s':
            return c1 == 'r'? 1 : 2; // rock wins (either 1st or 2nd player)
        case 's'+'p':
            return c1 == 's'? 1 : 2; // scissors wins (either 1st or 2nd player)
    }

    return -1; // invalid combination
}

int main()
{
    printf("Please choose: rock (r) - paper (p) - scissors (s)\n");
    const char* s1 = choise(getchar());

    time_t t;
    srand((unsigned) time(&t));
    const char* s2 = choise(rand()%3);

    printf("You choose %s, I choose %s\n", s1, s2);

    char r = game(*s1, *s2);
    switch (r)
    {
        case 0:
            printf("Game draw\n");
            break;
        case 1:
            printf("You win: %s beats %s\n", s1, s2);
            break;
        case 2:
            printf("I win: %s beats %s\n", s2, s1);
            break;
        default:
            printf("I win by default\n");
            break;
    }

    return 0;
}
