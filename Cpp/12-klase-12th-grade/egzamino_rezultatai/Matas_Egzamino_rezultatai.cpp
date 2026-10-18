#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void skaitymas(int n, string gr[], int p[], double v[], int &stud);
double vidur(int p[], int stud);
void israsymas(string gr[], double v[], int stud);

int main()
{
    double v[100];
    int n, p[100], stud = 0;
    string gr[100];

    skaitymas(n, gr, p, v, stud);
    israsymas(gr, v, stud);

    return 0;
}
void skaitymas(int n, string gr[], int p[], double v[], int &stud){

    ifstream fd("Duomenys3.txt");

    fd >> n;

    for(int i = 0; n > i; i++){
        fd >> gr[i];
        fd >> stud;

            for(int j = 0; stud > j; j++){
            fd >> p[j];
            }

    v[i] = vidur(p, stud);

    }

    fd.close();

}
double vidur(int p[], int stud){
    double v = 0, sump = 0;

    for(int i = 0; stud > i; i++){
        sump += p[i];
    }

    v = sump / stud;

    return v;
}
void israsymas(string gr[], double v[], int stud){
    ofstream fr("Rezultatai3.txt");

    for(int i = 0; stud > i; i++){
        fr << fixed << setprecision(2) << gr[i] << " " << v[i] << endl;
    }

    fr.close();
}
