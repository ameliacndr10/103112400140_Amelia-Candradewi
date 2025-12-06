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