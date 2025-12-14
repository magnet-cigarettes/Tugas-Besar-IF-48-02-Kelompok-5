#include "header.h"
#include <iostream>
using namespace std;

adrProduk createProduk(int idProduk, string namaProduk, int stok, int harga, string pemasok){
    adrProduk p = new elmProduk;
    p->info.idProduk = idProduk;
    p->info.namaProduk = namaProduk;
    p->info.stok = stok;
    p->info.harga = harga;
    p->info.pemasok = pemasok;
    p->next = nullptr;
    return p;
}

bool isEmptyProduk(adrToko t){
    return (t == nullptr || t->fProduk == nullptr);
}

void insertFirstProduk(adrToko t, adrProduk P){
    if (t->fProduk == nullptr) {
        t->fProduk = P;
    } else {
        P->next = t->fProduk;
        t->fProduk = P;
    }
}

void insertLastProduk(adrToko t, adrProduk P){
    if (t->fProduk== nullptr) {
        t->fProduk = P;
    } else {
        adrProduk Q = t->fProduk;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterProduk(adrToko t, adrProduk prec, adrProduk P){
    if (prec != nullptr) {
        P->next = prec->next;
        prec->next = P;
    }
}
