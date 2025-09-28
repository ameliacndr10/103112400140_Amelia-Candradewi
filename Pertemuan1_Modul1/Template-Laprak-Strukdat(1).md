# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Amelia Candradewi - 103112400140</p>

## Dasar Teori
Suatu pekerjaan dapat dikerjakan dengan lebih cepat dan lebih mudah apabila permasalahan dan alur dari pekerjaan jelas. Dalam pemrograman konsep kerja dan logika dari pemrograman harus dipahami terlebih dahulu. Sebuah pemrograman tidak akan terlepas dari konsep kerja suatu komputer. Terdapat logika dasar seperti input, proses, dan output yang bermakna bahwa ada data yang harus diberikan untuk diproses sehingga dapat menghasilkan keluaran. Algoritma merupakan fondasi yang harus dipahami atau dikuasai oleh seorang pemrogram (Sitorus, 2015) [1]

Perulangan dilakukan dengan syarat tertentu. Terdapat tiga pengulangan yang umum digunakan yaitu :
1. while -> perulangan while akan menjalankan intruksi untuk mengulang satu baris perintah selama syarat yang diberikan terpenuhi.
2. do-while -> digunakan untuk mengulang satu baris perintah hingga syarat tidak terpenuhi.
3. for -> digunakan untuk mengulang sebuah proses dengan variabel nilaiawal dan nilai akhir. [2]

Nested loop adalah perulangan didalam perulangan. artinya sebuah loop berada didalam loop lain. Loop bagian dalam akan dijalnkan setiap kali loop bagian luar berjalan satu kali. 

### A. C++ adalah bahasa pemrograman tingkat tinggi yang mendukung paradigma prosedural dan berorientasi objek [2]<br/>
...
#### 1.Struktur Dasar Program C++ 

Header: misalnya #include <iostream> untuk input/output.

Fungsi main(): titik awal eksekusi program.

Statement: baris perintah di dalam fungsi.
### 2. Variabel dan Tipe Data

int, float, double, char, string, dll.

Digunakan untuk menyimpan nilai yang diproses program.
#### 4. Input dan Output

Input: cin digunakan untuk membaca data dari pengguna.

Output: cout digunakan untuk menampilkan data ke layar.[2]


## Guided 

### 1. operasi aritmatika

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "masukkan angka1 : ";
    cin >> angka1;
    cout << "masukkan angka2 : ";
    cin >> angka2;

    //penjumlahan
    cout <<"penjumlahan :" << angka1 + angka2 << endl;
    //pengurangan 
    cout <<"pengurangan :" << angka1 - angka2 << endl;
    //perkalian
    cout <<"perkalian :" << angka1 * angka2 << endl;
    //pembagian
    cout <<"pembagian :" << angka1 / angka2 << endl;
    //modulus
    cout <<"modulus :" << angka1 % angka2 << endl;
    return 0;
}
```
penjelasan singkat guided 1
Membuat code dari C++ terkait penjumlahan, pengurangan, pembagian dan modulus.

Langkah pertama inisialisasi variabel nya int angka1, angka2. Karena kita akan men-input 2 bilangan.

Cout -> untuk menampilkan data maupun tulisan
Cin -> untuk memasukkan data kesuatu variabel

Lalu, masukkan rumus penjumlahan, pengurangan, perkalian, pembagian dan modulus. dengan operator aritmatika + - * / %

return 0 untuk mengembalikan 0 secara otomatis

### 2. Percabangan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "masukkan angka1 : ";
    cin >> angka1;
    cout << "masukkan angka2 : ";
    cin >> angka2;

    if (angka1 > angka2) {
        cout << angka1 << "lebih besar dari" << angka2 << endl;
    }else if (angka1 == angka2) {
        cout<< angka1 << "sama dengan" << angka2 << endl;
    }else if (angka1 < angka2) {
        cout << angka1 << "lebih kecil dari" << angka2 << endl;
    }

    if (angka1 != angka2) {
        cout << angka1 << "tidak sama dengan" << angka2 << endl;
    }
    return 0;
}
```
penjelasan singkat guided 2
Membuat code dari C++ terkait percabangan if, else if dan else. Kita ingin melakukan perbandingan "lebih besar", "sama dengan", "lebih kecil dari".
Langkah pertama inisialisasi variabel nya int angka1, angka2. Karena kita akan men-input 2 bilangan.

Cout -> untuk menampilkan data maupun tulisan
Cin -> untuk memasukkan data kesuatu variabel

Langkah 1 : "lebih besar dari"
Masukkan rumus jika angka1 > angka2, maka yang akan ter-print "lebih besar dari".
Langkah 2 : "sama dengan"
Masukkan rumus jika angka1==angka2, maka yang akan ter-print "sama dengan.
Langkah 3 : "lebih kecil dari"
Masukkan rumus jika angka1 < angka2, maka yang akan ter-print "lebih kecil dari".

Untuk "tidak sama dengan" dibuat if sendiri(dipisah) agar tidak ter-cek ke percabangan sebelumnya. menggunakan operator != (tidak sama dengan)

### 3. Perulangan while

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "masukkan angka1 : ";
    cin >> angka1;

    int i = 0;
    int j = 11;

    //perulangan while
    while (i < angka1) {
        cout << i << "-";
        i++; //increment
    }

    //perulangan do-while
    do {
        cout << j << "-";
        j++; //increment
    }while(j < angka1);
    
    return 0;
}
```
penjelasan singkat guided 3
Membuat code dari C++ terkait perulangan while, do-while.
Langkah pertama inisialisasi variabel nya int angka1. Kita input-kan angka1.

Cout -> untuk menampilkan data maupun tulisan
Cin -> untuk memasukkan data kesuatu variabel

Deklarasi variabel i=0 untuk perulangan while 
Deklarasi variabel j=11 untuk perulangan do-while

Misal angka1= 2
maka 2 akan masuk ke perulangan while, 0<2 (iya), 1<2 (iya), 2<2 (tidak) lanjut ke do-while

di do-while juga sama, 11<3(tidak) di cek terus sampai 12 -> 11<12 (iya) cetak 11

jadi output nya 0-1-11


## Unguided 

### 1.Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;
int main() {
    float angka1, angka2;

    cout << "Masukkan angka1:";
    cin >> angka1;
    cout << "Masukkan angka2:";
    cin>> angka2;

    //penjumlahan 
    cout <<"penjumlahan :" << angka1 + angka2 << endl;
    //penngurangan 
    cout <<"pengurangan :" << angka1 - angka2 << endl;
    //perkalian
    cout <<"perkalian :" << angka1 * angka2 << endl;
    //pembagian
    cout <<"pembagian :" << angka1 / angka2 << endl;

}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 
Membuat code dari C++ terkait penjumlahan, pengurangan, pembagian dan modulus.

Langkah pertama inisialisasi variabel nya int angka1, angka2. Karena kita akan men-input 2 bilangan.

Cout -> untuk menampilkan data maupun tulisan
Cin -> untuk memasukkan data kesuatu variabel

Lalu, masukkan rumus penjumlahan, pengurangan, perkalian, pembagian dan modulus. dengan operator aritmatika + - * / %

return 0 untuk mengembalikan 0 secara otomatis

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100
contoh: 79: tujuh puluh Sembilan

```C++
#include <iostream>
using namespace std;

int main() {
    int i;
    string arr[] = {"nol", "satu", "dua", "tiga", "empat","lima","enam","tujuh","delapan","sembilan"};
    cout << "Masukkan angka:";
    cin >> i;
    
    if (i==100){
        cout << "seratus";
    }else if (i < 0 || i>99 ) {
        cout << "Masukkan angka harus 0-99";
    }else if (i<9) {
        cout << arr[i];
    }else if (i==10) {
        cout << "sepuluh";
    }else if (i==11) {
        cout << "sebelas";
    }else if (i<20){
        cout << arr[i%10] << " belas";
    }else {
        int sisa = i%10;
        cout << arr[i/10] << " puluh ";
        if (sisa !=0) {
            cout << arr[sisa];
        }
    }
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2
Membuat code dari C++ terkait apabila input angka, outputnya bentuk tulisan dari angka tersebut.

langkah pertama inisialisasi variabel i untuk inputan angka nya.
langkah 2: tentukan angka spesial seperti, sepuluh, sebelas, belas, puluh, seratus.
langkah 3: buat string array yang berisi string nol sampai string sembilan.
langkah 4: buat if i == 100 output "seratus". ditaruh di awal agar tidak ter-cek di else if selanjutnya
langkah 5: buat operator perbandingan angka indeks 0 sampai 99 pakai operator ||
langkah 6: buat else if i < 9 outputnya string array
langkah 7: buat else if angka spesial 10 (sepuluh), 11 (sebelas)
langkah 8: buat else if i<20 maka di modulus didalam arraynya i%10 outputnya belas
langkah 9: jika ada sisa dari modulus maka outputnya puluh, if !=0 agar diakhir string nol tidak ikut.


### 3. (nested-loop) Buatlah program yang dapat memberikan input dan output sbb.
input: 3
output:
321 * 123
 21 * 12
  1 * 1
    *

```C++
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Input: ";
    cin >> n;

    for (int i =0; i <= n; i++) {
        for (int j=0; j<i; j++){
            cout << " ";
        }
        for (int j = n-i; j>=1; j--) {
            cout << j;
        }
        cout << " * ";
        for (int j=1; j <= n-i;j++) {
            cout << j;
        }
        cout << endl;
    }
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3
Membuat code dari C++ terkait dapat memberikan input dan output mengecil dan ditengahnya *
Langkah pertama inisialisasi variabel n untuk inputan angka nya.
langkah 2: buat loop for untuk awalan dimulai dari i=0 untuk mengatur baris dari 0 sampai n
langkah 2: buat loop for didalam, inisialisasi variabel j untuk menambahkan spasi sebelum angka
langkah 3: buat loop for didalam, inisialisasi variabel j untuk mencetak angka menurun dari n-i sampai 1
langkah 3: buat loop for didalam, inisialisasi variabel j untuk mencetak angka meningkat dari 1 sampai n-i

Jadi nested loop digunakan untuk mengontrol kolom dan baris sekaligus, terutama saat membuat pola piramida, segitiga, atau bentuk tertentu.


## Kesimpulan
Perulangan dilakukan dengan syarat tertentu. Terdapat tiga pengulangan yang umum digunakan yaitu while, do-while, for.
Nested loop adalah perulangan didalam perulangan. artinya sebuah loop berada didalam loop lain. Loop bagian dalam akan dijalnkan setiap kali loop bagian luar berjalan satu kali.

## Referensi
[1] Hanief, S., Jepriana, I. W., & Kom, S. (2020). Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Penerbit Andi.
<br>[2] Nabila Chairunnisa,S.Kom (2024). "Langkah mudah belajar pemrograman C++". Penerbit ANAK HEBAT INDONESIA
<br>[3] Warford, J.S. (2002). Nested Loops. In: Hug, K. (eds) Computing Fundamentals. Vieweg+Teubner Verlag, Wiesbaden. https://doi.org/10.1007/978-3-322-91603-7_11
