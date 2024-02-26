#include <stdio.h>
#include <stdlib.h>

#define N_MAX_BOARD_ROW_SIZE 15
int board[N_MAX_BOARD_ROW_SIZE] = { 0 };
const char bullet_code = 'x';
enum PrintingStepType {
  Searching,
  Placed,
  RollingBack,
  FoundSolution
};
int step_count = 0;
int problem_size = 0;
int wait_for_enter = 1;
int queen(int row, const int n);
int place(int row, int column);
void printMenu();
void printTable(int n);
void clear_screen();
int main(int argc, char *argv[]) {
  if (argc > 1) {
    wait_for_enter = *argv[1] == '0' ? 0 : 1;
  }
  
  do {
    clear_screen();
    printMenu();
    scanf("%d", &problem_size);
  } while (problem_size < 4 || problem_size > 13); 
  if (queen(1, problem_size) == 1) {
    printTable(problem_size);
  }
  
  printf("\n");
  system("pause");
  return 0;
}

void printMenu() {
  printf("\t- N Queens Problem Using Backtracking -");
  printf("\n\nEnter number of Queens[Must be between 4 and 13]:");
}
void printTable(int n) {
  int i, j;
  printf("\n\nSolution:\n\n");
  printf(" ");
  for (i = 1; i <= n; ++i)
    printf("  %d", i);
  
  for (i = 1; i <= n; ++i) {
    printf("\n\n%d", i);
    for (j = 1; j <= n; ++j) 
    {
      if (board[j] == i)
        printf("  Q"); 
      else
        printf("  %c", bullet_code); 
    }
  }
  printf("\n");
}

void printStep(int row, int step_type) {
  int i, j;
  if (wait_for_enter == 0) return;
  
  clear_screen();
  printf("\n\nStep [%d] [Column %d]: ", ++step_count, row);
  
  switch (step_type) {
    case Searching:
      printf("[Searching a valid place to queen]");
      break;
    case RollingBack:
      printf("[No solution are found for this layout! Rolling back]");
      break;
    case Placed:
      printf("[Queen is placed]");
      break;
    case FoundSolution:
      printf(" Problem is solved! All queens are in right place");
      return;
      break;
    default:
      printf(" Upps!!!...");
      break;
  }
  printf("\n\n");
  
  printf(" ");
  for (i = 1; i <= problem_size; ++i)
    printf("  %d", i);
  
  for (i = 1; i <= problem_size; ++i) {
    printf("\n\n%d", i);
    for (j = 1; j <= problem_size; ++j) //for nxn board
    {
      if (board[j] == i)
        printf("  Q"); //queen at i,j position
      else
        printf("  %c", bullet_code); //empty slot
    }
  }
  printf("\n\nPress enter to continue..");
  getchar();
}
int place(int row, int column) {
  int i;
  for (i = 1; i <= row - 1; ++i) {
    if (board[i] == column) 
      return 0;
    else
      if (abs(board[i] - column) == abs(i - row))
        return 0;
  }
  return 1; 
}
int queen(int row, const int n) {
  int column;
  if (row > n) {
    return 1;
  }
  
  printStep(row, Searching);
  for (column = 1; column <= n; ++column) {
    if (place(row, column)) {
      board[row] = column;
      printStep(row, Placed);
      if (queen(row + 1, n) == 1) {
        printStep(row, FoundSolution);
        return 1;
      }
      printStep(row, RollingBack);
      board[row] = 0; 
    }
  }
  return 0;
}

void clear_screen() {
#ifdef WIN32
  system("cls");
#else
  system("clear");
#endif
}
