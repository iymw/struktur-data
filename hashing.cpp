#include <iostream>
#include <map>
#include <math.h>

using namespace std;

map<string, map<string, string>> dataAkun;

int hashFunction(string password)
{
    int num = 0;
    const int PRIME_CONST = 7;
    const int DENOMINATOR = 26;

    for (int i = 0; i < password.length(); i++)
    {
        num += password[i] * pow(PRIME_CONST, i);
        num %= DENOMINATOR;
    }

    return num;
}

void registerAkun()
{
    string username, password, fullname;
    cout << "Masukkan Full Name: ";
    cin >> username;
    cout << "Masukkan NRP: " << " ";
    cin >> password;
    cout << "Masukkan Department: " << " ";
    cin >> fullname;

    string hash_key = to_string(hashFunction(password));

    map<string, string> dataDetail;
    dataDetail["username"] = username;
    dataDetail["fullname"] = fullname;

    // masukkan ke map
    dataAkun[hash_key] = dataDetail;
}

void loginAkun()
{
    string username, password;
    cout << "Masukkan Password: " << endl;
    cin >> password;

    string hash_key = to_string(hashFunction(password));

    cout << endl;
    if (dataAkun.find(hash_key) != dataAkun.end())
    {
        cout << "Login berhasil!" << endl
             << endl;
        cout << "==== Account Details ====" << endl;
        cout << "Full Name: " << dataAkun[hash_key]["username"] << endl;
        cout << "Department: " << dataAkun[hash_key]["fullname"] << endl;
    }
    else
    {
        cout << "Login gagal!" << endl
             << endl;
    }
}

void printAkun()
{
    cout << endl;
    for (auto i = dataAkun.begin(); i != dataAkun.end(); i++)
    {
        cout << "Key: " << i->first << "\t"
             << " Username: " << i->second["username"] << " Fullname: " << i->second["fullname"] << endl;
    }
}

// Menu
void menu()
{
    while (true)
    {
        int input_user;

        cout << endl;
        cout << "==== MENU ====" << endl;
        cout << "1. Register Data" << endl;
        cout << "2. Data Confirmation" << endl;
        cout << "3. Exit" << endl;

        cout << endl;
        cout << "Pilih Menu: " << endl;
        cin >> input_user;

        if (input_user == 1)
        {
            registerAkun();
        }
        else if (input_user == 2)
        {
            loginAkun();
        }
        else if (input_user == 3)
        {
            printAkun();
            break;
        }
        else
        {
            cout << "Invalid!" << endl;
        }
    }
}

int main()
{
    menu();
}


/*

1. Program tersebut menerima input berupa nama lengkap, NRP, dan departemen
2. NRP berperan sebagai angka khusus yang akan dihashing menggunakan pola berikut:
    int num = 0;
    const int PRIME_CONST = 7;
    const int DENOMINATOR = 26;

    for (int i = 0; i < password.length(); i++)
    {
        num += password[i] * pow(PRIME_CONST, i);
        num %= DENOMINATOR;
    }
3. Apabila user memilih opsi nomor 2, maka user diminta untuk menginput NRP sebagai metode pengecekan data
4. Apabila data tersebut sudah terdaftar, maka program akan mengeluarkan output sesuai dengan input pada opsi nomor 1
*/