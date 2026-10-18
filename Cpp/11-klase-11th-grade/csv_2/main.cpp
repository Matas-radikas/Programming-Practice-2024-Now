#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const string input = "Darbuotojai.csv";
const string output = "Rezultatai.csv";
const int CMax = 100;
const string komentaras = "Vardas,Pavardė,Atlyginimas";

struct Vard_Pav_suma {
    string Vard;
    string Pav;
    int suma;
};

void skaitymas(Vard_Pav_suma VPs[], int& i);
int suma(int h, int atly_per_h);
void rikiavimas(Vard_Pav_suma VPs[], int i);
void isvedimas(Vard_Pav_suma VPs[], int i);

int main()
{
    Vard_Pav_suma VPs[CMax] = {};
    int i = 0; // indexas

    skaitymas(VPs, i);
    rikiavimas(VPs, i);
    isvedimas(VPs, i);

    return 0;
}
void skaitymas(Vard_Pav_suma VPs[], int& i){
    ifstream fd(input);

    char k = ','; // kableliai
    string data_antraste = " ";
    int h = 0; // valandos
    int atly_per_h = 0;

    getline(fd, data_antraste);

    while(getline(fd, VPs[i].Vard, ',')){

        getline(fd, VPs[i].Pav, ',');

        fd >> h;
        fd >> k;
        fd >> atly_per_h;
        fd.ignore(80, '\n');

        VPs[i].suma = suma(h, atly_per_h);

        i++;
    }

    fd.close();
}
int suma(int h, int atly_per_h){
    int sum = 0;

    sum = h * atly_per_h;

    return sum;
}
void rikiavimas(Vard_Pav_suma VPs[], int i){
    Vard_Pav_suma temp;
    int mini = 0;

    for(int j = 0; j < i-1; j++){
        mini = j;
        for(int h = j + 1; h < i; h++)
            if(VPs[h].suma > VPs[mini].suma)
                mini = h;

        temp = VPs[j];
        VPs[j] = VPs[mini];
        VPs[mini] = temp;

    }
}
void isvedimas(Vard_Pav_suma VPs[], int i){
    ofstream fr(output);

    char k = ',';

    fr << komentaras << endl;

    for(int j = 0; j < i; j++){
            fr << VPs[j].Vard << k;
            fr << VPs[j].Pav << k;
            fr << VPs[j].suma << endl;
    }
    fr.close();
}
