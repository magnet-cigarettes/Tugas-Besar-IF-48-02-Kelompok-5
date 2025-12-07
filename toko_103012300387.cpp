#include "indoapril.h"
#include <iostream>

using namespace std;

void createListToko(ListToko &L) {
    L.first = nullptr;
}

adrToko createToko(int id, string nama, string alamat) {
    adrToko P = new elmToko;
    P->idToko = id;
    P->namaToko = nama;
    P->alamat = alamat;
    P->firstProduk = nullptr;
    P->lastProduk = nullptr;
    P->next = nullptr;
    return P;
}

void insertToko(ListToko &L, adrToko P) {
    P->next = L.first;
    L.first = P;
}

adrToko findToko(ListToko L, int id) {
    adrToko p = L.first;

    while (p != nullptr && p->idToko != id) {
        p = p->next;
    }
    return p;
}

void deleteFirstToko(ListToko &L) {
    adrToko p = L.first;

    if (L.first == nullptr) {
        cout << "List toko kosong.\n";
        return;
    }
    L.first = p->next;
    p->firstProduk = nullptr;
    p->lastProduk = nullptr;
    p->next = nullptr;

    cout << "Delete first toko berhasil.\n";
}

void deleteLastToko(ListToko &L) {
    adrToko p = L.first;
    adrToko prev = nullptr;

    if (L.first == nullptr) {
        cout << "List toko kosong.\n";
        return;
    }
    if (L.first->next == nullptr) {
        deleteFirstToko(L);
        return;
    }
    while (p->next != nullptr) {
        prev = p;
        p = p->next;
    }

    prev->next = nullptr;
    p->firstProduk = nullptr;
    p->lastProduk = nullptr;

    cout << "Delete last toko berhasil.\n";
}

void deleteAfterToko(ListToko &L, int idPrev) {
    adrToko p = findToko(L, idPrev);
    adrToko q = p->next;

    if (p == nullptr || p->next == nullptr) {
        cout << "Tidak bisa deleteAfter.\n";
        return;
    }
    p->next = q->next;
    q->firstProduk = nullptr;
    q->lastProduk = nullptr;
    q->next = nullptr;

    cout << "Delete after toko berhasil.\n";
}

void deleteToko(ListToko &L, int id) {
    adrToko p = L.first;
    adrToko prev = nullptr;

    if (L.first == nullptr) {
        cout << "List toko kosong.\n";
        return;
    }
    if (p->idToko == id) {
        deleteFirstToko(L);
        return;
    }
    while (p != nullptr && p->idToko != id) {
        prev = p;
        p = p->next;
    }
    if (p == nullptr) {
        cout << "Toko tidak ditemukan.\n";
        return;
    }
    if (p->next == nullptr) {
        deleteLastToko(L);
        return;
    }
    prev->next = p->next;
    p->firstProduk = nullptr;
    p->lastProduk = nullptr;
    p->next = nullptr;

    cout << "Toko berhasil dihapus.\n";
}

void showToko(ListToko L) {
    adrToko p = L.first;

    while (p != nullptr) {
        cout << "===========================\n";
        cout << "ID Toko : " << p->idToko << endl;
        cout << "Nama    : " << p->namaToko << endl;
        cout << "Alamat  : " << p->alamat << endl;

        cout << "\nProduk:\n";
        if (p->firstProduk == nullptr)
            cout << "  (Tidak ada produk)\n";
        else
            showProduk(p->firstProduk);

        p = p->next;
    }
}

void deleteProdukFromToko(adrToko T, string namaProduk) {
    if (T == nullptr) return;
    if (T->firstProduk == nullptr) {
        cout << "Produk kosong!\n";
        return;
    }

    deleteProduk(T->firstProduk, T->lastProduk, namaProduk);
    cout << "Produk berhasil dihapus.\n";
}
