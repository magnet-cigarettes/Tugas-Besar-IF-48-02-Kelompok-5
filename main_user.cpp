#include <iostream>
#include "header.h"

using namespace std;

int main_user(){
    ListToko L;
    int opsi, id;
    adrToko T;
    adrProduk p;

    createListToko(L);

    while (opsi != 99) {
        cout << "\n=== MENU USER ===\n";
         cout << "1. Display Semua Toko\n";
         cout << "2. Display Produk per Toko\n";
         cout << "3. Cari Toko\n";
         cout << "4. Cari Produk\n";
         cout << "99. Out\n";
         cout << "Opsi: "; cin >> opsi;

         switch (opsi){
            case 1:
                showToko(L);
                break;

            case 2:
                cout << "Masukkan nama produk: "; cin >> id;
                p = findProduk(T, id);
                if(p){
                    cout << "\nDaftar produk di toko " << id;
                    showProduk(T);
                }else{
                    cout << "Toko tidak ditemukan";
                }
                break;

            case 3:
                cout << "Nama toko yang dicari: ", cin >> id;
                T = findToko(L, id);
                if (T){
                    cout << "Toko ditemukan\n";
                    cout << "Id Toko: " << T->info.idToko << endl;
                    cout << "Nama Toko: " << T->info.namaToko << endl;
                    cout << "Alamat: " << T->info.alamat << endl;
                }else{
                    cout << "Toko tidak ditemukan";
                }
                break;
            case 4:
                cout << "Masukkan id Toko: "; cin >> id;
                T = findToko(L, id);
                if(!T){
                    cout << "Toko tidak ditemukan\n";
                    break;
                }
                cout << "Masukkan id produk: "; cin >> id;
                p = findProduk(T, id);
                if (p){
                    cout << "\nProduk ditemukan\n";
                    cout << "Id: " << p->info.idProduk << endl;
                    cout << "Nama Produk: " << p->info.namaProduk << endl;
                    cout << "Stok: " << p->info.stok << endl;
                    cout << "Harga: " << p->info.harga << endl;
                    cout << "Pemasok: " << p->info.pemasok << endl;
                }else{
                    cout << "Produk tidak ditemukan\n";
                }
                break;

            case 99:
                cout << "Keluar menu user\n";
                break;

            default:
                cout << "Opsi tidak ada";
         }

    }while(opsi != 99);
    return 0;
}
