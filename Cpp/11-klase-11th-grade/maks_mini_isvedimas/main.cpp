#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fd("U3.txt");
    ofstream fr("U3rez.txt");

    int maks, mini, a, k;
    double sum = 0, vid = 0;

    fd >> a;

    maks = a;
    mini = a;

    while (fd >> a){

        if (maks < a)
        maks = a;

        if (mini > a)
        mini = a;
    }

    fr << "Minimumas yra " << mini << endl;
    fr << "Maksimumas yra " << maks << endl;
    return 0;
}
