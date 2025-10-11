#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main(){
    mahasiswa mhs[MAX];
    
    int i = 0;
    string input;
    while (i < MAX)
    {
        inputMhs (mhs[i]);
        mhs[i].nilaiAkhir = nilaiAkhir(mhs[i]);
        cout << "nilai akhir = " << mhs[i].nilaiAkhir << endl;
        i++;
        cout << "Input Iya/Tidak : ";
        cin >> input;
        if (input == "tidak"){
            break;
        }
    } 
    
    return 0;
}