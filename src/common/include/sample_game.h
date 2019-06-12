#ifndef _INClUDE_SAMPLE_GAME_H
#define _INClUDE_SAMPLE_GAME_H

#include "game.h"

/*
 * Creates a sample 1 player 2 room game struct
 *
 * Parameters:
 *  - nothing
 *
 * Returns:
 *  - A pointer to a game struct
 */
game_t* create_sample_game();

game_t *create_sample_game_cp();

game_t *create_sample_game_gs();

#endif /* _INClUDE_SAMPLE_GAME_H */
