#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

const string input = "duom.txt";
const string output = "Rez1.txt";
const int CMax = 1001;

int Kiek(char skaic);
void isvedimas(char skaic);

int main()
{
    char skaic;

    isvedimas(skaic);

    return 0;
}
void isvedimas(char skaic){
    ofstream fr(output);

    for(char i = '0'; i <= '9'; i++){
        fr << i << " " << Kiek(i) << endl;
    }

    fr.close();
}
int Kiek(char skaic){
    ifstream fd(input);

    char n; // laikinas simbolis
    int k = 0; // kiekis simbolio/skaičiaus
    // skaito simbolius cikle
    while(fd.get(n)){
        //patikriname ar simbolis/skaicius atitinka ieškomamą
        if(n == skaic)
            k++;
    }
    fd.close();
    return k;
}
