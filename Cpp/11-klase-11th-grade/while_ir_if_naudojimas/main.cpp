#include <iostream>

using namespace std;

int main()
{
    int x;
    int x1; // pradinis skaičiaus išsaugojimas
    int s;

    cin >> x;

    s = 0;

    if (x < 10)
        cout << x << endl;
    else {
        x1 = x;

        while (x1 > 0) {
            s += x1 % 10;
            x1 /= 10;
        }

        while (s > 9){
            x = s;
            s = 0;
            x1 = x;

            while (x1 > 0) {
            s += x1 % 10;
            x1 /= 10;
            }
        }
        cout << s << endl;
    }
    return 0;
}
