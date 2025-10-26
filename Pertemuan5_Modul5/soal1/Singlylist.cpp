#include "Singlylist.h"
#include <iostream>
using namespace std;

bool isEmpty(List L){
    if(L.First == NULL){
        return true;
    }else{
        return false;
    }
}
void CreateList(List &L){
    L.First = NULL;
}

address alokasi(infotype x){
    address nodeBaru = new ElmList;
    nodeBaru->info = x;
    return nodeBaru;
}
void dealokasi(address P){
    P->next = NULL;
    delete P;
}

void printInfo(List L){
    if(L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        while (nodeBantu != NULL){
            cout << nodeBantu->info << " ";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}
void insertFirst(List &L, address P){
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x){
    if (isEmpty(L) == true ){
        cout << "List kosong!" << endl;
    }else{
        address nodeBantu = L.First;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != NULL){
            posisi++;
            if(nodeBantu->info == x){
                cout << x << " ditemukan dalam list" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
    }
}

void penjumlahan(List L){
    if(L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        int P = 0;
        while (nodeBantu != NULL){
            P += nodeBantu->info;
            nodeBantu = nodeBantu->next;
        }
        cout << "Total info dari kelima elemen adalah " << P << endl;
        cout << endl;
    }
}