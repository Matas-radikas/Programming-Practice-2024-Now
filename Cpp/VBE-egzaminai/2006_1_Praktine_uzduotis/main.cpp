#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string input = "Duom1.txt";
const string output = "Rez1.txt";
const int CMax = 10000;

void skaitymas(int& n, int M[], long long SV[], int SV_pra[]);
void isvedimas(int n, int M[], long long SV[], int SV_pra[]);
double skaiciavimas(int n, int M[], long long SV[], int SV_pra[]);

int main()
{
    int n;
    int M[CMax]; // lygiagrečiai sujungtų laidininkų skaičių masyvas
    long long SV[CMax]; // varžų reikšmių masyvas
    int SV_pra[CMax]; // varžų reikšmių indeksų masyvas

    skaitymas(n, M, SV, SV_pra);
    isvedimas(n, M, SV, SV_pra);

    return 0;
}
void skaitymas(int& n, int M[], long long SV[], int SV_pra[]){
    ifstream fd(input);
    if(!fd.is_open()){
        cout << "Failas neatsidarė" << endl;
        return;
    }
    fd >> n;

    int index = 0;
    for(int i = 0; i < n; i++){
        fd >> M[i]; // nuskaitome lygiagrečiai sujungtų laidininkų skaičius
        SV_pra[i] = index; // priskiriame nauja masyvo indexą

        for(int j = 0; j < M[i]; j++){
            fd >> SV[index]; // naudojame indexą ir nuskaitome varžos reikšmę
            index++; // didiname indexą
        }
    }
    fd.close();
}
void isvedimas(int n, int M[], long long SV[], int SV_pra[]){
    ofstream fr(output);
    double R = 0;

    R = skaiciavimas(n, M, SV, SV_pra); // apskaičiuojame bendrą varžą
    fr << fixed << setprecision(2) << R << endl;

    fr.close();
}
double skaiciavimas(int n, int M[], long long SV[], int SV_pra[]){
    double L[CMax], R = 0;

    for(int i = 0; i < n; i++){
        L[i] = 0; // kadangi skaičiuojame sumą kintamajam suteikiame nulinę reikšmę

        for(int j = 0; j < M[i]; j++){
            L[i] += (double) 1 / SV[SV_pra[i] + j]; // skaičiuojame 1/R kiekvienai varžai
        }
        R += (double) 1 / L[i]; // bendros varžos skaičiavimas (R = 1 / (1/R1 + 1/R2 + ...))
    }

    return R;
}
