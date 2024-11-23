#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk Menambah Stok Barang
void tambahStok() {
    char idBarang[10];
    int tambahanStok;
    int ditemukan = 0;

    FILE *file = fopen(FILE_BARANG, "r");
    FILE *temp = fopen("temp.txt", "w");

    Barang barang;

    if (file == NULL || temp == NULL) {
        printf("File barang.txt tidak ditemukan.\n");
        return;
    }

    // Input ID Barang dan jumlah stok tambahan
    printf("Masukkan ID Barang: ");
    scanf("%s", idBarang);
    printf("Masukkan jumlah stok yang ingin ditambahkan: ");
    scanf("%d", &tambahanStok);

    // Baca file barang.txt
    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", 
                  barang.id, barang.nama, barang.kategori, 
                  &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            barang.stok += tambahanStok;
            ditemukan = 1;
            printf("Stok untuk barang '%s' berhasil ditambah. Stok baru: %d\n", barang.nama, barang.stok);
        }
        fprintf(temp, "%s|%s|%s|%.2f|%d\n", 
                barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
    fclose(temp);

    // Ganti file barang.txt dengan file temp.txt
    remove(FILE_BARANG);
    rename("temp.txt", FILE_BARANG);

    if (!ditemukan) {
        printf("Barang dengan ID '%s' tidak ditemukan.\n", idBarang);
    }
}
