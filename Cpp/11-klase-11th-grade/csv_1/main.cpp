#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string input = "vardai_atrinkimui_data.csv";
const string output = "vardai_atrinkti_res.csv";
const int CMax = 1000;
const int pop_kiek = 11;

struct vard_pop{
    string Vard;
    int pop[pop_kiek];
};

void skaitymas(int& i, string& komentaras, vard_pop Vp[]);
void atrinkti(int i, vard_pop Vp[], vard_pop Vp_atrinkta[], int& m);
void spausdinti(vard_pop Vp_atrinkta[], string komentaras, int m, char k);

int main()
{
    char k = ';';
    string komentaras;
    vard_pop Vp[CMax] = {}, Vp_atrinkta[CMax] = {};
    int i = 0; // vardø kiekis
    int m = 0; // naujo masyvo vardų kiekis

    skaitymas(i, komentaras, Vp);
    atrinkti(i, Vp, Vp_atrinkta, m);
    spausdinti(Vp_atrinkta, komentaras, m, k);

    return 0;
}
void skaitymas(int& i, string& komentaras, vard_pop Vp[]){
    ifstream fd(input);
    char k;

    getline(fd, komentaras);
    while(getline(fd, Vp[i].Vard, ';')){
        for (int j = 0; j < pop_kiek; j++){
            fd >> Vp[i].pop[j];
            if(j < pop_kiek-1){
                fd >> k;
            }
        }
        fd.ignore(80, '\n');
        i++;
    }
    fd.close();
}
void atrinkti(int i, vard_pop Vp[], vard_pop Vp_atrinkta[], int& m){
    for(int j = 0; j < i; j++){
        int index = 0;

        for(int g = 0; g < pop_kiek-1; g++){
            if(Vp[j].pop[g] > 200 && Vp[j].pop[g] < 1000){
                index++;
                break;
            }
        }
        if(index == 1){
            Vp_atrinkta[m] = Vp[j];
            m++;
        }
    }
}
void spausdinti(vard_pop Vp_atrinkta[], string komentaras, int m, char k){
    ofstream fr(output);

    fr << komentaras << endl;

    for(int j = 0; j < m; j++){
        fr << Vp_atrinkta[j].Vard << k;
        for(int g = 0; g < pop_kiek; g++){
            fr << Vp_atrinkta[j].pop[g];
            if(g < pop_kiek-1){
                fr << k;
            }
        }
        fr << endl;
    }
    fr.close();
}
