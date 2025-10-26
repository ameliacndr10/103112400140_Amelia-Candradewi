# <h1 align="center">Laporan Praktikum Modul 5 SINGLY LINKED LIST (BAGIAN KEDUA)</h1>
<p align="center">Amelia Candradewi- 103112400140</p>

## Dasar Teori
Linked list adalah salah satu struktur data dasar dalam pemrograman yang terdiri dari serangkaian elemen data yang terhubung satu sama lain menggunakan referensi atau pointer. Setiap elemen dalam linked list, yang disebut node, Setiap node dalam linked list terdiri dari dua komponen utama: data dan pointer. Komponen data menyimpan nilai atau informasi yang ingin kita simpan dalam linked list. Node pertama dalam linked list disebut head, dan node terakhir disebut tail. Head menyimpan referensi ke node pertama, sedangkan tail menyimpan referensi ke node terakhir. Dengan menggunakan head, kita dapat mengakses elemen pertama dalam linked list dan melakukan operasi seperti penambahan, penghapusan, atau pencarian data.

Salah satu keunggulan utama linked list adalah kemampuannya untuk mengatasi perubahan ukuran secara dinamis. Ketika kita ingin menambahkan atau menghapus elemen dari linked list, kita dapat melakukannya dengan mudah tanpa mempengaruhi elemen-elemen lain dalam struktur data tersebut. [1]

Singly linked list merupakan struktur data di mana setiap elemen (node) memiliki dua bagian: data yang disimpan dan referensi ke node berikutnya dalam urutan. Node terakhir memiliki nilai NULL sebagai referensi akhir. Operasi seperti penambahan dan penghapusan bisa cepat di awal (head), tetapi lambat di akhir (tail). [1]
Lalu, Insert Single linked list adalah Penyisipan setelah simpul tertentu pada posisi tertentu memerlukan penelusuran daftar hingga posisi yang diinginkan tercapai.[2]
Modul 5 Singly Linked List (Bagian Kedua) ini berfokus pada teori lanjutan, seperti search dan update[2].

Update pada linked list merupakan update data dalam list yang bisa dilakukan di awal(Update First), akhir (Update Last) atau Update After

Searching pada linked list merupakan mencari data dalam list bisa dilakukan dengan nilai data, address dan range[3].

implementasi efektif dari Singly Linked List dalam C++—termasuk mekanisme Search by Data dan Update After—menegaskan bahwa struktur ini adalah alat yang fleksibel dan efisien, asalkan batasan aksesnya dipahami dan diterapkan secara tepat dalam konteks pemrograman.

## Guided 

### 1. Update dan Find single lingked list

### listBuah.h
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; 

typedef struct node *address; 

struct node{ 
    dataBuah isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

### listBuah.cpp
```C++
#include "listBuah.h"
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

address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
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
        cout << "Node pertama berhasil terhapus!" << endl;
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
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
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
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
    cout << "List berhasil terhapus!" << endl;
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

```

### main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

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
penjelasan singkat guided 1
Pada bagian kedua ini ada nya penambahan function update dan Find.
void updateFirst digunakan untuk meng-update list pertama.
void updateLast digunakan untuk meng-update list terakhir.
void updateAfter(linkedlist List, address prev) digunakan untuk meng-update list setelahnya dan menggunakan parameter address preview.

void FindNodeByData digunakan untuk mencari node berdasarkan data nya.
void FindNodeByAddress digunakan untuk mencari node berdasarkan alamat nya.
void FindNodeByRange digunakan untuk mencari node berdasarkan range data nya.

## Unguided 

### 1. Membuat ADT Singly Linked list, kemudian carilah elemen dengan info 8 dengan membuat fungsi findElm dan hitunglah jumlah total info seluruh elemen

### Singlylist.h
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

bool isEmpty(List L);
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
void penjumlahan(List L);

#endif
```
### Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

bool isEmpty(List L){
    if(L.First == NULL){
        return true;
    }else{
        return false;
    }
}
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
        cout << endl;
    }
}
void insertFirst(List &L, address P){
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x){
    if (isEmpty(L) == true ){
        cout << "List kosong!" << endl;
    }else{
        address nodeBantu = L.First;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != NULL){
            posisi++;
            if(nodeBantu->info == x){
                cout << x << " ditemukan dalam list" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
    }
}

void penjumlahan(List L){
    if(L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        int P = 0;
        while (nodeBantu != NULL){
            P += nodeBantu->info;
            nodeBantu = nodeBantu->next;
        }
        cout << "Total info dari kelima elemen adalah " << P << endl;
        cout << endl;
    }
}
```

### main.cpp
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

    findElm(L,8);
    penjumlahan(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan5_Modul5/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan5_Modul5/Output-Unguided1-2.png)

##### Output 3
![Screenshot Output Unguided 1_3](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan5_Modul5/Output-Unguided1-3.png)

##### Output 4
![Screenshot Output Unguided 1_4](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan5_Modul5/Output-Unguided1-4.png)

penjelasan unguided 1 
Program ini meminta untuk membuat ADT Singly linked list, kemudian mencari elemen dengan info 8 dengan membuat fungsi findElm dan hitunglah jumlah total info seluruh elemen.

Pertama kita buat file list.h
langkah pertama: buat header guard nya 
#ifndef
#define
langkah 2: buat typedef untuk Mendefinisikan tipe data baru bernama infotype yang merupakan alias untuk tipe data primitif int(integer).
langkah 3: buat typedef untuk Mendefinisikan tipe data baru bernama address yang merupakan alias untuk pointer yang menunjuk ke struktur struct ElmList.
langkah 4: buat struct ElmList yang berisi Setiap struct ElmList adalah sebuah Node. Node ini memiliki nilai (info) dan penunjuk (next) yang mengarah ke node selanjutnya.
langkah 5: buat struct List yang berisi address pertama
langkah 6: 
tulis semua function dan prosedur yang akan dipakai :
bool isEmpty (List L); -> untuk memeriksa apakah linkedlist kosong atau tidak.
void createList(List &L); -> untuk memastikan daftar berada dalam keadaan kosong 0.
address alokasi(infotype x) -> untuk mengalokasikan memori baru di head untuk satu buah node. address alias untuk pointer ke node
void dealokasi(address P); -> untuk membebaskan memori dari sebuah node tertentu yang sudah tidak digunakan lagi
void printInfo(List L); -> untuk mencetak semua elemen data yang tersimpan didalam linkedlist, dimulai dari node pertama hingga node terakhir
Buat prosedur untuk insert first
void insertFirst(List &L, address P); -> untuk menyisipkan list di list pertama.

Terjadi beberapa penambahan 
Penambahan 1 :
address findElm(List L, infotype x); -> membuat address berupa findElm didalamnya diisi parameter List L, infotype yang di inisialisasi variabel x. memakai address karena kita ingin mengembalikan nilai alamat memori yang didalamnya berupa isi List nya dan angka.

Penambahan 2:
prosedure penjumlahan(List L) -> untuk menghitung penjumlahan isi list nya

Kedua buat file Singlylist.cpp
panggil Singlylist.h nya
langkah pertama: isi fungsi bool isEmpty fungsi ini untuk mengecek apakah list kosong atau tidak
langkah 2: CreateList dengan parameter List &L didalamnya L.First = 0. memastikan list pertama keadaan = 0.
langkah 3: address alokasi dengan parameteer infotype x. didalamnya disi nodeBaru diberi variabel new ElmList, di nodeBaru dipanggil info = 0, kembalikan nilai nodeBAru.
langkah 4: prosedur dealokasi dengan parameter address P. didalamnya diisin P selanjutnya = 0 lalu hapus nilai P.
langkah 5: printInfo dengan parameter list L. untuk menampilkan isi list nya. 
langkah 6: insertFirst dengan parameter List &L, address P. didalmnya P selanjutnya = List pertama, List pertama = P.

Penambahan 1:
langkah 7: findElm dengan parameter List L, infortype x. menggunakan if-else-while. jika isEmpty(L) nya true print "List kosong, tapi jika, address nodeBantu = List pertama, posisi dimulai dari 0, bool found nya false, ketika nodeBAntu tidak sama dengan 0, maka nodeBantu info == x print ditemukan dalam list jika found nya true, jika false tadi maka, nodeBAntu = nodeBantu selanjutnya.

Penambahan 2:
langkah 8: penjumlahan dengan parameter List L. menggunakan if-else-while. jika L pertama = 0 print list masih kosong. tapi address nodeBAntu = L pertama, P = 0, ketika nodeBantu tidak sama dengan 0, nilai P akan ditambah dan nodeBantu info yang sudah di cek akan disimpan dan ditambahkan lalu, nodeBantu selanjutnya juga akan dimasukkan ke penjumlahan tersebut. lalu, diluar while akan ter-output hasil dari Total info dar kelima elemen adalah, dengan memanggil nilai P.

Ketiga buat file main.cpp
panggil Singlylist.h
di int main diisi List L, address P1,P2,P3,P4,P5 = 0, CreateList(L)
langkah 2: buat data dummy untuk node tersebut dan panggil alokasi.
langkah 3: panggil insertFirst disertai isi List dan address nya
langkah 4: printInfo nya.
langkah 5: panggil findElm disertai isi List dan address data dummy nya.
langkah 6: panggil penjumlahan disertai isi List nya
return 0

### 2. Membuat ADT Singlly linked list, lalu buat procedure updateFirst, updateLast, updateAfter, lalu cari prosedur' Buat procedure SearchByData, SearchByAddress, SearchByRange dan lakukan operasi aritmatika penjumlahan, pengurangan dan perkalian

### ListAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka Angka;
    address next;
};

struct linkedList {
    address First;
};

bool isEmpty(linkedList L);
void CreateList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(linkedList L);
void insertFirst(linkedList &L, address nodeBaru);
void insertLast(linkedList &L, address nodeBaru);
void insertAfter(linkedList &L, address nodeBaru, address nodePrev);
void delAfter(linkedList &L, address nodeHapus, address nodePrev);
// int nbList(linkedList L);

void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address nodePrev);

void SearchByData(linkedList L, int data);
void SearchByAddress(linkedList L, address node);
void SearchByRange(linkedList L, int nilaiMin);

void penjumlahan(linkedList L);
void pengurangan(linkedList L);
void perkalian(linkedList L);
#endif
```

### ListAngka.cpp
```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList L) {
    if(L.First == NULL){
        return true; 
    } else {
        return false;
    }
}

void CreateList(linkedList &L){
    L.First = NULL;
}
address alokasi(dataAngka x){
    address nodeBaru = new node;
    nodeBaru->Angka = x;
    nodeBaru->next =NULL;
    return nodeBaru;
}
void dealokasi(address &node){
    node->next= NULL;
    delete node;
}

void printList(linkedList L){
    if(L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        while (nodeBantu != NULL){
            cout << nodeBantu->Angka << "-";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}
void insertFirst(linkedList &L, address nodeBaru){
    nodeBaru->next = L.First;
    L.First = nodeBaru;
}
void insertLast(linkedList &L, address nodeBaru){
    if (isEmpty(L)) {
        L.First = nodeBaru;
    } else {
        address nodeBantu = L.First;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}
void insertAfter(linkedList &L, address nodeBaru, address nodePrev){
    if (nodePrev != NULL) {
        nodeBaru->next = nodePrev->next;
        nodePrev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}
void delAfter(linkedList &L, address nodeHapus, address nodePrev){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != NULL && nodePrev->next != NULL) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = NULL;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->Angka << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void updateFirst(linkedList &L){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        cin >> L.First->Angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList &L){
    if (isEmpty(L) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : "<< " : " << endl;
        cout << "Nama Angka: ";
        cin >> nodeBantu->Angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList &L, address nodePrev){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != NULL && nodePrev->next != NULL){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node : " << nodePrev->Angka << endl;
            cout << "Nama Angka : ";
            cin >> nodePrev->next->Angka;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
    }
}

void SearchByData(linkedList L, int data){
        if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != NULL){
            posisi++;
            if(nodeBantu->Angka == data){
                found = true;
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void SearchByAddress(linkedList L, address node){
    if(isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != NULL) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}
void SearchByRange(linkedList L, int nilaiMin){
    if(isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas nilai" << nilaiMin << "---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != NULL) {
            posisi++;
            int A = nodeBantu->Angka;
            if( A >= nilaiMin ) {
                cout << "Data ditemukan pada posisi ke- " << posisi << ",nilai :" << nodeBantu->Angka << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data angka dalam range nilai tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

void penjumlahan(linkedList L){
    if( L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        int P = 0;
        while (nodeBantu != NULL){
            P += nodeBantu->Angka;
            nodeBantu = nodeBantu->next;
        }
        cout << "Total penjumlahan : " << P << endl;
        cout << endl;
    }
}
void pengurangan(linkedList L){
    if(L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        int P = L.First->Angka;
        while (nodeBantu != NULL){
            P -= nodeBantu->Angka;
            nodeBantu = nodeBantu->next;
        }
        cout << "Total pengurangan :" << P << endl;
        cout << endl;
    }
}

void perkalian(linkedList L){
    if (L.First == NULL){
        cout << "list masih kosong";
    }else{
        address nodeBantu = L.First;
        int P = 1;
        while (nodeBantu != NULL)
        {
            P*= nodeBantu->Angka;
            nodeBantu = nodeBantu->next;
        }
        cout << "Total perkalian :" << P << endl;
        cout << endl;
    }
}
```

### main.cpp
```C++
#include "ListAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedList L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = NULL;
    CreateList(L);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L,nodeF);
    delAfter(L, nodeB, nodeC);
    printList(L);
    
    updateFirst(L);
    updateAfter(L,nodeD);
    updateLast(L);
    updateAfter(L, nodeF);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(L);

    SearchByData(L, 20);
    SearchByData(L, 55);
    SearchByAddress(L, nodeB);
    SearchByAddress(L, nodeA);
    SearchByRange(L, 40);

    penjumlahan(L);
    pengurangan(L);
    perkalian(L);

    cout << endl;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan5_Modul5/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan5_Modul5/Output-Unguided2-2.png)

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan5_Modul5/Output-Unguided2-3.png)

penjelasan unguided 2
Program ini Membuat ADT Singlly linked list, lalu buat procedure updateFirst, updateLast, updateAfter, lalu cari prosedur' Buat procedure SearchByData, SearchByAddress, SearchByRange dan lakukan operasi aritmatika penjumlahan, pengurangan dan perkalian

ertama kita buat file list.h
langkah pertama: buat header guard nya 
#ifndef
#define
langkah 2: buat typedef untuk Mendefinisikan tipe data baru bernama dataAngka yang merupakan alias untuk tipe data primitif int(integer).
langkah 3: buat typedef untuk Mendefinisikan tipe data baru bernama address yang merupakan alias untuk pointer yang menunjuk ke struktur struct node.
langkah 4: buat struct node yang berisi Setiap struct node adalah sebuah node. Node ini memiliki dataAngka Angka dan penunjuk (next) yang mengarah ke node selanjutnya.
langkah 5: buat struct List yang berisi address pertama
langkah 6: 
tulis semua function dan prosedur yang akan dipakai :
bool isEmpty(linkedList L);-> untuk memeriksa apakah linkedlist kosong atau tidak.
void CreateList(linkedList &L);-> untuk memastikan daftar berada dalam keadaan kosong 0.
address alokasi(dataAngka x); -> untuk mengalokasikan memori baru di head untuk satu buah node. address alias untuk pointer ke node
void dealokasi(address &node); -> untuk membebaskan memori dari sebuah node tertentu yang sudah tidak digunakan lagi
void printList(linkedList L); -> untuk mencetak semua elemen data yang tersimpan didalam linkedlist, dimulai dari node pertama hingga node terakhir
Buat prosedur untuk insert first, inserrtLast, insertAfter:
void insertFirst(linkedList &L, address nodeBaru); -> untuk menyisipkan list di list pertama.
void insertLast(linkedList &L, address nodeBaru); -> untuk menyisipkan list terakhir.
void insertAfter(linkedList &L, address nodeBaru, address nodePrev); -> untuk menyisipkan list setelahnya.
void delAfter(linkedList &L, address nodeHapus, address nodePrev); -> untuk menghapus list

Terjadi beberapa penambahan procedure :
Penambahan 1 : update
void updateFirst(linkedList &L); -> untuk men-update di node pertama.
void updateLast(linkedList &L); -> untuk men-update di noe terakhir.
void updateAfter(linkedList &L, address nodePrev); -> untuk men-update di node setelah node

Penambahan 2 : Search
void SearchByData(linkedList L, int data); -> untuk mencari menggunakan data.
void SearchByAddress(linkedList L, address node); -> untuk mencari menggunakan alamat.
void SearchByRange(linkedList L, int nilaiMin); -> untuk mencari nilai node berdasarkan nilai maksimum dan minimum.

Penambahan 3 : aritmatika penjumlahan, pemgurangan, perkalian
void penjumlahan(linkedList L); -> untuk penjumlahan.
void pengurangan(linkedList L); -> untuk pengurangan.
void perkalian(linkedList L); -> untuk perkalian.

Kedua buat file ListAngka.cpp
panggil ListAngka.h nya
langkah pertama: isi fungsi bool isEmpty fungsi ini untuk mengecek apakah list kosong atau tidak
langkah 2: CreateList dengan parameter linkedList &L didalamnya L.First = 0. memastikan list pertama keadaan = 0.
langkah 3: address alokasi dengan parameteer dataAngka x. didalamnya disi nodeBaru diberi variabel new node, di nodeBaru dipanggil Angka = 0, kembalikan nilai nodeBaru.
langkah 4: prosedur dealokasi dengan parameter address &node. didalamnya diisi node selanjutnya = 0, delete node
langkah 5: printList dengan parameter linkedList L. untuk menampilkan isi list nya, dan jangan lupa tanda "-" agar setiap list yg ter-output ada strip nya.
langkah 6: insertFirst dengan parameter linkedList &L, address nodeBaru. didalmnya nodeBaru selanjutnya = L.pertama, List pertama = nodeBaru.
langkah 7: insertLAst dengan parameter linkedlist &L, address nodeBaru. menggunakan if-else-while. jika isEmpty (L) maka L pertama = nodeBAru, tapi adrees nodeBantu = L pertama ketika nodeBantu sleanjutnya tidak sam adengan = maka nodeBAntu akan menajdi selanjutnya.
langkah 8: insertAfter dengan parameter (linkedList &L, address nodeBaru, address nodePrev) menggunakan if-else. jika node sebelumnya tidak 0 maka node baru selanjutnya = node sebelumnya setelahnya = nodeBaru.
langkah 9: delAfter dengan parameter (linkedList &L, address nodeHapus, address nodePrev). menggunakan if-else-if-else. jika list tidak kosong akan dilakukan perbandingan node sbeelunya dan node sebelum setelahnya, akan nodeHapus = nodesebelum selanjutnya = node Hapus setelahnya = 0, dealokasi di nodeHapus. akan ter-output narasi node setelah node panggi; nodePrev.Angka berhasil dihapus.

Terjadi penambahan :
Penambahan 1 : update
langkah 10: updateFirst dengan parameter (linkedList &L). menggunakan if-else. jika isEmpty == true maka list kosong, tapi akan teroutput user diminta untuk masukkan update data node pertama, lalu masukkan angka dengan memanggil L pertama.Angka dan data berhasil diupdate.
langkah 11: updateLast dengan parameter (linkedList &L). mengguankan if-else-while. jika isEmpty == true maka list kosong, tapi address nodeBAntu = L pertama ketika nodeBantu selanjutnya tidak sama dengan 0 nodeBantu = nodeBAntu selanjutnya. dilua while akan teroutput user diminta untuk masukkan update data node terakhir, masukkan nama angka nya dengan memanggil nodeBantu.Angka dan Data berhasil di update.
langkah 12: updateAfter dengan parameter (linkedList &L, address node). mengguankan if-else-while. jika isEmpty == true maka list kosong, tapi address nodePrev tidak sama denagn 0 ddan nodePrev selanjutnya tidak sama dengan 0, address nodeBantu = nodePrev selanjutnya. akan teroutput user diminta untuk men-update data node manggil nodesebelumnya.Angka, lalu masukkan angka panggil nodePrev.next.Angka, lalu data berhasil di update.

Penambahan 2 : Search
langkah 13 dengan data: SearchByData dengan parameter(linkedList L, int data). menggunakan if-else-while-if dan diluar while gunakan if lagi. jika isEmpty == true maka list kosong, tapi address nodeBantu = List pertama, int posisi dimulai dari 0, bool found = false ketika nodeBantu tidak sama dengan 0 dicek jika nodeBantu.Angka == data, found true (ditemukan), akan ter-output pesan data, panggil data nya ditemukan pada posisi ke - panggil posisi nya, dan break berhenti. di while nodeBantu = nodeBantu selanjutnya. dicek lagi apabila found === false maka node dengan data panggil data tidak ditemukan.

langkah 14 dengan alamat nya : SearchByAddress dengan parameter(linkedList L, address node) menggunakan if-else-while-if dan diluar while gunakan if lagi. jika isEmpty == true maka list kosong, tapi address nodeBantu = List pertama, int posisi dimulai dari 0, bool found = false ketika nodeBantu tidak sama dengan 0 dicek jika nodeBantu == node, akan ter-output pesan node ditemukan pad aposisi ke - panggil posisi lalu, alamat node panggil nodeBantu dan break. di while ketidak tidak sama dengan 0 nodeBAntu = nodeBantu selanjutnya. diluar while dicek if jiak found == fasle maka node dengan alamat m=panggil node tidak ditemukan dalam list.

langkah 15 dengan perbandingan nilai minimum : SearchByRange dengan parameter (linkedList L, int nilaiMin). menggunakan if-else-while-if lalu diluar while cek guakan if lagi. jika isEmpty == true maka list kosong, tapi address nodeBantu = List pertama, int posisi dimulai dari 0, bool found = false akan teroutput data diatas nilai panggil nilaiMin nya. ketika nodeBAntu tidak sama dengan 0, buat var.a tipe data int untuk perbandingan nilai yaitu = nodeBantu.Angka. jika A >= nilaiMin akan ter-output  data ditemukan pada posisi ke- panggil posisi, nilai : panggil nodeBantu.Angka found == true. diluar while cek found == false akan ter-output tidak ada data angka dlm range nilai tersebut.

Penambahan 3 : 
langkah 16 penjumlahan:  penjumlahan dengan parameter linkedlist L. menggunakan if-else-while. jika L pertama = 0 print list masih kosong. tapi address nodeBAntu = L pertama, P = 0, ketika nodeBantu tidak sama dengan 0, nilai P akan ditambah dan nodeBantu.Angka yang sudah di cek akan disimpan dan ditambahkan lalu, nodeBantu selanjutnya juga akan dimasukkan ke penjumlahan tersebut. lalu, diluar while akan ter-output hasil dari Total penjumlahan :, dengan memanggil nilai P.

langkah 17 pengurangan:  pengurnagan dengan parameter linkedlist L. menggunakan if-else-while. jika L pertama = 0 print list masih kosong. tapi address nodeBantu = L pertama, P = Lpertama.Angka, ketika nodeBantu tidak sama dengan 0, nilai P akan dikurang dan nodeBantu.Angka yang sudah di cek akan disimpan dan ditambahkan lalu, nodeBantu selanjutnya juga akan dimasukkan ke pengurangan tersebut. lalu, diluar while akan ter-output hasil dari Total pengurangan :, dengan memanggil nilai P.

langkah 18 perkalian:  perkalian dengan parameter linkedlist L. menggunakan if-else-while. jika L pertama = 0 print list masih kosong. tapi address nodeBAntu = L pertama, P = 1, ketika nodeBantu tidak sama dengan 0, nilai P akan dikalikan dan nodeBantu.Angka yang sudah di cek akan disimpan dan ditambahkan lalu, nodeBantu selanjutnya juga akan dimasukkan ke perkalian tersebut. lalu, diluar while akan ter-output hasil dari Total perkalian :, dengan memanggil nilai P.

Ketiga buat file main.cpp
panggil ListAngka.h
di int main diisi List L, address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = 0, CreateList(L)
langkah 2: buat data dummy untuk node tersebut dan panggil alokasi.
langkah 3: panggil insertFirst, insertLast, insertAfter,insertFirst,insertLast,insertFirst, delAfter disertai isi List dan address nya
langkah 4: printListnya.

Penambahan
langkah 5: panggil updateFirst, updateAfter,updateLast,updateAfter disertai isi List dan address node nya nya.
langkah 6: akan print Isi list setelah dilakukan update. 
langkah 7: panggil SearchByData,SearchByData disertai isi list, dan data dummy nya
langkah 8: panggil SearchByAddress, SearchByAddress disertai isi list nya dan address node nya.
langkah 9: panggil SearchByRange disertai isi list nya dan data dummy nya.

langkah 10: panggil penjumlahan, pengurangan, perkalian disertai isi list L.
return 0
## Kesimpulan
Singly Linked List adalah struktur data dinamis yang fundamental, dicirikan oleh node yang saling terhubung satu arah melalui pointer (next) dan diakses mulai dari simpul Head. Keunggulan utamanya terletak pada fleksibilitas manajemen memori yang memungkinkan penambahan atau penghapusan elemen secara efisien tanpa menggeser data lain.

Meskipun unggul dalam operasi struktural seperti penyisipan (Insert After) karena hanya memerlukan manipulasi pointer, operasi Search dan Update memiliki keterbatasan kinerja:

Pencarian (Search): Dilakukan melalui penelusuran linier (traversal) dari Head. Fungsi pencarian dapat mengembalikan alamat (address) node yang ditemukan atau NULL.

Update: Memerlukan langkah Search terlebih dahulu untuk menemukan node target sebelum data (info) diubah.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Modul Pembelajaran Struktur Data (2025). Linked List Dasar dengan C++. Fakultas Ilmu Komputer, Universitas X https://www.scribd.com/document/927910910/Modul-Praktikum-Struktur-Data-2025
