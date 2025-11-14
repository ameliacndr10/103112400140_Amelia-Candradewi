# <h1 align="center">Laporan Praktikum Modul 8 QUEUE</h1>
<p align="center">Amelia Candradewi - 103112400140</p>

## Dasar Teori
queue (teori antrian) adalah kajian tentang perilaku sistem layanan di mana entitas (manusia, data, atau objek lain) datang untuk dilayani, menunggu jika layanan sedang sibuk, dan meninggalkan sistem setelah dilayani. Teori ini mencari cara memahami, mengukur, dan mengoptimalkan efisiensi dari sistem pelayanan yang melibatkan antrean, baik dalam pelayanan publik, industri, maupun teknologi informasi.

Penyisipan antrean dalam C++ terjadi di ujung belakang, dan penghapusan terjadi di ujung depan. Ujung belakang atau elemen belakang adalah elemen terakhir dalam antrean. Bagian depan atau elemen depan adalah elemen pada posisi pertama dalam antrean. Sistem nya menggunakan konsep FIFO (First In First Out), Masuk pertama Keluar pertama.

### A. Semua antrian harus :

#### 1. Enqueue: Penambahan elemen di akhir antrean.
#### 2. Dequeue: Penghapusan elemen dari bagian depan antrean.
#### 3. IsEmpty: Pemeriksaan antrean apakah kosong.
#### 4. IsFull: Pemeriksaan antrean apakah penuh.

### Dan juga harus menggunakan function primitif seperti:
#### 1. isEmpty
#### 2. isFull
#### 3. createEnqueu
#### 4. viewQueue


## Guided 

### 1. implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak). (Tanpa array)
### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node{
    string nama;
    Node* next;; 
};

struct queue{
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

### queue.cpp
```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
penjelasan singkat guided 1
Men-implemetasikan ADT Queue tanpa menggunakan array.
Menggunakan function primitif seperti Createqueue, isEmpty,isFull.

Karena ini Queue maka insert dan delete nya menjadi enQueue, deQueue.

Untuk melihat outputnya menggunakan viewEnqueue dan untuk mengosongkan elemen menggunakan clearQueue.

dengan menambahkan data dummy di main, maka saat enQueue data ditambahkan dan saat ingin menghapus menggunakan deQueue.

di queue.cpp 
void enQueue menggunakan if else, dengan mengecek isEMpty dimulai dari Q.head =Q.tail = baru, lalu Q.tail.next = baru, jadi Q.tail = baru.

void deQueue mengecek isEmpty, diluar if buat variabel baru hapus dengan memanggil nilai Node yaitu = Q.head, print "Menghapus data, hapus namanya. lalu, Q.head jadi Q.head.next.
dan di if jika Q.head = NULL, Q.tail = NULL maka hapus


### 2. implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak), Alternatif 2 (head bergerak, tail bergerak), Alternatif 3 (head dan tail berputar) (Menggunakan ARRAY)

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;
struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q); // terbentuk queue dengan head = -1 dan tail =-1
void enQUeue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

### queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

### main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Penjelasan singkat guided 2
Pada guided 2, kita akan implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak), Alternatif 2 (head bergerak, tail bergerak), Alternatif 3 (head dan tail berputar) (Menggunakan ARRAY).

Telah diberikan beberapa contoh saat menggunakan array. Tetatpi dicontoh kita hanya akan menggunakan implementasi 1 yaitu : head diam, tail bergerak. Tabel dengan hanya representasi TAIL adalah indeks elemen terakhir, HEAD selalu di-setsama dengan
1 jika Queue tidak kosong. Jika Queue kosong, maka HEAD=0

kita menggunakan function-function primitif.

1. saat isEmpty menggunakan if-else. jika Q.head == -1 dan Q.tail == -1 akan mengecek apakah beneran kosong atau tidak.
2. saat isFull menggunakan if-else. jika nilai Q.tail nya maksimal - 1 maka akan ter-cek benar bahwa ada isi list nya.
3. buat CreateQueue fungsinya untuk terbentuk queue dengan head = -1 dan tail = -1
4. implementasi enQueue. dengan menggunakan if-else-if-else. if pertama akan mengecek apakah queue sudah terisi atau belum , jika ada maka dilakukan penyisipan yg membuat Q.head = Q.tail bernilai 0 dan Q.tail akan melakukan penambahan sampai Q.nama[Q.tail], indeks array nya sesuai.
5. implementasi deQueue. dengan menggunakan if-else-for-if.if pertama mengecek apakah queue kosong atau tidak. jika tidak kosong maka akan dilakukan penghapusan, dengan menggunakan for yg dimulai dari indeks 0 sampai kurang dari Q.tail nya. LAlu, jika Q.tail < 0, jika queue sudah dikeluarkan semua, set head & tail ke -1
6. Untuk men-print queue gunakan viewQueue. dengan menggunakan if-else-for. jika tidak kosong ;anjut ke for dan akan dilakukan perulangan sebanyak for nya.
## Unguided 

### 1.Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

typedef int infotype;
struct Queue{
    infotype info[5];
    int head, tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue (Queue &Q);
void printInfo(Queue Q);

#endif
```

### queue.cpp
```C++
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}
bool isEmptyQueue(Queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    }else{
        return false;
    }
}
bool isFullQueue(Queue Q){
    if(Q.tail == 5 -1){
        return true;
    }else{
        return false;
    }
}
void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)== true){
        cout << "Queue sudah penuh!" << endl;
    }else{
        if (isEmptyQueue(Q) == true){
            Q.head = Q.tail = 0;
        }else{
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue (Queue &Q){
    if(isEmptyQueue(Q) == true){
        cout << "Empty queue" << endl;
    }else{
        for(int i = 0; i < Q.tail; i++){
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){
            Q.head = -1;
            Q.tail = -1;
        }
    }
}
void printInfo(Queue Q){
    cout << Q.head << "-" << Q.tail << "\t | ";

    if(isEmptyQueue(Q) == true){
        cout << "Empty queue" << endl;
    }else{
        for (int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

### main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
cout << "Hello World" << endl;
Queue Q;
CreateQueue(Q);
cout<<"----------------------"<<endl;
cout<<" H - T \t | Queue info"<<endl;
cout<<"----------------------"<<endl;
printInfo(Q);
enqueue(Q,5); printInfo(Q);
enqueue(Q,2); printInfo(Q);
enqueue(Q,7); printInfo(Q);
dequeue(Q); printInfo(Q);
dequeue(Q); printInfo(Q);
enqueue(Q,4); printInfo(Q);
dequeue(Q); printInfo(Q);
dequeue(Q); printInfo(Q);
return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan8_Modul8-queue/Output-Unguided1.png)


penjelasan unguided 1 
Kita akan implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

Buat file queue.h
1. buat header #ifndef QUEUE_H #define QUEUE_H
2. buat typedef infotype dengan tipe data int
3. buat struct queue yg berisi infotype array 5. head, tail tipe data int
4. buat function primitif :
- CreateQueue, isEmptyQueue, isFullQueue
5. buat implemntasi queue. seperti :
- enqueue 
- dequeue
6. buat printInfo untuk menampilkan outputnya

Buat file queue.cpp
1. buat CreateQueue fungsinya untuk terbentuk queue dengan head = -1 dan tail = -1
2. saat isEmptyQueue menggunakan if-else. jika Q.head == -1 dan Q.tail == -1 akan mengecek apakah beneran kosong atau tidak.
3. saat isFullQueue menggunakan if-else. jika nilai Q.tail nya maksimal - 1 maka akan ter-cek benar bahwa ada isi list nya.
4. implementasi enQueue. dengan menggunakan if-else-if-else. if pertama akan mengecek apakah queue sudah terisi atau belum , jika ada maka dilakukan penyisipan yg membuat Q.head = Q.tail bernilai 0 dan Q.tail akan melakukan penambahan sampai Q.nama[Q.tail], indeks array nya sesuai.
5. implementasi deQueue. dengan menggunakan if-else-for-if. if pertama mengecek apakah queue kosong atau tidak. jika tidak kosong maka akan dilakukan penghapusan, dengan menggunakan for yg dimulai dari indeks 0 sampai kurang dari Q.tail nya. Lalu, jika Q.tail < 0, jika queue sudah dikeluarkan semua, set head & tail ke -1
6. Untuk men-print queue gunakan printInfo. dengan menggunakan if-else-for. jika tidak kosong lanjut ke for dan akan dilakukan perulangan sebanyak indeks for nya.

Buat file main.cpp
Masukkan code yang tertera disoal

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak)

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

typedef int infotype;
struct Queue{
    infotype info[5];
    int head, tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue (Queue &Q);
void printInfo(Queue Q);

#endif
```

### queue.cpp
```C++
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}
bool isEmptyQueue(Queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    }else{
        return false;
    }
}
bool isFullQueue(Queue Q){
    if(Q.tail == 5 -1){
        return true;
    }else{
        return false;
    }
}
void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)== true){
        cout << "Queue sudah penuh!" << endl;
    }else{
        if (isEmptyQueue(Q) == true){
            Q.head = Q.tail = 0;
        }else{
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue (Queue &Q){
    if(isEmptyQueue(Q) == true){
        cout << "Empty queue" << endl;
    }else{
        Q.head++;
        if(Q.head > Q.tail){
            Q.head = -1;
            Q.tail = -1;
        }
    }
}
void printInfo(Queue Q){
    cout << Q.head << "-" << Q.tail << "\t | ";

    if(isEmptyQueue(Q) == true){
        cout << "Empty queue" << endl;
    }else{
        for (int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

### main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
cout << "Hello World" << endl;
Queue Q;
CreateQueue(Q);
cout<<"----------------------"<<endl;
cout<<" H - T \t | Queue info"<<endl;
cout<<"----------------------"<<endl;
printInfo(Q);
enqueue(Q,5); printInfo(Q);
enqueue(Q,2); printInfo(Q);
enqueue(Q,7); printInfo(Q);
dequeue(Q); printInfo(Q);
dequeue(Q); printInfo(Q);
enqueue(Q,4); printInfo(Q);
dequeue(Q); printInfo(Q);
dequeue(Q); printInfo(Q);
return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan8_Modul8-queue/Output-Unguided2.png)

penjelasan unguided 2
Kita akan implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak)

Buat file queue.h
1. buat header #ifndef QUEUE_H #define QUEUE_H
2. buat typedef infotype dengan tipe data int
3. buat struct queue yg berisi infotype array 5. head, tail tipe data int
4. buat function primitif :
- CreateQueue, isEmptyQueue, isFullQueue
5. buat implemntasi queue. seperti :
- equeue 
- dequeue
6. buat printInfo untuk menampilkan outputnya

Buat file queue.cpp
1. buat CreateQueue fungsinya untuk terbentuk queue dengan head = -1 dan tail = -1
2. saat isEmptyQueue menggunakan if-else. jika Q.head == -1 dan Q.tail == -1 akan mengecek apakah beneran kosong atau tidak.
3. saat isFullQueue menggunakan if-else. jika nilai Q.tail nya 5 - 1 maka akan ter-cek benar bahwa ada isi list nya.
4. implementasi enQueue. dengan menggunakan if-else-if-else. if pertama akan mengecek apakah queue sudah terisi atau belum , jika ada maka dilakukan penyisipan yg membuat Q.head = Q.tail bernilai 0 dan Q.tail akan melakukan penambahan sampai Q.nama[Q.tail], indeks array nya sesuai.
5. implementasi deQueue. dengan menggunakan if-else-if. if pertama mengecek apakah queue kosong atau tidak. if kedua Q.head > Q.tail maka Q>head, Q.tail akan diset ke -1
6. Untuk men-print queue gunakan printInfo. dengan menggunakan if-else-for. jika tidak kosong lanjut ke for dan akan dilakukan perulangan sebanyak indeks for nya.


Buat file main.cpp
Masukkan code yang tertera disoal

### 3.Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;
typedef int infotype;
struct Queue{
    infotype info[MAX];
    int head, tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue (Queue &Q);
void printInfo(Queue Q);

#endif
```

### queue.cpp
```C++
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}
bool isEmptyQueue(Queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    }else{
        return false;
    }
}
bool isFullQueue(Queue Q){
    if((Q.tail + 1) % MAX == Q.head) {
        return true;
    }else{
        return false;
    }
}
void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)== true){
        cout << "Queue sudah penuh!" << endl;
    }else{
        if (isEmptyQueue(Q) == true){
            Q.head = Q.tail = 0;
        }else{
            Q.tail = (Q.tail +1) % MAX;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue (Queue &Q){
    if(isEmptyQueue(Q) == true){
        cout << "Empty queue" << endl;
    }else{
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        }else{
            Q.head = (Q.head +1) % MAX;
        }
    }
}
void printInfo(Queue Q){
    cout << Q.head << "-" << Q.tail << "\t | ";

    if (isEmptyQueue (Q) == true){
        cout << "Empty kosong" << endl;
    }else{
        int i = Q.head;
        int count = 1;
        while(true){
            cout << Q.info[i] << " ";
            if (i == Q.tail){
                break;
            }
            i = (i + 1) % MAX;
            count++;
        }
        cout << endl;
    }
}
```

### main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
cout << "Hello World" << endl;
Queue Q;
CreateQueue(Q);
cout<<"----------------------"<<endl;
cout<<" H - T \t | Queue info"<<endl;
cout<<"----------------------"<<endl;
printInfo(Q);
enqueue(Q,5); printInfo(Q);
enqueue(Q,2); printInfo(Q);
enqueue(Q,7); printInfo(Q);
dequeue(Q); printInfo(Q);
dequeue(Q); printInfo(Q);
enqueue(Q,4); printInfo(Q);
dequeue(Q); printInfo(Q);
dequeue(Q); printInfo(Q);
return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan8_Modul8-queue/Output-Unguided3.png)

penjelasan unguided 3
Kita akan implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

Buat file queue.h
1. buat header #ifndef QUEUE_H #define QUEUE_H
2. buat typedef infotype dengan tipe data int
3. buat struct queue yg berisi infotype array [MAX]. head, tail tipe data int
4. buat function primitif :
- CreateQueue, isEmptyQueue, isFullQueue
5. buat implemntasi queue. seperti :
- enqueue 
- dequeue
6. buat printInfo untuk menampilkan outputnya

Buat file queue.cpp
1. buat CreateQueue fungsinya untuk terbentuk queue dengan head = -1 dan tail = -1
2. saat isEmptyQueue menggunakan if-else. jika Q.head == -1 dan Q.tail == -1 akan mengecek apakah beneran kosong atau tidak.

Karena ini implementasi 3 dimana head adan tail berputar maka :
3. saat isFullQueue menggunakan if-else. . (Q.tail + 1) % MAX == Q.head. dilakukan pengecekan sampai benar terisi.
4. implementasi enQueue. dengan menggunakan if-else-if-else. if pertama akan mengecek apakah queue sudah terisi atau belum , jika ada maka dilakukan penyisipan yg membuat Q.head = Q.tail bernilai 0, Q.tail = (Q.tail+1) % MAX dan Q.tail akan melakukan penambahan sampai Q.nama[Q.tail], indeks array nya sesuai.
5. implementasi deQueue. dengan menggunakan if-else-if-else. if pertama mengecek apakah queue kosong atau tidak. if kedua Q.head == Q.tail maka Q>head, Q.tail akan diset ke -1, lalu, Q.head = (Q.head +1)%MAX, Ini menyebabkan Q.head melompat dari indeks 4 kembali ke indeks 0, sehingga antrian menggunakan kembali ruang kosong di awal array yang sebelumnya telah dikosongkan.
6. Untuk men-print queue gunakan printInfo. dengan menggunakan if-else-while-if. if pertama mengecek apakah queue kosonhg/tidak. Jika antrian tidak kosong, proses pencetakan dimulai:
Inisialisasi: Variabel iterasi i diatur ke Q.head (elemen pertama dalam antrian).
Loop while(true): Loop ini digunakan untuk bergerak maju melalui elemen antrian.
Pencetakan berhenti ketika iterasir i mencapai Q.tail (elemen terakhir yang valid dalam antrian). Operator modulo (%) memastikan bahwa iterasir i bergerak maju 1 langkah, dan jika iterasi mencapai batas array, ia akan melompat kembali ke indeks 0. Ini memungkinkan pencetakan elemen secara berurutan, bahkan jika antrian telah melingkar.

Buat file main.cpp
Masukkan code yang tertera disoal

## Kesimpulan
Queue (Antrian) adalah struktur data fundamental yang mengikuti prinsip FIFO (First-In, First-Out).

Poin Utama:
Mekanisme FIFO: Elemen yang pertama masuk adalah yang pertama keluar, seperti antrian di kehidupan nyata.
Teori Antrian: Adalah kajian untuk mengoptimalkan efisiensi sistem layanan dengan menganalisis waktu tunggu dan kapasitas.

Operasi Wajib:
-Enqueue (Penambahan) selalu dilakukan di ujung Belakang (Tail).
-Dequeue (Penghapusan) selalu dilakukan di ujung Depan (Head).

## Referensi
[1] https://www.simplilearn.com/tutorials/cpp-tutorial/queue-in-cpp
<br>[2] Iswahyudi, C. Konsep QUEUE Dalam Bahasa Pemrograman C++.
