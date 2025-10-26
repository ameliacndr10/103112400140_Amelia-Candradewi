#ifndef SINGLYLIST 
#define SINGLYLIST

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList{
    infotype info;
    address next;
};

struct List {
    address First;
};

bool isEmpty(List L);
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
void penjumlahan(List L);

#endif