#include "header.h"

// Fungsi untuk menambah member
void tambahMember() {
    Member member;
    FILE *file = fopen(FILE_MEMBER, "a");

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

