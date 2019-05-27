#include <stdlib.h>
#include <stdbool.h>
#include <criterion/criterion.h>
#include "utlist.h"
#include "actionmanagement.h"

#define NUM_ACTIONS (13)

action_type_t *search_supported_actions(char *query)
{
    list_action_type_t *head, *temp;
    head = get_supported_actions();
    for (temp = head; temp != NULL; temp = temp->next)
    {
        if (strcmp(temp->act->c_name,query) == 0)
        {
            return temp->act;
        }        
    }
    return NULL;
}

/* Checks to see if the action list called can be iterated over using string */
Test(get_actions, search_success)
{
    action_type_t *open, *consume, *go, *use_on;
    open = search_supported_actions("open");
    consume = search_supported_actions("consume");
    go = search_supported_actions("go");
    use_on = search_supported_actions("use on");

    cr_assert_neq(open, NULL, 
                  "search_supported_actions returned a null for query \"open\".\n");
    cr_assert_neq(consume, NULL, 
                  "search_supported_actions returned a null for query \"consume\".\n");
    cr_assert_neq(go, NULL, 
                  "search_supported_actions returned a null for query \"go\".\n");
    cr_assert_neq(use_on, NULL, 
                  "search_supported_actions returned a null for query \"use on\".\n");

    cr_assert_eq(open->kind, ITEM, 
                 "Expected the action kind %d, but got action kind %d.\n",
                 ITEM, open->kind);
    cr_assert_eq(consume->kind, ITEM, 
                 "Expected the action kind %d, but got action kind %d.\n",
                 ITEM, consume->kind);
    cr_assert_eq(go->kind, PATH, 
                 "Expected the action kind %d, but got action kind %d.\n",
                 PATH, go->kind);
    cr_assert_eq(use_on->kind, ITEM_ITEM, 
                 "Expected the action kind %d, but got action kind %d.\n",
                 ITEM_ITEM, use_on->kind);
}

Test(get_actions, search_failure)
{
    action_type_t *dance, *jump, *fight;
    dance = search_supported_actions("dance");
    jump = search_supported_actions("jump");
    fight = search_supported_actions("fight");
    cr_assert_eq(dance, NULL, 
                 "search_supported_actions returned a pointer for invalid query \"dance\".\n");
    cr_assert_eq(jump, NULL, 
                 "search_supported_actions returned a pointer for invalid query \"jump\".\n");
    cr_assert_eq(fight, NULL, 
                 "search_supported_actions returned a pointer for invalid query \"fight\".\n");
}

Test(get_actions, count)
{   
    list_actions_type_t *head, *elt;
    head = get_supported_actions();
    int count;
    LL_COUNT(head, elt, count);
    cr_assert_eq(count, NUM_ACTIONS,
                 "Expected a count of %d items, but got a count of %d.\n",
                 count, NUM_ACTIONS);
}