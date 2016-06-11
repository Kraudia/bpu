#include <stdio.h>

int main()
{
   char data[80];
   char buf[80];
   scanf("%s", buf);
   sprintf(data, "podano: %s", buf);
   puts(data);

   return(0);
}
