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
  unsigned char remain_place = 1;
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
  else if ((grid->line1[0] == grid->line2[1]) && (grid->line1[0] == grid->line3[3])){
    *winner = grid->line1[0];
  }
  else if ((grid->line1[3] == grid->line2[1]) && (grid->line1[3] == grid->line3[0])){
    *winner = grid->line1[3];
  }

  //Remain empty box ?
  for(i=0; i<9; i++){
    if (grid->line1[i] == (i+1)){
      remain_place = 1;
      break;
    }
  }

  if (*winner != '?'){
    return 1;
  }
  else if (remain_place == 0){
    return 1;
  }
  else{
    return 0;
  }
}

unsigned char get_box(unsigned char player){
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
  }else{
    box = (unsigned char) temp;
    return temp;
  }
}

Grid_struct grid;
char player1 = 'X';
char player2 = 'O';
char winner = '?';
unsigned char temp;

int main(int argc, char *argv[])
{

    init(&grid);
    while(Settings(&player1, &player2) == 0){
      // Repeat
    }

    print_grid(&grid);

    while (1){

      sleep(1);
      if(player1 != '@'){
        do{
          temp = get_box(1);
        } while (temp == 0);
      }
      play_as(&player1, temp, &grid, &player1, &player2);
      print_grid(&grid);
      if(check_win(&grid, &player1, &player2, &winner) == 1){
        break;
      }

      sleep(1);
      if(player2 != '@'){
        do{
          temp = get_box(2);
        } while (temp == 0);
      }
      play_as(&player2, temp, &grid, &player1, &player2);
      print_grid(&grid);
      if(check_win(&grid, &player1, &player2, &winner) == 1){
        break;
      }

    }

    if (winner == '?'){
      printf("---------------GAME---------------\n");
      printf("---------------DRAW---------------\n");
    }
    else if (winner == player1){
      printf("--------------WINNER---------------\n");
      printf("--------------PLAYER1--------------\n");
    }
    else if (winner == player2){
      printf("--------------WINNER---------------\n");
      printf("--------------PLAYER2--------------\n");
    }
    return 0;
}
