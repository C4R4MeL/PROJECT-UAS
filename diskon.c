#include "header.h"

float beriDiskon(Member member, float totalBayar) {
    float diskon = 0;

    if (member.poin >= 100) {
        diskon = 10;  // Member mendapatkan diskon 10%
    } else if (member.poin >= 50) {
        diskon = 5;   // Member mendapatkan diskon 5%
    }

    return totalBayar - (totalBayar * diskon / 100);
}
