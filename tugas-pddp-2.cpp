#include <iostream>
using namespace std;
int main() 
{
    //DEKLARASI VARIABEL
    string username = "vektor"; //revisi
    string password = "124250082"; //revisi
    string pertanyaan1;
    string nama_barang[5];
    string keterangan;
    int stok_barang[5];

    // VARIABEL INPUT
    string inputusername;
    string inputpassword;

    //DEKLARASI PROGRAM LOGIN
    cout << "Halo! Selamat datang. " << endl;
    cout << "Silahkan login terlebih dahulu. " << endl;
    cout << "Username : ";
    getline(cin, inputusername);
    cout << "Password : ";
    getline(cin, inputpassword);
    if (inputusername == username && inputpassword == password) //if untuk perbandingan usn dan password
    {
        cout << "Login berhasil!" <<endl;
        cout << "== Selamat datang di Toko Barokah Pak Slamet ==" << endl;
        cout << "===============================================" << endl;
        while (true)
        {
        cout << "Apakah anda ingin input barang? (ya/tidak): "; getline(cin, pertanyaan1);
        if (pertanyaan1 == "ya" || pertanyaan1 == "Ya" || pertanyaan1 == "y" || pertanyaan1 == "Y")
            {
                for (int i = 0; i<5; i++) //For untuk loop input barang hingga 5 kali
                {
                    // Input nama dan stok barang
                    cout << "Masukkan nama barang ke-" << i+1 << ": ";
                    getline(cin, nama_barang[i]);
                    cout << "Masukkan stok barang ke-" << i+1 << ": ";
                    cin >> stok_barang[i];
                    cin.ignore();
                }
                //Output daftar barang dan stok
                cout << "--- Daftar Barang dan Stok ---" << endl;
                cout << "------------------------------------------------------------------------" << endl;
                cout << "Nama Barang\t\t\tStok\t\t\tKeterangan" << endl;
                cout << "------------------------------------------------------------------------" << endl;
                for (int i = 0; i<5; i++) //for untuk menampilkan daftar barang yang berulang hingga 5 kali
                {
                    //if ini untuk validasi ditampilkan atau tidak
                    if(stok_barang[i] >= 0){
                        //if ini untuk menentukan keterangan
                        if(stok_barang[i] == 0){
                            keterangan = "Stok Habis";
                        } else if (stok_barang[i] <= 50){
                            keterangan = "Stok Menipis";
                        }  else if (stok_barang[i] <= 100){
                            keterangan = "Stok Relatif Aman"; 
                        } else {
                            keterangan = "Stok Banyak";
                        }
                    //output tabel nama barang, stok, dan keterangan
                    cout << nama_barang[i] << "\t\t\t\t" << stok_barang[i] << "\t\t\t" << keterangan << endl;
                    }
                }
                cout << "------------------------------------------------------------------------" << endl;
                break;
            }
            
            else if (pertanyaan1 == "tidak" || pertanyaan1 == "Tidak" || pertanyaan1 == "t" || pertanyaan1 == "T") 
            {
                cout << "Terima kasih, program selesai." << endl;
                break;
            }
            else 
            {
                cout << "Opsi jawaban tidak tersedia. Silahkan isi sesuai ketentuan." << endl;
            }  
        }
    } 
    else
    {
        cout << "Login gagal!" << endl;
    }
    return 0;
}