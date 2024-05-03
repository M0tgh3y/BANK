#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
class Date{
public:
    int day, month, year;
};
ostream & operator<<(ostream &x, Date a)
{
    cout << a.year;
    cout << "-" << a.month;
    cout << "-" << a.day;
    return x;
}
istream & operator>>(istream &x, Date &a)
{
    cout << "\n Enter day:";
    cin >> a.day;
    cout << "\n Enter Month:";
    cin >> a.month;
    cout << "\n Enter Year:";
    cin >> a.year;
    return x;
}

//*************************

class Moshtari {
public:
    char nam[30], famil[50], namePedar[30], adress[100];
    int mojudi;
    long long int shomareHesab, codemeli;
    Date tavalod;

    friend ostream & operator<<(ostream &x, Moshtari &a)
    {
        x << endl << "Nam: " << a.nam << endl;
        x << "Famil: " << a.famil << endl;
        x << "Name Pedar: " << a.namePedar << endl;
        x << "Adres: " << a.adress << endl;
        x << "Code Melli: " << a.codemeli << endl;
        x << "Tarikh Tavalod: " << a.tavalod.year << "/" << a.tavalod.month << "/" << a.tavalod.day << endl;
        x << "Shomare Hesab: " << a.shomareHesab << endl;
        x << "Mojudi: " << a.mojudi << endl;
        return x;
    }


    void NewAccount(Moshtari &a)
    {
        cout << "\n Nam ra vared konid: ";
        cin.ignore();
        cin.getline(a.nam, 30);

        cout << "\n famil ra vared konid: ";
        cin.ignore();
        cin.getline(a.famil, 50);

        cout << "\n NamePedar ra vared konid: ";
        cin.ignore();
        cin.getline(a.namePedar, 30);

        cout << "\n Adres ra vared konid: ";
        cin.ignore();
        cin.getline(a.adress, 100);

        cout << "\n Code melli ra vared konid: ";
        cin >> a.codemeli;

        cout << "\n tarikh tavalod ra vared konid(sal, mah, ruz): ";
        cin >> a.tavalod.year >> a.tavalod.month >> a.tavalod.day;

        cout << "\n Shomare hesab ra vared konid: ";
        cin >> a.shomareHesab;

        cout << "\n Mojoodi ra vared konid: ";
        cin >> a.mojudi;
    }

    void virayesh(Moshtari &a)
    {
        int editChoice;
        cout << "1. Nam" << endl;
        cout << "2. Famil" << endl;
        cout << "3. Name Pedar" << endl;
        cout << "4. Adres" << endl;
        cout << "5. Code Melli" << endl;
        cout << "6. Tarikh Tavalod" << endl;
        cout << "7. Shomare Hesab" << endl;
        cout << "8. Mojudi" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose the field you want to edit: ";
        cin >> editChoice;
        switch (editChoice) {
            case 1:
                cout << "Nam jadid ra vared konid: ";
                cin.ignore();
                cin.getline(a.nam, 30);
                break;
            case 2:
                cout << "Famil jadid ra vared konid: ";
                cin.ignore();
                cin.getline(a.famil, 50);
                break;
            case 3:
                cout << "NamePedar jadid ra vared konid: ";
                cin.ignore();
                cin.getline(a.namePedar, 30);
                break;
            case 4:
                cout << "Adres jadid ra vared konid: ";
                cin.ignore();
                cin.getline(a.adress, 100);
                break;
            case 5:
                cout << "Code Melli jadid ra vared konid: ";
                cin >> a.codemeli;
                break;
            case 6:
                cout << "Tarikh Tavalod (sal, mah, ruz) jadid ra vared konid: ";
                cin >> a.tavalod.year >> a.tavalod.month >> a.tavalod.day;
                break;
            case 7:
                cout << "Shomare Hesab jadid ra vared konid: ";
                cin >> a.shomareHesab;
                break;
            case 8:
                cout << "Mojudi jadid ra vared konid: ";
                cin >> a.mojudi;
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!";
                break;
        }

    }

    int variz(Moshtari &a, int b)
    {
        a.mojudi += b;
        return a.mojudi;
    }

     int Bardasht(Moshtari &a, int b)
    {
        if (b > a.mojudi)
        {
            cout << "You are SO POOR! (and me too)";
        }
        else
        {
            a.mojudi -= b;
        }
        return a.mojudi;
    }

    void Enteghal(Moshtari &a, Moshtari &b, int c)
    {
        if (c > a.mojudi)
        {
            cout << "You are SO POOR! (and me too)";
        }
        else
        {
            a.mojudi -= c;
            b.mojudi += c;
            cout << "#Enteghal Movafaghiat#";
        }
    }

    void Mojodi(Moshtari &a)
    {
        cout << "mojudi =" << a.mojudi;
    }
};

//****************************

int main()
{
    int choice;
    int tedadeMoshtari = -1;
    Moshtari moshtari[100];
    while (tedadeMoshtari < 100)
    {
        cout << endl << "**************************" << "\n 1- Baz kardan Hesab Jadid";
        cout << "\n 2- Virayesh";
        cout << "\n 3- Variz";
        cout << "\n 4- Bardasht";
        cout << "\n 5- Enteghal";
        cout << "\n 6- Mojudi";
        cout << "\n 0- Exit" << endl << "**************************";
        cout << "\n Amaliat mored nazar ra vared konid: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                tedadeMoshtari++;
                cout << "\n *** Baz kardan Hesab Jadid ***";
                moshtari[tedadeMoshtari].NewAccount(moshtari[tedadeMoshtari]);
                break;
            case 2:
                cout << "\n *** Virayesh ***" << endl;
                moshtari[tedadeMoshtari].virayesh(moshtari[tedadeMoshtari]);
                break;
            case 3:
                cout << "\n *** Variz ***";
                cout << "\n Mablagh ra vared konid: ";
                int b;
                cin >> b;
                moshtari[tedadeMoshtari].variz(moshtari[tedadeMoshtari], b);
                cout << "\n mojudi = " << moshtari[tedadeMoshtari].mojudi;
                break;
            case 4:
                cout << "\n *** Bardasht ***";
                cout << "\n Mablagh ra vared konid: ";
                int c;
                cin >> c;
                moshtari[tedadeMoshtari].Bardasht(moshtari[tedadeMoshtari], c);
                cout << "\n mojudi = " << moshtari[tedadeMoshtari].mojudi;
                break;
            case 5:
                cout << "\n *** Enteghal ***";
                long long int shomarehes;
                cout << "\n shomare hessab mored nazar ra vared konid: ";
                cin >> shomarehes;
                for (int i = 0; i < 100; i++)
                {
                    if (moshtari[i].shomareHesab == shomarehes)
                    {
                        int mablagh;
                        cout << "\n Mablagh ra vared konid: ";
                        cin >> mablagh;
                        moshtari[tedadeMoshtari].Enteghal(moshtari[tedadeMoshtari], moshtari[i], mablagh);
                        break;
                    }
                }
                break;
            case 6:
                moshtari[tedadeMoshtari].Mojodi(moshtari[tedadeMoshtari]);
                return 0;
            case 0:
                break;
            default:
                cout << "Invalid choice!";
                break;
        }
    }

    cout << endl << "****** All Account in This Bank ******";
    for (int i = 1; i <= tedadeMoshtari; i++)
    {
        cout << moshtari[i] << endl;
    }
}
