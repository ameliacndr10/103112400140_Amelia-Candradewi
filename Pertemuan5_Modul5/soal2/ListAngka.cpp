#include "ListAngka.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList L) {
    if(L.First == NULL){
        return true; 
    } else {
        return false;
    }
}

void CreateList(linkedList &L){
    L.First = NULL;
}
address alokasi(dataAngka x){
    address nodeBaru = new node;
    nodeBaru->Angka = x;
    nodeBaru->next =NULL;
    return nodeBaru;
}
void dealokasi(address &node){
    node->next= NULL;
    delete node;
}

void printList(linkedList L){
    if(L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        while (nodeBantu != NULL){
            cout << nodeBantu->Angka << "-";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}
void insertFirst(linkedList &L, address nodeBaru){
    nodeBaru->next = L.First;
    L.First = nodeBaru;
}
void insertLast(linkedList &L, address nodeBaru){
    if (isEmpty(L)) {
        L.First = nodeBaru;
    } else {
        address nodeBantu = L.First;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}
void insertAfter(linkedList &L, address nodeBaru, address nodePrev){
    if (nodePrev != NULL) {
        nodeBaru->next = nodePrev->next;
        nodePrev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}
void delAfter(linkedList &L, address nodeHapus, address nodePrev){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != NULL && nodePrev->next != NULL) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = NULL;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->Angka << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void updateFirst(linkedList &L){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        cin >> L.First->Angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList &L){
    if (isEmpty(L) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : "<< " : " << endl;
        cout << "Nama Angka: ";
        cin >> nodeBantu->Angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList &L, address nodePrev){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != NULL && nodePrev->next != NULL){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node : " << nodePrev->Angka << endl;
            cout << "Nama Angka : ";
            cin >> nodePrev->next->Angka;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
    }
}

void SearchByData(linkedList L, int data){
        if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != NULL){
            posisi++;
            if(nodeBantu->Angka == data){
                found = true;
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void SearchByAddress(linkedList L, address node){
    if(isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != NULL) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}
void SearchByRange(linkedList L, int nilaiMin){
    if(isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas nilai" << nilaiMin << "---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != NULL) {
            posisi++;
            int A = nodeBantu->Angka;
            if( A >= nilaiMin ) {
                cout << "Data ditemukan pada posisi ke- " << posisi << ",nilai :" << nodeBantu->Angka << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data angka dalam range nilai tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

void penjumlahan(linkedList L){
    if( L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        int P = 0;
        while (nodeBantu != NULL){
            P += nodeBantu->Angka;
            nodeBantu = nodeBantu->next;
        }
        cout << "Total penjumlahan : " << P << endl;
        cout << endl;
    }
}
void pengurangan(linkedList L){
    if(L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        int P = L.First->Angka;
        while (nodeBantu != NULL){
            P -= nodeBantu->Angka;
            nodeBantu = nodeBantu->next;
        }
        cout << "Total pengurangan :" << P << endl;
        cout << endl;
    }
}

void perkalian(linkedList L){
    if (L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        int P = 1;
        while (nodeBantu != NULL)
        {
            P*= nodeBantu->Angka;
            nodeBantu = nodeBantu->next;
        }
        cout << "Total perkalian :" << P << endl;
        cout << endl;
    }
}


// int nbList(linkedList L){
//     int count = 0;
//     address nodeBantu = L.First;
//     while (nodeBantu != NULL) {
//         count++;
//         nodeBantu = nodeBantu->next; 
//     }
//     return count;
// }