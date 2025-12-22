#ifndef GRAPHKOTA_H
#define GRAPHKOTA_H

#include <iostream>
#include <string>
#include <queue>  
#include <stack> 

using namespace std;

typedef struct ElmKota *adrKota;
typedef struct ElmEdge *adrEdge;

struct ElmKota {
    string namaKota;     
    int visited;         
    adrEdge firstEdge;  
    adrKota next;
};

struct ElmEdge {
    adrKota kotaTujuan; 
    int jarak;           
    adrEdge next;
};

struct GraphKota {
    adrKota First;       
};

//BAGIAN.A
void createGraph(GraphKota &G);
adrKota alokasiNode(string nama);
adrEdge alokasiEdge(adrKota tujuan, int jarak);
void insertNode(GraphKota &G, string nama);
adrKota findNode(GraphKota G, string nama);
void connectNode(GraphKota &G, string kota1, string kota2, int jarak);
void disconnectNode(adrKota k1, adrKota k2);
void deleteNode(GraphKota &G, string nama);
void printGraph(GraphKota G);

//BAGIAN B
void resetVisited(GraphKota &G);
void printBFS(GraphKota G, string startKota);
void printDFS(GraphKota G, string startKota);

#endif