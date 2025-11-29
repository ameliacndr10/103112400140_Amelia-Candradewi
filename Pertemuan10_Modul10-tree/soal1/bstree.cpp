#include "bstree.h"
#include <iostream>

using namespace std;

bool isEmpty(address root){
    if(root == Nil){
        return true;
    } else {
        return false;
    }
}

address alokasi(infotype x){
    address nodeBaru = new Node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
        return;
    } else if(x < root->info){
        insertNode(root->left, x);
    } else if(x > root->info){
        insertNode(root->right, x);
    }
}

void findNode(address &root, infotype x){
    address nodeBantu = root;
    if(isEmpty(root) == true){
        cout << "Tree kosong!" << endl;
    } else {
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(x < nodeBantu->info){
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;
        }
    }
}
void printInOrder(address root){
    if(root == Nil){
        return;
    }
    printInOrder(root->left);
    cout << root->info << " - ";
    printInOrder(root->right);
}

// UNTUK JAWABAN NOMOR.2
int hitungJumlahNode(address root){
    if(isEmpty(root) == true){
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
    cout << endl;
}

int hitungTotalInfo(address root, int start){
    if(isEmpty(root) == true){
        return 0;
    }else{
        return root->info + hitungTotalInfo(root->left, start) + hitungTotalInfo(root->right, start);
    }
    cout << endl;
}
int hitungKedalaman(address root, int start){
        if(isEmpty(root) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = hitungKedalaman(root->left, start + 1);
        int hr = hitungKedalaman(root->right, start + 1);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

// UNTUK JAWABAN NOMOR.3
void preOrder(address root){
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(address root){
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}

