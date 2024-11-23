#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk menampilkan laporan penjualan
void laporanPenjualan() {
    FILE *fileTransaksi = fopen(FILE_TRANSAKSI, "r");
    Transaksi transaksi;

    if (fileTransaksi == NULL) {
        printf("File transaksi.txt tidak ditemukan.\n");
        return;
    }

    // Menampilkan header laporan
    printf("\n--- Laporan Penjualan ---\n");
    printf("ID Transaksi\tTanggal\t\tTotal Bayar\tDiskon\tID Member\n");
    printf("--------------------------------------------------------------\n");

    // Membaca dan menampilkan setiap transaksi
    while (fscanf(fileTransaksi, "%s|%s|%f|%f|%s\n", transaksi.id, transaksi.tanggal, &transaksi.totalBayar, &transaksi.diskon, transaksi.idMember) != EOF) {
        printf("%s\t%s\t%.2f\t%.2f%%\t%s\n", transaksi.id, transaksi.tanggal, transaksi.totalBayar, transaksi.diskon, transaksi.idMember);
    }

    fclose(fileTransaksi);
}
