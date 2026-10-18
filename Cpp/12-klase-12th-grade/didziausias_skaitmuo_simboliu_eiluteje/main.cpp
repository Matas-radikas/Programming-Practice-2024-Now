#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

const string input = "U1.txt";
const string output = "U1rez.txt";
const int CMax = 100;

void skaitymas(char skaicius[], int& n);
void isvedimas(char skaicius[], int n);
int did_yra(char skaicius[], int n);

int main()
{
    char skaicius[CMax];
    int n = 0;

    skaitymas(skaicius, n);
    isvedimas(skaicius, n);

    return 0;
}
void skaitymas(char skaicius[], int& n){
    ifstream fd(input);

    fd.getline(skaicius, CMax);
    n = strlen(skaicius);

    fd.close();
}
void isvedimas(char skaicius[], int n){
    ofstream fr(output);
    char did;

    for(int i = 0; i < n; i++){
        if((skaicius[i] >= 'a' && skaicius[i] <= 'z') || (skaicius[i] >= 'A' && skaicius[i] <= 'Z')){
            fr << "NE" << endl;
            fr.close();
            return;
        }
    }

    did = did_yra(skaicius, n);

    fr << did << endl;

    fr.close();
}
int did_yra(char skaicius[], int n){
    char did = skaicius[0];

    for(int i = 1; i < n; i++){
        if(skaicius[i] > did){
            did = skaicius[i];
        }
    }

    return did;
}
