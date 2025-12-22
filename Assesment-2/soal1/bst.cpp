#include "bst.h"
#include <iostream>

using namespace std;

void createTree(BinTree &tree) {
    tree = Nil;
}

bool isEmpty(BinTree tree) {
    return tree == Nil;
}

node alokasi(int id, string nama, int stok) {
    node nodeBaru = new BST;
    nodeBaru->idProduk = id;
    nodeBaru->namaProduk = nama;
    nodeBaru->stok = stok;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus) {
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru) {
    if (isEmpty(tree)) {
        tree = nodeBaru;
    } else if (nodeBaru->idProduk < tree->idProduk) {
        insertNode(tree->left, nodeBaru);
    } else if (nodeBaru->idProduk > tree->idProduk) {
        insertNode(tree->right, nodeBaru);
    }
}

void searchById(BinTree tree, int id) {
    if (isEmpty(tree)) {
        cout << "ID " << id << " tidak ditemukan!" << endl;
        return;
    }
    if (tree->idProduk == id) {
        cout << "Ditemukan: [" << tree->idProduk << "] " << tree->namaProduk << " | Stok: " << tree->stok << endl;
    } else if (id < tree->idProduk) {
        searchById(tree->left, id);
    } else {
        searchById(tree->right, id);
    }
}

void searchByProduct(BinTree tree, string nama) {
    if (isEmpty(tree)) return;
    
    if (tree->namaProduk == nama) {
        cout << "Ditemukan: [" << tree->idProduk << "] " << tree->namaProduk << " | Stok: " << tree->stok << endl;
        return; 
    }
    searchByProduct(tree->left, nama);
    searchByProduct(tree->right, nama);
}

node mostLeft(BinTree tree) {
    while (tree && tree->left != Nil) tree = tree->left;
    return tree;
}

node findMin(BinTree tree) {
    return mostLeft(tree);
}

node findMax(BinTree tree) {
    while (tree && tree->right != Nil) tree = tree->right;
    return tree;
}

bool deleteNode(BinTree &tree, int id) {
    if (isEmpty(tree)) return false;

    if (id < tree->idProduk) {
        return deleteNode(tree->left, id);
    } else if (id > tree->idProduk) {
        return deleteNode(tree->right, id);
    } else {
        node temp;
        if (tree->left == Nil) {
            temp = tree;
            tree = tree->right;
            dealokasi(temp);
        } else if (tree->right == Nil) {
            temp = tree;
            tree = tree->left;
            dealokasi(temp);
        } else {
            node successor = findMin(tree->right);
            tree->idProduk = successor->idProduk;
            tree->namaProduk = successor->namaProduk;
            tree->stok = successor->stok;
            return deleteNode(tree->right, successor->idProduk);
        }
        return true;
    }
}

void deleteTree(BinTree &tree) {
    if (isEmpty(tree)) return;
    deleteTree(tree->left);
    deleteTree(tree->right);
    dealokasi(tree);
    tree = Nil;
}

void inOrder(BinTree tree) {
    if (isEmpty(tree)) return;
    inOrder(tree->left);
    cout << tree->idProduk << " ";
    inOrder(tree->right);
}

void preOrder(BinTree tree) {
    if (isEmpty(tree)) return;
    cout << tree->idProduk << " ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void postOrder(BinTree tree) {
    if (isEmpty(tree)) return;
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->idProduk << " ";
}