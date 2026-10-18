#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

const string input = "U1.txt";
const string output = "U1rez.txt";
const int CMax = 100;

void ivedimas(char skola[], int& n);
void isvedimas(char skola[], int n);
int kiek_skaiciaus_po_kab(char skola[], int n);
int zenklas_simb(char skola[], int n);

int main()
{
    char skola[CMax];
    int n;

    ivedimas(skola, n);
    isvedimas(skola, n);

    return 0;
}
void ivedimas(char skola[], int& n){
    ifstream fd(input);

    fd.getline(skola, CMax);
    n = strlen(skola);

    fd.close();
}
void isvedimas(char skola[], int n){
    ofstream fr(output);
    int kiek; // skaitmenų kiekis po kablelio
    int zenklas; // zenklas ar yra '-' (1), jei ne (0)

    for(int i = 0; i < n; i++){
        if(skola[i] >= 'a' && skola[i] <= 'z' || skola[i] >= 'A' && skola[i] <= 'Z'){

        fr << "NE" << endl;
        fr.close();
        return;
        }
    }

        kiek = kiek_skaiciaus_po_kab(skola, n);
        zenklas = zenklas_simb(skola, n);

        if(zenklas == 1 && kiek == 2)
            fr << "TAIP" << endl;
        else fr << "NE" << endl;

    fr.close();
}
// skaičiaus kiekis po kablelio apskaičiavimas ir ar skaičius turi ',', o ne '.'
int kiek_skaiciaus_po_kab(char skola[], int n){
    int k = 0;
    //ieškome kablelio
    while(k < n && skola[k] != ',')
        k++;
    //jei kablelio nėra grąžiname 0
    if (k == n) return 0;

    //jei yra kablelis apskaičiuojame skaitmenų kiekį po kablelio
    k = n - k - 1;
    return k;
}
// apskaičiuojame ar yra '-' char eilutėje
int zenklas_simb(char skola[], int n){
    int z = 0;
    if(skola[0] == '-' && skola[1] >= '1' && skola[1] <= '9'){
        z++;
    }
    return z;
}
