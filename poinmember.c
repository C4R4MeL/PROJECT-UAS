int tambahPoin(int totalBayar, int poinLama) {
    int poinBaru = totalBayar / 100;  // 1 poin per 100 unit pembayaran
    return poinLama + poinBaru;
}
