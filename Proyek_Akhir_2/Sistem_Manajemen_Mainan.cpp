#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std; //POSTTEST 4
/////PR UBAH DATA MENJADI DATA SORTING
//Untuk Batas Maksimal Jumlah Mainan Yang Disimpan
#define max 50

/*
Blok Kode Untuk Menampung Variabel Global
*/
string filename = "mainan.txt"; // Untuk Mengimport File txt yang berisi List Mainan
string loop; //Untuk Kembali Menginput Informasi Mainan Atau Menu
int idDihapus; //Untuk Menyimpan Id Mainan Apabila Mainan Dihapus
bool idTerhapus = false; //Untuk Mengambil Informasi Apakah Ada Riwayat Id mainan terhapus
int daya_tampung = 0; //Untuk Mengetahui Jumlah Mainan Sudah Berapa
int indeks_mainan_angka;
string ket_mainan, indeks_mainan; //Untuk Memilih Opsi Jenis Dan Kondisi Mainan
bool kembali; //Untuk Kembali Ke Menu Crud Atau Saat Pada Kondisi Koleksi Mainan Masih Kosong
string pilihan; //Untuk Memilih Opsi Crud
string arraykategori[] = {"Boneka", "Action Figure", "Miniatur", "Mainan Edukasi", "Robot", "Puzzle"}; // Untuk Filter Mainan Berdasarkan Kategori
string arraykondisi[] = {"Baru", "Masih Bagus", "Baret Sedikit", "Baret Parah", "Rusak"}; // Untuk Filter Mainan Berdasarkan Kondisi
int panjangkategori = sizeof(arraykategori) / sizeof(arraykategori[0]);
int panjangkondisi = sizeof(arraykondisi) / sizeof(arraykondisi[0]);
string mainan_nama, mainan_jenis, mainan_kondisi;
int mainan_tahun_produksi;
const int NO_OF_CHARS = 256;

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
    int id; //id mainan
    string nama; //Nama Mainan
    string jenis; //Jenis Mainan
    int tahun_produksi; //Tahun Produksi Mainan
    string kondisi; //Kondisi Mainan Apakah Masih Layak Atau Tidak
};
//koleksi_mainan mainan[max];
//koleksi_mainan *mainanPtr = mainan; //Pointer pada array mainan

struct Node {
    koleksi_mainan mainan;
    Node *next;
};

/*
Blok kode untuk menampung Fungsi
*/
bool kembali_kosong() {
    if (daya_tampung == 0) {
        cout << "Koleksi Mainan Kosong!"<<endl;
        kembali_loop();
        return true;
    } else {
        return false;
    }
}

int membuatID() {
    if (idTerhapus) {
        idTerhapus = false;
        return idDihapus;
    } else {
        return daya_tampung+1;
    }
}

int Maks(int x, int y)
{
    return (x >= y) ? x : y;
}

string jenis_mainan() {
    string jenis;
    do {
        cout << "1. Boneka\n2. Action Figure\n3. Miniatur\n4. Mainan Edukasi\n5. Robot\n6. Puzzle\nPilih Kategori(1-6): ";
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
        cout << "1. Baru\n2. Masih Bagus\n3. Baret Sedikit\n4. Baret Parah\n5. Rusak\nPilih Kondisi (1-5): ";
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
Blok kode untuk menampung Prosedur Crud, Sorting, Dan Searching
*/

//void tambahMainanDariFile(Node *&HEAD, const string &filename) {
//    ifstream file(filename);
//    if (!file) {
//        cerr << "Tidak dapat membuka file: " << filename << endl;
//        return;
//    }
//    
//    string line;
//    int id_counter = 1;
//    
//    while (getline(file, line)) {
//        if (daya_tampung == 50) {
//            return;
//        }
//        if (line.find("Mainan#") != string::npos) {
//            Node* nodeBaru = new Node;

//            nodeBaru->mainan.id = id_counter;
//            id_counter++;

//            getline(file, line);
//            nodeBaru->mainan.nama = line.substr(line.find(":") + 2);

//            getline(file, line);
//            nodeBaru->mainan.jenis = line.substr(line.find(":") + 2);

//            getline(file, line);
//            nodeBaru->mainan.tahun_produksi = stoi(line.substr(line.find(":") + 2));

//            getline(file, line);
//            nodeBaru->mainan.kondisi = line.substr(line.find(":") + 2);

//            nodeBaru->next = nullptr;
//            if (HEAD == nullptr) {
//                HEAD = nodeBaru;
//            } else {
//                Node *temp = HEAD;
//                while (temp->next != nullptr) {
//                    temp = temp->next;
//                }
//                temp->next = nodeBaru;
//            }
//            daya_tampung++;
//        }
//    }

//    file.close();
//}

void swap(koleksi_mainan &a, koleksi_mainan &b) {
    koleksi_mainan temp = a;
    a = b;
    b = temp;
}

// Quick Sort Berdasarkan ID
Node* partitionIDAsc(Node* low, Node* high) {
    int pivot = high->mainan.id;
    Node* i = low->next;
    Node* j = low;
    while (j != high) {
        if (j->mainan.id < pivot) {
            swap(i->mainan, j->mainan);
            i = (i == nullptr) ? low : i->next;
        }
        j = j->next;
    }
    swap(i->mainan, high->mainan);
    return i;
}

void quickSortIDAsc(Node* low, Node* high) {
    if (low != high && high != nullptr && low != nullptr && low != high->next) {
        Node* p = partitionIDAsc(low, high);
        quickSortIDAsc(low, p->next);
        quickSortIDAsc(p->next, high);
    }
}

// Quick Sort Berdasarkan Tahun Produksi
Node* partitionYearAsc(Node* low, Node* high) {
    int pivot = high->mainan.tahun_produksi;
    Node* i = low->next;
    Node* j = low;
    while (j != high) {
        if (j->mainan.tahun_produksi < pivot) {
            swap(i->mainan, j->mainan);
            i = (i == nullptr) ? low : i->next;
        }
        j = j->next;
    }
    swap(i->mainan, high->mainan);
    return i;
}

void quickSortYearAsc(Node* low, Node* high) {
    if (low != high && high != nullptr && low != nullptr && low != high->next) {
        Node* p = partitionYearAsc(low, high);
        quickSortYearAsc(low, p->next);
        quickSortYearAsc(p->next, high);
    }
}

// Merge Sort Berdasarkan ID (Descending)
Node* mergeIDDesc(Node* a, Node* b) {
    Node* result = nullptr;
    if (!a) return b;
    if (!b) return a;
    if (a->mainan.id > b->mainan.id) {
        result = a;
        result->next = mergeIDDesc(a->next, b);
    } else {
        result = b;
        result->next = mergeIDDesc(a, b->next);
    }
    return result;
}

void splitList(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

void mergeSortIDDesc(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next) return;
    Node* a;
    Node* b;
    splitList(head, &a, &b);
    mergeSortIDDesc(&a);
    mergeSortIDDesc(&b);
    *headRef = mergeIDDesc(a, b);
}

// Merge Sort Berdasarkan Tahun Produksi (Descending)
Node* mergeYearDesc(Node* a, Node* b) {
    Node* result = nullptr;
    if (!a) return b;
    if (!b) return a;
    if (a->mainan.tahun_produksi > b->mainan.tahun_produksi) {
        result = a;
        result->next = mergeYearDesc(a->next, b);
    } else {
        result = b;
        result->next = mergeYearDesc(a, b->next);
    }
    return result;
}

void mergeSortYearDesc(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next) return;
    Node* a;
    Node* b;
    splitList(head, &a, &b);
    mergeSortYearDesc(&a);
    mergeSortYearDesc(&b);
    *headRef = mergeYearDesc(a, b);
}

void tampilkanKoleksiMainan(Node *HEAD) {
    //int indeks = 0;
    kembali = kembali_kosong();
    if (kembali) {
        return;
    }
    while (HEAD != nullptr) {
        //indeks++;
        cout << "Mainan(ID: " << HEAD->mainan.id << ")\n" << "Nama: " << HEAD->mainan.nama << "\n" << "Kategori Mainan: " << HEAD->mainan.jenis << "\n" << "Tahun Produksi: " << HEAD->mainan.tahun_produksi << "\n" << "Kondisi: " << HEAD->mainan.kondisi << "\n" <<endl;
        HEAD = HEAD->next;
    }
    cout <<endl;
}

void tambahMainan(Node *&HEAD) {
    cout << "Pilih Tambah Di Awal Atau Diakhir\n1. Awal\n2. Akhir\nPilih(1-2): ";
    getline(cin, pilihan);
    for (int i = daya_tampung; i < max; i++) {
        system("cls");
        
        Node* nodeBaru = new Node;
        cout << "Kapasitas Penyimpanan " << i << "/" << max <<endl;
        cout << "Masukkan Nama Mainan: ";
        getline(cin, mainan_nama);
        nodeBaru->mainan.nama = mainan_nama;
        cout << "Masukkan Kategori Mainan\n";
        mainan_jenis = jenis_mainan();
        nodeBaru->mainan.jenis = mainan_jenis;
        cout << "Masukkan Tahun Produksi: ";
        cin >> mainan_tahun_produksi;
        cin.ignore();
        nodeBaru->mainan.tahun_produksi = mainan_tahun_produksi;
        cout << "Masukkan Kondisi Mainan\n";
        mainan_kondisi = kondisi_mainan();
        nodeBaru->mainan.kondisi = mainan_kondisi;
        nodeBaru->mainan.id = membuatID();
        if (pilihan == "2") {
            nodeBaru->next = nullptr;
            if (HEAD == nullptr) {
                HEAD = nodeBaru;
            } else {
                Node *temp = HEAD;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = nodeBaru;
            }
        } else {
            nodeBaru->next = HEAD;
            HEAD = nodeBaru;
        }
        daya_tampung++;
        cout << "Kapasitas Koleksi Mainan Bertambah\n" <<endl;
        cout << "Tersisa " << max - (i+1) << " Ruang Penyimpanan" <<endl;
        if (daya_tampung==max) {
            cout << "Penyimpanan Penuh" <<endl;
            return;
        }
        cout << "Masukkan x jika ingin masih menambah mainan atau Masukkan tombol selain x untuk berhenti menambah: ";
        getline(cin, loop);
        if (loop=="x") {
            continue;
        } else {
            break;
        }
    }
}

void updateMainan(Node *&HEAD) {
    kembali = kembali_kosong();
    if (kembali) {
        return;
    }
    tampilkanKoleksiMainan(HEAD);
    cout << "Pilih Mainan Berdasarkan Nama: ";
    getline(cin, indeks_mainan);
    
    system("cls");
    
    Node *temp = HEAD;
    while (temp != nullptr) {
        if (temp->mainan.nama == indeks_mainan) {
            cout << "Nama: " << temp->mainan.nama << "\n" << "Kategori Mainan: " << temp->mainan.jenis << "\n" << "Tahun Produksi: " << temp->mainan.tahun_produksi << "\n" << "Kondisi: " << temp->mainan.kondisi << "\n" <<endl;
            do {
                cout << "Pilih Data Yang Ingin Diubah\n1. Nama Mainan\n2. Kategori Mainan\n3. Tahun Produksi\n4. Kondisi\nPilih(1-4): ";
                getline(cin, ket_mainan);
                if (ket_mainan=="1") {
                    cout << "Masukkan Nama Baru Mainan: ";
                    getline(cin, temp->mainan.nama);
                } else if (ket_mainan=="2") {
                    cout << "Masukkan Kategori Baru Mainan\n";
                    temp->mainan.jenis = jenis_mainan();
                } else if (ket_mainan=="3") {
                    cout << "Masukkan Tahun Terbaru Produksi: ";
                    cin >> temp->mainan.tahun_produksi;
                    cin.ignore();
                } else if (ket_mainan=="4") {
                    cout << "Masukkan Kondisi Mainan\n";
                    temp->mainan.kondisi = kondisi_mainan();
                } else {
                    cout << "Tidak Valid" <<endl;
                }
            } while (ket_mainan != "1" and ket_mainan != "2" and ket_mainan != "3" and ket_mainan != "4");
            break;
        }
        temp = temp->next;
    }
    system("cls");
    cout << "Data Berhasil Diubah!\n";
    tampilkanKoleksiMainan(HEAD);
    if (daya_tampung != 0) {
        kembali_loop();
    }
}

void hapusMainan(Node *&HEAD) {
    kembali = kembali_kosong();
    if (kembali) {
        return;
    }
    tampilkanKoleksiMainan(HEAD);
    int temp = daya_tampung; //Variabel Sementara Untuk Menyimpan Nilai Variabel daya_tampung Sebelum Decrementa
    daya_tampung--;
    idTerhapus = true;
    do {
        cout << "Pilihan Hapus\n1. Berdasarkan Nama Nama\n2. Hapus Yang Mainan Awal\n3. Hapus Mainan Paling Akhir\nPilih(1-3): ";
        getline(cin, pilihan);
    } while (pilihan != "1" and pilihan != "2" and pilihan != "3");
    
    if (pilihan == "1") {
        cout << "Pilih Hapus Mainan Berdasarkan Nama: ";
        getline(cin, indeks_mainan);
        Node *temp = HEAD;
        while (temp->next != nullptr) {
            if (temp->next->mainan.nama == indeks_mainan) {
                idDihapus = temp->next->mainan.id;
                Node *nodeHapus = temp->next; //Untuk Menandai Mainan Yang Ingin Dihapus
                temp->next = temp->next->next;
                delete nodeHapus;
                break;
            } else if (temp->mainan.nama == indeks_mainan) {
                idDihapus = temp->mainan.id;
                Node *nodeHapus = temp;
                HEAD = HEAD->next;
                delete nodeHapus;
                break;
            }
            temp = temp->next;
        }
    } else if (pilihan == "2") {
        Node *temp = HEAD;
        idDihapus = HEAD->mainan.id;
        HEAD = HEAD->next;
        delete temp;
    } else {
        if (HEAD->next == nullptr) {
            idDihapus = HEAD->mainan.id;
            delete HEAD;
            HEAD = nullptr;
        } else {
            Node *temp = HEAD;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            idDihapus = temp->next->mainan.id;
            delete temp->next;
            temp->next = nullptr;
        }
    }
    
    system("cls");
    if (daya_tampung != 0) {
        cout << "Koleksi Mainan Terbaru!\n\n";
    }
    tampilkanKoleksiMainan(HEAD);
    if (daya_tampung != 0) {
        kembali_loop();
    }
}

/*Buat Node Untuk Stack Dan Queue*/

Node* createNode() {
    Node* nodeBaru = new Node;
    cout << "Masukkan Nama Mainan: ";
    getline(cin, mainan_nama);
    nodeBaru->mainan.nama = mainan_nama;
    cout << "Masukkan Kategori Mainan\n";
    mainan_jenis = jenis_mainan();
    nodeBaru->mainan.jenis = mainan_jenis;
    cout << "Masukkan Tahun Produksi: ";
    cin >> mainan_tahun_produksi;
    cin.ignore();
    nodeBaru->mainan.tahun_produksi = mainan_tahun_produksi;
    cout << "Masukkan Kondisi Mainan\n";
    mainan_kondisi = kondisi_mainan();
    nodeBaru->mainan.kondisi = mainan_kondisi;
    nodeBaru->mainan.id = membuatID();
    nodeBaru->next = nullptr;
    return nodeBaru;
}

/*STACK*/

void displayStack(Node *HEAD) {
    if (!HEAD) {
        cout << "Stack Kosong"<<endl;
        return;
    }
    
    while (HEAD) {
        cout << "Mainan(ID: " << HEAD->mainan.id << ")\n" << "Nama: " << HEAD->mainan.nama << "\n" << "Kategori Mainan: " << HEAD->mainan.jenis << "\n" << "Tahun Produksi: " << HEAD->mainan.tahun_produksi << "\n" << "Kondisi: " << HEAD->mainan.kondisi << "\n" <<endl;
        HEAD = HEAD->next;
    }
}

void push(Node *&HEAD) {
    do {
        Node* nodeBaru = createNode();
        daya_tampung++;
        //if (HEAD == nullptr) {
//            HEAD = nodeBaru;
//        } else {
//            nodeBaru->next = HEAD;
//            HEAD = nodeBaru;
//        }
        nodeBaru->next = HEAD;
        HEAD = nodeBaru;
        cout << "Berhasil Ditambah!" <<endl;
        cout << "Tambah Lagi? Tekan (y) Untuk Lanjut: ";
        getline(cin, loop);
    } while (loop == "y");
}

void pop(Node *&HEAD) {

    if (HEAD == NULL) {
        cout << "Stack underflow\n";
        return;
    }
    do {
        daya_tampung--;
        idTerhapus = true;
        Node* temp = HEAD;
        idDihapus = HEAD->mainan.id;
        HEAD = (HEAD)->next;
        delete temp;
        if (HEAD == NULL) {
            cout << "Stack underflow\n";
            return;
        }
        cout << "Berhasil Dihapus!" <<endl;
        cout << "Hapus Lagi? Tekan (y) Untuk Lanjut: ";
        getline(cin, loop);
    } while (loop == "y");
}

/*Queue*/

void enqueue(Node** rear, Node *&HEAD) {
    do {
        Node* nodeBaru = createNode();
        daya_tampung++;
        if (! HEAD) {
            HEAD = nodeBaru;
        } else {
            Node *temp = HEAD;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nodeBaru;
        }
        *rear = nodeBaru;
        cout << "Berhasil Ditambah!" <<endl;
        cout << "Tambah Lagi? Tekan (y) Untuk Lanjut: ";
        getline(cin, loop);
    } while (loop == "y");
}

void dequeue(Node *&HEAD) {
    if (! HEAD) {
        cout << "Antrian Kosong!"<<endl;
        return;
    }
    do {
        daya_tampung--;
        idTerhapus = true;
        Node* temp = HEAD;
        idDihapus = HEAD->mainan.id;
        HEAD = HEAD->next;
        delete temp;
        cout << "Berhasil Dihapus!" <<endl;
        if (! HEAD) {
            cout << "Antrian Kosong!"<<endl;
            return;
        }
        cout << "Hapus Lagi? Tekan (y) Untuk Lanjut: ";
        getline(cin, loop);
    } while (loop == "y");
}

void displayQueue(Node *HEAD) {
    if (! HEAD) {
        cout << "Antrian Kosong!"<<endl;
        return;
    }
    while (HEAD) {
        cout << "Mainan(ID: " << HEAD->mainan.id << ")\n" << "Nama: " << HEAD->mainan.nama << "\n" << "Kategori Mainan: " << HEAD->mainan.jenis << "\n" << "Tahun Produksi: " << HEAD->mainan.tahun_produksi << "\n" << "Kondisi: " << HEAD->mainan.kondisi << "\n" <<endl;
        HEAD = HEAD->next;
    }
}

/*Search*/

void displayFilter(Node *HEAD) {
    if (! HEAD) {
        cout << "Data Kosong!"<<endl;
        return;
    }
    string kategoriTerpilih, kondisiTerpilih;
    do {
        cout << "Filter Berdasarkan Apa\n1. Kategori\n2. Kondisi\nPilih (1-2): ";
        getline(cin, ket_mainan);
        if (ket_mainan == "1") {
            for (int i = 0; i < panjangkategori; i++) {
                cout << i+1 << ". " << arraykategori[i] <<endl;
            }
            cout << "Tampilkan Mainan Berdasarkan Kategori Yang Mana (Pilih 1-6): ";
            cin >> indeks_mainan_angka;
            kategoriTerpilih = arraykategori[indeks_mainan_angka-1];
            
            while (HEAD) {
                if (HEAD->mainan.jenis == kategoriTerpilih) {
                    cout << "Mainan(ID: " << HEAD->mainan.id << ")\n" << "Nama: " << HEAD->mainan.nama << "\n" << "Kategori Mainan: " << HEAD->mainan.jenis << "\n" << "Tahun Produksi: " << HEAD->mainan.tahun_produksi << "\n" << "Kondisi: " << HEAD->mainan.kondisi << "\n" <<endl;
                    HEAD = HEAD->next;
                } else {
                    HEAD = HEAD->next;
                }
            }
        } else if (ket_mainan == "2") {
            for (int i = 0; i < panjangkondisi; i++) {
                cout << i+1 << ". " << arraykondisi[i] <<endl;
            }
            cout << "Tampilkan Mainan Berdasarkan Kondisi Yang Mana (Pilih 1-5): ";
            cin >> indeks_mainan_angka;
            kondisiTerpilih = arraykondisi[indeks_mainan_angka-1];
            
            while (HEAD) {
                if (HEAD->mainan.kondisi == kondisiTerpilih) {
                    cout << "Mainan(ID: " << HEAD->mainan.id << ")\n" << "Nama: " << HEAD->mainan.nama << "\n" << "Kategori Mainan: " << HEAD->mainan.jenis << "\n" << "Tahun Produksi: " << HEAD->mainan.tahun_produksi << "\n" << "Kondisi: " << HEAD->mainan.kondisi << "\n" <<endl;
                    HEAD = HEAD->next;
                } else {
                    HEAD = HEAD->next;
                }
            }
        } else {
            cout << "Tidak Valid" << endl;
        }
    } while (ket_mainan != "1" and ket_mainan != "2");
}

void badCharHeuristic(string str, int size, int badChar[NO_OF_CHARS])
{
    
    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        badChar[i] = -1;
    }

    
    for (int i = 0; i < size; i++)
    {
        badChar[(int)str[i]] = i;
    }
}

void search(Node *head, string key)
{
    int keyLength = key.size();

    Node *temp = head;

    while (temp != nullptr)
    {
        int dataLength = temp->mainan.nama.size();

        int badChar[NO_OF_CHARS];
        badCharHeuristic(key, keyLength, badChar);

        int s = 0;                            
        while (s <= (dataLength - keyLength)) 
        {
            int j = keyLength - 1;

            while (j >= 0 && key[j] == temp->mainan.nama[s + j])
            {
                j--;
            }

            if (j < 0)
            {
                cout << "Mainan(ID: " << temp->mainan.id << ")\n" << "Nama: " << temp->mainan.nama << "\n" << "Kategori Mainan: " << temp->mainan.jenis << "\n" << "Tahun Produksi: " << temp->mainan.tahun_produksi << "\n" << "Kondisi: " << temp->mainan.kondisi << "\n" <<endl;
                break;
            }
            else
            {
                s += Maks(1, j - badChar[temp->mainan.nama[s + j]]);
            }
        }
        temp = temp->next;
    }
}

Node* fibonacciSearch(Node* head, int id) {
    Node* temp = head;
    int fibM2 = 0;  // (m-2)'th Fibonacci No.
    int fibM1 = 1;  // (m-1)'th Fibonacci No.
    int fibM = fibM2 + fibM1; // m'th Fibonacci No.

    // Hitung Fibonacci number yang lebih besar atau sama dengan jumlah elemen
    while (fibM < daya_tampung) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM1 + fibM2;
    }

    // Offset untuk elemen yang ditemukan
    int offset = -1;

    // Loop sampai kita menemukan elemen
    while (fibM > 1) {
        // Indeks untuk elemen yang akan diperiksa
        int i = min(offset + fibM2, daya_tampung - 1);

        // Traverse ke indeks i
        Node* current = head;
        for (int j = 0; j < i && current != nullptr; j++) {
            current = current->next;
        }

        if (current != nullptr) {
            if (current->mainan.id > id) {
                fibM = fibM2;
                fibM1 = fibM1 - fibM2;
                fibM2 = fibM1 - fibM2;
            } else if (current->mainan.id < id) {
                fibM = fibM1;
                fibM1 = fibM2;
                fibM2 = fibM - fibM1;
                offset = i;
            } else {
                return current; // Ditemukan
            }
        } else {
            break; // Jika tidak ada elemen, keluar dari loop
        }
    }

    // Cek elemen terakhir
    if (fibM1 && temp != nullptr && temp->mainan.id == id) {
        return temp; // Ditemukan
    }

    return nullptr; // Tidak ditemukan
}

// Fungsi untuk mencari mainan berdasarkan ID menggunakan Jump Search
void jumpSearch(Node* head, int id) {
    Node* current = head;
    int jump = sqrt(daya_tampung); // Ukuran lompatan
    Node* prev = nullptr;

    while (current != nullptr) {
        // Melompat ke node berikutnya
        for (int i = 0; i < jump && current != nullptr; i++) {
            prev = current;
            current = current->next;
        }

        // Jika ID yang dicari lebih kecil dari ID di node saat ini, lakukan pencarian linier
        if (current == nullptr || current->mainan.id > id) {
            current = prev; // Kembali ke node sebelumnya
            while (current != nullptr && current->mainan.id < id) {
                current = current->next;
            }
            // Cek apakah ID ditemukan
            if (current != nullptr && current->mainan.id == id) {
                cout << "Mainan(ID: " << current->mainan.id << ")\n" 
                     << "Nama: " << current->mainan.nama << "\n" 
                     << "Kategori Mainan: " << current->mainan.jenis << "\n" 
                     << "Tahun Produksi: " << current->mainan.tahun_produksi << "\n" 
                     << "Kondisi: " << current->mainan.kondisi << "\n" << endl;
                return;
            }
            break; // Jika tidak ditemukan, keluar dari loop
        }
    }
    cout << "Mainan dengan ID " << id << " tidak ditemukan." << endl;
}

/*
Blok Kode Program Utama Crud
*/
int main() {
    Node *HEAD = nullptr; //Untuk HEAD Link list, TOP Stack dan Front Queue
    //Node* TOP = nullptr;
    Node *REAR = nullptr;
    string stu;
    //tambahMainanDariFile(HEAD, filename);
    do {
        system("cls");
        cout << "Sistem Manajemen Koleksi Mainan\n" <<endl;
        cout << "1. Tambah Mainan Baru\n2. Update Mainan\n3. Hapus Mainan\n4. Tampilkan Koleksi Mainan\n----------------------------------\n            Stack\n\n5. Tambah Mainan Baru (Push)\n6. Hapus Mainan (Pop)\n7. Tampilkan Mainan (Peek)\n----------------------------------\n            Queue\n\n8. Tambah Mainan (Enqueue)\n9. Hapus Mainan (Dequeue)\n10. Tampilkan Mainan (Queue)\n----------------------------------\n            Searching\n\n11. Filter Mainan\n12. Search Mainan Berdasarkan Nama (Booyer-Moore)\n13. Search Mainan Berdasarkan ID (Fibonacci)\n14. Search Mainan Berdasarkan ID (Jump)\n----------------------------------\n   Sorting Ascending (Quick Sort)\n\n15. Berdasarkan ID\n16. Berdasarkan Tahun Produksi\n----------------------------------\n   Sorting Descending (Merge Sort)\n\n17. Berdasarkan ID\n18. Berdasarkan Tahun Produksi\n----------------------------------\n19. Keluar\nPilih(1-19): ";
        getline(cin, pilihan);
        if (pilihan=="1") {
            system("cls");
            tambahMainan(HEAD);
        } else if (pilihan=="2") {
            system("cls");
            updateMainan(HEAD);
        } else if (pilihan=="3") {
            system("cls");
            hapusMainan(HEAD);
        } else if (pilihan=="4") {
            system("cls");
            tampilkanKoleksiMainan(HEAD);
            if (daya_tampung != 0) {
                kembali_loop();
            }
        } else if (pilihan=="5") {
            system("cls");
            push(HEAD);
        } else if (pilihan == "6") {
            system("cls");
            pop(HEAD);
        } else if (pilihan =="7") {
            system("cls");
            displayStack(HEAD);
            kembali_loop();
        } else if (pilihan == "8") {
            system("cls");
            enqueue(&REAR, HEAD);
        } else if (pilihan == "9") {
            system("cls");
            dequeue(HEAD);
        } else if (pilihan == "10") {
            system("cls");
            displayQueue(HEAD);
            kembali_loop();
        } else if (pilihan == "11") {
            system("cls");
            displayFilter(HEAD);
            kembali_loop();
        } else if (pilihan == "12") {
            system("cls");
            cout << "Masukkan Kata Kunci Mainan: ";
            getline(cin, ket_mainan); 
            search(HEAD, ket_mainan);
            kembali_loop();
        } else if (pilihan == "13") {
            system("cls");
            cout << "Masukkan ID Mainan yang ingin dicari: ";
            int id;
            cin >> id;
            cin.ignore();
            Node* result = fibonacciSearch(HEAD, id);
            if (result != nullptr) {
            cout << "Mainan(ID: " << result->mainan.id << "    )\n" 
                << "Nama: " << result->mainan.nama << "\n" 
                << "Kategori Mainan: " << result->mainan.jenis << "\n" 
                << "Tahun Produksi: " << result->mainan.tahun_produksi << "\n" 
                << "Kondisi: " << result->mainan.kondisi << "\n" << endl;
            } else {
                cout << "Mainan dengan ID " << id << " tidak ditemukan." << endl;
            }
            kembali_loop();
        } else if (pilihan == "14") {
            system("cls");
            int id;
            cout << "Masukkan ID Mainan: ";
            cin >> id;
            cin.ignore();
            jumpSearch(HEAD, id);
            kembali_loop();
        } else if (pilihan == "15") {
            system("cls");
            quickSortIDAsc(HEAD, REAR);
            cout << "Data berhasil diurutkan berdasarkan ID (Ascending)!" << endl;
            tampilkanKoleksiMainan(HEAD);
            kembali_loop();
        } else if (pilihan == "16") {
            system("cls");
            quickSortYearAsc(HEAD, REAR);
            cout << "Data berhasil diurutkan berdasarkan Tahun Produksi (Ascending)!" << endl;
            tampilkanKoleksiMainan(HEAD);
            kembali_loop();
        } else if (pilihan == "17") {
            system("cls");
            mergeSortIDDesc(&HEAD);
            cout << "Data berhasil diurutkan berdasarkan ID (Descending)!" << endl;
            tampilkanKoleksiMainan(HEAD);
            kembali_loop();
        } else if (pilihan == "18") {
            system("cls");
            mergeSortYearDesc(&HEAD);
            cout << "Data berhasil diurutkan berdasarkan Tahun Produksi (Descending)!" << endl;
            tampilkanKoleksiMainan(HEAD);
            kembali_loop();
        } else if (pilihan == "19") {
            return 0;
        } else {
            cout << "Pilihan Tidak Valid!" <<endl;
        }
    } while (pilihan != "18");
} //18.42
