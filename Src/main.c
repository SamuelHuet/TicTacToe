#include "Tictactoe.h"

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



    while (1){

      sleep(1);
      print_grid(&grid);
      if(player1 != '@'){
        do{
          temp = get_box(1, &grid, &player1, &player2);
        } while (temp == 0);
      }
      play_as(&player1, temp, &grid, &player1, &player2);
      //print_grid(&grid);
      if(check_win(&grid, &player1, &player2, &winner) == 1){
        break;
      }

      sleep(1);
      print_grid(&grid);
      if(player2 != '@'){
        do{
          temp = get_box(2, &grid, &player1, &player2);
        } while (temp == 0);
      }
      play_as(&player2, temp, &grid, &player1, &player2);
      //print_grid(&grid);
      if(check_win(&grid, &player1, &player2, &winner) == 1){
        break;
      }

    }
    print_grid(&grid);
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
