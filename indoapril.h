#ifndef PRODUK_H_INCLUDED
#define PRODUK_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct elmProduk *adrProduk;
typedef struct elmToko *adrToko;

struct elmProduk {
    string namaProduk;
    int stok;
    int harga;
    string pemasok;

    adrProduk next;
    adrProduk prev;
};

struct elmToko {
    int idToko;
    string namaToko;
    string alamat;

    adrProduk firstProduk;
    adrProduk lastProduk;
    adrToko next;
};

struct ListToko {
    adrToko first;
};


adrProduk createProduk(string nama, int stok, int harga, string pemasok);
void insertProduk(adrProduk &first, adrProduk &last, adrProduk P);
adrProduk findProduk(adrProduk first, string nama);
void deleteProduk(adrProduk &first, adrProduk &last, string nama);
void deleteFirstProduk(adrProduk &first, adrProduk &last);
void deleteLastProduk(adrProduk &first, adrProduk &last);
void deleteAfterProduk(adrProduk &first, adrProduk &last, string namaPrev);
void showProduk(adrProduk first);

void createListToko(ListToko &L);
adrToko createToko(int id, string nama, string alamat);
void insertToko(ListToko &L, adrToko P);
adrToko findToko(ListToko L, int id);
void deleteToko(ListToko &L, int id);
void deleteFirstToko(ListToko &L);
void deleteLastToko(ListToko &L);
void deleteAfterToko(ListToko &L, int idPrev);
void showToko(ListToko L);
void deleteProdukFromToko(adrToko T, string namaProduk);

#endif // PRODUK_H_INCLUDED
