# <h1 align="center">Laporan Praktikum Modul 10 TREE (BAGIAN PERTAMA)</h1>
<p align="center">Amelia Candradewi - 103112400140</p>

## Dasar Teori
Struktur data Tree (Pohon) adalah koleksi simpul (node) yang terhubung secara hirarkis, menjadikannya struktur non-linear. Setiap Tree memiliki satu simpul utama yang disebut Akar (Root), yang berfungsi sebagai titik awal. Setiap simpul hanya boleh memiliki satu simpul Induk (Parent) (kecuali Root), namun dapat memiliki beberapa simpul Anak (Child). Simpul yang tidak memiliki anak disebut Daun (Leaf). Dalam C++, Tree diimplementasikan menggunakan struktur (struct) atau kelas (class) untuk merepresentasikan node, di mana setiap node berisi data (infotype) dan satu atau lebih pointer yang menunjuk ke simpul anaknya.Jenis pohon yang paling dasar adalah Binary Tree, di mana setiap simpul maksimal hanya memiliki dua anak: kiri (left) dan kanan (right). Bentuk paling penting dari ini adalah Binary Search Tree (BST). Dalam BST, keterurutan data dijaga: untuk setiap simpul, semua nilai di sub-pohon kirinya lebih kecil dari nilai simpul tersebut, dan semua nilai di sub-pohon kanannya lebih besar. Aturan ini memungkinkan operasi dasar seperti pencarian (searching), penyisipan (insertion), dan penghapusan (deletion) dilakukan dengan sangat efisien, biasanya dalam kompleksitas waktu BigO (log n) pada kasus rata-rata.


## Guided 1 : implementasi untuk menguji dan menjalankan operasi-operasi Binary Search Tree (BST).

### bst.h

```C++
#ifndef BST_H
#define BST_H
#define Nil NULL 

using namespace std;

typedef struct  BST *node; //alias pointer =node

struct BST{ //nama struct nya BST
    int angka;
    node left;
    node right;
};

typedef node BinTree; // alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

### bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;
//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

//prosedur tranfersal nya
void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
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
```

### main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

penjelasan singkat guided 1
Program ini dibuat sebagai implementasi untuk menguji dan menjalankan operasi-operasi Binary Search Tree (BST).

Pada guided 1 ini diberikan codingan untuk implementasi operasi-operasi BST seperti :

1.Seperti biasa membuat pointer node nya, lalu buat nama struct bst diisi dengan node left, node right karena ini operasi Tree. dan buat alias tree = BinTree.
2.Buat fungsi primitif seperti isEmpty, createTree, alokasi, dealokasi.
3.Buat insertNode, searchBydata,preOrder,inOrder,postOrder.
4.Buat deleteNode, mostRight,mostLeft,deleteTree, sze, height.

Untuk file .cpp nya :
Code di fungsi primitif sama saja hanya pada saat di Tree gunakan left right nya juga.

Pada saat :
1.InsertNode : jika tree nya kosong buat nodeBaru lalu output node nya sudah terisi bilangan yang di inputkan. dan untuk menaruh posisi node nya dilakukan pengecekan . pengecekan pertama apabila angka nya < root maka akan ditaruh di sisi kiri, jika angka inputan > root maka akan diatruh disisi kanan.

2.SearchByData : jika tree benar kosong maka akan lanjut. buat variabel untuk men-aliaskan nilai tree nya, buat variabel untuk parent kosong, buat boolean variabel ketemu untuk false/true nantinya. gunakan while, variabel tree nya tidak ksoong, cek jika data yang dicari < angka variabel tree maka disimpan di parent kiri, tetapi jika data angka > variabel tree masuk ke parent disimpan di kanan, jika data yang dicari == variabel tree maka ketemu = true, itu dilakukan pengecekan terus menerus hingga ketemu sesuai dengan data nya, jika false , ter-output data tidak ditemukan. jika ketemu ter-output data ditemukan didalam tree, dan ter-output data angka: (isi data yang dicari).

untuk menampilkan parent &pengecekan sibiling :
buat variabel sibling kosong, jika parent tidak kosong teroutput parent : (isi data nya) - (node root).

untuk menampilkan sibling :
jika sibling tidak kosong teroutput sibling : (isi data nya), kalo kosong ter-output sibling : -

untuk menampilkan childnya :
jika variabel tree kiri tidak kosong, ter-output child kiri : (isi data nya), tetapi jika variabel kiri == kosong  ter-output child kiri : -
jika variabel kanan tidak kosong ter-output child kanan : (isi data nya), jika variabel kanan == kosong ter-output child kanan : -.

#### Prosedur transfersal
1.preOrder (Tengah- kiri-kanan atauu root-child kiri-child kanan) : jika data nya == kosong return , ter-output data nya, ter-output preorder kiri preorder kanan.
2.inOrder (kiri - tengah - kanan atau child kiri - root - child kanan) : jika data nya == kosong, ter-output inOrder kiri - inOrder kanan.
3.postOrder (kiri - kanan - tengah atau child kiri - child kanan - root) : jika data nya == kosong maka akan teroutput data kiri - data kanan.

Untuk delete node : sama saja speerti sebelumnya, hanya saja setelah pengecakan digunakan case yang mau dihapus.

untuk mostRight : Tujuannya Mencari node dengan nilai terbesar (maksimum) dalam sub-pohon yang diberikan. Melakukan iterasi (perulangan) dari node akar tree yang diberikan, selalu mengikuti pointer right hingga pointer right tersebut menunjuk ke Nil (NULL).

untuk mostLeft : Tujuannya Mencari node dengan nilai terkecil (minimum) dalam sub-pohon yang diberikan. Melakukan iterasi (perulangan) dari node akar tree yang diberikan, selalu mengikuti pointer left hingga pointer left tersebut menunjuk ke Nil (NULL).

untuk deleteTree :  jika data tidak koosong maka return dan hapus data kiri, data kanan dealokasi kan data = kosong.

untuk int size : untuk mengembalikan jumlah semua node, jika isEmpty == benar maka return 0, jika tidak return 1 + jumlah semua node kiri + jumlah semua node kanan.

untuk int height : untuk mengembalikan jumlah level tree, jika isEmpty == true, return -1, tetapi jika tidak buat variabel baru untuk kiir kanan, variabel max height nya dan pengecekan jika variabel pertma lebih dari variabel kedua maka max height nya varibael pertma, jika tidak masuk ke variabel kedua, return 1 + maxheight nya


#### Untuk di main.cpp
 disesuaikan dengan yang diminta soal, kalau disuruh buat tampilan menu gunakan swicth case


## Unguided 

### Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”

### bstree.h
```C++
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
};

bool isEmpty(address root);
address alokasi(infotype x);

void insertNode(address &root, infotype x);
void findNode(address &root);
void printInOrder(address root);

// UNTUK JAWABAN NOMOR.2
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

// UNTUK JAWABAN NOMOR.3
void preOrder(address root);
void postOrder(address root);

#endif
```

### bstree.cpp
```C++
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
```

### main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

// Jalankan sesuai nomor

INT MAIN NOMOR 1
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    printInOrder(root);
    return 0;
}

// INT MAIN NOMOR.2
// int main() {
//     cout << "Hello World" << endl;
//     address root = Nil;
//     insertNode(root,1);
//     insertNode(root,2);
//     insertNode(root,6);
//     insertNode(root,4);
//     insertNode(root,5);
//     insertNode(root,3);
//     insertNode(root,6);
//     insertNode(root,7);
//     printInOrder(root);
//     cout<<"\n";
//     cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
//     cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
//     cout<<"total : "<<hitungTotalInfo(root,0)<<endl;
//     return 0;
// }

// //INT MAIN NOMOR.3
// int main() {
//     cout << "Hello World" << endl;
//     address root = Nil;
//     insertNode(root,6);
//     insertNode(root,4);
//     insertNode(root,7);
//     insertNode(root,2);
//     insertNode(root,5);
//     insertNode(root,1);
//     insertNode(root,3);


//     cout << "PrintPreOrder : ";
//     preOrder(root);
//     cout << endl;

//     cout << "PrintPostOrder : ";
//     postOrder(root);
//     cout << endl;

//     return 0;
// }
```
### Output Unguided  :

##### Output soal-1
![Screenshot Output Unguided 1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan8_Modul8-queue/Output-Unguided-soal1.png)

##### Output soal-2
![Screenshot Output Unguided 1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan8_Modul8-queue/Output-Unguided-soal2.png)

##### Output soal-3
![Screenshot Output Unguided 1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan8_Modul8-queue/Output-Unguided-soal3.png)


## penjelasan unguided untuk soal 1, 2 dan 3 digabung karena saling berkesinambungan
program ini meminta untuk menampilkan data tree dari dummy yang sudah diberikan

1.Seperti biasa membuat pointer node nya, lalu buat nama struct bst diisi dengan node left, node right karena ini operasi Tree. dan buat alias infotype info.
2.Buat fungsi primitif seperti isEmpty, alokasi.
3.Buat insertNode, findNode, printInOrder.

## PENJELASAN NOMOR 2 JUGA
4.Buat hitungJumlah Node dengan parameter address root.
5.Buat hitungTotalInfo dengan parameter address root int start.
6.Buat hitungKedalaman dengan parameter address root int star

## PENJELASAN NOMOR 3 JUGA
7.Buat preOrder
8.buat postOrder

Untuk file .cpp nya :
Code di fungsi primitif sama saja hanya pada saat di Tree gunakan left right nya juga.

Pada saat :
1.InsertNode : jika tree nya kosong buat nodeBaru lalu output node nya sudah terisi bilangan yang di inputkan. dan untuk menaruh posisi node nya dilakukan pengecekan . pengecekan pertama apabila angka nya < root maka akan ditaruh di sisi kiri, jika angka inputan > root maka akan diatruh disisi kanan.

2.findNode : Buat variabel untuk men-aliaskan nilai tree nya, buat variabel untuk parent kosong, buat boolean variabel ketemu untuk false/true nantinya. gunakan while, variabel tree nya tidak ksoong, cek jika data yang dicari < angka variabel tree maka disimpan di parent kiri, tetapi jika data angka > variabel tree masuk ke parent disimpan di kanan, jika data yang dicari == variabel tree maka ketemu = true, itu dilakukan pengecekan terus menerus hingga ketemu sesuai dengan data nya, jika false , ter-output data tidak ditemukan. jika ketemu ter-output data ditemukan didalam tree, dan ter-output data angka: (isi data yang dicari).

## NOMOR 2 NYA 
3.hitung jumlahNode : jika isEmpty == benar maka return 0, jika tidak return 1 + jumlah semua node kiri + jumlah semua node kanan.
4.hitungTotalInfo : jika isEmpty == benar maka return 0, jika tidak isi data nya + hitungTotalInfo kiri, start + hitungTotalInfo kanan, start.
5.hitung kedalaman :jika isEmpty == true, return -1, tetapi jika tidak buat variabel baru untuk kiri kanan, variabel max height nya dan pengecekan jika variabel pertma lebih dari variabel kedua maka max height nya varibael pertma, start + 1, jika tidak masuk ke variabel kedua, return 1 + maxheight nya, start +1

#### Prosedur transfersal
## NOMOR 1 NYA
6.printInOrder (kiri - tengah - kanan atau child kiri - root - child kanan) : jika data nya == kosong, ter-output inOrder kiri - inOrder kanan.

## NOMOR 2 NYA
7.preOrder (Tengah- kiri-kanan atauu root-child kiri-child kanan) : jika data nya == kosong return , ter-output data nya, ter-output preorder kiri preorder kanan.

## NOMOR 3 NYA
8.preOrder (Tengah- kiri-kanan atauu root-child kiri-child kanan) : jika data nya == kosong return , ter-output data nya, ter-output preorder kiri preorder kanan.
9.postOrder (kiri - kanan - tengah atau child kiri - child kanan - root) : jika data nya == kosong maka akan teroutput data kiri - data kanan.

## UNTUK DI MAIN.CPP NYAA
#### 1. masukkan data dummy yang telah disediakan
#### 2. masukkan data dummy yang telah disediakan jugaa
#### 3. coppy data dummy yang sudah ada lalu dirubah urutannya sesuai yang dimintai soal


## Kesimpulan
truktur data Tree (Pohon) adalah metode penyimpanan data non-linear yang tersusun hirarkis, dimulai dari Akar (Root). Di C++, Tree direpresentasikan oleh node yang saling terhubung melalui pointer. Jenis utamanya, Binary Search Tree (BST), menerapkan aturan keterurutan (nilai left < Nilai root < Nilai right) yang memastikan semua operasi dasar (searching, insertion, deletion) berjalan sangat efisien dengan kompleksitas waktu BigO(log n).

## Referensi
[1] Chevalier, F., Auber, D., & Telea, A. (2007, September). Structural analysis and visualization of c++ code evolution using syntax trees. In Ninth international workshop on Principles of software evolution: in conjunction with the 6th ESEC/FSE joint meeting (pp. 90-97).
<br>[2] Nabila Chairunnisa,S.Kom (2024). "Langkah mudah belajar pemrograman C++". Penerbit ANAK HEBAT INDONESIA
