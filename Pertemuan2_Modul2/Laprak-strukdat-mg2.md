# <h1 align="center">Laporan Praktikum Modul 2 PENGENALAN BAHASA C++ (BAGIAN KEDUA)</h1>

<p align="center">Amelia Candradewi - 103112400140</p>

## Dasar Teori
Pada Modul 2 ini, kita mempelajari tipe data kompleks dan konsep dasar pemrograman C++ seperti array, pointer, reference, dan prosedur. Array adalah variabel yang dapat menyimpan sekumpulan data dengan tipe yang sama; array 1 dimensi memiliki satu indeks dan digunakan untuk data linear, sedangkan array 2 dimensi memiliki dua indeks seperti tabel, cocok untuk matriks. Pointer adalah variabel yang menyimpan alamat memori variabel lain, memungkinkan akses langsung ke nilai variabel dan efisiensi saat menukar nilai. Reference adalah alias dari variabel yang sudah ada, sehingga perubahan pada reference otomatis memengaruhi variabel asli. Prosedur atau fungsi adalah blok kode yang dapat dipanggil berulang kali untuk melakukan tugas tertentu, bisa dengan atau tanpa nilai balik, dan berguna untuk memecah program menjadi bagian yang lebih rapi dan mudah dipahami. Kombinasi array, pointer, dan reference sering digunakan untuk operasi seperti penjumlahan elemen array, mencari nilai maksimum, menukar nilai variabel, dan manipulasi data secara efisien. [2]

### A. Array<br/>

Array adalah struktur data yang dapat digunakan untuk menyimpan sekumpulan data dalam satu tempat memori yang berurutan serta dapat diakses menggunakan indeks. Memungkinkan penyimpanan dan pengelolaan data secara efisien. Dalam C++ data array disimpan dalam memori pada lokasi yang berurutan. Elemen pertama memiliki indeks 0 dan selemen selanjutnya memiliki indeks 1 dan seterusnya. Jadi jika terdapat array dengan 5 elemen maka elemen pertama memiliki indeks 0 dan elemen terakhir memiliki indeks 4. [1]

tipe nama_array[ukuran];

#### 1. Array satu dimensi
array satu dimensi adalah array yang hanya terdiri dari satu larik data saja.  cara pendeklarasiannya adalah : tipe_data nama_var[ukuran];
contohnya : int nilai[10];     [3]

#### 2. Array dua dimensi
array dua dimensi adalah struktur data yang dapat menyimpan data dalam bentuk matriks atau tabel dua dimensi atau dimensi yang lebih tinggi. Array tipe ini sangat memungkinkan untuk mengorganisir data dalam bentuk grid dengan baris dan kolom. Sering digunakan untuk mempresentasikan matriks yang setiap elemennya memiliki baris dan kolom. 
contoh : int array[3][3];   [3]

#### 3. Array berdimensi banyak
array berdimensi banyak adalah array yang mempunyai indeks banyak, lebih dari dua. 
contoh : int_data nama-var[ukuran1][ukuran2]...[ukuran-N];
contoh : int data-rumit[4][6][6];   [3]

### B. Pointer
Pointer adalah variabel yang menyimpan alamat memori dari suatu nilai atau objek. Tujuan dari pointer adalah mengalokasikan objek baru kepada timbunan dan melakukan iterasi atas elemen dalam array atau kepada struktur data lainnya. Cara menggunakannya adalah dengan meletakkan tanda & didepan identits saat pemanggilan variabel.

### C. Prosedur atau fungsi 
merupakan sekumpulan kode yang bisa dijalankan berulang kali untuk menjalankan suatu tugas tertentu, baik mengembalikan nilai maupun tidak, serta membantu membagi program menjadi bagian-bagian yang lebih terstruktur dan mudah dimengerti. Penggunaan array, pointer, dan reference secara bersamaan sering diterapkan untuk berbagai operasi, seperti menjumlahkan elemen array, menemukan nilai terbesar, menukar nilai variabel, dan melakukan manipulasi data dengan lebih efisien. [1]

## Guided

### 1. Array-1-dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i= 0;i<5;i++) {
        cout << "Masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while(j<5) {
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```

penjelasan singkat guided 1
Membuat kode mengenai array 1 dimensi.
langkah pertama : menulis isi indeks array nya yang akan diinputkan nantinya
langkah 2: agar saat diinputkan ter-looping maka menggunakan perulangan for sampai indeks nya sesuai. isi inputannya disimpan kedalam arr[i]
langkah 3: menggunakan while untuk menulis isi array yang telah diinputkan dimulai dari indeks ke-0, disimpan didalam arr[j].

### 2. Array-2-dimensi

```C++
#include <iostream>
using namespace std;
void tampilkanHasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for(int j = 0; j<2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    };
}
int main() {
    int arrA[2][2]= {
        {1,2},
        {3,4}
    };
    int arrB[2][2] = {
        {2,3},
        {4,5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};



    for(int i = 0; i < 2; i++) {                    
        for(int j = 0; j < 2; j++){                 
            arrC[i][j] = arrA[i][j] + arrB[i][j];   
        }
    }
    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    for (int i = 0; i < 2; i++){
        for( int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                arrD[i][j] = arrA[i][k] + arrB[k][j];
            }
        }
    }
    cout << "hasil perkalian : " << endl;
    tampilkanHasil (arrD);
    return 0;
}
```
penjelasan singkat guided 2
Membuat kode mengenai array-2-dimensi
langkah pertama : membuat prosdeur tampilkanHasil untuk spasi pda baris dan kolom
langkah 2 : membuat isi array dengan deklarasi variabel arraA, arrB dan sekalian diisi data dummy nya. Lalu, membuat deklarasi variabel  arrC, arrD untuk menyimpan rumus penjumalahan dan perkalian
langkah 3 : membuat perulangan for i dan j untuk menghitung penjumlahan berapa kali dilakukan perhitungan dan menyimpan nya di arrC dan panggil tampilkanHasil(arrC)
langkah 4 : membuat perulangan for i dan j untuk menghitung perkalian berapa kali dilakukan perhitungan dan menyimpan nya di arrD dan panggil tampilkanHasil(arrD).


### 3. Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a : " << a << endl;
    cout << "Addres of : " << &a << endl;
    cout << "Value stured in ptrs (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr : " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a=" <<a << "and b=" << b << endl;
    return 0;
}
```

penjelasan singkat guided 3
membuat kode agar isi value a dan b tertukar
langkah pertama : menggunakan prosedur tukar, dengan tipe data int dan variabel x,y. didalamnya dibuat variabel temp untuk menyimpan sementara saat menukar nilai dengan tipe data int disertai simbol *
langkah 2 : buat int main, didalamnya berisi data dummy var.a,b. lalu, buat variabel baru pointer yang disingkat jadi ptr disertai tanda * agar bisa membaca alamat dari variabel a maka diberikan simbol &
langkah 3 : membuat output string nya dengan "" dan cout. Panggil variabel nya juga untuk setiap string nyaa.
langkah 4 : agar bisa tertukar var.a,b maka panggil prosedur tukar didalamnya memakai simbol & 


### 4. Refrence

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main() {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Value of a : " << a << endl;
    cout << "Addres of : " << &a << endl;
    cout << "Value stured in ptrs (address of a): " << ref << endl;
    cout << "Value pointed to by ptr : " << &ref << endl;


    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a:" << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a=" <<a << "and b=" << b << endl;
    return 0;
}
```

penjelasan singkat guided 4
membuat kode agar isi value a dan b tertukar
langkah pertama : menggunakan prosedur tukar, dengan tipe data int dan variabel x,y disertai &. didalamnya dibuat variabel temp untuk menyimpan sementara saat menukar nilai dengan tipe data int 
langkah 2 : buat int main, didalamnya berisi data dummy var.a,b. lalu, buat variabel baru refrence yang disingkat jadi ref disertai tanda int& agar bisa membaca alamat dari variabel a 
langkah 3 : membuat output string nya dengan "" dan cout. Panggil variabel nya juga untuk setiap string nyaa.
langkah 4 : ref adalah refrence ke a. ref dan a menunjuk ke nilai yang sama dimemori, jadi saat menulis ref=50, nilai a otomatis berubah menjadi 50
langkah 5 : agar bisa tertukar var.a,b maka panggil prosedur tukar tanpa simbol apapun


### 5. Function-Prosedur

```C++
#include <iostream>
using namespace std;

int cariMax(int arr[], int ukuran) {
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}
void operasiAritmatika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for( int i =0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;
}
int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "masukkan nilai array ke-" << i << " : ";
        cin >> arr[i]
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMax(arr, ukuran) << endl;
    operasiAritmatika(arr, ukuran);
    return 0;
}
```

penjelasan singkat guided 5
membuat fungsi-prosedur. yang didalamnya bisa inputkan nilai array indeks ke-0 sampai ke-5 dan menampilkan nilai terbesar array, total penjumlahan, total perkalian.

langkah pertama: membuat  fungsi cariMax didalamnya berisi arr[], variabel ukuran. didalmnya diisi dengan variabel MAX yang dihitung dari indeks array ke-0. menggunakan for if yang perhitungannya dimulai dari i = 1, jika sesuai akan masuk kedalam penyimpanan arr[i] > MAX, nilai MAX sama dengan niali arr[i] nya
langkah 2: 
membuat prosedur operasiAritmatika yang diisi arr[], var.ukuran. didalamnya berisi var.totalJumlah = 0. menggunakan for i=0, i < ukuran, hasil perhitungannya akan disimpan di totalJumlah dengan rumus array[i] + jumlah perulangannya yg sudah dihitung tadi, dan cout total penjumlahan, dipanggil nilai dari totalJumlah nya.

lalu, membuat int totalKali = 1 karena perkalian harus dimulai dari 1, kalo dari 0 nanti jadi 0 semua. didalamnya menggunakan for i = 0, i < ukuran, jika sesuai akan masuk kedalam penyimpanan arr[i], variabel totalKali = arr[i] *  jumlah perulangan yg sudah dihitung tadi, dan cout total perkalian, dipanggil nilai dari totalKali nya.

langkah 3 : 
membuat int main didalmnya berisi jumlah panjang elemen nya, lalu, membuat array yang berisi nilai konstan, arr[ukuran].
menggunakan perulangan for untuk inputan array, yang dimulai dari array ke-0 dan disimpan di arr[i]

langkah 4 : membuat output menggunakan cout untuk mencari nilai terbesar dalam array dengan memanggil var.cariMax didalamnya diisi arr,ukuran dan operasiAritmatika didalamnya juga diisi arr,ukuran


## Unguided

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
#include <iostream>
using namespace std;
void tampilkanHasil(int arr[3][3]){
    for (int i = 0; i < 3; i++){
        for(int j = 0; j<3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    };
}
int main() {
    int arrA[3][3]= {
        {1,1,1},
        {1,1,1},
        {1,1,1}

    };
    int arrB[3][3]= {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    int arrC[3][3] = {0};
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};


    //penjumlahan matriks 
    for(int i = 0; i < 3; i++) {                    
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];   
        }
    }
    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    
    //pengurangan matriks 
    for(int i = 0; i < 3; i++) {                    
        for(int j = 0; j < 3; j++){
            arrD[i][j] = arrA[i][j] - arrB[i][j];   
        }
    }
    cout << "Hasil penguranagan : " << endl;
    tampilkanHasil(arrD);
    cout << endl;

    
    //perkalian matriks 
    for (int i = 0; i < 3; i++){
        for( int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                arrE[i][j] = arrA[i][k] * arrB[k][j];
            }
        }
    }
    cout << "hasil perkalian : " << endl;
    tampilkanHasil (arrE);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan2_Modul2/Output-Unguided1.png)

penjelasan unguided 1
Membuat kode mengenai matriks 3x3 menggunakan array-2dimensi
langkah pertama : membuat prosdeur tampilkanHasil untuk spasi pada baris dan kolom.
langkah 2: membuat int main masukkan data dummy harus berisi 3 angka untuk arrA,arrB. buat variabel arrC,arrD,arrE untuk menyimpan hasil penjumlahan,pengurangan dan perkalian
langkah3: membuat perulangan for i dan j untuk menghitung penjumlahan dilakukan 3kali perhitungan dan menyimpan nya di arrC dan panggil tampilkanHasil(arrC)
langkah 4:  membuat perulangan for i dan j untuk menghitung pengurangan dilakukan 3kali perhitungan dan menyimpan nya di arrD dan panggil tampilkanHasil(arrD)
langkah 5:  membuat perulangan for i j k untuk menghitung perkalian dilakukan 3kali perhitungan dan menyimpan nya di arrE dan panggil tampilkanHasil(arrE)


### 2-1 Berdasarkan guided pointer sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}
int main() {
    int a = 20, b = 30, c=40;
    int *ptr;

    ptr = &a;

    cout << "Value of a : " << a << endl;
    cout << "Addres of : " << &a << endl;
    cout << "Value stured in ptrs (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr : " << *ptr << endl;

    tukar(&a, &b, &c);
    cout << "After swapping, value of a=" <<a << "b=" << b << "c=" << c << endl;
    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2-1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan2_Modul2/Output-Unguided2-1.png)

penjelasan unguided 2
membuat kode agar isi value a b c tertukar
langkah pertama : menggunakan prosedur tukar, dengan tipe data int dan variabel x,y,z didalamnya dibuat variabel temp untuk menyimpan sementara saat menukar nilai dengan tipe data int disertai simbol *
langkah 2 : buat int main, didalamnya berisi data dummy var.a,b,c lalu, buat variabel baru pointer yang disingkat jadi ptr disertai tanda * agar bisa membaca alamat dari variabel a maka diberikan simbol &
langkah 3 : membuat output string nya dengan "" dan cout. Panggil variabel nya juga untuk setiap string nyaa.
langkah 4 : agar bisa tertukar var.a,b,c maka panggil prosedur tukar didalamnya memakai simbol & 


### 2-2 Berdasarkan guided reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}
int main() {
    int a = 20, b = 30, c = 40;
    int& ref = a;

    cout << "Value of a : " << a << endl;
    cout << "Addres of : " << &a << endl;
    cout << "Value stured in ptrs (address of a): " << ref << endl;
    cout << "Value pointed to by ptr : " << &ref << endl;

    
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a:" << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b, c);
    cout << "After swapping, value of a = " <<a << ", b = " << b << " dan c = " << c << endl;
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2-2](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan2_Modul2/Output-Unguided2-2.png)

penjelasan unguided 2
membuat kode agar isi value a,b,c tertukar
langkah pertama : menggunakan prosedur tukar, dengan tipe data int dan variabel x,y,z disertai &. didalamnya dibuat variabel temp untuk menyimpan sementara saat menukar nilai dengan tipe data int 
langkah 2 : buat int main, didalamnya berisi data dummy var.a,b,c lalu, buat variabel baru refrence yang disingkat jadi ref disertai tanda int& agar bisa membaca alamat dari variabel a 
langkah 3 : membuat output string nya dengan "" dan cout. Panggil variabel nya juga untuk setiap string nyaa.
langkah 4 : ref adalah refrence ke a. ref dan a menunjuk ke nilai yang sama dimemori, jadi saat menulis ref=50, nilai a otomatis berubah menjadi 50
langkah 5 : agar bisa tertukar var.a,b,c maka panggil prosedur tukar tanpa simbol apapun 


### 3. Diketahui sebuah array 1 dimensi sebagai berikut :
arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari
array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan
function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur
hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan
menu switch-case seperti berikut ini :
--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata


```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int ukuran) {
    int MIN = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if (arr[i] < MIN){
            MIN = arr[i];
        }
    }
    return MIN;
}
int cariMaksimum(int arr[], int ukuran) {
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void hitungRataRata(int arr[], int ukuran){
    int totalJumlah = 0;
    for( int i =0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "Rata-rata : " << totalJumlah/ukuran << endl;
}

int main() {
    int ukuran = 10;
    int arrA[ukuran] = {11,8,5,7,12,26,3,54,33,55};

    cout << "--Menu Program Array--" << endl;
    cout << "1. Tampilkan isi array" << endl;
    cout << "2. Cari nilai maksimum" << endl;
    cout << "3. Cari nilai minimum" << endl;
    cout << "4. Hitung nilai rata-rata" << endl;
    
    cout << "Masukkan inputan user: ";
    int input;
    cin >> input;

    switch (input)
    {
    case 1:
        for(int i=0; i<10 ;i++){
            cout << arrA[i] <<" ";
        }
        break;
    case 2:
        cout << cariMaksimum(arrA,ukuran);
        break;
    case 3: 
        cout << cariMinimum(arrA, ukuran);
        break;
    case 4:
        hitungRataRata(arrA, ukuran);
        break;
    default:
        cout << "inputan salah";
        break;
    }
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3-1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan2_Modul2/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3-2](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan2_Modul2/Output-Unguided3-2.png)

penjelasan unguided 3
membuat program agar user bisa memilih mau menampilkan menu program apa

langkah pertama: membuat  array untuk cariMinimum, cariMaksimum
langkah 2: membuat prosedur hitungRataRata
langkah 3: 
membuat int main, didalamnya berisi int ukuran = 10 yang berarti isi array nya ada 10
buat arrA[ukuran] diisi dengan data dummy isi array nya
buat cout untuk memudahkan user memilih menu input-an nya, dan dibawahnya dibuat masukkan inputan user
mengguanakan switch-case, buat for pertama untuk setiap output array nya ada spasi
case 2, untuk menampilkan cariMaksikum nya
case 3, untuk menampilkan cariMinimum
case 4, untuk hitungRataRata
apabila user input nilai yang tidak ada maka akan ter-output string "inputan salah"
langkah 4: balik ke kode cariMinimum
didalamnya diisi dengan arr[], ukuran. untuk MIN dimulai dari indeks ke 0 makanya arr[0], akan melakukan perulangan dari ke1 < nilai MIN nya dan akan disimpan di arr[i]
langkah 5: balik ke kode cariMaksimum
didalamnya diisi dengan arr[], ukuran. untuk MAX dimulai dari indeks ke 0 makanya arr[0], akan melakukan perulangan dari ke1 > nilai MAX nya dan akan disimpan di arr[i]
langkah 6: balik ke prosedur hitungRataRata
didalamnya diisi dengan arr[],ukuran. dengan var.totalJumlah =0, akan melakukan perulangan dari 0 dan totalJumlah nya = arr[i]+ totalJumlah.
untuk menghitung rata-rata nya masukkan rumus totalJumlah/ukuran


## Kesimpulan
Array digunakan untuk menyimpan banyak data, pointer dan reference mempermudah akses dan manipulasi nilai variabel, sedangkan prosedur/fungsi membantu membuat program lebih terstruktur dan efisien. Kombinasi konsep-konsep ini memungkinkan pengolahan data secara efektif, seperti penjumlahan elemen, pencarian nilai maksimum, dan pertukaran nilai variabel.

## Referensi

[1] Nabila Chairunnisa,S.Kom (2024). "Langkah mudah belajar pemrograman C++". Penerbit ANAK HEBAT INDONESIA
<br>[2]Hanief, S., Jepriana, I. W., & Kom, S. (2020). Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Penerbit Andi.
<br>[3]Modul-2 praktikum Telkom-University
