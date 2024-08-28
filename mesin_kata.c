/* Saya Ahmad Taufiq H (2202074) mengerjakan Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h" // include file header.h

// deklarasi ulang variabel global
int idx;        // index dari karakter terakhir pada kata
int wlen;       // panjang kata (word length)
char cw[50];    // kata saat ini (current word)

// Prosedur untuk memulai mesin kata
void start(char str[])
{
    // inisialisasi index dan panjang kata
    idx = 0;
    wlen = 0;

    // jika karakter dalam index adalah spasi, maka index terus maju
    while (str[idx] == ' ')
    {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }

    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Prosedur untuk mengosongkan kata yang dibaca dalam mesin kata
void reset()
{
    // inisialisasi panjang kata dan kata saat ini agar NULL
    wlen = 0;
    cw[wlen] = '\0';
}

// Fungsi untuk memeriksa akhir dari proses (End Of Process)
int eop(char str[])
{
    // Memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (str[idx] == ';')
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

// Prosedur untuk memajukan kata (Increment)
void inc(char str[])
{
    // inisialisasi ulang panjang kata
    wlen = 0;

    // jika karakter dalam pita adalah spasi, maka index terus maju
    while (str[idx] == ' ')
    {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }

    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Fungsi untuk mendapatkan panjang kata saat ini
int getlen()
{
    return wlen;
}

// Fungsi untuk mendapatkan kata saat ini
char *getcw()
{
    return cw;
}