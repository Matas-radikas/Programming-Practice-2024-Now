#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int n1 = n / 100;
    int n2 = n / 10 % 10;
    int n3 = n % 10;

    int m = (n3 * 100) + (n2 * 10) + n1;

    cout << "Naujas skaicius " << m << endl;
    return 0;
}
