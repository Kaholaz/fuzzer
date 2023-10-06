#include <stdio.h>
#include <stdlib.h>

#include "replace.h"

int main() {
  const char *input = "This is a <sample> & string.";
  char *replaced = replace(input);
  printf("Original: %s", input);
  printf("Replaced: %s", replaced);
  free(replaced);

  return 0;
}

