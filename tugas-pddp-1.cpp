#include <iostream>
using namespace std;
int main () 
{
   //DEKLARASI VARIABEL
   string Nama;
   string Prodi;
   string NIM;
   char digitke3;

   //DESKRIPSI PROGRAM
   cout << "Masukkan Nama Mahasiswa : " ;
   getline(cin, Nama);
   cout << "Masukkan NIM Mahasiswa : " ;
   cin >> NIM;

    //DESKRIPSI OUTPUT
    cout << "Data Mahasiswa :" << endl;
    cout << "====================" << endl;
    cout << "Nama Mahasiswa : " << Nama << endl;
    cout << "NIM Mahasiswa : " << NIM << endl;

    digitke3 = NIM[2];

   //MEMBUAT KONDISI PRODI BERDASARKAN NIM
   switch (digitke3)
   {
   case '1' : cout << "Prodi = Teknik Informatika" ; break;
   case '2' : cout << "Prodi = Teknik Industri" ; break;
   case '3' : cout << "Prodi = Informatika" ; break;
   case '4' : cout << "Prodi = Sistem Informasi" ; break;
   default : cout << " Prodi Diluar Jangkauan" ; break;
   }

   

    return 0;
}