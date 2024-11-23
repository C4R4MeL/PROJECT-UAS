#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk mengecek apakah ID sudah ada
int idSudahAda(const char *id) {
    FILE *file = fopen(FILE_MEMBER, "r");
    if (file == NULL) {
        return 0; // Jika file tidak ada, ID dianggap belum ada
    }

    Member temp;
    while (fscanf(file, "%s %s %d", temp.id, temp.nama, &temp.poin) != EOF) {
        if (strcmp(temp.id, id) == 0) {
            fclose(file);
            return 1; // ID ditemukan
        }
    }

    fclose(file);
    return 0; // ID tidak ditemukan
}

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

    // Validasi ID unik
    if (idSudahAda(member.id)) {
        printf("ID Member sudah ada. Silakan gunakan ID lain.\n");
        fclose(file);
        return;
    }

    // Menggunakan getchar() untuk membersihkan newline setelah scanf sebelumnya
    getchar();  // Menyerap karakter newline yang tertinggal di buffer setelah scanf

    printf("Masukkan Nama Member: ");
    scanf("%[^\n]", member.nama);  // Mengizinkan spasi dalam nama
    member.poin = 0;  // Poin awal untuk member baru

    // Menyimpan data member ke file
    fprintf(file, "%s %s %d\n", member.id, member.nama, member.poin);
    fclose(file);

    printf("Member berhasil ditambahkan!\n");
}
