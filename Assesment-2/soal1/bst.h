#ifndef BST_H
#define BST_H
#define Nil NULL 
#include <iostream>
using namespace std;

struct BST {
    int idProduk;        
    string namaProduk;
    int stok;
    BST *left;
    BST *right;
};

typedef BST *node;
typedef node BinTree;

void createTree(BinTree &tree);
bool isEmpty(BinTree tree);
node alokasi(int id, string nama, int stok);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchById(BinTree tree, int id);
void searchByProduct(BinTree tree, string nama); 
bool deleteNode(BinTree &tree, int id);
void deleteTree(BinTree &tree);

void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

node findMin(BinTree tree);
node findMax(BinTree tree);
node mostLeft(BinTree tree);

#endif