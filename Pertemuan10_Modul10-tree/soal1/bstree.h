#ifndef BST_H
#define BST_H
#define Nil NULL 

using namespace std;

typedef int infotype;
typedef struct  Node *address; //alias pointer =node
struct Node{ //nama struct nya BST
    infotype info;
    address left;
    address right;
};//

bool isEmpty(address root);//
address alokasi(infotype x);//

void insertNode(address &root, infotype x);
void findNode(address &root);
void printInOrder(address root);//

// UNTUK JAWABAN NOMOR.2
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

// UNTUK JAWABAN NOMOR.3
void preOrder(address root);
void postOrder(address root);

#endif