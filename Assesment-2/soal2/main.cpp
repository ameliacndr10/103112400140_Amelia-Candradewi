#include "mll.h"
#include <iostream>
using namespace std;

int main() {
    // No. 1
    listParent L;
    createListParent(L);

    // No. 2
    NodeParent G4 = alokasiNodeParent("G004", "Romance");
    insertFirstParent(L, G4);
    NodeParent G3 = alokasiNodeParent("G003", "Horror");
    insertFirstParent(L, G3);
    NodeParent G2 = alokasiNodeParent("G002", "Comedy");
    insertFirstParent(L, G2);
    NodeParent G1 = alokasiNodeParent("G001", "Action");
    insertFirstParent(L, G1);

    insertLastChild(G1->L_Anak, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));    
    insertLastChild(G2->L_Anak, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(G2->L_Anak, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
    insertLastChild(G3->L_Anak, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
    insertLastChild(G4->L_Anak, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(G4->L_Anak, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    // No. 3
    cout << "=== DIAWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // No. 4
    cout << "4) searchFilmByRatingRange() dengan rentang rating 8.0 - 8.5" << endl;
    searchFilmByRatingRange(L, 8.0, 8.5);
    cout << endl;

    // No. 5
    cout << "5) deleteAfterParent(), delete node G002 (prev-nya G001)" << endl;
    deleteAfterParent(L, G1);
    cout << endl;

    // No. 6
    cout << "6) printStrukturMLL() " << endl;
    printStrukturMLL(L);

    return 0;
}