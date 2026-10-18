#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int n1 = n/1000;
    int n2 = n/100%10;
    int n3 = n/10%10;
    int n4 = n%10;

    int m = n1 + (n4*10) + (n3*100) + (n2*1000);
    cout << "Naujas skaicius " << m <<endl;
    return 0;
}
