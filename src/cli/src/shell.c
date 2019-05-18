#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include "shell.h"

/* ========================= */
/* === interface actions === */
/* ========================= */

/* See shell.h */
void help_text()
{
    char p[] =
        "HERE IS A BRIEF OVERVIEW OF GAME ACTIONS (SOME NOT IMPLEMENTED)\n"
        "LOOK [OBJECT]\n"
			"	-Look at specefied object\n"
        "TAKE [OBJECT]\n"
			"	-Take specefied object\n"
        "go [DIRECTION]\n"
			"	-Move to the south, east, west or north\n"
        "inv\n"
			"	-Prints everything you are carrying\n"
        "GIVE [OBJECT] TO [NPC]\n"
			"	-Gives specefied object to specefied non player character\n\n"

        "HERE IS A BRIEF OVERVIEW OF SYSTEM ACTIONS\n"
        "HELP\n" 
			"	-Prints out help menu (duh, you just used it)\n"
        "HIST\n"
			"	-Prints out the history of valid command"
			" inputs in this session\n"
        "load [PATH] (NOT IMPLEMENTED)\n"
			"	-Loads a saved game from a specefied location\n"
			"	 relative to the folder chiventure is running in\n"
        "save [PATH] (NOT IMPLEMENTED)\n"
		 	"	-Saves a game to a specefied location\n"
        "QUIT\n"
			"	-Quit game\n\n";
   printf("%s",p);
}

/* See shell.h */
void greet()
{
    printf("***** Welcome to CHIVENTURE! *****\n\n");
    printf("NOTHING USEFULL IMPLEMENTED YET !\n\n");
}

/* See shell.h */
void print_history()
{
    int offset_start = history_base,
        offset_end = history_length;

    int i, j=1;
    for (i = offset_start; i <= offset_end; i++)
    {
        printf("Entry %d: %s\n", j, history_get(i)->line);
        j++;
    }
}

/* See shell.h */
void shell_error(char *s)
{
    fprintf(stderr,"===> ERROR! You can't: %s <===\n",s);
}

/* See shell.h */
void shell_error_arg(char *fmt, char *s)
{
    fprintf(stderr,"===> ERROR: ");
    fprintf(stderr,fmt,s);
    fprintf(stderr," <===\n");
}