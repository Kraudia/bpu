#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//Funkcja sprawdzająca czy dana linia zawiera dany text
bool search(string line, string text) {
	bool contain = false;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == text[0]) {
			int j = 1;
			for (j; j < text.length(); j++) {
				if (line[i+j] != text[j]) {
					j--;
					break;	
				}					
			}
			if (j == text.length()) {
				contain = true;
				break;
			}
		}
	}
	return contain;
}

int main (int argc, char * argv[]) {
  string line;
  ifstream myfile (argv[1]);
  string text = argv[2];
  if (myfile.is_open()) {
  	while ( getline (myfile,line) ) {
		if (search(line, text)) {
			cout << line << '\n';
		}		
	}
	myfile.close();
  }
  else cout << "Unable to open file"; 
  return 0;
}


