#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, x, x1, x2, D;
    cout << "a reiksme: ";
    cin >> a;

    cout << "b reiksme: ";
    cin >> b;

    cout << "c reiksme: ";
    cin >> c;
    D = pow(b, 2) - 4 * a * c;
    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        if (x1 < x2) {
            cout << x1 << endl;
            cout << x2;
        }
        else {
            cout << x2 << endl;
            cout << x1;
        };
    }
    else if (D == 0) {
            x = (-b) / (2 * a);
            cout << x << endl;
        }
    else if (D < 0)
        cout << "NO" << endl;
    return 0;
}
