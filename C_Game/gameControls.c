#include<stdlib.h>
#include<stdio.h>

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

void display_mapFrame(void*, int rows, int cols); /* Prints a 5*9 display of the Map */

void move_player(Player *player, char button );
void print_info(Player *player, int arg);
void print_gap(int i) ;

int dungeon_prompt();   /* Typical prompt used when player is in dungeon, returns player's choice as int  */
void* prompt_to_func(int code); /* Takes int, returns appropriate function pointer, 
    which will be used to run an event like- moving, attacking,  */
int run_game(Player *player, int difficulty);

int run_game(Player *player, int difficulty) {
    char map[4][7] = {  {'_', '_', '_', '_', 'O', '_', 'O'},
                        {' ', 'O', ' ', 'O', 'O', ' ', 'O'},
                        {' ', ' ', ' ', 'O', ' ', ' ', ' '},
                        {' ', 'O', ' ', ' ', ' ', 'O', ' '} };
    char meme_map[5][2] = { {'1', '2'}, {'3', '4'}, {'5', '6'}, {'7', '8'}, {'9', '0'} };
    char tutorial_map[5][1] = { {'A'}, {'B'}, {'C'}, {'D'}, {'E'} };
    player->currentRoom = &(tutorial_map[0][0]);

    while(player->health > 0) {
        printf("What will you do!?\n");

        printf("{%c}\n", map[0][0]);
        display_mapFrame(map, 4, 7);
        
        dungeon_prompt(); /* Sleeps for 3 secs */
        
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

int dungeon_prompt() {
    sleep(3);
    return 0;
}

void* prompt_to_func(int code) {
    return NULL;
}

void display_mapFrame(void* map , int rows, int cols) {
    char* row_ptr = (char*)map;
    printf("@@@@@@@@@@@\n");
    for(int i = 0; i < rows; i++ ) {
        /* for(int offset = 0; offset) */
        printf("@");
        /* Print actual row of map in here. */
        for(int room = 0; room < cols; room++) {
            
            printf("%c", row_ptr[room]);
        }
        printf("@\n");
        row_ptr += cols;    /* Shabby pointer arithmetic :( */
    }
    printf("@@@@@@@@@@@\n");


}