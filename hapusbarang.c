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

// *** Fungsi untuk Menghapus Barang ***
void hapusBarang() {
    char idBarang[10];
    FILE *file = fopen(FILE_BARANG, "r");
    FILE *temp = fopen("temp.txt", "w");
    Barang barang;
    int ditemukan = 0;

    if (file == NULL || temp == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    printf("Masukkan ID Barang yang ingin dihapus: ");
    scanf("%s", idBarang);

    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            ditemukan = 1; // Barang ditemukan dan dilewati (tidak ditulis ke temp.txt)
        } else {
            fprintf(temp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
        }
    }

    fclose(file);
    fclose(temp);

    // Ganti file asli dengan file sementara
    remove(FILE_BARANG);
    rename("temp.txt", FILE_BARANG);

    if (ditemukan) {
        printf("Barang berhasil dihapus.\n");
    } else {
        printf("Barang dengan ID tersebut tidak ditemukan.\n");
    }
}

// *** Fungsi Utama untuk Pengujian ***
int main() {
    printf("Hapus Barang dari File\n");
    hapusBarang();
    return 0;
}
