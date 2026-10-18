#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

void skaitymas(int &pinigai, int &prekes, int kodas[], int kaina[]);
void atrinkti(int kaina[], int prekes, int pinigai, string TarbaN[]);
int perkamosprek(int kaina[], int prekes, int pinigai);
void isvedimas(int kodas[], string TarbaN[], int prekes, int kaina[], int pinigai);

int main()
{

    int pinigai, prekes, kodas[100], kaina[100], perkam; // perkam - ką galime nusipirkti;
    string TarbaN[100]; // Taip/Ne - perkamos prekės sprendimas

    skaitymas(pinigai, prekes, kodas, kaina);
    atrinkti(kaina, prekes, pinigai, TarbaN);
    isvedimas(kodas, TarbaN, prekes, kaina, pinigai);

    return 0;
}
void skaitymas(int &pinigai, int &prekes, int kodas[], int kaina[]){
    ifstream fd("Duomenys2.txt");

    fd >> pinigai >> prekes;

    for (int i = 0; i < prekes; i++){
        fd >> kodas[i] >> kaina[i];
    }

    fd.close();
}
void atrinkti(int kaina[], int prekes, int pinigai, string TarbaN[]){

    for (int i = 0; i < prekes; i++){
        if (kaina[i] <= pinigai) TarbaN[i] = "TAIP";
        else TarbaN[i] = "NE";
    }

}
int perkamosprek(int kaina[], int prekes, int pinigai){

    int prekiusuma = 0, perkam = 0;

    for(int i = 0; i < prekes; i++){

        prekiusuma += kaina[i];
        if(prekiusuma <= pinigai) perkam++;
    }

    return perkam;
}
void isvedimas(int kodas[], string TarbaN[], int prekes, int kaina[], int pinigai){

    ofstream fr("Rezultatai2.txt");

    for (int i = 0; i < prekes; i++){
        fr << kodas[i] << " " << TarbaN[i] << endl;
    }

    fr << "Galima nusipirkt " << perkamosprek(kaina, prekes, pinigai) << " prekes" << endl;

    fr.close();
}
