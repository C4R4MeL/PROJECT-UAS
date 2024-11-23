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

// Fungsi untuk melihat daftar barang
void lihatDaftarBarang() {
    FILE *file = fopen("barang.txt", "r");
    Barang barang;

    if (file == NULL) {
        printf("File barang.txt tidak ditemukan.\n");
        return;
    }

    printf("ID\tNama\t\tKategori\tHarga\tStok\n");
    printf("---------------------------------------------------\n");

    // Membaca dan menampilkan data barang
    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%d\n", barang.id, barang.nama, barang.kategori, &barang.harga, &barang.stok) != EOF) {
        printf("%s\t%s\t%s\t\t%.2f\t%d\n", barang.id, barang.nama, barang.kategori, barang.harga, barang.stok);
    }

    fclose(file);
}

int main() {
    // Memanggil fungsi untuk melihat daftar barang
    lihatDaftarBarang();
    return 0;
}
