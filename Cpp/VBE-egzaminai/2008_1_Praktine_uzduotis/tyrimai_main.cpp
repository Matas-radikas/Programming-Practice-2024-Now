#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string input = "U1.txt";
const string output = "U1rez.txt";
const int CMax = 150;

void skaitymas(int &n, int M[], int Kel[]);
void isvedimas(int n, int M[], int Kel[]);
void mars_did(int n, int M[], int Kel[]);
int mars_did_K(int n, int sum_K_teig[]);

int main()
{
    int n, M[CMax], Kel[CMax];

    skaitymas(n, M, Kel);
    isvedimas(n, M, Kel);

    return 0;
}
void skaitymas(int&n, int M[], int Kel[]){
    ifstream fd(input);

    fd >> n;
    for(int i = 0; i < n; i++){
        fd >> M[i] >> Kel[i];
    }

    fd.close();
}
void isvedimas(int n, int M[], int Kel[]){
    ofstream fr(output);

    mars_did(n, M, Kel);

    int praeitas_mars = -1; // reikšmė, kuri neegzistuoja M[]

    int sum_K_teig [CMax] = {0}; // kadangi masyvas keleivių, kurie įlipo yra sumos, tai reikia priskirti 0
    int sum_K_neig [CMax] = {0}; // kadangi masyvas keleivių, kurie išlipo yra sumos, tai reikia priskirti 0
    int mars [CMax]; // maršrutai

    int index = -1; // reikšmė, indexas masyvo, priskiriame neigiamam, nes mes vis didinsime šią reikšmę

    int mars_max_kel = 0; //maksimalus keleivių skaičius viename maršrute

    for (int i = 0; i < n; i++){

        if(M[i] != praeitas_mars){
            index++;
            praeitas_mars = M[i];
            mars[index] = M[i];
        }
        if(Kel[i] > 0){
            sum_K_teig[index] += Kel[i];
            mars_max_kel = mars_did_K(n, sum_K_teig);
        }
        else{
            sum_K_neig[index] += Kel[i];
        }
    }
// maršrutų išvedimas
    for (int i = 0; i <= index; i++){
        fr << setw(6) << mars[i];
    }
// keleivių išvedimas, kiek įlipo
    fr << endl;
    for (int i = 0; i <= index; i++){
        fr << setw(6) << sum_K_teig[i];
    }
// keleivių išvedimas, kiek išlipo
    fr << endl;
    for (int i = 0; i <= index; i++){
        fr << setw(6) << sum_K_neig[i];
    }
// daugiausiai keleivių esančių maršrute
    fr << endl;
    fr << setw(6) << mars[mars_max_kel];


    fr.close();
}
void mars_did(int n, int M[], int Kel[]){
    int mini; // mažiausia reikšmės vieta
    int temp_M; // išsaugoti laikinai reikšmę iš masyvo M[]
    int temp_K; // išsaugoti laikinai reikšme iš masyvo K[]

    for (int i = 0; i < n - 1; i++){
        mini = i;
        for (int j = i + 1; j < n; j++)
            if(M[j] < M[mini]) mini = j;
// rikiavimas didėjimo tvarka maršrutus
            temp_M = M[i];
            M[i] = M[mini];
            M[mini] = temp_M;
// rikiavimas didėjimo tvarka keleivius
            temp_K = Kel[i];
            Kel[i] = Kel[mini];
            Kel[mini] = temp_K;
    }
}
int mars_did_K(int n, int sum_K_teig[]){
// didžiausio masyvo reikšmės paieška
    int vieta = 0;

    for (int i = 0; i < n; i++){
        if(sum_K_teig[i] > sum_K_teig[vieta]){
            vieta = i;
        }
    }
    return vieta;
}
