#include "graphKota.h"
#include <iostream>
#include <queue>
#include <stack>

void createGraph(GraphKota &G) {
    G.First = NULL;
}

adrKota alokasiNode(string nama) {
    adrKota P = new ElmKota;
    P->namaKota = nama;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrEdge alokasiEdge(adrKota tujuan, int jarak) {
    adrEdge E = new ElmEdge;
    E->kotaTujuan = tujuan;
    E->jarak = jarak;
    E->next = NULL;
    return E;
}

void insertNode(GraphKota &G, string nama) {
    adrKota P = alokasiNode(nama);
    if (G.First == NULL) {
        G.First = P;
    } else {
        adrKota last = G.First;
        while (last->next != NULL) last = last->next;
        last->next = P;
    }
}

adrKota findNode(GraphKota G, string nama) {
    adrKota P = G.First;
    while (P != NULL) {
        if (P->namaKota == nama) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(GraphKota &G, string kota1, string kota2, int jarak) {
    adrKota k1 = findNode(G, kota1);
    adrKota k2 = findNode(G, kota2);
    if (k1 != NULL && k2 != NULL) {
        adrEdge e1 = alokasiEdge(k2, jarak);
        e1->next = k1->firstEdge;
        k1->firstEdge = e1;

        adrEdge e2 = alokasiEdge(k1, jarak);
        e2->next = k2->firstEdge;
        k2->firstEdge = e2;
    }
}

void disconnectNode(adrKota k1, adrKota k2) {
    if (k1 == NULL || k1->firstEdge == NULL) {
        return;
    }
    adrEdge P = k1->firstEdge;
    adrEdge prev = NULL;

    while (P != NULL && P->kotaTujuan != k2) {
        prev = P;
        P = P->next;
    }
    if (P != NULL) {
        if (prev == NULL) {
            k1->firstEdge = P->next;
        } else {
            prev->next = P->next;
        }
        delete P;
    }
}

void deleteNode(GraphKota &G, string nama) {
    adrKota target = findNode(G, nama);
    if (target == NULL) return;

    adrKota tempK = G.First;
    while (tempK != NULL) {
        disconnectNode(tempK, target);
        tempK = tempK->next;
    }

    adrEdge tempE = target->firstEdge;
    while (tempE != NULL) {
        adrEdge del = tempE;
        tempE = tempE->next;
        delete del;
    }

    if (G.First == target) {
        G.First = target->next;
    } else {
        adrKota prevK = G.First;
        while (prevK->next != target) prevK = prevK->next;
        prevK->next = target->next;
    }
    delete target;
}

void printGraph(GraphKota G) {
    adrKota P = G.First;
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    
    while (P != NULL) {
        cout << "Node " << P->namaKota << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        
        while (E != NULL) {
            cout << E->kotaTujuan->namaKota << "(" << E->jarak << " KM)";
            
            if (E->next != NULL) {
                cout << ", ";
            } else {
                cout << ","; 
            }
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

//BAGIAN B
void resetVisited(GraphKota &G) {
    adrKota P = G.First;
    while (P != NULL) {
        P->visited = 0;
        P->next; 
        P = P->next;
    }
}

void printBFS(GraphKota G, string startKota) {
    resetVisited(G);
    adrKota start = findNode(G, startKota);
    if (start == NULL) return;

    queue<adrKota> q;
    start->visited = 1;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        adrKota curr = q.front();
        q.pop();
        cout << curr->namaKota << " ";

        adrEdge e = curr->firstEdge;
        while (e != NULL) {
            if (e->kotaTujuan->visited == 0) {
                e->kotaTujuan->visited = 1;
                q.push(e->kotaTujuan);
            }
            e = e->next;
        }
        if (!q.empty()) cout << "- ";
    }
    cout << endl;
}

void printDFS(GraphKota G, string startKota) {
    resetVisited(G);
    adrKota start = findNode(G, startKota);
    if (start == NULL) return;

    stack<adrKota> s;
    s.push(start);

    cout << "DFS Traversal: ";
    bool first = true;
    while (!s.empty()) {
        adrKota curr = s.top();
        s.pop();

        if (curr->visited == 0) {
            curr->visited = 1;
            if (!first) cout << "- ";
            cout << curr->namaKota << " ";
            first = false;

            adrEdge e = curr->firstEdge;
            while (e != NULL) {
                if (e->kotaTujuan->visited == 0) {
                    s.push(e->kotaTujuan);
                }
                e = e->next;
            }
        }
    }
    cout << endl;
}