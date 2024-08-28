/* Saya Ahmad Taufiq H (2202074) mengerjakan Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h> // include untuk library standard input output
#include <string.h> // include untuk library string
#include <stdlib.h> // include untuk standard library

// deklarasi tipe bungkusan pelanggan
typedef struct
{
    char idPelanggan [20]; // variabel untuk menyimpan id pelanggan
    char namaPelanggan[50]; // variabel untuk menyimpan nama pelanggan
    int lenNama;
} dataPelanggan;

// deklarasi tipe bungkusan barang
typedef struct
{
    char idBarang [20]; // variabel untuk menyimpan id barang
    char namaBarang[50]; // variabel untuk menyimpan nama barang
    int lenBarang;
} dataBarang;

// deklarasi tipe bungkusan penjualan
typedef struct
{
    char idPenjualan [20]; // variabel untuk menyimpan id penjualan
    char fkPelanggan [20]; // variabel untuk menyimpan foreign key id pelanggan
    char fkBarang [20]; // variabel untuk menyimpan foreign key id barang
    char date [11]; // variabel untuk menyimpan tanggal penjualan
} dataPenjualan;

// deklarasi variabel global
extern int idx;     // index dari karakter terakhir pada kata
extern int wlen;    // panjang kata (word length)
extern char cw[50]; // kata saat ini (current word)

extern int nPelanggan, nBarang, nPenjualan; // variabel menyimpan index record tabel

// bagian untuk memulai, mereset, dan mengakhiri mesin kata
void start(char str[]);
void reset();
int eop(char str[]);

// bagian memajukan mesin kata
void inc(char str[]);

// bagian mendapatkan variabel global/atribut mesin kata
int getlen();
char *getcw();
int length(char word[]);
void strip (int n);
void spasi (int n);

// prosedur dan fungsi tambahan
void modify_tape (char str[], dataPelanggan *pelanggan, dataBarang *barang, dataPenjualan *penjualan);

// fungsi untuk melakukan read dari sequential file
int readPelanggan (dataPelanggan *pelanggan);
int readBarang (dataBarang *barang);
int readPenjualan (dataPenjualan *penjualan);

// fungsi untuk melakukan flush record terbaru ke sequential file
void flushPelanggan (dataPelanggan *pelanggan);
void flushBarang (dataBarang *barang);
void flushPenjualan (dataPenjualan *penjualan);

// prosedur untuk melakukan proses ISI HAPUS dan join tabel
void joinTable (dataPelanggan *pelanggan, dataBarang *barang, dataPenjualan *penjualan, int menu);
void hapus (dataPelanggan *pelanggan, dataBarang *barang, dataPenjualan *penjualan, char str[], int menu);
void isi (dataPelanggan *pelanggan, dataBarang *barang, dataPenjualan *penjualan, char str[], int menu);