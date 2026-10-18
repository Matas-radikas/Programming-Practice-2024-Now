#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string input = "duomenys.txt";
const string output = "rez.txt";
const int CMax = 100;
const int CPav = 20;

struct Pav_ir_kiek{
    string pav;
    string vals;
    int kiek;
};

void skaitymas(Pav_ir_kiek PK[], int& n);
void atranka(Pav_ir_kiek PK[], int n, Pav_ir_kiek PK2[], int& m);
int Yra(Pav_ir_kiek PK[], int n, string pav);
void spausdinimas(Pav_ir_kiek PK2[], int n, string pav);


int main()
{
    Pav_ir_kiek PK[CMax];
    Pav_ir_kiek PK2[CMax]; // naujas masyvas
    int n;
    int m; // naujo masyvo indexas

    skaitymas(PK, n);
    atranka(PK, n, PK2, m);
    spausdinimas(PK2, m, "Valstybiu sarasas:");

    return 0;
}
void skaitymas(Pav_ir_kiek PK[], int& n){
    ifstream fd(input);
    char eil[CPav + 1];

    fd >> n;
    fd.ignore(80, '\n');
    for(int i = 0; i < n; i++){
        fd.get(eil, CPav);
        PK[i].pav = eil;
        getline(fd, PK[i].vals);
        PK[i].kiek = 1;
    }

    fd.close();
}
void spausdinimas(Pav_ir_kiek PK2[], int m, string pav){
    ofstream fr(output);
    fr << pav << endl;
    for(int i = 0; i < m; i++){
        fr << setw(15) << PK2[i].vals;
        fr << setw(6) << PK2[i].kiek;
        fr << endl;
    }
    fr.close();
}
void atranka(Pav_ir_kiek PK[], int n, Pav_ir_kiek PK2[], int& m){
    m = 0;
    for (int i = 0; i < n; i++){
        //ieðkome ar yra naujame masyve pavadinimas
        int k = Yra(PK2, m, PK[i].vals);
            //jei yra didiname kieká
            if(k >= 0){
                PK2[k].kiek++;
            }
            //jei nëra priskiriame naujam masyvui pavadinimà ir didiname indeksà
            else{
                PK2[m] = PK[i];
                m++;
            }
    }
}
int Yra(Pav_ir_kiek PK[], int m, string pav){
    for (int i = 0; i < m; i++){
        if(PK[i].vals == pav) return i;
    }
    return -1;
}
