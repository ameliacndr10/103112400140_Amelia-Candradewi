#include "Singlylist.h"
#include <iostream>
using namespace std;


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
    }
}
void insertFirst(List &L, address P){
    P->next = L.First;
    L.First = P;
}
