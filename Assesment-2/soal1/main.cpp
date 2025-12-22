#include <iostream>
#include <string>
#include "bst.h"

using namespace std;

int main() {
    BinTree gudang;
    createTree(gudang);


    insertNode(gudang, alokasi(50, "Monitor LED", 10));
    insertNode(gudang, alokasi(30, "Keyboard RGB", 20));
    insertNode(gudang, alokasi(70, "Mouse Gaming", 15));
    insertNode(gudang, alokasi(20, "Kabel HDMI", 50));
    insertNode(gudang, alokasi(40, "Headset 7.1", 12));
    insertNode(gudang, alokasi(60, "Webcam HD", 8));
    insertNode(gudang, alokasi(80, "Speaket BT", 5));

    cout << "HASIL TRAVERSAL TREE" << endl;
    cout << "InOrder   : "; inOrder(gudang);   cout << endl;
    cout << "PreOrder  : "; preOrder(gudang);  cout << endl;
    cout << "PostOrder : "; postOrder(gudang); cout << endl;

    cout << "\nPENCARIAN BERDASARKAN ID" << endl;
    cout << "Search ID 40 : "; searchById(gudang, 40);
    cout << "Search ID 99 : "; searchById(gudang, 99);

    cout << "\nPENCARIAN BERDASARKAN NAMA PRODUK" << endl;
    cout << "Search Name 'Webcam HD' : "; searchByProduct(gudang, "Webcam HD");
    cout << "Search Name 'Printer'   : "; searchByProduct(gudang, "Printer");

    cout << "\nNILAI EKSTRIM PRODUK" << endl;
    if (!isEmpty(gudang)) {
        cout << "ID Produk Terkecil (Min) : " << findMin(gudang)->idProduk << endl;
        cout << "ID Produk Terbesar (Max) : " << findMax(gudang)->idProduk << endl;
    }

    cout << "\nPENGHAPUSAN DATA (ID: 20)" << endl;
    if (deleteNode(gudang, 20)) {
        cout << "Status: ID 20 berhasil dihapus." << endl;
    } else {
        cout << "Status: ID 20 tidak ditemukan." << endl;
    }
    cout << "InOrder terbaru : "; inOrder(gudang); cout << endl;

    cout << "\nPENGHAPUSAN DATA (ID: 30)" << endl;
    if (deleteNode(gudang, 30)) {
        cout << "Status: ID 30 berhasil dihapus." << endl;
    } else {
        cout << "Status: ID 30 tidak ditemukan." << endl;
    }
    cout << "InOrder terbaru : "; inOrder(gudang); cout << endl;

    cout << "\nPENGHAPUSAN DATA (ID: 50 - ROOT)" << endl;
    if (deleteNode(gudang, 50)) {
        cout << "Status: ID 50 berhasil dihapus." << endl;
    } else {
        cout << "Status: ID 50 tidak ditemukan." << endl;
    }
    cout << "InOrder terbaru : "; inOrder(gudang); cout << endl;

    cout << "\nPENGHAPUSAN SELURUH DATA TREE" << endl;
    deleteTree(gudang);
    cout << "Status: Seluruh pohon telah didelete." << endl;
    cout << "InOrder terbaru : "; 
    if (isEmpty(gudang)) {
        cout << "Tree Kosong";
    } else {
        inOrder(gudang);
    }
    cout << endl;
    cout << "========================================" << endl;

    return 0;
}