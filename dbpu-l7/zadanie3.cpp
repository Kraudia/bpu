#include <cstdlib>
#include <iostream>
#include <ctime>
#include <sys/mman.h>

using namespace std;

int main() {
	char preKey[16];
	mlock(preKey, 16);
	
	for(int i=0; i<16; i++) {
		preKey[i] = (rand() * time(0)) % 100;
		cout << (int) preKey[i] << '\n';
	}

	for(int i=0; i<16; i++) {
		preKey[i] = 0;
	}

	munlock(preKey, 16);

	return 0;
}
