# <h1 align="center">Modul 6 DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Amelia Candradewi - 103112400140</p>

## Dasar Teori
doubly Linked List (DLL) merupakan struktur data linier yang terdiri dari node-node yang saling berhubungan, dimana setiap node mempunyai dua pointer yang menunjuk ke node sebelumnya dan node berikutnya. Berbeda dengan Single Linked List (SLL) yang hanya memiliki satu pointer yang menunjuk ke node berikutnya. Keunggulan DLL dibandingkan SLL terletak pada kemudahan dalam melakukan operasi penyisipan dan penghapusan data, karena DLL memungkinkan navigasi dua arah dalam daftar. penggunaan algoritma DLL untuk operasi insertion dan deletion. Algoritma insertion pada DLL dapat dilakukan di awal list (depan), di akhir list (belakang), atau di tengah list. Algoritma deletion pada DLL juga dapat dilakukan di awal list, di akhir list, atau di tengah list.

terjadi penambahan variabel pada struct nya :
1. address first dan address last
2. di struct isi pointer nya ada penambahan address prev[1].

Detail Proses Insertion dan Delete
Operasi insertion:

Di awal: Node baru dibuat, prev-nya diarahkan ke NULL, next ke first node, dan jika first node tidak kosong, prev dari first node diupdate mengarah ke node baru. address first diupdate ke node baru.

Di akhir: Node baru dibuat, next-nya diarahkan ke NULL, prev ke last node, dan last node (jika ada) next-nya diupdate ke node baru. address last diperbarui ke node baru.

Di tengah: Node baru diletakkan di antara dua node, prev dan next diupdate agar konsisten dengan posisi node baru.

Operasi delete:
Di awal: Node pertama dihapus, address first diubah ke node setelahnya (dan prev node baru diatur ke NULL).

Di akhir: Node terakhir dihapus, address last diubah ke node sebelumnya, dan next node baru diatur ke NULL.

Di tengah: Node target dihapus, prev-next tetangganya diatur agar tetap terhubung[2].

## Guided

### 1. Update data makanan di node pertama, terakhir, sebelum, sesudah

### listMakanan.h

```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev; //beda nya dengan singly linked list
};

struct linkedlist{
    address first;
    address last; //ini juga
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

### listMakanan.cpp

```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```

### main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```

penjelasan singkat guided 1
Program ini dibuat agar bisa Update data makanan di node pertama, terakhir, sebelum, sesudah.

Adanya penambahan prosedur before pada insert maupun update. Lalu, di struct nya ada penambahan variabel address sebagai prev nya. 
Langkah-langkah nya :
langkah pertama :List dibuat kosong.
langkah 2: Lima node data makanan dialokasikan (D, A, C, E, B).
langkah 3: Node-node disisipkan sehingga urutan akhirnya menjadi: D - A - C - E - B.
langkah 4: List ditampilkan.
langkah 5: List mengalami 4 operasi update (Pertama, Terakhir, Sebelum C, Setelah C).
langkah 6: List terakhir ditampilkan setelah semua pembaruan data dilakukan.

### 2. Update data makanan di node pertama, terakhir, sebelum, sesudah, lalu,mencari data makanan lewat nama, lalu, hapus lewat nama dan menampilkan isi list setelah didelete

### listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```

### listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

### main.cpp
```C++
	#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```

penjelasan singkat guided 2
Program ini dibuat agar bisa Update data makanan di node pertama, terakhir, sebelum, sesudah, lalu,mencari data makanan lewat nama, lalu, hapus lewat nama dan menampilkan isi list setelah didelete

Adanya penambahan prosedur before pada insert maupun update. Lalu, di struct nya ada penambahan variabel address sebagai prev nya. 

Lalu, ada penambahan Searching yaitu findByName, findByJenis, findByMinRating.
Langkah-langkah nya :
langkah pertama :List dibuat kosong.
langkah 2: Lima node data makanan dialokasikan dan dituliskan data dummy nya.
langkah 3: Node-node disisipkan sehingga urutan akhirnya menjadi: D - A - C - E - B.
langkah 4: List ditampilkan.
langkah 5: List mengalami 4 operasi update (Pertama, Terakhir, Sebelum C, Setelah C).
langkah 6: mencari data dengan nama yg sudah dimasukkan data dummy nya
langkah 7: node update first dihapus dari posisi pertama
langkah 8: node update sebelum node data dummy Donat dihapus.
langkah 6: List terakhir ditampilkan setelah semua pembaruan data dilakukan.


## Unguided 

### 1.1 Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil
### 1.2 Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address implementasi ADT pada file “main.cpp”.
### 1.3  Hapus elemen dengan nomor polisi D003 dengan procedure delete. procedure deleteFirst( input/output L : List,
### P : address )
### - procedure deleteLast( input/output L : List, P : address )
### - procedure deleteAfter( input Prec : address, input/output P : address )

### doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct Elmlist *address;

struct Elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address last;
};

bool isEmpty(List L);
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);

void insertLast(List &L, address P);
address cariNopol(List L, infotype x);
void deleteFirst(List &L, address P);
void deleteLast(List &L, address P);
void deleteAfter(address Prec, address &P);
void deleteByNopol(List &L, infotype x);
#endif
```

### doublylist.cpp 
```C++
#include "doublylist.h"
#include <iostream>
using namespace std;

bool isEmpty(List L){
    if(L.First == NULL){
        return true; 
    } else {
        return false;
    }
}
void CreateList(List &L){
    L.First = NULL;
    L.last  = NULL;
}
    address alokasi(infotype x){
    address nodeBaru = new Elmlist;
    nodeBaru->info.nopol = x.nopol;
    nodeBaru->info.warna = x.warna;
    nodeBaru->info.thnBuat = x.thnBuat;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;
    return nodeBaru;
}
void dealokasi(address &P){
    P->next = NULL;
    P->prev = NULL;
    delete P;
}
void printInfo(List L){
    if (isEmpty(L) == true){
        cout << "List kosong!" << endl;
    }else{
        address nodebantu = L.First;
        cout << "DATA LIST 1" << endl;
        cout << endl;
        while( nodebantu != NULL){
            cout << "no polisi  :" << nodebantu->info.nopol << endl;
            cout << "warna      :" << nodebantu->info.warna << endl;
            cout << "tahun      :" << nodebantu->info.thnBuat << endl;
            nodebantu = nodebantu->next;
        }
    }
}
void insertLast(List &L, address P){
    if(isEmpty(L) == true){
        L.First = L.last = P;
    }else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

address cariNopol(List L, infotype x){
    address P = L.First;
    while(P != NULL){
        if(P->info.nopol == x.nopol){
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirst(List &L, address P){
    if(isEmpty(L)== true){
        cout << "List kosong!" << endl;
        return;
    }
    address pDel = L.First;
    if(L.First == L.last){
        L.First = L.last = NULL;
    }else{
        L.First = pDel->next;
        L.First->prev = NULL;
        pDel->next = NULL;
    }
    pDel->prev = NULL;
    cout << "Node " << pDel->info.nopol << " berhasil dihapus dari posisi pertama." << endl;
}
void deleteLast(List &L, address P){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
        return;
    }
    address pDel = L.last;
    if(L.First == L.last){
        L.First = L.last = NULL;
    }else {
        L.last = pDel->prev;
        L.last->next = NULL;
        pDel->prev = NULL;
    }
    pDel->next = NULL;
    cout << "Node " << pDel->info.nopol << " berhasil dihapus dari posisi pertama." << endl;
}

void deleteAfter(address Prec, address &P){
    P = Prec->next;

    if (P != NULL){
        Prec->next = P->next;
        if (P->next != NULL){
            P->next->prev = Prec;
        }else {
            Prec->next = NULL;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}


void deleteByNopol(List &L, infotype x ){
    address P = cariNopol(L,x);
    address Prec;
    if (P == NULL) {
        return;
    }
    if (P == L.First) {
        deleteFirst(L,P);
    }else if(P == L.last){
        deleteLast(L,P);
    }else{
        Prec = P->prev;
        deleteAfter(Prec,P);
    }
    cout << "Data dengan nomor polisi " << x.nopol << " berhasil dihapus." << endl;
    dealokasi(P);
}
```

### main.cpp
```C++
#include "doublylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);
    
    int input;
    cout << "masukkan jumlah input-an   :";
    cin >> input;
    string nomor; 
    string warna;
    int tahun;
    for(int i =0 ; i < input; i++){
        cout << "masukkan nomor polisi      :";
        cin >> nomor;
        cout << "masukkan warna kendaraan   :";
        cin >> warna;
        cout << "masukkan tahun kendaraan   :";
        cin >> tahun;

        infotype A;
        A = {nomor, warna, tahun};
        if(cariNopol(L,A) == NULL){
            insertLast(L,alokasi(A));
        }else {
            cout << "nomor polisi sudah terdaftar" << endl;
        }
        cout << endl;
    }
    printInfo(L);

    cout << endl;
    cout << "Masukkan nomor polisi yang dicari  :";
    cin >> nomor;


    infotype cari;
    cari.nopol = nomor;
    address P = cariNopol(L,cari);
    if(P != NULL){
        cout << "Nomor polisi   : " << P->info.nopol<< endl;
        cout << "Warna          : " << P->info.warna<<endl;
        cout << "Tahun          : " << P->info.thnBuat<<endl;
    }else{
        cout << "Data tidak ditemukan";
    }

    cout << endl;
    cout << "Masukkan nomor polisi yang dihapus :";
    cin >> nomor;
    infotype hapus;
    hapus.nopol = nomor;
    deleteByNopol(L,hapus);
    printInfo(L);
    
    return 0;
}
```
### Output Unguided 1 :
```C++
    cout << "masukkan jumlah input-an   :";
    cin >> input;
    string nomor; 
    string warna;
    int tahun;
    for(int i =0 ; i < input; i++){
        cout << "masukkan nomor polisi      :";
        cin >> nomor;
        cout << "masukkan warna kendaraan   :";
        cin >> warna;
        cout << "masukkan tahun kendaraan   :";
        cin >> tahun;

        infotype A;
        A = {nomor, warna, tahun};
        if(cariNopol(L,A) == NULL){
            insertLast(L,alokasi(A));
        }else {
            cout << "nomor polisi sudah terdaftar" << endl;
        }
        cout << endl;
    }
    printInfo(L);
```
##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan6_Modul6/Output-Unguided1-1.png)

```C++
    cout << endl;
    cout << "Masukkan nomor polisi yang dicari  :";
    cin >> nomor;


    infotype cari;
    cari.nopol = nomor;
    address P = cariNopol(L,cari);
    if(P != NULL){
        cout << "Nomor polisi   : " << P->info.nopol<< endl;
        cout << "Warna          : " << P->info.warna<<endl;
        cout << "Tahun          : " << P->info.thnBuat<<endl;
    }else{
        cout << "Data tidak ditemukan";
    }
```
##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan6_Modul6/Output-Unguided1-2.png)

```C++
    cout << "Masukkan nomor polisi yang dihapus :";
    cin >> nomor;
    infotype hapus;
    hapus.nopol = nomor;
    deleteByNopol(L,hapus);
    printInfo(L);
```
##### Output 3
![Screenshot Output Unguided 1_3](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan6_Modul6/Output-Unguided1-3.png)

penjelasan unguided 1 
Program ini meminta user memasukkan nomor polisi, warna, tahun kendaraan. lalu, sistem akan mencari dan delete nopol yg dimasukkan user.

didalamnya ditulis code yg sudah diberikan soal berupa pesducode nya. 

langkah pertama :
buat struct dengan nama kendaraan didalamnya diisi, string nopol, string warna, int thnBuat.
langkah 2: buat typedef kendaraan dengan tipe data infotype, lalu, buat pointer Elmlist menuju address. typedef struct ELmlist *address 
langkah 3: buat struct Elmlist berisi infotype info, address next, address prev.
langkah 4: buat struct list berisi address list, address last.
langkah 5: 
bool isEmpty(List L); -> untuk memeriksa apakah lis kosong/ tidak.
void CreateList(List &L); -> buat list.
address alokasi(infotype x); -> buat meng-alokasikan node nya.
void dealokasi(address &P); -. untuk menghapus node.
void printInfo(List L); -> untuk print list nya

void insertLast(List &L, address P); -> untuk menyisipkan list di terakhir
address cariNopol(List L, infotype x); -> variabel untuk menyimpan cari nomor polisi.
void deleteFirst(List &L, address P); -> untuk menghapus list pertama.
void deleteLast(List &L, address P); -> untuk menghapus list terakhir.
void deleteAfter(address Prec, address &P); -> untuk menghapus list setelahnya.
void deleteByNopol(List &L, infotype x); -> untuk menghapus list dari nomor polisi nya.

Untuk bagian :
bool isEmpty(List L);
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L); 

Penjelasannya sama seperti guided-guided sebelumnya, untuk mengecek tiap-tiap list yg ada dan mengalokasi kannya lalu, menghapus node nya.

Untuk bagian : 
void insertLast(List &L, address P);
didalamnya dicek isEmpty nya.

address cariNopol(List L, infotype x);
didalamnya buat variabel address P = List pertama, ketika P tidak sama dengan 0, jika P nopol nya == x nopoll return P, dan P = P selanjutnya.

void deleteFirst(List &L, address P);
dicek isEmpty nya lalu, buat variabel address pDel = list pertama, jika List pertama == list terakhir = 0, tetapi list pertama = list pertama selanjutnya. dan list pertama sebelumnya = 0 maka akan ter-delete.

void deleteLast(List &L, address P);
dicek isEmpty nya lalu, buat variabel pDel = list terakhir, jika list pertama = ;ist terahir, tetapi list pertama = list terkahir sebelumnya, selanjutnya =0, lalu, pDel selanjutnya = 0 maka akan ter-delete list terakhirnya.

void deleteAfter(address Prec, address &P);
dicek menggunakan P = prec selanjutnya. jika P tidak sama dengan 0, prec selanjutnya = p selanjutnya, jika p sleanjutnya tidak smaa dengan 0, prev nya = prec, taapi, prec selanjutnya = 0

void deleteByNopol(List &L, infotype x);
buat variabel address P = panggil cari nopol nya, lalu buat variabel address prec. jika P == 0 return, jika P== list prtama delete l,p. tetapi jika P == list terakhir delete last nya, tapi prec = p prev maka delete after.

di main.cpp
buat inputtan untuk user masukkan jumlahnya berpaa, dan akan dilakukan perulangan kepada user untuk men-inputkan sejumlah yg diinputkan dan apabila nomor nya sama dengan yg diinputkan akan tercetak nopol sudah terdaftar,
buat inputtan untuk user masukkan nopol yg dicari, apabila inputkan tapi nopol tidak ada di data maka akan tercetk data tidak ditemukan.
buat inputtan user untuk masukkan nopol yg dihapus.

## Kesimpulan
Penambahan address first dan last serta address prev pada setiap node mempercepat proses manipulasi dan traversal pada kedua sisi list, terutama untuk aplikasi yang membutuhkan akses cepat ke kedua ujung struktur data. Dengan demikian, efisiensi operasi pada DLL memang jauh lebih unggul secara teoritis dan implementatif dibanding SLL

## Referensi
[1] Agung Wijoyo https://jurnalmahasiswa.com/index.php/jriin/article/view/1282 
<br>[2] Daismabali.com  https://daismabali.com/artikel_detail/63/1/Memahami-Doubly-Linked-List-dalam-Struktu-Data-dengan-mudah.html
