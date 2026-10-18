#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string input = "duom.txt";
const string output = "rez.txt";
const int CMax = 100;
const int CPav = 20;

struct Vard_kiek{
    string Vard;
    int kiek;
};

void skaitymas(int& n, string Pav[], Vard_kiek Vk[]);
void atranka(int& n, Vard_kiek Vk[], Vard_kiek Vk2[], int& m);
int Yra(Vard_kiek Vk2[], int m, string Vard);
void spausdinti(Vard_kiek Vk2[], int m);
void rikiavimas(Vard_kiek Vk2[], int m);

int main()
{
    int n = 0, m = 0;
    string Pav[CMax];
    Vard_kiek Vk[CMax], Vk2[CMax];

    skaitymas(n, Pav, Vk);
    atranka(n, Vk, Vk2, m);
    spausdinti(Vk2, m);

    return 0;
}
void skaitymas(int& n, string Pav[], Vard_kiek Vk[]){
    ifstream fd(input);

    char eil[CPav + 1];

    fd >> n;
    fd.ignore(80,'\n');
    for(int i = 0; i < n; i++){
        fd >> Pav[i];
        fd >> Vk[i].Vard;
        Vk[i].kiek = 1;
    }

    fd.close();
}
void atranka(int& n, Vard_kiek Vk[], Vard_kiek Vk2[], int& m){
    for(int i = 0; i < n; i++){
        int kiek = Yra(Vk2, m, Vk[i].Vard);
        if(kiek >= 0){
            Vk2[kiek].kiek++;
        }
        else{
            Vk2[m] = Vk[i];
            m++;
        }
    }
}
int Yra(Vard_kiek Vk2[], int m, string Vard){
    for(int i = 0; i < m; i++){
        if(Vk2[i].Vard == Vard)
            return i;
    }

    return -1;
}
void spausdinti(Vard_kiek Vk2[], int m){
    ofstream fr(output);
    rikiavimas(Vk2, m);
    for(int i = 0; i < m; i++){
        fr << left << setw(CPav) << Vk2[i].Vard << Vk2[i].kiek << endl;

    }

    fr.close();
}
void rikiavimas(Vard_kiek Vk2[], int m){
    int mini;
    Vard_kiek temp;

    for(int i = 0; i < m - 1; i++){
        mini = i;

        for(int j = i + 1; j < m; j++)
            if(Vk2[j].Vard < Vk2[mini].Vard)
                mini = j;

        temp = Vk2[i];
        Vk2[i] = Vk2[mini];
        Vk2[mini] = temp;
    }
}
