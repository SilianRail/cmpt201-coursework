#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // ----getline()----
  printf("Please enter some text: ");

  char *line = NULL;
  size_t linecap = 0;

  ssize_t linelen = getline(&line, &linecap, stdin);
  if (linelen == -1) {
    perror("getline failed");
    exit(EXIT_FAILURE);
  }

  // ----strtok_r()----
  printf("Tokens:\n");
  char *sep = " ";
  char *word, *brkt;

  for (word = strtok_r(line, sep, &brkt); word;
       word = strtok_r(NULL, sep, &brkt)) {
    printf("\t%s\n", word);
  }

  free(line);

  return 0;
}
