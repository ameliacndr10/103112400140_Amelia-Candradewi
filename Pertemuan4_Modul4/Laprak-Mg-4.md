# <h1 align="center">Laporan Praktikum Modul 4 SINGLY LINKED LIST (BAGIAN PERTAМА)</h1>
<p align="center">Amelia Candradewi - 103112400140</p>

## Dasar Teori
Linked list adalah salah satu struktur data dasar dalam pemrograman yang terdiri dari serangkaian elemen data yang terhubung satu sama lain menggunakan referensi atau pointer. Setiap elemen dalam linked list, yang disebut node, Setiap node dalam linked list terdiri dari dua komponen utama: data dan pointer. Komponen data menyimpan nilai atau informasi yang ingin kita simpan dalam linked list. Node pertama dalam linked list disebut head, dan node terakhir disebut tail. Head menyimpan referensi ke node pertama, sedangkan tail menyimpan referensi ke node terakhir. Dengan menggunakan head, kita dapat mengakses elemen pertama dalam linked list dan melakukan operasi seperti penambahan, penghapusan, atau pencarian data.

Salah satu keunggulan utama linked list adalah kemampuannya untuk mengatasi perubahan ukuran secara dinamis. Ketika kita ingin menambahkan atau menghapus elemen dari linked list, kita dapat melakukannya dengan mudah tanpa mempengaruhi elemen-elemen lain dalam struktur data tersebut. [1]

Adapun jenis-jenis linked list :
1. Singly linked list

struktur data di mana setiap elemen (node) memiliki dua bagian: data yang disimpan dan referensi ke node berikutnya dalam urutan. Node terakhir memiliki nilai NULL sebagai referensi akhir. Operasi seperti penambahan dan penghapusan bisa cepat di awal (head), tetapi lambat di akhir (tail). [1]

Lalu, Insert Single linked list adalah Penyisipan setelah simpul tertentu pada posisi tertentu memerlukan penelusuran daftar hingga posisi yang diinginkan tercapai.[2]

## Guided 

### 1. Insert Single linked list

###list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL 

#include <iostream>
using namespace std;
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 

typedef struct node *address; 
struct node{ 
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist list);
void createList(linkedlist &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &List,address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prey);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

###list.cpp
```C++
#include "list.h"
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
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) { 
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

###main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
penjelasan singkat guided 1
Kita membuat program isi list setelah dilakukan insert

Pertama kita buat file list.h
langkah pertama: buat header guard nya 
#ifndef
#define 
#define
langkah 2: buat struct mahasiswa, untuk isi data struct mahasiswa. nama, nim, umur
langkah 3: buat typedef untuk menyederhanakan sintaks struct dan memberikan nama alias untuk struct mahasiswa
langkah 4: buat typedef pointer ke struct node
langkah 5: buat struct node untuk list dari linked list nya, isi setiap node adalah data* pointer
langkah 6: buat struct linkedlist, isinya address first
langkah 7: 
tulis semua function dan prosedur yang akan dipakai :
bool isEmpty(linkedlist list); -> untuk memeriksa apakah linkedlist kosong atau tidak
void createList(linkedlist &list); -> untuk memastikan daftar berada dalam keadaan kosong 
address alokasi(string nama, string nim, int umur); -> untuk mengalokasikan memori baru di heap untuk satu buah node. address alias untuk pointer ke node
void dealokasi(address &node); -> untuk membebaskan memori dari sebuah node tertentu yang sudah tidak digunakan lagi
void printList(linkedlist list); -> untuk mencetak semua elemen data yang tersimpan didalam linkedlist, dimulai dari node pertama hingga node terakhir
Buat prosedur untuk insert first,after, last
void insertFirst(linkedlist &List,address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prey);
void insertLast(linkedlist &List, address nodeBaru);

Kedua buat file list.cpp
panggil list.h nya
langakah 2: isi fungsi bool isEmpty fungsi ini untuk mengecek apakah list kosong atau tidak
langkah 3: buat struct untuk linked list kosong
langkah 4: buat node baru dengan menerapkan manajemen memori, isinya nama, nim, umur.
nodeBaru diberi variabel new node, di nodeBaru dipanggil nama, lalu nim, lalu umur, nodeBaru next nya adalah Nil(0)
buat prosedur untuk penghapusan node dengan menerapkan manajemen memori yang diberi nama dealokasi. berisi address &node 
buat prosedur-prosedur untuk insert / menambahkan node baru kedalam list.
InsertFirst untuk menempatkan elemen list node pada awal list
InsertAfter untuk nodeBaru, dan Prev alamat salah satu elemen list. apabila Prev tidak kosong maka akan ditempatkan setelah prev next yaitu nodeBaru. 
InsertLast untuk menempatkan elemen nodeBaru pada akhir list
PrintList untuk menampilkan isi list

Ketiga buat file main.cpp
panggil list.h
di int main diisi linkedlist list, alamat nodeA,nodeB,nodeC,nodeD, nodeE = Nill, dataMahasiswa sebagai mhs
langkah 2: buat data dummy untuk node tersebut dan panggil alokasi.
langkah 3: panggil insertFirst disertai isi linkedlist dan address nya
langkah 3: printList nya.
### 2. Insert Single linked list (delete isi nya)

###list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL 

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address; 

struct node{ 
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist list);
void createList(linkedlist &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &List,address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

###list.cpp

```C++
#include "list.h"
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
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

###main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
penjelasan singkat guided 2
Penjelasannya sama seperti guided 1 tetapi ada beberapa penambahan

file list.h
penambahan fungsi isEmpty untuk mengecek apakah list kosong atau tidak.
Lalu, penambahan deleteFirst,Last,After, delete list dan juga nbList
deleteFirst digunakan untuk menghapus isi list pertama.
deleteLast digunakan untuk menghapus isi list terakhir.
deleteAfter digunakan untuk menghapus isi list setelahnya.
nbList digunakan untuk melihat berapa banyak node
deleteList digunakan untuk menghapus list

file list.cpp
penambahan bagian isEmpty, jika listFirst = 0 maka akan lanjut
penambahan deleteFirst dengan parameter linkedlist &List, address nya nodeHapus. menggunakan if else, jika isEmpty nya false nodeHapus nya list pertama, list pertama = list selanjutnya. nodeHapus selanjutnya = Nil, panggil dealokasi nodeHapus, kalau true list kosong

penambahan deleteLast parameter linkedlist &List, menggunakan if else while, address nya nodeHapus, nodeprev. jika is Empty == false nodeHapus = list pertama, jika node hapus selanjutnya == Nill, List pertama selanjutnya ==Nill, dealokasi nodeHapus. tetapi ketika node hapus selanjutnya tidak sama dengan Nill nodePrev = nodeHapus, nodeHapus = nodeHapus selanjutnya. dan di dealokasi di nodeHapus

penambahan deleteAfter diisi parameter linkedlist&List, address nya nodeHapus, nodePrev. Pakai if else, jika isEmpty berisi list == true ter-print List kosong!. tetapi jika list tidak kosong di cek, jika node sebelumnya tidak 0 dan node setelahnya tidak 0, nodeHapus = nodePrev selanjutnya = nodeHapus setelahnya = Nill, dealokasi berisi nodeHapus

penambahan printList parameter diisi linkedlist List, memakai if else while. jika isEmpty isinya List ter-print List kosong, tetapi alamat nodeBantu = List pertama, ketika nodeBantu tidak sama dengan Nil, akan ter-print Nama, Nim, Usia dipanggil isidata.nama, isidata.nim, isidata.umur. nodeBantu = nodeBantu selanjutnya.

panggil nbList disi parameter nya linkedlist List, buat count = 0, address nya nodeBantu = List pertama, ketika nodebantu tidak sama dengan 0  isi nodeBantu selanjutnya


## Unguided 

### 1. ![Screenshot soal1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan4_Modul4/soal1.png)

###Singlylist.h
```C++
#ifndef SINGLYLIST 
#define SINGLYLIST

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList{
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

###Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;


void CreateList(List &L){
    L.First = NULL;
}

address alokasi(infotype x){
    address nodeBaru = new ElmList;
    nodeBaru->info = x;
    return nodeBaru;
}
void dealokasi(address P){
    P->next = NULL;
    delete P;
}

void printInfo(List L){
    if(L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        while (nodeBantu != NULL){
            cout << nodeBantu->info << " ";
            nodeBantu = nodeBantu->next;
        }
    }
}
void insertFirst(List &L, address P){
    P->next = L.First;
    L.First = P;
}
```

###main.cpp
```C++
#include "Singlylist.h"

#include <iostream>
using namespace std;

int main(){
    List L;
    address P1, P2, P3, P4, P5 = NULL;
    CreateList(L);
    
    P1 = alokasi (2);
    insertFirst(L,P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L,P3);
    P4 = alokasi(12);
    insertFirst(L,P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :
![Screenshot Output Unguided 1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan4_Modul4/Output-Unguided1.png)

penjelasan unguided 1 
Buat program single linked list  dan menampilkan list 

Langkah pertama Buat file Singlylist.h
isi nya mendefinisikan int sebagai infotype, ElmList sebagai struct nilai address
lalu buat, struct ElmList isinya infotype info, next sebagai address
lalu, buat struct List isinya address first.

buat, prosedur CreateList berisi nilai List &L, buat addres alokasi berisi infotype x, buat prosedur dealokasi berisi address P, buat prosedur printInfo berisi List L, buat insert First berisi  List &L, address P

Langkah 2 Buat file Singlylist.cpp
panggil Singlylist.h

buat prosedur CreateList parameter List &L, isinya L pertama = NULL.
buat function address alokasi parameter berisi infotype x, isinya address nodebaru = new ElmList.
buat address alokasi parameter berisi x, isi address alokasi nodeBaru = new Elmlist. nodeBaru nya info = x, kembalikan nilai nodeBaru.
buat prosedur dealokasi  parameter P. isi prosedur nya P selanjutnya berisi 0 lalu, hapus nilai P
buat printInfo parameter berisi list L. mengguanakn if-else-while. jika L pertama berisi 0, print list masih kosong, jika address nodeBantu = Lpertama ketika nodeBantu tidak sama dengan 0, print nodeBantu info print spasi " ", untuk nodeBantu selanjutnya.
buat insertFirst parameter berisi List &L, address P, isi nya P selanjutnya = Lpertama, nilainya adalah P.

Langkah 3 Buat file main.cpp
panggil Singlylist.h

buat int main(), isi nya List L, address P1,P2,P3,P4,P5 = 0, CreateList(L)

buat dummy untuk alokasi nilai nya, dan panggil alokasi, lalu, insertFirst(L,address), lalu, printInfo(L).

### 2.Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node
2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan
jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh
node menggunakan deleteList().
Output yang diharapkan :
12 0
Jumlah node : 2
- List Berhasil Terhapus –
Jumlah node : 0

###Singlylist.h
```C++
#ifndef SINGLYLIST 
#define SINGLYLIST

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList{
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address P, address Q);
int nbList(List L);
void deleteList(List &L);

#endif
```

###Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;


void CreateList(List &L){
    L.First = NULL;
}

address alokasi(infotype x){
    address nodeBaru = new ElmList;
    nodeBaru->info = x;
    return nodeBaru;
}
void dealokasi(address &P){
    P->next = NULL;
    delete P;
}

void printInfo(List L){
    if(L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        while (nodeBantu != NULL){
            cout << nodeBantu->info << " ";
            nodeBantu = nodeBantu->next;
        }
    }
}
void insertFirst(List &L, address P){
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L){
    address P;

    if(L.First== NULL){
        cout<< "list masih kosong";
    }else{
        P = L.First;
        L.First = L.First->next;
        P->next = NULL;
        dealokasi (P);
    }
}
void deleteLast(List &L){
    address P, Q;

    if (L.First == NULL)
    { 
    cout<< "list masih kosong";
    }else{
        P = L.First;
        if (P->next == NULL){
            P->next = NULL;
            dealokasi (P);
        }else{
            while (P->next !=NULL)
            {
                Q = P;
                P = P->next;
            }
            Q->next = NULL;
            dealokasi(P);
        }
    }
    
}
void deleteAfter(List &L, address P, address Q){
    if(L.First == NULL){
        cout << "list masih kosong";
    }else{
        if ( Q != NULL && Q->next != NULL){
            P = Q->next;
            Q->next = P->next;
            P->next = NULL;
            dealokasi(P);
        }else{
            cout << "Node sebelum, (prev) tidak valid";
        }
    }
}
int nbList(List L){
    int count = 0;
    address P = L.First;
    while (P != NULL)
    {
        count++;
        P = P->next;
    }
    return count;
}
void deleteList(List &L){
    address nodeBantu,P;
    nodeBantu = L.First;
    while (nodeBantu != NULL)
    {
        P = nodeBantu;
        nodeBantu= nodeBantu->next;
        dealokasi(P);
    }
    L.First = NULL;
    cout << "List sudah terhapus" << endl;
}
```

###main.cpp
```C++
#include "Singlylist.h"

#include <iostream>
using namespace std;

int main(){
    List L;
    address P1, P2, P3, P4, P5 = NULL;
    CreateList(L);
    
    P1 = alokasi (2);
    insertFirst(L,P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L,P3);
    P4 = alokasi(12);
    insertFirst(L,P4);
    P5 = alokasi(9);
    insertFirst(L, P5);


    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L,P3,P4);

    printInfo(L);
    cout << endl;
    cout << "jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "jumlah node : " << nbList(L) << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan4_Modul4/Output-Unguided2.png)

penjelasan unguided 2
Buat program single linked list menampilkan list yang telah di delete.

Langkah pertama Buat file Singlylist.h
isi nya mendefinisikan int sebagai infotype, ElmList sebagai struct nilai address
lalu buat, struct ElmList isinya infotype info, next sebagai address
lalu, buat struct List isinya address first.

buat, prosedur CreateList berisi nilai List &L, buat addres alokasi berisi infotype x, buat prosedur dealokasi berisi address P, buat prosedur printInfo berisi List L, buat insert First berisi  List &L, address P

Ada penambahan prosedur untuk delete
buat prosedur, Prosedur yang berisi parameter List &L yaitu deleteFirst,deleteLast,deleteList. untuk prosedur deleteAfter berisi parameter List &L, address P, address Q, prosedur nbList parameter berisi List L

Langkah kedua Buat file Singlylist.cpp
panggil Singlylist.h

buat prosedur CreateList parameter List &L, isinya L pertama = NULL.

buat function address alokasi parameter berisi infotype x, isinya address nodebaru = new ElmList.

buat address alokasi parameter berisi x, isi address alokasi nodeBaru = new Elmlist. nodeBaru nya info = x, kembalikan nilai nodeBaru.

buat prosedur dealokasi  parameter P. isi prosedur nya P selanjutnya berisi 0 lalu, hapus nilai P.

buat printInfo parameter berisi list L. mengguanakn if-else-while. jika L pertama berisi 0, print list masih kosong, jika address nodeBantu = Lpertama ketika nodeBantu tidak sama dengan 0, print nodeBantu info print spasi " ", untuk nodeBantu selanjutnya.

buat insertFirst parameter berisi List &L, address P, isi nya P selanjutnya = Lpertama, nilainya adalah P.

buat deleteFirst berisi address P, menggunakan if else. Jika L pertama = 0 print list, tetapi P berisi nilai L pertama, L pertama selanjutnya. jadi P selanjutnya = 0 maka akan terhapus list pertama.

buat deleteLast berisi address P,Q. menggunakan if else while. jika Lpertama = 0 ter-print list masih kosong, tapi, P = nilai list pertama jika P selanjutnya 0 dealokasi nilai P, ketika P selanjutnya tidak sama dengan 0, nilai Q =nilai P, P  merupakan P selanjutnya. jadi nilai Q selanjutnya = 0 maka terhapus list terakhir.

buat deleteAfter didalamnya menggunakan if else. jika L pertama = 0, ter-print list masih kosong. tapi jika Q tidak sama dengan 0 && Q next tidak sama dengan 0 juga, nilai P = Q selanjutnya = P selanjutnya = 0. dealokasi nilai P. maka akan terhapus list setelahnya.

buat delete list menggunakan while. address nodeBantu,P. nodeBantu = L pertama, ketika nodeBantu tidak sama dengan 0, nilai P = nodeBantu, nodeBantu = nodeBantu selanjutnya. kemudian dealoaksi nilai P .

Langkah ketiga Buat file main.cpp
panggil Singlylist.h

buat int main(), isi nya List L, address P1,P2,P3,P4,P5 = 0, CreateList(L)

buat dummy untuk alokasi nilai nya, dan panggil alokasi, lalu, insertFirst(L,address). 

ada penambahan deleteFirst berisi L, deleteLAst berisi L, deleteAfter berisi L,P3,P4.

lalu, printInfo berisi L, print output yang sudah di hapus


## Kesimpulan
Linked List: Struktur Data Dinamis dan Fleksibel

Linked list adalah struktur data fundamental yang terdiri dari serangkaian elemen data, yang disebut node, dihubungkan melalui referensi atau pointer. Setiap node memiliki dua bagian: data (nilai yang disimpan) dan pointer (referensi ke node berikutnya).

Akses: Node pertama disebut head , yang merupakan titik masuk untuk mengakses dan memanipulasi elemen dalam daftar. Node terakhir disebut tail.

Keunggulan: Keunggulan utama linked list adalah kemampuannya untuk mengatasi perubahan ukuran secara dinamis, memungkinkan penambahan atau penghapusan elemen dengan mudah tanpa mempengaruhi elemen lain.

## Referensi
[1] A. Faizul Akabar. (2023) https://terapan-ti.vokasi.unesa.ac.id/post memahami-konsep-dan-jenis-jenis-linked-list-dalam-struktur-data
<br>[2] https://medium.com/@itsanuragjoshi/insert-an-element-in-a-linked-list-data-structures-algorithm-2a41d01afc24 
