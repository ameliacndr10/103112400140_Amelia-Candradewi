# <h1 align="center">Laporan Praktikum MODUL 13 MULTI LINKED LIST</h1>
<p align="center">Amelia Candradewi- 103112400140</p>

## Dasar Teori
Multi linked list merupakan struktur data yang mengembangkan linked list biasa dengan setiap node memiliki lebih dari satu pointer, memungkinkan hubungan kompleks antar elemen seperti relasi parent-child atau multiple akses. Struktur ini cocok untuk menyimpan data dengan relasi banyak-ke-banyak, seperti penjualan sales atau pegawai dengan anak-anaknya.​

Karakteristik Utama nya Setiap node berisi data dan multiple pointer, berbeda dari single linked list yang hanya satu pointer next. Multi linked list mendukung akses simultan ke beberapa kumpulan list terpisah, menjaga organisasi data tanpa duplikasi. Keunggulannya termasuk fleksibilitas penyisipan/penghapusan tanpa geser elemen, meski traversal lebih lambat O(n).


## Guided 

### 1. INISIALISASI LIST MLL

## mll.h

```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild;  // alias pointeer ke struct nodeChild

struct nodeChild { //node child
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);

void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

## mll.cpp
```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

## main.cpp
```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

penjelasan singkat guided 1
Guided ini memberikan contoh code-code tentang MLL. Program ini terdiri dari code MLL, sudah tersedia data dummy di main.cpp nya

File mll.h
1.buat struct-struct untuk nodeParent dan nodeChild nya. 
2.buat alias pointer ke struct nodeParent dan alias pointer ke struct nodeChild.
3.buat struct-struct untuk nodeChild yang berisi isidata,next dan prev. lalu, buat struct untuk nodeParent yg berisi sama namun diakhir ditambahkan inisialisasi variabel untuk memanggil list anak
4.buat struct listAnak yang berisi first, last begitupun listInduk.
5.buat isEmpty Induk dan anak dgn panggil parameter yang sudah dibuat pada struct sebelumnya.
5.buat list untuk induk dan anak dengan parameter yg sam aditambah &.
6.buat alokasi untuk nodeParent dan NodeChild parameter diisi dengan struct struct nodeParent dan nodeChild nya. lalu, buat dealokasi untuk nodeParent dan nodeChild parameter memanggil struct nodeChild, nodeParent ditambahkan &.

--untuk operasi parent 
1.buat insert untuk parent dan delete untuk parent lalu, find parentByID yang dicari, lalu, update data parent by id.

--untuk operasi child
1.buat insert untuk child dan dekete untuk child lalu findChildByID yang dicari, lalu, upate data child by id.

--untuk operasi print 
1.buat printStrutur mll nya dengan parameter struct listInduk.
2.buat printListInduk nya dengan parameter struct listInduk.
3.buat printListAnak dengan parameter struct listInduk, panggil nodeparent nya.

--operasi hapus list
1.buat hapusListInduk
2.buat hapusListAnak



## Unguided 

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h”, lalu, lakukan operasi INSERT sebagaimana sehingga bentuk dari multi linked listnya

### 2.Tambahkan prosedur searchHewanByEkor(input/output LParent listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cp

### 3. Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked listnya berubah menjadi seperi ini

### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
using namespace std;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild{
    NodeChild first;
    NodeChild last;
};

struct nodeParent{
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};


bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent , NodeParent newNParent );
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent , NodeParent NPrev );

void insertFirstChild(listChild &LChild ,NodeChild  newNChild );
void insertLastChild(listChild &LChild , NodeChild newNChild );
void deleteFirstChild(listChild &LChild);
void deleteListChild(listChild &LChild);

// nomor 2
void searchHewanByEkor(listParent &LParent, bool tail);
// nomor 3
void printMLLStructure(listParent &LParent);
void deleteAfterChild(listChild &LChild , NodeChild NPrev );
#endif
```

### MultiLL.cpp
```C++
#include "MultiLL.h"
#include <iostream>

using namespace std;

bool isEmptyParent(listParent &LParent){
    if(LParent.first == NULL){
        return true;
    } else {
        return false;
    }
}
bool isEmptyChild(listChild &LChild){
    if(LChild.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListParent(listParent &LParent){
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild){
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent newNParent = new nodeParent;
    newNParent->isidata.idGolongan = idGol;
    newNParent->isidata.namaGolongan = namaGol;
    newNParent->next = NULL;
    newNParent->prev = NULL;
    createListChild(newNParent->L_Child);
    return newNParent;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight){
    NodeChild newNChild = new nodeChild;
    newNChild->isidata.idHewan = idHwn;
    newNChild->isidata.namaHewan = namaHwn;
    newNChild->isidata.habitat = habitat;
    newNChild->isidata.ekor = tail;
    newNChild->isidata.bobot = weight;
    newNChild->next = NULL;
    newNChild->prev = NULL;
    return newNChild;
}
void deallocNodeParent(NodeParent &NParent){
    if(NParent != NULL) {
        NParent->next = NParent->prev = NULL;
        delete NParent;
        NParent = NULL;
    }
}
void deallocNodeChild(NodeChild &NChild){
    if(NChild != NULL) {
        NChild->next = NChild->prev = NULL;
        delete NChild;
        NChild = NULL;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent) == true) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}
void insertLastParent(listParent &LParent , NodeParent newNParent ){
    if(isEmptyParent(LParent) == true) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent){
    if(isEmptyParent(LParent) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LParent.first;
        if (LParent.first == LParent.last) { // KASUS KHUSUS 1 ELEMEN
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Child.first != NULL){
        deleteListChild(nodeHapus->L_Child);
        }
        deallocNodeParent(nodeHapus);
    }
}
void deleteAfterParent(listParent &LParent , NodeParent NPrev ){
    if(isEmptyParent(LParent) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(NPrev != NULL && NPrev->next != NULL){
            NodeParent nodeHapus = NPrev->next;
            NPrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = NPrev;
            } else {
                LParent.last = NPrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Child.first != NULL){
            deleteListChild(nodeHapus->L_Child);
            }
            deallocNodeParent(nodeHapus);
        }
    }
}

void insertFirstChild(listChild &LChild ,NodeChild  newNChild ){
        if(isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}
void insertLastChild(listChild &LChild , NodeChild newNChild ){
if(isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}
void deleteFirstChild(listChild &LChild){
    if(isEmptyChild(LChild) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LChild.first;
        if (LChild.first == LChild.last) { // KASUS KHUSUS 1 ELEMEN
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        deallocNodeChild(nodeHapus);
    }
}
void deleteAfterChild(listChild &LChild , NodeChild NPrev ){
        if(isEmptyChild(LChild) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(NPrev != NULL && NPrev->next != NULL){
            NodeChild nodeHapus = NPrev->next;
            NPrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = NPrev;
            } else {
                LChild.last = NPrev;
            }
            nodeHapus->next = NULL;
            deallocNodeChild(nodeHapus);
            cout << "Node child setelah node " << NPrev->isidata.namaHewan << " berhasil dihapus!" << endl;
        }
    }
}
void printMLLStructure(listParent &LParent){
    if(isEmptyParent(LParent)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Golongan    : " << nodeBantuParent->isidata.idGolongan << endl;
            cout << "Nama Golongan  : " << nodeBantuParent->isidata.namaGolongan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Hewan     : " << nodeBantuChild->isidata.idHewan << endl;
                    cout << "      Nama Hewan   : " << nodeBantuChild->isidata.namaHewan << endl;
                    cout << "      Habitat      : " << nodeBantuChild->isidata.habitat << endl;
                    cout << "      Ekor         : " << nodeBantuChild->isidata.ekor << endl;
                    cout << "      Bobot        : " << nodeBantuChild->isidata.bobot << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
void deleteListChild(listChild &LChild){
    NodeChild nodeBantu = LChild.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        deallocNodeChild(nodeHapus);
    }
    LChild.first = LChild.last = NULL;
}

void searchHewanByEkor(listParent &LParent, bool tail){
    if(isEmptyParent(LParent) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.ekor == tail) {
                    cout << "Data ID hewan ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaGolongan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child               : " << nodeBantuChild->isidata.idHewan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Hewan             : " << nodeBantuChild->isidata.namaHewan << endl;
                    cout << "Ekor                   : " << nodeBantuChild->isidata.ekor << endl;
                    cout << "Bobot                  : " << nodeBantuChild->isidata.bobot << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent               : " << nodeBantuParent->isidata.idGolongan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama golongan           : " << nodeBantuParent->isidata.namaGolongan << endl;
                    cout << "---------------------------" << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                nodeBantuParent = nodeBantuParent->next;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}
```

### main.cpp
```C++
#include "MultiLL.h"
#include <iostream>

using namespace std;

int main() {
    //NOMOR 1
    listParent L;
    createListParent(L);

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = allocNodeParent("G001", "Aves");
    insertFirstParent(L, Kat1);
    NodeParent Kat2 =allocNodeParent("G002", "Mamalia");
    insertLastParent(L, Kat2);
    NodeParent Kat3 =allocNodeParent("G003", "Pisces");
    insertLastParent(L, Kat3);
    NodeParent Kat4 =allocNodeParent("G004", "Amfibi");
    insertLastParent(L, Kat4);
    NodeParent Kat5 =allocNodeParent("G005", "Reptil");
    insertLastParent(L, Kat5);

    cout << endl;

    // 3. Memasukkan Data Child (Nama Hewan) ke Kategori Tertentu
    // --> Isi Kategori AVES (G001)
    NodeChild Mkn1 =allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(Kat1->L_Child, Mkn1);
    NodeChild Mkn2 =allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(Kat1->L_Child, Mkn2);
    // --> Isi Kategori MAMALIA(G002)
    NodeChild Min1 =allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertLastChild(Kat2->L_Child, Min1);

    NodeChild Min2 =allocNodeChild("M003", "Gorila","Hutan", false, 160);
    insertLastChild(Kat2->L_Child, Min2);

    NodeChild Min3 =allocNodeChild("M002", "Kucing","Darat", true, 4);
    insertLastChild(Kat2->L_Child, Min3);

    // isi kategori AMFIBI G004
    NodeChild Des1 =allocNodeChild("AM001", "Kodok", "sawah", false, 0.2);
    insertLastChild(Kat4->L_Child, Des1);
    cout << endl;

    cout << "== NOMOR 1 ==" << endl;
    printMLLStructure(L);
    cout << endl;

    //NOMOR 2
    // 4. Test Pencarian (Find)
    cout << "== NOMOR 2 PENCARIAN ==" << endl;
    searchHewanByEkor(L, false); 

    // NOMOR 3
    cout << "== NOMOR 3 DELETE==" << endl;
    cout << "> Menghapus Parent Terakhir G004" << endl;
    deleteAfterParent(L,Kat3); 
    cout << "\n=== TAMPILAN AKHIR SETELAH DELETE ===" << endl;
    printMLLStructure(L);

    return 0;
}
```

### Output Unguided  :

##### Output soal 1
![Screenshot Output Unguided 1](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan11_Modul11-mll/Output-Unguided1.png)

##### Output soal 2
![Screenshot Output Unguided 2](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan11_Modul11-mll/Output-Unguided2.png)

##### Output soal 3
![Screenshot Output Unguided 3](https://github.com/ameliacndr10/103112400140_Amelia-Candradewi/blob/main/Pertemuan11_Modul11-mll/Output-Unguided3.png)

penjelasan unguided 1 
Program ini meminta untuk menuliskan data dummy di main.cpp menggunakan insert dari multi linked list nya. 

Penjelasan :
1. buat struct untuk golonganHewan yang berisi string idGolongan, string namaGolongan.
2. buat struct dataHewan yang berisi string idHewan, string namaHewan, string habitat, bool ekor, float bobot.
3. buat struct pointer NodeParents ke nodeParent,buat struct pointer NodeChild ke nodeChild.
4. buat struct nodeChild berisi dataHewan isidata, NodeChild next, NodeChild prev.
5. buat struct listChild berisi NodeChild first, NodeChild last,
6. buat struct nodeParent berisi golonganHewan isidata, NodeParent next, NodeParent prev, listChild L_Child.
7. buat struct listParent berisi NodeParent first, NodePArent last.

--function primitif--
1. bool isEmptyParent(listParent &LParent) -> cek apakah listparent pertama kosong benar atau tidak.
2. bool isEmptyChild(listChild &LChild) -> cek listchild pertama kosong benar atau tidak.
3. void createListParent(listParent &LParent)-> buat listparent kosong pertama dan terakhir.
4. void createListChild(listChild &LChild)-> buat listchild kosong pertama dan terakhir.

--function alokasi node parent--
1. NodeParent allocNodeParent(string idGol, string namaGol)-> buat variabel newParent sebagai new nodeParent. idGol berisi isidata dari golongan, namaGol berisi isidata dari namaGolongan, dan variabel newNparent next dan prev dikoosngkan. buat listChild yang diisi newNparent panggil L_Child nya.

2. NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight)-> buat variabel newChild sebagai new nodeChild, idHwn berisi isidata idHewan, namaHwn berisi isidata namaHewan, habitat berisi data habitat, tail berisi data ekor, weight berisi bobot, newNChild next, prev dikosongkan dan return newNchid.

3. void deallocNodeParent(NodeParent &NParent)-> jika NParent tidak kosong maka disi NParent selanjutnya dan Nparent prev NULL, delete NParent, NParent kosong.

4. void deallocNodeChild(NodeChild &NChild)-> jika NChild tidak kosong diisi Nchild sleanjutnya NChild prevkosong dan delete Nchild kosong.

--untuk insert dan delete untuk parent--
1. void insertFirstParent(listParent &LParent, NodeParent newNParent)-> cek jika isEmpty parent true  maka newNParent, newNParent next = LParent pertama, LParent pertama sebelumnya  = newNParent, LParent pertama = newNParent.  
2. void insertLastParent(listParent &LParent , NodeParent newNParent )->  cek jika isEmptyPArent true maka Lparent pertama dan terakhir = newNparent, newNParent prev = LParent last , dan selanjutnya = newNParent, jadi LParent last = newNParent.
3. void deleteFirstParent(listParent &LParent)-> cek jika isEmptyParent true cout list induk kosong. buat variabel nodeHApus untuk Lparent first. jika LParent first = Lparent last nya kosong. tetapi LParent pertana = selanjutnya  dan Lparent pertama sebelmunya NULL, nodeHapus setelahnya kosong.
jika nodehapus merupakan l child first tidak kosong maka delte list child  panggil nodehapus L_child. dealokasika node parent menajdi nodehapus
4. void deleteAfterParent(listParent &LParent , NodeParent NPrev )-> cek jika isEmptyParent true cout list induk kosong. buat variabel nodeHApus untuk Lparent first. jika NPrev tidak kosong dan NPrev selanjutnya tidak kosong, buat variabel nodeHapus  = Nprev selanjutnya= nodehapus selanjutnya. jika nodehapusnext tidak kosong, sbeelum nodehapus selanjutnya = NPrev, tetapi Lparent last juga = Nprev. nodehapus sleanjutnya kosong. 

jika nodehapus merupakan l child first tidak kosong maka delete list child  panggil nodehapus L_child. dealokasika node parent menajdi nodehapus

--untuk insert dan delete untuk child--
5. void insertFirstChild(listChild &LChild ,NodeChild  newNChild )-> cek isemptychild nya  lchild first dan last = newNchild. newnchild selanjutnya = lchild pertama, prev nya = newn child, jadi lchild first = newnchild. 
6. void insertLastChild(listChild &LChild , NodeChild newNChild )-> cek isemptychild nya  lchild first dan last = newNchild. newnshild prev = lchild last, selanjutnya = newn child juga, lchildlast juga newnchild
7. void deleteFirstChild(listChild &LChild)-> cek jika isemptychild true cout list anak kosong, tetapi buat nodehapus = lchildfirst, jika lchild pertama = l child next  dan sblmnya, nodehapus selanjutnya kosong. dealokasikan node child panggil nodehapus.
8. void deleteListChild(listChild &LChild)-> buat var nodebantu = l child first, ketika nodebantu tidak kosong, node hapus = nodebantu selanjutnya dealokasikan node child panggil nodehapus. l child first = l child last = null

// nomor 2
void searchHewanByEkor(listParent &LParent, bool tail)-> cek jika isempty parent true cout list induk koosng, buat var nodebantu parent = lparent first, lalu buat indexparent =1, buat perbandingan ketemu = false. ketika nodebantu tidak kosong, node bantu child = nodebantuparent kemudian l child first, int indexchild nya 1. jika ketemu search by ekor nya true maka ter-output data yang dicari kemudian break. jika tidak ketemu teroutput data ide child tidak ditemukan dalam list anak.

// nomor 3
1. void printMLLStructure(listParent &LParent)-> cek is empty parent. buat nodebantuparent = lparent first, int indexparent =1. ketika nodebantuparent tidak kosong teroutput data parent beserta id dan nama yg sudah dipanggil. print list anak dari node parentnya, buat variabel nodebantuchild  da int indeks child =1 ketika nodebantu child tidak kosong trr-output data-data nya seperti: child, id hewan, nama hewan, habitat, ekor, bobot.

2. void deleteAfterChild(listChild &LChild , NodeChild NPrev )-> cek isemptychild, jika nprev tidak kosong dan nprev selanjutnya tidak kosong buat variabel nodebantu = nprev selanjutnya = nodehapus selanjutnya. jika nodehapus selnjutnya tidak ksoong maka, sebelum nodehapus selanjutnya = nprev. l childlast = kosong. dealokasi nodechild anggil nodehapus. 


## Kesimpulan
Multi Linked List adalah pengembangan dari Linked List tradisional, di mana setiap node tidak hanya menyimpan data, tetapi juga lebih dari satu pointer. Struktur data ini memungkinkan pembuatan hubungan yang kompleks antar elemen, seperti relasi banyak-ke-banyak atau parent-child

## Referensi
[1]Jurnal Modul 10 - Multi Linked List. (2025). Diakses dari https://id.scribd.com/document/618400689/Jurnal-Modul-10-Multi-Linked-List​
<br>[2] Nabila Chairunnisa,S.Kom (2024). "Langkah mudah belajar pemrograman C++". Penerbit ANAK HEBAT INDONESIA
[2]
