#include <iostream>
#include "array.h"

using namespace std;

int main() {
        int arrA[UKURAN][UKURAN]= {
        {1,2,5},
        {6,3,6},
        {7,9,3}

    };
    int arrB[UKURAN][UKURAN]= {
        {7,5,4},
        {9,7,2},
        {9,7,6}
    };
    cout << "Array sebelum ditukar:"<< endl;
    cout << "Array A :"<< endl;
    tampilkanHasil(arrA);
    cout << "Array B :"<< endl;
    tampilkanHasil(arrB);

    tukarArr(arrA,arrB);

    cout << "Array setelah ditukar:"<< endl;
    cout << "Array A :"<< endl;
    tampilkanHasil(arrA);
    cout << "Array B :"<< endl;
    tampilkanHasil(arrB);

    int a = 20, b = 30;
    
    cout << "Variabel A sebelum ditukar:"<< a << endl;
    cout << "Variabel B sebelum ditukar:"<< b << endl;
    tukarPtr(&a,&b);

    cout << "Variabel A setelah ditukar:"<< a << endl;
    cout << "Variabel B setelah ditukar:"<< b << endl;
}