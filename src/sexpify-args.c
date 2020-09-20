#include <stdio.h>
#define false 0
#define true 1

int main(int argc, char ** args) {
  int isEscaped = false;
  if (argc == 1) {
    printf("nil\n");
    return 0;
  }
  putchar('(');
  for (int i = 1; i < argc; i++) {
    char * ptr = args[i];
    if (i > 1) {
      putchar(' ');
    }
    putchar('"');
    while (*ptr != 0) {
      char letter = *ptr;
      if (letter == '\\') {
        isEscaped = !isEscaped;
      } else {
        if (letter == '"' && !isEscaped) {
          putchar('\\');
        }  
        isEscaped = false;
      }
      putchar(letter);
      ptr++;
    }
    putchar('"');
  }
  putchar(')');
  putchar('\n');
  return 0;
}
