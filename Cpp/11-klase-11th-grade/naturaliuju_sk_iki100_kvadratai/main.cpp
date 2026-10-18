#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fr ("rez.txt");

    int a = 1;
    long long a1 = 0;
    while (a < 101){
        a1 = a * a;
        fr << a1 << endl;
        a++;
    }
    fr.close();
    return 0;
}
