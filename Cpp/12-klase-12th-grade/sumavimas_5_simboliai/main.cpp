#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

const string input = "U1.txt";
const string output = "U1rez.txt";
const int CMax = 6;

void skaitymas(char sum[], int& n);
void isvedimas(char sum[], int n);
int suma_aps(char sum[], int n);

int main()
{
    char sum[CMax];
    int n = 0;

    skaitymas(sum, n);
    isvedimas(sum, n);

    return 0;
}
void skaitymas(char sum[], int& n){
    ifstream fd(input);

    fd.getline(sum, CMax);
    n = strlen(sum);

    fd.close();
}
void isvedimas(char sum[], int n){
    ofstream fr(output);
    int suma = 0;

    for(int i = 0; i < n; i++){
        if((sum[i] >= 'a' && sum[i] <= 'z') || (sum[i] >= 'A' && sum[i] <= 'Z')){
            fr << "NE" << endl;
            fr.close();
            return;
        }
    }

    suma = suma_aps(sum, n);

    fr << suma << endl;

    fr.close();
}
int suma_aps(char sum[], int n){

    int temp = 0;
    int skaic_1 = 0, skaic_2 = 0;

    temp = (sum[0] - '0')* 10;
    skaic_1 = temp + (sum[1] - '0');

    temp = (sum[3] - '0')* 10;
    skaic_2 = temp + (sum[4] - '0');

    return skaic_1 + skaic_2;
}
