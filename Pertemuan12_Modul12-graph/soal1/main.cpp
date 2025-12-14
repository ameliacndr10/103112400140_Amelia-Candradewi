#include "graph.h"
#include <iostream>
using namespace std;

int main(){
    // no 1
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode nA, nB, nC, nD, nE, nF, nG, nH;
    nA = FindNode(G, 'A');
    nB = FindNode(G, 'B');
    nC = FindNode(G, 'C');
    nD = FindNode(G, 'D');
    nE = FindNode(G, 'E');
    nF = FindNode(G, 'F');
    nG = FindNode(G, 'G');
    nH = FindNode(G, 'H');

    ConnectNode(nA, nC);
    ConnectNode(nA, nB);
    ConnectNode(nB, nE);
    ConnectNode(nB, nD);
    ConnectNode(nC, nG);
    ConnectNode(nC, nF);
    ConnectNode(nG, nH);
    ConnectNode(nF, nH);
    ConnectNode(nE, nH);
    ConnectNode(nD, nH);

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    // no 2
    PrintDFS(G, nA); 
    // no 3
    PrintBFS(G, nA); 
    cout << endl;
}