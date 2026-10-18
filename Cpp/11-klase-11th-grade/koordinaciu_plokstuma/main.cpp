#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x, y;
    cin >> x>> y;
    if (x!=0 && y==0 )
        cout << "X asyje" << endl;
    else if (x==0 && y!=0)
        cout << "Y asyje" << endl;
    else if (x==0 && y==0)
        cout << "Koordinaciu pradzia" << endl;
    else
        cout << "X ir Y asiu plokstumoje" << endl;

    if (x>0 && y>0)
        cout << "I ketvirtyje" << endl;
    else if (x<0 && y>0)
        cout << "II ketvirtyje" << endl;
    else if (x<0 && y<0)
        cout << "III ketvirtyje" << endl;
    else if (x>0 && y<0)
        cout << "IV ketvirtyje" << endl;
    return 0;
}
