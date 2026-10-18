#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x, a, b, c;
    cin >> a >> b >> c;
    x=(b+sqrt((b*b)-(a*c)))/(2*a);
    cout << fixed << setprecision (3)<< x << endl;
    return 0;
}
