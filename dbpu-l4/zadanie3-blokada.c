#include <stdio.h>
#include <pthread.h>  
                         
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER; 
long number = 0;
void* child_fn ( void* arg ) {           
	for(int i = 0; i < 2000000; i++){
		pthread_mutex_lock(&mut); 
		number++;
		pthread_mutex_unlock(&mut); 
	}             
	return NULL;
}

int main ( void ) {    
	pthread_t child[5];           
	for(int j = 0; j < 5; j++){
		pthread_create(&child[j], NULL, child_fn, NULL);           
	}  
	for(int j = 0; j < 5; j++){ 
		pthread_join(child[j], NULL);
	} 
	printf("%li\n", number);
	return 0;
}
