#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur Data Barang
typedef struct {
    char id[10];        // ID Barang
    char nama[50];      // Nama Barang
    char kategori[30];  // Kategori Barang
    int stok;           // Stok Barang
    float harga;        // Harga Barang
} Barang;

// Struktur Data Member
typedef struct {
    char id[10];   // ID Member
    char nama[50]; // Nama Member
    int poin;      // Poin Member (untuk diskon)
} Member;

// Struktur Data Transaksi
typedef struct {
    char id[10];      // ID Transaksi
    char tanggal[11]; // Tanggal Transaksi (Format: YYYY-MM-DD)
    float totalBayar; // Total Pembayaran
    float diskon;     // Diskon yang diberikan
    char idMember[10]; // ID Member (kosong jika tidak ada)
} Transaksi;

// Konstanta File
#define FILE_BARANG "barang.txt"
#define FILE_MEMBER "member.txt"
#define FILE_TRANSAKSI "transaksi.txt"
#define FILE_ADMIN "admin.txt"

// Fungsi Deklarasi
void tambahBarang();          // Menambahkan barang baru
void hapusBarang();          // Menghapus barang
void tambahStok();           // Menambah stok barang
void kurangiStok();          // Mengurangi stok barang
void lihatDaftarBarang();    // Melihat daftar barang yang tersedia
void kategorikanBarang();    // Mengkategorikan barang
void tambahMember();         // Menambahkan member baru
void tambahPoinMember();     // Menambah poin member
void pembayaran();           // Proses pembayaran dan diskon
void beriDiskon();           // Menetapkan diskon untuk member
void laporanPenjualan();     // Melihat laporan penjualan
int login();                 // Fungsi login untuk admin

#endif
