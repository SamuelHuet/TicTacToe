#include "Tictactoe.h"

void print_grid(unsigned char line1[], unsigned char line2[], unsigned char line3[]){
  printf("-------------------\r\n");
  printf("|  %c  |  %c  |  %c  |\r\n", line1[0], line1[1], line1[2]);
  printf("-------------------\r\n");
  printf("|  %c  |  %c  |  %c  |\r\n", line2[0], line2[1], line2[2]);
  printf("-------------------\r\n");
  printf("|  %c  |  %c  |  %c  |\r\n", line3[0], line3[1], line3[2]);
  printf("-------------------\r\n");
}

unsigned char line1 [3] = {' ', ' ', ' '};
unsigned char line2 [3] = {' ', ' ', ' '};
unsigned char line3 [3] = {' ', ' ', ' '};



int main(int argc, char *argv[])
{
    print_grid(&line1, &line2, &line3);
    return 0;
}
