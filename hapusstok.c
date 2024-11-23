#include "header.h"

// Fungsi untuk Mengurangi Stok Barang
void kurangiStok() {
    char idBarang[10];
    int stokKurang;
    int ditemukan = 0;
    Barang barang;

    // Membuka file barang.txt untuk dibaca dan ditulis
    FILE *file = fopen(FILE_BARANG, "r+");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    // Input ID Barang dan jumlah stok yang ingin dikurangi
    printf("Masukkan ID Barang: ");
    scanf("%s", idBarang);
    printf("Masukkan jumlah stok yang ingin dikurangi: ");
    scanf("%d", &stokKurang);

    // Membaca data dari file barang.txt dan melakukan pengecekan serta pengurangan stok
    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            if (barang.stok >= stokKurang) {
                barang.stok -= stokKurang;  // Mengurangi stok barang
                ditemukan = 1;
                printf("Stok barang %s berhasil dikurangi. Stok sekarang: %d\n", barang.nama, barang.stok);
            } else {
                printf("Stok barang tidak cukup untuk dikurangi.\n");
            }
        }
        // Menulis kembali data ke file sementara
        fprintf(temp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
    fclose(temp);

    // Jika barang ditemukan, ganti file lama dengan file baru
    if (ditemukan) {
        remove(FILE_BARANG);         // Menghapus file lama
        rename("temp.txt", FILE_BARANG);  // Menamai file sementara sebagai file utama
    } else {
        printf("Barang dengan ID tersebut tidak ditemukan.\n");
        remove("temp.txt");  // Menghapus file sementara jika barang tidak ditemukan
    }
}
