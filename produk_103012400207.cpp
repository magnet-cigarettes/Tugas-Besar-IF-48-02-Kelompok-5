#include "header.h"
#include <iostream>
using namespace std;

void deleteFirstProduk(adrToko t, adrProduk &P){
    if (!isEmptyProduk(t)) {
        P = t->fProduk;
        t->fProduk = P->next;
        P->next = nullptr;
    }
}
void deleteLastProduk(adrToko t, adrProduk &P){
    if (!isEmptyProduk(t)) {

        if (t->fProduk->next == nullptr) {
            deleteFirstProduk(t, P);
        } else {
            adrProduk Q = t->fProduk;

            while (Q->next->next != nullptr) {
                Q = Q->next;
            }

            P = Q->next;
            Q->next = nullptr;
            P->next = nullptr;
        }
    }
}
void deleteAfterProduk(adrToko t, adrProduk prec, adrProduk &P){
    if (prec != nullptr && prec->next != nullptr) {
        P = prec->next;
        prec->next = P->next;

        P->next = nullptr;
    }
}

adrProduk findProduk(adrToko t, int idProduk) {
    adrProduk P = t->fProduk;

    while (P != nullptr) {
        if (P->info.idProduk == idProduk) {
            return P;
        }
        P = P->next;
    }

    return nullptr;
}

void showProduk(adrToko t) {
    adrProduk p = t->fProduk;
    while (p != nullptr) {
        cout << "\n====================================\n";
        cout << "Id: " << p->info.idProduk << endl;
        cout << "Nama toko: " << p->info.namaProduk<< endl;
        cout << "Stok: " << p->info.stok << endl;
        cout << "Harga: " << p->info.harga << endl;
        cout << "Pemasok: " << p->info.pemasok << endl;

        p = p->next;
    }
}
