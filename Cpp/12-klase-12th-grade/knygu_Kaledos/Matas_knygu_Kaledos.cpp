#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void skaitymas(int &n, double kain[], double kiek[]);
void knygkain(int &n, double kain[], double kiek[], double sum[]);
double visosknyg(int n, double sum[]);
int parduotaknyg(int n, double kiek[]);
void isvedimas(int n, double kain[], double kiek[], double sum[]);

int main()
{
    int n; // knygų tipai
    double kain[100], kiek[100], sum[100]; // knygos vieneto kaina;  knygø kiekis; vienos knygos tipo kainos suma

    skaitymas(n, kain, kiek); // išrašome iš duomenų failo kintamuosius į masyvus
    knygkain(n, kain, kiek, sum); // apskaičiuojame kiekvienos knygos tipų kainų sumas
    isvedimas(n, kain, kiek, sum); // išvedame į failą gautus atsakymus

    return 0;
}
void skaitymas(int &n, double kain[], double kiek[]){

    ifstream fd("Duomenys1.txt");

    fd >> n;

    for (int i = 0; i < n; i++){
        fd >> kain[i] >> kiek[i];
    }

    fd.close();
}
void knygkain(int &n, double kain[], double kiek[], double sum[]){

    for (int i = 0; i < n; i++){
        sum[i] = kain[i] * kiek[i];
    }

}
double visosknyg (int n, double sum[]){

    double visosknygos = 0;

    for (int i = 0; i < n; i++){
        visosknygos += sum[i];
    }

    return visosknygos;
}
int parduotaknyg (int n, double kiek[]){

    int virs5knyg = 0;

    for (int i = 0; i < n; i++){
        if (kiek[i] >= 5){
        virs5knyg++;
        }
    }

    return virs5knyg;
}
void isvedimas(int n, double kain[], double kiek[], double sum[]){
    ofstream fr("Rezultatai1.txt");

    for (int i = 0; i < n; i++){
        fr << kain[i] << " " << (int)kiek[i] << " ";
        fr << fixed << setprecision(2) << sum[i] << endl;
    }

    fr << visosknyg(n, sum) << endl; // apskaičiuojame visų turimų knygų kainų sumas
    fr << parduotaknyg(n, kiek) << endl; // apskaičiuojame kiek skirtingų knygų tipų biblioteka turėjo daugiau nei 5

    fr.close();

}
