#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
	char * pointer = (char *) malloc(1000);
	free(pointer);
	free(pointer);

	char * pointer2 = (char *) malloc(1000);
  	return 0;
}


