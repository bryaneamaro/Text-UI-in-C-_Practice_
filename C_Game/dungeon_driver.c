#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enums.c"

typedef struct monster {
    char* currentRoom;
    int health;
    int attack;

} Monster;

typedef struct player {
    char* name;
    void* currentRoom;
    int health;
    int attack;
} Player;

void display_mapFrame(char** map);
void move_player(Player *player, char button );
void print_info(Player *player, int arg);
void print_gap(int i) ;
int dungeon_prompt();
void* prompt_to_func(int code);


int main() {
    /* Create 2d array holding ENUMS */
    Player *user = malloc(sizeof(Player) );


    char map[4][7] = {  {' ', ' ', ' ', ' ', 'O', ' ', 'O'},
                        {' ', 'O', ' ', 'O', 'O', ' ', 'O'},
                        {' ', ' ', ' ', 'O', ' ', ' ', ' '},
                        {' ', 'O', ' ', ' ', ' ', 'O', ' '} };

    char tutorial_map[5][1] = { {' '}, {' '}, {' '}, {' '}, {' '} };

    printf("\nNew Porgammig!!1\n\n");
    
    printf("Enter your character name: ");
    fgets(user->name, 20, stdin);
    user->name[strlen(user->name) -1] = '\0';

    print_gap(4);
    printf("{%s}, length: %d\n\n", user->name, strlen(user->name));

    user->attack = 9;
    user->health = 40;
    user->currentRoom = &(tutorial_map[0][0]);
    print_info(user, 0);

    run_game;
    

    return 0;
}

int run_game(Player *player, int difficulty) {
    while(player->health > 0) {
        printf("What will you do!?\n");
        dungeon_prompt();

        sleep(3);
        printf("\nEnd of cycle!\n\n");
        printf("[][][][][][][][][][][][][][][][][][][][][][]\n\n");
    }
}

void print_info(Player *player, int arg) {

    if(arg == 0) {
        printf("!!! Starting Stats !!!\n");
    }
    printf("{}============{ %s }==========={}\n", player->name);
    printf("{} Health: %d | Attack: %d\n\n", player->health, player->attack);
    

}
void print_gap(int i) {
    for( i ; i > 0 ; i-- ) {
        printf("\n");
    }
}