#include <stdio.h>

int main() {

  FILE *file;

  file = fopen("../../examples/main.kit", "r");

  if (file == NULL) {
    printf("Unable to open file. \n");
    return 1; // return 1 error code.
  }

  char buffer[100];
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    printf("%s", buffer);
  }

  fclose(file);

  return 0;
}
