#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk menghitung total pembayaran setelah diskon
float hitungDiskon(float total, float diskon) {
    return total - (total * diskon / 100);
}

// Fungsi untuk melakukan pembayaran
void pembayaran() {
    char idBarang[10], idMember[10];
    int jumlah, itemDibeli = 0;
    float totalBayar = 0, diskon = 0;
    FILE *fileBarang = fopen(FILE_BARANG, "r");
    FILE *fileTransaksi = fopen(FILE_TRANSAKSI, "a");
    Barang barang;
    Member member;
    int ditemukan = 0;

    if (fileBarang == NULL || fileTransaksi == NULL) {
        printf("Error membuka file.\n");
        return;
    }

// Input ID Member
printf("Masukkan ID Member (kosongkan jika tidak ada): ");
scanf("%9s", idMember); // Batasi panjang input ID member untuk menghindari overflow

// Jika ID Member tidak kosong, periksa apakah member terdaftar dan berikan diskon
if (strlen(idMember) > 0) {
    FILE *fileMember = fopen(FILE_MEMBER, "r");
    if (fileMember == NULL) {
        printf("File member.txt tidak ditemukan.\n");
        fclose(fileBarang); // Pastikan fileBarang ditutup sebelum keluar
        fclose(fileTransaksi); // Pastikan fileTransaksi ditutup sebelum keluar
        return;
    }

    int ditemukan = 0; // Menyimpan status apakah member ditemukan atau tidak
    while (fscanf(fileMember, "%s %s %d\n", member.id, member.nama, &member.poin) != EOF) {
        if (strcmp(idMember, member.id) == 0) {
            diskon = 10; // Misalnya member mendapatkan diskon 10%
            printf("Member ditemukan. Diskon: %.2f%%\n", diskon);
            ditemukan = 1;
            break; // Jika ditemukan, keluar dari loop
        }
    }

    fclose(fileMember);

    if (!ditemukan) {
        printf("ID Member tidak ditemukan. Tidak ada diskon yang diterapkan.\n");
    }
} else {
    printf("ID Member tidak dimasukkan, tidak ada diskon yang diterapkan.\n");
}


    // Proses pembelian barang
    while (1) {
        printf("Masukkan ID Barang (atau ketik 'selesai' untuk selesai): ");
        scanf("%s", idBarang);

        if (strcmp(idBarang, "selesai") == 0) {
            break;
        }

        // Cari barang berdasarkan ID
        fseek(fileBarang, 0, SEEK_SET);
        int barangDitemukan = 0;
        while (fscanf(fileBarang, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
            if (strcmp(idBarang, barang.id) == 0) {
                barangDitemukan = 1;
                printf("Nama Barang: %s\n", barang.nama);
                printf("Harga: %.2f\n", barang.harga);
                printf("Stok tersedia: %d\n", barang.stok);

                // Masukkan jumlah barang yang ingin dibeli
                printf("Masukkan jumlah: ");
                scanf("%d", &jumlah);

                if (jumlah <= barang.stok) {
                    totalBayar += barang.harga * jumlah;
                    itemDibeli++;
                    printf("Total sementara: %.2f\n", totalBayar);
                    break;
                } else {
                    printf("Stok tidak mencukupi.\n");
                }
            }
        }

        if (!barangDitemukan) {
            printf("Barang dengan ID %s tidak ditemukan.\n", idBarang);
        }
    }

    if (itemDibeli > 0) {
        // Hitung total pembayaran setelah diskon
        float totalSetelahDiskon = hitungDiskon(totalBayar, diskon);

        // Catat transaksi ke file
        Transaksi transaksi;
        printf("Tanggal Transaksi (YYYY-MM-DD): ");
        scanf("%s", transaksi.tanggal);
        printf("Masukkan ID Transaksi: ");
        scanf("%s", transaksi.id);
        transaksi.totalBayar = totalSetelahDiskon;
        transaksi.diskon = diskon;
        strcpy(transaksi.idMember, idMember[0] == '\0' ? "-" : idMember);

        fprintf(fileTransaksi, "%s|%s|%.2f|%.2f|%s\n", transaksi.id, transaksi.tanggal, transaksi.totalBayar, transaksi.diskon, transaksi.idMember);

        printf("Total yang harus dibayar: %.2f\n", totalSetelahDiskon);

        // Pembayaran
        float uangDibayar;
        printf("Masukkan uang yang dibayar: ");
        scanf("%f", &uangDibayar);

        if (uangDibayar >= totalSetelahDiskon) {
            printf("Pembayaran berhasil! Kembalian: %.2f\n", uangDibayar - totalSetelahDiskon);
        } else {
            printf("Uang yang dibayar kurang.\n");
        }
    } else {
        printf("Tidak ada barang yang dibeli.\n");
    }

    fclose(fileBarang);
    fclose(fileTransaksi);
}
