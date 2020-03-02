#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 20

int main(int argc, char * argv[]) {
  FILE *file;

  int sleep_time = atoi(getenv("SLOWCAT_SLEEP_TIME"));
  
  if (sleep_time == 0) {
    sleep_time = 1;
  }
  
  if (argc != 2) {
    fprintf(stderr, "Incorrect number of arguments\n");
    exit(-1);
  }
  else if (strncmp(argv[1], "-", 1) == 0) { // == "-") {
    file = stdin;
  }
  else {
    file = fopen(argv[1], "r");
    if (file == NULL) {
      fprintf(stderr, "Invalid file name\n");
      exit(-1);
    }
  }

  fprintf(stderr, "%d\n", getpid());
  
  char line[MAX];
  while (fgets(line, MAX, file)) {
    fprintf(stdout, "%s", line);
    sleep(sleep_time);
  }
    

}
