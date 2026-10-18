#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void daliklis (long n, int i);

int main()
{
    long n;
    int i;
    daliklis (n, i);

    return 0;
}

void daliklis (long n, int i){
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    fd >> n;

    for (int i = 1; i <= n; i++){ // imamae 1, nes nėra daliklio su 0
        if (n % i == (long long) 0){ // patiktiname ar skaičius yra daliklis
            fr << i << " yra skaiciaus " << n << " daliklis" << endl;
        }
    }
}
