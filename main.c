#include "header.h"

int main() {
    int statusLogin;
    char idMember[10];
    int pilihanLogin;

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
    } else if (pilihanLogin == 2) {
        // Login sebagai Member
        statusLogin = loginMember(idMember);
        if (statusLogin != 0) {
            // Menu Member
            menuMember();
        } else {
            printf("Login member gagal.\n");
        }
    } else {
        printf("Pilihan tidak valid.\n");
    }

    return 0;
}
