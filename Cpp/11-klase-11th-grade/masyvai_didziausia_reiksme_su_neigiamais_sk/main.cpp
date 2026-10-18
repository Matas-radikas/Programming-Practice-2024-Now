#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int M[20];
    int n, did = 0;
    ifstream fd("U1.txt");
    ofstream fr("U1rez.txt");

    fd >> n;

    fd >> did;

    for (int i = 1; i < n; i++){
        fd >> M[i];
        if (M[i] > did)
            did = M[i];
    }

    fr << did << endl;
    return 0;
}
