#include <iostream>
#include "array.h"
using namespace std;
void tampilkanHasil(int arr[UKURAN][UKURAN]){
    for (int i = 0; i < 3; i++){
        for(int j = 0; j<3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    };
}

void tukarArr(int arrA[UKURAN][UKURAN], int arrB[UKURAN][UKURAN]) {
    for(int i = 0; i < 3; i++) {                    
        for(int j = 0; j < 3; j++){
            int temp;
            temp = arrA[i][j];
            arrA[i][j] = arrB[i][j];
            arrB[i][j] = temp;
        }
    }
}

void tukarPtr(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}