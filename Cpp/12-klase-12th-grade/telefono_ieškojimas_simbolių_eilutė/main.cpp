#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

const string input = "U1.txt";
const string output = "U1rez.txt";
const int CMax = 100;

void ivedimas(char Telefonas[], int& n);
void isvedimas(char Telefonas[], int n);

int main()
{
    char Telefonas[CMax];
    int n = 0;

    ivedimas(Telefonas, n);
    isvedimas(Telefonas, n);

    return 0;
}
void ivedimas(char Telefonas[], int& n){
    ifstream fd(input);

    fd.getline(Telefonas, CMax);
    n = strlen(Telefonas);

    fd.close();
}
void isvedimas(char Telefonas[], int n){
    ofstream fr(output);
    // tikriname ar char eilutė turi raidžių
    for(int i = 0; i < n; i++){
        if(Telefonas[i] >= 'a' && Telefonas[i] <= 'z' || Telefonas[i] >= 'A' && Telefonas[i] <= 'Z'){
            fr << "NE" << endl;
            fr.close();
            return;
        }
    }
    // pritaikome kriterijas iš sąlygos
    if(Telefonas[0] == '+' && Telefonas[1] == '3' && Telefonas[2] == '7' && Telefonas[3] == '0' && n == 12){
        fr << "TAIP" << endl;
    }
    else fr << "NE" << endl;

    fr.close();
}
