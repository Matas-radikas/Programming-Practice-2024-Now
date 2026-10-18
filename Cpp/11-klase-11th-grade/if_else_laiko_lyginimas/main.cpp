#include <iostream>

using namespace std;

int main()
{
    int v1, m1, m2, v, m, z1, z2;
    cin >> v1 >> m1 >> m2 >> v >> m;
    z1=(v1*60)+m1+m2;
    z2=(v*60)+m;
    if (z1>z2){
        cout << "Petras i pamoka paveluos.";
    }
    else cout << "Petras i pamoka nepaveluos.";
    return 0;
}
