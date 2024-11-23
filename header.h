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

// Konstanta
#define FILE_BARANG "barang.txt"
#define FILE_MEMBER "member.txt"
#define FILE_TRANSAKSI "transaksi.txt"
#define FILE_ADMIN "admin.txt"

// Fungsi Deklarasi
void tambahBarang();
void hapusBarang();
void tambahStok();
void kurangiStok();
void lihatDaftarBarang();
void kategorikanBarang();
void tambahMember();
void tambahPoinMember();
void pembayaran();
void beriDiskon();
void laporanPenjualan();
int login();

#endif
