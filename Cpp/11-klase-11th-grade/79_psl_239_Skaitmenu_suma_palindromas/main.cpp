#include <iostream>

using namespace std;

int main()
{
    long long n; // įvestas sk.
    long long m = 0, m1 = 0; // apverstas sk.
    long long n2; // pradiniai sk.
    long long k = 0; // kiek kartų sudėtis vyko

    cin >> n;

    while (true){
        m = 0; // apverstas skaičius
        m1 = 0;
        n2 = n; //išsaugojam pradinį sk.

        while (n2 > 0){
            m = m * 10 + (n2 % 10);
            n2 /= 10;
        }

        n += m;
        k++; // atliktų veiksmų kiekis

        n2 = n; // išsaugojam neapverstą sumos sk.
        while (n2 > 0) {
            m1 = m1 * 10 + (n2 % 10);
            n2 /= 10;
        }

        if (n == m1){
            break; // if su break tikrina ar skaičius palindromas, jei taip ciklas baigiasi
        }
    }

    cout << k << endl; // išvedame veiksmų kiekis
    cout << n << endl; // išvedame palindromišką skaičių

    return 0;
}
