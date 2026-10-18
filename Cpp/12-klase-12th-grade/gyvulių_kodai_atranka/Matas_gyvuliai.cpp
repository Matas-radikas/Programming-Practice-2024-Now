#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void skaitymas(int &k, char AK[], string AKkodas[]);
void atranka(int k, int &Avkiek, int &Karkiek, char AK[], string AKkodas[], string Akodas[], string Kkodas[]);
void israsymas(int k, int Avkiek, int Karkiek, string Akodas[], string Kkodas[]);

int main()
{
    int k = 0, Avkiek = 0, Karkiek = 0; //kiekis
    char AK[100]; //avis ar karvë
    string AKkodas[100], Akodas[100], Kkodas[100]; // aviø ir karviø kodai

    skaitymas(k, AK, AKkodas);
    atranka(k, Avkiek, Karkiek, AK, AKkodas, Akodas, Kkodas);
    israsymas(k, Avkiek, Karkiek, Akodas, Kkodas);

    return 0;
}
void skaitymas(int &k, char AK[], string AKkodas[]){

    ifstream fd("Duomenys4.txt");

    while(!fd.eof()){
        fd >> AK[k] >> AKkodas[k];
        k++;
    }

    fd.close();
}
void atranka(int k, int &Avkiek, int &Karkiek, char AK[], string AKkodas[], string Akodas[], string Kkodas[]){

    for(int i = 0; i < k; i++){
        if(AK[i] == 'A'){
            Akodas[Avkiek] = AKkodas[i];
            Avkiek++;
        }
        else {
            Kkodas[Karkiek] = AKkodas[i];
            Karkiek++;
        }
    }

}
void israsymas(int k, int Avkiek, int Karkiek, string Akodas[], string Kkodas[]){

    ofstream frA("RezultataiA.txt");
    ofstream frK("RezultataiK.txt");

    frA << "Avių kodai:" << endl;

    for(int i = 0; i < Avkiek; i++){

        frA << Akodas[i]<<endl;

    }
    frA.close();

    frK << "Karvių kodai:" << endl;

    for(int i = 0; i < Karkiek; i++){

        frK << Kkodas[i]<<endl;
    }

    frK.close();

}
// while(!fd.eof()) - þiûri failà iki pabaigos
