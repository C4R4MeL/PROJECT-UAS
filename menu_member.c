#include "header.h"

// Fungsi untuk membeli barang
void beliBarang() {
    char idBarang[10];
    int jumlah;
    int ditemukan = 0;
    Barang barang;

    FILE *file = fopen(FILE_BARANG, "r+");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    printf("Masukkan ID Barang yang ingin dibeli: ");
    scanf("%s", idBarang);
    printf("Masukkan jumlah yang ingin dibeli: ");
    scanf("%d", &jumlah);

    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            if (barang.stok >= jumlah) {
                barang.stok -= jumlah;  // Kurangi stok
                ditemukan = 1;
                printf("Pembelian berhasil! Barang: %s, Jumlah: %d, Total Harga: %.2f\n", barang.nama, jumlah, barang.harga * jumlah);
            } else {
                printf("Stok tidak cukup untuk pembelian.\n");
            }
        }
        fprintf(temp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
    fclose(temp);

    if (ditemukan) {
        remove(FILE_BARANG);  // Hapus file lama
        rename("temp.txt", FILE_BARANG);  // Ganti file sementara dengan nama file asli
    } else {
        printf("Barang dengan ID tersebut tidak ditemukan.\n");
        remove("temp.txt");  // Hapus file sementara jika tidak ditemukan
    }
}

// Fungsi utama untuk menu member
void menuMember() {
    int pilihan;

    do {
        printf("\n--- Menu Member ---\n");
        printf("1. Lihat Daftar Barang\n");
        printf("2. Beli Barang\n");
        printf("0. Keluar\n");

        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                lihatDaftarBarang();
                break;
            case 2:
                beliBarang();
                break;
            case 0:
                printf("Keluar dari menu member.\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (pilihan != 0);
}
