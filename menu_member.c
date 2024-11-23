// Fungsi utama untuk menu member
void menuMember() {
    int pilihan;

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
                beliBarang();
                break;
            case 0:
                printf("Keluar dari menu member.\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (pilihan != 0);
}
