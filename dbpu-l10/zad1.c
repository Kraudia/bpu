#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h> 

int main() {
	int randomData = open("/dev/urandom", O_RDONLY);
	char myRandomData[1];
	size_t randomDataLen = 0;
	time_t start, stop;
	time(&start);
	while (difftime(stop,start) < 60)
	{
		read(randomData, myRandomData, 1);
		time(&stop);
		randomDataLen += 1;
	}
	fprintf(stderr, "Odczytano łącznie %zu \n", randomDataLen);
	close(randomData);
	return 0;
}
