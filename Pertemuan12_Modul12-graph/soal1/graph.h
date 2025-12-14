#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode{
    infoGraph info; 
    int visited; 
    adrEdge firstEdge; 
    adrNode Next; 
};

struct ElmEdge{
    adrNode Node; 
    adrEdge Next; 
};

struct Graph{
    adrNode First;
};

// no.1
void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph X); 
adrEdge AlokasiEdge(adrNode nodeTujuan); 

void InsertNode(Graph &G, infoGraph X); 
void ConnectNode(adrNode &N1, adrNode &N2);
void PrintInfoGraph(Graph G); 
adrNode FindNode(Graph G, infoGraph X);

//no.2 
void PrintDFS(Graph G, adrNode N);
void ResetVisited(Graph &G);

//no.3
void PrintBFS(Graph G, adrNode N);
#endif