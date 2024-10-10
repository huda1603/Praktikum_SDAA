#include <iostream>
#include <string>
using namespace std; //POSTTEST 4

//Untuk Batas Maksimal Jumlah Mainan Yang Disimpan
#define max 50

/*
Blok Kode Untuk Menampung Variabel Global
*/
string loop; //Untuk Kembali Menginput Informasi Mainan Atau Menu
int daya_tampung = 0; //Untuk Mengetahui Jumlah Mainan Sudah Berapa
string ket_mainan, indeks_mainan; //Untuk Memilih Opsi Jenis Dan Kondisi Mainan
bool kembali; //Untuk Kembali Ke Menu Crud Atau Saat Pada Kondisi Koleksi Mainan Masih Kosong
string pilihan; //Untuk Memilih Opsi Crud
string mainan_nama, mainan_jenis, mainan_tahun_produksi, mainan_kondisi;

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
void tampilkanKoleksiMainan(Node *HEAD) {
    int indeks = 0;
    kembali = kembali_kosong();
    if (kembali) {
        return;
    }
    while (HEAD != nullptr) {
        indeks++;
        cout << "Mainan(" << indeks << ")\n" << "Nama: " << HEAD->mainan.nama << "\n" << "Jenis Mainan: " << HEAD->mainan.jenis << "\n" << "Tahun Produksi: " << HEAD->mainan.tahun_produksi << "\n" << "Kondisi: " << HEAD->mainan.kondisi << "\n" <<endl;
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
        cout << "Masukkan Jenis Mainan\n";
        mainan_jenis = jenis_mainan();
        nodeBaru->mainan.jenis = mainan_jenis;
        cout << "Masukkan Tahun Produksi: ";
        getline(cin, mainan_tahun_produksi);
        nodeBaru->mainan.tahun_produksi = mainan_tahun_produksi;
        cout << "Masukkan Kondisi Mainan\n";
        mainan_kondisi = kondisi_mainan();
        nodeBaru->mainan.kondisi = mainan_kondisi;
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
            cout << "Nama: " << temp->mainan.nama << "\n" << "Jenis Mainan: " << temp->mainan.jenis << "\n" << "Tahun Produksi: " << temp->mainan.tahun_produksi << "\n" << "Kondisi: " << temp->mainan.kondisi << "\n" <<endl;
            do {
                cout << "Pilih Data Yang Ingin Diubah\n1. Nama Mainan\n2. Jenis Mainan\n3. Tahun Produksi\n4. Kondisi\nPilih(1-4): ";
                getline(cin, ket_mainan);
                if (ket_mainan=="1") {
                    cout << "Masukkan Nama Baru Mainan: ";
                    getline(cin, temp->mainan.nama);
                } else if (ket_mainan=="2") {
                    cout << "Masukkan Jenis Baru Mainan\n";
                    temp->mainan.jenis = jenis_mainan();
                } else if (ket_mainan=="3") {
                    cout << "Masukkan Tahun Terbaru Produksi: ";
                    getline(cin, temp->mainan.tahun_produksi);
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
                Node *nodeHapus = temp->next; //Untuk Menandai Mainan Yang Ingin Dihapus
                temp->next = temp->next->next;
                delete nodeHapus;
                break;
            } else if (temp->mainan.nama == indeks_mainan) {
                Node *nodeHapus = temp;
                HEAD = HEAD->next;
                delete nodeHapus;
                break;
            }
            temp = temp->next;
        }
    } else if (pilihan == "2") {
        Node *temp = HEAD;
        HEAD = HEAD->next;
        delete temp;
    } else {
        if (HEAD->next == nullptr) {
            delete HEAD;
            HEAD = nullptr;
        } else {
            Node *temp = HEAD;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
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
    cout << "Masukkan Jenis Mainan\n";
    mainan_jenis = jenis_mainan();
    nodeBaru->mainan.jenis = mainan_jenis;
    cout << "Masukkan Tahun Produksi: ";
    getline(cin, mainan_tahun_produksi);
    nodeBaru->mainan.tahun_produksi = mainan_tahun_produksi;
    cout << "Masukkan Kondisi Mainan\n";
    mainan_kondisi = kondisi_mainan();
    nodeBaru->mainan.kondisi = mainan_kondisi;
    nodeBaru->next = NULL;
    return nodeBaru;
}

/*STACK*/

void displayStack(Node* top) {
    if (!top) {
        cout << "Stack Kosong"<<endl;
        return;
    }
    
    while (top) {
        cout << "Nama: " << top->mainan.nama << "\nJenis Mainan: " << top->mainan.jenis << "\nTahun Produksi: " << top->mainan.tahun_produksi << "\nKondisi: " << top->mainan.kondisi << "\n" <<endl;
        top = top->next;
    }
}

void push(Node** top) {
    do {
        Node* nodeBaru = createNode();
        nodeBaru->next = *top;
        *top = nodeBaru;
        cout << "Berhasil Ditambah!" <<endl;
        cout << "Tambah Lagi? Tekan (y) Untuk Lanjut: ";
        getline(cin, loop);
    } while (loop == "y");
}

void pop(Node** top) {

    if (*top == NULL) {
        cout << "Stack underflow\n";
        return;
    }
    do {
        Node* temp = *top;
        *top = (*top)->next;
        delete temp;
        if (*top == NULL) {
            cout << "Stack underflow\n";
            return;
        }
        cout << "Berhasil Dihapus!" <<endl;
        cout << "Hapus Lagi? Tekan (y) Untuk Lanjut: ";
        getline(cin, loop);
    } while (loop == "y");
}

/*Queue*/

void enqueue(Node** front, Node** rear) {
    do {
        Node* nodeBaru = createNode();
        if (! *front) {
            *front = nodeBaru;
        } else {
            (*rear)->next = nodeBaru;
        }
        *rear = nodeBaru;
        cout << "Berhasil Ditambah!" <<endl;
        cout << "Tambah Lagi? Tekan (y) Untuk Lanjut: ";
        getline(cin, loop);
    } while (loop == "y");
}

void dequeue(Node** front) {
    if (! *front) {
        cout << "Antrian Kosong!"<<endl;
        return;
    }
    do {
        Node* temp = *front;
        *front = (*front)->next;
        delete temp;
        cout << "Berhasil Dihapus!" <<endl;
        if (! *front) {
            cout << "Antrian Kosong!"<<endl;
            return;
        }
        cout << "Hapus Lagi? Tekan (y) Untuk Lanjut: ";
        getline(cin, loop);
    } while (loop == "y");
}

void displayQueue(Node* front) {
    if (! front) {
        cout << "Antrian Kosong!"<<endl;
        return;
    }
    while (front) {
        cout << "Nama: " << front->mainan.nama << "\nJenis Mainan: " << front->mainan.jenis << "\nTahun Produksi: " << front->mainan.tahun_produksi << "\nKondisi: " << front->mainan.kondisi << "\n"<<endl;
        front = front->next;
    }
}

/*
Blok Kode Program Utama Crud
*/
int main() {
    Node *HEAD = nullptr;
    Node* TOP = NULL;
    Node *FRONT = NULL, *REAR = NULL;
    string stu;
    do {
        system("cls");
        cout << "Sistem Manajemen Koleksi Mainan\n" <<endl;
        cout << "1. Tambah Mainan Baru\n2. Update Mainan\n3. Hapus Mainan\n4. Tampilkan Koleksi Mainan\n----------------------------------\n            Stack\n\n5. Tambah Mainan Baru (Push)\n6. Hapus Mainan (Pop)\n7. Tampilkan Mainan (Peek)\n----------------------------------\n            Queue\n\n8. Tambah Mainan (Enqueue)\n9. Hapus Mainan (Dequeue)\n10. Tampilkan Mainan (Queue)\n----------------------------------\n11. Keluar\nPilih(1-11): ";
        getline(cin, pilihan);
        if (pilihan=="1") {
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
            push(&TOP);
        } else if (pilihan == "6") {
            system("cls");
            pop(&TOP);
        } else if (pilihan =="7") {
            system("cls");
            displayStack(TOP);
            kembali_loop();
        } else if (pilihan == "8") {
            system("cls");
            enqueue(&FRONT, &REAR);
        } else if (pilihan == "9") {
            system("cls");
            dequeue(&FRONT);
        } else if (pilihan == "10") {
            system("cls");
            displayQueue(FRONT);
            kembali_loop();
        }else if (pilihan == "11") {
            return 0;
        } else {
            cout << "Pilihan Tidak Valid!" <<endl;
        }
    } while (pilihan != "11");
}