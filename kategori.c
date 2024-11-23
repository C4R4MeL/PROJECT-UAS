#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur Data Barang
typedef struct {
    char id[10];
    char nama[50];
    char kategori[30];
    int stok;
    float harga;
} Barang;

// Fungsi untuk menampilkan barang berdasarkan kategori
void kategorikanBarang() {
    char kategoriCari[30];
    FILE *file = fopen("barang.txt", "r");
    Barang barang;

    if (file == NULL) {
        printf("File barang.txt tidak ditemukan.\n");
        return;
    }

    printf("Masukkan kategori yang ingin dicari: ");
    scanf("%s", kategoriCari);

    printf("ID\tNama\t\tKategori\tHarga\tStok\n");
    printf("---------------------------------------------------\n");

    // Mencari dan menampilkan barang yang sesuai dengan kategori
    int ditemukan = 0;
    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.kategori, kategoriCari) == 0) {
            printf("%s\t%s\t%s\t\t%.2f\t%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
            ditemukan = 1;
        }
    }

    if (!ditemukan) {
        printf("Tidak ada barang dengan kategori \"%s\".\n", kategoriCari);
    }

    fclose(file);
}

