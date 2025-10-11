# <h1 align="center">Laporan Praktikum Modul 3- ABSTARCT DATA TYPE (ADT)</h1>
<p align="center">Amelia Candradewi - 103112400140</p>

## Dasar Teori
Tipe data abstrak (ADT) dapat didefinisikan sebagai objek data yang menyempurnakan tipe data dengan cara mengaitkannya dengan fungsi-fungsi yang beroprasi pada data yang bersangkutan. Merupakan hal yang sangat penting untuk mengenali bahwa operasi-operasi yang akan dimanipulasi data pada objek yang bersangkutan termuat dalam spesifikasi ADT. [1]

Dalam ADT file codingan dipisah 
1. Definisi/Spesifikasi Type dan Primitif/Header fungsi (.h)
Spesifikasi type sesuai dengan kaidah bahasa yang dipakai
Spesifikasi dari primitif sesuai dengan kaidah dalam konteks prosedural, yaitu:
Fungsi: nama, domain, range, dan prekondisi jika ada
Prosedur: Initial state, Final state, dan proses yang dilakukan
2. Body/realisasi dari primitif (.c)
Berupa kode program dalam bahasa yang bersangkutan (dalam praktikum ini berarti dengan bahasa C++). Realisasi fungsi dan prosedur harus sedapat mungkin memanfaatkan selector dan konstruktor.[2]

## Guided 

### 1. Menghitung rata-rata nilai mahasiswa yg diinputkan menggunakan struct dan prosedur

```C++
#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "Masukkan nama mahasiswa : ";
    cin >> m.nama;
    cout << "masukkan nilai 1 : ";
    cin >> m.nilai1;
    cout << "masukkan nilai 2 : ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return float(m.nilai1 + m.nilai2)/2;
}

int main(){
    mahasiswa mhs;
    inputMhs(mhs); 
    cout << "Rata-rata : " << rata2(mhs);   
    return 0;
}
```
penjelasan singkat guided 1
Menghitung rata-rata nilai mahasiswa yang diinputkan menggunakan struct dan prosedur. Kita akan men-inputkan 1 nama dan 2 nilai lalu, menghitung rata-rata nya

langkah pertama: membuat struct mahasiswa. didalamnya diisi nama tipe datanya string, nilai1,nilai2 tipe datanya float.
langkah 2: buat prosedur inputMhs yang diisi mahasiswa dan diberi simbol & untuk variabel m. didalamnya diisi inputan nama mahasiswa, nilai1, nilai2, diberi m.nama, m. berguna untuk menyimpan data yg diinputkannya
langkah 3: buat function rata2 untuk rumus menghitung rata-rata nya
langkah 4: panggil struct ADT mahasiswa mhs, panggil prosedur nya, panggil function rumus rata-rata nya
langkah 5: dan akan ter-output hasil rata-rata nya


### 2. ADT

### pelajaran.h

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif

### pelajaran.cpp
#include "pelajaran.h"
pelajaran create_pelajaran(string namaMapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namaMapel;  //parameter lgsg dimasukin ke struct
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) { //pemanggilan menggunakan pel
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

### main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

penjelasan singkat guided 2
langkah pertama : kita harus memisahkan deklarasi tipe,variabel kedalam file.h
langkah 2: 
buat header guard untuk mencegah file header yg sama
#ifndef
#define
lalu, deklarasi ADT pelajaran, struct pelajaran yang didalamnya berisi string namaMapel,kodeMapel
lalu, buat function untuk membuat data pelajaran. 
lalu, buat prosedur untuk menampilkan data pelajaran
diakhir #endif
langkah 3: 
buat file .cpp dari pelajaran.h tadi, didalamnya dipanggil #include "pelajaran.h"
lalu, implementasi function create_pelajaran. didalamnya diberi variabel permisalan untuk pelajaran, dan parameter langsung dimasukin ke struct
lalu, implementasi prosedur tampil_pelajaran didalamnya diberi variabel cout untuk user inputkan nama dan nilai 
langkah 4:
buat file main nya untuk menaruh semua file yg sudah dibuat
lalu, #include "pelajaran.h"
lalu, Memanggil fungsi yang didefinisikan di pelajaran.h untuk membuat objek pelajaran baru dan menyimpannya di variabel pel
lalu, Memanggil fungsi yang didefinisikan di pelajaran.h untuk menampilkan isi objek pel


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```mahasiswa.h

#ifndef MAHASISWA
#define MAHASISWA

const int MAX = 10;
struct mahasiswa{
    char nama[MAX];
    char nim[MAX];
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

```mahasiswa.cpp

#include <iostream>
#include "mahasiswa.h"

using namespace std;
void inputMhs(mahasiswa &m){
    cout << "masukkan nama = ";
    cin >> (m).nama;
    cout << "nim = ";
    cin >> (m).nim;
    cout << "uts = ";
    cin >> (m).uts;
    cout << "uas = ";
    cin >> (m).uas;
    cout << "tugas = ";
    cin >> (m).tugas;
}
float nilaiAkhir(mahasiswa m){
    return (0.3*m.uts + 0.4*m.uas + 0.3*m.tugas);
}

```main.cpp

#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main(){
    mahasiswa mhs[MAX];
    
    int i = 0;
    string input;
    while (i < MAX)
    {
        inputMhs (mhs[i]);
        mhs[i].nilaiAkhir = nilaiAkhir(mhs[i]);
        cout << "nilai akhir = " << mhs[i].nilaiAkhir << endl;
        i++;
        cout << "Input Iya/Tidak : ";
        cin >> input;
        if (input == "tidak"){
            break;
        }
    } 
    
    return 0;
}
void inputMhs(mahasiswa &m);
float nilaiAkhir(mahasiswa m);
#endif
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan3_Modul3/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan3_Modul3/Output-Unguided1-2.png)

penjelasan unguided 1 
kita akan membuat program yg didalamnya dapat menyimpan data mahasiswa max.10 kedalam sebua array yg diisi nama, nim, uts, uas,tugas dan nilai akhir
langkah pertama : kita harus memisahkan deklarasi tipe,variabel kedalam file.h
langkah 2: 
buat header guard untuk mencegah file header yg sama
#ifndef
#define
langkah 3: 
agar nilai max nya tetap 10 maka dibuat const MAX =10
lalu, buat struct mahasiswa didalamnya berisi tipedata dan nama variabel yg akan diinputkan. nama,nim, uts, uas, tugas, nilai akhir
langkah 4:
buat file .cpp dari mahasiswa.h tadi, didalamnya dipanggil #include "mahasiswa.h"
lalu, buat prosedur untuk input mahasiswa, untuk menyimpan data inputan nya buat variabel &m. agar user men-inputkan data-data nya buat cout nya dan panggil struct nya dengan (.)
lalu, buat function nilaiAkhir untuk mengambil struct dari mahasiswa dan didalamnya return untuk menghitung uts,uas,tugas
langkah 5:
buat file main nya untuk menaruh semua file yg sudah dibuat
lalu, #include "mahasiswa.h"
agar user bisa input nya mengulang hingga nilai MAX buat variabel untuk pengulangannya dimulai dari 0. ketika inputan belum sampai MAX nya maka dibuat while didalamnya berisi panggil struct nya dan buat variabel mhs. didalamnya diisi array i
lalu, buat cout apabila user input "tidak" maka akan berhenti programnya. apabila user menulis "iya" program akan meminta user input kan data nya lagi


### 2. 
![Screenshot soal.2](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan3_Modul3/soal.2.png)

```mahasiswa.h

#ifndef MAHASISWA
#define MAHASISWA

const int MAX = 10;
struct mahasiswa{
    char nama[MAX];
    char nim[MAX];
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

```mahasiswa.cpp

#include <iostream>
#include "mahasiswa.h"

using namespace std;
void inputMhs(mahasiswa &m){
    cout << "masukkan nama = ";
    cin >> (m).nama;
    cout << "nim = ";
    cin >> (m).nim;
    cout << "uts = ";
    cin >> (m).uts;
    cout << "uas = ";
    cin >> (m).uas;
    cout << "tugas = ";
    cin >> (m).tugas;
}
float nilaiAkhir(mahasiswa m){
    return (0.3*m.uts + 0.4*m.uas + 0.3*m.tugas);
}

```main.cpp

#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main(){
    mahasiswa mhs[MAX];
    
    int i = 0;
    string input;
    while (i < MAX)
    {
        inputMhs (mhs[i]);
        mhs[i].nilaiAkhir = nilaiAkhir(mhs[i]);
        cout << "nilai akhir = " << mhs[i].nilaiAkhir << endl;
        i++;
        cout << "Input Iya/Tidak : ";
        cin >> input;
        if (input == "tidak"){
            break;
        }
    } 
    
    return 0;
}
void inputMhs(mahasiswa &m);
float nilaiAkhir(mahasiswa m);
#endif
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan3_Modul3/Output-Unguided2.png)

penjelasan singkat guided 2
langkah pertama : kita harus memisahkan deklarasi tipe,variabel kedalam file.h
langkah 2: 
buat header guard untuk mencegah file header yg sama
#ifndef
#define
lalu, deklarasi ADT pelajaran, struct pelajaran yang didalamnya berisi string namaMapel,kodeMapel
lalu, buat function untuk membuat data pelajaran. 
lalu, buat prosedur untuk menampilkan data pelajaran
diakhir #endif
langkah 3: 
buat file .cpp dari pelajaran.h tadi, didalamnya dipanggil #include "pelajaran.h"
lalu, implementasi function create_pelajaran. didalamnya diberi variabel permisalan untuk pelajaran, dan parameter langsung dimasukin ke struct
lalu, implementasi prosedur tampil_pelajaran didalamnya diberi variabel cout untuk user inputkan nama dan nilai 
langkah 4:
buat file main nya untuk menaruh semua file yg sudah dibuat
lalu, #include "pelajaran.h"
lalu, Memanggil fungsi yang didefinisikan di pelajaran.h untuk membuat objek pelajaran baru dan menyimpannya di variabel pel
lalu, Memanggil fungsi yang didefinisikan di pelajaran.h untuk menampilkan isi objek pel

### 3.Buatlah program dengan ketentuan:
-2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
-fungsi/prosedur yang menampilkan isi sebuah array integer 2D
-fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
-fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```array.h
#ifndef ARRAY
#define ARRAY

const int UKURAN = 3;
void tampilkanHasil(int arr[UKURAN][UKURAN]);
void tukarArr(int arrA[UKURAN][UKURAN], int arrB[UKURAN][UKURAN]);
void tukarPtr(int *x, int *y);

#endif

```array.cpp
#include <iostream>
#include "array.h"
using namespace std;
void tampilkanHasil(int arr[UKURAN][UKURAN]){
    for (int i = 0; i < 3; i++){
        for(int j = 0; j<3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    };
}

void tukarArr(int arrA[UKURAN][UKURAN], int arrB[UKURAN][UKURAN]) {
    for(int i = 0; i < 3; i++) {                    
        for(int j = 0; j < 3; j++){
            int temp;
            temp = arrA[i][j];
            arrA[i][j] = arrB[i][j];
            arrB[i][j] = temp;
        }
    }
}

void tukarPtr(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

``` main.cpp
#include <iostream>
#include "array.h"

using namespace std;

int main() {
        int arrA[UKURAN][UKURAN]= {
        {1,2,5},
        {6,3,6},
        {7,9,3}

    };
    int arrB[UKURAN][UKURAN]= {
        {7,5,4},
        {9,7,2},
        {9,7,6}
    };
    cout << "Array sebelum ditukar:"<< endl;
    cout << "Array A :"<< endl;
    tampilkanHasil(arrA);
    cout << "Array B :"<< endl;
    tampilkanHasil(arrB);

    tukarArr(arrA,arrB);

    cout << "Array setelah ditukar:"<< endl;
    cout << "Array A :"<< endl;
    tampilkanHasil(arrA);
    cout << "Array B :"<< endl;
    tampilkanHasil(arrB);

    int a = 20, b = 30;
    
    cout << "Variabel A sebelum ditukar:"<< a << endl;
    cout << "Variabel B sebelum ditukar:"<< b << endl;
    tukarPtr(&a,&b);

    cout << "Variabel A setelah ditukar:"<< a << endl;
    cout << "Variabel B setelah ditukar:"<< b << endl;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan3_Modul3/Output-Unguided-3.png)

penjelasan unguided 3
kita akan membuat program menampilkan isi dari 2 array sblm ditukar dan menampilkan 2 array yg sudah ditukar, membuat 2 pinter dan menampilkan sebelum ditukar dan setelah ditukar
langkah pertama : kita harus memisahkan deklarasi tipe,variabel kedalam file.h
langkah 2: 
buat header guard untuk mencegah file header yg sama
#ifndef ARRAY
#define ARRAY
lalu, agar ukuran selalu konstan maka dibuat const int UKURAN =3
lalu, buat prosedur tampilkanHasil didalamnya diisi array 2D nya[ukuran][ukuran] baris dan kolom
lalu, buat prosedur tukarArr didalamnya diisi untuk arrA dan arrB
lalu, buat prosedur tukarPtr untuk menukar pointer yg akan dibuat nanti
langkah 3: #include "array.h" nya di file array.cpp
lalu, panggil prosedur tampilkanHasil didalamnya berisi perulangan untuk baris dan kolom yg akan dihitung
lalu, panggil prosedur tukarArr didalamnya berisi perulangan untuk baris dan kolom, lalu buat var.temp untuk menyimpan array ygsudah ditukar, misal array A akan ditukar menjadi arrayB dan itu akan disimpan di temp
lalu, panggil tukarPtr didalamnya menggunakan prosedur tukar, dengan tipe data int dan variabel x,y didalamnya dibuat variabel temp untuk menyimpan sementara saat menukar nilai dengan tipe data int disertai simbol *
langkah 4: buat file main nya, main.cpp panggil #include "array.h"
didalam int main nya  diisi data dummy arrA, lalu arrB
lalu, buat cout arrayA, arrB sblm ditukar dan arrayA,arrB sesudah ditukar lalu, masing masing panggil tampilkanHasil arrA, arrB nya
langkha 5:
buat data dummy untuk pointer nya di a dan b 
lalu, cout var.A var.B sebelum ditukar dan setelah ditukar


## Kesimpulan
Abstract Data Type (ADT) adalah spesifikasi logis suatu tipe data yang didefinisikan oleh kumpulan data dan operasi (fungsi) yang dapat memanipulasi data tersebut. ADT menyempurnakan tipe data dasar dengan cara mengaitkan operasi-operasi spesifik pada objek data yang bersangkutan.

Prinsip utamanya adalah pemisahan antara:

Antarmuka/Spesifikasi (.h): Ini adalah kontrak ADT yang berisi Definisi Tipe (seperti struct) dan Header Primitif (prototipe fungsi atau prosedur, termasuk nama, domain, dan prange). Bagian ini mendefinisikan apa yang bisa dilakukan.

Realisasi/Implementasi (.c): Ini adalah dapur ADT yang berisi Body/Kode Program lengkap dari semua primitif. Bagian ini mendefinisikan bagaimana operasi tersebut benar-benar bekerja.

## Referensi
[1] [Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. ](https://shoffin.wordpress.com/2010/08/25/14/)
<br>[2] Modul-3-ADT-Telkom-university
