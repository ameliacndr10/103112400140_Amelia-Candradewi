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

void inputMhs(mahasiswa &m);
float nilaiAkhir(mahasiswa m);
#endif