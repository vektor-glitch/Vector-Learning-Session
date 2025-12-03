#include <iostream>
#include <iomanip>
using namespace std;

//variabel global ygy
int pilihan;
string yort;
float mean (float d, float t, float k, float i, float h)
{
    float meannilai = (d*0.2)+(t*0.15)+(k*0.2)+(i*0.3)+(h*0.15);
    return meannilai;
}

//void fuction ygy
void tampilanmenu(string judulmenu)
{
    cout << "=== PROGRAM " << judulmenu << " ===" << endl;
}
void menu_utama_ygy()
{
    cout << "1.  Input Nilai Pegawai" << endl;
    cout << "2.  Tampilkan Hasil Penilaian" << endl;
    cout << "3.  Keluar" << endl;
    cout << "Pilih menu (1-3): ";
    cin >> pilihan;
}
void menu1_ygy()
{
    tampilanmenu("INPUT NILAI PEGAWAI");
}
void menu2_ygy()
{
    tampilanmenu("Hasil Penilaian");
}
bool yesornot ()
{
    cout << "Apakah anda ingin kembali ke menu utama? ";
    cin >> yort;
    
    if (yort == "ya" || yort == "Ya" || yort == "YA" || yort == "yA" || yort == "y" || yort == "Y")
    {
        system("cls");
        return true;
    }
    else if (yort == "tidak" || yort == "Tidak" || yort == "TIDAK" || yort == "t" || yort == "T")
	{
		cout << "Terima kasih telah menggunakan program ini!" << endl; 
		return false;
	}
    else 
	{
		cout << "Opsi tidak tersedia. Silahkan input kembali" << endl;
		return yesornot();
	}
}

//main fuction ygy
int main ()
{
    //variabel local main ygy
    string nama_pegawai[100];
    float meanpegawai[100];
    string kategori[100];
    string teladan[100];
    int jumlahpegawaiawal = 0;
    int jumlahpegawaiinput;
    int disiplin;
    int tanggungjawab;
    int kerjasama;
    int inisiatif;
    int hasilkerja;

    //programnya ygy
    do 
    {
        tampilanmenu ("PENILAIAN KINERJA PEGAWAI");
        menu_utama_ygy();
        if (pilihan == 1)
        {
            system("cls");
            menu1_ygy();
            cout << "Masukkan jumlah pegawai yang ingin ditambahkan: ";
            cin >> jumlahpegawaiinput;
            cout << endl;
            
            cout << "Perhatian, nilai yang diinput hanya bisa 0-100." << endl;
            cout << "Jika lebih atau kurang dari itu, maka sistem akan menolak dan pengguna akan diharuskan untuk menginput kembali sesuai aturan." << endl;
            cout << endl;
            system ("pause");
            cout << endl;

            for (int i=0; i<jumlahpegawaiinput; i++)
            {
                
                cin.ignore();
                cout << "Pegawai ke-" << i+1 << endl;
                cout << "--------------------------------------------------------------" << endl;
                cout << "Nama Pegawai: ";
                getline(cin, nama_pegawai[jumlahpegawaiawal+i]);
                cout << "Nilai disiplin: ";
                cin >> disiplin;
                while (true)
                {
                    if (disiplin > 100 || disiplin < 0)
                    {
                        cout << "Nilai tidak valid! Silahkan input ulang" << endl;
                        cout << "Nilai disiplin: ";
                        cin >> disiplin;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Nilai Tanggung Jawab: ";
                cin >> tanggungjawab;
                while (true)
                {
                    if (tanggungjawab > 100 || tanggungjawab < 0)
                    {
                        cout << "Nilai tidak valid! Silahkan input ulang" << endl;
                        cout << "Nilai Tanggung Jawab: ";
                        cin >> tanggungjawab;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Nilai kerjasama: ";
                cin >> kerjasama;
                while (true)
                {
                    if (kerjasama > 100 || kerjasama < 0)
                    {
                        cout << "Nilai tidak valid! Silahkan input ulang" << endl;
                        cout << "Nilai Kerjasama: ";
                        cin >> kerjasama;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Nilai Inisiatif: ";
                cin >> inisiatif;
                while (true)
                {
                    if (inisiatif > 100 || inisiatif < 0)
                    {
                        cout << "Nilai tidak valid! Silahkan input ulang" << endl;
                        cout << "Nilai Tanggung Jawab: ";
                        cin >> tanggungjawab;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Nilai Hasil Kerja: ";
                cin >> hasilkerja;
                while (true)
                {
                    if (hasilkerja > 100 || hasilkerja < 0)
                    {
                        cout << "Nilai tidak valid! Silahkan input ulang" << endl;
                        cout << "Nilai Hasil Kerja: ";
                        cin >> hasilkerja;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << endl;

                int hasiljumlahpegawai = jumlahpegawaiawal+i;
                meanpegawai[hasiljumlahpegawai] = mean(disiplin, tanggungjawab, kerjasama, inisiatif, hasilkerja); //berbalik nilai dan simpen ke array ygy 
                float hasil = meanpegawai[hasiljumlahpegawai];

                //kategori
                if (hasil >= 90)
                {
                    kategori[hasiljumlahpegawai] = "Sangat Baik";
                }
                else if (hasil >= 80)
                {
                    kategori[hasiljumlahpegawai] = "Baik";
                }
                else if (hasil >= 70)
                {
                    kategori[hasiljumlahpegawai] = "Cukup";
                }
                else
                {
                    kategori[hasiljumlahpegawai] = "Kurang";
                }

                //teladan dan tidak teladan
                if (hasil >= 90)
                {
                    teladan[hasiljumlahpegawai] = "Ya";
                }
                else 
                {
                    teladan[hasiljumlahpegawai] = "Tidak";
                }
            }

            jumlahpegawaiawal += jumlahpegawaiinput; //buat nambah jumlah pegawai yang udah diinput array sebelumnya ygy

            cout << "Data penilaian berhasil ditambahkan!" << endl;
            if (!yesornot()) 
            {
                return 0;
            }
        }
        else if (pilihan == 2)
        {
            system ("cls");
            menu2_ygy();
            cout << endl;
            if (jumlahpegawaiawal == 0)
            {
                cout << "Belum ada data Pegawai yang diinput." << endl;
            }
            else
            {
                cout << "+====+===================================+===========+=============+===============+" << endl;
                cout << "| No | Nama Pegawai\t\t         | Rata-Rata | Kategori\t   | Teladan\t   |" << endl;
                cout << "+----+-----------------------------------+-----------+-------------+---------------+" << endl;
                for (int j=0; j<jumlahpegawaiawal; j++)
                {
                    cout << "| " << j+1 << "  | " 
                         << setw(25) << left << nama_pegawai[j] << "\t | "
                         << setw(5) << left << meanpegawai[j] << "     | "
                         << setw(11) << left << kategori[j] << " | "
                         << setw(5) << left << teladan[j] << "\t   |" << endl;
                }
                cout << "+====+===================================+===========+=============+===============+" << endl;
            }

            if(!yesornot())
            {
                return 0;
            }
        }
        else if (pilihan == 3)
        {
            cout << "Program selesai, terima kasih telah menggunakan program ini. Selamat Beristirahat!" << endl;
        }
        else 
        {
            system ("cls");
            cout << "Pilihan tidak valid! Input pilihan sesuai aturan." << endl;
            system ("pause");
        }
    }
    while (pilihan != 3);
    return 0;
}