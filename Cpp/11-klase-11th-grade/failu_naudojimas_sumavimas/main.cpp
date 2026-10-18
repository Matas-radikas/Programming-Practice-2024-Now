#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ived;
    ived.open("U1.txt");
    ofstream isved;
    isved.open("U1rez.txt");

    int a, b, sum;

    ived >> a >> b;
    sum = a + b;
    isved << "Suma yra " << sum << endl;
    ived.close();
    isved.close();
}
