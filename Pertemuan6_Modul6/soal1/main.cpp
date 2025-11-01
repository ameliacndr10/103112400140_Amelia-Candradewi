#include "doublylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);
    
    int input;
    cout << "masukkan jumlah input-an   :";
    cin >> input;
    string nomor; 
    string warna;
    int tahun;
    for(int i =0 ; i < input; i++){
        cout << "masukkan nomor polisi      :";
        cin >> nomor;
        cout << "masukkan warna kendaraan   :";
        cin >> warna;
        cout << "masukkan tahun kendaraan   :";
        cin >> tahun;

        infotype A;
        A = {nomor, warna, tahun};
        if(cariNopol(L,A) == NULL){
            insertLast(L,alokasi(A));
        }else {
            cout << "nomor polisi sudah terdaftar" << endl;
        }
        cout << endl;
    }
    printInfo(L);

    cout << endl;
    cout << "Masukkan nomor polisi yang dicari  :";
    cin >> nomor;


    infotype cari;
    cari.nopol = nomor;
    address P = cariNopol(L,cari);
    if(P != NULL){
        cout << "Nomor polisi   : " << P->info.nopol<< endl;
        cout << "Warna          : " << P->info.warna<<endl;
        cout << "Tahun          : " << P->info.thnBuat<<endl;
    }else{
        cout << "Data tidak ditemukan";
    }

    cout << "Masukkan nomor polisi yang dihapus :";
    cin >> nomor;
    infotype hapus;
    hapus.nopol = nomor;
    deleteByNopol(L,hapus);
    printInfo(L);
    
    return 0;
}

