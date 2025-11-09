# <h1 align="center">Laporan Praktikum Modul 7-STACK</h1>
<p align="center">Amelia Candradewi - 103112400140</p>

## Dasar Teori
Pada modul 7 ini kita mmepelajari stack. Stack adalah struktur data yang mengikuti prinsip LIFO (Last In, First Out). Artinya, elemen terakhir yang ditambahkan ke tumpukan adalah elemen pertama yang dikeluarkan. Bayangkan tumpukan seperti tumpukan buku: Anda hanya dapat mengambil buku dari atas[1]

### A. Operasi dasar
#### 1. Push : Menambahkan elemen ke bagian atas stack
#### 2. Pop  : Menghapus elemen teratas
#### 3. Top  : Mengecek elemen atas tanpa menghapusnya
#### 4. isEmpty : Memeriksa stack kosong [1]

Struktur data Stack diimplementasikan secara terpisah menggunakan Array dan Linked list, di mana setiap pendekatan dirancang untuk mendukung operasi dasar seperti push, pop, dan isEmpty. Selanjutnya, dilakukan pengujian dengan dua skenario utama. Pada skenario pertama, Stack berbasis Array digunakan untuk mengonversi ekspresi matematika dari notasi infix ke postfix.Sementara itu, pada skenario kedua, Stack berbasis Linked list diterapkan untuk mendukung fitur undo/redo pada aplikasi sederhana. Hasil dari pengujian tersebut kemudian dikumpulkan, meliputi data terkait waktu eksekusi, penggunaan memori, dan fleksibilitas ukuran Stack. [2]


## Guided 

### 1. update data setelah dipop pada posisi 2 dan 1. lalu, mencari data 4 dan 9 dari data yang ter-update

### stack.h
```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

penjelasan singkat guided 1
Program ini meminta untuk update data pada posisi 2 dan 1. lalu, mencari data 4 dan 9 dari data yang ter-update.

Menggunakan fitur push, pop, update, view, searchdata. lalu, dimasukkan data dummy node yg akan ditambahkan dan stack setelah di push akan tertampil. lalu akan ada node alamat yang terhapus dan stac setelah di pop 2 kali akan ter-tampil.

user diminta untuk update dan masukkan angka di poisis 2 dan 1. apabila data yg diupdate termasuk data yang dicari yaitu 4 dan 9 makan akan ter-ouput data 4 ditemukan dalam stack, sebaliknya jika tidak akan ter-output data 4 tidak ditemukan didalam stack.

### 2. update data setelah di pop pada posisi 2 dan 1. lalu, mencari data 4 dan 9 dari data yang ter-update

### stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

### stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if (isFull(s)){
        cout << "Stak Penuh!" << endl;
    }else{
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
    
}

void pop(stackTable &s){
    if (isEmpty(s)){
        cout << "Stak Kosong!" << endl;
    }else{
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if (isEmpty(s))
    {
        cout << "Stack Kosong!" << endl;
        return;
    }
    if (posisi <= 0)
    {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    // index = top - (posisi - 1)
    int idx = s.top - (posisi -1);
    if (idx < 0 || idx > s.top)
    {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
    }
    
    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> s.data[idx];
    cout << "data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
    }else{
        for (int i = s.top; i >= 0; --i)
        {
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; i--){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
    }
    cout << endl;
}
```
penjelasan singkat guided 2
Program ini meminta untuk update data pada posisi 2 dan 1. lalu, mencari data 4 dan 9 dari data yang ter-update.

Menggunakan fitur push, pop, update, view, searchdata. lalu, dimasukkan data dummy node yg akan ditambahkan dan stack setelah di push akan tertampil. lalu akan ada node yang terhapus dan stac setelah di pop 2 kali akan ter-tampil.

user diminta untuk update dan masukkan angka di poisis 2 dan 1. apabila data yg diupdate termasuk data yang dicari yaitu 4 dan 9 makan akan ter-ouput data 4 ditemukan dalam stack, sebaliknya jika tidak akan ter-output data 4 tidak ditemukan didalam stack.

## Unguided 

### Buatlah ADT Stack menggunakan ARRAY
### 1. ADT stack menggunkan array dan akan teroutput push dan balik stack
### stack.h
```C++
#ifndef STACK
#define STACK

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack{
    infotype info[20];
    int top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void CreateStack( Stack &S);

void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack( Stack &S);
```

### stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(Stack S){
    return S.top == -1;
}

bool isFull(Stack S){
    return S.top == 19;
}

void CreateStack(Stack &S){
    S.top = -1;
}

void push(Stack &S, infotype x){
    if (isFull(S)){
        cout << "Stack penuh!" << endl;
    }else{
        S.top++;
        S.info[S.top] = x;
    }
}
infotype pop(Stack &S){
    if (isEmpty(S)){
        cout << "Stack kosong!" << endl;
    }else{
        int val = S.info[S.top];
        S.top--;
        return val;
    }
}
void printInfo(Stack S){
    cout << "[TOP]";
    
    if(isEmpty(S)){
        cout << "Stack kosong!" << endl;
    }else{
        for (int i = S.top; i >= 0; --i){
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack( Stack &S){
    if (isEmpty(S)){
        return;
    } 

    Stack temp1;
    CreateStack(temp1);
    Stack temp2;
    CreateStack(temp2);

    while (!isEmpty(S)) {
        push(temp1, pop(S));
    }
    while (!isEmpty(temp1)) {
        push(temp2, pop(temp1));
    }
    while (!isEmpty(temp2)) {
        push(S, pop(temp2));
    }
}
```

### main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "------------" << endl;
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    push(S,3);
    push(S,4);
    push(S,8);
    pop(S);
    push(S,2);
    push(S,3);
    pop(S);
    push(S,9);
    printInfo(S);

    cout<<"balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout <<"------------" << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan7_Modul7-stack/Output-Unguided-1.png)

penjelasan unguided 1 
Pada program ini kita disuruh untuk menampilkan hello world beserta isi array di data dummy yang sudah diberikan, lalu membalikkan stack tersebut.

langkah pertama : buat file stack.h
langkah 2: buat variabel dengan tipe data int infotype.
langkah 3: buat strcut stack yang berisi infotype info isi array [20], int top.
langkah 3 buat function primitif seperti isEmpty, isFull, dan createstack untuk mengecek apakah kosong, penuh dan membuat stack baru.
langkah 4 : buat prosedur stack nya seperti push, pop, printInfo, balik stack.

langkah kedua : buat file stack.cpp
langkah 1: buat return S.top == -1 untuk cek stack berbasis array kosong karna array dimulai dari0, maka untuk mengecek -1.
langkah 2: buat return S.top == 19 karna panjang array 20 jadinya 19 yg dimulai dari 0.
langkah 3: createstack, buat return S.top = -1. setiap kali stack dibuat baru, maka isi array nya harus kosong.
langkah 4: push untuk penyisipan data kedalam stack. menggunakan if else, jika full akan output stack penuh, dan S.top++ akan beratmbah dan isi x nya berisi S.info[S.top].
langkah 5: buat pop untuk melakukan penghapussan. menggunakan if else, langkah awal jika kosong makan output stack kosong, tapi jika tidak int val = S.info[S.top], S.top-- maka akan terhapus.
langkah 6: printInfo untuk menampilkan isi TOP dan data nya.

pada bagian ini dilakukan balik stack sebagai berikut :
buat prosedur balikStack dengan parameter Stack &S. cek is empty terlebih dahulu. lalu buat variabel baru untuk menampung stack yang ditukar yaitu stack temp1, stack temp2. dan di createstack tempt temp2. menggunakan while.
while pertama : pindahkan pop S ke temp1
while kedua : pindahkan temp1 ke temp 2
while ketiga pindahkan temp2 ke S dan sekaang Stack s terbalik

langkah ketiga : buat main.cpp
di int main masukkan data dummy dengan push dan panggil balikstack dan printinfo s nya.

### 2. Menambahkan prosedur pushAscending( in/out S : Stack, in x : integer). terurut membesar.
### stack.h
```C++
void pushAscending(Stack &S, infotype x);
```
### stack.cpp
```C++
void pushAscending(Stack &S, infotype x){
    if(isFull(S)){
        cout << "Stack penuh!" << endl;
    }

    Stack tempstack;
    CreateStack(tempstack);
    if (!isEmpty(S)){
        while(!isEmpty(S) && S.info[S.top] > x){
            infotype tempVal = pop(S);
            push(tempstack, tempVal);
        }
    }
    push(S, x);

    while (!isEmpty(tempstack)){
        infotype tempVal = pop(tempstack);
        push(S, tempVal);
    }
}
```

### main.cpp
```C++
int main() {
    cout << "------------" << endl;
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    cout << "------------" << endl;
    return 0;

}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan7_Modul7-stack/Output-Unguided-2.png)

penjelasan unguided 2
Melanjutkan nomor 1, dan ditambahkan pushAscending yaitu mengurutkan stack dari terkecil ke terbesar.

membuat prosedur pushAscending berisi parameter Stack &S, infotype x.
di file stack.cpp di cek stack full/tidak. buat stack baru untuk menyimpan stack yang sedang di urutkan yaitu stack tempstack dan createstack. menggunakan if-while. jika tidak kosong ketika tidak kosong dan S.top nya > x dilakukan operasi LIFO, mengurangi S.top, dan mengembalikan data yang dihapus dan disimpan di tempVal. lalu push tempstack, tempVAl. diluar if push S, x.
while luar  mengurutkan atau memindahkan elemen-elemen yang sebelumnya dikeluarkan dari Stack utama (S) kembali ke S

di file main.cpp, int main nya buat data dummy nya dengan memanggil pushacending, saat balik stack panggil fungsi balikstack dan printinfo.

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

### stack.h
```C++
void getInputStream(Stack &S);
#endif
```

### stack.cpp
```C++
void getInputStream(Stack &S){
    int input ;

    while((input = cin.get()) != '\n') {
        if ((input >= '0' && input <= '9')){
            infotype data = input -'0';
            push(S, data);
        }
    }
}
```

### main.cpp
```C++
int main(){
    cout << "------------" << endl;
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);
    cout<<"balik stack"<< endl;
    balikStack(S);
    printInfo(S);
    cout << "------------" << endl;
    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan7_Modul7-stack/Output-Unguided-3.png)

### penjelasan Unguided-3

melanjutkan nomor 2, adanya penambahan getInputStream yaitu user input angka dan dilakukan balik stack dari angka yang diinputkan user, mengguanakn cin.get() tetapi tidak dikonversi kedalam bentuk ASCII. akan ter-output angka yg user inputkan.

buat file stack.h buat prosedur getInputStream dengan parameter Stack &S.

di file stack.cpp buat isi prosedur nya yaitu :
buat variabel untuk user inputkan dengan tipe data int. menggunakan while if, ketika input = cin.get() != '\n' untuk membaca dari user hingga tombol enter ditekan. didalamnya dilakukan pengecekan agar tidak berubah ke ASCII dengan if, jika input >= 0 dan input <= 9 maka infotype data = input - 0 Mengubah kode ASCII dari digit menjadi nilai int. push (S, data)

di file main.cpp
di int mainnya, panggil fungsi getInputStack, printInfo lalu saat balik stack panggil function balikstack, printinfo.

akan ter-output stack yang dibalik dari inputan user tersebut.
## Kesimpulan
esimpulannya, Stack adalah struktur data fundamental yang beroperasi berdasarkan prinsip LIFO (Last In, First Out), mirip dengan tumpukan fisik di mana hanya elemen teratas yang dapat diakses. Operasi dasarnya mencakup Push (menambah elemen ke atas), Pop (menghapus elemen teratas), Top (melihat elemen teratas tanpa menghapus), dan isEmpty (memeriksa kondisi kosong).

## Referensi
[1] Rishabh Singh. (2024). https://medium.com/@RobuRishabh/understanding-how-to-use-stack-queues-c-9f1fc06d1c5e 
<br>[2]Risky Dwi Setiyawan.(2024) PENGGUNAAN STRUKTUR DATA STACK DALAM PEMROGRAMAN C++ DENGAN PENDEKATAN ARRAY DAN LINKED LIST https://journal.uii.ac.id/Snati/article/download/2208/2031
