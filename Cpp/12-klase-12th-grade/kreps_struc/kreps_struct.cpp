#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int CMax = 100;
const string komentaras = "-------------------------------------";
const string input = "Duomenys.txt";
const string output = "Rezultatai.txt";

struct Kreps{
    string vardas;
    double ugis;
    int taskai;
};

void Skaitymas(Kreps A[], int& n, double& p, double& k);
void Didugistaskai(Kreps A[], int n, double& p, double& k, double& didug, double& didim);
void Atranka(Kreps A[], Kreps B[], int n, double& didug, double& didim, int& kiek);
void Spausdinimas(Kreps B[], int kiek);

int main()
{
    Kreps A[CMax], B[CMax]; // struct masyvai, duomenys is failo ir duomenys isvedimui
    int n = 0, kiek = 0; // n - nariu skaicius, kiek - kiek nariu pateko i rinktine
    double p = 0, k = 0; // p - % dalis, auksciausio zmogaus, k - % dalis, daugiausiai tasku imetes zmogus
    double didug = 0, didim = 0; //  didug - didziausias ugis, didim - daugiausiai tasku imesta i krepsi
    Skaitymas(A, n, p, k); // nuskaito duomenis is failo
    Didugistaskai(A, n, p, k, didug, didim); // nustato kriterijus rinktiniai
    Atranka(A, B, n, didug, didim, kiek); // atrenkame nauja masyva (Kreprez B) pagal kriterijas
    Spausdinimas(B, kiek); // israsome i faila gauto naujo masyvo rezultatus
    return 0;
}
void Skaitymas(Kreps A[], int& n, double& p, double& k){
    ifstream fd(input);
    fd >> n;
    for (int i = 0; i < n; i++){
        fd >> A[i].vardas >> A[i].ugis >> A[i].taskai;
    }
    fd >> p >> k;
    fd.close();
}
void Didugistaskai(Kreps A[], int n, double& p, double& k, double & didug, double & didim){
    didug = A[0].ugis; // suteikiame reiksme kintamajam, didug - pirmo krepsininko ugis
    didim = A[0].taskai; // suteikiame reiksme kintamajam, didim - pirmo krepsininko imestu tasku skaiciui
    for(int i = 1; i < n; i++){
        if(A[i].ugis > didug){
            didug = A[i].ugis;
        }
        if(A[i].taskai > didim){
            didim = A[i].taskai;
        }
    }
    didug = didug - (didug*(p/100)); // bendras skaicius pagal kriterija
    didim = didim - (didim*(k/100)); // bendras skaicius pagal kriterija
}
void Atranka(Kreps A[], Kreps B[], int n, double& didug, double& didim, int& kiek){
    for(int i = 0; i < n; i++){
        if(A[i].ugis >= didug || A[i].taskai >= didim){ // pritaikome kriterijas ir sukuriame nauja masyva
            B[kiek].vardas = A[i].vardas;
            B[kiek].ugis = A[i].ugis;
            B[kiek].taskai = A[i].taskai;
            kiek++; // naujo masyvo vietos skaicius        }
        }
    }
}
void Spausdinimas(Kreps B[], int kiek){
    ofstream fr(output);
    fr << komentaras << endl;
    fr << left << setw(15) << "Vardas" << setw(9) <<"Ūgis" << "Taškai" << endl;
    fr << komentaras << endl;
    for (int i = 0; i < kiek; i++){
        fr << left << setw(15) << B[i].vardas << setw(9) << B[i].ugis << B[i].taskai << endl;
    }
    fr << komentaras << endl;
    fr.close();
}
