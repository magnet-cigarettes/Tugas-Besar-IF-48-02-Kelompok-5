#include <iostream>
#include "header.h"
using namespace std;

void main_admin();
void main_user();

int main() {
    int opsi;
    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Login Admin\n";
        cout << "2. Login User\n";
        cout << "99. Keluar\n";
        cout << "Opsi: "; cin >> opsi;

        switch (opsi) {
            case 1:
                main_admin();
                break;
            case 2:
                main_user();
                break;
            case 99:
                cout << "Keluar program.\n";
                return 0;
            default:
                cout << "Pilihan salah! Coba lagi.\n";
        }
    } while (opsi != 99);

    return 0;
}
