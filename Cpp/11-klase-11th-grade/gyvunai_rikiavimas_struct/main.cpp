#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string input = "duomenys.txt";
const string output = "rez.txt";
const int CMax = 100;
const int CPav = 15;
const int CPav_2 = 20;

struct gyv_kiek{
    string Gyv;
    int kiek = {0};

};

void skaitymas(int& n, gyv_kiek GK[], string Sav[]);
void sumavimas(int& n, gyv_kiek GK[]);
void rikiavimas(int n, gyv_kiek GK[]);
void isvedimas(int n, gyv_kiek GK[]);

int main()
{
    int n;
    gyv_kiek GK[CMax];
    string Sav[CMax];

    skaitymas(n, GK, Sav);
    sumavimas(n, GK);
    rikiavimas(n, GK);
    isvedimas(n, GK);

    return 0;
}
void skaitymas(int& n, gyv_kiek GK[], string Sav[]){
    ifstream fd(input);
    char eil_1[CPav + 1];
    char eil_2[CPav_2 + 1];

    fd >> n;
    for (int i = 0; i < n; i++){
        fd.ignore(80, '\n');

        fd.get(eil_1, CPav);
        GK[i].Gyv = eil_1;

        fd >> GK[i].kiek;

        fd.get(eil_2, CPav_2);
        Sav[i] = eil_2;
    }

    fd.close();
}
// sudedame pasikartuojančius gyunų kiekius, sumažiname masyvą
void sumavimas(int& n, gyv_kiek GK[]){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (GK[i].Gyv == GK[j].Gyv){
                GK[i].kiek += GK[j].kiek;

                for (int k = j; k < n - 1; k++){
                    GK[k] = GK[k + 1];
                }

                n--;
                j--;
            }
        }
    }
}
// rikiuojame mažėjamo tvarka
void rikiavimas(int n, gyv_kiek GK[]){
    int did;
    int temp; // laikinas kiekio saugojimo keitinys
    string temp1; // laikinas gyvūno saugojimo keitinys
    for (int i = 0; i < n - 1; i++){
        did = i;
        for (int j = i + 1; j < n; j++){
            if (GK[j].kiek > GK[did].kiek){
                did = j;
            }
        }
        if (did != i){
            // kiekio rikiavimas
            temp = GK[i].kiek;
            GK[i].kiek = GK[did].kiek;
            GK[did].kiek = temp;
            // gyvūnų rikiavimas
            temp1 = GK[i].Gyv;
            GK[i].Gyv = GK[did].Gyv;
            GK[did].Gyv = temp1;
        }

    }
}
void isvedimas(int n, gyv_kiek GK[]){
    ofstream fr{output};

    for(int i = 0; i < n; i++){
        fr << left << setw(CPav) << GK[i].Gyv;
        fr << right << setw(5) << GK[i].kiek << endl;
    }

    fr.close();
}
