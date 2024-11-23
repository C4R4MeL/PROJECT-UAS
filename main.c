#include "header.h"

int main() {
    int statusLogin;
    char idMember[10];
    int pilihanLogin;

    do {
        // Menampilkan pilihan login
        printf("Login Sebagai:\n");
        printf("1. Admin\n");
        printf("2. Member\n");
        printf("Pilih (1/2): ");
        scanf("%d", &pilihanLogin);

        if (pilihanLogin == 1) {
            // Login sebagai Admin
            statusLogin = loginAdmin();
            if (statusLogin != 0) {
                // Menu Admin
                menuAdmin();
            } else {
                printf("Login admin gagal.\n");
            }
            break;  // Keluar dari loop setelah login berhasil
        } else if (pilihanLogin == 2) {
            // Login sebagai Member
            statusLogin = loginMember(idMember);
            if (statusLogin != 0) {
                // Menu Member
                menuMember();
            } else {
                printf("Login member gagal.\n");
            }
            break;  // Keluar dari loop setelah login berhasil
        } else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (1);  // Loop sampai login berhasil

    return 0;
}
