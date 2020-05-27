#ifndef BATTLE_MOVES_H
#define BATTLE_MOVES_H

#include <stdbool.h>
#include <string.h>
#include "battle_classes.h"
#include "battle_structs.h"


/* For use in testing battle code,
make a test move for each class */

move_t *test_move_bard();

move_t *test_move_cleric();

move_t *test_move_paladin();

move_t *test_move_wizard();


#endif
