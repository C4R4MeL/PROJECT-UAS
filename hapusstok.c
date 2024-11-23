#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *** Konstanta ***
#define FILE_BARANG "barang.txt"

// *** Struktur Data ***
typedef struct {
    char id[10];
    char nama[50];
    char kategori[30];
    int stok;
    float harga;
} Barang;

// *** Fungsi untuk Mengurangi Stok Barang ***
void kurangiStok() {
    char idBarang[10];
    int jumlahKurang, ditemukan = 0;
    Barang barang;

    FILE *file = fopen(FILE_BARANG, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    printf("Masukkan ID Barang yang ingin dikurangi stoknya: ");
    scanf("%s", idBarang);
    printf("Masukkan jumlah stok yang ingin dikurangi: ");
    scanf("%d", &jumlahKurang);

    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            ditemukan = 1;
            if (barang.stok >= jumlahKurang) {
                barang.stok -= jumlahKurang;
                printf("Stok barang berhasil dikurangi. Stok baru: %d\n", barang.stok);
            } else {
                printf("Stok tidak mencukupi untuk dikurangi.\n");
            }
        }
        // Menulis kembali data barang ke file sementara
        fprintf(temp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
    fclose(temp);

    // Mengganti file asli dengan file sementara
    remove(FILE_BARANG);
    rename("temp.txt", FILE_BARANG);

    if (!ditemukan) {
        printf("Barang dengan ID tersebut tidak ditemukan.\n");
    }
}

