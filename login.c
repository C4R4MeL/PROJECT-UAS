#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// *** Konstanta ***
#define FILE_ADMIN "admin.txt"
#define FILE_MEMBER "member.txt"

// *** Fungsi untuk Login Admin ***
int loginAdmin() {
    char username[50], password[50], uname[50], pass[50];
    FILE *file = fopen(FILE_ADMIN, "r");
    if (file == NULL) {
        printf("File admin.txt tidak ditemukan.\n");
        return 0;
    }

    printf("=== Login Admin ===\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    while (fscanf(file, "%s %s", uname, pass) != EOF) {
        if (strcmp(username, uname) == 0 && strcmp(password, pass) == 0) {
            fclose(file);
            printf("Login admin berhasil.\n");
            return 1; // Login berhasil
        }
    }

    fclose(file);
    printf("Login admin gagal. Username atau password salah.\n");
    return 0; // Login gagal
}

// *** Fungsi untuk Login Member ***
int loginMember(char *idMember) {
    char id[10], nama[50];
    int poin;
    FILE *file = fopen(FILE_MEMBER, "r");

    if (file == NULL) {
        printf("File member.txt tidak ditemukan.\n");
        return 0;
    }

    printf("=== Login Member ===\n");
    printf("ID Member: ");
    scanf("%s", idMember);

    while (fscanf(file, "%s %s %d", id, nama, &poin) != EOF) {
        if (strcmp(id, idMember) == 0) {
            fclose(file);
            printf("Login member berhasil. Selamat datang, %s!\n", nama);
            return 1; // Login berhasil
        }
    }

    fclose(file);
    printf("Login member gagal. ID member tidak ditemukan.\n");
    return 0; // Login gagal
}
