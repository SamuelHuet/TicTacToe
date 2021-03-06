
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct{
  unsigned char line1 [3];
  unsigned char line2 [3];
  unsigned char line3 [3];
} Grid_struct;

void init(Grid_struct *grid);
void print_grid(Grid_struct *grid);
unsigned char play_as(unsigned char *xo, unsigned char number, Grid_struct *grid, char* player1, char* player2);
unsigned char Settings(char *player1, char *player2);
unsigned char check_win(Grid_struct* grid, char* player1, char* player2, char* winner);
unsigned char get_box(unsigned char player, Grid_struct *grid, char* player1, char* player2);
