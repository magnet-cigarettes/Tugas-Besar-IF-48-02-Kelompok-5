#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED

#include <iostream>
using namespace std;

typedef struct Toko infoToko;
typedef struct elmToko *adrToko;

typedef struct Produk infoProduk;
typedef struct elmProduk *adrProduk;

struct Toko {
    int idToko;
    string namaToko;
    string alamat;
};

struct elmToko {
    infoToko info;
    adrProduk fProduk;
    adrToko next;
    adrToko prev;
};

struct ListToko {
    adrToko first;
    adrToko last;
};

struct Produk {
    int idProduk;
    string namaProduk;
    int stok;
    int harga;
    string pemasok;
};

struct elmProduk {
    infoProduk info;
    adrProduk next;
};

void createListToko(ListToko &L);
adrToko createToko(int idToko, string namaToko, string alamat);
bool isEmptyToko(ListToko L);

void insertFirstToko(ListToko &L, adrToko t);
void insertLastToko(ListToko &L, adrToko t);
void insertAfterToko(ListToko &L, adrToko prec, adrToko t);

void deleteFirstToko(ListToko &L, adrToko &P);
void deleteLastToko(ListToko &L, adrToko &P);
void deleteAfterToko(ListToko &L, adrToko prec, adrToko &P);

adrToko findToko(ListToko L, int idToko);
void showToko(ListToko L);

adrProduk createProduk(int idProduk, string namaProduk, int stok, int harga, string namaPemasok);
bool isEmptyProduk(adrToko t);

void insertFirstProduk(adrToko t, adrProduk P);
void insertLastProduk(adrToko t, adrProduk P);
void insertAfterProduk(adrToko t, adrProduk prec, adrProduk P);

void deleteFirstProduk(adrToko t, adrProduk &P);
void deleteLastProduk(adrToko t, adrProduk &P);
void deleteAfterProduk(adrToko t, adrProduk prec, adrProduk &P);

adrProduk findProduk(adrToko t, int idProduk);
void showProduk(adrToko t);
#endif
