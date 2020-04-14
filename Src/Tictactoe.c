#include "Tictactoe.h"

void init(Grid_struct *grid){
  strcpy( grid->line1, "123");
  strcpy( grid->line2, "456");
  strcpy( grid->line3, "789");
}

void print_grid(Grid_struct *grid){
  printf("-------------------\r\n");
  printf("|  %c  |  %c  |  %c  |\r\n", grid->line1[0], grid->line1[1], grid->line1[2]);
  printf("-------------------\r\n");
  printf("|  %c  |  %c  |  %c  |\r\n", grid->line2[0], grid->line2[1], grid->line2[2]);
  printf("-------------------\r\n");
  printf("|  %c  |  %c  |  %c  |\r\n", grid->line3[0], grid->line3[1], grid->line3[2]);
  printf("-------------------\r\n");
}

void play_as(char xo, unsigned char number, Grid_struct *grid){
    grid->line1[number-1] = xo;
}

void Settings(char *player1, char *player2){
  char temp;
  printf("Select the player1 symbol then press [ENTER],\r\ntype '@' to let play an AI\r\n");
  fflush(stdin);
  scanf("%c", &temp);

  printf("Select the player2 symbol then press [ENTER],\r\ntype '@' to let play an AI\r\n");
  fflush(stdin);
  scanf("\n%c", &temp);
}



Grid_struct grid;
char player1 = 'X';
char player2 = 'O';

int main(int argc, char *argv[])
{

    init(&grid);
    print_grid(&grid);
    Settings(&player1, &player2);
    fflush(stdout);
    //printf("%s and %s", player1, player2);
    return 0;
}
