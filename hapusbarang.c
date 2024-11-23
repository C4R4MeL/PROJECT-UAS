#include "header.h"

// Fungsi untuk Menghapus Barang
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

    // Input ID Barang yang akan dihapus
    printf("Masukkan ID Barang yang ingin dihapus: ");
    scanf("%s", idBarang);

    // Membaca data barang dari file dan menyalin ke file sementara kecuali barang yang akan dihapus
    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            ditemukan = 1; // Jika ID ditemukan, tidak menyalin barang ke file sementara
        } else {
            fprintf(temp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
        }
    }

    fclose(file);
    fclose(temp);

    // Jika barang ditemukan, ganti file asli dengan file sementara
    if (ditemukan) {
        remove(FILE_BARANG);       // Menghapus file asli
        rename("temp.txt", FILE_BARANG); // Menamai ulang file sementara menjadi file asli
        printf("Barang berhasil dihapus.\n");
    } else {
        printf("Barang dengan ID tersebut tidak ditemukan.\n");
        remove("temp.txt");  // Menghapus file sementara jika barang tidak ditemukan
    }
}
