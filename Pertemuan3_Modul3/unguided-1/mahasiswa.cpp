#include <iostream>
#include "mahasiswa.h"

using namespace std;
void inputMhs(mahasiswa &m){
    cout << "masukkan nama = ";
    cin >> (m).nama;
    cout << "nim = ";
    cin >> (m).nim;
    cout << "uts = ";
    cin >> (m).uts;
    cout << "uas = ";
    cin >> (m).uas;
    cout << "tugas = ";
    cin >> (m).tugas;
}
float nilaiAkhir(mahasiswa m){
    return (0.3*m.uts + 0.4*m.uas + 0.3*m.tugas);
}