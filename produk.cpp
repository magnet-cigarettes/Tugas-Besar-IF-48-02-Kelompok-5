#include "indoapril.h"
#include <iostream>
using namespace std;

adrProduk createProduk(string nama, int stok, int harga, string pemasok) {
    adrProduk P = new elmProduk;
    P->namaProduk = nama;
    P->stok = stok;
    P->harga = harga;
    P->pemasok = pemasok;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertProduk(adrProduk &first, adrProduk &last, adrProduk P) {
    if (first == nullptr) {
        first = last = P;
    } else {
        last->next = P;
        P->prev = last;
        last = P;
    }
}

adrProduk findProduk(adrProduk first, string nama) {
    adrProduk p = first;
    while (p != nullptr) {
        if (p->namaProduk == nama) return p;
        p = p->next;
    }
    return nullptr;
}

void deleteFirstProduk(adrProduk &first, adrProduk &last) {
    adrProduk p = first;
    if (first == nullptr) {
        cout << "List produk kosong.\n";
        return;
    }
    if (first == last) {
        first = last = nullptr;
    } else {
        first = first->next;
        first->prev = nullptr;
    }
    p->next = nullptr;
    p->prev = nullptr;

    cout << "Delete first produk berhasil.\n";
}

void deleteLastProduk(adrProduk &first, adrProduk &last) {
    adrProduk p = last;

    if (first == nullptr){
        return;
    }
    if (first == last) {
        deleteFirstProduk(first, last);
        return;
    }

    last = last->prev;
    last->next = nullptr;
    p->prev = nullptr;

    cout << "Delete last produk berhasil.\n";
}

void deleteAfterProduk(adrProduk &first, adrProduk &last, string namaPrev) {
    adrProduk p = findProduk(first, namaPrev);
    adrProduk q = p->next;

    if (p == nullptr || p->next == nullptr) {
        cout << "Tidak bisa delete\n";
        return;
    }
    if (q == last) {
        last = p;
        p->next = nullptr;
    } else {
        p->next = q->next;
        q->next->prev = p;
    }
    q->next = nullptr;
    q->prev = nullptr;

    cout << "Delete after produk berhasil.\n";
}

void deleteProduk(adrProduk &first, adrProduk &last, string nama) {
    adrProduk p = findProduk(first, nama);

    if (p == nullptr) {
        cout << "Produk tidak ditemukan.\n";
        return;
    }
    if (first == last && p == first) {
        first = last = nullptr;
        p->next = nullptr;
        p->prev = nullptr;
        cout << "Produk berhasil dihapus (satu-satunya item).\n";
        return;
    }
    if (p == first) {
        deleteFirstProduk(first, last);
        return;
    }
    if (p == last) {
        deleteLastProduk(first, last);
        return;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->next = nullptr;
    p->prev = nullptr;

    cout << "Produk berhasil dihapus (middle).\n";
}

void showProduk(adrProduk first) {
    adrProduk p = first;
    while (p != nullptr) {
        cout << " - " << p->namaProduk;
        cout << " | Stok: " << p->stok;
        cout << " | Harga: " << p->harga;
        cout << " | Pemasok: " << p->pemasok << endl;
        p = p->next;
    }
}
