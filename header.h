#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur Data
typedef struct {
    char id[10];
    char nama[50];
    char kategori[30];
    int stok;
    float harga;
} Barang;

typedef struct {
    char id[10];
    char nama[50];
    int poin;
} Member;

typedef struct {
    char id[10];
    char tanggal[11];
    float totalBayar;
    float diskon;
    char idMember[10];
} Transaksi;

// Fungsi Deklarasi
void menuAdmin();
void menuMember();
int loginAdmin();
int loginMember(char *idMember);
void lihatDaftarBarang();
void tambahBarang();
void hapusBarang();
void tambahStok();
void kurangiStok();
void kategorikanBarang();
void tambahMember();
void bayar();
void laporanPenjualan();
void beriDiskon();
void tambahPoinMember();
void laporanTransaksi();

#endif
