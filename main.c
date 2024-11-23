#include "header.h"

int main() {
    int pilihanLogin;
    int statusLogin = 0;
    char idMember[10];  // ID member untuk login

    // Pilihan untuk login admin atau member
    printf("Pilih login:\n");
    printf("1. Login Admin\n");
    printf("2. Login Member\n");
    printf("Masukkan pilihan (1/2): ");
    scanf("%d", &pilihanLogin);

    if (pilihanLogin == 1) {
        // Login sebagai Admin
        statusLogin = loginAdmin();
        if (statusLogin) {
            printf("Login Admin berhasil. Anda dapat mengakses menu admin.\n");
        } else {
            printf("Login Admin gagal.\n");
        }
    } else if (pilihanLogin == 2) {
        // Login sebagai Member
        statusLogin = loginMember(idMember);
        if (statusLogin) {
            printf("Login Member berhasil. ID Member: %s\n", idMember);
        } else {
            printf("Login Member gagal.\n");
        }
    } else {
        printf("Pilihan tidak valid.\n");
    }

    return 0;
}
