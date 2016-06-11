#include <stdio.h>
#include <string.h>

void copyString(char *str) {
   char buffer[16];

   strcpy(buffer, str);
}

int main() {
  char large_string[256];
  int i;

  for( i = 0; i < 255; i++){
    large_string[i] = 'A';
  }

  copyString(large_string);
  
  return 0;
}
