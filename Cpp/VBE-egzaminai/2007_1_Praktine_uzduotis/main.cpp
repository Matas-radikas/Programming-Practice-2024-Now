#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const string input = "U1.txt";
const string output = "U1rez.txt";
const int CMax = 100;

struct suma{
    long sumbar = 0;
    long sumraud = 0;
    long sumlep = 0;
    long sumgryb = 0;
};

void ivedimas(int& n, suma S[]);
void isvedimas(int n, suma S[]);
int daugsurin(suma S[]);

int main()
{
    int n, k[CMax];
    suma S[CMax];

    ivedimas(n, S);
    isvedimas(n, S);

    return 0;
}
void ivedimas(int& n, suma S[]){
    ifstream fd(input);
    int index = 0;
    long bar = 0, raud = 0, lep = 0;

    fd >> n;
    for (int i = 0; i < n; i++){

        fd >> index;
        fd >> bar >> raud >> lep;

        S[index].sumbar += bar;
        S[index].sumraud += raud;
        S[index].sumlep += lep;
    }
    fd.close();
}
void isvedimas(int n, suma S[]){
    ofstream fr(output);
    for(int i = 1; i < 31; i++){
        if (S[i].sumbar == 0 && S[i].sumraud == 0 && S[i].sumlep == 0){}
        else{
            fr << i << " " << S[i].sumbar << " " << S[i].sumraud << " " << S[i].sumlep << endl;
        }
    }

    int s = 0;
    s = daugsurin(S);
    fr << s << " " << S[s].sumgryb << endl;

    fr.close();
}
int daugsurin(suma S[]){
    int maxdien = 1; // daugiausiai surinktų grybų diena (index)
    int maxgryb = S[1].sumbar + S[1].sumraud + S[1].sumlep;

    for(int i = 2; i < 31; i++){
        S[i].sumgryb += S[i].sumbar + S[i].sumraud + S[i].sumlep;

        if(maxgryb < S[i].sumgryb){
            maxgryb = S[i].sumgryb;
            maxdien = i; // priskiriame kintamajam dieną (index), kada daugiausiai surinko grybų
        }
    }
    return maxdien;
}
