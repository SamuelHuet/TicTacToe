
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct{
  unsigned char line1 [3];
  unsigned char line2 [3];
  unsigned char line3 [3];
} Grid_struct;

void init(Grid_struct *grid);
void print_grid(Grid_struct *grid);
