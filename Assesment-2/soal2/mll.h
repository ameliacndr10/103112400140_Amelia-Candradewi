#ifndef MLL_H
#define MLL_H

#include <iostream>
using namespace std;

struct DataFilm {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
};

struct DataGenre {
    string idGenre;
    string namaGenre;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataFilm isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    DataGenre isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Anak;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);
NodeParent alokasiNodeParent(string id, string nama);
NodeChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void dealokasiNodeParent(NodeParent &P);
void dealokasiNodeChild(NodeChild &C);

void insertFirstParent(listParent &L, NodeParent P);
void insertLastChild(listChild &L, NodeChild C);
void deleteAfterParent(listParent &L, NodeParent nodePrev);
void hapusListChild(listChild &L);

void searchFilmByRatingRange(listParent L, float minRating, float maxRating);
void printStrukturMLL(listParent L);

#endif