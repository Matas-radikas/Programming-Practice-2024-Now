#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string input = "U2.txt";
const string output = "U2rez.txt";
const int CMax = 100;

struct vard_dalyk_pazy{
    string vard;
    string dalyk;
    int pazy_kiek;
    int pazy[CMax];
    double vidurkis;
};

void skaitymas(vard_dalyk_pazy VDP[], int& n);
void vidurkis(vard_dalyk_pazy VDP[], int n);
void rikiavimas1(vard_dalyk_pazy VDP[], int n);
void rikiavimas2(string dalykai[], int kiekiai[], int m);
void isvedimas(vard_dalyk_pazy VDP[], int n);

int main()
{
    int n = 0; //mokiniø skaièius
    vard_dalyk_pazy VDP[CMax] = {};

    skaitymas(VDP,  n);
    vidurkis(VDP, n);
    rikiavimas1(VDP, n);
    isvedimas(VDP, n);

    return 0;
}
void skaitymas(vard_dalyk_pazy VDP[], int& n){
    ifstream fd(input);

    fd >> n;

    for(int i = 0; i < n; i++){
        fd >> VDP[i].vard;
        fd >> VDP[i].dalyk;
        fd >> VDP[i].pazy_kiek;
        for(int j = 0; j < VDP[i].pazy_kiek; j++){
            fd >> VDP[i].pazy[j];
        }

    }

    fd.close();
}
void vidurkis(vard_dalyk_pazy VDP[], int n){
    int suma = 0;

    for(int i = 0; i < n; i++){
        suma = 0;
        for(int j = 0; j < VDP[i].pazy_kiek; j++){
            suma += VDP[i].pazy[j];
        }
        if(suma > 0){
            VDP[i].vidurkis =(double) suma / VDP[i].pazy_kiek;
        }
        else
            VDP[i].vidurkis = 0;
    }
}
void rikiavimas1(vard_dalyk_pazy VDP[], int n){
    vard_dalyk_pazy temp;

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(VDP[j].dalyk < VDP[i].dalyk){
                temp = VDP[i];
                VDP[i] = VDP[j];
                VDP[j] = temp;
            }
        }
    }
}
void rikiavimas2(string dalykai[], int kiekiai[], int m){
    for(int i = 0; i < m - 1; i++){
        for(int j = i + 1; j < m; j++){
            if(kiekiai[j] > kiekiai[i] || (kiekiai[j] == kiekiai[i] && dalykai[j] < dalykai[i])){

                swap(kiekiai[i], kiekiai[j]);
                swap(dalykai[i], dalykai[j]);
            }
        }
    }
}
void isvedimas(vard_dalyk_pazy VDP[], int n){
    ofstream fr(output);

    string dalykai[CMax];
    int kiekiai[CMax];
    int m = 0;

    for(int i = 0; i < n; i++){
        string temp_dalykas = VDP[i].dalyk;
        int kiek = 0;

        for(int j = 0; j < n; j++){
            if(VDP[j].dalyk == temp_dalykas && VDP[j].vidurkis >= 9){
                kiek++;
            }
        }

        int rasta = 0;
        for(int k = 0; k < m; k++){
            if(dalykai[k] == temp_dalykas){
                rasta = 1;
            }
        }

        if(rasta == 0 && kiek > 0){
            dalykai[m] = temp_dalykas;
            kiekiai[m] = kiek;
            m++;
        }
    }

    if(m == 0){
        fr << "Neatitinka vidurkis" << endl;
        fr.close();
        return;
    }

    rikiavimas2(dalykai, kiekiai, m);

    for(int d = 0; d < m; d++){
        fr << dalykai[d] << " " << kiekiai[d] << endl;
        for(int i = 0; i < n; i++){
            if(VDP[i].dalyk == dalykai[d] && VDP[i].vidurkis >= 9){
                fr << VDP[i].vard << endl;
            }
        }
    }


    fr.close();
}
