#include <iostream>
#include <string>

using namespace std;

struct mahasiswa
{
    string nama;
    string nrp;
    string hobi;
    int umur;
    bool jenis_kelamin;
    string universitas;
    float ipk;
    string kesibukan;
    string masukIt;
    string peminatan;
};

void inputData(struct mahasiswa *mhs, bool &flag, int &input_user)
{
    cin.ignore();
    cout << "Nama: ";
    getline(cin, mhs[input_user].nama);
    cout << "NRP: ";
    cin >> mhs[input_user].nrp;
    cout << "Umur: ";
    cin >> mhs[input_user].umur;
    cout << "Jenis kelamin: ";
    cin >> mhs[input_user].jenis_kelamin;
    cin.ignore(); // Consume the newline character from previous input
    cout << "Universitas: ";
    getline(cin, mhs[input_user].universitas);
    cout << "IPK: ";
    cin >> mhs[input_user].ipk;
    cin.ignore(); // Consume the newline character from previous input
    cout << "Kesibukan: ";
    getline(cin, mhs[input_user].kesibukan);
    cout << "Alasan Masuk IT: ";
    getline(cin, mhs[input_user].masukIt);
    cout << "Peminatan: ";
    getline(cin, mhs[input_user].peminatan);

    cout << endl;

    cout << "Data berhasil disimpan, berikut adalah data ke-" << input_user + 1 << ":" << endl;
    cout << "Nama: " << mhs[input_user].nama << endl;
    cout << "NRP: " << mhs[input_user].nrp << endl;
    cout << "Umur: " << mhs[input_user].umur << endl;
    cout << "Jenis Kelamin: " << (mhs[input_user].jenis_kelamin ? "Laki-laki" : "Perempuan") << endl;
    cout << "Universitas: " << mhs[input_user].universitas << endl;
    cout << "IPK: " << mhs[input_user].ipk << endl;
    cout << "Kesibukan: " << mhs[input_user].kesibukan << endl;
    cout << "Alasan Masuk IT: " << mhs[input_user].masukIt << endl;
    cout << "Peminatan: " << mhs[input_user].peminatan << endl;

    cout << endl;

    input_user++;

    flag = true;
}

void ubahData(struct mahasiswa *mhs, bool &flag, int i, int input_user)
{
    cout << "Data nomor berapa yang ingin Anda rubah? " << endl;
    cin >> i;

    int j = i - 1;
    cout << "Data ke-" << i << ":" << endl;
    cout << "Nama: " << mhs[j].nama << endl;
    cout << "NRP: " << mhs[j].nrp << endl;
    cout << "Umur: " << mhs[j].umur << endl;
    cout << "Jenis Kelamin: " << (mhs[j].jenis_kelamin ? "Laki-laki" : "Perempuan") << endl;
    cout << "Universitas: " << mhs[j].universitas << endl;
    cout << "IPK: " << mhs[j].ipk << endl;
    cout << "Kesibukan: " << mhs[j].kesibukan << endl;
    cout << "Alasan Masuk IT: " << mhs[j].masukIt << endl;
    cout << "Peminatan: " << mhs[j].peminatan << endl;

    cout << endl;
    cin.ignore();
    cout << "Nama: ";
    getline(cin, mhs[j].nama);
    cout << "NRP: ";
    cin >> mhs[j].nrp;
    cout << "Umur: ";
    cin >> mhs[j].umur;
    cout << "Jenis kelamin: ";
    cin >> mhs[j].jenis_kelamin;
    cin.ignore();
    cout << "Universitas: ";
    getline(cin, mhs[j].universitas);
    cout << "IPK: ";
    cin >> mhs[j].ipk;
    cin.ignore();
    cout << "Kesibukan: ";
    getline(cin, mhs[j].kesibukan);
    cout << "Alasan Masuk IT: ";
    getline(cin, mhs[j].masukIt);
    cout << "Peminatan: ";
    getline(cin, mhs[j].peminatan);

    cout << endl;

    flag = true;
    cout << "Data berhasil diubah" << endl;
}

void tampilData(struct mahasiswa *mhs, int input_user)
{
    cout << "Berikut adalah tampilan semua data:" << endl;

    for (int i = 0; i < input_user; i++)
    {
        cout << "Data ke-" << i + 1 << ":" << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NRP: " << mhs[i].nrp << endl;
        cout << "Umur: " << mhs[i].umur << endl;
        cout << "Jenis Kelamin: " << (mhs[i].jenis_kelamin ? "Laki-laki" : "Perempuan") << endl;
        cout << "Universitas: " << mhs[i].universitas << endl;
        cout << "IPK: " << mhs[i].ipk << endl;
        cout << "Kesibukan: " << mhs[i].kesibukan << endl;
        cout << "Alasan Masuk IT: " << mhs[i].masukIt << endl;
        cout << "Peminatan: " << mhs[i].peminatan << endl;
        cout << endl;
    }
}

void hapusData(struct mahasiswa *mhs, bool &flag, int i, int &user_input)
{
    cout << "Data nomor berapa yang ingin Anda hapus?" << endl;
    cin >> i;

    if (i <= user_input)
    {
        for (int j = i - 1; j < user_input - 1; j++)
        {
            mhs[j] = mhs[j + 1];
        }

        user_input--;
        cout << "Data berhasil dihapus" << endl;
    }

    if (user_input == 0)
    {
        flag = false;
    }
    else
    {
        flag = true;
    }
}

void lihatData(struct mahasiswa *mhs, bool &flag, int i)
{
    cout << "Data nomor berapa yang ingin Anda lihat? " << endl;
    cin >> i;

    int j = i - 1;

    cout << "Data ke-" << i << ":" << endl;
    cout << "Nama: " << mhs[j].nama << endl;
    cout << "NRP: " << mhs[j].nrp << endl;
    cout << "Umur: " << mhs[j].umur << endl;
    cout << "Jenis Kelamin: " << (mhs[j].jenis_kelamin ? "Laki-laki" : "Perempuan") << endl;
    cout << "Universitas: " << mhs[j].universitas << endl;
    cout << "IPK: " << mhs[j].ipk << endl;
    cout << "Kesibukan: " << mhs[j].kesibukan << endl;
    cout << "Alasan Masuk IT: " << mhs[j].masukIt << endl;
    cout << "Peminatan: " << mhs[j].peminatan << endl;

    cout << endl;

    flag = true;
}

int main()
{
    int choose;
    struct mahasiswa mhs[10];
    int input_user = 0;
    bool flag = false;
    int i;

    do
    {
        int add = 0;

        cout << "1. Input data" << endl;
        cout << "2. Menampilkan data" << endl;
        cout << "3. Merubah data" << endl;
        cout << "4. Menghapus data" << endl;
        cout << "5. Mencari Data" << endl;
        cout << "0. Stop" << endl;

        cout << endl;
        cout << "Pilih menu: ";
        cin >> choose;

        switch (choose)
        {
        case 0:
            cout << "Terima kasih telah menggunakan aplikasi kami" << endl;
            break;
        case 1:
            inputData(mhs, flag, input_user);
            break;

        case 2:
            if (flag)
            {
                tampilData(mhs, input_user);
            }
            else
            {
                cout << "Tidak ada data yang ditampilkan, kamu belum input data" << endl;
            }
            break;

        case 3:
            if (flag)
            {
                ubahData(mhs, flag, i, input_user);
            }
            else
            {
                cout << "Tidak ada data yang bisa diubah, kamu belum input data" << endl;
            }
            break;

        case 4:
            if (flag)
            {
                hapusData(mhs, flag, i, input_user);
            }
            else
            {
                cout << "Tidak ada data yang terhapus, kamu belum input data" << endl;
            }
            break;

        case 5:
            if (flag)
            {
                lihatData(mhs, flag, i);
            }
            else
            {
                cout << "Spesifik data tidak bisa dilihat, kamu belum input data" << endl;
            }
            break;
        }
    } while (choose != 0);
}