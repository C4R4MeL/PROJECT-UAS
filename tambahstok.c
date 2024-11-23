#include "header.h"

// Fungsi untuk Menambah Stok Barang
void tambahStok() {
    char idBarang[10];
    int stokTambah;
    int ditemukan = 0;
    Barang barang;

    FILE *file = fopen(FILE_BARANG, "r+");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    // Input ID Barang dan jumlah stok yang ingin ditambahkan
    printf("Masukkan ID Barang: ");
    scanf("%s", idBarang);
    printf("Masukkan jumlah stok yang ingin ditambahkan: ");
    scanf("%d", &stokTambah);

    // Proses membaca file barang dan menambahkan stok
    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            barang.stok += stokTambah;  // Menambah stok barang
            ditemukan = 1;
            printf("Stok barang %s berhasil ditambahkan. Stok sekarang: %d\n", barang.nama, barang.stok);
        }
        // Menyimpan kembali barang ke file sementara
        fprintf(temp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
    fclose(temp);

    // Jika barang ditemukan, file utama akan digantikan dengan file sementara
    if (ditemukan) {
        remove(FILE_BARANG);
        rename("temp.txt", FILE_BARANG);
    } else {
        printf("Barang dengan ID tersebut tidak ditemukan.\n");
        remove("temp.txt");
    }
}
