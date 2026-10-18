#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const string input = "miestai_data.csv";
const string output = "miestai_res.csv";
const int CMax = 100;
const string komentaras_Nr2 = "Surikiuotas sąrašas";
const int top_10 = 10;

struct miest_data{
    string Miest;
    double plat;
    double ilg;
    int gyv_sk;
};

void skaitymas(miest_data Md[], long& i, string& komentaras);
void atrinkti_miest_20_tukst(miest_data Md[], long i, miest_data Md_1[], int& m);
void spausdinimas_10_miest(miest_data Md_1[], string komentaras, int m);

void rikiavimas(miest_data Md[], long i);
void spausdinimas_surikiuotas(miest_data Md[], long i, string komentaras);

int main()
{
    miest_data Md[CMax] = {}, Md_1[CMax] = {};
    long i = 0;
    int m = 0; // Md_1 masyvo indeksas
    string komentaras = " ";

    ofstream fr(output);
    fr.close();

    skaitymas(Md, i, komentaras);
    atrinkti_miest_20_tukst(Md, i, Md_1, m);
    spausdinimas_10_miest(Md_1, komentaras, m);

    rikiavimas(Md, i);
    spausdinimas_surikiuotas(Md, i, komentaras);

    return 0;
}
void skaitymas(miest_data Md[], long& i, string& komentaras){
    ifstream fd(input);

    if (!fd.is_open()) {
        cout << "Failas neatsidare!" << endl;
        return;
    }

    char k = ',';

    getline(fd, komentaras);

    while(getline(fd, Md[i].Miest, ',')){
          fd >> Md[i].plat;
          fd >> k;
          fd >> Md[i].ilg;
          fd >> k;
          fd >> Md[i].gyv_sk;
          i++;
    }

    fd.close();
}
void atrinkti_miest_20_tukst(miest_data Md[], long i, miest_data Md_1[], int& m){
    for(int j = 0; j < i; j++){
        if(Md[j].gyv_sk > 20000){
            Md_1[m] = Md[j];
            m++;
        }
    }
}
void spausdinimas_10_miest(miest_data Md_1[], string komentaras, int m){
    ofstream fr(output, ios::app);

    if (!fr.is_open()) {
        cout << "Failas neatsidare!" << endl;
        return;
    }

    char k = ',';
    int kiek = min(m, top_10);

    fr << komentaras << endl;

    for(int i = 0; i < kiek; i++){
        fr << Md_1[i].Miest << k;
        fr << Md_1[i].plat << k;
        fr << Md_1[i].ilg << k;
        fr << Md_1[i].gyv_sk << endl;
    }

    fr << endl;

    fr.close();
}
void rikiavimas(miest_data Md[], long i){
    miest_data temp;
    int mini;

    for(int j = 0; j < i - 1; j++){
        mini = j;
        for(int h = j + 1; h < i; h++){
            if((Md[h].plat < Md[mini].plat) || (Md[h].plat == Md[mini].plat && Md[h].gyv_sk > Md[mini].gyv_sk)){
                mini = h;
            }
        }

        temp = Md[j];
        Md[j] = Md[mini];
        Md[mini] = temp;
    }
}
void spausdinimas_surikiuotas(miest_data Md[], long i, string komentaras){
    ofstream fr(output, ios::app);

    if(!fr.is_open()){
        cout << "Failas neatsidare!" << endl;
        return;
	}

    char k = ',';

    fr << endl;
    fr << komentaras_Nr2 << endl;
    fr << komentaras << endl;

    for(int j = 0; j < i; j++){

        fr << Md[j].Miest << k;
        fr << Md[j].plat << k;
        fr << Md[j].ilg << k;
        fr << Md[j].gyv_sk << endl;

    }

    fr.close();
}
