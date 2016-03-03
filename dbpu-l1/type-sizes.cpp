#include <iostream>

using namespace std;

int main(){
    cout << "char size:"  << sizeof(char) << " bytes" << endl;
    cout << "short size:"  << sizeof(short) << " bytes" << endl;
    cout << "int size:" << sizeof(int) << " bytes" << endl;
    cout << "long size:"  << sizeof(long) << " bytes" << endl;
    cout << "long long size:" << sizeof(long long) << " bytes" << endl;
    cout << "float size:"  << sizeof(float) << " bytes" << endl;
    cout << "double size:"  << sizeof(double) << " bytes" << endl;
    cout << "long double size:"  << sizeof(long double) << " bytes" << endl;
    cout << "wchar_t size:"  << sizeof(wchar_t) << " bytes" << endl;
    
    return 0;
}