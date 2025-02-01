#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

#ifndef STDBOOL
#define STDBOOL
#include <stdbool.h>
#endif

//A player
typedef struct player_t
{
    char* name;
    struct player_t* next;
} player_t;


//A string list
typedef struct player_list_t
{
    player_t* head;
} player_list_t;

//Initialize an empty list. 
//The lst parameter must point to usable memory that can hold a player_list_t.
void player_list_init(player_list_t*);

//Free all memory allocated as part of the provided list.
void player_list_destroy(player_list_t*);

//Add a player to the end of the given list. 
//This function should take ownership of the memory pointed to by the name parameter.
void player_list_append(player_list_t*, char*);

//Remove the player with the provided name from the list. 
//Return true if a matching player was found and removed, or false otherwise.
bool player_list_remove(player_list_t*, char*);

//Return the number of players in the given list.
size_t player_list_length(const player_list_t*);

//Print the current list, interpreting it as the target ring. 
void print_as_target_ring(const player_list_t*);

//Print the current list interpreting it as the tagged list.
void print_as_tagged_list(const player_list_t*);
