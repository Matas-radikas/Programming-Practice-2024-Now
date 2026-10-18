#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string input = "tersalai.txt";
const string output = "tersalairez.txt";
const int CMax = 100;
const int CPav = 30;
const string komentaras = "-------------------------------------------";

struct ters{
    string Pav;
    double ters_kiek[CMax];
};

void skaitymas (ters TS[], int& r, int& prmetai, int& m);
int daug (ters TS[], int r, int prmetai, int m, int i);
int maz (ters TS[], int r, int prmetai, int m, int i);
double suma_ton_metai (ters TS[], int r, int m, int j);
void rikiavimas (ters TS[], int r, int m, double sum[]);
void salinimas (ters TS[], double sum[], int& r);
void isvedimas (ters TS[], int r, int prmetai, int m);

int main()
{
    ters TS[CMax];
    int r = 0, prmetai = 0, m = 0;

    skaitymas (TS, r, prmetai, m);
    isvedimas (TS, r, prmetai, m);

    return 0;
}

void skaitymas (ters TS[], int& r, int& prmetai, int& m){
    ifstream fd(input);

    char eil[CPav + 1];

    fd >> r >> prmetai >> m;
    for (int i = 0; i < r; i++){
        fd.ignore(80, '\n');
        fd.get(eil, CPav);
        TS[i].Pav = eil;
        for (int j = 0; j < m; j++){
            fd >> TS[i].ters_kiek[j];
        }
    }
    fd.close();
}
int daug (ters TS[], int r, int prmetai, int m, int i){
    int vieta = 0;

    for (int j = 0; j < m; j++){
        if (TS[i].ters_kiek[j] > TS[i].ters_kiek[vieta])
            vieta = j;
    }
    if (vieta == 0){
        return prmetai;
    }
    else return prmetai + vieta;
}
int maz (ters TS[], int r, int prmetai, int m, int i){
    int vieta = 0;

    for (int j = 0; j < m; j++){
        if(TS[i].ters_kiek[j] < TS[i].ters_kiek[vieta])
            vieta = j;
    }
    if (vieta == 0){
        return prmetai;
    }
    else return prmetai + vieta;
}
double suma_ton_metai (ters TS[], int r, int m, int j){
    double sum = 0;

        for (int i = 0; i < r; i++){
            sum += TS[i].ters_kiek[j];
        }

    return sum;
}
void rikiavimas (ters TS[], int r, int m, double sum[]){

    for (int i = 0; i < r; i++){
        sum[i] = 0;
        for (int j = 0; j < m; j++){
            sum[i] += TS[i].ters_kiek[j];
        }
    }

    for (int i = 0; i < r - 1; i++){
        int mini = i;
        for (int j = i + 1; j < r; j++){
            if (sum[j] < sum[mini]){
                mini = j;
            }
            else if (sum[j] == sum[mini]){
                if (TS[j].Pav > TS[mini].Pav)
                    mini = j;
            }
        }

        // saugom Pav ir masyvą
        string tempPav = TS[i].Pav;
        double tempKiek[CMax];
        for (int k = 0; k < m; k++)
            tempKiek[k] = TS[i].ters_kiek[k];

        // perrašom i su mini
        TS[i].Pav = TS[mini].Pav;
        for (int k = 0; k < m; k++)
            TS[i].ters_kiek[k] = TS[mini].ters_kiek[k];

        // perrašom mini su temp
        TS[mini].Pav = tempPav;
        for (int k = 0; k < m; k++)
            TS[mini].ters_kiek[k] = tempKiek[k];

        double t = sum[i];
        sum[i] = sum[mini];
        sum[mini] = t;
    }
}
void salinimas (ters TS[], double sum[], int& r){
    if(r == 0) return;

    double maxsum = sum[r-1];

    while (r > 0 && sum[r-1] == maxsum){

        if (r > 1 && sum[r-2] == maxsum && TS[r-2].Pav > TS[r-1].Pav){
            TS[r-1] = TS[r-2];
            sum[r-1] = sum[r-2];
        }

        r--;
    }

}
void isvedimas (ters TS[], int r, int prmetai, int m){
    ofstream fr(output);
    // did ir maz tersalų kiekis metais
    int did_met[CMax], maz_met[CMax];

    for (int i = 0; i < r; i++){
        did_met[i] = daug(TS, r, prmetai, m, i);
        maz_met[i] = maz(TS, r, prmetai, m, i);
        fr << TS[i].Pav << " " << did_met[i] << " " << maz_met[i] << endl;
    }
    fr << komentaras << endl;

    // tersalų išviso išmesta kiekvienais metais ir visų metų išmestų teršalų suma
    int sum_prmetai = prmetai;
    double ters_sum[CMax], sum_per_vis_met = 0;
    int j = 0;

    for (int i = 0; i < m; i++){
        fr << sum_prmetai << " ";

        ters_sum[i] = suma_ton_metai(TS, r, m, j);
        sum_per_vis_met += ters_sum[i];
        fr << fixed << setprecision(1) << ters_sum[i] << endl;

        j++;
        sum_prmetai++;
    }
    fr << komentaras << endl;

    // vidutiniškai išmesta teršalų/metus
    double vid = 0;

    vid = sum_per_vis_met / m;

    fr << fixed << setprecision(1) << vid << endl;

    fr << komentaras << endl;
    //rikiavimas

    double sum[CMax];

    rikiavimas(TS, r, m, sum);

    for (int i = 0; i < r; i++){
        fr << TS[i].Pav << sum[i] << endl;

    }

    fr << komentaras << endl;

    //salinimas
    salinimas(TS, sum, r);

    for (int i = 0; i < r; i++){
        fr << TS[i].Pav << sum[i] << endl;

    }

    fr.close();
}
