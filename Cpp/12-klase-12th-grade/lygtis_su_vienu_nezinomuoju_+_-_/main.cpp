#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

const string input = "U1.txt";
const string output = "U1rez.txt";
const int CMax = 6;

void skaitymas(char lygtis[], int& n);
void spausdinimas(char lygtis[], int n);
int zenklas(char lygtis[], int n);

int main()
{
    char lygtis[CMax];
    int n = 0;

    skaitymas(lygtis, n);
    spausdinimas(lygtis, n);

    return 0;
}
void skaitymas(char lygtis[], int& n){
    ifstream fd(input);

    fd.getline(lygtis, CMax);
    n = strlen(lygtis);

    fd.close();
}
void spausdinimas(char lygtis[], int n){
    ofstream fr(output);
    char zenklas_sk = 0;
    int sprend = 0;

    if(lygtis[0] == 'x'){
        zenklas_sk = zenklas(lygtis, n);
        if(zenklas_sk == 1){
            sprend = (lygtis[4] - '0') - (lygtis[2] - '0');
        }
        else{
            sprend = (lygtis[4] - '0') + (lygtis[2] - '0');
        }
    }
    else if(lygtis[2] == 'x'){
            zenklas_sk = zenklas(lygtis, n);
            if(zenklas_sk == 1){
                sprend = (lygtis[4] - '0') - (lygtis[0] - '0');
            }
            else{
                sprend = (lygtis[0] - '0') - (lygtis[4] - '0');
            }
        }
        else{
            zenklas_sk = zenklas(lygtis, n);
            if(zenklas_sk == 1){
                sprend = (lygtis[0] - '0') + (lygtis[2] - '0');
            }
            else{
                sprend = (lygtis[0] - '0') - (lygtis[2] - '0');
            }
        }
    fr << sprend << endl;

    fr.close();
}
int zenklas(char lygtis[], int n){
    int zenklas_sk = 0;

    if(lygtis[1] == '+'){
        zenklas_sk++;
    }

    return zenklas_sk;
}
