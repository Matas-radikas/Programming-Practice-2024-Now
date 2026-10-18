#include <iostream>

using namespace std;

int main()
{
    long long n;
    long long m = 0;
    long long n1;

    cin >> n;

    n1 = n;

    while (n1 > 0){
        m = m * 10 + n1 % 10;
        n1 /= 10;
    }

    if (m == n) {
    cout << "Skaicius apsivercia: " << m << endl;
  } else {
    cout << "Skaicius neapsivercia" << endl;}

    return 0;
}
