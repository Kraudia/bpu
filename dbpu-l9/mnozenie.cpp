#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int size = 2000;
int macierzA[size][size];
int macierzB[size][size];
int macierzC[size][size];

void MatrixMul() {
    int i, j, k;
    for(i=0; i<size; i++)
    	for(j=0; j<size; j++)
    		for(k=0; k<size; k++)
    			macierzC[i][j] += macierzA[i][k] * macierzB[k][j];                          
}

void PrintMatrix() {

	for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cout<<macierzA[i][j]<<" ";
        }
        cout<<"\n";           
    }

	cout <<"*\n";

	for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cout<<macierzB[i][j]<<" ";
        }
        cout<<"\n";           
    }

	cout <<"=\n";

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cout<<macierzC[i][j]<<" ";
        }
        cout<<"\n";           
    }
}

int main() {
	time_t start, koniec;
	time( & start);
	srand(time(0));
	int a,b;

	for(int i=0; i<size; i++)                                       
    	for(int j=0; j<size; j++) {                                      
			a = ( std::rand() % 50) + 1;
			b = ( std::rand() % 50) + 1;
    		macierzA[i][j]=a;
			macierzB[i][j]=b;
			macierzC[i][j]=0;  
		}

    MatrixMul();
    //PrintMatrix();
	time( & koniec);
	cout << "\nCzas wykonywania: " << (koniec - start) << " sekund\n";
    return 0;
}
 
