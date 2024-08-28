/* Saya Ahmad Taufiq H (2202074) mengerjakan Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h" // include file header.h

// fungsi untuk memodifikasi input user
void modify_tape (char str[], dataPelanggan *pelanggan, dataBarang *barang, dataPenjualan *penjualan)
{
    // perintah untuk membersihkan console
    system("cls");

    // memulai mesin kata
    start(str);

    // kondisi jika query yang digunakan adalah ISI
    if (strcmp(getcw(), "ISI") == 0)
    {
        inc(str);
        int exist = 0;

        // kondisi jika query yang digunakan adalah ISI UBAH
        if (strcmp(getcw(), "UBAH") == 0)
        {
            inc(str);

            // kondisi jika memilih dari tabel pelanggan
            if (strcmp(getcw(), "tPelanggan") == 0 && eop(str) == 0)
            {
                inc(str);
                
                int i = 0, upd = 0;
                // ulangi untuk seluruh record dalam tabel pelanggan
                while (i < nPelanggan - 1 && exist == 0)
                {
                    // jika ditemukan record pelanggan dengan id yang sama
                    if (strcmp(pelanggan[i].idPelanggan, getcw()) == 0 && eop(str) == 0)
                    {
                        inc(str);

                        if (eop(str) == 1)
                        {
                            // lakukan perubahan record dan alert perubahan berhasil
                            strcpy(pelanggan[i].namaPelanggan, getcw());
                            pelanggan[i].lenNama = getlen();
                            printf ("-- (UBAH tPelanggan) record dengan id : %s berhasil diubah --\n\n", pelanggan[i].idPelanggan);
                            upd = 1;
                        }

                        // jika terjadi kesalahan update
                        if (upd == 0) printf ("-- (ERROR ISI UBAH tPelanggan) jumlah kolom tidak sesuai dengan tabel --\n\n");

                        exist = 1;
                    }

                    i++;
                }
                
                // jika tidak ditemukan record dengan id yang sama, lakukan pengisian record baru
                if (exist == 0 && eop(str) == 0)
                {
                    isi (pelanggan, barang, penjualan, str, 1);
                }
            }

            // kondisi jika memilih dari tabel barang
            else if (strcmp(getcw(), "tBarang") == 0 && eop(str) == 0)
            {
                inc(str);
                
                int i = 0, upd = 0;
                while (i < nBarang - 1 && exist == 0)
                {
                    if (strcmp(barang[i].idBarang, getcw()) == 0 && eop(str) == 0)
                    {
                        inc(str);

                        if (eop(str) == 1)
                        {
                            strcpy(barang[i].namaBarang, getcw());
                            barang[i].lenBarang = getlen();
                            printf ("-- (UBAH tBarang) record dengan id : %s berhasil diubah --\n\n", barang[i].idBarang);
                            upd = 1;
                        }

                        if (upd == 0) printf ("-- (ERROR ISI UBAH tBarang) jumlah kolom tidak sesuai dengan tabel --\n\n");

                        exist = 1;
                    }

                    i++;
                }

                if (exist == 0 && eop(str) == 0)
                {
                    isi (pelanggan, barang, penjualan, str, 2);
                }
            }

            // kondisi jika memilih dari tabel penjualan
            else if (strcmp(getcw(), "tPenjualan") == 0 && eop(str) == 0)
            {
                inc(str);
                
                int i = 0, upd = 0;
                while (i < nPenjualan - 1 && exist == 0)
                {
                    if (strcmp(penjualan[i].idPenjualan, getcw()) == 0 && eop(str) == 0)
                    {
                        dataPenjualan tempPenjualan = penjualan[i];

                        if (eop(str) == 0)
                        {
                            inc(str);
                            strcpy(penjualan[i].fkPelanggan, getcw());

                            if (eop(str) == 0)
                            {
                                inc(str);
                                strcpy(penjualan[i].fkBarang, getcw());

                                if (eop(str) == 0)
                                {
                                    inc(str);
                                    strcpy(penjualan[i].date, getcw());
                                    printf ("-- (UBAH tPenjualan) record dengan id : %s berhasil diubah --\n\n", penjualan[i].idPenjualan);
                                    upd = 1;
                                }
                            }
                        }

                        if (upd == 0) 
                        {
                            penjualan[i] = tempPenjualan;
                            printf ("-- (ERROR ISI UBAH tPenjualan) jumlah kolom tidak sesuai dengan tabel --\n\n");
                        }

                        exist = 1;
                    }

                    i++;
                }

                if (exist == 0 && eop(str) == 0)
                {
                    isi (pelanggan, barang, penjualan, str, 3);
                }
            }

            // error handling jika nama tabel bukan tPelanggan, tBarang / tPenjualan
            else
            {
                printf ("-- (ERROR ISI UBAH) tidak ada tabel dengan nama %s --\n\n", getcw());
            }
        }
        
        // kondisi jika query yang digunakan hanya ISI saja
        else if (strcmp(getcw(), "tPelanggan") == 0)
        {
            inc (str);
            isi (pelanggan, barang, penjualan, str , 1);
        }

        else if (strcmp(getcw(), "tBarang") == 0)
        {
            inc (str);
            isi (pelanggan, barang, penjualan, str , 2);
        }

        else if (strcmp(getcw(), "tPenjualan") == 0)
        {
            inc (str);
            isi (pelanggan, barang, penjualan, str , 3);
        }

        // error handling jika nama tabel bukan tPelanggan, tBarang / tPenjualan
        else
        {
            printf ("-- (ERROR ISI) tidak ada tabel dengan nama %s --\n\n", getcw());
        }
    }

    // kondisi jika quey yang digunakan adalah UBAH
    else if (strcmp(getcw(), "UBAH") == 0)
    {
        inc(str);
        int exist = 0;

        // kondisi jika memilih dari tabel pelanggan
        if (strcmp(getcw(), "tPelanggan") == 0 && eop(str) == 0)
        {
            inc(str);
            
            int i = 0, upd = 0;
            while (i < nPelanggan - 1 && exist == 0)
            {
                if (strcmp(pelanggan[i].idPelanggan, getcw()) == 0 && eop(str) == 0)
                {
                    inc(str);

                    if (eop(str) == 1)
                    {
                        strcpy(pelanggan[i].namaPelanggan, getcw());
                        pelanggan[i].lenNama = getlen();
                        printf ("-- (UBAH tPelanggan) record dengan id : %s berhasil diubah --\n\n", pelanggan[i].idPelanggan);
                        upd = 1;
                    }

                    if (upd == 0) printf ("-- (ERROR UBAH tPelanggan) jumlah kolom tidak sesuai dengan tabel --\n\n");

                    exist = 1;
                }

                i++;
            }

            if (exist == 0)
            {
                printf ("-- (ERROR UBAH tPelanggan) tidak ditemukan data pelanggan dengan id : %s --\n\n", getcw());
            }
        }

        // kondisi jika memilih dari tabel barang
        else if (strcmp(getcw(), "tBarang") == 0 && eop(str) == 0)
        {
            inc(str);
            
            int i = 0, upd = 0;
            while (i < nBarang - 1 && exist == 0)
            {
                if (strcmp(barang[i].idBarang, getcw()) == 0 && eop(str) == 0)
                {
                    inc(str);

                    if (eop(str) == 1)
                    {
                        strcpy(barang[i].namaBarang, getcw());
                        barang[i].lenBarang = getlen();
                        printf ("-- (ISI UBAH tBarang) record dengan id : %s berhasil diubah --\n\n", barang[i].idBarang);
                        upd = 1;
                    }

                    if (upd == 0) printf ("-- (ERROR ISI UBAH tBarang) jumlah kolom tidak sesuai dengan tabel --\n\n");

                    exist = 1;
                }

                i++;
            }

            if (exist == 0)
            {
                printf ("-- (ERROR UBAH tBarang) tidak ditemukan data barang dengan id : %s --\n\n", getcw());
            }
        }

        // kondisi jika memilih dari tabel penjualan
        else if (strcmp(getcw(), "tPenjualan") == 0 && eop(str) == 0)
        {
            inc(str);
            
            int i = 0, upd = 0;
            while (i < nPenjualan - 1 && exist == 0)
            {
                if (strcmp(penjualan[i].idPenjualan, getcw()) == 0 && eop(str) == 0)
                {
                    dataPenjualan tempPenjualan = penjualan[i];

                    if (eop(str) == 0)
                    {
                        inc(str);
                        strcpy(penjualan[i].fkPelanggan, getcw());

                        if (eop(str) == 0)
                        {
                            inc(str);
                            strcpy(penjualan[i].fkBarang, getcw());

                            if (eop(str) == 0)
                            {
                                inc(str);
                                strcpy(penjualan[i].date, getcw());
                                printf ("-- (UBAH tPenjualan) record dengan id : %s berhasil diubah --\n\n", penjualan[i].idPenjualan);
                                upd = 1;
                            }
                        }
                    }

                    if (upd == 0) 
                    {
                        penjualan[i] = tempPenjualan;
                        printf ("-- (ERROR ISI UBAH tPenjualan) jumlah kolom tidak sesuai dengan tabel --\n\n");
                    }

                    exist = 1;
                }

                i++;
            }

            if (exist == 0)
            {
                printf ("-- (ERROR UBAH tPenjualan) tidak ditemukan data penjualan dengan id : %s --\n\n", getcw());
            }
        }

        // error handling jika nama tabel bukan tPelanggan, tBarang / tPenjualan
        else
        {
            printf ("-- (ERROR UBAH) tidak ada tabel dengan nama %s --\n\n", getcw());
        }
    }

    // kondisi jika query yang digunakan adalah HAPUS
    else if (strcmp(getcw(), "HAPUS") == 0)
    {
        inc(str);

        // kondisi jika query yang digunakan hanya ISI saja
        if (strcmp(getcw(), "tPelanggan") == 0)
        {
            inc (str);
            hapus (pelanggan, barang, penjualan, str, 1);
        }

        else if (strcmp(getcw(), "tBarang") == 0)
        {
            inc (str);
            hapus (pelanggan, barang, penjualan, str, 2);
        }

        else if (strcmp(getcw(), "tPenjualan") == 0)
        {
            inc (str);
            hapus (pelanggan, barang, penjualan, str, 3);
        }

        else 
        {
            printf ("-- (ERROR HAPUS) tidak ada tabel dengan nama %s --\n\n", getcw());
        }
    }

    // kondisi jika query yang digunakan adalah TAMPIL
    else if (strcmp(getcw(), "TAMPIL") == 0)
    {
        inc(str);

        // kondisi jika menampilkan tabel pelanggan
        if (strcmp(getcw(), "tPelanggan") == 0 && eop(str) == 1)
        {
            printf ("\n-- isi tabel pelangan : --\n");

            if (nPelanggan > 1)
            {
                int lenPelanggan = length ("Nama Pelanggan");

                for (int i = 0; i < nPelanggan; i++)
                {
                    if (lenPelanggan < pelanggan[i].lenNama)
                    {
                        lenPelanggan = pelanggan[i].lenNama;
                    }
                }

                strip(lenPelanggan + 19);

                printf ("| Id Pelanggan | ");
                printf ("Nama Pelanggan");
                spasi (lenPelanggan - 14);
                printf (" |\n");

                strip(lenPelanggan + 19);

                for (int i = 0; i < nPelanggan - 1; i++)
                {
                    printf ("| %s", pelanggan[i].idPelanggan);
                    spasi (9);
                    printf ("| %s", pelanggan[i].namaPelanggan);
                    spasi (lenPelanggan - pelanggan[i].lenNama + 1);
                    printf ("|\n");
                }

                strip(lenPelanggan + 19); printf("\n");
            }

            else
            {
                printf ("-- (TAMPIL tPelanggan) tabel pelanggan kosong --\n");
            } printf ("\n");
        }

        // kondisi jika menampilkan tabel barang
        else if (strcmp(getcw(), "tBarang") == 0 && eop(str) == 1)
        {
            printf ("\n-- isi tabel barang : --\n");

            if (nBarang > 1)
            {
                int lenBarang = length ("Nama Barang");

                for (int i = 0; i < nPelanggan; i++)
                {
                    if (lenBarang < barang[i].lenBarang)
                    {
                        lenBarang = barang[i].lenBarang;
                    }
                }

                strip(lenBarang + 16);

                printf ("| Id Barang | ");
                printf ("Nama Barang");
                spasi (lenBarang - 11);
                printf (" |\n");

                strip(lenBarang + 16);

                for (int i = 0; i < nPelanggan - 1; i++)
                {
                    printf ("| %s", barang[i].idBarang);
                    spasi (6);
                    printf ("| %s", barang[i].namaBarang);
                    spasi (lenBarang - barang[i].lenBarang + 1);
                    printf ("|\n");
                }

                strip(lenBarang + 16); printf("\n");
            }

            else
            {
                printf ("-- (TAMPIL tBarang) tabel barang kosong --\n");
            } printf ("\n");
        }

        // kondisi jika menampilkan tabel penjualan
        else if (strcmp(getcw(), "tPenjualan") == 0) 
        {
            if (eop(str) == 1)
            {
                printf ("\n-- isi tabel penjualan : --\n");

                if (nPenjualan > 1)
                {
                    strip(51);
                    printf ("| Id Penjualan | Pelanggan | Layanan |   Tanggal  |\n");
                    strip(51);

                    for (int i = 0; i < nPenjualan - 1; i++)
                    {
                        printf ("| %s         | %s      | %s    | %s |\n", penjualan[i].idPenjualan, penjualan[i].fkPelanggan, penjualan[i].fkBarang, penjualan[i].date);
                    }

                    strip(51); printf("\n");
                }

                else
                {
                    printf ("-- (TAMPIL tPenjualan) tabel penjualan kosong --\n");
                } printf ("\n");
            }

            // kondisi join tabel
            else if (eop(str) == 0)
            {
                inc(str);

                // kondisi join dengan tabel pelanggan
                if (strcmp(getcw(), "tPelanggan") == 0 && eop(str) == 1)
                {
                    printf ("\n-- isi tabel penjualan (JOIN tPelanggan) : --\n");

                    if (nPenjualan > 1)
                    {
                        if (nPelanggan > 1)
                        {
                            int spacePelanggan = 9;

                            for (int i = 0; i < nPelanggan; i++)
                            {
                                if (spacePelanggan < pelanggan[i].lenNama)
                                {
                                    spacePelanggan = pelanggan[i].lenNama;
                                }
                            }

                            strip(42 + spacePelanggan);
                            printf ("| Id Penjualan | Pelanggan");
                            spasi (spacePelanggan - 8);
                            printf ("| Layanan |   Tanggal  |\n");
                            strip(42 + spacePelanggan);

                            for (int i = 0; i < nPenjualan - 1; i++)
                            {
                                int idxPelanggan = -1, j = 0;
                                while (j < nPelanggan && idxPelanggan == -1)
                                {
                                    if (strcmp(penjualan[i].fkPelanggan, pelanggan[j].idPelanggan) == 0)
                                    {
                                        idxPelanggan = j;
                                    }
                                    j++;
                                }

                                if (idxPelanggan == -1)
                                {
                                    printf ("| %s         | %s ", penjualan[i].idPenjualan, penjualan[i].fkPelanggan);
                                    spasi(spacePelanggan - 4);
                                    printf ("| %s    | %s |\n", penjualan[i].fkBarang, penjualan[i].date);
                                }

                                else
                                {
                                    printf ("| %s         | %s ", penjualan[i].idPenjualan, pelanggan[idxPelanggan].namaPelanggan);
                                    spasi(spacePelanggan - pelanggan[idxPelanggan].lenNama);
                                    printf ("| %s    | %s |\n", penjualan[i].fkBarang, penjualan[i].date);                                
                                }
                            }

                            strip(42 + spacePelanggan);
                        }

                        else
                        {
                            printf ("-- (TAMPIL tPelanggan) tabel pelanggan kosong --\n");
                        } printf ("\n");
                    }

                    else
                    {
                        printf ("-- (TAMPIL tPenjualan) tabel penjualan kosong --\n");
                    } printf ("\n");
                }

                // kondisi join dengan tabel barang
                else if (strcmp(getcw(), "tBarang") == 0 && eop(str) == 1)
                {
                    printf ("\n-- isi tabel penjualan (JOIN tBarang) : --\n");
                    
                    if (nPenjualan > 1)
                    {
                        if (nBarang > 1)
                        {
                            int spaceBarang = 7;

                            for (int i = 0; i < nBarang; i++)
                            {
                                if (spaceBarang < barang[i].lenBarang)
                                {
                                    spaceBarang = barang[i].lenBarang;
                                }
                            }

                            strip(44 + spaceBarang);
                            printf ("| Id Penjualan | Pelanggan | Layanan ");
                            spasi (spaceBarang - 7);
                            printf ("|   Tanggal  |\n");
                            strip(44 + spaceBarang);

                            for (int i = 0; i < nPenjualan - 1; i++)
                            {
                                int idxBarang = -1, j = 0;
                                while (j < nBarang && idxBarang == -1)
                                {
                                    if (strcmp(penjualan[i].fkBarang, barang[j].idBarang) == 0)
                                    {
                                        idxBarang = j;
                                    }
                                    j++;
                                }

                                if (idxBarang == -1)
                                {
                                    printf ("| %s         | %s      | %s ", penjualan[i].idPenjualan, penjualan[i].fkPelanggan, penjualan[i].fkBarang);
                                    spasi(spaceBarang - 4);
                                    printf ("| %s |\n", penjualan[i].date);
                                }

                                else
                                {
                                    printf ("| %s         | %s      | %s ", penjualan[i].idPenjualan, penjualan[i].fkPelanggan, barang[idxBarang].namaBarang);
                                    spasi(spaceBarang - barang[idxBarang].lenBarang);
                                    printf ("| %s |\n", penjualan[i].date);
                                }
                            }

                            strip(44 + spaceBarang);
                        }

                        else
                        {
                            printf ("-- (TAMPIL tBarang) tabel barang kosong --\n");
                        } printf ("\n");
                    }

                    else
                    {
                        printf ("-- (TAMPIL tPenjualan) tabel penjualan kosong --\n");
                    } printf ("\n");
                }

                else if (eop(str) == 0)
                {
                    if (strcmp(getcw(), "tPelanggan") == 0)
                    {
                        inc(str);

                        if (strcmp(getcw(), "tBarang") == 0 && eop(str) == 1)
                        {
                            joinTable (pelanggan, barang, penjualan, 3);
                        }

                        else
                        {
                            printf ("\n-- (ERROR TAMPIL) tidak ada tabel dengan nama %s --\n\n", getcw());
                        }
                    }

                    else if (strcmp(getcw(), "tBarang") == 0)
                    {
                        inc(str);

                        if (strcmp(getcw(), "tPelanggan") == 0 && eop(str) == 1)
                        {
                            joinTable (pelanggan, barang, penjualan, 3);
                        }

                        else
                        {
                            printf ("\n-- (ERROR TAMPIL) tidak ada tabel dengan nama %s --\n\n", getcw());
                        }
                    }
                }

                else
                {
                    printf ("\n-- (ERROR TAMPIL) tidak ada tabel dengan nama %s --\n\n", getcw());
                }
            }
        }

        // error handling jika nama tabel bukan tPelanggan, tBarang / tPenjualan
        else
        {
            printf ("\n-- (ERROR TAMPIL) tidak ada tabel dengan nama %s --\n\n", getcw());
        }
    }

    // error handling jika perintah bukan ISI / UBAH / HAPUS / TAMPIL
    else
    {
        printf ("-- (ERROR) perintah yang anda gunakan salah --\n\n", getcw());
    }
}

// fungsi untuk read data dari file pelanggan
int readPelanggan (dataPelanggan *pelanggan)
{
    FILE *fPelanggan; // pointer ke file
    fPelanggan = fopen("tPelanggan.dat", "r"); // buka file dengan mode read
    // masukan baris pertama pada file kedalam array tipe bungkusan
    fscanf (fPelanggan, "%s %s", pelanggan[nPelanggan].idPelanggan, pelanggan[nPelanggan].namaPelanggan);
    pelanggan[nPelanggan].lenNama = length(pelanggan[nPelanggan].namaPelanggan);

    // cek kolom id yang baru discan tadi apakah merupakan EOF atau bukan?
    if (strcmp(pelanggan[nPelanggan].idPelanggan, "####") != 0)
    {
        // jika bukan, lakukan perunalangan selama belum EOF
        while (strcmp(pelanggan[nPelanggan].idPelanggan, "####") != 0)
        {
            // lakukan increment untuk menambah index, dan masukkan baris kedalam array tipe bungkusan
            nPelanggan++;
            fscanf (fPelanggan, "%s %s", pelanggan[nPelanggan].idPelanggan, pelanggan[nPelanggan].namaPelanggan);
            pelanggan[nPelanggan].lenNama = length(pelanggan[nPelanggan].namaPelanggan);
        }
    }
    
    nPelanggan++; // increment akhir proses baca data dari file
    fclose(fPelanggan); // tutup file
    return nPelanggan; // kembalikan nilai index
}

// fungsi untuk read data dari file barang
int readBarang (dataBarang *barang)
{
    FILE *fBarang; // pointer ke file
    fBarang = fopen("tBarang.dat", "r"); // buka file dengan mode read
    // masukan baris pertama pada file kedalam array tipe bungkusan
    fscanf (fBarang, "%s %s", barang[nBarang].idBarang, barang[nBarang].namaBarang);
    barang[nBarang].lenBarang = length(barang[nBarang].namaBarang);

    // cek kolom id yang baru discan tadi apakah merupakan EOF atau bukan?
    if (strcmp(barang[nBarang].idBarang, "####") != 0)
    {
        // jika bukan, lakukan perunalangan selama belum EOF
        while (strcmp(barang[nBarang].idBarang, "####") != 0)
        {
            // lakukan increment untuk menambah index, dan masukkan baris kedalam array tipe bungkusan
            nBarang++;
            fscanf (fBarang, "%s %s", barang[nBarang].idBarang, barang[nBarang].namaBarang);
            barang[nBarang].lenBarang = length(barang[nBarang].namaBarang);
        }
    }

    nBarang++; // increment akhir proses baca data dari file
    fclose(fBarang); // tutup file
    return nBarang; // kembalikan nilai index
}

// fungsi untuk read data dari file penjualan
int readPenjualan (dataPenjualan *penjualan)
{
    FILE *fPenjualan; // pointer ke file
    fPenjualan = fopen("tPenjualan.dat", "r"); // buka file dengan mode read
    // masukan baris pertama pada file kedalam array tipe bungkusan
    fscanf (fPenjualan, "%s %s %s %s", penjualan[nPenjualan].idPenjualan, penjualan[nPenjualan].fkPelanggan, penjualan[nPenjualan].fkBarang, penjualan[nPenjualan].date);

    // cek kolom id yang baru discan tadi apakah merupakan EOF atau bukan?
    if (strcmp(penjualan[nPenjualan].idPenjualan, "####") != 0)
    {
        // jika bukan, lakukan perunalangan selama belum EOF
        while (strcmp(penjualan[nPenjualan].idPenjualan, "####") != 0)
        {
            // lakukan increment untuk menambah index, dan masukkan baris kedalam array tipe bungkusan
            nPenjualan++;
            fscanf (fPenjualan, "%s %s %s %s", penjualan[nPenjualan].idPenjualan, penjualan[nPenjualan].fkPelanggan, penjualan[nPenjualan].fkBarang, penjualan[nPenjualan].date);
        }
    }

    nPenjualan++; // increment akhir proses baca data dari file
    fclose(fPenjualan); // tutup file
    return nPenjualan; // kembalikan nilai index
}

// fungsi untuk flush data pelanggan kedalam file pelanggan
void flushPelanggan (dataPelanggan *pelanggan)
{
    FILE *fPelanggan; // pointer ke file
    fPelanggan = fopen("tPelanggan.dat", "w"); // buka file dengan mode write

    // tulis data ke file
    for (int i = 0; i < nPelanggan; i++)
    {
        // tulis 2 kolom lalu beri newline
        fprintf(fPelanggan, "%s %s\n", pelanggan[i].idPelanggan, pelanggan[i].namaPelanggan);
    }

    // "tutup file"
    fclose(fPelanggan);
}

// fungsi untuk flush data barang kedalam file barang
void flushBarang (dataBarang *barang)
{
    FILE *fBarang; // pointer ke file
    fBarang = fopen("tBarang.dat", "w"); // buka file dengan mode write

    // tulis data ke file
    for (int i = 0; i < nBarang; i++)
    {
        // tulis 2 kolom lalu beri newline
        fprintf(fBarang, "%s %s\n", barang[i].idBarang, barang[i].namaBarang);
    }

    // "tutup file"
    fclose(fBarang);
}

// fungsi untuk flush data penjualan kedalam file penjualan
void flushPenjualan (dataPenjualan *penjualan)
{
    FILE *fPenjualan; // pointer ke file
    fPenjualan = fopen("tPenjualan.dat", "w"); // buka file dengan mode write

    // tulis data ke file
    for (int i = 0; i < nPenjualan; i++)
    {
        // tulis 4 kolom lalu beri newline
        fprintf(fPenjualan, "%s %s %s %s\n", penjualan[i].idPenjualan, penjualan[i].fkPelanggan, penjualan[i].fkBarang, penjualan[i].date);
    }

    // "tutup file"
    fclose(fPenjualan);
}

// fungsi utnuk menghitung panjang sebuah kata
int length (char word[])
{
    int len = 0;

    while (word[len] != '\0')
    {
        len++;
    }

    return len;
}

// prosedur untuk output garis horizontal pada tabel
void strip (int n)
{
    for (int i = 0; i < n; i++)
    {
        printf ("~");
    } printf ("\n");
}

// prosedur untuk loop spasi
void spasi (int n)
{
    for (int i = 0; i < n; i++) 
    {
        printf (" ");
    }
}

// prosedur untuk menampilkan hasil join table
void joinTable (dataPelanggan *pelanggan, dataBarang *barang, dataPenjualan *penjualan, int menu)
{
    if (menu == 3)
    {
        printf ("\n-- isi tabel penjualan (JOIN tBarang tPenjualan) : --\n");

        if (nPenjualan > 1)
        {
            if (nPelanggan > 1)
            {
                if (nBarang > 1)
                {
                    int spaceBarang = 7;
                    int spacePelanggan = 9;

                    for (int i = 0; i < nPelanggan; i++)
                    {
                        if (spacePelanggan < pelanggan[i].lenNama)
                        {
                            spacePelanggan = pelanggan[i].lenNama;
                        }
                    }

                    for (int i = 0; i < nBarang; i++)
                    {
                        if (spaceBarang < barang[i].lenBarang)
                        {
                            spaceBarang = barang[i].lenBarang;
                        }
                    }

                    strip(35 + spaceBarang + spacePelanggan);
                    printf ("| Id Penjualan | Pelanggan");
                    spasi (spacePelanggan - 8);
                    printf ("| Layanan ");
                    spasi (spaceBarang - 7);
                    printf ("|   Tanggal  |\n");
                    strip(35 + spaceBarang + spacePelanggan);

                    for (int i = 0; i < nPenjualan - 1; i++)
                    {
                        int idxPelanggan = -1, idxBarang = -1, j = 0, k = 0;

                        while (j < nPelanggan && idxPelanggan == -1)
                        {
                            if (strcmp(penjualan[i].fkPelanggan, pelanggan[j].idPelanggan) == 0)
                            {
                                idxPelanggan = j;
                            }
                            j++;
                        }

                        while (k < nBarang && idxBarang == -1)
                        {
                            if (strcmp(penjualan[i].fkBarang, barang[k].idBarang) == 0)
                            {
                                idxBarang = k;
                            }
                            k++;
                        }

                        if (idxPelanggan == -1 && idxBarang == -1)
                        {
                            printf ("| %s         | %s ", penjualan[i].idPenjualan, penjualan[i].fkPelanggan);
                            spasi(spacePelanggan - 4);
                            printf ("| %s ", penjualan[i].fkBarang);
                            spasi(spaceBarang - 4);
                            printf ("| %s |\n", penjualan[i].date);
                        }

                        else if (idxBarang == -1)
                        {
                            printf ("| %s         | %s ", penjualan[i].idPenjualan, pelanggan[idxPelanggan].namaPelanggan);
                            spasi(spacePelanggan - pelanggan[idxPelanggan].lenNama);
                            printf ("| %s ", penjualan[i].fkBarang);
                            spasi(spaceBarang - 4);
                            printf ("| %s |\n", penjualan[i].date);                               
                        }

                        else if (idxPelanggan == -1)
                        {
                            printf ("| %s         | %s ", penjualan[i].idPenjualan, penjualan[i].fkPelanggan);
                            spasi(spacePelanggan - 4);
                            printf ("| %s ", barang[idxBarang].namaBarang);
                            spasi(spaceBarang - barang[idxBarang].lenBarang);
                            printf ("| %s |\n", penjualan[i].date);   
                        }

                        else
                        {
                            printf ("| %s         | %s ", penjualan[i].idPenjualan, pelanggan[idxPelanggan].namaPelanggan);
                            spasi(spacePelanggan - pelanggan[idxPelanggan].lenNama);
                            printf ("| %s ", barang[idxBarang].namaBarang);
                            spasi(spaceBarang - barang[idxBarang].lenBarang);
                            printf ("| %s |\n", penjualan[i].date);   
                        }
                    }

                    strip(35 + spaceBarang + spacePelanggan);
                }

                else
                {
                    printf ("-- (TAMPIL tBarang) tabel barang kosong --\n");
                }
            }

            else
            {
                printf ("-- (TAMPIL tPelanggan) tabel pelanggan kosong --\n");
            }
        }

        else
        {
            printf ("-- (TAMPIL tPenjualan) tabel penjualan kosong --\n");
        } printf ("\n");
    }
}

// prosedur untuk menghapus record
void hapus (dataPelanggan *pelanggan, dataBarang *barang, dataPenjualan *penjualan, char str[], int menu)
{
    // kondisi jika menhapus dari tabel pelanggan
    if (menu == 1)
    {
        if (eop(str) == 1 && strcmp(getcw(), "####") != 0)
        {
            int i = 0, del = 0;

            while (i < nPelanggan - 1 && del == 0)
            {
                if (strcmp(pelanggan[i].idPelanggan, getcw()) == 0)
                {
                    while (i < nPelanggan)
                    {
                        pelanggan[i] = pelanggan[i+1];
                        i++;
                    }
                    
                    printf ("\n-- (HAPUS tPelanggan) berhasil hapus record pelanggan dengan id : %s --\n\n", getcw());
                    del = 1;
                    nPelanggan--;
                }
                
                i++;
            }

            if (del == 0)
            {
                printf ("\n-- (ERROR HAPUS tPelanggan) tidak ditemukan pelanggan dengan id : %s --\n\n", getcw());
            }
        }

        else printf ("\n-- (ERROR HAPUS tPelanggan) format yang anda masukkan salah --\n\n");
    }

    // kondisi jika menghapus dari tabel barang
    else if (menu == 2)
    {
        if (eop(str) == 1 && strcmp(getcw(), "####") != 0)
        {
            int i = 0, del = 0;

            while (i < nBarang - 1 && del == 0)
            {
                if (strcmp(barang[i].idBarang, getcw()) == 0)
                {
                    while (i < nBarang)
                    {
                        barang[i] = barang[i+1];
                        i++;
                    }
                    
                    printf ("\n-- (HAPUS tBarang) berhasil hapus record barang dengan id : %s --\n\n", getcw());
                    del = 1;
                    nBarang--;
                }
                
                i++;
            }

            if (del == 0)
            {
                printf ("\n-- (ERROR HAPUS tBarang) tidak ditemukan barang dengan id : %s --\n\n", getcw());
            }
        }

        else printf ("\n-- (ERROR HAPUS tBarang) format yang anda masukkan salah --\n\n");
    }

    // kondisi jika menghapus dari tabel penjualan
    else if (menu == 3)
    {
        if (eop(str) == 1 && strcmp(getcw(), "####") != 0)
        {
            int i = 0, del = 0;

            while (i < nPenjualan - 1 && del == 0)
            {
                if (strcmp(penjualan[i].idPenjualan, getcw()) == 0)
                {
                    while (i < nPenjualan)
                    {
                        penjualan[i] = penjualan[i+1];
                        i++;
                    }
                    
                    printf ("\n-- (HAPUS tPenjualan) berhasil hapus record penjualan dengan id : %s --\n\n", getcw());
                    del = 1;
                    nPenjualan--;
                }
                
                i++;
            }

            if (del == 0)
            {
                printf ("\n-- (ERROR HAPUS tPenjualan) tidak ditemukan penjualan dengan id : %s --\n\n", getcw());
            }
        }

        else printf ("\n-- (ERROR HAPUS tPenjualan) format yang anda masukkan salah --\n\n");
    }

    // error handling jika nama tabel bukan tPelanggan, tBarang / tPenjualan
    else
    {
        printf ("\n-- (ERROR HAPUS) tidak ada tabel dengan nama %s --\n\n", getcw());
    }
}

// prosedur untuk mengisi record baru
void isi (dataPelanggan *pelanggan, dataBarang *barang, dataPenjualan *penjualan, char str[], int menu)
{
    int exist = 0;

    // kondisi jika memilih dari tabel pelanggan
    if (menu == 1)
    {
        for (int i = 0; i < nPelanggan - 1; i++)
        {
            if (strcmp(getcw(), pelanggan[i].idPelanggan) == 0)
            {
                printf ("-- (ERROR ISI tPelanggan) ditemukan record pelanggan dengan id : %s --\n\n", getcw());
                exist = 1;
            }
        }

        if (exist == 0 && eop(str) == 0)
        {
            int notValid = 0;
            nPelanggan--;

            if (eop(str) == 0 && notValid == 0)
            {
                strcpy(pelanggan[nPelanggan].idPelanggan, getcw());
                inc(str);
            } else notValid = 1;

            if (eop(str) == 1 && notValid == 0) 
            {
                strcpy(pelanggan[nPelanggan].namaPelanggan, getcw());
                pelanggan[nPelanggan].lenNama = getlen();
            } else notValid = 1;

            if (notValid == 0) 
            {
                printf ("-- (ISI tPelanggan) record dengan id : %s berhasil ditambahkan --\n\n", pelanggan[nPelanggan].idPelanggan);

                nPelanggan++;
                strcpy(pelanggan[nPelanggan].idPelanggan, "####");
                strcpy(pelanggan[nPelanggan].namaPelanggan, "####");
                nPelanggan++;
            }

            else 
            {
                strcpy(pelanggan[nPelanggan].idPelanggan, "####");
                strcpy(pelanggan[nPelanggan].namaPelanggan, "####");
                nPelanggan++;
                printf ("-- (ERROR ISI tPelanggan) jumlah kolom tidak sesuai dengan tabel --\n\n");
            }
        }
    }

    // kondisi jika memilih dari tabel barang
    else if (menu == 2)
    {
        for (int i = 0; i < nBarang - 1; i++)
        {
            if (strcmp(getcw(), barang[i].idBarang) == 0)
            {
                printf ("-- (ERROR ISI tBarang) ditemukan record barang dengan id : %s --\n\n", getcw());
                exist = 1;
            }
        }

        if (exist == 0 && eop(str) == 0)
        {
            int notValid = 0;
            nBarang--;

            if (eop(str) == 0 && notValid == 0)
            {
                strcpy(barang[nBarang].idBarang, getcw());
                inc(str);
            } else notValid = 1;
            
            if (eop(str) == 1 && notValid == 0)
            {
                strcpy(barang[nBarang].namaBarang, getcw());
                barang[nBarang].lenBarang = getlen();
            } else notValid = 1;

            if (notValid == 0) 
            {
                printf ("-- (ISI tBarang) record dengan id : %s berhasil ditambahkan --\n\n", barang[nBarang].idBarang);

                nBarang++;
                strcpy(barang[nBarang].idBarang, "####");
                strcpy(barang[nBarang].namaBarang, "####");
                nBarang++;
            }

            else 
            {
                strcpy(barang[nBarang].idBarang, "####");
                strcpy(barang[nBarang].namaBarang, "####");
                nBarang++;
                printf ("-- (ERROR ISI tBarang) jumlah kolom tidak sesuai dengan tabel --\n\n");
            }
        }
    }

    // kondisi jika memilih dari tabel penjualan
    else if (menu == 3)
    {
        for (int i = 0; i < nPenjualan - 1; i++)
        {
            if (strcmp(getcw(), penjualan[i].idPenjualan) == 0)
            {
                printf ("-- (ERROR ISI tPenjualan) ditemukan record Penjualan dengan id : %s --\n\n", getcw());
                exist = 1;
            }
        }

        if (exist == 0 && eop(str) == 0)
        {
            int notValid = 0;
            nPenjualan--;

            if (eop(str) == 0 && notValid == 0)
            {
                strcpy(penjualan[nPenjualan].idPenjualan, getcw());
                inc(str);
            } else notValid = 1;

            if (eop(str) == 0 && notValid == 0)
            {
                strcpy(penjualan[nPenjualan].fkPelanggan, getcw());
                inc(str);
            } else notValid = 1;

            if (eop(str) == 0 && notValid == 0)
            {
                strcpy(penjualan[nPenjualan].fkBarang, getcw());
                inc(str);
            } else notValid = 1;

            if (eop(str) == 1 && notValid == 0)
            {
                strcpy(penjualan[nPenjualan].date, getcw());
            } else notValid = 1;

            if (notValid == 0) 
            {
                printf ("-- (ISI tPenjualan) record dengan id : %s berhasil ditambahkan --\n\n", penjualan[nPenjualan].idPenjualan);

                nPenjualan++;
                strcpy(penjualan[nPenjualan].idPenjualan, "####");
                strcpy(penjualan[nPenjualan].fkPelanggan, "####");
                strcpy(penjualan[nPenjualan].fkBarang, "####");
                strcpy(penjualan[nPenjualan].date, "####");
                nPenjualan++;
            }

            else 
            {
                strcpy(penjualan[nPenjualan].idPenjualan, "####");
                strcpy(penjualan[nPenjualan].fkPelanggan, "####");
                strcpy(penjualan[nPenjualan].fkBarang, "####");
                strcpy(penjualan[nPenjualan].date, "####");
                nPenjualan++;
                printf ("-- (ERROR ISI tPenjualan) jumlah kolom tidak sesuai dengan tabel --\n\n");
            }
        }
    }
}