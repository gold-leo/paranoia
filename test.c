#ifndef PLAYER_LIST
#define PLAYER_LIST
#include "player_list.h"
#endif

#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

#ifndef STDBOOL
#define STDBOOL
#include <stdbool.h>
#endif

#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

#ifndef STRING
#define STRING
#include <string.h>
#endif

//assigns a string to an already-created character pointer
char* getstr()
{
    char* str = malloc(1);
    for (int n = 0;;)
    {
        char ch;
        scanf("%c", &ch);
        //breaks on user hitting enter or reaching the char limit.
        if (ch == (int)'\n')
        {
            str[n] = '\0';
            break;
        }
        //if input is within limit, write
        if (ch < 127 && ch > 31)
        {
            str[n] = ch;
            n++;
            str = realloc(str, n + 1);
        }
    }
    return str;
}

int main()
{
    //create the target ring
    player_list_t target_ring;
    player_list_t* tr = &target_ring;
    player_list_init(tr);

    printf("Press enter to start the game.\n");
    for (;;)
    {
        printf("Enter a player's name: ");
        char* str = getstr();
        if (strcmp("", str) == 0)
        {
            break;
        }
        player_list_append(tr, str);
    }

}