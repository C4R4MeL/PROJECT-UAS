#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk melihat daftar barang
void lihatDaftarBarang() {
    FILE *file = fopen(FILE_BARANG, "r");
    Barang barang;

    if (file == NULL) {
        printf("File barang.txt tidak ditemukan.\n");
        return;
    }

    printf("\n--- Daftar Barang ---\n");
    printf("ID\tNama\t\tKategori\tHarga\tStok\n");
    printf("-----------------------------------------------\n");

    // Membaca dan menampilkan data barang dari file
    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        printf("%s\t%s\t%s\t\t%.2f\t%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
}
