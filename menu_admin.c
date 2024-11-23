#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk menampilkan menu admin
void menuAdmin() {
    int pilihan;

    do {
        // Menampilkan menu admin
        printf("\n--- Menu Admin ---\n");
        printf("1. Tambah Barang\n");
        printf("2. Lihat Daftar Barang\n");
        printf("3. Hapus Barang\n");
        printf("4. Tambah Stok Barang\n");
        printf("5. Kurangi Stok Barang\n");
        printf("6. Kategorikan Produk\n");
        printf("7. Laporan Penjualan\n");  // Opsi untuk laporan penjualan
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        // Menangani pilihan yang dimasukkan oleh admin
        switch (pilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                lihatDaftarBarang();
                break;
            case 3:
                hapusBarang();
                break;
            case 4:
                tambahStok();
                break;
            case 5:
                kurangiStok();
                break;
            case 6:
                kategorikanBarang();
                break;
            case 7:
                laporanPenjualan();  // Menampilkan laporan penjualan
                break;
            case 0:
                printf("Keluar dari menu admin.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);
}
