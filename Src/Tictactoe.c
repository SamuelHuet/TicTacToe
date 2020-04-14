
#include "Tictactoe.h"

void init(Grid_struct *grid){
  srand(time(NULL));
  strcpy( grid->line1, "123");
  strcpy( grid->line2, "456");
  strcpy( grid->line3, "789");
}

void print_grid(Grid_struct *grid){
  printf("\r\n\r\n-------------------\r\n");
  printf("|  %c  |  %c  |  %c  |\r\n", grid->line1[0], grid->line1[1], grid->line1[2]);
  printf("-------------------\r\n");
  printf("|  %c  |  %c  |  %c  |\r\n", grid->line2[0], grid->line2[1], grid->line2[2]);
  printf("-------------------\r\n");
  printf("|  %c  |  %c  |  %c  |\r\n", grid->line3[0], grid->line3[1], grid->line3[2]);
  printf("-------------------\r\n\r\n");
}

unsigned char play_as(unsigned char *xo, unsigned char number, Grid_struct *grid, char* player1, char* player2){
  unsigned char random;
    if (*xo == '@'){
      //play as AI
      do{
        random = rand()%(10-1)+1;
      } while((grid->line1[random] == *player1) || (grid->line1[random] == *player2));
      number = random;

    }
    if ((grid->line1[number-1] == *player1) || (grid->line1[number-1] == *player2)){
      printf("EchENC\n");
      return 0;
    }
    grid->line1[number-1] = *xo;
    return 1;
}

unsigned char Settings(char *player1, char *player2){
  char temp;
  printf("Select the player1 symbol then press [ENTER],\r\ntype '@' to let play an AI\r\n");
  fflush(stdin);
  scanf("\n%c", &temp);
  *player1 = temp;

  printf("Select the player2 symbol then press [ENTER],\r\ntype '@' to let play an AI\r\n");
  fflush(stdin);
  scanf("\n%c", &temp);
  *player2 = temp;

  if (*player1 == *player2){
    printf("\r\n\r\n/!\\ You can't use the same symbol for both players !\r\n\r\n");
    return 0;
  }
  else if ((*player1 == '?') || (*player2 == '?')){
    printf("\r\n\r\n/!\\ '?' is a special caracter, please do not use it !\r\n\r\n");
    return 0;
  }
  else {
    return 1;
  }
}

unsigned char check_win(Grid_struct* grid, char* player1, char* player2, char* winner){
  unsigned char i;
  //char winner = "";
  unsigned char remain_place = 0;
  //check lines
  if ((grid->line1[0] == grid->line1[1]) &&  (grid->line1[0] == grid->line1[2])){
    *winner = grid->line1[0];
  }
  else if ((grid->line2[0] == grid->line2[1]) &&  (grid->line2[0] == grid->line2[2])){
    *winner = grid->line2[0];
  }
  else if ((grid->line3[0] == grid->line3[1]) &&  (grid->line3[0] == grid->line3[2])){
    *winner = grid->line3[0];
  }

  //check columns
  else if ((grid->line1[0] == grid->line2[0]) && (grid->line1[0] == grid->line3[0])){
    *winner = grid->line1[0];
  }
  else if ((grid->line1[1] == grid->line2[1]) && (grid->line1[1] == grid->line3[1])){
    *winner = grid->line1[1];
  }
  else if ((grid->line1[2] == grid->line2[2]) && (grid->line1[2] == grid->line3[2])){
    *winner = grid->line1[2];
  }

  //check diagonal
  // printf("grid->line1[0] = %d", grid->line1[0]);
  // printf("grid->line2[1] = %d", grid->line1[0]);
  // printf("grid->line1[0] = %d", grid->line1[0]);
  else if ((grid->line1[0] == grid->line2[1]) && (grid->line1[0] == grid->line3[2])){
    *winner = grid->line1[0];
  }
  else if ((grid->line1[2] == grid->line2[1]) && (grid->line1[2] == grid->line3[0])){
    *winner = grid->line1[2];
  }

  //Remain empty box ?
  for(i=0; i<9; i++){
    // printf("%d =?= %d\r\n", grid->line1[1], (i+1));
    // printf("%d =?= %d\r\n", grid->line1[i], (i+49));
    if (grid->line1[i] == (i+49)){
      // printf("Encore de la place\n");
      remain_place = 1;
      break;
    }
  }

  if (*winner != '?'){
    printf("*winner != '?'\n");
    return 1;
  }
  else if (remain_place == 0){
    return 1;
  }
  else{
    return 0;
  }
}

unsigned char get_box(unsigned char player, Grid_struct *grid, char* player1, char* player2){
  int temp;
  unsigned char box;
  if (player == 1){
    printf("[PLAYER1] ");
  }else{
    printf("[PLAYER2] ");
  }
  printf("Select the number's box you want to play then press [ENTER]\r\n");
  fflush(stdin);
  scanf("\n%d", &temp);
  if ((temp <1) || (temp >9)){
    printf("\r\n\r\n/!\\ You can't write outside the grid !\r\n\r\n");
    return 0;
  }
  else if ((grid->line1[temp-1] == *player1) || (grid->line1[temp-1] == *player2)){
    printf("\r\n\r\n/!\\ This box is already played !\r\n\r\n");
    return 0;
  }
  else{
    box = (unsigned char) temp;
    return temp;
  }
}
