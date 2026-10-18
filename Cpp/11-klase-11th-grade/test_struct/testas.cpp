#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int CMax = 100;
const string input = "duom.txt";
const string output = "rez.txt";

struct Rungtynes{
    string pavadinimas; // rungtynės pavadinimas
    int ziog_taskai; // komandos „Žiogai“ taškai
    int pries_taskai; // priešininkų taškai
};
struct blog_rez{
    string pavadinimas; // rungtynės pavadinimas
    int ziog_taskai; // komandos „Žiogai“ taškai
    int pries_taskai; // priešininkų taškai
};
struct ger_rez{
    string pavadinimas; // rungtynės pavadinimas
    int skirtumas;
};

void skaitymas(Rungtynes R[], int &n); // nuskaito iš failo
void spausdiniti(Rungtynes R[], int n); // išrašo į failą
int blogrez(Rungtynes R[], blog_rez BR[], int n); // randa blogiausia rezultatą
int gerrez(Rungtynes R[], ger_rez GR[], int n); // randa didžiausia skirtuma tarp dviejų komandų
void vidur_sum (Rungtynes R[], int n, double& sum, double& vid); // apskaičiuoja komandos „Žiogai“ taškų sumą ir vidurkį

int main()
{
    Rungtynes R[CMax]; // struktūros masyvas
    int n = 0; // struktūros masyvas

    skaitymas (R, n);
    spausdiniti (R, n);

    return 0;
}
void skaitymas(Rungtynes R[], int &n){
    ifstream fd(input);
    fd >> n;
    for (int i = 0; i < n; i++){
        fd >> R[i].pavadinimas >> R[i].ziog_taskai >> R[i].pries_taskai;
    }

    fd.close();
}
void spausdiniti (Rungtynes R[], int n){
    ofstream fr(output);
    int m = 0, d = 0;
    double sum = 0, vid = 0;
    blog_rez BR[CMax]; // blogiausias rezultatas „Žiogai“
    ger_rez GR[CMax]; // didžiausias skirtumas tarp „Žiogų“ ir priešininkų

    m = blogrez(R, BR, n); // priskiriame kiek rungtynių blogiausiai žaidė „Žiogai“ (jei lygūs du žaidimai taip pat priskiriamas)
    d = gerrez(R, GR, n); // priskiriame kiek rungtynių turėjo „Žiogai“ ir priešininkai skirtumą (jei lygūs du žaidimai taip pat priskiriamas)
    vidur_sum (R, n, sum, vid); // apskaičiuoja sumą ir vidurkį

    for (int i = 0; i < m; i++){
        fr << left << setw(15) << BR[i].pavadinimas << setw(5) << BR[i].ziog_taskai << BR[i].pries_taskai << endl;
    }
    for (int i = 0; i < d; i++){
        fr << left << setw(15) << GR[i].pavadinimas << GR[i].skirtumas << endl;
    }
    fr << fixed << setprecision (2) << vid << endl; // apskaičiuoja sumą ir vidurkį
    fr << setprecision (0) << sum << endl; // rašome 0, nes suma visada bus natūralus skaičius

    fr.close();
}
int blogrez(Rungtynes R[], blog_rez BR[], int n){
    int m = 0;
    int maz_surin = R[0].ziog_taskai; // prilyginam mum numanumą mažiausią taškų reikšmę
    BR[m].ziog_taskai = R[0].ziog_taskai;
    BR[m].pries_taskai = R[0].pries_taskai;
    BR[m].pavadinimas = R[0].pavadinimas;
    m++;
    for (int i = 1; i < n; i++){
        if (maz_surin > R[i].ziog_taskai){
                maz_surin = R[i].ziog_taskai;
                m = 0;
                BR[m].ziog_taskai = R[i].ziog_taskai;
                BR[m].pries_taskai = R[i].pries_taskai;
                BR[m].pavadinimas = R[i].pavadinimas;
                m++;
            }
            else if (maz_surin == R[i].ziog_taskai){
                    BR[m].ziog_taskai = R[i].ziog_taskai;
                    BR[m].pries_taskai = R[i].pries_taskai;
                    BR[m].pavadinimas = R[i].pavadinimas;
                    m++;
                }
        }

    return m;
}
int gerrez(Rungtynes R[], ger_rez GR[], int n){
    int d = 0;
    int ger_skirt = abs(R[0].ziog_taskai - R[0].pries_taskai);// priskiriame numanomą didžiausį skirtumą

    GR[d].skirtumas = ger_skirt;
    GR[d].pavadinimas = R[0].pavadinimas;
    d++;

    for (int i = 1; i < n; i++){
        if(ger_skirt < abs(R[i].ziog_taskai - R[i].pries_taskai)){
            ger_skirt = abs(R[i].ziog_taskai - R[i].pries_taskai);
            d = 0;

            GR[d].skirtumas = abs(R[i].ziog_taskai - R[i].pries_taskai);
            GR[d].pavadinimas = R[i].pavadinimas;
            d++;
            }
            else if(ger_skirt == abs(R[i].ziog_taskai - R[i].pries_taskai)){
                GR[d].skirtumas = abs(R[i].ziog_taskai - R[i].pries_taskai);
                GR[d].pavadinimas = R[i].pavadinimas;
                d++;
                }
    }
    return d;
}
void vidur_sum (Rungtynes R[], int n, double& sum, double& vid){
    sum = 0;
    for (int i = 0; i < n; i++){
        sum += R[i].ziog_taskai;
    }
    vid = sum / n;
}
