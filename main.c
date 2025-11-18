#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void hukumOhm() {
    char pilih;
    float V, I, R;
    printf("--- Kalkulator Hukum Ohm ---\n");
    printf("Hitung (V/I/R)? ");
    scanf(" %c", &pilih);

    switch (pilih) {
        case 'V':
        case 'v':
            printf("Masukkan arus (I) [Ampere]: ");
            scanf("%f", &I);
            printf("Masukkan hambatan (R) [Ohm]: ");
            V = I * R;            scanf("%f", &R);

            printf("Tegangan (V) = %.2f Volt\n", V);
            break;
        case 'I':
        case 'i':
            printf("Masukkan tegangan (V) [Volt]: ");
            scanf("%f", &V);
            printf("Masukkan hambatan (R) [Ohm]: ");
            scanf("%f", &R);
            I = V / R;
            printf("Arus (I) = %.2f Ampere\n", I);
            break;
        case 'R':
        case 'r':
            printf("Masukkan tegangan (V) [Volt]: ");
            scanf("%f", &V);
            printf("Masukkan arus (I) [Ampere]: ");
            scanf("%f", &I);
            R = V / I;
            printf("Hambatan (R) = %.2f Ohm\n", R);
            break;
        default:
            printf("Pilihan tidak valid.\n");
    }
}

void dayaListrik() {
    float V, I, P;
    printf("--- Kalkulator Daya Listrik ---\n");
    printf("Masukkan tegangan (V) [Volt]: ");
    scanf("%f", &V);
    printf("Masukkan arus (I) [Ampere]: ");
    scanf("%f", &I);
    P = V * I;
    printf("Daya (P) = %.2f Watt\n", P);
}

void resistorSeri() {
    int n;
    float total = 0, r;
    printf("--- Kalkulator Resistor Seri ---\n");
    printf("Masukkan jumlah resistor: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Resistor %d (Ohm): ", i);
        scanf("%f", &r);
        total += r;
    }
    printf("Total Hambatan Seri = %.2f Ohm\n", total);
}

void resistorParalel() {
    int n;
    float r, invTotal = 0;
    printf("--- Kalkulator Resistor Paralel ---\n");
    printf("Masukkan jumlah resistor: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Resistor %d (Ohm): ", i);
        scanf("%f", &r);
        if (r != 0)
            invTotal += 1.0 / r;
    }
    if (invTotal != 0)
        printf("Total Hambatan Paralel = %.2f Ohm\n", 1.0 / invTotal);
    else
        printf("Tidak valid (semua resistor tak hingga).\n");
}

void oktalKeDesimal() {
    char okt[30];
    int des = 0;
    printf("--- Konversi Oktal ke Desimal ---\n");
    printf("Masukkan bilangan oktal: ");
    scanf("%s", okt);
    sscanf(okt, "%o", &des);
    printf("Desimal = %d\n", des);
}

void heksaKeDesimal() {
    char hex[30];
    int des = 0;
    printf("--- Konversi Heksadesimal ke Desimal ---\n");
    printf("Masukkan bilangan heksadesimal: ");
    scanf("%s", hex);
    sscanf(hex, "%x", &des);
    printf("Desimal = %d\n", des);
}


int main() {
    int pilihan;
    do {
        printf("\n=============================================\n");
        printf(" TOOLKIT LENGKAP ASISTEN LABORATORIUM ELEKTRO\n");
        printf("=============================================\n");
        printf(" --- Verifikasi Rangkaian Elektrik ---\n");
        printf(" 1. Kalkulator Hukum Ohm ( V = I * R )\n");
        printf(" 2. Kalkulator Daya Listrik ( P = V * I )\n");
        printf(" 3. Kalkulator Resistor Seri\n");
        printf(" 4. Kalkulator Resistor Paralel\n");
        printf(" --- Utilitas Sistem Digital ---\n");
        printf(" 5. Desimal -> Biner / Oktal / Heksadesimal\n");
        printf(" 6. Biner -> Desimal\n");
        printf(" 7. Oktal -> Desimal\n");
        printf(" 8. Heksadesimal -> Desimal\n");
        printf(" 9. Keluar\n");
        printf("---------------------------------------------\n");
        printf("Masukkan pilihan Anda (1-9): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: hukumOhm(); break;
            case 2: dayaListrik(); break;
            case 3: resistorSeri(); break;
            case 4: resistorParalel(); break;
            // case 5: desimalKeLain(); break;
            // case 6: binerKeDesimal(); break;
            case 7: oktalKeDesimal(); break;
            case 8: heksaKeDesimal(); break;
            case 9: printf("Terima kasih telah menggunakan toolkit ini!\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
        if (pilihan != 9) {
            printf("\nTekan Enter untuk kembali ke menu...");
            getchar(); getchar();
        }
    } while (pilihan != 9);
    return 0;
}
