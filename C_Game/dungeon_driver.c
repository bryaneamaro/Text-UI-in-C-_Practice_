#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enums.c"
#include "gameControls.c"


int main() {
    Player *user = malloc(sizeof(Player) );

    /* Map of rooms player can traverse through. Unused*/
    


    printf("\nNew Porgammig!!1\n\n");

    /* {This entire section initializes player info, make into separate function later} =============*/
    printf("Enter your character name: ");
    fgets(user->name, 20, stdin);
    user->name[strlen(user->name) -1] = '\0'; /* Eliminates trailing '\n' character  */
    print_gap(4);
    /* printf("{%s}, length: %d\n\n", user->name, strlen(user->name)); */

    user->attack = 9;
    user->health = 40;
    /* user->currentRoom = &(tutorial_map[0][0]); */
    /* ==============================================================================================*/

    print_info(user, 0);

    run_game(user, 1);
    

    return 0;
}

