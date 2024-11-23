#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *** Struktur Data Member ***
typedef struct {
    char id[10];
    char nama[50];
    int poin;
} Member;

// *** Fungsi untuk Menerima Diskon ***
float beriDiskon(float totalBelanja, int poinMember) {
    float diskon = 0.0;

    // Diskon berdasarkan total belanja
    if (totalBelanja > 100000) { // Misal diskon 10% untuk belanja lebih dari 100,000
        diskon = totalBelanja * 0.1; 
        printf("Diskon 10%% diberikan karena total belanja lebih dari 100,000.\n");
    }
    
    // Diskon berdasarkan poin member
    if (poinMember >= 100) { // Misal diskon 5% jika poin member lebih dari 100
        diskon = totalBelanja * 0.05;
        printf("Diskon 5%% diberikan karena poin member lebih dari 100.\n");
    }
    
    // Total diskon tidak boleh lebih dari 20% dari total belanja
    if (diskon > totalBelanja * 0.2) {
        diskon = totalBelanja * 0.2;
        printf("Diskon dibatasi hingga 20%% dari total belanja.\n");
    }

    return diskon;
}

// *** Fungsi untuk Menampilkan Diskon dan Total Pembayaran ***
void pembayaranDenganDiskon(float totalBelanja, int poinMember) {
    float diskon = beriDiskon(totalBelanja, poinMember);
    float totalSetelahDiskon = totalBelanja - diskon;

    printf("\n--- Rincian Pembayaran ---\n");
    printf("Total Belanja: %.2f\n", totalBelanja);
    printf("Diskon: %.2f\n", diskon);
    printf("Total Pembayaran Setelah Diskon: %.2f\n", totalSetelahDiskon);
}

// Fungsi utama untuk percakapan dengan user
int main() {
    float totalBelanja;
    int poinMember;

    // Input dari user
    printf("Masukkan total belanja: ");
    scanf("%f", &totalBelanja);
    printf("Masukkan jumlah poin member: ");
    scanf("%d", &poinMember);

    // Menampilkan rincian pembayaran dengan diskon
    pembayaranDenganDiskon(totalBelanja, poinMember);

    return 0;
}
