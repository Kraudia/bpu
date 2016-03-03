#include <stdio.h>

/*
	Alternatywa dla strstr() z cstring
	
	Funkcja przyjmuje jako argumenty wskaźniki do:
		- aktualnej linii
		- wyszukiwanego słowa
		
	Działanie:
	Począwszy od pierwszych znaków obu ciągów, porównywane są zawartości dwóch kolejnych wskaźników. Jeżeli szukany łacuch się skończy, to po prostu wracamy do punktu startu łańcucha, który przeszukujemy. Jeśli w danym momencie znaki, na które wskazywały wskaźniki, nie są równe, przechodzimy do nowej pozycji startowej łańcucha, który przeszukujemy.
		
		
*/
char *strStr(char *line, char *toFind) {
    if(*toFind=='\0'){
        return line;
    }
    if(*line=='\0'){
        return NULL;
    }
    
    char *start=line;
    char *bStart;
    
    while(*start!='\0'){
        bStart=start;
        char *bFind=toFind;
        while(*bStart!='\0' && *bFind!='\0' && *bStart==*bFind){
            bStart++;
            bFind++;
        }
        if(*bFind=='\0'){
            return start;
        }
        start++;
    }
    return NULL;
}

main(int argc, char *argv[]) {
   FILE *fp;
   int nl = 1;
   char line[512];

   if((fp = fopen(argv[1], "r")) == NULL) {
     printf("Plik nie istnieje lub wystąpił problem z jego odczytem.");
     return(-1);
   }

   while(fgets(line, sizeof(line), fp) != NULL) {
	 if(strStr(line, argv[2])) {
		printf("%d -> %s\n", nl, line);
     }
     nl++;
   }

   if(fp) {
  	 fclose(fp);
   }

   return(0);
}
