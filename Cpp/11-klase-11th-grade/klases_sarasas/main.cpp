#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string input = "duom.txt";
const string output = "rez.txt";
const int CMax = 30;
const int CPav = 25;
const string komentaras = "----------------------------------";

struct Mokiniai{
    string vard_pav;
    string dalykas;
};

void skaitymas_Pav(ifstream & fd, Mokiniai A[], int& n);
void skaitymas_Klase(ifstream & fd, Mokiniai A[], int& n);
void trinti(Mokiniai B[], int m, Mokiniai A[], int& n);
void papildyti(Mokiniai C[], int k, Mokiniai A[], int& n);
void rikiavimas(Mokiniai A[], int n);
void atrinkti(Mokiniai A[], int n, string dalykas, Mokiniai B[], int& m);
void spausdinimas(Mokiniai A[], int n, string eil);

int main()
{
    Mokiniai Klase[CMax], Iki[CMax], Nauj[CMax];
    int n, m, k; // klasės mokinių sąrašas / išvykusių sąrašas / naujokų sąrašas
    ofstream fr(output);
    fr.close();
    ifstream fd(input);

    skaitymas_Pav(fd, Iki, m); // išvykusių mokinių sąrašas
    skaitymas_Klase(fd, Nauj, k); // naujų mokinių sąrašas
    skaitymas_Klase(fd, Klase, n); // klasės mokinių sąrašas
    fd.close();

    trinti(Iki, m, Klase, n);
    papildyti(Nauj, k, Klase, n);
    rikiavimas(Klase, n);
    atrinkti(Klase, n, "Etika", Iki, m);
    spausdinimas(Klase, n, "Klasės sąrašas");
    spausdinimas(Iki, m, "Etiką pasirinkusieji mokiniai");

    return 0;
}
void skaitymas_Pav(ifstream & fd, Mokiniai A[], int& n){
    char eil[CPav+1];
    fd >> n;
    fd.ignore(80, '\n');

    for(int i = 0; i < n; i++){
        fd.get(eil, CPav);
        A[i].vard_pav = eil;
        A[i].dalykas = "";
        fd.ignore(80, '\n');
    }
}
void skaitymas_Klase(ifstream & fd, Mokiniai A[], int& n){
    char eil[CPav+1];
    fd >> n;
    fd.ignore(80, '\n');

    for(int i = 0; i < n; i++){
        fd.get(eil, CPav);
        A[i].vard_pav = eil;
        fd >> ws;
        getline(fd, A[i].dalykas);
    }

}
void trinti(Mokiniai B[], int m, Mokiniai A[], int& n){
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(B[i].vard_pav == A[j].vard_pav){
                A[j] = A[n-1];
                n--;
                j=n;
            }

}
void papildyti(Mokiniai C[], int k, Mokiniai A[], int& n){
    for(int i = 0; i < k; i++){
        A[n] = C[i];
        n++;
    }

}
void rikiavimas(Mokiniai A[], int n){
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(A[j].vard_pav < A[i].vard_pav){
                Mokiniai temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
}
void atrinkti(Mokiniai A[], int n, string dalykas, Mokiniai B[], int& m){
    m = 0;
    for(int i = 0; i < n; i++){
        if(A[i].dalykas == dalykas){
            B[m] = A[i];
            m++;
        }
    }

}
void spausdinimas(Mokiniai A[], int n, string eil){
    ofstream fr(output, ios::app);
    fr << eil << endl;
    fr << komentaras << endl;
    fr << setw(25) << left << "Mokinys"
       << setw(15) << left << "Dalykas" << endl;
    fr << komentaras << endl;
    for(int i = 0; i < n; i++){
        fr << setw(25) << left << A[i].vard_pav
            << setw(15) << left << A[i].dalykas << endl;
    }
    fr << komentaras << endl;
    fr.close();
}

