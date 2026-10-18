#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int M[20];
    int n, k = 0;
    double sum = 0, vid = 0;
    ifstream fd("U1.txt");
    ofstream fr("U1rez.txt");

    fd >> n;

    for (int i = 0; i < n; i++){
        fd >> M[i];

        if (M[i] > 0) {
        sum += M[i];
        k++;
        }
    }

    if (sum == 0) fr << "NO" << endl;
    else {vid = sum / k;
        fr << fixed << setprecision (2)<< vid <<endl;}
    return 0;
}
