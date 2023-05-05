#include "header.h"

int move_window(int tab[SIZE][SIZE], Player *player) {
  int score = 0;

  int window_x = player->posPlayer.pos_x -
                 9; // Coordonnée x du coin supérieur gauche de la fenêtre
  int window_y = player->posPlayer.pos_y -
                 9; // Coordonnée y du coin supérieur gauche de la fenêtre

  while (1) {
    // Afficher la fenêtre
    ClearScreen();
    print_Overlay(player);
    printf("\n");
    printf("\n");
    for (int x = window_x; x < window_x + 20; x++) {
      for (int y = window_y; y < window_y + 20; y++) {
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
          if (x == player->posPlayer.pos_x && y == player->posPlayer.pos_y) {
            printf(ANSI_COLOR_YELLOW "P " ANSI_COLOR_RESET);
          } else if (tab[x][y] == '*') {
        printf("\u2694 ");
      } else if (tab[x][y] == '@') {
        printf("\U0001F33F");
      } else if (tab[x][y] == '=') {
        printf( "\U0001F64B"); // Ajout d'un espace après l'emoji
      } else if (tab[x][y] == '^') {
        printf("\U0001F9D9");
      } else if (tab[x][y] == '#') {
        printf("\U0001F6E1 ");
      } else if (tab[x][y] == 'W') {
        printf("\U0001FAB5 ");
      } else if (tab[x][y] == 'R') {
        printf("\U0001FAA8 ");
      } else if (tab[x][y] == '~') {
        printf("\U0001F381");
      } else if (tab[x][y] == '!') {
        printf("\U0001F9CC ");
      } else if (tab[x][y] == 'H') {
        printf("\U0001F3E1");
      } else if (tab[x][y] == 'X') {
        printf("\U0001F30A");
      } else {
        printf("%c ", tab[x][y]);
      }
    }else {
          printf("  "); // Afficher un espace pour les coordonnées en dehors de
                        // la map
        }
      }
      printf("\n");
    }
    // Récupérer la touche frappée par le joueur
    char input;
    input = getchar();
    getchar();
    usleep(550000);
    // Déplacer le joueur en conséquence
    switch (input) {
    case 'z':
      if (player->posPlayer.pos_x > 2) {
        player->posPlayer.pos_x--;
        window_x--;
      }
      break;
    case 'q':
      if (player->posPlayer.pos_y > 2) {
        player->posPlayer.pos_y--;
        window_y--;
      }
      break;
    case 's':
      if (player->posPlayer.pos_x < SIZE - 3) {
        player->posPlayer.pos_x++;
        window_x++;
      }
      break;
    case 'd':
      if (player->posPlayer.pos_y < SIZE - 3) {
        player->posPlayer.pos_y++;
        window_y++;
      }
      break;
    case 'e':
      ClearScreen();
      printf(
          "What do you want to do?\n1.resume\n2.save\n3.Map\n4.Return to the menu\n");
      char choice = getchar();
      getchar(); // Consume the newline character
      if (choice == '1') {

      } else if (choice == '2') {
        ClearScreen();
        printf("Saving...\n");
        sleep(3);
        printf("Game saved!\n");
        sleep(2);
      } else if (choice == '3') {
        ClearScreen();
        area_print(tab,player);
        sleep(3);
      }else if (choice == '4') {
        ClearScreen();
        return 0;
      }
      break;
    default:
      printf("Invalid input.\n");
      getchar();
      break;
    }
  }
}
