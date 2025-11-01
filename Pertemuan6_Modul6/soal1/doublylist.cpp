#include "doublylist.h"
#include <iostream>
using namespace std;

bool isEmpty(List L){
    if(L.First == NULL){
        return true; 
    } else {
        return false;
    }
}
void CreateList(List &L){
    L.First = NULL;
    L.last  = NULL;
}
    address alokasi(infotype x){
    address nodeBaru = new Elmlist;
    nodeBaru->info.nopol = x.nopol;
    nodeBaru->info.warna = x.warna;
    nodeBaru->info.thnBuat = x.thnBuat;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;
    return nodeBaru;
}
void dealokasi(address &P){
    P->next = NULL;
    P->prev = NULL;
    delete P;
}
void printInfo(List L){
    if (isEmpty(L) == true){
        cout << "List kosong!" << endl;
    }else{
        address nodebantu = L.First;
        cout << "DATA LIST 1" << endl;
        cout << endl;
        while( nodebantu != NULL){
            cout << "no polisi  :" << nodebantu->info.nopol << endl;
            cout << "warna      :" << nodebantu->info.warna << endl;
            cout << "tahun      :" << nodebantu->info.thnBuat << endl;
            nodebantu = nodebantu->next;
        }
    }
}
void insertLast(List &L, address P){
    if(isEmpty(L) == true){
        L.First = L.last = P;
    }else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

address cariNopol(List L, infotype x){
    address P = L.First;
    while(P != NULL){
        if(P->info.nopol == x.nopol){
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirst(List &L, address P){
    if(isEmpty(L)== true){
        cout << "List kosong!" << endl;
        return;
    }
    address pDel = L.First;
    if(L.First == L.last){
        L.First = L.last = NULL;
    }else{
        L.First = pDel->next;
        L.First->prev = NULL;
        pDel->next = NULL;
    }
    pDel->prev = NULL;
    cout << "Node " << pDel->info.nopol << " berhasil dihapus dari posisi pertama." << endl;
}
void deleteLast(List &L, address P){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
        return;
    }
    address pDel = L.last;
    if(L.First == L.last){
        L.First = L.last = NULL;
    }else {
        L.last = pDel->prev;
        L.last->next = NULL;
        pDel->prev = NULL;
    }
    pDel->next = NULL;
    cout << "Node " << pDel->info.nopol << " berhasil dihapus dari posisi pertama." << endl;
}

void deleteAfter(address Prec, address &P){
    P = Prec->next;

    if (P != NULL){
        Prec->next = P->next;
        if (P->next != NULL){
            P->next->prev = Prec;
        }else {
            Prec->next = NULL;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}


void deleteByNopol(List &L, infotype x ){
    address P = cariNopol(L,x);
    address Prec;
    if (P == NULL) {
        return;
    }
    if (P == L.First) {
        deleteFirst(L,P);
    }else if(P == L.last){
        deleteLast(L,P);
    }else{
        Prec = P->prev;
        deleteAfter(Prec,P);
    }
    cout << "Data dengan nomor polisi " << x.nopol << " berhasil dihapus." << endl;
    dealokasi(P);
}


    // address P = L.First;
    // while(P != NULL){
    //     if(P->info.nopol == x.nopol){
    //         return P;
    //     }
    //     P = P->next;
    // }

    // return NULL;