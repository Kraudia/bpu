#include <stdio.h>
#include <cstring>

bool StrStr(char* line, int lineSize, char* text, int textSize) {
  //printf("\n%c %d %s\n", line[0], lineSize, text);
	bool contain = false;
	for (int i = 0; i < lineSize; i++) {
    printf("%c\n", line[i]);
		if (line[i] == text[0]) {
			int j = 1;
			for (j; j < textSize; j++) {
				if (line[i+j] != text[j]) {
					j--;
					break;
				}
			}
			if (j == textSize) {
				contain = true;
				break;
			}
		}
	}
	return contain;
}
main(int argc, char *argv[]) {
   FILE *fp;
   int lineNum = 1;
	 int findResult = 0;
	 char temp[512];

   if((fp = fopen(argv[1], "r")) == NULL) {
      printf("dsfsdf");
     	return(-1);
   }

   while(fgets(temp, 512, fp) != NULL) {
  		if(StrStr(temp, sizeof(temp), argv[2], sizeof(argv[2]))) {
			     printf("Znaleziono w linii: %d\n", lineNum);
           findResult++;
    }
    lineNum++;
  }
  if(findResult == 0) {
  		printf("\nBrak wyników\n");
	}

	if(fp) {
  	fclose(fp);
	}
  return(0);
}
