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

Grid_struct grid;
const char x = 'X';
const char o = 'O';

int main(int argc, char *argv[])
{

    init(&grid);
    play_as(x, 7, &grid);
    print_grid(&grid);
    play_as(x, 8, &grid);
    print_grid(&grid);
    play_as(x, 9, &grid);
    print_grid(&grid);
    return 0;
}
