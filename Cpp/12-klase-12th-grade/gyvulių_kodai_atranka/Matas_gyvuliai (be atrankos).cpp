#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void skaitymas(int &i, char AK[], string AKkodas[]);
void israsymas(int i, char AK[], string AKkodas[]);

int main()
{
    int i = 0; //kiekis
    char AK[100]; //avis ar karvë
    string AKkodas[100]; // aviø ir karviø kodai

    skaitymas(i, AK, AKkodas);
    israsymas(i, AK, AKkodas);

    return 0;
}
void skaitymas(int &i, char AK[], string AKkodas[]){

    ifstream fd("Duomenys4.txt");

    while(!fd.eof()){
        fd >> AK[i] >> AKkodas[i];
        i++;
    }

    fd.close();
}
void israsymas(int i, char AK[], string AKkodas[]){

    ofstream frA("RezultataiA.txt");
    ofstream frK("RezultataiK.txt");

    frA << "Avių kodai:" << endl;
    frK << "Karvių kodai:" << endl;

    int j=0;

    while (i>=j){
        if (AK[j] != 'A' || AK[j] != 'K'){
            frA << "Per mažai duomenų" << endl;
            frK << "Per mažai duomenų" << endl;
        }
        else{
        if (AK[j] == 'A'){
            frA << AKkodas [j] << endl;
        }
        else{
            frK << AKkodas [j] << endl;
        }
        j++;
        }
    }
    frA.close();
    frK.close();

}
// while(!fd.eof()) - þiûri failà iki pabaigos
