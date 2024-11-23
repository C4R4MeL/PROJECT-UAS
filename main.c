#include "header.h"

// Fungsi untuk login admin
int login() {
    char username[50], password[50], uname[50], pass[50];
    FILE *file = fopen(FILE_ADMIN, "r");
    if (file == NULL) {
        printf("File admin.txt tidak ditemukan.\n");
        return 0;
    }

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    while (fscanf(file, "%s %s", uname, pass) != EOF) {
        if (strcmp(username, uname) == 0 && strcmp(password, pass) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    printf("Login gagal.\n");
    return 0;
}

// Fungsi untuk menambah barang
void tambahBarang() {
    Barang barang;
    FILE *file = fopen(FILE_BARANG, "a");

    if (file == NULL) {
        printf("File barang.txt tidak dapat dibuka.\n");
        return;
    }

    printf("Masukkan ID Barang: ");
    scanf("%s", barang.id);
    printf("Masukkan Nama Barang: ");
    scanf(" %[^\n]", barang.nama);
    printf("Masukkan Kategori Barang: ");
    scanf("%s", barang.kategori);
    printf("Masukkan Harga Barang: ");
    scanf("%f", &barang.harga);
    printf("Masukkan Stok Barang: ");
    scanf("%d", &barang.stok);

    fprintf(file, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    fclose(file);

    printf("Barang berhasil ditambahkan!\n");
}

// Fungsi untuk melihat daftar barang
void lihatDaftarBarang() {
    FILE *file = fopen(FILE_BARANG, "r");
    Barang barang;

    if (file == NULL) {
        printf("File barang.txt tidak ditemukan.\n");
        return;
    }

    printf("ID\tNama\t\tKategori\tHarga\tStok\n");
    printf("---------------------------------------------------\n");

    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        printf("%s\t%s\t%s\t\t%.2f\t%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
}

// Fungsi utama
int main() {
    int pilihan;

    if (!login()) {
        printf("Akses ditolak. Program keluar.\n");
        return 0;
    }

    do {
        printf("\n--- Sistem Kasir Sederhana ---\n");
        printf("1. Tambah Barang\n");
        printf("2. Lihat Daftar Barang\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                lihatDaftarBarang();
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}
