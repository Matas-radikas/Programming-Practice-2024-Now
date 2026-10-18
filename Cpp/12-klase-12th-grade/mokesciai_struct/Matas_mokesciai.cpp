#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int CMax = 1000;
const string input = "duomenys.txt";
const string output = "rezultatai.txt";
const string komentaras = "-------------------------";

struct zmones_ir_mokesciai{
    string vardas;
    double siluma;
    double telefonas;
    double vanduo;
};
struct mokesciai{
    string vardas;
    double suma;
};
struct paslaugos{
    double suma_silumai = 0;
    double suma_telefonui = 0;
    double suma_vandeniui = 0;
};
void skaitymas(zmones_ir_mokesciai ZM[], int& n);
void liko_moketi_ir_paslaugos(zmones_ir_mokesciai ZM[], mokesciai M[], paslaugos &p, int n, int& m);
void isvedimas(paslaugos p, mokesciai M[], int m);

int main()
{
    zmones_ir_mokesciai ZM[CMax]; // asmenys ir jiems priskirti mokesčiai
    mokesciai M[CMax]; // kam dar trūksta/reikia sumokėti mokesčius
    paslaugos p; // paslaugų uždarbis
    int n = 0, m = 0; // n - visi asmenys; m - asmenys, kuriems dar reikia mokėti mokesčius

    skaitymas(ZM, n);
    liko_moketi_ir_paslaugos(ZM, M, p, n, m);
    isvedimas(p, M, m);

    return 0;
}
void skaitymas(zmones_ir_mokesciai ZM[], int& n){
    ifstream fd (input);
    if (!fd.is_open()){ // patikriname ar duomenų failas tikrai atsidarė
        cout << "duomenų failas neatsidarė" << endl;
        return;
    }
    else {
        fd >> n;
        for (int i = 0; i < n; i++){
            fd >> ZM[i].vardas >> ZM[i].siluma >> ZM[i].telefonas >> ZM[i].vanduo;
        }
    }
    fd.close();
}
void liko_moketi_ir_paslaugos(zmones_ir_mokesciai ZM[], mokesciai M[], paslaugos &p, int n, int& m){
    for (int i = 0; i < n; i++){
        double suma = 0;

        if(ZM[i].siluma > 0) {
            suma += ZM[i].siluma;
            p.suma_silumai += ZM[i].siluma;
        }
        if(ZM[i].telefonas > 0){
            suma += ZM[i].telefonas;
            p.suma_telefonui += ZM[i].telefonas;
        }
        if(ZM[i].vanduo > 0){
            suma += ZM[i].vanduo;
            p.suma_vandeniui += ZM[i].vanduo;
        }
        if (suma > 0) {
            M[m].vardas = ZM[i].vardas;
            M[m].suma = suma;
            m++;
        }
    }
}
void isvedimas(paslaugos p, mokesciai M[], int m){
    ofstream fr(output);
    fr << fixed << "Už šilumą turi būti sumokėta: " << right << setw (7) << setprecision (2) << p.suma_silumai << endl;
    fr << fixed << "Už telefoną turi būti sumokėta: " << right << setw (5) << setprecision (2) << p.suma_telefonui << endl;
    fr << fixed << "Už vandenį turi būti sumokėta: " << right << setw (6) << setprecision (2) <<p.suma_vandeniui << endl;
    fr << komentaras << endl;
    fr << right << "Vardas" << setw(18) <<"Turi mokėti" << endl;
    fr << komentaras << endl;
    for (int i = 0; i < m; i++){
        fr << fixed << left << setw (15)<< M[i].vardas << setprecision(2) << M[i].suma << endl;
    }
    fr << komentaras << endl;
    fr.close();
}
