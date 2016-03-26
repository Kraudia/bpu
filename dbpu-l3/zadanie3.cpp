#include <stdio.h>
using namespace std;

void multiply(int A[10000][10000], int B[10000][10000]) {
  int i, j, k;
  int C[10000][10000];
  for(i = 0; i < 10000; i++)
    for(j = 0; j < 10000; j++)
      C[i][j] = 0;
  for(i = 0; i < 10000; i++)
    for(j = 0; j < 10000; j++)
      for(k = 0; k < 10000; k++)
        C[i][j] += A[j][k] * B[k][i];
}


int main (int argc, char * argv[]) {
	int matrix1[10000][10000], matrix2[10000][10000];

	for(int i=0; i<10000; i++){
		for(int j=0; j<10000; j++){
			matrix1[i][j] =  i + j;
			matrix2[i][j] =  i + j + 20;
		}
	}

	multiply(matrix1, matrix2);

  	return 0;
}


