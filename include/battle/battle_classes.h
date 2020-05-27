#ifndef BATTLE_CLASSES_H
#define BATTLE_CLASSES_H

#include "common/utlist.h"
#include "common/common.h"
#include <stdbool.h>
#include <string.h>

/* define max size of class info strings */
static const int MAX_CLASS_INFO_LEN = 100;


/* A mock player class type enum that
 * includes 4 classes:
 * bard
 * cleric
 * paladin
 * wizard
 */
typedef enum class_type
{
    CLASS_BARD,
    CLASS_CLERIC,
    CLASS_PALADIN,
    CLASS_WIZARD
} class_type_t;


/* Players get stat bonuses based on their class.
 * This enum type is part of the class struct. Whichever stat
 * is stored in class_t.st is increased by class_t.bonus
 * includes the following mock stats:
 * speed
 * strength
 * dexterity 
 * charisma 
 */
typedef enum possible_stats
{
    STAT_SPEED,
    STAT_STRENGTH,
    STAT_DEXTERITY,
    STAT_CHARISMA
} possible_stats_t;


/* The mock  player class struct, which includes:
 * class_type: the enum class type (bard, cleric, paladin, wizard)
 * info: a short description of the class
 * stats: which stat the class gets a bonus for
 * bonus: how much that bonus is, a flat number 
 */
typedef struct class
{
    class_type_t class_type;
    char *info;
    possible_stats_t stats;
    int bonus;
} class_t;


/*
 * Allocates a class
 *
 * Parameters:
 * - class_type: an enum class type
 * - info: a short description of the class
 * - stats: the stat that the class receives a bonus for
 * - bonus: the amount added to the designated stat
 *
 * Returns:
 * -A pointer to the class, or NULL if a class
 *  cannot be allocated
 */
class_t *new_class(class_type_t class_type, char* info,
                   possible_stats_t stats, double bonus);

/*
 * Initializes a class
 *
 * Parameters: 
 * - class: A class pointer. Must point to allocated memory. 
 * - class_type: an enum class type
 * - info: a short description of the class
 * - stats: the stat that the class receives a bonus for
 * - bonus: the amount added to the designated stat
 *
 * Returns:
 * - 0 for success, 1 if an error occurs
 */
int init_class(class_t *class, class_type_t class_type, char* info,
	       possible_stats_t stats, double bonus);


/* Initializes one hard-coded test class 
for each of the four class */

class_t *make_test_bard();

class_t *make_test_cleric();

class_t *make_test_paladin();

class_t *make_test_wizard();



#endif