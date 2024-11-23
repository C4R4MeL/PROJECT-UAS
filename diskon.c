#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk menghitung total pembayaran setelah diskon
float hitungDiskon(float total, float diskon) {
    return total - (total * diskon / 100);
}

// Fungsi untuk memberikan diskon pada transaksi
float beriDiskon(Member member, float totalBayar) {
    float diskon = 0;

    // Member mendapatkan diskon 10% jika poin lebih dari 100
    if (member.poin > 100) {
        diskon = 10; // Member dengan poin lebih dari 100 mendapatkan diskon 10%
    }
    // Jika poin lebih dari 200, diskon 20%
    else if (member.poin > 200) {
        diskon = 20; // Member dengan poin lebih dari 200 mendapatkan diskon 20%
    }

    printf("Diskon yang diterima: %.2f%%\n", diskon);
    
    // Menghitung total pembayaran setelah diskon
    return hitungDiskon(totalBayar, diskon);
}

// Fungsi untuk melakukan pembayaran dan memberikan diskon
void pembayaran() {
    char idBarang[10], idMember[10];
    int jumlah, itemDibeli = 0;
    float totalBayar = 0;
    FILE *fileBarang = fopen(FILE_BARANG, "r");
    FILE *fileTransaksi = fopen(FILE_TRANSAKSI, "a");
    Barang barang;
    Member member;
    int ditemukan = 0;

    if (fileBarang == NULL || fileTransaksi == NULL) {
        printf("Error membuka file.\n");
        return;
    }

    printf("Masukkan ID Member (kosongkan jika tidak ada): ");
    scanf("%s", idMember);

    // Jika member terdaftar, periksa diskon
    if (strlen(idMember) > 0) {
        FILE *fileMember = fopen(FILE_MEMBER, "r");
        if (fileMember == NULL) {
            printf("File member.txt tidak ditemukan.\n");
            fclose(fileBarang);
            fclose(fileTransaksi);
            return;
        }

        while (fscanf(fileMember, "%s %s %d\n", member.id, member.nama, &member.poin) != EOF) {
            if (strcmp(idMember, member.id) == 0) {
                printf("Member ditemukan: %s\n", member.nama);
                printf("Poin member: %d\n", member.poin);
                ditemukan = 1;
                break;
            }
        }
        fclose(fileMember);

        if (!ditemukan) {
            printf("ID Member tidak ditemukan.\n");
        }
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
                printf("Stok tersedia: %d\n");

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
        // Menghitung total pembayaran setelah diskon jika ada
        if (ditemukan) {
            totalBayar = beriDiskon(member, totalBayar);
        }

        // Catat transaksi ke file
        Transaksi transaksi;
        printf("Tanggal Transaksi (YYYY-MM-DD): ");
        scanf("%s", transaksi.tanggal);
        printf("Masukkan ID Transaksi: ");
        scanf("%s", transaksi.id);
        transaksi.totalBayar = totalBayar;
        strcpy(transaksi.idMember, idMember[0] == '\0' ? "-" : idMember);

        fprintf(fileTransaksi, "%s|%s|%.2f|%.2f|%s\n", transaksi.id, transaksi.tanggal, transaksi.totalBayar, 10, transaksi.idMember); // diskon statis

        printf("Pembayaran berhasil! Total yang harus dibayar: %.2f\n", totalBayar);
    } else {
        printf("Tidak ada barang yang dibeli.\n");
    }

    fclose(fileBarang);
    fclose(fileTransaksi);
}
