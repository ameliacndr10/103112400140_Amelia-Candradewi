#include <iostream>
using namespace std;

int cariMinimum(int arr[], int ukuran) {
    int MIN = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if (arr[i] < MIN){
            MIN = arr[i];
        }
    }
    return MIN;
}
int cariMaksimum(int arr[], int ukuran) {
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void hitungRataRata(int arr[], int ukuran){
    int totalJumlah = 0;
    for( int i =0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "Rata-rata : " << totalJumlah/ukuran << endl;
}

int main() {
    int ukuran = 10;
    int arrA[ukuran] = {11,8,5,7,12,26,3,54,33,55};

    cout << "--Menu Program Array--" << endl;
    cout << "1. Tampilkan isi array" << endl;
    cout << "2. Cari nilai maksimum" << endl;
    cout << "3. Cari nilai minimum" << endl;
    cout << "4. Hitung nilai rata-rata" << endl;
    
    cout << "Masukkan inputan user: ";
    int input;
    cin >> input;

    switch (input)
    {
    case 1:
        for(int i=0; i<10 ;i++){
            cout << arrA[i] <<" ";
        }
        break;
    case 2:
        cout << cariMaksimum(arrA,ukuran);
        break;
    case 3: 
        cout << cariMinimum(arrA, ukuran);
        break;
    case 4:
        hitungRataRata(arrA, ukuran);
        break;
    default:
        cout << "inputan salah";
        break;
    }
}