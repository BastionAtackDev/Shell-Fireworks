#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>

#define ASTEPTARE 1

int main (int argc, char *argv[]) {
  int lines, cols, posX, i, miscare;
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  srand(time(NULL));
  
  lines = w.ws_row;
  cols = w.ws_col;
  system("clear");
  posX = rand() % cols;
  for (i = 0; i < lines - 1; i++) {
    printf("\n");
  }
  for (i = 0; i < posX - 10; i++) {
    printf(" ");
  }
  printf("/\n");
  sleep(ASTEPTARE);
  for (lines = lines - 1; lines - 10 > 0; lines--) {
    system("clear");
    miscare = rand() % 3;
    posX = (posX - 1) + miscare;
    for (i = 0; i < lines - 1; i++) {
      printf("\n");
    }
    for (i = 0; i < posX - 10; i++) {
      printf(" ");
    }
    if (miscare == 0) {
      printf("\\\n");
    }else if (miscare == 1) {
      printf("|\n");
    }else {
      printf("/\n");
    }
    sleep(ASTEPTARE);
  }
  return 0;
}
