#include <iostream>
#include <string>
using namespace std;

//Untuk Batas Maksimal Jumlah Mainan Yang Disimpan
#define max 30

/*
Blok Kode Untuk Menampung Variabel Global
*/
string loop; //Untuk Kembali Menginput Informasi Mainan Atau Menu
int daya_tampung = 0; //Untuk Mengetahui Jumlah Mainan Sudah Berapa
string ket_mainan; //Untuk Memilih Opsi Jenis Dan Kondisi Mainan
bool kembali; //Untuk Kembali Ke Menu Crud Atau Saat Pada Kondisi Koleksi Mainan Masih Kosong

/*
Prosedur Untuk Kembali
*/
void kembali_loop() {
    do {
        cout << "Kembali(y): ";
        getline(cin, loop);
    } while (loop != "y");
}

/*
Blok Kode Untuk Menampung Struct
*/
struct koleksi_mainan {
    string nama; //Nama Mainan
    string jenis; //Jenis Mainan
    string tahun_produksi; //Tahun Produksi Mainan
    string kondisi; //Kondisi Mainan Apakah Masih Layak Atau Tidak
};
koleksi_mainan mainan[max];
koleksi_mainan *mainanPtr = mainan; //Pointer pada array mainan

/*
Blok kode untuk menampung Fungsi
*/
bool kembali_kosong()
{
    if (daya_tampung == 0) {
        cout << "Koleksi Mainan Kosong!\n";
        kembali_loop();
        return true;
    } else {
        return false;
    }
}

string jenis_mainan() {
    string jenis;
    do {
        cout << "1. Boneka\n2. Action Figure\n3. Miniatur\n4. Mainan Edukasi\n5. Robot\n6. Puzzle\nPilih(1-6): ";
        getline(cin, ket_mainan);
        if (ket_mainan == "1") {
            jenis = "Boneka";
        } else if (ket_mainan == "2") {
            jenis = "Action Figure";
        } else if (ket_mainan == "3") {
            jenis = "Miniatur";
        } else if (ket_mainan == "4") {
            jenis = "Mainan Edukasi";
        } else if (ket_mainan == "5") {
            jenis = "Robot";
        } else if (ket_mainan == "6") {
            jenis = "Puzzle";
        } else {
            cout << "Tidak Valid" <<endl;
        }
    } while (ket_mainan != "1" and ket_mainan != "2" and ket_mainan != "3" and ket_mainan != "4" and ket_mainan != "5" and ket_mainan != "6");
    return jenis;
}

string kondisi_mainan() {
    string kondisi;
    do {
        cout << "1. Baru\n2. Masih Bagus\n3. Baret Sedikit\n4. Baret Parah\n5. Rusak\nPilih (1-5): ";
        getline(cin, ket_mainan);
        if (ket_mainan == "1") {
            kondisi = "Baru";
        } else if (ket_mainan == "2") {
            kondisi = "Masih Bagus";
        } else if (ket_mainan == "3") {
            kondisi = "Baret Sedikit";
        } else if (ket_mainan == "4") {
            kondisi = "Baret Parah";
        } else if (ket_mainan == "5") {
            kondisi = "Rusak";
        } else {
            cout << "Tidak Valid" <<endl;
        }
    } while (ket_mainan != "1" and ket_mainan != "2" and ket_mainan != "3" and ket_mainan != "4" and ket_mainan != "5");
    return kondisi;
}

/*
Blok kode untuk menampung Prosedur Crud
*/
void tampilkanKoleksiMainan(int indeks = 0) {
    kembali = kembali_kosong();
    if (kembali) {
        return;
    }
    if (indeks == daya_tampung) {
        return;
    } else {
        cout << "Mainan(" << indeks + 1 << ")\n" << "Nama: " << mainan[indeks].nama << "\n" << "Jenis Mainan: " << mainan[indeks].jenis << "\n" << "Tahun Produksi: " << mainan[indeks].tahun_produksi << "\n" << "Kondisi: " << mainan[indeks].kondisi << "\n" <<endl;
        tampilkanKoleksiMainan(indeks + 1);
    }
}

void tambahMainan() {
    for (int i = daya_tampung; i < max; i++) {
        system("cls");
        cout << "Kapasitas Penyimpanan " << i << "/" << max <<endl;
        cout << "Masukkan Nama Mainan: ";
        getline(cin, mainan[i].nama);
        cout << "Masukkan Jenis Mainan\n";
        mainan[i].jenis = jenis_mainan();
        cout << "Masukkan Tahun Produksi: ";
        getline(cin, mainan[i].tahun_produksi);
        cout << "Masukkan Kondisi Mainan\n";
        mainan[i].kondisi = kondisi_mainan();
        daya_tampung++;
        cout << "Kapasitas Koleksi Mainan Bertambah\n" <<endl;
        cout << "Tersisa " << max - (i+1) << " Ruang Penyimpanan" <<endl;
        cout << "Masukkan x jika ingin masih menambah mainan atau Masukkan tombol selain x untuk berhenti menambah: ";
        getline(cin, loop);
        if (loop=="x") {
            continue;
        } else {
            break;
        }
    }
}

void updateMainan(int indeks_mainan_int) {
    kembali = kembali_kosong();
    if (kembali) {
        return;
    }
    system("cls");
    cout << "Mainan(" << indeks_mainan_int << ")\n" << "Nama: " << mainan[indeks_mainan_int - 1].nama << "\n" << "Jenis Mainan: " << mainan[indeks_mainan_int - 1].jenis << "\n" << "Tahun Produksi: " << mainan[indeks_mainan_int - 1].tahun_produksi << "\n" << "Kondisi: " << mainan[indeks_mainan_int - 1].kondisi << "\n" <<endl;
    
    do {
        cout << "Pilih Data Yang Ingin Diubah\n1. Nama Mainan\n2. Jenis Mainan\n3. Tahun Produksi\n4. Kondisi\nPilih(1-4): ";
        getline(cin, ket_mainan);
        if (ket_mainan=="1") {
            cout << "Masukkan Nama Baru Mainan: ";
            getline(cin, mainan[indeks_mainan_int - 1].nama);
        } else if (ket_mainan=="2") {
            cout << "Masukkan Jenis Baru Mainan\n";
            mainan[indeks_mainan_int - 1].jenis = jenis_mainan();
        } else if (ket_mainan=="3") {
            cout << "Masukkan Tahun Terbaru Produksi: ";
            getline(cin, mainan[indeks_mainan_int - 1].tahun_produksi);
        } else if (ket_mainan=="4") {
            cout << "Masukkan Kondisi Mainan\n";
            mainan[indeks_mainan_int - 1].kondisi = kondisi_mainan();
        } else {
            cout << "Tidak Valid" <<endl;
        }
    } while (ket_mainan != "1" and ket_mainan != "2" and ket_mainan != "3" and ket_mainan != "4");
    system("cls");
    cout << "Data Berhasil Diubah!\n";
    tampilkanKoleksiMainan();
    if (daya_tampung != 0) {
        kembali_loop();
    }
}

void hapusMainan(int indeks_mainan_int) {
    kembali = kembali_kosong();
    if (kembali) {
        return;
    }
    int temp = daya_tampung; //Variabel Sementara Untuk Menyimpan Nilai Variabel daya_tampung Sebelum Decrementa
    daya_tampung--;
    
    if (temp == indeks_mainan_int) {
    } else {
        for (int i = indeks_mainan_int;i < temp; i++) {
            mainanPtr[i - 1].nama = mainanPtr[i].nama;
            mainanPtr[i - 1].jenis = mainanPtr[i].jenis;
            mainanPtr[i - 1].tahun_produksi = mainanPtr[i].tahun_produksi;
            mainanPtr[i - 1].kondisi = mainanPtr[i].kondisi;
        }
    }
    system("cls");
    if (daya_tampung != 0) {
        cout << "Koleksi Mainan Terbaru!\n\n";
    }
    tampilkanKoleksiMainan();
    if (daya_tampung != 0) {
        kembali_loop();
    }
}

/*
Blok Kode Program Utama Crud
*/
int main() {
	int indeks_mainan_int;//Indeks Mainan Integer
    string pilihan; //Untuk Memilih Opsi Crud
    string indeks_mainan; //Untuk Data Indeks Mainan Yang Ingin Di Ubah
    do {
        system("cls");
        cout << "Sistem Manajemen Koleksi Mainan" <<endl;
        cout << "1. Tambah Mainan Baru\n2. Update Mainan\n3. Hapus Mainan\n4. Tampilkan Koleksi Mainan\n5. Keluar\nPilih(1-5): ";
        getline(cin, pilihan);
        if (pilihan=="1") {
            tambahMainan();
        } else if (pilihan=="2") {
            system("cls");
            tampilkanKoleksiMainan();
            if (daya_tampung!=0) {
                cout << "Pilih Update Mainan Ke: ";
        		getline(cin, indeks_mainan);
        		indeks_mainan_int = stoi(indeks_mainan);
        		updateMainan(indeks_mainan_int);
            }
        } else if (pilihan=="3") {
            system("cls");
            tampilkanKoleksiMainan();
            if (daya_tampung!=0) {
                cout << "Pilih Hapus Mainan Ke: ";
        		getline(cin, indeks_mainan);
        		indeks_mainan_int = stoi(indeks_mainan);
        		hapusMainan(indeks_mainan_int);
            }
        } else if (pilihan=="4") {
            system("cls");
            tampilkanKoleksiMainan();
            if (daya_tampung != 0) {
                kembali_loop();
            }
        } else if (pilihan == "5") {
            return 0;
        } else {
            cout << "Pilihan Tidak Valid!" <<endl;
        }
    } while (pilihan != "1" or pilihan != "2" or pilihan != "3" or pilihan != "4" or pilihan != "5");
}
