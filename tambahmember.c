#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur Data Member
typedef struct {
    char id[10];
    char nama[50];
    int poin;
} Member;

// Fungsi untuk menambah member
void tambahMember() {
    Member member;
    FILE *file = fopen("member.txt", "a");

    if (file == NULL) {
        printf("File member.txt tidak dapat dibuka.\n");
        return;
    }

    // Input data member
    printf("Masukkan ID Member: ");
    scanf("%s", member.id);
    printf("Masukkan Nama Member: ");
    scanf(" %[^\n]", member.nama);  // Mengizinkan spasi dalam nama
    member.poin = 0;  // Poin awal untuk member baru

    // Menyimpan data member ke file
    fprintf(file, "%s|%s|%d\n", member.id, member.nama, member.poin);
    fclose(file);

    printf("Member berhasil ditambahkan!\n");
}

int main() {
    tambahMember();
    return 0;
}
