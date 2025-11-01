#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct Elmlist *address;

struct Elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address last;
};

bool isEmpty(List L);
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);

void insertLast(List &L, address P);
address cariNopol(List L, infotype x);
void deleteFirst(List &L, address P);
void deleteLast(List &L, address P);
void deleteAfter(address Prec, address &P);
void deleteByNopol(List &L, infotype x);
#endif