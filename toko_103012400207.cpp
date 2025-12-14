#include "header.h"
#include <iostream>

using namespace std;

void createListToko(ListToko &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrToko createToko(int idToko, string namaToko, string alamat){
    adrToko t = new elmToko;
    t->info.idToko = idToko;
    t->info.namaToko = namaToko;
    t->info.alamat = alamat;
    t->fProduk = nullptr;
    t->next = nullptr;
    t->prev = nullptr;

    return t;
}


void insertFirstToko(ListToko &L, adrToko t){
    if (L.first == nullptr) {
        L.first = t;
        L.last = t;
    } else {
        t->next = L.first;
        L.first->prev = t;
        L.first = t;
    }
}

void insertLastToko(ListToko &L, adrToko t){
    if (L.first == nullptr) {
        L.first = t;
        L.last = t;
    } else {
        L.last->next = t;
        t->prev = L.last;
        L.last = t;
    }
}

void insertAfterToko(ListToko &L, adrToko prec, adrToko t){
    if (prec != nullptr) {
        t->next = prec->next;
        t->prev = prec;

        if (prec->next != nullptr) {
            prec->next->prev = t;
        } else {
            L.last = t;
        }
        prec->next = t;
    }
}
