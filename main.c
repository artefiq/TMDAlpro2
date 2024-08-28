/* Saya Ahmad Taufiq H (2202074) mengerjakan Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h" // include file header.h

// deklarasi ulang variabel global untuk index record
int nPelanggan = 0, nBarang = 0, nPenjualan = 0;

// deklarasi fungsi main
int main()
{
    // header program DBMS
    printf ("Selamat Datang di DBMS Laundry Taufiq\n");
    printf ("Versi 1.0\n\n");

    int cekPerintah = 0; // deklarasi variabel penanda program selesai

    // deklarasi array tipe data terstruktur untuk setiap tabel
    dataPelanggan pelanggan[100];
    dataBarang barang[100];
    dataPenjualan penjualan[100];

    // memanggil fungsi read file, dan memasukan nilai ke variabel index
    nPelanggan = readPelanggan (pelanggan);
    nBarang = readBarang (barang);
    nPenjualan = readPenjualan (penjualan);

    // looping selama masih ada query yang diinput
    while (cekPerintah == 0)
    {
        // deklarasi variabel pita
        char tape[501];

        printf ("dbms taufiq> ");
        scanf(" %500[^\n]s", &tape); // meminta input perintah dari user

        // jika user meng-input "jangan lupa bahagia hari ini;", maka akhiri program
        if (strcmp(tape, "jangan lupa bahagia hari ini;") == 0)
        {
            cekPerintah = 1; // mengubah nilai menjadi 1, untuk menghentikan perulangan
            printf ("\n-- Program Telah Berakhir --\n\n");
        }

        // jika user meng-input query, maka jalankan prosedur
        else
        {
            // memanggil prosedur untuk memodifikasi data sesuai spesifikasi
            modify_tape (tape, pelanggan, barang, penjualan);

            // memanggil prosedur untuk memasukkan data terbaru kedalam file
            flushPelanggan (pelanggan);
            flushBarang (barang);
            flushPenjualan (penjualan);
        }
    }

    return 0; // mengembalikan nilai 0 dari fungsi main
}