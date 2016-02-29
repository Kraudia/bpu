#include <stdio.h>

/*
	Alternatywa dla strstr() z cstring
	
	Funkcja przyjmuje jako argumenty wskaźniki do:
		- aktualnej linii
		- wyszukiwanego słowa
		
	Działanie:
	1. Jeżeli wskaźnik nie istnieje to jest zwracana cała linia.
	2. Tworzony są pomocniczne wskaźniki na:
		- linię (first) -> posłuży do iterowania po kolejnych pozycjach w linii
		- szukaną frazę (second) -> posłuży do iterowania 
			po kolejnych pozycjach w szukanym słowie
		- linię (firstChar) -> posłuży do sprawdzenia, czy dotarliśmy do końca linii
	3. Dopóki możemy iterować po szukanym słowie
		
		
*/
char* StrStr(char *line, const char *phraseToFind) {
  if (!*phraseToFind) {
		return line;
  }
  char *first = (char*)line, *second = (char*)phraseToFind;
  char *firstChar = (char*)line;
  while (*++second) {
    firstChar++;
  }

  while (*firstChar) {
    char *firstBegin = first;
    second = (char*)phraseToFind;
    while (*first && *second && *first == *second) {
      first++;
      second++;
    }
    printf("%p %p %p\n", firstBegin, first, second);
    if (!*second)
      return firstBegin;
    first = firstBegin + 1;
    firstChar++;
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
  	if(StrStr(line, argv[2])) {
			printf("%d -> %s\n", nl, line);
    }
    nl++;
  }

	if(fp) {
  	fclose(fp);
	}
  return(0);
}
