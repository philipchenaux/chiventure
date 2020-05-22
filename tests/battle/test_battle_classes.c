#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../include/battle/battle_classes.h"


/* Tests new_class() */
Test(class, new)
{
    char *test_str;
    test_str = "Test description";

    class_t* class;
    class = new_class(0, test_str, 1, 3.0);

    cr_assert_not_null(class, "new_class() failed");

    cr_assert_eq(class->info, test_str, "new_class() didn't set info");
}


/* Tests init_class() */
Test(class, init)
{
    class_t class;
    int rc;

    char *test_str;
    test_str = "Test description";

    rc = init_class(&class, 0, test_str, 1, 3.0);

    cr_assert_eq(rc, 0, "init_class() failed");

    cr_assert_eq(class.info, test_str, "init_class() didn't set info");
}


/* Test make_test_bard */
Test(class, bard)
{
    class_t *bard = make_test_bard();
    
    cr_assert_eq(bard->cl, 0, "make_test_bard() didn't set class type");

    cr_assert_eq(bard->info,
                 "Charismatic, always has a joke, song, or moving speech ready", 
		 "make_test_bard() didn't set class info);
   
    cr_assert_eq(bard->st, 3, "make_test_bard() didn't set stat bonus type”);

    cr_assert_eq(bard->bonus, 2.0, "make_test_bard() didn't set stat bonus value”);
}


/* Test make_test_cleric */
{
    class_t *cleric = make_test_cleric();
    
    cr_assert_eq(cleric->cl, 1, "make_test_cleric() didn't set class type");

    cr_assert_eq(cleric->info,
                 "Fueled by divine inspiration, devout to the craft",
                 "make_test_cleric() didn't set class info);
   
    cr_assert_eq(cleric->st, 1, "make_test_cleric() didn't set stat bonus type”);

    cr_assert_eq(bard->bonus, 2.0, "make_test_cleric() didn't set stat bonus value”);
}


/* Test make_test_paladin */
{
    class_t *paladin = make_test_paladin();
    
    cr_assert_eq(paladin->cl, 2, "make_test_paladin() didn't set class type");

    cr_assert_eq(paladin->info,
                 "Driven and committed to justice",
                 "make_test_paladin() didn't set class info);
   
    cr_assert_eq(paladin->st, 2, "make_test_paladin() didn't set stat bonus type”);

    cr_assert_eq(paladin->bonus, 2.0, "make_test_paladin() didn't set stat bonus value”);
}


/* Test make_test_wizard */
{
    class_t *wizard = make_test_wizard();
    
    cr_assert_eq(wizard->cl, 3, "make_test_wizard() didn't set class type");

    cr_assert_eq(wizard->info,
                 "Draws power from nature",
                 "make_test_wizard() didn't set class info);
   
    cr_assert_eq(wizard->st, 0, "make_test_wizard() didn't set stat bonus type”);

    cr_assert_eq(wizard->bonus, 2.0, "make_test_wizard() didn't set stat bonus value”);
}


