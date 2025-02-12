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

//get a string. (basically getline)
char* getstr()
{
    //begin loop
    char* str;
    for (int n = 0;;)
    {
        str = realloc(str, n + 1);
        char ch;
        scanf("%c", &ch);
        //breaks on user hitting enter.
        if (ch == '\n')
        {
            str[n] = '\0';
            break;
        }
        //if input is within limit, write
        if (ch < 127 && ch > 31)
        {
            str[n] = ch;
            n++;
        }
    }
    return str;
}

//Print the state of the ring.
//Return true if the list has one player left.
bool print_ring_state(const player_list_t* tr, const player_list_t* tg)
{
    print_as_target_ring(tr);
    print_as_tagged_list(tg);

    //if one/zero players left, return true.
    int n = player_list_length(tr);
    if (n <= 1)
    {
        return true;
    }
    printf("There are %d people left.\n", n);
    return false;
}

int main()
{
    //create the target ring
    player_list_t target_ring;
    player_list_t* tr = &target_ring;
    player_list_init(tr);

    //create tagged list
    player_list_t tagged_list;
    player_list_t* tg = &tagged_list;
    player_list_init(tg);

    //inputting players loop
    printf("Press enter to start the game.\n");
    for (;;)
    {
        printf("Enter a player's name: ");
        char* str = getstr();
        if (strcmp("", str) == 0)
        {
            free(str);
            break;
        }
        player_list_append(tr, str);
    }

    //if one player left, end game
    if (print_ring_state(tr, tg) == true)
    {
        printf("The game has ended.\n");
    }
    else
    {
        //removing players loop
        for (;;)
        {
            printf("Enter a target: ");
            char* str = getstr();
            //if no player with matching name, print
            if (player_list_remove(tr, str) == false)
            {
                printf("%s is not a target.\n", str);
                free(str);
            }
            else
            {
                player_list_append(tg, str);
            }

            //if one player left, end game
            if (print_ring_state(tr, tg) == true)
            {
                printf("The game has ended.\n");
                break;
            }
        }
    }
    
    player_list_destroy(tr);
    player_list_destroy(tg);
}
