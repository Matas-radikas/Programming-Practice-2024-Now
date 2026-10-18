#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    int n, sand1, sand2, sum;
    ifstream fd("U1.txt");
    fd >> n;
    ofstream fr("U1rez.txt");
    int m = 1;
    sand1 = 0;
    sand2 = 0;
    sum = 0;

    for (int i = 1; i <= n; i++){
        if (m == i) 
            sand1 += i * m;
    }
    for (int i = 1; i <= n; i++){
        if (m != i)
            sand2 += i * (m + 2);
    }
    sum = sand1 + sand2;
    fr << sum << endl;

    return 0;
}
