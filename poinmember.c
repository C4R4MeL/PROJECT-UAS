#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk menambahkan poin member
void tambahPoinMember() {
    char idMember[10];
    int poinTambah;
    int ditemukan = 0;
    Member member;
    FILE *fileMember = fopen(FILE_MEMBER, "r+");
    
    if (fileMember == NULL) {
        printf("File member.txt tidak ditemukan.\n");
        return;
    }

    // Input ID member dan jumlah poin yang ingin ditambahkan
    printf("Masukkan ID Member: ");
    scanf("%s", idMember);
    printf("Masukkan jumlah poin yang ingin ditambahkan: ");
    scanf("%d", &poinTambah);

    // Mencari member berdasarkan ID
    while (fscanf(fileMember, "%s %s %d\n", member.id, member.nama, &member.poin) != EOF) {
        if (strcmp(member.id, idMember) == 0) {
            ditemukan = 1;

            // Tambahkan poin
            member.poin += poinTambah;

            // Kembali ke posisi awal file untuk mengupdate data member
            fseek(fileMember, -((long)sizeof(Member)), SEEK_CUR);
            
            // Update data member dengan poin baru
            fprintf(fileMember, "%s %s %d\n", member.id, member.nama, member.poin);
            printf("Poin berhasil ditambahkan! Total poin baru: %d\n", member.poin);
            break;
        }
    }

    if (!ditemukan) {
        printf("Member dengan ID %s tidak ditemukan.\n", idMember);
    }

    fclose(fileMember);
}
