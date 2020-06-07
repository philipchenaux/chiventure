/* Team RPG-Openworld
*
* Default NPC header file
*
* default_npc.h: This file: contains all of the necessary npc  structs and functions
* that are necessary to move npcs in a autogenerated room
*
* See chiventure/src/openworld/default_npc.c source code to see implementation.
*/
#ifndef _DEFAULT_NPCS_H
#define _DEFAULT_NPCS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game-state/game_state_common.h"

/*
* npc_classification
* Classification of the type of NPC characters to be found
* within the rooms. Where friendly means NPC doesn't engage in fights,
* Hostile means engages in fights, and generic means can engage in fights
*/

typedef enum npc_classification {
	NPC_GENERIC = 0,
	NPC_HOSTILE = 1,
	NPC_FRIENDLY = 2
} npc_classification_t;


/* npc_t struct
* This struct will carry the necessary info for creating a NPC in a room 
* This struct contains:
* - int level: player level in game
* - char *npc_name: strings a NPC type and name, ex: wizard type Hostile
* -  npc_classification_t classification: enum for the three types of NPCs
* - item_hash_t *item inventory: item inventory for the NPCs
*/
typedef struct npc
{
	char *npc_name;
	int level;
	item_hash_t *inventory;
	npc_classification_t classification;
	struct npc *next;
	struct npc *prev;
	UT_hash_handle hh;
} npc_t;

/* get_hostile_npcs produces mock NPCs of type Hostile.
* Will recieve a linked list of hostile npcs and includes the items that
* each NPC carries with them makes 3 npcs that are hostile
* Input:
*  - none
* Output:
*  - a hash list of hostile npcs with their own items inventory
*/
npc_t *get_hostile_npcs();


/* get_friendly_npcs produces mock NPCs of type Friendly
* makes 3 npcs that are friendly and includes the items that each NPC carries with them. 
* Input:
* - none
* Output:
* - Returns them as a hash list
*/
npc_t *get_friendly_npcs();



/* get_generic_npcs produces mock NPCs of type Generic
* Generic: NPCs that you can choose to be friendly or hostile with
* Function  makes 3 npcs that are generic and includes the items that each NPC carries with them
* Input:
* - none
* Output:
* - puts the NPCs in as a hash list
*/
npc_t *get_generic_npcs();


#endif