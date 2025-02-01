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

//Initialize an empty list. 
//The lst parameter must point to usable memory that can hold a player_list_t.
void player_list_init(player_list_t* lst)
{
    lst->head = NULL;
}

//Free all memory allocated as part of the provided list.
void player_list_destroy(player_list_t* lst)
{
    //goes through all players and frees them
    player_t* i = lst->head;
    for (; i != NULL; i = i->next)
    {
        free(i->name);
        free(i);
    }
    lst->head = NULL;
}

//Add a player to the end of the given list. 
//This function should take ownership of the memory pointed to by the name parameter.
void player_list_append(player_list_t* lst, char* name)
{
    player_t *new_node = NULL;

    //allocate mem for new_node
    new_node = (player_t*)malloc(sizeof(player_t));
    if (new_node == NULL)
    {
        printf("Error: malloc failed in string_list_insert\n");
        exit(EXIT_FAILURE);
    }

    //setup new_node
    new_node->name = (char*)malloc(strlen(name) + 1);
    strcpy(new_node->name, name);
    new_node->next = NULL;

    //if lst->head is empty, replace with item
    if (lst->head != NULL)
    {
        //go to end of list
        for (player_t* p = lst->head;; p = p->next) 
        {
            //add new_node to the end of the list
            if (p->next == NULL) 
            {
                p->next = new_node;
                break;
            }
        }
    }
    else
    {
        lst->head = new_node;
    }
    
    
    free(name);
}

//Remove the player with the provided name from the list. 
//Return true if a matching player was found and removed, or false otherwise.
bool player_list_remove(player_list_t* lst, char* name)
{
    player_t* prev = NULL;

    //go through player_list looking for matching names until the end of the list
    player_t* p = lst->head;
    for (;p != NULL;)
    {
        //test if the name matches
        if (strcmp(name, p->name) == 0)
        {
            //test if first in the list
            if (prev == NULL)
            {
                lst->head = p->next;
            }
            else
            {
                prev->next = p->next;
            }
            free(p->name);
            free(p);

            return true;
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }

    return false;
}

//Return the number of players in the given list.
size_t player_list_length(const player_list_t* lst)
{
    int length = 0;

    //increment for each player in the player_list
    player_t* p = lst->head;
    for(;p != NULL; p = p->next)
    {
        length++;
    }

    return length;
}

//Print the current list, interpreting it as the target ring. 
void print_as_target_ring(const player_list_t* lst)
{
    player_t* p = lst->head;
    //test if no players in player_list.
    if (p == NULL)
    {
        printf("There are no targets left.\n");
    }
    else
    {
        //test if there is only one player in player_list.
        if (p->next == NULL)
        {
            printf("%s is the final person remaining.\n", p->name);
        }
        else
        {
            //go through every player in player_list.
            printf("Target Ring:\n");
            for (;; p = p->next)
            {
                printf("%s is stalking %s\n", p->name, p->next->name);
                //if at the second to last, print the circular portion and exit
                if (p->next->next == NULL)
                {
                    printf("%s is stalking %s\n", p->next->name, lst->head->name);
                    break;
                }
            }

        }
    }
}

//Print the current list interpreting it as the tagged list.
void print_as_tagged_list(const player_list_t* lst)
{
    //check if list is empty
    if (lst->head == NULL)
    {
        printf("No people have been tagged yet.\n");
    }
    else
    {
        //go through players in player_list
        printf("Tagged List:\n");
        for (player_t* p = lst->head; p != NULL; p = p->next)
        {
            printf("%s\n", p->name);
        }

    }
    printf("\n");
}