#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int maxx = 8;//definiujemy maksimum jako staĹÄ
int main(){
	int lab[8][8];
	for(int i=0;i<8;i++) {//wczytywanie labiryntu z pliku
		for(int j=0;j<8;j++) {
			cin >> lab[i][j];
			cout << lab[i][j] << " ";
		}
		cout << endl;
	}
    int x=0,y=0; //pozycja gracza
	int last[40][2];

	for(int k=0;k<40;k++) {//przechodzenie przez labirynt
		cout << "Jestem tu: x=" << x << "y=" << y << endl;
		if ((x == 3) && (y == 7)) {
			cout << "Wyszedles z labiryntu. KONIEC GRY" << endl;	
			for(int i=0;i<8;i++) {//wczytywanie labiryntu z pliku --> cat labirynt(nazwa pliku)| ./a.out
				for(int j=0;j<8;j++) {
					cout << lab[i][j] << " ";
					if (lab[i][j]==8)
					lab[i][j]=0;
				}
				cout << endl;
			}
			exit (0);
		}
		last[k][0] = x;
		last[k][1] = y;
		if ((x < maxx)&&(lab[x+1][y]==0)){
			x++;
		} else if ((y < maxx)&&(lab[x][y+1]==0)){
			y++;
		} else if ((x > 0)&&(lab[x-1][y]==0)){
			x--;
		} else if ((y > 0)&&(lab[x][y-1]==0)){
			y--;
		} else { 
			if ((x < maxx)&&(lab[x+1][y]==4) && (last[k-1][0] != x+1 || last[k-1][1] != y)){
				x++;
			} else if ((y < maxx)&&(lab[x][y+1]==4) && (last[k-1][0] != x || last[k-1][1] != y+1)){
				y++;
			} else if ((x > 0)&&(lab[x-1][y]==4) && (last[k-1][0] != x-1 || last[k-1][1] != y)){
				x--;
			} else if ((y > 0)&&(lab[x][y-1]==4) && (last[k-1][0] != x || last[k-1][1] != y-1)){
				y--;
			} else {
				int cellValue = 4;
				while(true) {
					if ((x < maxx)&&(lab[x+1][y]==cellValue)){
						x++;
						break;
					} else if ((y < maxx)&&(lab[x][y+1]==cellValue)){
						y++;
						break;
					} else if ((x > 0)&&(lab[x-1][y]==cellValue)){
						x--;
						break;
					} else if ((y > 0)&&(lab[x][y-1]==cellValue)){
						y--;
						break;
					}
					cellValue++;
				}	 
			}	
		}
		for(int i=0;i<8;i++) {//wczytywanie labiryntu z pliku
			for(int j=0;j<8;j++) {
				cout << lab[i][j] << " ";
				if (lab[i][j]==8)
					lab[i][j]=0;
			}
			cout << endl;
		}
		if (lab[x][y] == 0) {
			lab[x][y] = 4;
		} else {
			lab[x][y] = lab[x][y] + 1;
		}
	}
}
