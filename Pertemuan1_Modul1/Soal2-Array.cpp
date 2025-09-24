#include <iostream>
using namespace std;

int main() {
    int i;
    string arr[] = {"nol", "satu", "dua", "tiga", "empat","lima","enam","tujuh","delapan","sembilan"};
    cout << "Masukkan angka:";
    cin >> i;

    if (i < 0 || i>99 ) {
        cout << "Masukkan angka harus 0-99";
    }else if (i<9) {
        cout << arr[i];
    }else if (i==10) {
        cout << "sepuluh";
    }else if (i==11) {
        cout << "sebelas";
    }else if (i<20){
        cout << arr[i%10] << " belas";
    }else {
        int sisa = i%10;
        cout << arr[i/10] << " puluh ";
        if (sisa !=0) {
            cout << arr[sisa];
        }
    }
}