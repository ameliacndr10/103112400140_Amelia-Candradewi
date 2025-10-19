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
void dealokasi(address &P){
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

void deleteFirst(List &L){
    address P;

    if(L.First== NULL){
        cout<< "list masih kosong";
    }else{
        P = L.First;
        L.First = L.First->next;
        P->next = NULL;
        dealokasi (P);
    }
}
void deleteLast(List &L){
    address P, Q;

    if (L.First == NULL)
    { 
    cout<< "list masih kosong";
    }else{
        P = L.First;
        if (P->next == NULL){
            P->next = NULL;
            dealokasi (P);
        }else{
            while (P->next !=NULL)
            {
                Q = P;
                P = P->next;
            }
            Q->next = NULL;
            dealokasi(P);
        }
    }
    
}
void deleteAfter(List &L, address P, address Q){
    if(L.First == NULL){
        cout << "list masih kosong";
    }else{
        if ( Q != NULL && Q->next != NULL){
            P = Q->next;
            Q->next = P->next;
            P->next = NULL;
            dealokasi(P);
        }else{
            cout << "Node sebelum, (prev) tidak valid";
        }
    }
}
int nbList(List L){
    int count = 0;
    address P = L.First;
    while (P != NULL)
    {
        count++;
        P = P->next;
    }
    return count;
}
void deleteList(List &L){
    address nodeBantu,P;
    nodeBantu = L.First;
    while (nodeBantu != NULL)
    {
        P = nodeBantu;
        nodeBantu= nodeBantu->next;
        dealokasi(P);
    }
    L.First = NULL;
    cout << "List sudah terhapus" << endl;
}