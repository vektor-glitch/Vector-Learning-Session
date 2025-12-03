#include <iostream>
#include <iomanip>
using namespace std;

//variabel global geyzztt
int jumlahpelanggan = 0;
int pilihan;
int jumlahbuku = 5;

struct kategori
{
    int ID;
    string nama_kategori;
};

struct databuku
{
    string judul;
    int stok;
    int harga;
    kategori ktrg;
};

struct datapelanggan
{
    string nama[100];
    string grade[100];
};

databuku dtbk [100] = {
    {"Marine Ford", 10, 50000, {2, "Non-Fiksi"}},
    {"Forever Young" ,1890, 45000, {2, "Non-Fiksi"}},
    {"Spring Day", 7, 91000, {3, "Pendidikan"}},
    {"One Piece", 100, 50000, {2, "Non-Fiksi"}},
    {"Dynamite", 9, 90000, {3, "Pendidikan"}}
};
datapelanggan dtplg[100];

int hitungtotalhargakategori (string a, int i)
{
    if (i >= jumlahbuku)
    {
        cout << "=";
        return 0;
    }
    if (dtbk[i].ktrg.nama_kategori == a)
    {
        cout << dtbk[i].harga << "+";
        return dtbk[i].harga + hitungtotalhargakategori(a, i+1);
    }
    else
    {
        return hitungtotalhargakategori(a, i+1);
    }
}
string kategoribuku (int IDktrg)
{
    if (IDktrg == 1)
    {
        return "Fiksi";
    }
    else if (IDktrg == 2)
    {
        return "Non-Fiksi";
    }
    else if (IDktrg == 3)
    {
        return "Pendidikan";
    }
    else if (IDktrg == 4)
    {
        return "Teknologi";
    }
    else
    {
        return "Kategori Tidak Diketakui";
    }
}
string funcgradepelanggan (int pembelian)
{
    if (pembelian > 5)
    {
        return "A";
    }
    else if (pembelian >= 3 && pembelian <= 5)
    {
        return "B";
    }
    else
    {
        return "C";
    }
}
float diskon (float totalhargaasli, string grade)
{
    float hargadiskon;
    if (grade == "A")
    {
        return hargadiskon = totalhargaasli * 0.15;
    }
    else if (grade == "B")
    {
        return hargadiskon = totalhargaasli * 0.1;
    }
    else
    {
        if (totalhargaasli > 90000)
        {
            return hargadiskon = totalhargaasli * 0.05;
        }
        else
        {
            return 0;
        }
    }
}

//void function geyzzt
void tampilanmenu(string judul)
{
    cout << "=====================================================================" << endl;
    cout << "\t\t\t" <<judul<< "\t\t" << endl;
    cout << "=====================================================================" << endl;
    cout << "1. Daftar Buku" << endl;
    cout << "2. Pembelian Buku" << endl;
    cout << "3. Tambah Data Buku" << endl;
    cout << "4. Total Harga Buku Berdasarkan Kategori" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan : ";
    cin >> pilihan;
}

bool yesorno(string yort)
{
    cout << "Ulangi Program? (Y/T) : ";
    cin >> yort;

    if (yort == "ya" || yort == "Ya" || yort == "YA" || yort == "yA" || yort == "y" || yort == "Y")
    {
        system("cls");
        return true;
    }
    else if (yort == "tidak" || yort == "Tidak" || yort == "TIDAK" || yort == "t" || yort == "T")
	{
		cout << "Program Selesai!" << endl;
        cout << "Terima kasih telah menggunakan program ini!" << endl; 
		return false;
	}
    else 
	{
		cout << "Opsi tidak tersedia. Silahkan input kembali" << endl;
		return yesorno("");
	}
}
//main function geyzzt
main ()
{
    //variable lokal geyzzt
    string grade;
    float totalharga;
    float hargadiskon;
    string judulbuku;
    int kembalian;
    float nilaidiskon;
    int jumlahbukuawal;
    int totalhargakategori;

    //variable lokal input geyzzt
    int jumlahbelibuku;
    int jumlahtambahbuku;
    int nobuku;
    int inputpembayaran;
    string kategoricari;

    //programnya menu utama geyzzt
    do
    {
        tampilanmenu("Program Toko Buku");
        cout << endl;

        //tampilan menu 1 geyzzt
        if (pilihan == 1)
        {
            system("cls");
            cout << "DAFTAR BUKU" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            cout << "No\t| Judul Buku\t\t\t| Stok\t\t\t| Harga\t\t| Kategori" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            for (int i = 0; i < jumlahbuku; i++)
            {
                cout << setw(2) << left << i+1 << "\t| "
                    << setw(15) << left << dtbk[i].judul << "\t\t| "
                    << setw(4) << left << dtbk[i].stok << "\t\t\t| Rp"
                    << setw(5) << left << dtbk[i].harga << "\t| "
                    << setw(10) << left << dtbk[i].ktrg.nama_kategori << endl;
            }
            if (!yesorno(""))
            {
                return 0;
            }
        }

        //tampilan menu 2 geyzzt
        else if (pilihan == 2)
        {
            system("cls");
            cin.ignore();
            cout << "INPUT PEMBELIAN" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Masukkan nama pembeli\t\t\t: ";
            getline(cin, dtplg[jumlahpelanggan].nama[jumlahpelanggan]);
            while (true)
            {
                cout << "Masukkan nomor buku yang ingin dibeli\t: ";
                cin >> nobuku;
                //validasi nomor buku geyzzt
                if (nobuku >= 1 && nobuku <= jumlahbuku)
                {
                    break;
                }
                else
                {
                    cout << "Input tidak valid!" << endl;
                }
            }
            while (true)
            {
                cout << "Masukkan jumlah buku yang ingin dibeli\t: ";
                cin >> jumlahbelibuku;
                //validasi jumlah beli
                if (jumlahbelibuku >= 1)
                {
                    break;
                }
                else
                {
                    cout << "Input tidak valid!" << endl;
                }
            }
            cout << endl;

            //perhitungan dan simpan grade array
            grade = funcgradepelanggan(jumlahbelibuku);
            dtplg[jumlahpelanggan].grade[jumlahpelanggan] = grade;
            totalharga = dtbk[nobuku-1].harga*jumlahbelibuku;
            nilaidiskon = diskon(totalharga, grade);
            hargadiskon = totalharga - nilaidiskon;
            judulbuku = dtbk[nobuku-1].judul;

            cout << "DATA PEMBELIAN" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Nama Pembeli\t\t: " << dtplg[jumlahpelanggan].nama[jumlahpelanggan] << endl;
            cout << "Grade Pembeli\t\t: " << grade << endl;
            cout << "Judul Buku\t\t: " << judulbuku << endl;
            cout << "Harga Buku\t\t: " << dtbk[nobuku-1].harga << endl;
            cout << "Jumlah Pembelian\t: " << jumlahbelibuku << endl;
            cout << "Total Harga\t\t: " << totalharga << endl;
            cout << "Total Bayar\t\t: " << hargadiskon << endl;
            cout << endl;

            cout << "INPUT PEMBAYARAN" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Masukkan jumlah uang yang dibayarkan\t: Rp";
            cin >> inputpembayaran;
            //validasi inputpembayaran dan rumus kembalian geyzzt
            while (true)
            {   
                if (inputpembayaran >= hargadiskon)
                {
                    kembalian = inputpembayaran - hargadiskon;
                    break;
                }
                else
                {
                    cout << "Uang tidak cukup! Silahkan input kembali." << endl;
                }
            }
            cout << "Kembali\t\t\t\t\t: Rp" << kembalian << endl;

            if (!yesorno(""))
            {
                return 0;
            }
        }

        //tampilan menu 3 geyzzt
        else if (pilihan == 3)
        {
            system("cls");
            cout << "TAMBAH DATA BUKU" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Ingin tambah berapa buku?\t: ";
            cin >> jumlahtambahbuku;
            
            jumlahbukuawal = jumlahbuku;
            for (int i = 0; i < jumlahtambahbuku; i++)
            {
                cin.ignore();
                cout << "DATA BUKU KE-" << jumlahbukuawal+i+1 << endl;
                cout << "=================================" << endl;
                cout << "Masukkan Judul buku\t\t: ";
                getline(cin, dtbk[jumlahbuku].judul);
                cout << "Masukkan Stok Buku\t\t: ";
                cin >> dtbk[jumlahbuku].stok;
                cout << "Masukkan Harga Buku\t\t: Rp";
                cin >> dtbk[jumlahbuku].harga;      
                cout << "Masukkan ID Kategori Buku\t: ";
                cin >> dtbk[jumlahbuku].ktrg.ID;
                dtbk[jumlahbuku].ktrg.nama_kategori = kategoribuku(dtbk[jumlahbuku].ktrg.ID);
                jumlahbuku++;
            }
            cout << "Buku berhasil ditambahkan!" << endl;
            if (!yesorno(""))
            {
                return 0;
            }
        }

        //tampilan menu 4 geyzzt
        else if (pilihan == 4)
        {
            cin.ignore();
            system ("cls");
            cout << "[FIksi, Non-Fiksi, Pendidikan, Teknologi]" << endl;
            cout << "Masukkan nama kategori yang ingin dihitung : ";
            getline(cin, kategoricari);

            totalhargakategori = hitungtotalhargakategori(kategoricari, 0);

            cout << totalhargakategori << endl;

            if (!yesorno(""))
            {
                return 0;
            }
        }
    }
    while (pilihan != 5);
    cout << "Program Selesai!" << endl;
    cout << "Terima kasih telah menggunakan program ini!" << endl; 
    return 0;
}