#include <iostream>
#include "header.h"

using namespace std;

int main_admin(){
    ListToko L;
    createListToko(L);

    int opsi, id, stok, harga;
    string nama, alamat, pemasok;
    adrToko T,d, precT;
    adrProduk P, precP;

    while (opsi != 99) {
        cout << "\n===== MENU ADMIN TOKO & PRODUK =====\n";
        cout << "1. Tambah Toko (insert first)\n";
        cout << "2. Tambah Toko (insert last)\n";
        cout << "3. Tambah Toko (insert after)\n";
        cout << "4. Hapus Toko (delete first)\n";
        cout << "5. Hapus Toko (delete last)\n";
        cout << "6. Hapus Toko (delete after)\n";
        cout << "7. Cari Toko\n";
        cout << "8. Tampilkan Semua Toko\n";

        cout << "\n=== MENU PRODUK ===\n";
        cout << "9. Tambah Produk (insert first)\n";
        cout << "10. Tambah Produk (insert last)\n";
        cout << "11. Tambah Produk (insert after)\n";
        cout << "12. Hapus Produk (delete first)\n";
        cout << "13. Hapus Produk (delete last)\n";
        cout << "14. Hapus Produk (delete after)\n";
        cout << "15. Cari Produk\n";
        cout << "16. Tampilkan Semua Produk\n";

        cout << "Opsi: ";
        cin >> opsi;

        switch (opsi) {

        case 1:
            cout << "ID Toko : "; cin >> id;
            cout << "Nama     : "; cin >> nama;
            cout << "Alamat     : "; cin >> alamat;

            T = createToko(id, nama, alamat);
            insertFirstToko(L, T);
            cout << "Toko berhasil ditambahkan.\n";
            break;

        case 2:
            cout << "ID Toko : "; cin >> id;
            cout << "Nama     : "; cin >> nama;
            cout << "Alamat     : "; cin >> alamat;

            T = createToko(id, nama, alamat);
            insertLastToko(L, T);
            cout << "Toko berhasil ditambahkan.\n";
            break;

        case 3:
            cout << "ID Toko yang dituju: ";
            cin >> id;

            precT = findToko(L, id);
            if (precT != nullptr) {
                cout << "ID Toko baru : "; cin >> id;
                cout << "Nama Toko    : "; cin >> nama;
                cout << "Alamat          : "; cin >> alamat;

                T = createToko(id, nama, alamat);
                insertAfterToko(L, precT, T);
                cout << "Insert-after berhasil.\n";
            } else {
                cout << "Toko tidak ditemukan.\n";
            }
            break;

        case 4:
            deleteFirstToko(L, d);
            if (d) {
                cout << "Toko dihapus: " << d->info.namaToko << endl;
            } else {
                cout << "List kosong.\n";
            }
            break;

        case 5:
            deleteLastToko(L, d);
            if (d) {
                cout << "Toko dihapus: " << d->info.namaToko << endl;
            } else {
                cout << "Toko tidak ditemukan.\n";
            }
            break;

        case 6:
            cout << "ID Toko yang dituju: ";
            cin >> id;

            precT = findToko(L, id);
            if (precT) {
                deleteAfterToko(L, precT, d);
                if (d) {
                    cout << "Toko dihapus: " << d->info.idToko << endl;
                } else {
                    cout << "Tidak ada Toko setelah yang dituju.\n";
                }
            } else {
                cout << "Toko tidak ditemukan.\n";
            }
            break;

        case 7:
            cout << "Masukkan ID Toko: ";
            cin >> id ;

            T = findToko(L, id);
            if (T) {
                cout << "ID   : " << T->info.idToko << endl;
                cout << "Nama Toko : " << T->info.namaToko << endl;
                cout << "Alamat : " << T->info.alamat << endl;
            } else {
                cout << "Toko tidak ditemukan.\n";
            }
            break;

        case 8:
            showToko(L);
            break;

        case 9:
            cout << "ID Toko: ";
            cin >> id;

            T = findToko(L, id);
            if (T) {
                cout << "ID Produk: "; cin >> id;
                cout << "Nama Produk: "; cin >> nama;
                cout << "Stok: "; cin >> stok;
                cout << "Harga: "; cin >> harga;
                cout << "Pemasok: "; cin >> pemasok;

                P = createProduk(id, nama, stok, harga, pemasok);
                insertFirstProduk(T, P);

                cout << "Produk berhasil ditambahkan.\n";
            } else {
                cout << "Toko tidak ditemukan.\n";
            }
            break;

        case 10:
            cout << "ID Toko: ";
            cin >> id;

            T = findToko(L, id);
            if (T) {
                cout << "ID Produk: "; cin >> id;
                cout << "Nama Produk: "; cin >> nama;
                cout << "Stok: "; cin >> stok;
                cout << "Harga: "; cin >> harga;
                cout << "Pemasok: "; cin >> pemasok;

                P = createProduk(id, nama, stok, harga, pemasok);
                insertLastProduk(T, P);

                cout << "Produk berhasil ditambahkan.\n";
            } else {
                cout << "Toko tidak ditemukan.\n";
            }
            break;

        case 11:
            cout << "ID Toko: ";
            cin >> id;

            T = findToko(L, id);
            if (T) {
                cout << "ID Produk yang dituju: ";
                cin >> id;

                precP = findProduk(T, id);
                if (precP) {
                    cout << "ID Produk baru: "; cin >> id;
                    cout << "Nama Produk: "; cin >> nama;
                    cout << "Stok: "; cin >> stok;
                    cout << "Harga: "; cin >> harga;
                    cout << "Pemasok: "; cin >> pemasok;

                    P = createProduk(id, nama, stok, harga, pemasok);
                    insertAfterProduk(T, precP, P);

                    cout << "Insert-after berhasil.\n";
                } else {
                    cout << "Produk yang dituju tidak ditemukan.\n";
                }
            }
            break;

        case 12:
            cout << "ID Toko: ";
            cin >> id;

            T = findToko(L, id);
            if (T) {
                deleteFirstProduk(T, P);
                if (P) {
                    cout << "Produk dihapus: " << P->info.idProduk << endl;
                } else {
                    cout << "Produk tidak ditemukan.\n";
                }
            }
            break;

        case 13:
            cout << "ID Toko: ";
            cin >> id;

            T = findToko(L, id);
            if (T) {
                deleteLastProduk(T,P);
                if (P) {
                    cout << "Produk dihapus: " << P->info.idProduk << endl;
                } else {
                    cout << "Produk tidak ditemukan.\n";
                }
            }
            break;

        case 14:
            cout << "ID Toko: ";
            cin >> id;

            T = findToko(L, id);
            if (T) {
                cout << "ID Produk yang dituju: ";
                cin >> id;

                precP = findProduk(T, id);
                if (precP) {
                    deleteAfterProduk(T, precP, P);
                    if (P) {
                        cout << "Produk dihapus: " << P->info.idProduk << endl;
                    } else {
                        cout << "Tidak ada produk setelah yang dituju.\n";
                    }
                }
            }
            break;

        case 15:
            cout << "ID Toko: ";
            cin >> id;

            T = findToko(L, id);
            if (T) {
                cout << "ID Produk: ";
                cin >> id;

                P = findProduk(T, id);
                if (P) {
                    cout << "ID Produk     : " << P->info.idProduk << endl;
                    cout << "Nama Produk: " << P->info.namaProduk << endl;
                    cout << "Stok       : " << P->info.stok << endl;
                    cout << "Harga    :" << P->info.harga << endl;
                    cout << "Pemasok   " << P->info.pemasok << endl;
                } else {
                    cout << "Produk tidak ditemukan.\n";
                }
            }
            break;

        case 16:
            cout << "ID Toko: ";
            cin >> id;

            T = findToko(L, id);
            if (T) {
                showProduk(T);
            }
            break;

        case 0:
            return 0;

        default:
            cout << "Opsi tidak valid.\n";
        }
    }
}
