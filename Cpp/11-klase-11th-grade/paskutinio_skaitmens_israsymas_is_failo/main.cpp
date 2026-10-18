#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ived;
    ived.open("U2.txt");
    ofstream isved;
    isved.open("U2rez.txt");

    int a, a1 = 0;

    while (ived >> a)
        {
        a1 = a;
        }
    isved << a1 << endl;
    ived.close();
    isved.close();
}
