#include <iostream>
using namespace std;
int main()
{
	//variabel
	int pilihan;
	string yort;
	string menu[100] = {"Espresso", "Cappucino", "Creamy Latte", "Americano", "Brownie Cake"};
	int harga[100] = {25000, 30000, 35000, 28000, 25000};
	int jmlmenu = 5;
	int nomenu;
	int diskon;
	int totalpesanan;
	int totalharga;
	int totalhargadiskon;
	int jmlhuang;
	int kembalian;
	int jmltambahmenu;
	int menu_awal;
	string inputnama;
	
	do
	{
		//program menu awal
		cout << "=========================================================" << endl;
		cout << "\t\t\tProgram Cafe\t\t" << endl;
		cout << "=========================================================" << endl;
		cout << endl;
		cout << "1. Daftar Menu" << endl;
		cout << "2. Pembelian Menu" << endl;
		cout << "3. Tambahan Menu Baru" << endl;
		cout << "4. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		
		if (pilihan == 1)
		{
			cout << "+---------------+-----------------------+---------------+" << endl;
			cout << "|\tNo\t|\tNama Menu\t|      Harga\t|" << endl;
			cout << "+---------------+-----------------------+---------------+" << endl;
			for (int i=0; i<jmlmenu; i++)
			{
					cout << "|\t" << i+1 << "\t|\t" << menu[i] << "\t|    Rp" << harga[i] << "\t|" << endl;
			}
			cout << "+---------------+-----------------------+---------------+" << endl;
			cout << endl;
			cout << "Apakah anda ingin melanjutkan program ? (ya/tidak): ";
			cin >> yort;
			while (true)
			{
				if (yort == "ya" || yort == "Ya" || yort == "YA" || yort == "yA" || yort == "y" || yort == "Y")
				{
					cout << "Silahkan memesan pada menu utama" << endl;
					system ("pause");
					break;
				}
				else if (yort == "tidak" || yort == "Tidak" || yort == "TIDAK" || yort == "t" || yort == "T")
				{
					cout << "Terima kasih telah menggunakan program ini!" << endl;
					return 0;
				}
				else
				{
						cout << "Opsi pilihan tidak tersedia, silahkan coba lagi (ya/tidak) : ";
						cin >> yort;
				}
			}
			system("cls");
		}
		else if (pilihan == 2)
		{
			cin.ignore();
			cout << "INPUT PEMBELIAN" << endl;
			cout << "---------------------------------------------------------" << endl;
			cout << "Masukkan nama pembeli\t\t\t: "; getline(cin, inputnama);
			cout << "Masukkan nomor menu yang ingin dibeli\t: "; cin >> nomenu;
			cout << "Masukkan jumlah pesanan\t\t\t: "; cin >> totalpesanan;
			cout << "Apakah pembeli adalah member? (ya/tidak): "; cin >> yort;
			
			//total harga
			totalharga = harga[nomenu-1] * totalpesanan;
			//diskon
			diskon = totalharga * 20 / 100;
			//total harga setelah diskon
			totalhargadiskon = totalharga-diskon;
			
			while (true)
			{
				if (yort == "ya" || yort == "Ya" || yort == "YA" || yort == "yA" || yort == "y" || yort == "Y")
				{
					//inputbayar
					cout << "DATA PEMBELIAN" << endl;
					cout << "---------------------------------------------------------" << endl;
					cout << "Nama Pembeli\t\t:" << inputnama << endl;
					cout << "Menu yang Dipesan\t:" << menu[nomenu-1] << endl;
					cout << "Harga per Menu\t\t: Rp" << harga[nomenu-1] << endl;
					cout << "Total Pesanan\t\t: " << totalpesanan << endl;
					cout << "Total Harga\t\t: Rp" << totalharga << endl;
					cout << "Diskon (20%)\t\t: Rp" << diskon << endl;
					cout << "Total Bayar\t\t: Rp" << totalhargadiskon << endl;
					
					//pembayaran
					kembalian = totalharga - jmlhuang;
					cout << "INPUT PEMBAYARAN" << endl;
					cout << "---------------------------------------------------------" << endl;
					cout << "Masukkan jumlah uang yang dibayarkan\t\t: Rp"; cin >> jmlhuang;
					kembalian = jmlhuang - totalhargadiskon;
					cout << "Kembali\t\t\t\t\t\t: Rp" << kembalian << endl;
					break;
				}
				else if (yort == "tidak" || yort == "Tidak" || yort == "TIDAK" || yort == "t" || yort == "T")
				{
					//inputbayar
					cout << "DATA PEMBELIAN" << endl;
					cout << "---------------------------------------------------------" << endl;
					cout << "Nama Pembeli\t\t:" << inputnama << endl;
					cout << "Menu yang Dipesan\t:" << menu[nomenu-1] << endl;
					cout << "Harga per Menu\t\t: Rp" << harga[nomenu-1] << endl;
					cout << "Total Pesanan\t\t: " << totalpesanan << endl;
					cout << "Total Harga\t\t: Rp" << totalharga << endl;
					cout << "Total Bayar\t\t: Rp" << totalharga << endl;
					
					//pembayaran
					cout << "INPUT PEMBAYARAN" << endl;
					cout << "---------------------------------------------------------" << endl;
					cout << "Masukkan jumlah uang yang dibayarkan\t\t: Rp"; cin >> jmlhuang;
					kembalian = jmlhuang - totalharga;
					cout << "Kembali\t\t\t\t\t\t: Rp" << kembalian << endl;
					break;
				}
				else 
				{
					cout << "Opsi tidak tersedia. Silahkan input kembali" << endl;
					cout << "Apakah pembeli adalah member? (ya/tidak): "; cin >> yort;
				}
			}
			cout << "Terima kasih sudah membeli produk kami!" << endl;
			cout << "Apakah kamu ingin kembali ke menu awal? (ya/tidak) : ";
			cin >> yort;
			if (yort == "ya" || yort == "Ya" || yort == "YA" || yort == "yA" || yort == "y" || yort == "Y")
			{
				system("cls");
			}
			else if (yort == "tidak" || yort == "Tidak" || yort == "TIDAK" || yort == "t" || yort == "T")
			{
				cout << "Terima kasih telah menggunakan program ini!";
				return 0;
			}
			else 
			{
				cout << "Opsi tidak tersedia. Silahkan input kembali" << endl;
				cout << "Terima kasih sudah membeli produk kami! Apakah kamu ingin kembali ke menu awal? (ya/tidak) : ";
				cin >> yort;
			}
		}
		else if (pilihan == 3)
		{
			cout << "TAMBAH MENU BARU" << endl;
			cout << "---------------------------------------------------------" << endl;
			cout << "Ingin tambah berapa menu?\t\t: ";
			cin >> jmltambahmenu;
			cin.ignore();
			menu_awal=jmlmenu;
			for (int i=0; i<jmltambahmenu; i++)
			{
				cout << "Data menu ke-"<< menu_awal + 1 + i << ": "<< endl;
				cout << "========================================================" << endl;
				cout << "Masukkan nama menu\t\t: ";
				getline(cin, menu[jmlmenu]);
				cout << "Masukkan harga menu\t\t: Rp";
				cin >> harga[jmlmenu];
				cin.ignore();
				jmlmenu++;
				cout << "========================================================" << endl;
			}
			cout << "Menu berhasil ditambahkan!" << endl;
			cout << "Apakah kamu ingin kembali ke menu awal? (ya/tidak) : ";
			cin >> yort;
			if (yort == "ya" || yort == "Ya" || yort == "YA" || yort == "yA" || yort == "y" || yort == "Y")
			{
				system("cls");
			}
			else if (yort == "tidak" || yort == "Tidak" || yort == "TIDAK" || yort == "t" || yort == "T")
			{
				cout << "Terima kasih telah menggunakan program ini!";
				return 0;
			}
			else 
			{
				cout << "Opsi tidak tersedia. Silahkan input kembali" << endl;
				cout << "Terima kasih sudah membeli produk kami! Apakah kamu ingin kembali ke menu awal? (ya/tidak) : ";
				cin >> yort;
			}
			
		}
	} 
	while (pilihan != 4);
	cout << "Terima kasih telah menggunakan program ini!" ;
	return 0;
}