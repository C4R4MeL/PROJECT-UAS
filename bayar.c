#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void pembayaran() {
    char idBarang[10], idMember[10];
    int jumlah, itemDibeli = 0;
    float totalBayar = 0;
    FILE *fileBarang = fopen(FILE_BARANG, "r");
    FILE *fileTransaksi = fopen(FILE_TRANSAKSI, "a");
    Barang barang;
    Member member;
    int memberDitemukan = 0;

    if (fileBarang == NULL || fileTransaksi == NULL) {
        printf("Error membuka file.\n");
        return;
    }

    // Input ID Member
    printf("Masukkan ID Member (kosongkan jika tidak ada): ");
    scanf("%s", idMember);

    if (strlen(idMember) > 0) {
        FILE *fileMember = fopen(FILE_MEMBER, "r");
        if (fileMember == NULL) {
            printf("File member tidak ditemukan.\n");
            fclose(fileBarang);
            fclose(fileTransaksi);
            return;
        }

        while (fscanf(fileMember, "%s %s %d", member.id, member.nama, &member.poin) != EOF) {
            if (strcmp(idMember, member.id) == 0) {
                printf("Member ditemukan\n");
                memberDitemukan = 1;
                break;
            }
        }
        fclose(fileMember);
    }

    // Proses pembelian barang
    while (1) {
        printf("Masukkan ID Barang (atau ketik 'selesai' untuk selesai): ");
        scanf("%s", idBarang);

        if (strcmp(idBarang, "selesai") == 0) {
            break;
        }

        fseek(fileBarang, 0, SEEK_SET); // Reset pointer file
        int barangDitemukan = 0;

        while (fscanf(fileBarang, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
            if (strcmp(idBarang, barang.id) == 0) {
                barangDitemukan = 1;
                printf("Nama Barang: %s\n", barang.nama);
                printf("Harga: %.2f\n", barang.harga);
                printf("Stok tersedia: %d\n", barang.stok);

                printf("Masukkan jumlah: ");
                scanf("%d", &jumlah);

                if (jumlah <= barang.stok) {
                    totalBayar += barang.harga * jumlah;
                    itemDibeli++;

                    // Update stok
                    FILE *fileBarangTemp = fopen("temp_barang.txt", "w");
                    if (fileBarangTemp) {
                        rewind(fileBarang);
                        while (fscanf(fileBarang, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
                            if (strcmp(idBarang, barang.id) == 0) {
                                barang.stok -= jumlah;
                            }
                            fprintf(fileBarangTemp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
                        }
                        fclose(fileBarangTemp);
                        fclose(fileBarang);
                        remove(FILE_BARANG);
                        rename("temp_barang.txt", FILE_BARANG);
                        fileBarang = fopen(FILE_BARANG, "r");
                    }
                } else {
                    printf("Stok tidak mencukupi.\n");
                }
                break;
            }
        }

        if (!barangDitemukan) {
            printf("Barang dengan ID %s tidak ditemukan.\n", idBarang);
        }
    }

    if (itemDibeli > 0) {
        float totalSetelahDiskon = memberDitemukan ? beriDiskon(member, totalBayar) : totalBayar;
        printf("Total yang harus dibayar: %.2f\n", totalSetelahDiskon);

        // Proses pembayaran
        float uangDibayar;
        printf("Masukkan uang yang dibayar: ");
        scanf("%f", &uangDibayar);

        if (uangDibayar >= totalSetelahDiskon) {
            printf("Pembayaran berhasil! Kembalian: %.2f\n", uangDibayar - totalSetelahDiskon);

            // Catat transaksi ke file transaksi.txt
            Transaksi transaksi;
            printf("Masukkan ID Transaksi: ");
            scanf("%s", transaksi.id);
            printf("Tanggal Transaksi (YYYY-MM-DD): ");
            scanf("%s", transaksi.tanggal);

            transaksi.totalBayar = totalSetelahDiskon;
            transaksi.diskon = memberDitemukan ? (totalBayar - totalSetelahDiskon) : 0;
            strcpy(transaksi.idMember, memberDitemukan ? idMember : "-");

            fprintf(fileTransaksi, "%s|%s|%.2f|%.2f|%s\n",
                    transaksi.id,
                    transaksi.tanggal,
                    transaksi.totalBayar,
                    transaksi.diskon,
                    transaksi.idMember);

            // Update poin member jika member ditemukan
            if (memberDitemukan) {
                FILE *fileMember = fopen(FILE_MEMBER, "r");
                FILE *tempMember = fopen("temp_member.txt", "w");
                Member temp;
                while (fscanf(fileMember, "%s %s %d", temp.id, temp.nama, &temp.poin) != EOF) {
                    if (strcmp(idMember, temp.id) == 0) {
                        temp.poin = tambahPoin((int)totalBayar, temp.poin);
                        printf("total poin anda: %d\n", temp.poin);
                    }
                    fprintf(tempMember, "%s %s %d\n", temp.id, temp.nama, temp.poin);
                }
                fclose(fileMember);
                fclose(tempMember);
                remove(FILE_MEMBER);
                rename("temp_member.txt", FILE_MEMBER);
            }
        } else {
            printf("Uang yang dibayar kurang. Transaksi dibatalkan.\n");
        }
    } else {
        printf("Tidak ada barang yang dibeli.\n");
    }

    fclose(fileBarang);
    fclose(fileTransaksi);
}
