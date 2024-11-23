#include "header.h"

// Fungsi untuk Menambah Barang
void tambahBarang() {
    Barang barang;
    FILE *file = fopen(FILE_BARANG, "a");

    if (file == NULL) {
        printf("File barang.txt tidak dapat dibuka.\n");
        return;
    }

    // Input data barang
    printf("Masukkan ID Barang: ");
    scanf("%s", barang.id);
    printf("Masukkan Nama Barang: ");
    scanf(" %[^\n]", barang.nama); // Membaca string dengan spasi
    printf("Masukkan Kategori Barang: ");
    scanf("%s", barang.kategori);
    printf("Masukkan Harga Barang: ");
    scanf("%f", &barang.harga);
    printf("Masukkan Stok Barang: ");
    scanf("%d", &barang.stok);

    // Simpan data ke file
    fprintf(file, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    fclose(file);

    printf("Barang berhasil ditambahkan!\n");
}
