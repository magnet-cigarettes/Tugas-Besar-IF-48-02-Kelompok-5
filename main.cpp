#include <iostream>
#include "indoapril.h"

using namespace std;

int main(){
    ListToko LT;
    createListToko(LT);

    int menu = 0;

    while (menu != 99) {
        cout << "\n==== MENU TOKO ====\n";
        cout << "1. Tambah Toko\n";
        cout << "2. Tambah Produk ke Toko\n";
        cout << "3. Lihat Semua Toko & Produk\n";
        cout << "4. Hapus Toko\n";
        cout << "5. Hapus Produk dari Toko\n";
        cout << "99. Exit\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            int id;
            string nama, alamat;

            cout << "ID Toko : ";
            cin >> id;
            cout << "Nama    : ";
            cin >> nama;
            cout << "Alamat  : ";
            cin >> alamat;

            insertToko(LT, createToko(id, nama, alamat));
        }

        else if (menu == 2) {
            int id;
            cout << "Masukkan ID Toko: ";
            cin >> id;

            adrToko T = findToko(LT, id);
            if (!T) {
                cout << "Toko tidak ditemukan!\n";
                continue;
            }

            string namaProduk, pemasok;
            int stok;
            int harga;

            cout << "Nama Produk : ";
            cin >> namaProduk;
            cout << "Stok        : ";
            cin >> stok;
            cout << "Harga       : ";
            cin >> harga;
            cout << "Pemasok     : ";
            cin >> pemasok;

            adrProduk P = createProduk(namaProduk, stok, harga, pemasok);
            insertProduk(T->firstProduk, T->lastProduk, P);
        }

        else if (menu == 3) {
            showToko(LT);
        }

        else if (menu == 4) {
            int id;
            cout << "Masukkan ID Toko yang ingin dihapus: ";
            cin >> id;

            deleteToko(LT, id);
        }

        else if (menu == 5) {
            int id;
            cout << "Masukkan ID Toko: ";
            cin >> id;

            adrToko T = findToko(LT, id);
            if (!T) {
                cout << "Toko tidak ditemukan!\n";
                continue;
            }

            string namaProduk;
            cout << "Nama produk yang ingin dihapus: ";
            cin >> namaProduk;

            deleteProdukFromToko(T, namaProduk);
        }
    }
    return 0;
}
