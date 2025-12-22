#include "mll.h"
#include <iostream>
using namespace std;

void createListParent(listParent &L) {
    L.first = L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = L.last = NULL;
}

NodeParent alokasiNodeParent(string id, string nama) {
    NodeParent P = new nodeParent;
    P->isidata.idGenre = id;
    P->isidata.namaGenre = nama;
    P->next = P->prev = NULL;
    createListChild(P->L_Anak);
    return P;
}

NodeChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    NodeChild C = new nodeChild;
    C->isidata.idFilm = id;
    C->isidata.judulFilm = judul;
    C->isidata.durasiFilm = durasi;
    C->isidata.tahunTayang = tahun;
    C->isidata.ratingFilm = rating;
    C->next = C->prev = NULL;
    return C;
}

void dealokasiNodeParent(NodeParent &P) {
    if (P != NULL) {
        delete P;
        P = NULL;
    }
}

void dealokasiNodeChild(NodeChild &C) {
    if (C != NULL) {
        delete C;
        C = NULL;
    }
}

void insertFirstParent(listParent &L, NodeParent P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(listChild &L, NodeChild C) {
    if (L.first == NULL) {
        L.first = L.last = C;
    } else {
        C->prev = L.last;
        L.last->next = C;
        L.last = C;
    }
}

void hapusListChild(listChild &L) {
    NodeChild P = L.first;
    while (P != NULL) {
        NodeChild temp = P;
        P = P->next;
        dealokasiNodeChild(temp);
    }
    L.first = L.last = NULL;
}

void deleteAfterParent(listParent &L, NodeParent nodePrev) {
    if (nodePrev != NULL && nodePrev->next != NULL) {
        NodeParent nodeHapus = nodePrev->next;
        // Hapus list anak terlebih dahulu
        hapusListChild(nodeHapus->L_Anak);
        
        nodePrev->next = nodeHapus->next;
        if (nodeHapus->next != NULL) {
            nodeHapus->next->prev = nodePrev;
        } else {
            L.last = nodePrev;
        }
        
        nodeHapus->next = nodeHapus->prev = NULL;
        dealokasiNodeParent(nodeHapus);
    }
}

void searchFilmByRatingRange(listParent L, float minR, float maxR) {
    NodeParent P = L.first;
    int posP = 1;
    bool found = false;
    
    while (P != NULL) {
        NodeChild C = P->L_Anak.first;
        int posC = 1;
        while (C != NULL) {
            if (C->isidata.ratingFilm >= minR && C->isidata.ratingFilm <= maxR) {
                cout << "Data Film ditemukan pada list child dari node parent " << P->isidata.namaGenre << " pada posisi ke-" << posC << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->isidata.judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << posC << endl;
                cout << "ID Film : " << C->isidata.idFilm << endl;
                cout << "Durasi Film : " << C->isidata.durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->isidata.tahunTayang << endl;
                cout << "Rating Film : " << C->isidata.ratingFilm << endl;
                cout << "---------------------------" << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->isidata.idGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << posP << endl;
                cout << "Nama Genre : " << P->isidata.namaGenre << endl;
                cout << "===========================" << endl;
                found = true;
            }
            C = C->next;
            posC++;
        }
        P = P->next;
        posP++;
    }
    if (!found) cout << "Film dengan rating " << minR << " - " << maxR << " tidak ditemukan." << endl;
}

void printStrukturMLL(listParent L) {
    NodeParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre : " << P->isidata.idGenre << endl;
        cout << "Nama Genre : " << P->isidata.namaGenre << endl;
        
        NodeChild C = P->L_Anak.first;
        int j = 1;
        while (C != NULL) {
            cout << "  - Child " << j << " :" << endl;
            cout << "    ID Film : " << C->isidata.idFilm << endl;
            cout << "    Judul Film : " << C->isidata.judulFilm << endl;
            cout << "    Durasi Film : " << C->isidata.durasiFilm << " menit" << endl;
            cout << "    Tahun Tayang : " << C->isidata.tahunTayang << endl;
            cout << "    Rating Film : " << C->isidata.ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << "---------------------------" << endl;
        P = P->next;
        i++;
    }
}