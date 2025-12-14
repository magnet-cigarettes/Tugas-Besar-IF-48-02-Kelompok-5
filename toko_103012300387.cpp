#include "header.h"
#include <iostream>

using namespace std;

void deleteFirstToko(ListToko &L, adrToko &P){
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = nullptr;
        P->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteLastToko(ListToko &L, adrToko &P){
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.last;
        L.last = P->prev;
        L.last->next = nullptr;
        P->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfterToko(ListToko &L, adrToko prec, adrToko &P){
    if (prec == nullptr || prec->next == nullptr) {
        P = nullptr;
    } else {
        P = prec->next;
        if (P == L.last) {
            L.last = prec;
            prec->next = nullptr;
            P->prev = nullptr;
            P->next = nullptr;
        } else {
            prec->next = P->next;
            P->next->prev = prec;
            P->next = nullptr;
            P->prev = nullptr;
        }
    }
}

adrToko findToko(ListToko L, int idToko){
    adrToko t = L.first;
    while (t != nullptr) {
        if (t->info.idToko == idToko) {
            return t;
        }
        t = t->next;
    }
    return nullptr;
}

void showToko(ListToko L) {
    adrToko t = L.first;
    while (t != nullptr) {
        cout << "\n====================================\n";
        cout << "Id: " << t->info.idToko << endl;
        cout << "Nama toko: " << t->info.namaToko<< endl;
        cout << "Alamat: " << t->info.alamat << endl;

        t = t->next;
    }
}
