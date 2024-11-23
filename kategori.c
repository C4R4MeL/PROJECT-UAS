#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk mengkategorikan ulang barang
void kategorikanBarang() {
    char idBarang[10];
    char kategoriBaru[30];
    int ditemukan = 0;
    Barang barang;

    // Membuka file barang.txt untuk dibaca dan temp.txt untuk menulis data sementara
    FILE *file = fopen(FILE_BARANG, "r+");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    // Input ID Barang yang ingin dikategorikan ulang
    printf("Masukkan ID Barang: ");
    scanf("%s", idBarang);
    printf("Masukkan kategori baru: ");
    scanf("%s", kategoriBaru);

    // Membaca data barang dan mengubah kategori jika ditemukan
    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            // Jika ID Barang ditemukan, ubah kategori
            strcpy(barang.kategori, kategoriBaru);
            ditemukan = 1;
            printf("Kategori barang %s berhasil diubah menjadi: %s\n", barang.nama, barang.kategori);
        }
        // Menulis kembali data ke file sementara
        fprintf(temp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
    fclose(temp);

    // Jika barang ditemukan, ganti file barang.txt dengan file sementara
    if (ditemukan) {
        remove(FILE_BARANG);  // Hapus file lama
        rename("temp.txt", FILE_BARANG);  // Ganti file sementara dengan nama file asli
    } else {
        printf("Barang dengan ID tersebut tidak ditemukan.\n");
        remove("temp.txt");  // Hapus file sementara jika tidak ditemukan
    }
}
