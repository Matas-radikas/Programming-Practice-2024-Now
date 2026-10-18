#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const string input = "Duom2.txt";
const string output = "Rez2.txt";
const int CMax = 101;

struct StotGreitLaikas{
    double atstumas;
    string stotele;
    int val;
    int mint;
};

void skaitymas(int& n, double& v, StotGreitLaikas SG[]);
void skaiciavimas(int n, double v, StotGreitLaikas SG[]);
double laikas(StotGreitLaikas SG[], double v, int i, double sumatstum);
void isvedimas(int n, StotGreitLaikas SG[]);

int main()
{
    int n;
    double v = 0;
    StotGreitLaikas SG[CMax];

    skaitymas(n, v, SG);
    skaiciavimas(n, v, SG);
    isvedimas(n, SG);

    return 0;
}
void skaitymas(int& n, double& v, StotGreitLaikas SG[]){
    ifstream fd(input);

    fd >> n >> v >> SG[0].val >> SG[0].mint;
    for(int i = 0; i < n; i++){
        fd >> SG[i].stotele >> SG[i].atstumas;
    }

    //cout << n << " " << v << " " << SG[0].val << " " << SG[0].mint << endl;
    //for(int i = 0; i < n; i++){
    //    cout << SG[i].stotele << " " << SG[i].atstumas << endl;
    //}





    fd.close();
}
void skaiciavimas(int n, double v, StotGreitLaikas SG[]){
    int pradlaikas = SG[0].val * 60 + SG[0].mint;
    double sumatstum = 0;

    for(int i = 0; i < n; i++){
        int atstumolaikas = 0, visaslaikasMin = 0;

        sumatstum += SG[i].atstumas;
        atstumolaikas = laikas(SG, v, i, sumatstum);

        visaslaikasMin = pradlaikas + atstumolaikas;
        SG[i].val = (visaslaikasMin / 60) % 24;
        SG[i].mint = visaslaikasMin % 60;
    }

}
double laikas(StotGreitLaikas SG[], double v, int i, double sumatstum){
    double laik = 0;
    laik = trunc(sumatstum / v * 60);
    return laik;
}
void isvedimas(int n, StotGreitLaikas SG[]){
    ofstream fr(output);

    for(int i = 0; i < n; i++){
        fr << SG[i].stotele << " " << SG[i].val << " val. " << SG[i].mint << " min." << endl;
    }

    fr.close();
}
