#include <iostream>
#include <vector>
#include <limits>
using namespace std;
struct datapendapatan{
    vector<long> pendapatan;//untuk mendeklarasikan array pendapatan
    vector<int> bulan;//untuk mendeklarasikan array bulan
    vector<int> tahun;//intuk medeklarasikan array tahun
};
datapendapatan data; //pendeklarian tipe data datapendapatan untuk variable data
void menu(){
    cout<<"\n============Menu==========\n";
    cout<<"1.Menamabahkan Pemasukan\n";
    cout<<"2.Menghapus Data Pemasukan\n";
    cout<<"3.Update Data pemasukan\n";
    cout<<"4.Lihat Data Pemasukan\n";
    cout<<"0.Shutdown\n";
    cout<<"==========================\n";
}
void lihatpendapatan(){  
    cout<<"-------------------------------\n";
    cout<<"--------List Pendapatan--------\n";
    cout<<"No.\tbulan\ttahun\tPendapatan\n";
    for (int i = 0; i < data.bulan.size(); i++) {
    // std::cout <<i+1<<". "<<*&data.bulan[i]<<" = Rp."<< *&data.pendapatan[i] << " \n";
    std::cout<<i+i<<"\t"<<*&data.bulan[i]<<"\t"<<*&data.tahun[i]<<"\t"<<data.pendapatan[i]<<endl;
    }
    cout<<"-------------------------------\n";
}


void insertionSort() {
    for (int i = 0; i < data.pendapatan.size(); i++) {
        int key = data.pendapatan[i];
        int key2 = data.bulan[i];
        int key3 = data.tahun[i];
        int j = i - 1;
        while (j >= 0 && data.pendapatan[j] > key) {
            data.pendapatan[j+1] = data.pendapatan[j];
            data.bulan[j+1] = data.bulan[j];
            data.tahun[j+1] = data.tahun[j];
            j--;
        }
        data.pendapatan[j+1] = key;
        data.bulan[j+1] = key2;
        data.tahun[j+1] = key2;
        // lihatpendapatan();
    }
    lihatpendapatan();
}

void shellSort() {
    int temp,temp2,temp3;
   for (int gap = data.bulan.size()/2; gap > 0; gap /= 2) {
      for (int i = gap; i < data.bulan.size(); i += 1) {
         int temp = data.bulan[i];
         char temp2 = data.tahun[i];
         int temp3 = data.pendapatan[i];
         for (int j = i; j >= gap && data.bulan[j - gap] > temp; j -= gap) {
            data.bulan[j] = data.bulan[j - gap];
            data.tahun[j] = data.tahun[j - gap];
            data.pendapatan[j] = data.pendapatan[j - gap];
         }
        //  data.bulan[] = temp;
        //  data.tahun[j] = temp2;
        //  data.pendapatan[j] = temp3;
      }
   }
   lihatpendapatan();
}







int main(){
    int ulang = 0;//untuk memasukan nilai pengulangan
    string nama,nim,pilihanmenu;//nama dan nim untuk memasukan nilai nim dan nama//pilihanmenu untuk memilih menu
    while(ulang<3){
        cout<<"MOHON LOGIN TERLEBIH DAHULU\n";
        cout<<"Masukan Nama: ";cin>>nama;
        cout<<"Masukan NIM: ";cin>>nim;
        if(nama=="aji"&&nim=="114"){
            while(true){
                menu();
                cout<<"Pilih Menu: ";cin>>pilihanmenu;
                if(pilihanmenu=="1"){
                    int bulanbaru,tahunbaru;//memasukan bulan agar bisa dimasukan ke array
                    long pendapatanbaru,batas;//memasukan penpatan agar bisa dimasukan ke dalam array pendapatan//batas untuk memasukan berapa banyak data yang kita ingin input
                    cout<<"Banyak data yang  ingin dimasukan: ";
                    while (!(cin >> batas)) {
                    cout << "Mohon hanya memasukan angka.\nBanyak data yang  ingin dimasukan: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    for(int i =0;i<batas;i++){
                        cout<<"Masukan Bulan: ";
                        while (!(cin >> bulanbaru)) {
                            cout << "Mohon hanya memasukan angka.\nMasukan Bulan: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        cout<<"Masukan Tahun: ";
                        while (!(cin >> tahunbaru)) {
                            cout << "Mohon hanya memasukan angka.\nMasukan Tahun: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        // cout<<"Data "<<i+1<<endl;
                        // cout<<"Masukan bulan: ";cin>>bulanbaru;
                        cout<<"Masukan Pendatanpatan Terbaru: ";
                        while (!(cin >> pendapatanbaru)) {
                            cout << "Mohon hanya memasukan angka.\nMasukan Pendatanpatan: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        data.pendapatan.push_back(pendapatanbaru);
                        data.bulan.push_back(bulanbaru);
                        data.tahun.push_back(tahunbaru);
                    }
                }
                else if(pilihanmenu=="2"){
                    string pilihanhapus;//pilihanhapus untuk memastikan apakah user yakin menghapus elemen tersebut
                    int pilihhapus;//piliupdate untuk memilih index elemen yang ingin dihapus
                    if(data.pendapatan.size()>=1){
                        lihatpendapatan();
                        cout<<"Masukan Nomor yang ingin anda hapus: ";
                        while (!(cin >> pilihhapus)) {
                        cout << "Mohon hanya memasukan angka.\nMasukan Nomor yang ingin anda hapus: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');    
                    }
                        cout<<data.pendapatan[pilihhapus-1] << " \n";
                        cout<<"Apakah anda ingin menghapus data diatas[Y/N] :";cin>>pilihanhapus;
                            while(true){
                                if (pilihanhapus=="y"||pilihanhapus=="Y"){
                                    data.pendapatan.erase(data.pendapatan.begin() + (pilihhapus-1));
                                    data.bulan.erase(data.bulan.begin()+(pilihhapus-1));
                                    data.tahun.erase(data.bulan.begin()+(pilihhapus-1));
                                    break;
                                }
                                else if (pilihanhapus=="N"||pilihanhapus=="n"){
                                    break;
                                }
                                else{
                                    cout<<"Mohon maaf pilihan tidak tersedia";
                                }
                            }
                    }
                    else{cout<<"Mohon menambahkan data terlebih dahulu";}            
                }
                else if(pilihanmenu=="3"){
                    string pilihanupdate;//pilihanupdate untuk memastikan apakah user yakin mengupdate elemen tersebut//bulanupdate untuk mengganti elemen bulan di array tangal
                    int bulanupdate,tahunupdate;
                    long pilihupdate,pendapatanupdate;//piliupdate untuk memilih index elemen yang ingin diganti//pendapatanupdate untuk mengganti elemen pendapatan di array pendapatan
                    if(data.pendapatan.size()>=1){    
                        lihatpendapatan();
                        cout<<"Masukan Nomor yang ingin anda Update: ";
                        while (!(cin >> pilihupdate)) {
                        cout << "Mohon hanya memasukan angka.\nMasukan Nomor yang ingin anda Update: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        cout <<data.pendapatan[pilihupdate-1] << " \n";
                        cout<<"Apakah anda ingin mengganti data diatas[Y/N]: ";cin>>pilihanupdate;
                            while(true){
                                if (pilihanupdate=="y"||pilihanupdate=="Y"){
                                        // cout<<"Masukan bulan terbaru: ";cin>>bulanupdate;
                                        // cout<<"Masukan Pendatanpatan Terbaru: ";cin>>pendapatanupdate;
                                        cout<<"Masukan Bulan: ";
                                        while (!(cin >> bulanupdate)) {
                                            cout << "Mohon hanya memasukan angka.\nMasukan Bulan: ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        }
                                        cout<<"Masukan Tahun: ";
                                        while (!(cin >> tahunupdate)) {
                                            cout << "Mohon hanya memasukan angka.\nMasukan Tahun: ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        }
                                        while (!(cin >> pendapatanupdate)) {
                                            cout << "Mohon hanya memasukan angka.\nData pendapatan terbaru: ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        }
                                        data.pendapatan[pilihupdate-1]=pendapatanupdate;
                                        data.bulan[pilihupdate-1]=bulanupdate;
                                        data.tahun[pilihupdate-1]=tahunupdate;
                                        break;
                                }
                                else if (pilihanupdate=="N"||pilihanupdate=="n"){
                                    break;
                                }
                                else{
                                    cout<<"Mohon maaf pilihan tidak tersedia";
                                }
                            }
                    }
                    else{cout<<"Mohon menambahkan data terlebih dahulu";}            
                }
                else if(pilihanmenu=="4"){
                    long total=0;//untuk memasukan penambahan pada pengulangan
                    if(data.pendapatan.size()>=1){
                        lihatpendapatan();
                        for(int i =0;i<data.pendapatan.size();i++){
                            total+=data.pendapatan[i];
                        }
                        int ratarata=total/data.pendapatan.size();//mendapatkan rata rata dari total
                        cout<<"\nTotal pendapatan adalah: Rp."<<total;
                        cout<<"\nRata - rata pendapatan adalah: Rp."<<ratarata;
                        cout<<"\n==================================";
                    }
                    else{cout<<"Mohon menambahkan data terlebih dahulu";} 
                }
                
                else if(pilihanmenu=="5"){
                    insertionSort();
                }

                else if(pilihanmenu=="0"){
                    system("cls");
                    cout<<"SHUTDOWN";
                    exit(0);
                }
                else{
                    cout<<"Maaf Pilihan tidak Tersedia";
                }
            }
        }
        else{
            cout<<"Nama atau NIM anda salah";
            ulang++;
        }
    }
}
