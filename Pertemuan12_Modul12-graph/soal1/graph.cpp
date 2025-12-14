#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>


void CreateGraph(Graph &G){
    G.First = NULL;
} 

adrNode AlokasiNode(infoGraph X){
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = X;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
} 

adrEdge AlokasiEdge(adrNode nodeTujuan){
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

void InsertNode(Graph &G, infoGraph X){
    adrNode nodeBaru = AlokasiNode(X);
    if (G.First == NULL){
        G.First = nodeBaru;
    }else{
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL){
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == X) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

void ConnectNode(adrNode &N1, adrNode &N2){
    if (N1 == NULL || N2 == NULL) {
        cout << "ERROR node bernilai NULL." << endl;
        return;
    }

    // 1. Edge dari N1 ke N2
    adrEdge newEdge1 = AlokasiEdge(N2);
    newEdge1->Next = N1->firstEdge;
    N1->firstEdge = newEdge1;

    // 2. Edge dari N2 ke N1 (karena tak berarah)
    adrEdge newEdge2 = AlokasiEdge(N1);
    newEdge2->Next = N2->firstEdge;
    N2->firstEdge = newEdge2;
}

void PrintInfoGraph(Graph G){
    adrNode nodeBantu = G.First;
    while(nodeBantu != NULL){
        cout << "Node" << nodeBantu->info << " terhubung ke :";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while(edgeBantu != NULL){
            cout << edgeBantu->Node->info << " ";
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

// no.2
void ResetVisited(Graph &G){
    adrNode nodeReset = G.First;
    while(nodeReset != NULL){
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

void PrintDFS(Graph G, adrNode N){
    ResetVisited(G);
    
    if(N == NULL) return;
    
    stack <adrNode> Stak;
    Stak.push(N);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}

// no.3
void PrintBFS(Graph G, adrNode N){
    ResetVisited(G);

    if(N == NULL ) return;

    queue<adrNode> Qyu;

    N->visited = 1;
    Qyu.push(N);

    cout <<"BFS Traversal: ";
    while (!Qyu.empty()){
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        adrEdge edgeBantu = nodeBantu->firstEdge;
        while(edgeBantu != NULL){
            if(edgeBantu->Node->visited == 0){
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}