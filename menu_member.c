#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void menuMember() {
    int pilihan;
    char lanjutBeli;
    float totalBelanja = 0.0f;  // Inisialisasi total belanja

    do {
        printf("\n--- Menu Member ---\n");
        printf("1. Lihat Daftar Barang\n");
        printf("2. Beli Barang\n");
        printf("0. Keluar\n");

        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                lihatDaftarBarang();
                break;
            case 2:
                 pembayaran();  
                break;
            case 0:
                printf("Keluar dari menu member.\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (pilihan != 0);
}
