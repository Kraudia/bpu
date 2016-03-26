#include <stdio.h>
       
long number = 0;
int main ( void ) {
	for(int i = 0; i < 10000000; i++){
		number++;
	}    
	printf("%li\n", number);
	return 0;
}
