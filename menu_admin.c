#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur Data Barang
typedef struct {
    char id[10];
    char nama[50];
    char kategori[30];
    int stok;
    float harga;
} Barang;

// Konstanta
#define FILE_BARANG "barang.txt"

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

// Fungsi untuk menghapus barang
void hapusBarang() {
    char idBarang[10];
    FILE *file = fopen(FILE_BARANG, "r");
    FILE *temp = fopen("temp.txt", "w");
    Barang barang;
    int ditemukan = 0;

    if (file == NULL || temp == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    printf("Masukkan ID Barang yang ingin dihapus: ");
    scanf("%s", idBarang);

    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            ditemukan = 1;
        } else {
            fprintf(temp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
        }
    }

    fclose(file);
    fclose(temp);

    if (ditemukan) {
        remove(FILE_BARANG);
        rename("temp.txt", FILE_BARANG);
        printf("Barang berhasil dihapus.\n");
    } else {
        printf("Barang dengan ID tersebut tidak ditemukan.\n");
        remove("temp.txt");
    }
}

// Fungsi untuk menambah stok barang
void tambahStok() {
    char idBarang[10];
    int stokTambah;
    int ditemukan = 0;
    Barang barang;

    FILE *file = fopen(FILE_BARANG, "r+");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    printf("Masukkan ID Barang: ");
    scanf("%s", idBarang);
    printf("Masukkan jumlah stok yang ingin ditambahkan: ");
    scanf("%d", &stokTambah);

    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            barang.stok += stokTambah;
            ditemukan = 1;
            printf("Stok barang %s berhasil ditambahkan. Stok sekarang: %d\n", barang.nama, barang.stok);
        }
        fprintf(temp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
    fclose(temp);

    if (ditemukan) {
        remove(FILE_BARANG);
        rename("temp.txt", FILE_BARANG);
    } else {
        printf("Barang dengan ID tersebut tidak ditemukan.\n");
        remove("temp.txt");
    }
}

// Fungsi untuk mengurangi stok barang
void kurangiStok() {
    char idBarang[10];
    int stokKurang;
    int ditemukan = 0;
    Barang barang;

    FILE *file = fopen(FILE_BARANG, "r+");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    printf("Masukkan ID Barang: ");
    scanf("%s", idBarang);
    printf("Masukkan jumlah stok yang ingin dikurangi: ");
    scanf("%d", &stokKurang);

    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            if (barang.stok >= stokKurang) {
                barang.stok -= stokKurang;
                ditemukan = 1;
                printf("Stok barang %s berhasil dikurangi. Stok sekarang: %d\n", barang.nama, barang.stok);
            } else {
                printf("Stok barang tidak cukup.\n");
            }
        }
        fprintf(temp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
    fclose(temp);

    if (ditemukan) {
        remove(FILE_BARANG);
        rename("temp.txt", FILE_BARANG);
    } else {
        printf("Barang dengan ID tersebut tidak ditemukan.\n");
        remove("temp.txt");
    }
}

// Fungsi untuk mengkategorikan produk
void kategorikanBarang() {
    char idBarang[10];
    char kategoriBaru[30];
    int ditemukan = 0;
    Barang barang;

    FILE *file = fopen(FILE_BARANG, "r+");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    printf("Masukkan ID Barang: ");
    scanf("%s", idBarang);
    printf("Masukkan kategori baru: ");
    scanf("%s", kategoriBaru);

    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        if (strcmp(barang.id, idBarang) == 0) {
            strcpy(barang.kategori, kategoriBaru);
            ditemukan = 1;
            printf("Kategori barang %s berhasil diubah menjadi: %s\n", barang.nama, barang.kategori);
        }
        fprintf(temp, "%s|%s|%s|%.2f|%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
    fclose(temp);

    if (ditemukan) {
        remove(FILE_BARANG);
        rename("temp.txt", FILE_BARANG);
    } else {
        printf("Barang dengan ID tersebut tidak ditemukan.\n");
        remove("temp.txt");
    }
}

// Fungsi Utama
int main() {
    int pilihan;

    do {
        printf("\n--- Menu Admin ---\n");
        printf("1. Tambah Barang\n");
        printf("2. Lihat Daftar Barang\n");
        printf("3. Hapus Barang\n");
        printf("4. Tambah Stok Barang\n");
        printf("5. Kurangi Stok Barang\n");
        printf("6. Kategorikan Produk\n");
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
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}
