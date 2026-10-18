#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int h, m, s;
    cin >> h >> m >> s;

    s--;

    if (s < 0) {
        s = 59;
        m--;
    }

    if (m < 0) {
        m = 59;
        h--;
    }

    if (h < 0) {
        h = 23;
        m = 59;
        s = 59;
    }

    cout << fixed << setw(1) << left << h <<" " << setw(1) << m << " " << setw(1) << s << endl;
    return 0;
}
