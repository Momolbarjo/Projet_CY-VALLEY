#ifndef HEADER_H
#define HEADER_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>


#define SIZE 100
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define FORMAT_STRING "https://www.youtube.com/watch?v=zRGCzCn5azI/%d"


typedef struct {
  int pos_x;
  int pos_y;
} Position;

typedef struct {
  int herbs;
  int woods;
  char item1[15];
  char item2[15];
  char item3[15];
} Inventory;

typedef struct {
  bool npc1_step1;
  bool npc2_step1;
  bool npc1_step2;
  bool npc2_step2;
  bool timer_start;
} Quests;


typedef struct {
  char name[20];
  int health;
  Inventory itemsPlayer;
  int dimensions;
  Position posPlayer;
  int score;
  int quest_seconds;
  Quests npcs;
} Player;

void ClearScreen();
int print_game_instructions();
void Introduction(Player* knight);
void initialise_board(int board[SIZE][SIZE]);
void randomizer(int map[SIZE][SIZE]);
void open_website_part(int i); 
void print_board(int board[SIZE][SIZE]);
void print_Overlay(Player *a);
void area_print(int board[SIZE][SIZE], Player *knight);
int move_window(int board[SIZE][SIZE], Player *knight);
int show_menu();
void Secure_Boot(Player* knight, Inventory* invent_player, Position* pos, Quests* npcs);
int interaction(int board[SIZE][SIZE],Player* knight);
void teleporter_interaction(int board[SIZE][SIZE], Player *knight);
void game_over();
void gift_interaction(Player *knight);
void npc2_quest(int map[SIZE][SIZE], Player* knight);
void npc1_quest(int map[SIZE][SIZE], Player* knight);
void npc2_shop(Player* knight);
void savegame(const int map[SIZE][SIZE], const Player* player, const char* playerName, const char* mapName);
void savemap(const int map[SIZE][SIZE], const char* fileName);
void saveplayer(const Player* player, const char* fileName);
void loadgame(int map[SIZE][SIZE], Player* player, const char* playerName, const char* mapName);
void loadmap(int map[SIZE][SIZE], const char* fileName);
void loadplayer(Player* player, const char* fileName);
void timer(Player *knight);
void deleteMapSaveFile(const char* fileName);
void deletePlayerSaveFile(const char* fileName);
void deleteSaveFiles(const char* mapFileName, const char* playerFileName);
bool fileExists(const char* fileName);
char getch();
void Cy_shop();
void display_end_screen();
void clear_buffer();

#endif
